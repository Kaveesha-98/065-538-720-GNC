import chisel3._
import chisel3.iotesters.PeekPokeTester
import org.scalatest._

class Tester(dut: ALU) extends PeekPokeTester(dut) {

    println("clk cycle: " + 0.toString())
    println("Output: " + peek(dut.io.ALUoutput).toString)
    println("Equal: " + peek(dut.io.EQUAL).toString)
    println("Less than signed: " + peek(dut.io.SIGNED_LESS_THAN).toString)
    println("Less than unsigned: " + peek(dut.io.LESS_THAN).toString)
    println("")

    step(1)
    poke(dut.io.ALU_OP,0.U)
    poke(dut.io.ALUinput1,-5.S)
    poke(dut.io.ALUinput2,10.S)
    println("clk cycle: " + 1.toString())
    println("Output: " + peek(dut.io.ALUoutput).toString)
    println("Equal: " + peek(dut.io.EQUAL).toString)
    println("Less than signed: " + peek(dut.io.SIGNED_LESS_THAN).toString)
    println("Less than unsigned: " + peek(dut.io.LESS_THAN).toString)
    println("")
    
}

//object Tester extends App {
//	chisel3.iotesters.Driver(() => new ALU()) { c => 
//	new Tester(c)
//	}
//}

object Tester extends App {
  iotesters.Driver.execute(Array("--target-dir", "generated", "--generate-vcd-output", "on"), () => new ALU()) {
    c => new Tester(c)
  }
}

class SimpleSpec extends FlatSpec with Matchers {
  "Tester" should "pass" in {
    chisel3.iotesters.Driver (() => new ALU()) { c =>
      new Tester(c)
    } should be (true)
  }
}