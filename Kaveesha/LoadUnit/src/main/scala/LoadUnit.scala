import chisel3._
import chisel3.util._
import chisel3.Driver

class Load_Unit extends Module{
	val io = IO(new Bundle{
		
		val load_mem_address_in = Input(UInt(32.W))				// Corresponding memory address to Load Data - Input
		val load_data = Input(SInt(8.W))					// Loaded Data into Load Unit		
		
		val LOAD_TO_REG = Input(UInt(1.W))					// Control signal to load data from Load Unit to a Register
		val LOAD_SIZE = Input(UInt(2.W))					// Control signal containing the size of the data to be loaded
		val LOAD_ADDRESS_IN = Input(UInt(1.W))					// Control signal to enable mem read address to Load Unit
		
		val mem_read = Output(UInt(1.W))					// Control signal to load data
		val LOAD_READY = Output(UInt(1.W))					// Status of Load Unit

		val load_mem_address_out = Output(UInt(32.W))				// Corresponding memory address to Load Data - Output
		val load_data_out = Output(SInt(32.W))					// Output from load unit ; the Loaded data into Load unit
		val EXTENSION = Input(UInt(1.W))
	})

	// Buffers
	val load_data_buffer = RegInit(0.U(32.W))
	val load_data_size_buffer = RegInit(0.U(2.W))
	val loaded_data_size_buffer = RegInit(0.U(2.W))
	val load_data_address_buffer = RegInit(0.U(32.W))
	val LOAD_SIZE = RegInit(0.U(2.W))
	val EXTENSION = RegInit(0.U(1.W))
	
	// States of ststus of Load_Unit FSM
	val ready :: not_ready :: Nil = Enum(2)
	val stateReg = RegInit(ready)

	io.load_data_out := 0.S
	io.LOAD_READY := 0.U
	io.load_mem_address_out := 0.U
	io.mem_read := 0.U
	
	
	//Implementing sign extension
	val MSB = Mux(LOAD_SIZE(0) === 1.U, load_data_buffer(7), load_data_buffer(15))
	val needMask = MSB & EXTENSION
	val mask = Cat(Mux(LOAD_SIZE(1) === 1.U, "hffff".U, "h0000".U), Mux(LOAD_SIZE === 3.U, "hff".U, "h00".U))
	val extending_mask = Mux(needMask === 1.U, mask, "h000000".U)
	val data_out = Cat(load_data_buffer(31,8) | extending_mask, load_data_buffer(7,0))
	
	io.load_data_out := data_out.asSInt

	// Load_Unit FSM state transition and operations under each state, under control signals
	switch(stateReg){
		is(ready){
			when(io.LOAD_ADDRESS_IN === 1.U){
				stateReg := not_ready
				load_data_address_buffer := io.load_mem_address_in
				load_data_size_buffer := io.LOAD_SIZE
				loaded_data_size_buffer := io.LOAD_SIZE
				load_data_buffer := 0.U
				io.LOAD_READY := 0.U
				LOAD_SIZE := io.LOAD_SIZE
				EXTENSION := io.EXTENSION
			}.otherwise{
				io.LOAD_READY := 1.U
				io.mem_read := 0.U
			}
		}
		is(not_ready){
			load_data_buffer := Cat(load_data_buffer(23,0), io.load_data.asUInt)
			io.load_mem_address_out := load_data_address_buffer
			io.mem_read := 1.U
        	when(load_data_size_buffer === 3.U){                       
				stateReg := ready
        	}.otherwise{
            	load_data_address_buffer := load_data_address_buffer + 1.U
				load_data_size_buffer := load_data_size_buffer + 1.U
			}
		}	
	}
}

object Load_Unit extends App{
	(new chisel3.stage.ChiselStage).emitVerilog(new Load_Unit)
}
