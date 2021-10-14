

import chisel3._
import chisel3.util._

class Load_Unit extends Module{
	val io = IO(new Bundle{
		//Ports connecting to main memory
		val mem_load_data = Input(SInt(8.W))
		val mem_load_address = Output(UInt(32.W))
		//connections with ctrl signal dispatch unit
		val LOAD_READY = Output(UInt(1.W))//Indicates that the Load unit is ready for a store operation
		val LOAD_SIZE = Input(UInt(2.W))//11-byte, 10-halfword, 00-word
		val ADDRESS_IN = Input(UInt(1.W))//Signals the store unit that address has been given
		val EXTENSION = Input(UInt(1.W))//=0 unsigned extension
		//connections with datapaths
		val load_data = Input(SInt(32.W))
		val load_address = Input(UInt(32.W))
	})
	
	io.mem_load_address := 0.U
	io.LOAD_READY := 1.U
}

object Load_Unit extends App{
	(new chisel3.stage.ChiselStage).emitVerilog(new Load_Unit)
}
