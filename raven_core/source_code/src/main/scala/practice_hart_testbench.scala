import chisel3._
import chisel3.util._
import chisel3.Driver


class practice_hart_testbench extends Module {
    val io = IO(new Bundle{
    	val start = Input(UInt(1.W))
    	val rgb = Output(UInt(2.W))
    })
    
    val pracHart = Module(new practice_hart())
    val idle :: working :: Nil = Enum(2)
    val stateReg = RegInit(idle)
    
    //write_address channel signals
    //val write_address_valid = Output(UInt(1.W))
    pracHart.io.write_address_ready := 1.U
    //val write_address = Output(UInt(32.W))
        
        //write_data channel signals
    pracHart.io.write_data_ready := 1.U
        
        //load_address channel signals
    pracHart.io.load_address_ready := 1.U
        
        //load_data channel signals
    pracHart.io.load_data_valid := 1.U
    pracHart.io.load_data := 1.U
        
    pracHart.io.fetch_PC := 0.U
    pracHart.io.fetch_valid := io.start
    pracHart.io.instruction := "b0000000_00000_00000_000_00001_0100011".U
    
    io.rgb := 1.U
    
    switch(stateReg){
    	is(idle){
    		when(pracHart.io.write_address_valid.asBool){
    			stateReg := working
    		}
    	}
    	is(working){
    		io.rgb := 2.U
    	}
    }
}

object practice_hart_testbench extends App{
    (new chisel3.stage.ChiselStage).emitVerilog(new practice_hart_testbench())
}
