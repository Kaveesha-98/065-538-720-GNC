import chisel3._
import chisel3.iotesters.PeekPokeTester
import org.scalatest._

class Tester(dut: Memory ) extends PeekPokeTester(dut) {
  var i = 0
  for( i <- 0 to 10){
    println("clk cycle: " + i.toString)
    println("result: " + peek(dut.io.rdData).toString)
    println("")
    step(1)
  }
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