import chisel3.iotesters.PeekPokeTester
import org.scalatest._

import chisel3._
import chisel3.Driver

class Tester(dut: TopLevel) extends PeekPokeTester(dut){
	
	//Writing one byte to Data Memory
	println("Loading data to store unit...")
	poke(dut.io.DATA_IN, 1.U)
	println("Data Enabled to Store Unit: 1.U")
	poke(dut.io.store_data, 5.S)
	println("Data value to be stored: 5.S")
	poke(dut.io.STORE_SIZE, 3.U)
	println("Data size: 3.U")
	step(1)
	println("Loading address to store unit...")
	poke(dut.io.ADDRESS_IN, 1.U)
	println("Address Enabled to Store Unit: 1.U")
	poke(dut.io.store_address, 10.U)
	println("Address which data to be stored: 10.U")
	step(1)
	println("Stored Data Value: " + peek(dut.io.dm_test_write).toString)
	step(5)

	// Giving memory address to load unit
	println("Giving memory address to load unit...")
	poke(dut.io.LOAD_ADDRESS_IN, 1.U)
	println("Read Address Enabled to Load Unit: 1.U")
	poke(dut.io.load_mem_address_in, 10.U)
	println("Address which data to be read from: 10.U")
	poke(dut.io.LOAD_SIZE, 3.U)
	println("Data size: 3.U")
	step(1)
	println("Read Data: " + peek(dut.io.load_data_out).toInt)
	//step(1)
	//println("Passing Loaded data into register")
	//poke(dut.io.LOAD_TO_REG,1.U)
	//step(1)
	//println("load data out: " + peek(dut.io.load_data_out).toInt)//toInt.toBinaryString.reverse.padTo(32, '0').reverse)
	//step(1)
}

object Tester extends App{
  chisel3.iotesters.Driver(() => new TopLevel()) {c=>new Tester(c)}
}

