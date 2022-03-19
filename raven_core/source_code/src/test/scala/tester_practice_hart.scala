import chisel3._
import chisel3.iotesters.PeekPokeTester
import org.scalatest._
import java.io._
import scala.io.Source

class tester_practice_hart(dut: practice_hart) extends PeekPokeTester(dut) {

    //println("clk cycle: 50" + 0.toString())
    
    val reg_ins = "b0000000_00101_00001_000_00110_0110011"
    val reg_imm_ins = "b0000000_00101_00110_000_00110_0010011"
    val reg_imm_ins1 = "b0000000_00101_00110_000_00111_0010011"
    val reg_imm_ins2 = "b0000000_00101_00101_000_00111_0010011"
	
	poke(dut.io.write_address_ready, 0.U)
	poke(dut.io.write_data_ready, 0.U)
	poke(dut.io.load_address_ready, 0.U)
	poke(dut.io.load_data_valid, 0.U)
	poke(dut.io.load_data, 0.U)

	val testInstructionsFile = Source.fromFile("test_instructions.txt")

	val instructions = testInstructionsFile.getLines.toArray
	
	testInstructionsFile.close
	
	poke(dut.io.instruction, instructions(0).U)
	poke(dut.io.fetch_valid, 1.U)
	poke(dut.io.fetch_PC, 0.U)
	
	var i: Int = 1
	var cycles: Int = 0
	
	while(i < 33){
		step(1)
		cycles = cycles + 1
		while(peek(dut.io.ready).toString == "0"){
			step(1)
			cycles = cycles + 1
		}
		poke(dut.io.instruction, instructions(i).U)
		poke(dut.io.fetch_PC, (4*i).U)
		i = i + 1
	}
	
	while(peek(dut.io.write_data_valid).toString == "0"){
		step(1)
		cycles = cycles + 1
	}

	println("Total no of cycles: " + cycles.toString)

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

object tester_practice_hart extends App {
  iotesters.Driver.execute(Array("--target-dir", "generated", "--generate-vcd-output", "on"), () => new practice_hart()) {
    c => new tester_practice_hart(c)
  }
}

class simpleSpec_tester_practice_hart extends FlatSpec with Matchers {
  "Tester" should "pass" in {
    iotesters.Driver.execute(Array("--target-dir", "generated", "--generate-vcd-output", "on"), () => new practice_hart()) { c =>
      new tester_practice_hart(c)
    } should be (true)
  }
}
