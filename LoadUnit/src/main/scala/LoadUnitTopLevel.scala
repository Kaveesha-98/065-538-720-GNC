import chisel3._
import chisel3.util._
import chisel3.Driver

class Load_Unit extends Module{
	val io = IO(new Bundle{
		
		val load_mem_address_in = Input(UInt(32.W))				// Corresponding memory address to Load Data - Input
		val load_data = Input(SInt(8.W))						// Loaded Data into Load Unit		
		
		val LOAD_TO_REG = Input(UInt(1.W))						// Control signal to load data from Load Unit to a Register
		val LOAD_SIZE = Input(UInt(2.W))					    // Control signal containing the size of the data to be loaded
		val LOAD_ADDRESS_IN = Input(UInt(1.W))					// Control signal to enable mem read address to Load Unit
		
		val mem_read = Output(UInt(1.W))						// Control signal to load data
		val LOAD_READY = Output(UInt(1.W))						// Status of Load Unit

		val load_mem_address_out = Output(UInt(32.W))			// Corresponding memory address to Load Data - Output
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
		
	}.otherwise{
		io.load_mem_address_out := 0.U
		io.mem_read := 0.U
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

// Data Memory
class Memory() extends Module{
    val io = IO(new Bundle{
		val mem_read = Input(UInt(1.W))
        val rdAddr = Input(UInt(32.W))
        val rdData = Output(SInt(8.W))
        val wrEna = Input(Bool())
        val wrData = Input(SInt(8.W))
        val wrAddr = Input(UInt(32.W))
    })

    val mem = SyncReadMem(1024, SInt(8.W))
	val memData = WireInit(0.S(8.W))
    val wrDataReg = RegNext(io.wrData)
    val doForwardReg = RegNext(io.wrAddr === io.rdAddr && io.wrEna === 1.U)

    when(io.mem_read === 1.U) {
        memData := mem.read(io.rdAddr)
    }

    when(io.wrEna === 1.U) {
        mem.write(io.wrAddr , io.wrData)
    }
    
    io.rdData := Mux(doForwardReg , wrDataReg , memData)
}

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
	val present :: absent :: Nil = Enum(2)
	val storing = RegInit(absent)
	
	val ready :: not_ready :: Nil = Enum(2)
	val stateReg = RegInit(ready)
	
	io.mem_write_data := 0.S
	io.STORE_READY := 0.U
	
	//Storing the data
	when(storing === present){
		io.mem_write_address := store_data_buffer_address
		io.mem_write_data := store_data_buffer(7, 0).asSInt
		io.mem_write := 1.U
		store_data_buffer := store_data_buffer >> 8
		store_data_buffer_address := store_data_buffer_address + 1.U
		when(store_data_size_buffer === 3.U){
			stateReg := ready//Unit is ready for another store instruction
			storing := absent
		}otherwise{
			store_data_size_buffer := store_data_size_buffer + 1.U
		}
		
	}otherwise{
		io.mem_write_data := 0.S
		io.mem_write_address := 0.U
		io.mem_write := 0.U
	}
	
	switch(stateReg){
		is(ready){
			when(io.DATA_IN === 1.U){
				stateReg := not_ready
				store_data_buffer := io.store_data.asUInt
				store_data_size_buffer := io.STORE_SIZE
				io.STORE_READY := 1.U
			}
		}
		is(not_ready){
			when(io.ADDRESS_IN === 1.U && storing === absent){
				store_data_buffer_address := io.store_address
				storing := present				
			}
			io.STORE_READY := 0.U
		}	
	}
}


class TopLevel extends Module {
	val io = IO(new Bundle {
		val load_mem_address_in = Input(UInt(32.W))										
		
		val LOAD_TO_REG = Input(UInt(1.W))					
		val LOAD_SIZE = Input(UInt(2.W))					    
		val LOAD_ADDRESS_IN = Input(UInt(1.W))					
						
		val LOAD_READY = Output(UInt(1.W))						

		val load_data_out = Output(SInt(32.W))					

		val STORE_READY = Output(UInt(1.W))
		val DATA_IN = Input(UInt(1.W))
		val STORE_SIZE = Input(UInt(2.W))
		val ADDRESS_IN = Input(UInt(1.W))

		//connections with datapaths
		val store_data = Input(SInt(32.W))
		val store_address = Input(UInt(32.W))

		val dm_test_write = Output(SInt(8.W))
		val dm_test_read = Output(UInt(8.W))
		//val dm_test_load = Output(SInt(32.W))

	})
	// create LoadUnit and Data Memory
	val LU = Module(new Load_Unit ())
	val DM = Module(new Memory ())
	val SU = Module(new Store_Unit())

	// Connect stote Unit
	SU.io.store_data := io.store_data
	SU.io.store_address := io.store_address
	SU.io.DATA_IN := io.DATA_IN
	SU.io.STORE_SIZE := io.STORE_SIZE
	SU.io.ADDRESS_IN := io.ADDRESS_IN

	io.STORE_READY := SU.io.STORE_READY

	// connect LoadUnit
	LU.io.load_mem_address_in := io.load_mem_address_in
	//LU.io.load_data := DM.io.load_data
	LU.io.LOAD_TO_REG := io.LOAD_TO_REG
	LU.io.LOAD_SIZE := io.LOAD_SIZE
	LU.io.LOAD_ADDRESS_IN := io.LOAD_ADDRESS_IN
	io.LOAD_READY := LU.io.LOAD_READY

	// Connect Data memory and Store Unit
	DM.io.wrEna := SU.io.mem_write
	DM.io.wrData := SU.io.mem_write_data
	DM.io.wrAddr := SU.io.mem_write_address

	// Connect Data memory and Load Unit
	DM.io.rdAddr := LU.io.load_mem_address_out
	DM.io.mem_read := LU.io.mem_read
	LU.io.load_data := DM.io.rdData

	io.load_data_out := LU.io.load_data_out
	io.dm_test_write := SU.io.mem_write_data
	io.dm_test_read := DM.io.rdAddr
	//io.dm_test_load := io.load_data_out
	io.load_data_out := LU.io.load_data_out
}

object TopLevel extends App{
	(new chisel3.stage.ChiselStage).emitVerilog(new TopLevel)
}

/*object Load_Unit extends App{
	(new chisel3.stage.ChiselStage).emitVerilog(new Load_Unit)
}*/