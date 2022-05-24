import chisel3._
import chisel3.iotesters.PeekPokeTester
import org.scalatest._

class testing_simple_hw_testbench(dut: simple_hw_testBench) extends PeekPokeTester(dut){
    poke(dut.io.rxd, 0.U)
    poke(dut.io.startProgram, 0.U)
    poke(dut.io.sw, 0.U)

    step(1)

    poke(dut.io.startProgram, 1.U)
    poke(dut.io.sw, 1.U)

    var a = 0;
      
      // for loop execution with a range
      for( a <- 1 to 1000){
         if(peek(dut.io.Led) == 1){
             print(peek(dut.io.txd).toChar)
         }
         step(1)
      }
} 

object testing_simple_hw_testbench extends App {
    val uartFrequency: Int = 100000000
    val uartBaudRate: Int = 115200
    val instructionCount: Int = 16
    val fpgaTesting: Boolean = false
    val uartOut: Boolean = false
    
  iotesters.Driver.execute(Array("--target-dir", "generated", "--generate-vcd-output", "off"),
   () => new simple_hw_testBench(uartFrequency, uartBaudRate, instructionCount, fpgaTesting, uartOut)) {
    c => new testing_simple_hw_testbench(c)
  }
}