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
    val read_immediate = Reg(UInt(32.W))
    
    //update when signal is given
    when(io.signals_read.update.asBool){ 
    	//register x0 is hardwired to be zero
    	rs1 := Mux(io.signals_read.rs1.orR, registerFile(io.signals_read.rs1), 0.U(32.W))
    	rs2 := Mux(io.signals_read.rs1.orR, registerFile(io.signals_read.rs2), 0.U(32.W))
    	read_immediate := io.signals_read.immediate
    }
    
    
    
    io.next_PC := 0.U
    
    io.store_data := 0.U
    io.mem_address := 0.U
}

object datapath extends App{
    (new chisel3.stage.ChiselStage).emitVerilog(new datapath())
}
