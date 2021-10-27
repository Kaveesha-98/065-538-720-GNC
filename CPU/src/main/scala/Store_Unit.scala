import chisel3._
import chisel3.util._

class Store_Unit extends Module{
	val io = IO(new Bundle{
		//Ports connecting to main memory
		val mem_write_data = Output(SInt(8.W))
		val mem_write_address = Output(UInt(32.W))
		val mem_write = Output(UInt(1.W))
		//connections with ctrl signal dispatch unit
		val STORE_READY = Output(UInt(1.W))//Indicates that the Store unit is ready for a store operation
		val DATA_IN = Input(UInt(1.W))//Signals the store unit that data has been given
		val STORE_SIZE = Input(UInt(2.W))//00-byte, 11-halfword, 01-word
		val ADDRESS_IN = Input(UInt(1.W))//Signals the store unit that address has been given
		//connections with datapaths
		val store_data = Input(SInt(32.W))
		val store_address = Input(UInt(32.W))
	})
	
	//Buffers data until address is given
	val store_data_buffer = RegInit(0.U(32.W))
	val store_data_size_buffer = RegInit(0.U(2.W))
	val store_data_buffer_address = RegInit(0.U(32.W))
	val absent :: present :: Nil = Enum(2)
	val storing = RegInit(absent)
	
	val ready :: not_ready :: Nil = Enum(2)
	val stateReg = RegInit(ready)
	
	io.mem_write_data := 0.S
	io.STORE_READY := 0.U
	io.mem_write := 0.U
	io.mem_write_address := 0.U
	//Storing the data
	
	
	switch(stateReg){
		is(ready){
			when(io.DATA_IN === 1.U){
				stateReg := not_ready
				store_data_buffer := io.store_data.asUInt
				store_data_size_buffer := io.STORE_SIZE
				io.STORE_READY := 0.U
			}
			io.STORE_READY := 1.U
		}
		is(not_ready){
			when(io.ADDRESS_IN === 1.U & storing === absent){
				store_data_buffer_address := io.store_address
				storing := present				
			}
			io.STORE_READY := 0.U
		}
	
	}
	
	switch(storing){
		is(present){
			io.mem_write_address := store_data_buffer_address
			io.mem_write_data := store_data_buffer(7, 0).asSInt
			io.mem_write := 1.U
			//store_data_buffer := store_data_buffer >> 8
			store_data_buffer := Cat("b0000_0000".U, store_data_buffer(31, 8))
			store_data_buffer_address := store_data_buffer_address + 1.U
			when(store_data_size_buffer === 3.U){
				stateReg := ready//Unit is ready for another store instruction
				storing := absent
			}otherwise{
				store_data_size_buffer := store_data_size_buffer + 1.U
			}
		}
		is(absent){
		io.mem_write_data := 0.S
		io.mem_write_address := 0.U
		io.mem_write := 0.U
		}
	}
	
	

}

object Store_Unit extends App{
	(new chisel3.stage.ChiselStage).emitVerilog(new Store_Unit)
}
