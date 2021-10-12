import chisel3.iotesters.PeekPokeTester
import org.scalatest._

import chisel3._
import chisel3.Driver

class tester_store_memory_connect(dut: store_memory_connect) extends PeekPokeTester(dut){
	poke(dut.io.ADDRESS_IN, 0.U)
	poke(dut.io.DATA_IN, 0.U)
}

object tester_store_memory_connect extends App{
	chisel3.iotesters.Driver(() => new store_memory_connect()){
		STORE_READY => new tester_store_memory_connect(STORE_READY)
	}
}
