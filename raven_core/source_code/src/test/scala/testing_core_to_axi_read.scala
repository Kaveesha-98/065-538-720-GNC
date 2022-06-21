import chisel3._
import chisel3.iotesters.PeekPokeTester
import org.scalatest._

class testing_core_to_axi(dut: core_to_axi) extends PeekPokeTester(dut){
    reset()
    step(2)

    poke(dut.io.readPort.rd.data, "h12345678".U)
    poke(dut.io.load_address, "h87654321".U)
    poke(dut.io.load_address_size, 0.U)

} 

object testing_core_to_axi extends App {
    val uartFrequency: Int = 100000000
    val uartBaudRate: Int = 115200
    val instructionCount: Int = 16
    val fpgaTesting: Boolean = false
    val uartOut: Boolean = false
    
  iotesters.Driver.execute(Array("--target-dir", "generated", "--generate-vcd-output", "on"),
   () => new core_to_axi()) {
    c => new testing_core_to_axi(c)
  }
}