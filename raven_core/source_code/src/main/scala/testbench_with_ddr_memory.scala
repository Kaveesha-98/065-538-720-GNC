//simple test bench to test raven_core
//no ddr memory
//no data memory(loads and stores to memory not possible)
//instructions loaded via UART

import chisel3._
import chisel3.util._
import chisel3.Driver

import scala.io.Source 

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - Bundle - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class testBench_with_memory_command_path_signals() extends Bundle{

    val addr    = Input(UInt(30.W))
    val bl      = Input(UInt(6.W))
    val empty   = Output(Bool())
    val en      = Input(Bool())
    val error   = Output(Bool())
    val full    = Output(Bool())
    val instr   = Input(UInt(3.W))

}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - Bundle - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class testBench_with_memory_write_datapath_path_signals() extends Bundle{

   /*  val PX_SIZE: Int        = dataWidth
    val PX_MASKSIZE: Int    = dataWidth/8 */
    
    val count       = Output(UInt(7.W))
    val data        = Input(UInt(32.W))
    val empty       = Output(Bool())
    val en          = Input(Bool())
    val error       = Output(Bool())
    val full        = Output(Bool())
    val mask        = Input(UInt(4.W))
    val underrun    = Output(Bool())

}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - Bundle - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class testBench_with_memory_read_datapath_path_signals() extends Bundle{

/*     val PX_SIZE: Int        = dataWidth
    val PX_MASKSIZE: Int    = dataWidth/8
     */
    val en          = Input(Bool())
    val data        = Output(UInt(32.W))
    val full        = Output(Bool())
    val empty       = Output(Bool())
    val count       = Output(UInt(7.W))
    val overflow    = Output(Bool())
    val error       = Output(Bool())

}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - Bundle - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class testBench_with_memory_memory_port() extends Bundle{

    //assert(portConfig == "read-write" || portConfig == "read-only" || portConfig == "write-only")

    val cmd = new testBench_with_memory_command_path_signals()
    val rd = new testBench_with_memory_read_datapath_path_signals()
    val wr = new testBench_with_memory_write_datapath_path_signals()

    /* if(portConfig == "read-write"){
        val rd = new testBench_with_memory_read_datapath_path_signals(dataWidth)
        val wr = new testBench_with_memory_write_datapath_path_signals(dataWidth)
    }else if(portConfig == "read-only"){
        val rd = new testBench_with_memory_read_datapath_path_signals(dataWidth)
    }else if(portConfig == "write-only"){
        val wr = new testBench_with_memory_write_datapath_path_signals(dataWidth)
    } */

}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - Bundle - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* class testBench_with_memory_uart_Tx(testingPlatform: String) extends Bundle{

    if (testingPlatform == "chiselTest"){
        val valid = Output(Bool())
        val channelByte = Output(Bool())
        val ready = Input(Bool())
    } else {
        val txd = Output(UInt(1.W))
    }

} */

class testBench_with_memory(uartFrequency: Int, uartBaudRate: Int, fpgaTesting: Boolean) extends Module{

    val testingPlatform: String = if (fpgaTesting) "fpga" else "chiselTest"

    val io = IO(new Bundle{
        val rxd = Input(UInt(1.W))//programing hart on a fpga implementation

        //val txd = new testBench_with_memory_uart_Tx(testingPlatform)
        val txd = Output(UInt(1.W))

        val startProgram = Input(Bool())

        //val dataWrite   = Flipped(new testBench_with_memory_memory_port(32, "write-only"))
        //val dataRead    = Flipped(new testBench_with_memory_memory_port(32, "read-only"))
        val instructionRead = Flipped(new testBench_with_memory_memory_port())
        val instructionWrite = Flipped(new testBench_with_memory_memory_port())

        //fpga debugging
        val Led = Output(UInt(8.W))
        
        //fpga debugging
        //val sw = Input(UInt(8.W))
    })

    //Release a bit at a time(ascii value of bit is released at a time '1' = 49, '0' = 48)
    val uartRecieveInstructions = Module(new Rx(uartFrequency, uartBaudRate))

    uartRecieveInstructions.io.rxd := io.rxd
        
    //Bytes will be buffered to form one instruction
    val newInstruction = RegInit(0.U(32.W))
    //For waiting 32 bits before storing recieved instruction
    val instructionBitCount = RegInit(0.U(6.W))

    //cannot recive instruction byte until fully formed instruction is stored
    val instructionIncomplete = instructionBitCount =/= 32.U
    uartRecieveInstructions.io.channel.ready := instructionIncomplete

    val newInstructionAddress = RegInit(0.U(32.W))

    val instrNotReadyToStore :: instrReadyToStore :: instrInBuffer :: Nil = Enum(3)

    val progInstrState = RegInit(instrNotReadyToStore)

    io.Led := 0.U

    io.instructionWrite.cmd.addr := newInstructionAddress(29, 0)
    io.instructionWrite.cmd.bl := 0.U
    io.instructionWrite.cmd.instr := "b000".U

    io.instructionWrite.wr.data := newInstruction
    io.instructionWrite.wr.mask := "b0000".U

    io.instructionRead.wr.data := 0.U
    io.instructionRead.wr.mask := "b0000".U
    io.instructionRead.wr.en := false.B

    when(uartRecieveInstructions.io.channel.valid && instructionIncomplete){
        instructionBitCount    := instructionBitCount + 1.U 
        newInstruction          := Cat((uartRecieveInstructions.io.channel.bits === '1'.U).asUInt, newInstruction(31, 1))
    }.elsewhen(~instructionIncomplete){
        when(progInstrState === instrNotReadyToStore){
            progInstrState := instrReadyToStore
            //for next instruction
            instructionBitCount    := 0.U
            newInstructionAddress   := newInstructionAddress + 4.U
        }
        io.Led := 1.U
    }

    io.instructionWrite.wr.en := false.B
    io.instructionWrite.cmd.en := false.B

    switch(progInstrState){
        is(instrReadyToStore){
            when(~io.instructionWrite.wr.full){
                io.instructionWrite.wr.en := true.B
                progInstrState := instrInBuffer
            }
        }
        is(instrInBuffer){
            when(~io.instructionWrite.cmd.full){
                io.instructionWrite.cmd.en := true.B
                progInstrState := instrNotReadyToStore
            }
        }
    }

    val instructionAddress = RegInit(0.U(32.W))

    val idle :: tx_Character :: issueReadCmd :: getData :: Nil = Enum(4)
    val readBackState = RegInit(idle)

    val tx = Module(new Tx(78125000, 115200))

    io.txd := tx.io.txd
    tx.io.channel.valid := false.B

    io.instructionRead.cmd.en := false.B
    io.instructionRead.rd.en := false.B

    when(io.startProgram && readBackState === idle){
        readBackState := issueReadCmd
    }

    val regBitCountDown = RegInit(0.U(6.W))

    val tx_word = Reg(UInt(32.W))

    tx.io.channel.bits := Mux(tx_word(31).asBool, '1'.U, '0'.U)

    io.instructionRead.cmd.addr := instructionAddress(29, 0)
    io.instructionRead.cmd.bl := 0.U
    io.instructionRead.cmd.instr := "b001".U

    io.instructionWrite.rd.en := false.B

    switch(readBackState){
        is(issueReadCmd){
            when(~io.instructionRead.cmd.full){
                io.instructionRead.cmd.en := true.B
                readBackState := issueReadCmd
            }
        }
        is(getData){
            when(~io.instructionRead.rd.empty){
                io.instructionRead.rd.en := true.B
                tx_word := io.instructionRead.rd.data
                readBackState := tx_Character
                regBitCountDown := 32.U
            }
        }
        is(tx_Character){
            when(tx.io.channel.ready && regBitCountDown =/= 0.U){
                tx.io.channel.valid := true.B
                regBitCountDown := regBitCountDown - 1.U
                tx_word := Cat(tx_word(30, 0), 0.U(1.W))
            }.elsewhen(regBitCountDown === 0.U && tx.io.channel.ready){
                tx.io.channel.valid := true.B
                tx.io.channel.bits := '\n'.U
                instructionAddress := instructionAddress + 4.U
                readBackState := issueReadCmd
            }
        }
    }
}

object testBench_with_memory extends App{

    val uartFrequency: Int = 78125000
    val uartBaudRate: Int = 115200
    val instructionCount: Int = 16
    val fpgaTesting: Boolean = false
    val uartOut: Boolean = true

    (new chisel3.stage.ChiselStage).emitVerilog(new testBench_with_memory(uartFrequency, 
    uartBaudRate, fpgaTesting))
}