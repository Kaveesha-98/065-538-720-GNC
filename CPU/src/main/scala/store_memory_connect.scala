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
		val STORE_SIZE = Input(UInt(2.W))//11-byte, 10-halfword, 00-word
		val ADDRESS_IN = Input(UInt(1.W))//Signals the store unit that address has been given
		//connections with datapaths
		val store_data = Input(SInt(32.W))
		val store_address = Input(UInt(32.W))
	})
	
	val storeUnit = Module(new Store_Unit())
	val dataMemory = Module(new Memory())
	
	//Connecting Data Memory to IO
	dataMemory.io.rdAddr := io.rdAddr 
	io.rdData := dataMemory.io.rdData
	
	//Connecting Store Unit to IO
	io.STORE_READY := storeUnit.io.STORE_READY
	storeUnit.io.DATA_IN := io.DATA_IN
	storeUnit.io.STORE_SIZE := io.STORE_SIZE
	storeUnit.io.ADDRESS_IN := io.ADDRESS_IN
	storeUnit.io.store_data := io.store_data
	storeUnit.io.store_address := io.store_address
	
	//Connecting Store Unit to data unit
	dataMemory.io.mem_write_data := storeUnit.io.mem_write_data
	dataMemory.io.mem_write_address := storeUnit.io.mem_write_address
	dataMemory.io.mem_write := storeUnit.io.mem_write
}

object store_memory_connect extends App{
    (new chisel3.stage.ChiselStage).emitVerilog(new store_memory_connect())
}
