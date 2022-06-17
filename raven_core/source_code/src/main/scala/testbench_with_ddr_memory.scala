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

class chiselTest_uart_tx() extends Module{

    val io = IO(new Bundle {
        val ready = Input(Bool())
        val valid = Output(Bool())
        val txd = Output(UInt(8.W))
        val channel = Flipped(new UartIO())
    })

    val ready :: transmitting :: Nil = Enum(2)

    val stateReg = RegInit(ready)

    io.valid := stateReg === transmitting
    io.channel.ready := stateReg === ready

    switch(stateReg){
        is(ready){
            when(io.channel.valid){
                stateReg := transmitting
            }
        }
        is(transmitting){
            when(io.ready){
                stateReg := ready
            }
        }
    }

}

class testBench_with_memory(uartFrequency: Int, uartBaudRate: Int, fpgaTesting: Boolean) extends Module {

    val testingPlatform: String = if (fpgaTesting) "fpga" else "chiselTest"

    val io = IO(new Bundle{
        //val rxd = Input(UInt(1.W))//programing hart on a fpga implementation

        val rxd = Input(UInt(1.W))

        val chiselRxd = Flipped(new UartIO())

        //val dataWrite   = Flipped(new testBench_with_memory_memory_port(32, "write-only"))
        //val dataRead    = Flipped(new testBench_with_memory_memory_port(32, "read-only"))
        //val instructionRead = Flipped(new testBench_with_memory_memory_port())
        val instructionMemPort = Flipped(new testBench_with_memory_memory_port())

        val txd = Output(UInt(1.W))

        val chiselTxd = new UartIO()

        val startRead = Input(Bool())

        val writingToMemory = Input(Bool())
    })

    def gettingInstruction[T <: Data](uartChannel: UartIO, 
        recievedInstructionOut: chisel3.UInt, 
        recievedAddress: chisel3.UInt, 
        ramReady: chisel3.Bool): chisel3.Bool = {

        val bitCount = RegInit(0.U(6.W))
        val recievingIncomplete = bitCount =/= 32.U
        
        uartChannel.ready := recievingIncomplete

        when(recievingIncomplete && uartChannel.valid){
            bitCount := bitCount + 1.U
            recievedInstructionOut := Cat((uartChannel.bits === '1'.U).asUInt, recievedInstructionOut(31, 1))
        }. elsewhen(~recievingIncomplete){
            when(ramReady){
                recievedAddress := recievedAddress + 4.U
                bitCount := 0.U 
            }
        }
        
        return ~recievingIncomplete

    }

    def instructionWrtieToMemory(recievedAddress: chisel3.UInt, 
    recievedInstructionOut: chisel3.UInt, 
    instructionWritePort: testBench_with_memory_memory_port,
    commenceWrite: chisel3.Bool,
    ramWrite: chisel3.Bool): Unit = {
        
        val recievedAddressBuffer = Reg(UInt(32.W))
        val recievedInstruntionBuffer = Reg(UInt(32.W)) 

        val idle :: pushToWriteBuffer :: pushtoCmdBuffer :: Nil = Enum(3)

        val stateReg = RegInit(idle)

        instructionWritePort.wr.mask    := "b0000".U
        instructionWritePort.wr.data    := recievedInstruntionBuffer
        instructionWritePort.wr.en      := stateReg === pushToWriteBuffer

        instructionWritePort.cmd.instr  := "b000".U
        instructionWritePort.cmd.bl     := "b000000".U
        instructionWritePort.cmd.en     := stateReg === pushtoCmdBuffer

        instructionWritePort.cmd.addr   := recievedAddressBuffer

        ramReady := stateReg === idle

        switch(stateReg){
            is(idle){
                when(commenceWrite){
                    recievedAddressBuffer       := recievedAddress
                    recievedInstruntionBuffer   := recievedInstructionOut

                    stateReg := pushToWriteBuffer
                }
            }
            is(pushToWriteBuffer){
                when(~instructionWritePort.wr.full){
                    stateReg := pushtoCmdBuffer
                }
            }
            is(pushtoCmdBuffer){
                when(~instructionWritePort.cmd.full){
                    stateReg := idle
                }
            }
        }

    }

    def fullMemRead(recievedAddress: chisel3.UInt, instructionReadPort: testBench_with_memory_memory_port,
    startRead: chisel3.Bool, uartTxIn: UartIO): Unit = {

        val readAddress = RegInit(0.U(32.W))

        val dataBuffer = Reg(UInt(32.W))

        val idle :: issueRead :: getDataToUart :: readData :: finishRead :: Nil = Enum(5)

        val stateReg = RegInit(idle)

        val uartCount = RegInit(33.U(6.W))

        uartTxIn.valid := (uartCount =/= 33.U) & (stateReg =/= finishRead)

        instructionReadPort.rd.en      := stateReg === readData

        instructionReadPort.cmd.instr  := "b001".U
        instructionReadPort.cmd.bl     := "b000000".U
        instructionReadPort.cmd.en     := stateReg === issueRead

        instructionReadPort.cmd.addr := readAddress

        uartTxIn.bits := '\n'.U

        when(uartCount < 32.U){
            when(uartTxIn.ready){
                uartTxIn.bits := Mux(dataBuffer(31).asBool, '1'.U, '0'.U)
                uartCount := uartCount + 1.U
                dataBuffer := Cat(dataBuffer(30, 0), dataBuffer(31))
            }
        }.elsewhen(uartCount === 32.U){
            uartTxIn.bits := '\n'.U
            when(uartTxIn.ready){
                uartCount := uartCount + 1.U
            }
        }

        switch(stateReg){
            is(idle){
                when(startRead){
                    stateReg := issueRead
                }
            }
            is(issueRead){
                when(~instructionReadPort.cmd.full){
                    stateReg := readData
                }
            }
            is(readData){
                dataBuffer := instructionReadPort.rd.data
                when(~instructionReadPort.rd.empty){
                    stateReg := getDataToUart
                    uartCount := 0.U
                }
            }
            is(getDataToUart){
                when(uartCount === 33.U){
                    stateReg := Mux(readAddress === recievedAddress, finishRead, issueRead)
                    readAddress := readAddress + 4.U
                }
            }
        }

    }

    /*===== Getting instruction from uart =====*/

    /* val uartRx = Module(new Rx(uartFrequency, uartBaudRate))

    uartRx.io.rxd := io.rxd */

    val recievedInstructionOut = Reg(UInt(32.W))// buffers the instruction from uart to write to memory
    val recievedAddress = RegInit(0.U(32.W))// gives the target address of the instruction

    val ramReady = WireInit(true.B)// to indicate whether writing to Memory can occur

    //val o = Mux(uartRx.io, 1.U, 0.U)

    val commenceWrite = WireInit(false.B)

    if(!fpgaTesting){

        commenceWrite := gettingInstruction(io.chiselRxd, recievedInstructionOut, recievedAddress, ramReady)

    } else {

        val uartRx = Module(new Rx(uartFrequency, uartBaudRate))
        uartRx.io.rxd := io.rxd
        commenceWrite := gettingInstruction(uartRx.io.channel, recievedInstructionOut, recievedAddress, ramReady)
        io.chiselRxd.ready := 0.U

    }

    //notifies when a instruction has been recieved
    //val commenceWrite = gettingInstruction(io.rxd, recievedInstructionOut, recievedAddress, ramReady)

    

    //val instructionBitOut = Wire(Flipped(new UartIO()))

    io.chiselTxd.bits := 0.U
    io.chiselTxd.valid := false.B
    io.instructionMemPort.wr.mask   := "b0000".U 
    io.instructionMemPort.wr.data   := recievedInstructionOut
    io.instructionMemPort.wr.en     := false.B 

    io.instructionMemPort.rd.en     := false.B

    when(io.writingToMemory){
        // commenses write when a instruction has been recieved and assembled on uart
        instructionWrtieToMemory(recievedAddress, recievedInstructionOut, io.instructionMemPort, commenceWrite, ramReady)
        io.txd := 1.U

    }otherwise{

        if(!fpgaTesting){
            fullMemRead(recievedAddress, io.instructionMemPort, io.startRead, io.chiselTxd)
            io.txd := 0.U
        } else {
            val uartTx = Module(new Tx(uartFrequency, uartBaudRate))
            io.txd := uartTx.io.txd
            fullMemRead(recievedAddress, io.instructionMemPort, io.startRead, uartTx.io.channel)
        }

    }

    val stateReg = Reg(UInt(32.W))
}

class chiseltestBench_with_ddr_memory extends Module{
    val io = IO(new Bundle{
        val rxd = Flipped(new UartIO())
        val txd = new UartIO()

        val writingToMemory = Input(Bool())

        val startRead = Input(Bool())
    })

    def getDataAfterMask(data: chisel3.UInt, orginalData: chisel3.UInt, mask: chisel3.UInt): chisel3.UInt = {

        val bytesAfterMask = Wire(Vec(4, UInt(8.W)))
        for(i <- 0 to 3){
            bytesAfterMask(i) := Mux(mask(i).asBool, orginalData(8*(i+1) - 1, 8*i), data(8*(i+1) - 1, 8*i))
        }
        Cat(bytesAfterMask.reverse)

    }

    val mem = SyncReadMem (4096 , UInt(32.W))

    val testBenchWithMemory = Module(new testBench_with_memory(78125000, 115200, false))

    testBenchWithMemory.io.chiselRxd <> io.rxd
    testBenchWithMemory.io.chiselTxd <> io.txd

    testBenchWithMemory.io.rxd := 0.U

    testBenchWithMemory.io.writingToMemory := io.writingToMemory

    testBenchWithMemory.io.startRead := io.startRead

    val dataBufferFull = RegInit(false.B)

    val data = Reg(UInt(32.W))
    val mask = Reg(UInt(4.W))

    when(testBenchWithMemory.io.instructionMemPort.wr.en){
        dataBufferFull := true.B 
        data := testBenchWithMemory.io.instructionMemPort.wr.data
        mask := testBenchWithMemory.io.instructionMemPort.wr.mask
    }

    val cmdAddress = testBenchWithMemory.io.instructionMemPort.cmd.addr

    val writeData = getDataAfterMask(data, mem(cmdAddress >> 2.U), mask)

    when(testBenchWithMemory.io.instructionMemPort.cmd.en && testBenchWithMemory.io.instructionMemPort.cmd.instr === "b000".U){
        dataBufferFull := false.B 
        mem.write(testBenchWithMemory.io.instructionMemPort.cmd.addr >> 2, writeData)
    }

    testBenchWithMemory.io.instructionMemPort.rd.data := mem(testBenchWithMemory.io.instructionMemPort.cmd.addr >> 2.U)

    testBenchWithMemory.io.instructionMemPort.cmd.empty := false.B
    testBenchWithMemory.io.instructionMemPort.cmd.error := false.B
    testBenchWithMemory.io.instructionMemPort.cmd.full  := false.B 

    testBenchWithMemory.io.instructionMemPort.wr.count  := 0.U 
    testBenchWithMemory.io.instructionMemPort.wr.empty  := false.B
    testBenchWithMemory.io.instructionMemPort.wr.error  := false.B 
    testBenchWithMemory.io.instructionMemPort.wr.full   := false.B 
    testBenchWithMemory.io.instructionMemPort.wr.underrun := false.B 

    testBenchWithMemory.io.instructionMemPort.rd.full     := false.B
    testBenchWithMemory.io.instructionMemPort.rd.empty    := false.B
    testBenchWithMemory.io.instructionMemPort.rd.count    := 0.U 
    testBenchWithMemory.io.instructionMemPort.rd.overflow := false.B 
    testBenchWithMemory.io.instructionMemPort.rd.error    := false.B

}

object testBench_with_memory extends App{

    val uartFrequency: Int = 78125000
    val uartBaudRate: Int = 115200
    val instructionCount: Int = 16
    val fpgaTesting: Boolean = true
    val uartOut: Boolean = true

    (new chisel3.stage.ChiselStage).emitVerilog(new testBench_with_memory(uartFrequency, 
    uartBaudRate, fpgaTesting))
}

object chiseltestBench_with_ddr_memory extends App{

    val uartFrequency: Int = 78125000
    val uartBaudRate: Int = 115200
    val instructionCount: Int = 16
    val fpgaTesting: Boolean = false
    val uartOut: Boolean = true

    (new chisel3.stage.ChiselStage).emitVerilog(new chiseltestBench_with_ddr_memory)
}