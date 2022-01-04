import chisel3._
import chisel3.util._
import chisel3.Driver

class L1_I_cache_entry() extends Bundle{
	val valid = UInt(1.W)
	val tag = UInt(20.W)
	val cache_line = UInt(1024.W)
}

class L1_I_cache extends Module {
    val io = IO(new Bundle{
    	//Connections with the CPU core
    	val instruction = Output(UInt(32.W))
    	val instruction_address = Input(UInt(32.W))
    	val instruction_loaded = Output(UInt(1.W))
		
		//cache io connections
    	val cache_line_loaded = Input(UInt(1.W))
    	val fetched_cache_line = Input(UInt(1024.W))
    	val fetch_cache_line_address = Output(UInt(32.W))
    })
    
    
    val L1ICacheWrite = Module(new L1_I_cache_write())
    L1ICacheWrite.io.cache_line_address := Cat(io.instruction_address(31, 7), 0.U(7.W))
    L1ICacheWrite.io.cache_line_loaded := io.cache_line_loaded
   	L1ICacheWrite.io.fetched_cache_line := io.fetched_cache_line
    io.fetch_cache_line_address := L1ICacheWrite.io.fetch_cache_line_address
    	
    	
    val tag = io.instruction_address(31, 12)
    val cache_line_index = io.instruction_address(11, 7)
    val word_offset = io.instruction_address(6, 2)
    
    val initial_cache_entry = Wire(new L1_I_cache_entry())
    
    initial_cache_entry.valid := 0.U
    initial_cache_entry.tag := 0.U
    initial_cache_entry.cache_line := 0.U
    
    val cache_entries = RegInit(VecInit(Seq.fill(32)(initial_cache_entry)))
    
    val cache_line = cache_entries(cache_line_index).cache_line
    
    val cache_line_instructions = Wire(Vec (32, UInt (32.W)))
    
    for (i <- 0 to 31) {
		cache_line_instructions(i) := cache_line(32*(i+1) - 1, i*32)
	}
	
	
    io.instruction := cache_line_instructions(word_offset)
    val tag_match = Mux(cache_entries(cache_line_index).tag === tag, 1.U, 0.U)
    val instruction_loaded = cache_entries(cache_line_index).valid & tag_match
    io.instruction_loaded := instruction_loaded
    
    L1ICacheWrite.io.cache_line_absent := ~instruction_loaded
    
    when(L1ICacheWrite.io.write_new_cache === 1.U){
    	cache_entries(cache_line_index).cache_line := L1ICacheWrite.io.new_cache_line
    }
    
    when(L1ICacheWrite.io.set_new_tag === 1.U){
    	cache_entries(cache_line_index).tag := tag
    	cache_entries(cache_line_index).valid := 1.U
    }
}

object L1_I_cache extends App{
    (new chisel3.stage.ChiselStage).emitVerilog(new L1_I_cache())
}
