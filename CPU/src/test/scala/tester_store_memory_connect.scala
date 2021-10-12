import chisel3.iotesters.PeekPokeTester
import org.scalatest._

import chisel3._
import chisel3.Driver

class tester_store_memory_connect(dut: store_memory_connect) extends PeekPokeTester(dut){
	poke(dut.io.ADDRESS_IN, 0.U)
	poke(dut.io.DATA_IN, 0.U)
	
	val startAddress = 10
	var loadAddress: BigInt = startAddress
	val bytes = 4
	
	println("Attempig load before storing data")
	for (offset <- -5 to 5){
		poke(dut.io.rdAddr, (loadAddress + offset).U)
		step(1)
		println("Data Address: " + (loadAddress + offset).toString.reverse.padTo(2, '0').reverse + ", Data: " + peek(dut.io.rdData).toInt.toBinaryString.reverse.padTo(8, '0').reverse)
	}
	
	println("Giving data to store")
	poke(dut.io.store_data, 0x12345678.S)
	poke(dut.io.DATA_IN, 1.U)
	poke(dut.io.STORE_SIZE, (4-bytes).U)
	step(1)
	
	println("Giving data address to store")
	poke(dut.io.store_address, startAddress.U)
	poke(dut.io.ADDRESS_IN, 1.U)
	step(1)
	
	loadAddress = startAddress
	
	println("reading while being stored")
	for (offset <- 0 to (bytes - 1)){
		poke(dut.io.rdAddr, (loadAddress + offset).U)
		step(1)
		println("Data Address: " + (loadAddress + offset).toString.reverse.padTo(2, '0').reverse + ", Data: " + peek(dut.io.rdData).toInt.toBinaryString.reverse.padTo(8, '0').reverse)
	}
	
	println("Attempig load after storing data")
	for (offset <- -5 to 5){
		poke(dut.io.rdAddr, (loadAddress + offset).U)
		step(1)
		println("Data Address: " + (loadAddress + offset).toString.reverse.padTo(2, '0').reverse + ", Data: " + peek(dut.io.rdData).toInt.toBinaryString.reverse.padTo(8, '0').reverse)
	}
}

object tester_store_memory_connect extends App{
	chisel3.iotesters.Driver(() => new store_memory_connect()){
		STORE_READY => new tester_store_memory_connect(STORE_READY)
	}
}
