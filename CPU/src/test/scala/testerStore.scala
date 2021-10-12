import chisel3.iotesters.PeekPokeTester
import org.scalatest._

import chisel3._
import chisel3.Driver

class testerStore(dut: Store_Unit) extends PeekPokeTester(dut){
	poke(dut.io.ADDRESS_IN, 0.U)
	if(peek(dut.io.STORE_READY).toString == "1"){
		println("Store unit ready")
	}else{
		println("Store unit not ready")
	}
	println("write memory data: " + peek(dut.io.mem_write_data).toInt.toBinaryString.reverse.padTo(8, '0').reverse)
	println("write memory data address: " + peek(dut.io.mem_write_address).toInt.toBinaryString)
	println("write memory op: " + peek(dut.io.mem_write).toInt.toBinaryString)
	
	//Loading data to store unit
	print("Loading data to store unit")
	poke(dut.io.DATA_IN, 1.U)
	poke(dut.io.store_data, 0x12345678.S)
	poke(dut.io.STORE_SIZE, 0.U)
	step(1)
	//poke(dut.io.DATA_IN, 0.U)
	
	println("After data has been given to store unit, status of store unit:")
	if(peek(dut.io.STORE_READY).toString == "1"){
		println("Store unit ready")
	}else{
		println("Store unit not ready")
	}
	println("write memory data: " + peek(dut.io.mem_write_data).toInt.toBinaryString.reverse.padTo(8, '0').reverse)
	println("write memory data address: " + peek(dut.io.mem_write_address).toInt.toBinaryString)
	println("write memory op: " + peek(dut.io.mem_write).toInt.toBinaryString)
	
	print("Loading data address to store unit")
	poke(dut.io.ADDRESS_IN, 1.U)
	poke(dut.io.store_address, "x9ABCDEF0".U)
	step(1)
	//poke(dut.io.ADDRESS_IN, 0.U)
	
	println("After data address has been given to store unit, status of store unit:")
	if(peek(dut.io.STORE_READY).toString == "1"){
		println("Store unit ready")
	}else{
		println("Store unit not ready")
	}
	println("write memory data: " + peek(dut.io.mem_write_data).toInt.toBinaryString.reverse.padTo(8, '0').reverse)
	println("write memory data address: " + peek(dut.io.mem_write_address).toInt.toBinaryString)
	println("write memory op: " + peek(dut.io.mem_write).toInt.toBinaryString)
	
	step(1)
	
	println("The next cycle, status of store unit:")
	if(peek(dut.io.STORE_READY).toString == "1"){
		println("Store unit ready")
	}else{
		println("Store unit not ready")
	}
	println("write memory data: " + peek(dut.io.mem_write_data).toInt.toBinaryString.reverse.padTo(8, '0').reverse)
	println("write memory data address: " + peek(dut.io.mem_write_address).toInt.toBinaryString)
	println("write memory op: " + peek(dut.io.mem_write).toInt.toBinaryString)
	
	step(1)
	
	println("The next cycle, status of store unit:")
	if(peek(dut.io.STORE_READY).toString == "1"){
		println("Store unit ready")
	}else{
		println("Store unit not ready")
	}
	println("write memory data: " + peek(dut.io.mem_write_data).toInt.toBinaryString.reverse.padTo(8, '0').reverse)
	println("write memory data address: " + peek(dut.io.mem_write_address).toInt.toBinaryString)
	println("write memory op: " + peek(dut.io.mem_write).toInt.toBinaryString)
	
	step(1)
	
	println("The next cycle, status of store unit:")
	if(peek(dut.io.STORE_READY).toString == "1"){
		println("Store unit ready")
	}else{
		println("Store unit not ready")
	}
	println("write memory data: " + peek(dut.io.mem_write_data).toInt.toBinaryString.reverse.padTo(8, '0').reverse)
	println("write memory data address: " + peek(dut.io.mem_write_address).toInt.toBinaryString)
	println("write memory op: " + peek(dut.io.mem_write).toInt.toBinaryString)
	
	step(1)
	
	println("The next cycle, status of store unit:")
	if(peek(dut.io.STORE_READY).toString == "1"){
		println("Store unit ready")
	}else{
		println("Store unit not ready")
	}
	println("write memory data: " + peek(dut.io.mem_write_data).toInt.toBinaryString.reverse.padTo(8, '0').reverse)
	println("write memory data address: " + peek(dut.io.mem_write_address).toInt.toBinaryString)
	println("write memory op: " + peek(dut.io.mem_write).toInt.toBinaryString)
}

object testerStore extends App{
	chisel3.iotesters.Driver(() => new Store_Unit()){
		mem_write => new testerStore(mem_write)
	}
}
