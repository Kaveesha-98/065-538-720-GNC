import chisel3.iotesters.PeekPokeTester
import org.scalatest._

import chisel3._
import chisel3.Driver

class Tester(dut: Load_Unit) extends PeekPokeTester(dut){

	// Loading a Byte from memory
	println("Giving memory address to load unit...")
	poke(dut.io.LOAD_ADDRESS_IN, 1.U)
	println("Read Address Enabled to Load Unit: 1")
	poke(dut.io.load_mem_address_in, 10.U)
	println("Address which data to be read from: 10")
	poke(dut.io.LOAD_SIZE, 3.U)
	println("Data size: 3")
	step(1)
	println("Read Data Address: " + peek(dut.io.load_mem_address_out).toInt)
	println("Memory Read Control Signal: " + peek(dut.io.mem_read).toInt)
	step(1)
	println("Loading Data from Memoy")
	poke(dut.io.load_begin, 1.U)
	println("Load begin Control Signal: 1")
	poke(dut.io.load_data, 5.S)
	println("Load Data Value: 5")
	step(1)
	poke(dut.io.LOAD_TO_REG, 1.U)
	println("Load data to Register Control Signal: 1")
	step(1)
	println("Load Unit Output: " + peek(dut.io.load_data_out).toInt)
	step(1)

	// Disabling all control signals that has been set by the controller
	poke(dut.io.LOAD_ADDRESS_IN, 0.U)
	poke(dut.io.LOAD_TO_REG, 0.U)
	poke(dut.io.load_begin, 0.U)
	step(1)

	/*
	// Loading a half Word from memory
	println("Giving memory address to load unit...")
	poke(dut.io.LOAD_ADDRESS_IN, 1.U)
	println("Read Address Enabled to Load Unit: 1")
	poke(dut.io.load_mem_address_in, 20.U)
	println("Address which data to be read from: 20")
	poke(dut.io.LOAD_SIZE, 2.U)
	println("Data size: 2")
	step(1)
	println("Read Data Address: " + peek(dut.io.load_mem_address_out).toInt)
	println("Memory Read Control Signal: " + peek(dut.io.mem_read).toInt)
	step(1)
	println("Loading Data from Memoy")
	poke(dut.io.load_begin, 1.U)
	println("Load begin Control Signal: 1")
	poke(dut.io.load_data, 1.S)
	println("First data Byte: 6")
	step(1)
	poke(dut.io.load_data, 2.S)
	println("Second data Byte: 7")
	step(1)
	poke(dut.io.LOAD_TO_REG, 1.U)
	println("Load data to Register Control Signal: 1")
	step(1)
	println("Load Unit Output: " + peek(dut.io.load_data_out).toInt)
	step(1)
	println("Load Unit Output: " + peek(dut.io.load_data_out).toInt)
	step(1)
	println("Load Unit Output: " + peek(dut.io.load_data_out).toInt)
	step(1)
	println("Load Unit Output: " + peek(dut.io.load_data_out).toInt)
	step(1)
	println("Load Unit Output: " + peek(dut.io.load_data_out).toInt)
	step(1)
	println("Load Unit Output: " + peek(dut.io.load_data_out).toInt)
	step(1)*/
}

object Tester extends App {
	iotesters.Driver.execute(Array("--target-dir", "generated", "--generate-vcd-output", "on"),() => new Load_Unit()) {
		c => new Tester(c)
	}
}

//object Tester extends App {
//  chisel3.iotesters.Driver(() => new Load_Unit()) {c=>new Tester(c)}
//}

