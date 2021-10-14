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
        val ALUinput1 = Input(SInt(32.W))
        val ALUinput2 = Input(SInt(32.W))
        val ALUoutput = Output(SInt(32.W))
    })
    //Giving default values for outputs so no error happens when compiling
    io.ALUoutput := 0.S
    io.EQUAL := 1.U
    io.LESS_THAN := 0.U

}

object ALU extends App{
    (new chisel3.stage.ChiselStage).emitVerilog(new ALU())
}