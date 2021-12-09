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
    	//Connections with I-cache fetch unit-fetching
    	val cache_line_address = Output(UInt(32.W))
    	val cache_line_absent = Output(UInt(32.W))
		//Connections with I-cache fetch unit-wirting to cache
		val set_new_tag = Input(UInt(1.W))
		val write_new_cache = Input(UInt(1.W))
		val new_cache_line = Input(UInt(1024.W))//cache line of 32 words(instructions)
    })
    
    io.cache_line_address := Cat(io.instruction_address(31, 7), "b0000000".U)
    
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
    val tag_match = Mux(cache_entries(cache_line_index).cache_line === tag, 1.U, 0.U)
    val instruction_loaded = cache_entries(cache_line_index).valid & tag_match
    io.instruction_loaded := instruction_loaded
    
    io.cache_line_absent := ~instruction_loaded
    
    when(io.write_new_cache === 1.U){
    	cache_entries(cache_line_index).cache_line := io.new_cache_line
    }
    
    when(io.set_new_tag === 1.U){
    	cache_entries(cache_line_index).tag := tag
    	cache_entries(cache_line_index).valid := 1.U
    }
    
    
}

object L1_I_cache extends App{
    (new chisel3.stage.ChiselStage).emitVerilog(new L1_I_cache())
}
