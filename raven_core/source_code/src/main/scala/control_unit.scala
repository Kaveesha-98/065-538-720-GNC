import chisel3._
import chisel3.util._
import chisel3.Driver

// Global constats
object opcodes {
  //ALU Operations
  val register = "b0110011".U(7.W)	/*register-register instructions*/
  val immediate = "b0010011".U(7.W) 	/*register-immediate instructions*/
  val store = "b0100011".U(7.W)
  val load = "b0000011".U(7.W)
  val branch = "b1100011".U(7.W)		/*conditional branching*/
  val jalr = "b1100111".U(7.W)
  val jal = "b1101111".U(7.W)
  val auipc = "b0010111".U(7.W)
  val lui = "b0110111".U(7.W)
}

class control_unit extends Module {
    val io = IO(new Bundle{
        val signals_read = Output(new datapath_read())
        val signals_alu = Output(new datapath_alu())
        val signals_writeback = Output(new datapath_writeback())
        val signals_branch1 = Output(new datapath_branch_stage1())
        val signals_branch2 = Output(new datapath_branch_stage2())
        val signals_branch3 = Output(new datapath_branch_stage3())

        val next_PC = Input(UInt(32.W))
        
        //write_address channel signals
        val write_address_valid = Output(UInt(1.W))
        val write_address_ready = Input(UInt(1.W))
        val write_address_size = Output(UInt(2.W))
        
        //write_data channel signals
        val write_data_valid = Output(UInt(1.W))
        val write_data_ready = Input(UInt(1.W))
        
        //load_address channel signals
        val load_address_ready = Input(UInt(1.W))
        val load_address_valid = Output(UInt(1.W))
        val load_address_size = Output(UInt(2.W))
        
        //load_data channel signals
        val load_data_valid = Input(UInt(1.W))
        val load_data_ready = Output(UInt(1.W))
        
        val load_extend_type = Output(UInt(1.W)) /*when 1 use unsigned extend*/
        
        val fetch_PC = Input(UInt(32.W))
        val valid_PC = Output(UInt(32.W))
        val fetch_valid = Input(UInt(1.W))
        val ready = Output(UInt(1.W))
        val fetch_PC_invalid = Output(UInt(1.W))
        val instruction = Input(UInt(32.W))
    })
    
    //----------read stage------------------------------------------------------
    val read_PC = Reg(UInt(32.W))
    val read_instruction = Reg(UInt(32.W))
    io.signals_read.PC := read_PC
    io.signals_read.rs1 := Mux(read_instruction(6, 0) === opcodes.lui, 0.U, read_instruction(19, 15))
    io.signals_read.rs2 := read_instruction(24, 20)
    
    /*setting immediate*/
    
    val immItype = Cat(Fill(20, read_instruction(31)), read_instruction(31, 20))
    val immItype_shift = Cat(0.U(27.W), read_instruction(24, 20))
    val immStype = Cat(Fill(20, read_instruction(31)), read_instruction(31, 25), read_instruction(11, 7))
    val immBtype = Cat(Fill(20, read_instruction(31)), read_instruction(31), read_instruction(7), read_instruction(30, 25), read_instruction(11, 8), 0.U(1.W))
    val immUtype = Cat(read_instruction(31, 12), 0.U(12.W))
    val immJtype = Cat(Fill(12, read_instruction(31)), read_instruction(31), read_instruction(19, 12), read_instruction(20), read_instruction(30, 21), 0.U(1.W))
    
    val read_immediate = Reg(UInt(32.W))
    
    io.signals_read.immediate := immItype/*loads, jalr*/
    
    switch(read_instruction(6,0)){
    	is(opcodes.immediate){ io.signals_read.immediate := Mux(read_instruction(30).asBool, immItype_shift, immItype) }
    	is(opcodes.store)    { io.signals_read.immediate := immStype }
    	is(opcodes.branch)   { io.signals_read.immediate := immBtype }
    	is(opcodes.jal)      { io.signals_read.immediate := immJtype }
    	is(opcodes.auipc)    { io.signals_read.immediate := immUtype }
    	is(opcodes.lui)		 { io.signals_read.immediate := immUtype }
    }
    
    //----------alu stage--------------------------------------------------------
    val alu_instruction = Reg(UInt(32.W))
    val alu_func3 = alu_instruction(14, 12)
    
    /*except register-register and register-immediate all instructions use addition always*/
    io.signals_alu.alu_op := Mux(alu_instruction(6,0) === opcodes.register || alu_instruction(6,0) === opcodes.immediate,
    	Cat(alu_instruction(30), alu_func3), constants.add)
    	
    io.signals_alu.choose_pc := (alu_instruction === opcodes.jalr || alu_instruction === opcodes.auipc).asUInt /*PC chosen as alu input only in jalr and auipc*/
    
    /*immediate is not an input only in register-register instructions*/
    io.signals_alu.choose_immediate := (alu_instruction =/= opcodes.register).asUInt
    
    //----------writeback stage---------------------------------------------------
    val writeback_instruction = Reg(UInt(32.W))
    
    io.signals_writeback.rd := writeback_instruction(11, 7)
    
    io.signals_writeback.choose_data := 0.U
    
    switch(writeback_instruction(6, 0)){
    	is(opcodes.jal){ io.signals_writeback.choose_data := 2.U }
    	is(opcodes.jalr){ io.signals_writeback.choose_data := 2.U }
    	is(opcodes.load){ io.signals_writeback.choose_data := 1.U }
    }
    
    //----------branch stage1-----------------------------------------------------
    io.signals_branch1.immediate := Mux(read_instruction(6, 0) === opcodes.jal, immJtype, immBtype)   
    
    //----------branch stage2----------------------------------------------------
    val branch2_instruction = Reg(UInt(32.W))
    
    io.signals_branch2.branch_op := Cat(branch2_instruction(14, 12), 2.U(2.W))
    
    switch(branch2_instruction(6, 0)){
    	is(opcodes.jal){io.signals_branch2.branch_op := Cat(branch2_instruction(14, 12), branch2_instruction(3, 2))}
    	is(opcodes.jalr){io.signals_branch2.branch_op := Cat(branch2_instruction(14, 12), branch2_instruction(3, 2))}
    	is(opcodes.branch){io.signals_branch2.branch_op := Cat(branch2_instruction(14, 12), branch2_instruction(3, 2))}
    }
    //----------branch stage3----------------------------------------------------
    
    
    //--------------memory----------------------------------
    io.write_address_size := writeback_instruction(13, 12)
    io.load_address_size := writeback_instruction(13, 12)
    io.load_extend_type := writeback_instruction(14)
    
    //------updater------------------------------------
    io.signals_read.update := 1.U
    io.signals_alu.update := 1.U
    io.signals_writeback.update := 0.U
    io.signals_branch1.update := 1.U
    io.signals_branch2.update := 1.U
    io.signals_branch3.update := 1.U
    
    val PC = RegInit(0.U(32.W))
    val ready :: stall :: execStore :: execLoad :: execBranch :: execOther :: update_pc :: Nil = Enum(7)
    val stateReg = RegInit(ready)
    val count = Reg(UInt(3.W))
    val instruction = Reg(UInt(32.W))
    
    read_instruction := instruction
    alu_instruction := instruction
    writeback_instruction := instruction
    branch2_instruction := instruction
    /*
    ready - compare with fetched PC
    stall - wait to get correct instruction
    exec - executing instruction*/
    
    io.fetch_PC_invalid := 0.U
    io.write_data_valid := 0.U
    io.write_address_valid := 0.U
    
    io.load_address_valid := 0.U
    io.load_data_ready := 0.U
    
    io.ready := 0.U
    
    switch(stateReg){
    	is(ready){
    		io.ready := 1.U
    		when(io.fetch_valid.asBool){
    			io.fetch_PC_invalid := io.fetch_PC =/= PC
    			stateReg := stall
    			count := 3.U
    			when(io.fetch_PC === PC){
    				instruction := io.instruction
    				read_PC := PC
    				stateReg := execOther
    				switch(io.instruction(6,0)){
    					is(opcodes.store){ stateReg := execStore }
    					is(opcodes.load){ 
    						stateReg := execLoad
    						count := 4.U 
    					}
    					is(opcodes.branch){ stateReg := execBranch }
    				}
    			}
    		}
    	}
    	is(stall){
    		when(io.fetch_valid.asBool){
    			stateReg := ready
    		}
    	}
    	is(execStore){
    		count := count - 1.U
    		switch(count){
    			is(1.U){ 
    				io.write_data_valid := 1.U
    				count := Mux(io.write_data_ready.asBool, 0.U, 1.U)
    			}
    			is(0.U){
    				io.write_address_valid := 1.U
    				stateReg := Mux(io.write_address_ready.asBool, update_pc, execStore)
    				count := 0.U
    			}
    		}
    	}
    	is(execLoad){
    		count := count - 1.U
    		switch(count){
    			is(1.U){
    				io.load_address_valid := 1.U
    				count := Mux(io.load_address_ready.asBool, 0.U, 1.U)
    			}
    			is(0.U){
    				io.load_data_ready := 1.U
    				stateReg := Mux(io.load_data_valid.asBool, update_pc, execLoad)
    				count := 0.U
    				io.signals_writeback.update := Mux(io.load_data_valid.asBool, 1.U, 0.U)
    			}
    		}
    	}
    	is(execBranch){
    		count := count - 1.U
    		switch(count){
    			is(0.U){ stateReg := update_pc }
    		}
    	}
    	is(execOther){
    		count := count - 1.U
    		switch(count){
    			is(0.U){ 
    				stateReg := update_pc
    				io.signals_writeback.update := 1.U
    			}
    		}
    	}
    	is(update_pc){
    		stateReg := ready
    		PC := io.next_PC
    	}
    }
    
    
    
    
    io.valid_PC := PC
}

object control_unit extends App{
    (new chisel3.stage.ChiselStage).emitVerilog(new control_unit())
}
