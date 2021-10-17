import chisel3._
import chisel3.iotesters._

class Tester(lu: Load_Unit) extends PeekPokeTester(lu){
  
  poke(lu.io.ADDRESS_EN, 0.U)
	if(peek(lu.io.LOAD_UNIT_READY).toString == "1"){
		println("Load unit ready")
	}else{
		println("Load unit not ready")
	}

	println("load memory address out: " + peek(lu.io.load_mem_address_out).toInt.toBinaryString)
	println("mem read: " + peek(lu.io.mem_read).toInt.toBinaryString)
  println("load data out: " + peek(lu.io.load_data_out).toInt.toBinaryString.reverse.padTo(8, '0').reverse)
	
  
}

object Tester extends App{
  chisel3.iotesters.Driver(() => new Load_Unit()) {c=>new Tester(c)}
}

