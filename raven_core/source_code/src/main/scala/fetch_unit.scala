class instruction_channel extends Bundle {
	val instruction = Input(UInt(32.W))
	val address = Input(UInt(32.W))
	val ready = Output(Bool())
	val valid = Input(Bool())
}

class instruction_read_address_channel extends Bundle {
	//as seen from a master component
	val ARADDR = Output(UInt(32.W))
	val ARVALID = Output(Bool())
	val ARREADY = Input(Bool())
}

class instruction_read_data_channel extends Bundle {
	//as seen from a master component
	val RDATA = Input(UInt(32.W))
	val RREADY = Output(Bool())
	val RVALID = Input(Bool())
}

class instruction_buffer extends Module {
	val io = IO(new Bundle{
		data_in = new instruction_channel()
		data_out = Flipped(new instruction_channel())
		val reset = Input(Bool())
	})
	
	val empty :: full :: Nil = Enum(2)
	val stateReg = RegInit(empty)
	
	val regInstruction = Reg(UInt(32.W))
	val regAddress = Reg(UInt(32.W))
	
	io.data_in.ready := stateReg === empty
	io.data_out.valid := stateReg === full
	
	when(reset){
		stateReg := empty
	}.otherwise{
		when(stateReg === empty){
			when(io.data_in.valid){
				regInstruction := io.data_in.instruction
				redAddress := io.data_in.address
				stateReg := full
			}
		}.otherwise{
			when(io.data_out.ready){
				stateReg := empty
			}
		}
	}
	io.data_out.instruction := regInstruction
	io.data_out.address := regAddress
}

class instruction_fetch_unit(depth: Int) extends Module {
	val io = IO(new Bundle{
		cache_address_channel = new instruction_read_address_channel()
		cache_data_channel = new instruction_read_data_channel()
		control_unit_channel = Flipped(new instruction_channel())
		
		val PC_invalid = Input(Bool())
		val valid_PC = Input(UInt(32.W))
	})
	
	val reset :: request :: valid_wait :: invalid_wait :: Nil = Enum(4)
	val stateReg = RegInit(reset)
	val resetBuffer = Wire(Bool())
	
	//creating buffers
	val buffers = Array.fill(depth{Module(new insturction_buffer)})
	
	
	//connecting buffers
	for(i <- 0 until depth - 1){
		buffers(i + 1).io.data_in <> buffers(i).io.data_out
		
		buffers(i).io.reset := resetBuffer
	}
	
	buffers(0).io.data_in.instruction := io.cache_data_channel.RDATA
	buffers(0).io.data_in.instruction := PC
	
	val PC = Reg(UInt(32.W))
	
	io.control_unit_channel <> buffers(depth-1).io.data_out
	
	//when control unit rejects instruction due invalid PC
	val controlUnitReject = buffers(depth - 1).io.data_out.valid && control_unit_channel.io.ready && io.PC_invalid
	
	io.cache_address_channel.ARVALID := false.B
	
	io.cache_data_channel.ready := false.B
	
	resetBuffer := false.B
	
	switch(stateReg){
		is(reset){
			PC := io.valid_PC
			stateReg := request
			resetBuffer := true.B
		}
		is(request){
			io.cache_address_channel.ARVALID := true.B
			when(io.cache_address_channel.ARREADY){
				when(controlUnitReject){
					stateReg := invalid_wait
				}.otherwise{
					stateReg := valid_wait
				}
			}.elsewhen(controlUnitReject){
				stateReg := reset
			}
		}
		is(valid_wait){
			io.cache_data_channel.RREADY := buffers(0).io.data_in.ready
			when(io.cache_data_channel.RVALID){
				//when new instruction available in the data channel
				when(controlUnitReject){
					stateReg := reset
				}.otherwise{
					when(buffers(0).io.data_in.ready){
						//buffers cannot accept new instruction
						stateReg := request
						PC := PC + 4.U
						buffers(0).io.data_in.valid := 1.U
					}
				}
			}.eslewhen(controlUnitReject){
				//before new instruction available in the data channel
				stateReg := invalid_wait
			}
		}
		is(invalid_wait){
			io.cache_data_channel.RREADY := true.B
			PC := io.valid_PC
			resetBuffer := true.B
			when(io.cache_data_channel.RVALID){
				stateReg := request
			}
		}
	}
}

















