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

class testBench_with_memory(uartFrequency: Int, uartBaudRate: Int, fpgaTesting: Boolean) extends Module{

    val testingPlatform: String = if (fpgaTesting) "fpga" else "chiselTest"

    val io = IO(new Bundle{
        val rxd = Input(UInt(1.W))//programing hart on a fpga implementation

        //val dataWrite   = Flipped(new testBench_with_memory_memory_port(32, "write-only"))
        //val dataRead    = Flipped(new testBench_with_memory_memory_port(32, "read-only"))
        //val instructionRead = Flipped(new testBench_with_memory_memory_port())
        //val instructionWrite = Flipped(new testBench_with_memory_memory_port())
    })

    def gettingInstruction[T <: Data](uartChannel: UartIO, 
        recievedInstructionOut: chisel3.UInt, 
        recievedAddress: chisel3.UInt, 
        ramReady: chisel3.Bool): chisel3.Bool = {

        val bitCount = RegInit(0.U(6.W))
        val recievingIncomplete = bitCount =/= 32.U
        
        uartChannel.ready := ~recievingIncomplete

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

    /*===== Getting instruction from uart =====*/

    val uartRx = Module(new Rx(uartFrequency, uartBaudRate))

    uartRx.io.rxd := io.rxd

    val recievedInstructionOut = Reg(UInt(32.W))
    val recievedAddress = RegInit(0.U(32.W))

    val ramReady = WireInit(true.B)

    //val o = Mux(uartRx.io, 1.U, 0.U)

    val CanStartWritingIntructionToRam = gettingInstruction(uartRx.io.channel, recievedInstructionOut, recievedAddress, ramReady)

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