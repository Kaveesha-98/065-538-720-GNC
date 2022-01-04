import chisel3._
import chisel3.util._
import chisel3.Driver

class L1_I_cache_write extends Module {
    val io = IO(new Bundle{
    	//internal cache connections
    	val fetch_cache_line = Output(UInt(1.W))
    	val write_new_cache = Output(UInt(1.W))
    	val set_new_tag = Output(UInt(1.W))
    	val cache_line_absent = Input(UInt(1.W))
    	val cache_line_address = Input(UInt(32.W))
    	val new_cache_line = Output(UInt(1024.W))
    	//cache io connections
    	val cache_line_loaded = Input(UInt(1.W))
    	val fetched_cache_line = Input(UInt(1024.W))
    	val fetch_cache_line_address = Output(UInt(32.W))
    })
    
    val cache_line_address = RegInit(0.U(32.W))
    val cache_line = RegInit(0.U(1024.W))
    
    io.fetch_cache_line := 0.U
    io.write_new_cache := 0.U
    io.set_new_tag := 0.U
    io.new_cache_line := cache_line
    io.fetch_cache_line_address := cache_line_address
    
    
    val waiting :: req_cache :: wrt_cache :: set_tag :: Nil = Enum(4)
    val state_reg = RegInit(waiting)
    
    switch(state_reg){
    	is(waiting){
    		when(io.cache_line_absent === 1.U){
    			state_reg := req_cache
    			cache_line_address := io.cache_line_address
    		}
    	}
    	is(req_cache){
    		io.fetch_cache_line === 1.U
    		when(io.cache_line_loaded === 1.U){
    			state_reg := wrt_cache
    			cache_line := io.fetched_cache_line
    		}
    	}
    	is(wrt_cache){
    		io.write_new_cache := 1.U
    		state_reg := set_tag
    	}
    	is(set_tag){
    		io.set_new_tag := 1.U
    		state_reg := waiting
    	}
    }
    
    
}

object L1_I_cache_write extends App{
    (new chisel3.stage.ChiselStage).emitVerilog(new L1_I_cache_write())
}
