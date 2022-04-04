import chisel3._
import chisel3.util._
import chisel3.Driver

// Global constats
object opcodes {
  //opcodes
  val register = "b0110011".U(7.W)	/*register-register instructions*/
  val immediate = "b0010011".U(7.W) 	/*register-immediate instructions*/
  val store = "b0100011".U(7.W)
  val load = "b0000011".U(7.W)
  val branch = "b1100011".U(7.W)		/*conditional branching*/
  val jalr = "b1100111".U(7.W)
  val jal = "b1101111".U(7.W)
  val auipc = "b0010111".U(7.W)
  val lui = "b0110111".U(7.W)
}

object channel_a_opcodes {
  val GET = 4.U(3.W)
  val PUTFULLDATA = 0.U(3.W)
  val PUTPARTIALDATA = 1.U(3.W)
}
