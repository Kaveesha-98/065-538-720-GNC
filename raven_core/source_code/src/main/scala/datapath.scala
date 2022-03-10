import chisel3._
import chisel3.util._
import chisel3.Driver

class datapath extends Module {
    val io = IO(new Bundle{
        val signals_read = Input(new datapath_read())
        val signals_alu = Input(new datapath_alu())
        val signals_writeback = Input(new datapath_writeback())
        val signals_branch1 = Input(new datapath_branch_stage1())
        val signals_branch2 = Input(new datapath_branch_stage2())
        val signals_branch3 = Input(new datapath_branch_stage3())

        val next_PC = Output(UInt(32.W))
        
        val store_data = Output(UInt(32.W))
        val mem_address = Output(UInt(32.W))
        val load_data = Input(UInt(32.W))
    })
    
    //----------read stage------------------------------------------------------
    val registerFile = Reg(Vec (32, UInt (32.W)))
    val rs1 = Reg(UInt(32.W))
    val rs2 = Reg(UInt(32.W))
    val PC = Reg(UInt(32.W))
    val read_immediate = Reg(UInt(32.W))
    
    //update when signal is given
    when(io.signals_read.update.asBool){ 
    	//register x0 is hardwired to be zero
    	rs1 := Mux(io.signals_read.rs1.orR, registerFile(io.signals_read.rs1), 0.U(32.W))
    	rs2 := Mux(io.signals_read.rs1.orR, registerFile(io.signals_read.rs2), 0.U(32.W))
    	read_immediate := io.signals_read.immediate
    	PC := io.signals_read.PC
    }
    
    //----------alu stage--------------------------------------------------------
    val alu = Module(new ALU())
    val alu_result = Reg(UInt(32.W))
    val compare_results = Reg(UInt(3.W))
    
    //for auipc instruction PC is choosen as input
    alu.io.ALUinput1 := Mux(io.signals_alu.choose_pc.asBool, PC, rs1)
    //for instructions(excludes branches) with an immediate
    alu.io.ALUinput2 := Mux(io.signals_alu.choose_immediate.asBool, read_immediate, rs2)
    alu.io.ALU_OP := io.signals_alu.alu_op
    
    //val T_compare_results = Cat(alu.EQUAL, alu.LESS_THAN, alu.SIGNED_LESS_THAN)
    
    when(io.signals_alu.update.asBool){
    	alu_result := alu.io.ALUoutput
    	compare_results := Cat(alu.io.EQUAL, alu.io.LESS_THAN, alu.io.SIGNED_LESS_THAN)
    }
    
    //----------writeback stage---------------------------------------------------
    val writeback_data = Wire(UInt(32.W))
    val link_address = Reg(UInt(32.W))
    
    writeback_data := alu_result
    
    switch(io.signals_writeback.choose_data){
    	is(1.U){writeback_data := io.load_data} /*for memory load instructions*/
    	is(2.U){writeback_data := link_address} /*for jump and link instructions(saving return address)*/
    }
    
    when(io.signals_writeback.update.asBool){
    	registerFile(io.signals_writeback.rd) := writeback_data
    }
    
    //----------branch stage1-----------------------------------------------------
    val jump_immediate = Reg(UInt(32.W))
    
    when(io.signals_branch1.update.asBool){
    	jump_immediate := io.signals_branch1.immediate
    }
    
    //----------branch stage2----------------------------------------------------
    val branch_op = Reg(UInt(5.W))
    val branch_address = Reg(UInt(32.W))
    
    when(io.signals_branch2.update.asBool){
    	branch_op := io.signals_branch2.branch_op
    	branch_address := PC + jump_immediate
    	link_address := PC + 4.U
    }
    
    //----------branch stage3----------------------------------------------------
    val next_PC = Reg(UInt(32.W))
    
    val compare_result = Wire(UInt(1.W))
    val branch_condition = ~branch_op(2)
    
    compare_result := 0.U
    
    switch(branch_op(4, 3)){
    	is(0.U){ compare_result := compare_results(2) } /*beq and bne instructions*/
    	is(2.U){ compare_result := compare_results(0) } /*blt and bge instructions*/
    	is(3.U){ compare_result := compare_results(1) } /*bltu and bgeu instruction*/
    }
    
    val branch_result = Mux(compare_result === branch_condition, branch_address, link_address)
    
    when(io.signals_branch3.update.asBool){
    	switch(branch_op(1, 0)){
    		is(3.U){ next_PC := branch_address } /*jal instruction*/
    		is(1.U){ next_PC := alu_result } /*jalr instruction*/
    		is(0.U){ next_PC := branch_result } /*conditional branches*/
    		is(2.U){ next_PC := link_address } /*every other instruction*/
    	}
    }
    
    io.next_PC := next_PC
    
    //--------------memory----------------------------------
    io.store_data := rs2
    io.mem_address := alu_result
}

object datapath extends App{
    (new chisel3.stage.ChiselStage).emitVerilog(new datapath())
}
