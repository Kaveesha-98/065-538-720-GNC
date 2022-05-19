//simple test bench to test raven_core
//no ddr memory
//no data memory(loads and stores to memory not possible)
//instructions loaded via UART

import chisel3._
import chisel3.util._
import chisel3.Driver

class simple_hw_testBench(uartFrequency: Int, uartBaudRate: Int, instructionCount: Int) extends Module{
    val io = IO(new Bundle{
        val rxd = Input(UInt(1.W))
        val txd = Output(UInt(1.W))
        val startProgram = Input(Bool())
    })

    val instructionMemory = Reg(Vec(instructionCount, UInt(32.W)))
    
    //Release a byte at a time
    val uartRecieveInstructions = Module(new Rx(uartFrequency, uartBaudRate))

    uartRecieveInstructions.io.rxd := io.rxd
    
    //Bytes will be buffered to form one instruction
    val newInstruction = RegInit(0.U(32.W))
    //For waiting 4 bytes before storing recieved instruction
    val instructionByteCount = RegInit(0.U(3.W))

    //cannot recive instruction byte until fully formed instruction is stored
    val instructionIncomplete = instructionByteCount =/= 4.U
    uartRecieveInstructions.io.channel.ready := instructionIncomplete

    val newInstructionAddress = RegInit(0.U(32.W))

    when(uartRecieveInstructions.io.channel.valid && instructionIncomplete){
        instructionByteCount    := instructionByteCount + 1.U 
        newInstruction          := Cat(uartRecieveInstructions.io.channel.bits, newInstruction(31, 8))
    }.elsewhen(~instructionIncomplete){
        instructionMemory(newInstructionAddress) := newInstruction
        //for next instruction
        instructionByteCount    := 0.U
        newInstructionAddress   := newInstructionAddress + 1.U
    }

    val tx = Module(new BufferedTx(uartFrequency, uartBaudRate))
    io.txd := tx.io.txd

    val ravenHartCore = Module(new raven_core_hart())

    //connecting transmitter to hart write channel
    tx.io.channel.bits := ravenHartCore.io.store_data(7,0)
    tx.io.channel.valid := ravenHartCore.io.write_data_valid.asBool
    ravenHartCore.io.write_data_ready := tx.io.channel.ready.asUInt

    //write address channel does not matter, as write port is only connected to tx
    ravenHartCore.io.write_address_ready := 1.U

    ravenHartCore.io.load_address_ready := 1.U

    ravenHartCore.io.load_data_valid := 1.U
    ravenHartCore.io.load_data := 0.U 

    ravenHartCore.io.cache_address_channel.ARREADY := true.B
    
    ravenHartCore.io.cache_data_channel.RDATA := instructionMemory(ravenHartCore.io.cache_address_channel.ARADDR)

    ravenHartCore.io.cache_data_channel.RVALID := io.startProgram

}

object simple_hw_testBench extends App{

    val uartFrequency: Int = 100000000
    val uartBaudRate: Int = 115200
    val instructionCount: Int = 4

    (new chisel3.stage.ChiselStage).emitVerilog(new simple_hw_testBench(uartFrequency, uartBaudRate, instructionCount))
}