import chisel3._
import chisel3.util._
import chisel3.Driver

class control_unit(pipelined: Boolean) extends Module {
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
    	is(opcodes.immediate){ io.signals_read.immediate := Mux(read_instruction(13, 12) === "b01".U, immItype_shift, immItype) }
    	is(opcodes.store)    { io.signals_read.immediate := immStype }
    	is(opcodes.branch)   { io.signals_read.immediate := immBtype }
    	is(opcodes.jal)      { io.signals_read.immediate := immJtype }
    	is(opcodes.auipc)    { io.signals_read.immediate := immUtype }
    	is(opcodes.lui)		 { io.signals_read.immediate := immUtype }
    }
    
    //----------alu stage--------------------------------------------------------
    val alu_instruction = Reg(UInt(32.W))
    val alu_func3 = alu_instruction(14, 12)

	val isShamtsrai = (alu_instruction(6,0) === opcodes.immediate && alu_instruction(13,12) === "b01".U).asUInt & alu_instruction(30)
    
    /*except register-register and register-immediate all instructions use addition always*/
    io.signals_alu.alu_op := Mux(alu_instruction(6,0) === opcodes.register || alu_instruction(6,0) === opcodes.immediate,
    	Cat(isShamtsrai, alu_func3), constants.add)
    	
    io.signals_alu.choose_pc := (alu_instruction === opcodes.jalr || alu_instruction === opcodes.auipc).asUInt /*PC chosen as alu input only in jalr and auipc*/
    
    /*immediate is not an input only in register-register instructions*/
    io.signals_alu.choose_immediate := (alu_instruction(6,0) =/= opcodes.register && alu_instruction(6,0) =/= opcodes.branch).asUInt
    
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
    if(!pipelined){
    	/*non pipelined implementation*/
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
    }else{
    	/*pipelined implementation*/
    	/*FSM states of signal execution units*/
    	val idle :: exec :: stall :: execBranch :: write_data_stall :: write_addr_stall :: load_addr_stall :: load_data_stall :: branch_update :: Nil = Enum(9)
    	
    	/*accepting instructions from prefetch unit*/
    	val PC = RegInit(0.U(32.W))			/*PC to verify the correct PC of instruction before appending*/
    	val ins_accept = RegInit(idle)		/*FSM for appending instructions to pipeline*/
    	
    	val reg_instruction = Reg(UInt(32.W))	/*buffering the instruction when stalls need to occur*/
    	
    	val read_stage_updated = Wire(UInt(1.W))
    	
    	//--------------------------checking whether register sources are available(avoiding data dependency hazrds-------------
    	val read_rd_valid = RegInit(0.U(1.W))
    	val read_stall = Wire(UInt(1.W))
    	
    	val alu_rd_valid = RegInit(0.U(1.W))
    	val alu_stall = Wire(UInt(1.W))
    	
    	val writeback_rd_valid = RegInit(0.U(1.W))
    	val writeback_stall = Wire(UInt(1.W))
    	
    	val update_instruction = Mux(ins_accept === stall, reg_instruction, io.instruction)
    	
    	val read_rd_rs1_match = Mux(read_rd_valid.asBool, (read_instruction(11, 7) === update_instruction(19, 15)).asUInt, 0.U(1.W))
    	val read_rd_rs2_match = Mux(read_rd_valid.asBool, (read_instruction(11, 7) === update_instruction(24, 20)).asUInt, 0.U(1.W))
    	
    	val alu_rd_rs1_match = Mux(alu_rd_valid.asBool, (alu_instruction(11, 7) === update_instruction(19, 15)).asUInt, 0.U(1.W))
    	val alu_rd_rs2_match = Mux(alu_rd_valid.asBool, (alu_instruction(11, 7) === update_instruction(24, 20)).asUInt, 0.U(1.W))
    	
    	val writeback_rd_rs1_match = Mux(writeback_rd_valid.asBool, (writeback_instruction(11, 7) === update_instruction(19, 15)).asUInt, 0.U(1.W))
    	val writeback_rd_rs2_match = Mux(writeback_rd_valid.asBool, (writeback_instruction(11, 7) === update_instruction(24, 20)).asUInt, 0.U(1.W))
    	
    	val rs1_match = Cat(read_rd_rs1_match, alu_rd_rs1_match, writeback_rd_rs1_match)
    	val rs2_match = Cat(read_rd_rs2_match, alu_rd_rs2_match, writeback_rd_rs2_match)
    	//----------------------------------------------------------------------------------------------------------------------
    	
    	io.ready := 0.U
		io.fetch_PC_invalid := 0.U
    	
    	val update_read = Wire(UInt(1.W))/*indicates that the instruction can be appended assuming no pipeline stall*/
    	val rd_valid = Wire(UInt(1.W))/*indicates that the new instruction to the pipeline has an rd field*/
    	val branching = Wire(UInt(1.W))/*indicates that the new instruction to the pipeline is a branching instruction*/
    	
    	val branchFinished = Wire(UInt(1.W)) /*to indicate when an branch instruction is finished*/
    	
    	read_stage_updated := 0.U
    	branching := 0.U
    	rd_valid := 0.U
    	branchFinished := 0.U
    	update_read := 0.U
    	
    	read_stall := 0.U
    	alu_stall := 0.U
    	writeback_stall := 0.U
    	
    	switch(update_instruction(6, 0)){
    		is(opcodes.register){
    			branching := 0.U
    			rd_valid := 1.U
    			update_read := 1.U
    			when(rs1_match.orR || rs2_match.orR){
    				update_read := 0.U
    			}
    		}
    		is(opcodes.immediate){
    			branching := 0.U
    			rd_valid := 1.U
    			update_read := 1.U
    			when(rs1_match.orR){
    				update_read := 0.U
    			}
    		}
    		is(opcodes.store){
    			branching := 0.U
    			rd_valid := 0.U
    			update_read := 1.U
    			when(rs1_match.orR || rs2_match.orR){
    				update_read := 0.U
    			}
    		}
    		is(opcodes.load){
    			branching := 0.U
    			rd_valid := 1.U
    			update_read := 1.U
    			when(rs1_match.orR){
    				update_read := 0.U
    			}
    		}
    		is(opcodes.branch){
    			branching := 1.U
    			rd_valid := 0.U
    			update_read := 1.U
    			when(rs1_match.orR || rs2_match.orR){
    				update_read := 0.U
    			}
    		}
    		is(opcodes.jalr){
    			branching := 1.U
    			rd_valid := 1.U
    			update_read := 1.U
    			when(rs1_match.orR){
    				update_read := 0.U
    			}
    		}
    		is(opcodes.jal){
    			branching := 1.U
    			rd_valid := 1.U
    			update_read := 1.U
    		}
    		is(opcodes.auipc){
    			branching := 0.U
    			rd_valid := 1.U
    			update_read := 1.U
    		}
    		is(opcodes.lui){
    			branching := 0.U
    			rd_valid := 1.U
    			update_read := 1.U
    		}
    	}
    	
    	switch(ins_accept){
    		is(idle){
    			io.ready := 1.U
    			ins_accept := idle
    			when(io.fetch_valid.asBool && io.fetch_PC === PC){
    				ins_accept := exec
    				when(Cat(read_stall, alu_stall, writeback_stall).orR){
    					/*when the pipeline is stalled and no instructions can be added*/
    					/*since io.ready = 1.U have to accept the instruction and stall*/
    					reg_instruction := io.instruction
    					ins_accept := stall
    				}.otherwise{
    					/*pipeline is free*/
    					when(update_read.asBool){
    						read_PC := PC
    						read_instruction := io.instruction
    						read_rd_valid := rd_valid
    						ins_accept := Mux(branching.asBool, execBranch, exec)
    						PC := PC + 4.U
    						read_stage_updated := 1.U
    					}.otherwise{
    						ins_accept := stall/*instruction cannot be added as source registers are not updated*/
    						reg_instruction := io.instruction
    					}
    				}
    			}.elsewhen(io.fetch_valid.asBool){
    				io.fetch_PC_invalid := 1.U
    				ins_accept := idle
    			}
    		}
    		is(exec){
    			io.ready := 1.U
    			when(io.fetch_valid.asBool){
    				when(io.fetch_PC === PC){
    					ins_accept := exec
    					when(Cat(read_stall, alu_stall, writeback_stall).orR){
    						reg_instruction := io.instruction
    						ins_accept := stall
    					}.otherwise{
    						/*pipeline is free*/
							when(update_read.asBool){
								read_PC := PC
								read_instruction := io.instruction
								read_rd_valid := rd_valid
								ins_accept := Mux(branching.asBool, execBranch, exec)
								PC := PC + 4.U
    							read_stage_updated := 1.U
							}.otherwise{
								ins_accept := stall/*instruction cannot be added as source registers are not updated*/
								reg_instruction := io.instruction
							}
    					}
    				}.otherwise{
    					io.fetch_PC_invalid := 1.U
    					ins_accept := idle
    				}
    			}.otherwise{
    				ins_accept := idle/*no instruction to accept go idle*/
    			}
    		}
    		is(stall){
    			io.ready := 0.U
    			when(Cat(read_stall, alu_stall, writeback_stall).orR){
    				ins_accept := stall
    			}.otherwise{
    				when(update_read.asBool){
    					read_instruction := reg_instruction
    					read_PC := PC
    					read_rd_valid := rd_valid
    					ins_accept := Mux(branching.asBool, execBranch, exec)
						PC := PC + 4.U
    					read_stage_updated := 1.U
    				}
    			}
    		}
    		is(execBranch){
    			io.ready := 0.U
    			when(branchFinished.asBool){
    				ins_accept := branch_update
    			}
    		}
    		is(branch_update){
    			PC := io.next_PC
    			ins_accept := idle
    		}
    	}
    	
    	val fsm_read = RegInit(idle)
    	
    	val alu_stage_updated = Wire(UInt(1.W))
    	
    	io.signals_read.update := 0.U
		io.signals_branch1.update := 0.U
		
		alu_stage_updated := 0.U
    	
    	switch(fsm_read){
    		is(idle){
    			read_stall := 0.U
    			when(read_stage_updated.asBool){
    				when(alu_stall.asBool || writeback_stall.asBool){
    					fsm_read := stall
    				}.otherwise{
    					fsm_read := exec
    				}
    			}
    		}
    		is(exec){
    			io.signals_read.update := 1.U
    			io.signals_branch1.update := 1.U
    			when(alu_stall.asBool || writeback_stall.asBool){
    				fsm_read := stall
    				io.signals_read.update := 0.U
    				io.signals_branch1.update := 0.U
    				read_stall := 1.U
    			}.otherwise{
    				alu_instruction := read_instruction
    				branch2_instruction := read_instruction
    				alu_rd_valid := read_rd_valid
					alu_stage_updated := 1.U
    				when(read_stage_updated.asBool){
    					fsm_read := exec
    				}.otherwise{
    					fsm_read := idle
    					read_rd_valid := 0.U
    				}
    			}
    		}
    		is(stall){
    			read_stall := 1.U
    			io.signals_read.update := 0.U
    			io.signals_branch1.update := 0.U
    			when(alu_stall.asBool || writeback_stall.asBool){
    				fsm_read := stall
    			}.otherwise{
    				fsm_read := exec
    			}
    		}
    	}
    	
    	val fsm_alu = RegInit(idle)
    	
    	val writeback_stage_updated = Wire(UInt(1.W))
    	
    	io.signals_alu.update := 0.U
    	io.signals_branch2.update := 0.U
		io.write_data_valid := 0.U
		writeback_stage_updated := 0.U
    	
    	switch(fsm_alu){
    		is(idle){
    			alu_stall := 0.U
    			when(alu_stage_updated.asBool){
    				when(writeback_stall.asBool){
    					fsm_alu := stall
    				}.otherwise{
    					fsm_alu := exec
    				}
    			}
    		}
    		is(exec){
    			io.signals_alu.update := 0.U
    			io.signals_branch2.update := 0.U
    			when(alu_instruction(6, 0) === opcodes.store && (~io.write_data_ready).asBool){
    				/*write data cannot be accepted at this time*/
    				fsm_alu := write_data_stall
    				alu_stall := 1.U
    				io.write_data_valid := 1.U
    			}.otherwise{
    				/*Write data can be accepted at this time*/
    				io.write_data_valid := (alu_instruction(6, 0) === opcodes.store).asUInt
    				/*moving to next stage of pipeline or being stalled*/
    				when(writeback_stall.asBool){
    					fsm_alu := stall
    					alu_stall := 1.U
    				}.otherwise{
    					io.signals_alu.update := 1.U
    					io.signals_branch2.update := 1.U
    					writeback_instruction := alu_instruction
    					writeback_rd_valid := alu_rd_valid
    					writeback_stage_updated := 1.U
    					when(alu_stage_updated.asBool){
    						fsm_alu := exec
    					}.otherwise{
    						alu_rd_valid := 0.U
    						fsm_alu := idle
    					}
    				}
    			}
    		}
    		is(write_data_stall){
    			/*wait for write data to be accepted*/
    			alu_stall := 1.U
    			io.write_data_valid := 1.U
    			when(io.write_data_ready.asBool){
    				fsm_alu := stall
    			}
    		}
    		is(stall){
    			alu_stall := 1.U
    			when((~writeback_stall).asBool){
    				alu_stall := 0.U
    				io.signals_alu.update := 1.U
    				io.signals_branch2.update := 1.U
    				writeback_instruction := alu_instruction
    				writeback_rd_valid := alu_rd_valid
    				writeback_stage_updated := 1.U
    				when(alu_stage_updated.asBool){
    					fsm_alu := exec
    				}.otherwise{
    					fsm_alu := idle
    					alu_rd_valid := 0.U
    				}
    			}
    		}
    	}
    	
    	val fsm_writeback = RegInit(idle)
    	
		io.signals_writeback.update := 0.U
		io.signals_branch3.update := 0.U
		io.write_address_valid := 0.U
		
		io.load_address_valid := 0.U
		io.load_data_ready := 0.U
		
    	switch(fsm_writeback){
    		is(idle){
    			when(writeback_stage_updated.asBool){
    				fsm_writeback := exec
    			}
    		}
    		is(exec){
    			when(writeback_instruction(6, 0) === opcodes.store){
    				io.write_address_valid := 1.U
    				when(io.write_address_ready.asBool){
    					when(~writeback_stage_updated.asBool){
    						fsm_writeback := idle
    						writeback_rd_valid := 0.U
    					}
    				}.otherwise{
    					fsm_writeback := write_addr_stall
    					writeback_stall := 1.U
    				}
    			}.elsewhen(writeback_instruction(6, 0) === opcodes.load){
    				io.load_address_valid := 1.U
    				writeback_stall := 1.U
    				when(io.load_address_ready.asBool){
    					fsm_writeback := load_data_stall
    				}.otherwise{
    					fsm_writeback := load_addr_stall
    				}
    			}.elsewhen(writeback_instruction(6, 0) === opcodes.register || writeback_instruction(6, 0) === opcodes.immediate || writeback_instruction(6, 0) === opcodes.auipc || writeback_instruction(6, 0) === opcodes.lui){
    				io.signals_writeback.update := 1.U
    				when(~writeback_stage_updated.asBool){
    					fsm_writeback := idle
    					writeback_rd_valid := 0.U
    				}
    			}.elsewhen(writeback_instruction(6, 0) === opcodes.branch || writeback_instruction(6, 0) === opcodes.jal || writeback_instruction(6, 0) === opcodes.jalr){
    				io.signals_writeback.update := Mux(writeback_instruction(6, 0) === opcodes.branch, 0.U, 1.U)
    				io.signals_branch3.update := 1.U
    				branchFinished := 1.U
    				when(~writeback_stage_updated.asBool){
    					fsm_writeback := idle
    					writeback_rd_valid := 0.U
    				}
    			}
    		}
    		is(write_addr_stall){
    			writeback_stall := 1.U
    			io.write_address_valid := 1.U
    			when(io.write_address_ready.asBool){
    				writeback_stall := 0.U
    				when(~writeback_stage_updated.asBool){
    					fsm_writeback := idle
    					writeback_rd_valid := 0.U
    				}.otherwise{
    					fsm_writeback := exec
    				}
    			}
    		}
    		is(load_addr_stall){
    			writeback_stall := 1.U
    			io.load_address_valid := 1.U
    			when(io.load_address_ready.asBool){
    				fsm_writeback := load_data_stall
    			}
    		}
    		is(load_data_stall){
    			writeback_stall := 1.U
    			io.load_data_ready := 1.U
    			when(io.load_data_valid.asBool){
    				writeback_stall := 0.U
    				io.signals_writeback.update := 1.U
    				when(~writeback_stage_updated.asBool){
    					fsm_writeback := idle
    					writeback_rd_valid := 0.U
    				}.otherwise{
    					fsm_writeback := exec
    				}
    			}
    		}
    	}
    	
		
		io.valid_PC := PC
    }
}

object control_unit extends App{
    (new chisel3.stage.ChiselStage).emitVerilog(new control_unit(true))
}
