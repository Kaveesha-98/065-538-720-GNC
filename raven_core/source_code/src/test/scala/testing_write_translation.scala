import chisel3._
import chisel3.iotesters.PeekPokeTester
import org.scalatest._

class testing_write_translation(dut: write_translation) extends PeekPokeTester(dut){
    reset()
    step(2)
} 

object testing_write_translation extends App {
    val uartFrequency: Int = 100000000
    val uartBaudRate: Int = 115200
    val instructionCount: Int = 16
    val fpgaTesting: Boolean = false
    val uartOut: Boolean = false
    
  iotesters.Driver.execute(Array("--target-dir", "generated", "--generate-vcd-output", "off"),
   () => new write_translation(32, 2, 32, 78125000, 115200)) {
    c => new testing_write_translation(c)
  }
}