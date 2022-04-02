import chisel3._
import chisel3.util._
import chisel3.Driver


class raven_core_hart extends Module {
    val io = IO(new Bundle{
    	//write_address channel signals
        val write_address_valid = Output(UInt(1.W))
        val write_address_ready = Input(UInt(1.W))
        val write_address_size = Output(UInt(2.W))
        val write_address = Output(UInt(32.W))
        
        //write_data channel signals
        val write_data_valid = Output(UInt(1.W))
        val write_data_ready = Input(UInt(1.W))
        val store_data = Output(UInt(32.W))
        
        //load_address channel signals
        val load_address_ready = Input(UInt(1.W))
        val load_address_valid = Output(UInt(1.W))
        val load_address_size = Output(UInt(2.W))
        val load_address = Output(UInt(32.W))
        
        //load_data channel signals
        val load_data_valid = Input(UInt(1.W))
        val load_data_ready = Output(UInt(1.W))
        val load_data = Input(UInt(32.W))
        
		val cache_address_channel = new instruction_read_address_channel()
		val cache_data_channel = new instruction_read_data_channel()
    })
    
    val dataPath = Module(new datapath())
    
    io.write_address := dataPath.io.mem_address
    io.load_address := dataPath.io.mem_address
    io.store_data := dataPath.io.store_data
    
    val controlUnit = Module(new control_unit(true))
    
    io.write_address_valid := controlUnit.io.write_address_valid
    controlUnit.io.write_address_ready := io.write_address_ready
    io.write_address_size := controlUnit.io.write_address_size
    
    io.write_data_valid := controlUnit.io.write_data_valid
    controlUnit.io.write_data_ready := io.write_data_ready
    
    controlUnit.io.load_address_ready := io.load_address_ready
    io.load_address_valid := controlUnit.io.load_address_valid
    io.load_address_size := controlUnit.io.load_address_size
    
    val load_data_valid = Reg(UInt(1.W))
    val load_data_ready = Reg(UInt(1.W))
    load_data_valid := io.load_data_valid
    load_data_ready := controlUnit.io.load_data_ready
    
    controlUnit.io.load_data_valid := load_data_valid
    io.load_data_ready := load_data_ready
    
    val load_data = Reg(UInt(32.W))
    
    when(controlUnit.io.load_data_ready.asBool){
    	load_data := io.load_data
    	switch(Cat(controlUnit.io.load_extend_type, controlUnit.io.load_address_size)){
    		is(0.U){ load_data := Cat(Fill(24, io.load_data(7)), io.load_data(7, 0)) }
    		is(1.U){ load_data := Cat(Fill(16, io.load_data(15)), io.load_data(7, 0)) }
    		is(4.U){ load_data := Cat(0.U(24.W), io.load_data(7, 0)) }
    		is(5.U){ load_data := Cat(0.U(16.W), io.load_data(7, 0)) }
    	}
    }
    
    dataPath.io.load_data := load_data
    
    dataPath.io.signals_read <> controlUnit.io.signals_read
    dataPath.io.signals_alu <> controlUnit.io.signals_alu
    dataPath.io.signals_writeback <> controlUnit.io.signals_writeback
    dataPath.io.signals_branch1 <> controlUnit.io.signals_branch1
    dataPath.io.signals_branch2 <> controlUnit.io.signals_branch2
    dataPath.io.signals_branch3 <> controlUnit.io.signals_branch3
    
    controlUnit.io.next_PC := dataPath.io.next_PC
    
    val fetchUnit = Module(new instruction_fetch_unit(1))
    
    controlUnit.io.fetch_PC := fetchUnit.io.control_unit_channel.address
    fetchUnit.io.valid_PC := controlUnit.io.valid_PC
    controlUnit.io.fetch_valid := fetchUnit.io.control_unit_channel.valid
    fetchUnit.io.control_unit_channel.ready := controlUnit.io.ready
    fetchUnit.io.PC_invalid := controlUnit.io.fetch_PC_invalid
    controlUnit.io.instruction := fetchUnit.io.control_unit_channel.instruction
    
    io.cache_address_channel <> fetchUnit.io.cache_address_channel
	io.cache_data_channel <> fetchUnit.io.cache_data_channel
}

object raven_core_hart extends App{
    (new chisel3.stage.ChiselStage).emitVerilog(new raven_core_hart())
}
