import chisel3._
import chisel3.iotesters.PeekPokeTester
import org.scalatest._

class Tester(dut: ALU) extends PeekPokeTester(dut) {

    println("clk cycle: " + 0.toString())
    println("Output: " + peek(dut.io.ALUoutput).toString)
    println("Zero flag: " + peek(dut.io.EQUAL).toString)
    println("Negative flag: " + peek(dut.io.LESS_THAN).toString)
    println("")

    step(1)
    poke(dut.io.ALU_OP,2.U)
    poke(dut.io.ALUinput1,10.S)
    poke(dut.io.ALUinput2,2.S)
    println("clk cycle: " + 1.toString())
    println("Output: " + peek(dut.io.ALUoutput).toString)
    println("Zero flag: " + peek(dut.io.EQUAL).toString)
    println("Negative flag: " + peek(dut.io.LESS_THAN).toString)
    println("")
    
}

object Tester extends App {
	chisel3.iotesters.Driver(() => new ALU()) { c => 
	new Tester(c)
	}
}

class SimpleSpec extends FlatSpec with Matchers {
  "Tester" should "pass" in {
    chisel3.iotesters.Driver (() => new ALU()) { c =>
      new Tester(c)
    } should be (true)
  }
}