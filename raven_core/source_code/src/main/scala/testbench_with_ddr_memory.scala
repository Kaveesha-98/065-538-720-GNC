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

class testBench_with_memory(uartFrequency: Int, uartBaudRate: Int, instructionCount: Int, fpgaTesting: Boolean, uartOut: Boolean) extends Module{
    val io = IO(new Bundle{
        val rxd = Input(UInt(1.W))//programing hart on a fpga implementation
        
        val startProgram = Input(Bool())

        val p0_cmd = Flipped(new testBench_with_memory_command_path_signals())
        val p0_wr = Flipped(new testBench_with_memory_read_datapath_path_signals())
        val p0_rd = Flipped(new testBench_with_memory_read_datapath_path_signals())

        val txd = Output(UInt(1.W))
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