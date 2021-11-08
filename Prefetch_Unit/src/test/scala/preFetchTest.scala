import chisel3._
import chisel3.iotesters.PeekPokeTester
import org.scalatest._

class Tester(dut: Prefetch ) extends PeekPokeTester(dut) {

    var i = 0
    for (i <- 0 to 10){
      poke(dut.io.pc,5.U)
      poke(dut.io.BRANCH,0.U)
      poke(dut.io.instr_in,i.U)
      step(1)
      println("clk cycle: " + (i+1).toString)
      println("Instruction: " + peek(dut.io.instr_out).toString)
      println("Address: " + peek(dut.io.addr_out).toString)
      println("Valid: " + peek(dut.io.VALID).toString)
      println("")
    }

    poke(dut.io.pc,25.U)
    poke(dut.io.BRANCH,1.U)
    poke(dut.io.instr_in,11.U)
    step(1)
    println("clk cycle: " + 11.toString)
    println("Instruction: " + peek(dut.io.instr_out).toString)
    println("Address: " + peek(dut.io.addr_out).toString)
    println("Valid: " + peek(dut.io.VALID).toString)
    println("")

    for (i <- 25 to 35){
      poke(dut.io.pc,30.U)
      poke(dut.io.BRANCH,0.U)
      poke(dut.io.instr_in,i.U)
      step(1)
      println("clk cycle: " + (i-13).toString)
      println("Instruction: " + peek(dut.io.instr_out).toString)
      println("Address: " + peek(dut.io.addr_out).toString)
      println("Valid: " + peek(dut.io.VALID).toString)
      println("")
    }
    
}

object Tester extends App {
  iotesters.Driver.execute(Array("--target-dir", "generated", "--generate-vcd-output", "on"), () => new Prefetch()) {
    c => new Tester(c)
  }
}

class SimpleSpec extends FlatSpec with Matchers {
  "Tester" should "pass" in {
    chisel3.iotesters.Driver (() => new Prefetch()) { c =>
      new Tester(c)
    } should be (true)
  }
}