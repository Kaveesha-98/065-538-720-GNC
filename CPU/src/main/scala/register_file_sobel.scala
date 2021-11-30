import chisel3._
import chisel3.util._
import chisel3.Driver

class register_file_sobel() extends Module{
    val io = IO(new Bundle{
    	//Control unit connections
        val RS1 = Input(UInt(5.W))
        val RS2 = Input(UInt(5.W))
        val RD = Input(UInt(5.W))
        val WRITE_EN = Input(UInt(1.W))
        //Datapath connections
        val rs1Data = Output(SInt(32.W))
        val rs2Data = Output(SInt(32.W))
        val rdData = Input(SInt(32.W))
        //for sobel
        val SOBEL_MODE_CHANGE = Input(UInt(1.W))
        val STORE_DATA_IN = Input(UInt(1.W))
    })
    //Initialting the datapath
    val registerFile = Reg(Vec(32, SInt(32.W)))
    
    //sobel_mode
    val sobel_mode = RegInit(0.U(2.W))
    
    when(sobel_mode(1) === 0.U){
    	sobel_mode := Cat(io.SOBEL_MODE_CHANGE, 0.U)
    }otherwise{
    	when(sobel_mode(0) === 0.U){
    		sobel_mode := Cat(1.U, io.SOBEL_MODE_CHANGE)
    	}otherwise{
    		when(io.SOBEL_MODE_CHANGE === 1.U){
    			sobel_mode := 0.U
    		}
    	}
    }
    
    //sobel calculation
    //x12 + x10(noramlizing) or x12 - x10(differentiation)
    val sobel_temp = Mux(sobel_mode(0) === 0.U, registerFile(12.U) - registerFile(10.U),  registerFile(12.U) + registerFile(10.U))
    val sobel_value = sobel_temp + Mux(sobel_mode(0) === 0.U, 0.S, registerFile(11.U))
    //mod in the final stage(averaging)
    val mod_sobel = Mux(sobel_value < 0.S, 0.S - sobel_value, sobel_value)
    //shifted_sobel for preserving sign after differentiating
    
    when(io.WRITE_EN === 0.U & sobel_mode(1) === 1.U){
    	registerFile(16.U) := Mux(sobel_mode(0) === 0.U, Cat(0.U, sobel_value(31, 1).asUInt).asSInt, mod_sobel)
    }
    
    
    //Reading the registers
    when(io.RS1 === 0.U){
    	io.rs1Data := 0.S
    }otherwise{
    	io.rs1Data := registerFile(io.RS1)
    }
    
    when(io.RS2 === 0.U){
    	io.rs2Data := 0.S
    }otherwise{
    	io.rs2Data := registerFile(io.RS2)
    }
    
    //data shifting for sobel calculations
    when(io.WRITE_EN === 0.U & io.STORE_DATA_IN === 1.U & sobel_mode(1) === 1.U){
    	registerFile(12.U) := registerFile(11.U)
    	registerFile(11.U) := registerFile(10.U) 
    }
    
    //Writng to register file
    when(io.WRITE_EN === 1.U){
    	when(io.RD =/= 0.U){
    		registerFile(io.RD) := io.rdData
    	}
    }otherwise{
    	when(io.STORE_DATA_IN === 1.U & sobel_mode(1) === 1.U){
    		registerFile(12.U) := registerFile(11.U)
    		registerFile(11.U) := registerFile(10.U) 
    	}
    }
}

object register_file_sobel extends App{
    (new chisel3.stage.ChiselStage).emitVerilog(new register_file_sobel())
}
