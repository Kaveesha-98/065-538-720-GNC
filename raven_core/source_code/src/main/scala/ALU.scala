import chisel3._
import chisel3.util._
import chisel3.Driver

// Global constats
object constants {
  //ALU Operations
  val add  = "b0000".U(4.W)
  val sub  = "b1000".U(4.W)
  val sll  = "b0001".U(4.W)
  val slt  = "b0010".U(4.W)
  val sltu = "b0011".U(4.W)
  val xor  = "b0100".U(4.W)
  val srl  = "b0101".U(4.W)
  val sra  = "b1101".U(4.W)
  val or   = "b0110".U(4.W)
  val and  = "b0111".U(4.W)
}

class ALU extends Module {
    val io = IO(new Bundle{
    	//Control unit connections
        val ALU_OP           = Input(UInt(4.W))     //ALUOperations{add, sub, sll, slt, sltu, xor, srl, sra, or, and}
        val EQUAL            = Output(UInt(1.W))    //When two registers are equal
        val LESS_THAN        = Output(UInt(1.W))    // When input1 is less than input 2 unsigned
        val SIGNED_LESS_THAN = Output(UInt(1.W))    // When iput1 is less than input 2 signed
        //Datapath connections
        val ALUinput1 = Input(UInt(32.W))
        val ALUinput2 = Input(UInt(32.W))
        val ALUoutput = Output(UInt(32.W))
    })
    //Set variables to IO
    val ALU_OP           = io.ALU_OP
    val ALUinput1        = io.ALUinput1
    val ALUinput2        = io.ALUinput2
    val ALUoutput        = Wire(UInt(32.W))
    val EQUAL            = Wire(UInt(1.W))
    val LESS_THAN        = Wire(UInt(1.W))
    val SIGNED_LESS_THAN = Wire(UInt(1.W))
    
    ALUoutput := 0.U

    // ALU operations
    switch(ALU_OP){
        is(constants.add){ ALUoutput := ALUinput1 + ALUinput2 }                                 // Addition       
        is(constants.sub){ ALUoutput := ALUinput1 - ALUinput2 }                                 // Subtraction
        is(constants.sll){ ALUoutput := ALUinput1 << ALUinput2(4,0) }                    // Left shift
        is(constants.srl){ ALUoutput := (ALUinput1 >> ALUinput2(4,0)) }    // Logical right shift
        is(constants.sra){ ALUoutput := (ALUinput1.asSInt >> ALUinput2(4,0)).asUInt }                    // Arithmatic right shift
        is(constants.xor){ ALUoutput := ALUinput1 ^ ALUinput2 }                                 // XOR
        is(constants.or ){ ALUoutput := ALUinput1 | ALUinput2 }                                 // OR
        is(constants.and){ ALUoutput := ALUinput1 & ALUinput2 }                                 // AND
    }

    when(ALUinput1 === ALUinput2) {EQUAL := 1.U}                    // Check equality
    .otherwise {EQUAL := 0.U}
    
    when(ALUinput1 < ALUinput2) {                                   // Check less than signed
        SIGNED_LESS_THAN := 1.U
        when(ALU_OP === constants.slt) {ALUoutput := 1.U}           // slt
        }           
    .otherwise {SIGNED_LESS_THAN := 0.U}
    
    when(ALUinput1.asUInt < ALUinput2.asUInt) {                     // Check less than unsigned
        LESS_THAN := 1.U
        when(ALU_OP === constants.sltu) {ALUoutput := 1.U}          // sltu
        }    
    .otherwise {LESS_THAN := 0.U}

    // Assign outputs to relevant variables
    io.ALUoutput        := ALUoutput
    io.EQUAL            := EQUAL
    io.LESS_THAN        := LESS_THAN
    io.SIGNED_LESS_THAN := SIGNED_LESS_THAN
}

object ALU extends App{
    (new chisel3.stage.ChiselStage).emitVerilog(new ALU())
}
