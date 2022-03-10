import chisel3._
import chisel3.iotesters.PeekPokeTester
import org.scalatest._

class Tester_datapath(dut: datapath) extends PeekPokeTester(dut) {

    println("clk cycle: " + 0.toString())
    poke(dut.io.signals_read.rs1, 5.U)
    
    /*
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
    println("")*/
    
}

//object Tester extends App {
//	chisel3.iotesters.Driver(() => new ALU()) { c => 
//	new Tester(c)
//	}
//}

object Tester_datapath extends App {
  iotesters.Driver.execute(Array("--target-dir", "generated", "--generate-vcd-output", "on"), () => new datapath()) {
    c => new Tester_datapath(c)
  }
}

class SimpleSpec extends FlatSpec with Matchers {
  "Tester" should "pass" in {
    iotesters.Driver.execute(Array("--target-dir", "generated", "--generate-vcd-output", "on"), () => new datapath()) { c =>
      new Tester_datapath(c)
    } should be (true)
  }
}
