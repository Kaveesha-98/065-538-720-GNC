import chisel3._
import chisel3.iotesters.PeekPokeTester
import org.scalatest._

import scala.io.Source 

import scala.math.pow

class testing_testBench_with_memory(dut: chiseltestBench_with_ddr_memory) extends PeekPokeTester(dut){
    //poke(dut.reset, true.B)

    reset()
    
    step(1)

    poke(dut.io.rxd.valid, false.B)
    poke(dut.io.writingToMemory, true.B)

    val fname = "test_instructions.txt"
    val fSource = Source.fromFile(fname) 
    var textInstruction: String = "12"

    for(line<-fSource.getLines)
    { 
        poke(dut.io.rxd.valid, true.B)
        for(i <- 0 to 31){

            if(line(31-i) == '1'){
                poke(dut.io.rxd.bits, 49.U)
                //print('1')
            }else{
                poke(dut.io.rxd.bits, 48.U)
                //print('0')
            }

            poke(dut.io.rxd.valid, true.B)
            step(1)
            
            while(peek(dut.io.rxd.ready).toString == "0"){
                step(1)
                
            }
            
        }
        
        /* instructionMemory(i) := ("b" + line).U 
        i += 1 */
    } 
    fSource.close()
    poke(dut.io.rxd.valid, false.B)
    step(10)

    poke(dut.io.writingToMemory, false.B)
    poke(dut.io.startRead, true.B)

    step(1)

    poke(dut.io.txd.ready, true.B)

    for(i <- 0 to 1000){
        if(peek(dut.io.txd.valid) == 1){
            print(peek(dut.io.txd.bits).toChar)
        }
        step(1)
    }
} 

object testing_testBench_with_memory extends App {

    val uartFrequency: Int = 100000000
    val uartBaudRate: Int = 115200
    val instructionCount: Int = 16
    val fpgaTesting: Boolean = false
    val uartOut: Boolean = false

  iotesters.Driver.execute(Array("--target-dir", "generated", "--generate-vcd-output", "on"),
   () => new chiseltestBench_with_ddr_memory) {
    c => new testing_testBench_with_memory(c)
  }
}