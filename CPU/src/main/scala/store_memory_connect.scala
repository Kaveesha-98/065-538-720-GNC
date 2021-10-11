import chisel3._
import chisel3.util._
import chisel3.Driver

class store_memory_connect extends Module{
	val io = IO(new Bundle{
		//Loadside connections
		val rdAddr = Input(UInt(32.W))
        	val rdData = Output(SInt(8.W))
		//CPU side connections
		//connections with ctrl signal dispatch unit
		val STORE_READY = Output(UInt(1.W))//Indicates that the Store unit is ready for a store operation
		val DATA_IN = Input(UInt(1.W))//Signals the store unit that data has been given
		val STORE_SIZE = Input(UInt(2.W))//00-byte, 11-halfword, 01-word
		val ADDRESS_IN = Input(UInt(1.W))//Signals the store unit that address has been given
		//connections with datapaths
		val store_data = Input(UInt(32.W))
		val store_address = Input(UInt(32.W))
	})
	
	
}
