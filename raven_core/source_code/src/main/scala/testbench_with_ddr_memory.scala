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

class testBench_with_memory_write_datapath_path_signals(dataWidth: Int) extends Bundle{

    val PX_SIZE: Int        = dataWidth
    val PX_MASKSIZE: Int    = dataWidth/8
    
    val count       = Input(UInt(7.W))
    val data        = Input(UInt(PX_SIZE.W))
    val empty       = Output(Bool())
    val en          = Output(Bool())
    val error       = Output(Bool())
    val full        = Output(Bool())
    val mask        = Input(UInt(PX_MASKSIZE.W))
    val underrun    = Output(Bool())

}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - Bundle - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class testBench_with_memory_read_datapath_path_signals(dataWidth: Int) extends Bundle{

    val PX_SIZE: Int        = dataWidth
    val PX_MASKSIZE: Int    = dataWidth/8
    
    val en          = Input(Bool())
    val data        = Output(UInt(PX_SIZE.W))
    val full        = Output(Bool())
    val empty       = Output(Bool())
    val count       = Output(UInt(7.W))
    val overflow    = Output(Bool())
    val error       = Output(Bool())

}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - Bundle - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class testBench_with_memory_memory_port(dataWidth: Int, portConfig: String) extends Bundle{

    assert(portConfig == "read-write" || portConfig == "read-only" || portConfig == "write-only")

    val cmd = new testBench_with_memory_command_path_signals()

    if(portConfig == "read-write"){
        val rd = new testBench_with_memory_read_datapath_path_signals(dataWidth)
        val wr = new testBench_with_memory_write_datapath_path_signals(dataWidth)
    }else if(portConfig == "read-only"){
        val rd = new testBench_with_memory_read_datapath_path_signals(dataWidth)
    }else if(portConfig == "write-only"){
        val wr = new testBench_with_memory_write_datapath_path_signals(dataWidth)
    }

}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - Bundle - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class testBench_with_memory_uart_Tx(testingPlatform: String) extends Bundle{

    if (testingPlatform == "chiselTest"){
        val valid = Output(Bool())
        val channelByte = Output(Bool())
        val ready = Input(Bool())
    } else {
        val txd = Output(UInt(1.W))
    }

}

class testBench_with_memory(uartFrequency: Int, uartBaudRate: Int, fpgaTesting: Boolean) extends Module{

    val testingPlatform: String = if (fpgaTesting) "fpga" else "chiselTest"

    val io = IO(new Bundle{
        val rxd = Input(UInt(1.W))//programing hart on a fpga implementation
        
        val startProgram = Input(Bool())

        val dataWrite   = Flipped(new testBench_with_memory_memory_port(32, "write-only"))
        val dataRead    = Flipped(new testBench_with_memory_memory_port(32, "read-only"))
        val instructionRead = Flipped(new testBench_with_memory_memory_port(32, "read-only"))
        val instructionWrite = Flipped(new testBench_with_memory_memory_port(32, "write-only"))

        val txd = new testBench_with_memory_uart_Tx(testingPlatform)
        //fpga debugging
        val Led = Output(UInt(8.W))
        
        //fpga debugging
        val sw = Input(UInt(8.W))
    })

    
}

/* object simple_hw_testBench extends App{

    val uartFrequency: Int = 100000000
    val uartBaudRate: Int = 115200
    val instructionCount: Int = 16
    val fpgaTesting: Boolean = false
    val uartOut: Boolean = true

    (new chisel3.stage.ChiselStage).emitVerilog(new simple_hw_testBench(uartFrequency, 
    uartBaudRate, instructionCount, fpgaTesting, uartOut))
} */