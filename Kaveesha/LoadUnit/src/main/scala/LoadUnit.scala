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
		val load_begin = Input(UInt(1.W))					// Control signal to start accepting load data from data memory
		val load_data_out = Output(SInt(32.W))					// Output from load unit ; the Loaded data into Load unit
	})

	// Buffers
	val load_data_buffer = RegInit(0.S(32.W))
	val load_data_size_buffer = RegInit(0.U(2.W))
	val loaded_data_size_buffer = RegInit(0.U(2.W))
	val load_data_address_buffer = RegInit(0.U(32.W))

	// States pf Mem read FSM
    val absent_r :: present_r :: Nil = Enum(2)
	val reading = RegInit(absent_r)

	// States of data Load FSM
   	val absent_l :: present_l :: Nil = Enum(2)
	val loading = RegInit(absent_l)
	
	// States of ststus of Load_Unit FSM
	val ready :: not_ready :: Nil = Enum(2)
	val stateReg = RegInit(ready)

	when(reading === present_r){
		io.load_mem_address_out := load_data_address_buffer
		io.mem_read := 1.U
        	when(load_data_size_buffer === 3.U){                       
			reading := absent_r
        	}.otherwise{
            		load_data_address_buffer := load_data_address_buffer + 1.U
			load_data_size_buffer := load_data_size_buffer + 1.U
		}
		
	}.otherwise{
		io.load_mem_address_out := 0.U
		io.mem_read := 0.U
	}
	
    	when(loading === present_l){
       		load_data_buffer := Cat(load_data_buffer(23,0), io.load_data).asSInt			
        	when(loaded_data_size_buffer === 3.U){
			stateReg := not_ready                          
			loading := absent_l
       		}.otherwise{
            		load_data_buffer := load_data_buffer << 8
			loaded_data_size_buffer := loaded_data_size_buffer + 1.U
		}
	}

	io.load_data_out := 0.S
	io.LOAD_READY := 0.U

	// Load_Unit FSM state transition and operations under each state, under control signals
	switch(stateReg){
		is(ready){
			when(io.LOAD_ADDRESS_IN === 1.U && reading === absent_r){
				stateReg := not_ready
				load_data_address_buffer := io.load_mem_address_in
				load_data_size_buffer := io.LOAD_SIZE
				loaded_data_size_buffer := io.LOAD_SIZE
				reading := present_r
				io.LOAD_READY := 0.U
			}.otherwise{
				io.LOAD_READY := 1.U
			}
		}
		is(not_ready){
			when(io.LOAD_TO_REG === 1.U && loading === absent_l){
				stateReg := ready
				io.load_data_out := load_data_buffer
			}.elsewhen(io.load_begin === 1.U && loading === absent_l){
				loading := present_l
				io.LOAD_READY := 0.U				
			}
		}	
	}
}

object Load_Unit extends App{
	(new chisel3.stage.ChiselStage).emitVerilog(new Load_Unit)
}
