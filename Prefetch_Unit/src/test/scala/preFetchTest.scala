import chisel3._
import chisel3.iotesters.PeekPokeTester
import org.scalatest._

class Tester(dut: Prefetch ) extends PeekPokeTester(dut) {
    poke(dut.io.pc,2.U)
    poke(dut.io.BRANCH,0.U)
    poke(dut.io.instr_in,2.U)
    step(1)
    println("clk cycle: " + 1.toString)
    println("Instruction: " + peek(dut.io.instr_out).toString)
    println("Address: " + peek(dut.io.addr_out).toString)
    println("Valid: " + peek(dut.io.VALID).toString)
    println("")

    step(1)
    println("clk cycle: " + 1.toString)
    println("Instruction: " + peek(dut.io.instr_out).toString)
    println("Address: " + peek(dut.io.addr_out).toString)
    println("Valid: " + peek(dut.io.VALID).toString)
    println("")

    step(1)
    println("clk cycle: " + 1.toString)
    println("Instruction: " + peek(dut.io.instr_out).toString)
    println("Address: " + peek(dut.io.addr_out).toString)
    println("Valid: " + peek(dut.io.VALID).toString)
    println("")

    step(1)
    println("clk cycle: " + 1.toString)
    println("Instruction: " + peek(dut.io.instr_out).toString)
    println("Address: " + peek(dut.io.addr_out).toString)
    println("Valid: " + peek(dut.io.VALID).toString)
    println("")
    
}

object Tester extends App {
	chisel3.iotesters.Driver(() => new Prefetch()) { c => 
	new Tester(c)
	}
}

class SimpleSpec extends FlatSpec with Matchers {
  "Tester" should "pass" in {
    chisel3.iotesters.Driver (() => new Prefetch()) { c =>
      new Tester(c)
    } should be (true)
  }
}