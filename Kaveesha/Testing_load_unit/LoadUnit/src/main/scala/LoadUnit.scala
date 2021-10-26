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

	})

	// Set vatiables for outputs
	val load_mem_address_out = WireInit(0.U(32.W))
	val mem_read = WireInit(0.U(1.W))
	val load_data_out = WireInit(0.S(32.W))
	val LOAD_READY = WireInit(0.U(1.W))

	// Buffers
	val load_data_buffer = RegInit(0.S(32.W))
	val load_data_size_buffer = RegInit(0.U(2.W))
	val load_data_address_buffer = RegInit(0.U(32.W))
	
	// Clock cycle Counter Regs
	val count_begin = RegInit(0.U(1.W))
	val load_begin = RegInit(0.U(1.W))
	val cntReg = RegInit(0.U(2.W))

	// States pf Mem read FSM
    	val present_r :: absent_r :: Nil = Enum(2)
	val reading = RegInit(absent_r)

	// States of data Load FSM
    	val present_l :: absent_l :: Nil = Enum(2)
	val loading = RegInit(absent_l)
	
	// States of ststus of Load_Unit FSM
	val ready :: not_ready :: Nil = Enum(2)
	val stateReg = RegInit(ready)
	
	io.load_mem_address_out := load_mem_address_out
	io.mem_read := mem_read
	io.load_data_out := load_data_out
	io.LOAD_READY := LOAD_READY

	// Clock cycle counter for waiting after Mem read control signal is activated (2-clock cycles)
	when(count_begin === 1.U){
		cntReg := cntReg + 1.U
		when(cntReg === 2.U){
			load_begin := 1.U
			count_begin := 0.U
			cntReg := 0.U
		}
	}

	when(reading === present_r){
		io.load_mem_address_out := load_data_address_buffer
		io.mem_read := 1.U
		count_begin := 1.U
		count_begin := io.mem_read
        	when(load_data_size_buffer === 3.U){
			stateReg := ready                           
			reading := absent_r
        	}.otherwise{
            		load_data_address_buffer := load_data_address_buffer + 1.U
			load_data_size_buffer := load_data_size_buffer + 1.U
		}
		
	}
	
    	when(loading === present_l){
	    	load_data_buffer := io.load_data						
	   	when(load_data_size_buffer === 3.U){
			stateReg := ready                          
			loading := absent_l
       }.otherwise{
            	load_data_buffer := load_data_buffer << 8
		load_data_size_buffer := load_data_size_buffer + 1.U
		}
	}

	// Load_Unit FSM state transition and operations under each state, under control signals
	switch(stateReg){
		is(ready){
			when(io.LOAD_ADDRESS_IN === 1.U && reading === absent_r){
				stateReg := not_ready
				load_data_address_buffer := io.load_mem_address_in
				load_data_size_buffer := io.LOAD_SIZE
				reading := present_r
				io.LOAD_READY := 0.U
			}.otherwise{
				io.LOAD_READY := 1.U
			}
		}
		is(not_ready){
			when(load_begin === 1.U){
				loading := present_l
				load_begin := 0.U
				io.LOAD_READY := 0.U				
			}.elsewhen(io.LOAD_TO_REG === 1.U && loading === absent_l){
				stateReg := ready
				io.load_data_out := load_data_buffer
			}
		}	
	}
}

object Load_Unit extends App{
	(new chisel3.stage.ChiselStage).emitVerilog(new Load_Unit)
}
