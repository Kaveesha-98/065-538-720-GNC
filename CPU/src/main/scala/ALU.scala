//Dummy ALU to replaced with the real one later

import chisel3._
import chisel3.util._
import chisel3.Driver

class ALU() extends Module{
    val io = IO(new Bundle{
    	//Control unit connections
        val ALU_OP = Input(UInt(3.W)) //ALUOperations{add, sub, sll, sra, srl, xor, or, and}
        val EQUAL = Output(UInt(1.W)) //When two registers are equal
        val LESS_THAN = Output(UInt(1.W)) // When input1 is less than input 2 
        val SIGNED_LESS_THAN = Output(UInt(1.W))
        //Datapath connections
        val ALUinput1 = Input(SInt(32.W))
        val ALUinput2 = Input(SInt(32.W))
        val ALUoutput = Output(SInt(32.W))
    })
    //Giving default values for outputs so no error happens when compiling
    io.ALUoutput := 0.S
    io.EQUAL := 1.U
    io.LESS_THAN := 0.U
    io.SIGNED_LESS_THAN := 0.U
}

object ALU extends App{
    (new chisel3.stage.ChiselStage).emitVerilog(new ALU())
}
