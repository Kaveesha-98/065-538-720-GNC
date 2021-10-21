import chisel3._
import chisel3.iotesters.PeekPokeTester
import org.scalatest._

class Tester(dut: Memory ) extends PeekPokeTester(dut) {
  // Write data 5 to address 6
  poke(dut.io.mem_write,true.B)
  poke(dut.io.mem_write_data,5.S)
  poke(dut.io.mem_write_address,6.U)
  step(1)
  // Write data 40 to address 10
  poke(dut.io.mem_write,true.B)
  poke(dut.io.mem_write_data,-40.S)
  poke(dut.io.mem_write_address,10.U)
  step(1)
  // Read address 6
  poke(dut.io.rdAddr,6.U)
  step(1)
  println("clk cycle: " + 3.toString)
  println("result: " + peek(dut.io.rdData).toString)
  println("")
  // Read address 10
  poke(dut.io.rdAddr,10.U)
  step(1)
  println("clk cycle: " + 4.toString)
  println("result: " + peek(dut.io.rdData).toString)
  println("")
  // Write data 50 to address 6 and read address 6
  poke(dut.io.mem_write,true.B)
  poke(dut.io.mem_write_data,-50.S)
  poke(dut.io.mem_write_address,6.U)
  poke(dut.io.rdAddr,6.U)
  step(1)
  // First read
  println("clk cycle: " + 5.toString)
  println("result: " + peek(dut.io.rdData).toString)
  println("")
  step(1)
  // Second read
  println("clk cycle: " + 6.toString)
  println("result: " + peek(dut.io.rdData).toString)
  println("")

}

object Tester extends App {
	chisel3.iotesters.Driver(() => new Memory()) { c => 
	new Tester(c)
	}
}

class SimpleSpec extends FlatSpec with Matchers {
  "Tester" should "pass" in {
    chisel3.iotesters.Driver (() => new Memory()) { c =>
      new Tester(c)
    } should be (true)
  }
}