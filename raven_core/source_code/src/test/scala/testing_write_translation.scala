import chisel3._
import chisel3.iotesters.PeekPokeTester
import org.scalatest._

class testing_write_translation(dut: write_translation) extends PeekPokeTester(dut){
    reset()
    step(2)

    /* 
    //testing memory writes
    poke(dut.io.store_data, "h12_34_56_78".U)
    poke(dut.io.write_data_valid, 1.U)

    step(1)
    poke(dut.io.write_data_valid, 0.U)

    poke(dut.io.write_address, "h0012_345f".U)
    poke(dut.io.write_address_size, "b01".U)
    poke(dut.io.write_address_valid, 1.U)

    step(1)
    poke(dut.io.write_address_valid, 0.U)

    while(peek(dut.io.writePort.wr.en) == 0){
      expect(dut.io.txChannel.valid, false.B)
      step(1)
    }

    expect(dut.io.writePort.wr.data, "h78000000".U)
    expect(dut.io.writePort.wr.mask, "b0111".U)

    step(1)

    expect(dut.io.writePort.wr.data, "h00123456".U)
    expect(dut.io.writePort.wr.mask, "b1110".U)

    step(1)

    expect(dut.io.writePort.cmd.addr, "h0012_345c".U)
    expect(dut.io.writePort.cmd.bl, 1.U)

    step(1) */

    //testing uart
    poke(dut.io.store_data, "h12_34_56_78".U)
    poke(dut.io.write_data_valid, 1.U)

    step(1)
    poke(dut.io.write_data_valid, 0.U)

    poke(dut.io.write_address, "hff12_345f".U)
    poke(dut.io.write_address_size, "b10".U)
    poke(dut.io.write_address_valid, 1.U)

    poke(dut.io.txChannel.ready, true.B)
    step(1)
    poke(dut.io.write_address_valid, 0.U)

    while(peek(dut.io.txChannel.valid) == 0){
      expect(dut.io.writePort.wr.en, false.B)
      //println(peek(dut.io.txChannel.valid).toString)
      step(1)
    }

    //step(12)

    if(peek(dut.io.txChannel.valid) == 1){
      expect(dut.io.txChannel.bits, "h78".U)
    }
    step(1)

    if(peek(dut.io.txChannel.valid) == 1){
      expect(dut.io.txChannel.bits, "h56".U)
    }
    step(1)

    if(peek(dut.io.txChannel.valid) == 1){
      expect(dut.io.txChannel.bits, "h34".U)
    }
    step(1)

    if(peek(dut.io.txChannel.valid) == 1){
      expect(dut.io.txChannel.bits, "h12".U)
    }
    step(1)
} 

object testing_write_translation extends App {
    val uartFrequency: Int = 100000000
    val uartBaudRate: Int = 115200
    val instructionCount: Int = 16
    val fpgaTesting: Boolean = false
    val uartOut: Boolean = false
    
  iotesters.Driver.execute(Array("--target-dir", "generated", "--generate-vcd-output", "on"),
   () => new write_translation()) {
    c => new testing_write_translation(c)
  }
}