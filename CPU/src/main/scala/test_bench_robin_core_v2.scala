import chisel3._
import chisel3.util._
import chisel3.Driver

class test_bench_robin_core_v2 extends Module{
    val io = IO(new Bundle{
    	//data memory-----------------------------------
        //val rdAddr_data = Input(UInt(32.W))
        //val rdData = Output(SInt(8.W))
        val signal_mem_write_data = Input(UInt(1.W))
        val mem_write_data = Input(SInt(8.W))
        val mem_write_address_data = Input(UInt(32.W))
        //instruction_memory-----------------------------
        //val rdAddr_instruction = Input(UInt(32.W))
        //val rdInstruction = Output(SInt(8.W))
        val signal_mem_write_instruction = Input(UInt(1.W))
        val mem_write_instruction = Input(UInt(32.W))
        val mem_write_address_instruction = Input(UInt(32.W))
        //start program-----------------------------------
        val START_PROGRAM = Input(UInt(1.W))
        val outputSake = Output(UInt(1.W))
        //reading outputs from CPU
        val out_mem_write = Output(UInt(1.W))
        val out_mem_write_data = Output(SInt(8.W))
        val out_mem_write_address = Output(UInt(32.W))
        //seeing current instruction
        val INSTRUCTION = Output(UInt(32.W))
        val PC = Output(UInt(32.W))
    })

	io.outputSake := 1.U

	val memoryData = Module(new Memory())
	val memoryInstruction = Module(new instruction_memory())
	val robinCore = Module(new robin_core_v2())
	
	val PROGRAM_LOADED = RegInit(0.U(1.W))
	
	memoryInstruction.io.mem_write := io.signal_mem_write_instruction
	memoryInstruction.io.mem_write_data := io.mem_write_instruction
	memoryInstruction.io.mem_write_address := io.mem_write_address_instruction
	
	memoryInstruction.io.rdAddr := Cat("b00".U, robinCore.io.PC(31, 2))
	robinCore.io.INSTRUCTION := memoryInstruction.io.rdData
	
	memoryData.io.rdAddr := robinCore.io.rdAddr
	robinCore.io.rdData := memoryData.io.rdData
	
	memoryData.io.mem_write := 0.U
	memoryData.io.mem_write_data := 0.S
	memoryData.io.mem_write_address := 0.U
	
	//connecting memories to I/O
	switch(PROGRAM_LOADED){
		is(0.U){
			//Before any instruction gets executed data needs to be loaded to respective memory
			memoryData.io.mem_write := io.signal_mem_write_data
			memoryData.io.mem_write_data := io.mem_write_data
			memoryData.io.mem_write_address := io.mem_write_address_data
			PROGRAM_LOADED := io.START_PROGRAM
		}
		is(1.U){
			memoryData.io.mem_write := robinCore.io.mem_write
			memoryData.io.mem_write_data := robinCore.io.mem_write_data
			memoryData.io.mem_write_address := robinCore.io.mem_write_address
		}
	}
	
	robinCore.io.START_PROGRAM := PROGRAM_LOADED
	io.out_mem_write := robinCore.io.mem_write
	io.out_mem_write_data := robinCore.io.mem_write_data
	io.out_mem_write_address := robinCore.io.mem_write_address
	
	io.INSTRUCTION := memoryInstruction.io.rdData
	io.PC := robinCore.io.PC
}

object test_bench_robin_core_v2 extends App{
    (new chisel3.stage.ChiselStage).emitVerilog(new test_bench_robin_core_v2)
}
