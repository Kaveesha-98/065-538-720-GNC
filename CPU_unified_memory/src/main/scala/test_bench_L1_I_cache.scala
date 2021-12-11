import chisel3._
import chisel3.util._
import chisel3.Driver


class test_bench_L1_I_cache extends Module {
    val io = IO(new Bundle{
    	//Connections with the CPU core
    	val instruction = Output(UInt(32.W))
    	val instruction_address = Input(UInt(32.W))
    	val instruction_loaded = Output(UInt(1.W))
    	//Connections with I-cache fetch unit-fetching
    	val cache_line_address = Output(UInt(32.W))
    	val cache_line_absent = Output(UInt(1.W))
		//Connections with I-cache fetch unit-wirting to cache
		val set_new_tag = Input(UInt(1.W))
		val write_new_cache = Input(UInt(1.W))
		val new_cache_line_word = Input(UInt(32.W))
    })
    
    val L1ICache = Module(new L1_I_cache())
    
    val new_cache_line = RegInit(0.U(1024.W))
    
    new_cache_line := Cat(new_cache_line(991, 0), io.new_cache_line_word)
    
    io.instruction := L1ICache.io.instruction
    L1ICache.io.instruction_address := io.instruction_address
    io.instruction_loaded := L1ICache.io.instruction_loaded
    
    io.cache_line_address := L1ICache.io.cache_line_address
    io.cache_line_absent := L1ICache.io.cache_line_absent
    
    L1ICache.io.set_new_tag := io.set_new_tag
    L1ICache.io.write_new_cache := io.write_new_cache
    L1ICache.io.new_cache_line := new_cache_line
}

object test_bench_L1_I_cache extends App{
    (new chisel3.stage.ChiselStage).emitVerilog(new test_bench_L1_I_cache())
}
