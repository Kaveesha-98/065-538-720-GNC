import chisel3._
import chisel3.util._
import chisel3.Driver

class data_memory_interface extends Module{
	val io = IO(new Bundle{
		//connections with ctrl signal dispatch unit
		val STORE_READY = Output(UInt(1.W))//Indicates that the Store unit is ready for a store operation
		val DATA_IN = Input(UInt(1.W))//Signals the store unit that data has been given
		val STORE_SIZE = Input(UInt(2.W))//11-byte, 10-halfword, 00-word
		val STORE_ADDRESS_IN = Input(UInt(1.W))//Signals the store unit that address has been given
		val LOAD_READY = Output(UInt(1.W))//Indicates that the Load unit is ready for a store operation
		val LOAD_SIZE = Input(UInt(2.W))//11-byte, 10-halfword, 00-word
		val LOAD_ADDRESS_IN = Input(UInt(1.W))//Signals the store unit that address has been given
		val EXTENSION = Input(UInt(1.W))//=0 unsigned extension
		//connections with datapaths
		val store_data = Input(SInt(32.W))
		val store_address = Input(UInt(32.W))
		val load_data = Output(SInt(32.W))
		val load_address = Input(UInt(32.W))
	})
	
	val storeUnit = Module(new Store_Unit())
	val dataMemory = Module(new Memory())
	val loadUnit = Module(new Load_Unit())
	
	//Connecting Store Unit to IO
	io.STORE_READY := storeUnit.io.STORE_READY
	storeUnit.io.DATA_IN := io.DATA_IN
	storeUnit.io.STORE_SIZE := io.STORE_SIZE
	storeUnit.io.ADDRESS_IN := io.STORE_ADDRESS_IN
	storeUnit.io.store_data := io.store_data
	storeUnit.io.store_address := io.store_address
	
	//Connecting load unit to IO
	//connections with ctrl signal dispatch unit
	io.LOAD_READY := loadUnit.io.LOAD_READY
	loadUnit.io.LOAD_SIZE := io.LOAD_SIZE
	loadUnit.io.ADDRESS_IN := io.LOAD_ADDRESS_IN
	loadUnit.io.EXTENSION := io.EXTENSION
	io.load_data := loadUnit.io.load_data
	loadUnit.io.load_address := io.load_address
	
	//Connecting Store Unit to data memory
	dataMemory.io.mem_write_data := storeUnit.io.mem_write_data
	dataMemory.io.mem_write_address := storeUnit.io.mem_write_address
	dataMemory.io.mem_write := storeUnit.io.mem_write
	
	//Connecting Load Unit to data memory
	dataMemory.io.rdAddr := loadUnit.io.rdAddr
	loadUnit.io.rdData := dataMemory.io.rdData
}

object data_memory_interface extends App{
    (new chisel3.stage.ChiselStage).emitVerilog(new data_memory_interface())
}
