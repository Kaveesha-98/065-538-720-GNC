import chisel3._
import chisel3.iotesters.PeekPokeTester
import org.scalatest._

class Tester_datapath(dut: datapath) extends PeekPokeTester(dut) {

    println("clk cycle: " + 0.toString())
    poke(dut.io.signals_read.rs1, 5.U)
    poke(dut.io.signals_read.rs2, 0.U)
    poke(dut.io.signals_read.immediate, 32.U)
    poke(dut.io.signals_read.update, 1.U)
    poke(dut.io.signals_read.PC, 4.U)
    
    poke(dut.io.signals_alu.choose_pc, 0.U)
    poke(dut.io.signals_alu.choose_immediate, 1.U)
    poke(dut.io.signals_alu.alu_op, 0.U)
    poke(dut.io.signals_alu.update, 1.U)
    
    poke(dut.io.signals_writeback.choose_data, 0.U)
    poke(dut.io.signals_writeback.rd, 6.U)
	poke(dut.io.signals_writeback.update, 1.U)
	
	poke(dut.io.signals_branch1.immediate, 0.U)
	poke(dut.io.signals_branch1.update, 1.U)
	
	poke(dut.io.signals_branch2.branch_op, 2.U)
	poke(dut.io.signals_branch2.update, 1.U)
	
	poke(dut.io.signals_branch3.update, 1.U)
	
	step(5)
	    
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
