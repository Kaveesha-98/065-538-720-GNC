import chisel3._
import chisel3.util._
import chisel3.Driver

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
		val data_in = new instruction_channel()
		val data_out = Flipped(new instruction_channel())
		val reset = Input(Bool())
	})
	
	val empty :: full :: Nil = Enum(2)
	val stateReg = RegInit(empty)
	
	val regInstruction = Reg(UInt(32.W))
	val regAddress = Reg(UInt(32.W))
	
	io.data_in.ready := stateReg === empty
	io.data_out.valid := stateReg === full
	
	when(io.reset){
		stateReg := empty
	}.otherwise{
		when(stateReg === empty){
			when(io.data_in.valid){
				regInstruction := io.data_in.instruction
				regAddress := io.data_in.address
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
		val cache_address_channel = new instruction_read_address_channel()
		val cache_data_channel = new instruction_read_data_channel()
		val control_unit_channel = Flipped(new instruction_channel())
		
		val PC_invalid = Input(Bool())
		//signals that the fetched PC is invalid
		val valid_PC = Input(UInt(32.W))
	})
	
	val reset_buffer :: request :: valid_wait :: invalid_wait :: Nil = Enum(4)
	val stateReg = RegInit(reset_buffer)
	val resetBuffer = Wire(Bool())
	
	//creating buffers
	val buffers = Array.fill(depth){Module(new instruction_buffer)}
	
	val PC = Reg(UInt(32.W))
	
	//connecting buffers
	for(i <- 0 until depth - 1){
		buffers(i + 1).io.data_in <> buffers(i).io.data_out
		
		buffers(i).io.reset := resetBuffer
	}
	
	buffers(depth - 1).io.reset := resetBuffer
	
	buffers(0).io.data_in.instruction := io.cache_data_channel.RDATA
	buffers(0).io.data_in.address := PC
	buffers(0).io.data_in.valid := false.B
	
	io.control_unit_channel <> buffers(depth-1).io.data_out
	
	//when control unit rejects instruction due invalid PC
	val controlUnitReject = buffers(depth - 1).io.data_out.valid && io.control_unit_channel.ready && io.PC_invalid
	
	io.cache_address_channel.ARVALID := false.B
	io.cache_address_channel.ARADDR := PC
	
	io.cache_data_channel.RREADY := false.B
	
	resetBuffer := false.B
	
	switch(stateReg){
		is(reset_buffer){
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
				stateReg := reset_buffer
			}
		}
		is(valid_wait){
			io.cache_data_channel.RREADY := buffers(0).io.data_in.ready
			when(io.cache_data_channel.RVALID){
				//when new instruction available in the data channel
				when(controlUnitReject){
					stateReg := reset_buffer
				}.otherwise{
					when(buffers(0).io.data_in.ready){
						//buffers cannot accept new instruction
						stateReg := request
						PC := PC + 4.U
						buffers(0).io.data_in.valid := 1.U
					}
				}
			}.elsewhen(controlUnitReject){
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


object instruction_fetch_unit extends App{
    (new chisel3.stage.ChiselStage).emitVerilog(new instruction_fetch_unit(1))
}
