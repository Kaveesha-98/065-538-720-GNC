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
        
		/* 
        //Used for when fetch buffer not present
        
        val fetch_PC = Input(UInt(32.W))
        val valid_PC = Output(UInt(32.W))
        val fetch_valid = Input(UInt(1.W))
        val ready = Output(UInt(1.W))
        val fetch_PC_invalid = Output(UInt(1.W))
        val instruction = Input(UInt(32.W)) 
        
        */

        val instructionFetchChannel = new instruction_read_data_channel()
        val instructionAddressIssueChannel = new instruction_read_address_channel()
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
    
    controlUnit.io.load_data_valid := io.load_data_valid
    io.load_data_ready := controlUnit.io.load_data_ready
    
    val load_data = Reg(UInt(32.W))
    
    when(controlUnit.io.load_data_ready.asBool){
        //to change how io.load_data is interpretted(for different load types) change here
    	load_data := io.load_data//lw
    	switch(Cat(controlUnit.io.load_extend_type, controlUnit.io.load_address_size)){
    		is(0.U){ load_data := Cat(Fill(24, io.load_data(7)), io.load_data(7, 0)) }//lb
    		is(1.U){ load_data := Cat(Fill(16, io.load_data(15)), io.load_data(7, 0)) }//lh
    		is(4.U){ load_data := Cat(0.U(24.W), io.load_data(7, 0)) }//lbu
    		is(5.U){ load_data := Cat(0.U(16.W), io.load_data(7, 0)) }//lhu
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


    /* 
    //Used for connecting when fetch buffer not present

    controlUnit.io.fetch_PC := io.fetch_PC
    io.valid_PC := controlUnit.io.valid_PC
    controlUnit.io.fetch_valid := io.fetch_valid
    io.ready := controlUnit.io.ready
    io.fetch_PC_invalid := controlUnit.io.fetch_PC_invalid
    controlUnit.io.instruction := io.instruction 
    
    */

    val instructionFetchUnit = Module(new instruction_fetch_unit(2))

    controlUnit.io.fetch_PC := instructionFetchUnit.io.control_unit_channel.address
    controlUnit.io.fetch_valid := instructionFetchUnit.io.control_unit_channel.valid.asUInt
    instructionFetchUnit.io.control_unit_channel.ready := controlUnit.io.ready
    controlUnit.io.instruction := instructionFetchUnit.io.control_unit_channel.instruction

    instructionFetchUnit.io.valid_PC := controlUnit.io.valid_PC
    instructionFetchUnit.io.PC_invalid := controlUnit.io.fetch_PC_invalid.asBool

    //connecting with io of top module - names of io of instructionFetch Unit need to be changed in the future 1/6/2022
    io.instructionFetchChannel <> instructionFetchUnit.io.cache_data_channel
    io.instructionAddressIssueChannel <> instructionFetchUnit.io.cache_address_channel

}

object raven_core_hart extends App{
    (new chisel3.stage.ChiselStage).emitVerilog(new raven_core_hart())
}
