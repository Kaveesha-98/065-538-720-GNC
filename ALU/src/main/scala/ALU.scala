import chisel3._
import chisel3.util._
import chisel3.Driver

// Global constats
object constants {
  //ALU Operations
  val add = 0.U(3.W)
  val sub = 1.U(3.W)
  val sll = 2.U(3.W)
  val sra = 3.U(3.W)
  val srl = 4.U(3.W)
  val xor = 5.U(3.W)
  val or  = 6.U(3.W)
  val and = 7.U(3.W)
}

class ALU extends Module {
    val io = IO(new Bundle{
    	//Control unit connections
        val ALU_OP = Input(UInt(3.W)) //ALUOperations{add, sub, sll, sra, srl, xor, or, and}
        val EQUAL = Output(UInt(1.W)) //When two registers are equal
        val LESS_THAN = Output(UInt(1.W)) // When input1 is less than input 2 
        //Datapath connections
        val ALUinput1 = Input(SInt(19.W))
        val ALUinput2 = Input(SInt(19.W))
        val ALUoutput = Output(SInt(32.W))
    })
    //Set variables to IO
    val ALU_OP = io.ALU_OP
    val ALUinput1 = io.ALUinput1
    val ALUinput2 = io.ALUinput2
    val ALUoutput = WireInit(0.S(32.W))
    val EQUAL = WireInit(1.U(1.W))
    val LESS_THAN = WireInit(0.U(1.W))

    // ALU operations
    switch(ALU_OP){
        // Addition
        is(constants.add){
            ALUoutput := ALUinput1 + ALUinput2          
            when((ALUinput1 + ALUinput2) === 0.S) {EQUAL := 1.U}      // Check equality to zero
            .otherwise {EQUAL := 0.U}
            when((ALUinput1 + ALUinput2) < 0.S) {LESS_THAN := 1.U}    // Check negativity
            .otherwise {LESS_THAN := 0.U}
        }
        // Subtraction
        is(constants.sub){
            ALUoutput := ALUinput1 - ALUinput2                      
            when((ALUinput1 - ALUinput2) === 0.S) {EQUAL := 1.U}      // Check equality to zero
            .otherwise {EQUAL := 0.U}
            when((ALUinput1 - ALUinput2) < 0.S) {LESS_THAN := 1.U}    // Check negativity
            .otherwise {LESS_THAN := 0.U}
        }
        // Left shift
        is(constants.sll){
            ALUoutput := (ALUinput1.asUInt << ALUinput2.asUInt).asSInt          
            when((ALUinput1.asUInt << ALUinput2.asUInt).asSInt === 0.S) {EQUAL := 1.U}      // Check equality to zero
            .otherwise {EQUAL := 0.U}
            when((ALUinput1.asUInt << ALUinput2.asUInt).asSInt < 0.S) {LESS_THAN := 1.U}    // Check negativity
            .otherwise {LESS_THAN := 0.U}
        }
        // Arithmatic right shift
        is(constants.sra){
            ALUoutput := (ALUinput1.asUInt >> ALUinput2.asUInt).asSInt          
            when((ALUinput1.asUInt >> ALUinput2.asUInt).asSInt === 0.S) {EQUAL := 1.U}      // Check equality to zero
            .otherwise {EQUAL := 0.U}
            when((ALUinput1.asUInt >> ALUinput2.asUInt).asSInt < 0.S) {LESS_THAN := 1.U}    // Check negativity
            .otherwise {LESS_THAN := 0.U}
        }
        // XOR
        is(constants.xor){
            ALUoutput := ALUinput1 ^ ALUinput2                      
            when((ALUinput1 ^ ALUinput2) === 0.S) {EQUAL := 1.U}      // Check equality to zero
            .otherwise {EQUAL := 0.U}
            when((ALUinput1 ^ ALUinput2) < 0.S) {LESS_THAN := 1.U}    // Check negativity
            .otherwise {LESS_THAN := 0.U}
        }
        // OR
        is(constants.or){
            ALUoutput := ALUinput1 | ALUinput2                      
            when((ALUinput1 | ALUinput2) === 0.S) {EQUAL := 1.U}      // Check equality to zero
            .otherwise {EQUAL := 0.U}
            when((ALUinput1 | ALUinput2) < 0.S) {LESS_THAN := 1.U}    // Check negativity
            .otherwise {LESS_THAN := 0.U}
        }
        // AND
        is(constants.and){
            ALUoutput := ALUinput1 & ALUinput2                      
            when((ALUinput1 & ALUinput2) === 0.S) {EQUAL := 1.U}      // Check equality to zero
            .otherwise {EQUAL := 0.U}
            when((ALUinput1 & ALUinput2) < 0.S) {LESS_THAN := 1.U}    // Check negativity
            .otherwise {LESS_THAN := 0.U}
        }
   
    
    }

    // Assign outputs to relevant variables
    io.ALUoutput := ALUoutput
    io.EQUAL := EQUAL
    io.LESS_THAN := LESS_THAN
}

object ALU extends App{
    (new chisel3.stage.ChiselStage).emitVerilog(new ALU())
}