import chisel3.iotesters.PeekPokeTester
import org.scalatest._

import chisel3._
import chisel3.Driver

class tester_control_store(dut: control_store) extends PeekPokeTester(dut){
	var loadAddress: BigInt = 1
	var Status: String = "1";
	
	var machineCodes = Array("b0000000_00111_00110_000_00101_0110011",
							"b0000_0000_0111_0011_0000_0010_1001_0011")
	var assemblyCodes = Array("add x5, x6, x7",
							"addi x5, x6, 7")
							
	for ( i <- 0 to (assemblyCodes.length - 1)) {
		poke(dut.io.INSTRUCTION, machineCodes(i).U)
		poke(dut.io.INSTRUCTION_LOADED, 1.U)
		step(1)
		poke(dut.io.INSTRUCTION_LOADED, 0.U)
		for(w <- 0 to 4){
			Status = "\nassembly code: " + assemblyCodes(i) + "\n"
			Status += "machine code: " + machineCodes(i)
			Status += "READY: " + peek(dut.io.READY).toString + "\n"
			Status += "Pipeline Stage 1------------\n"
			Status += "RS1: " + peek(dut.io.RS1).toString + "\n"
			Status += "RS2: " + peek(dut.io.RS2).toString + "\n"
			Status += "IMMEDIATE: " + peek(dut.io.IMMEDIATE).toString + "\n"
			Status += "CHOOSE_IMMEDIATE: " + peek(dut.io.CHOOSE_IMMEDIATE).toString + "\n"
			Status += "BRANCH_IMMEDIATE: " + peek(dut.io.BRANCH_IMMEDIATE).toString + "\n"
			Status += "Pipeline Stage 2------------\n"
			Status += "STORE_SIZE: " + peek(dut.io.STORE_SIZE).toString + "\n"
			Status += "ALU_OP: " + peek(dut.io.ALU_OP).toString + "\n"
			Status += "DATA_IN: " + peek(dut.io.DATA_IN).toString + "\n"
			Status += "Pipeline Stage 3------------\n"
			Status += "PROCEDURE_BRANCHING: " + peek(dut.io.PROCEDURE_BRANCHING).toString + "\n"
			Status += "STORE_ADDRESS_IN: " + peek(dut.io.STORE_ADDRESS_IN).toString + "\n"
			Status += "LOAD_SIZE: " + peek(dut.io.LOAD_SIZE).toString + "\n"
			Status += "LOAD_ADDRESS_IN: " + peek(dut.io.LOAD_ADDRESS_IN).toString + "\n"
			Status += "EXTENSION: " + peek(dut.io.EXTENSION).toString + "\n"
			Status += "RD: " + peek(dut.io.RD).toString + "\n"
			Status += "WRITE_EN: " + peek(dut.io.WRITE_EN).toString + "\n"
			Status += "BRANCH_SELECT: " + peek(dut.io.BRANCH_SELECT).toString + "\n"
			Status += "BRANCH_CONDITION: " + peek(dut.io.BRANCH_CONDITION).toString + "\n"
			Status += "Pipeline Stage 4------------\n"
			Status += "WRITE_EN: " + peek(dut.io.WRITE_EN).toString + "\n"
			Status += "CHOOSE_MEMORY_LOAD: " + peek(dut.io.CHOOSE_MEMORY_LOAD).toString
			println(Status)
			step(1)
		}
	}
}

object tester_control_store extends App{
	chisel3.iotesters.Driver(() => new control_store()){
		READY => new tester_control_store(READY)
	}
}
