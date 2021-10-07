import chisel3._
import chisel3.util._
import chisel3.Driver

class Memory() extends Module{
    val io = IO(new Bundle{
        val rdAddr = Input(UInt(32.W))
        val rdData = Output(SInt(8.W))
        val wrEna = Input(Bool())
        val wrData = Input(SInt(8.W))
        val wrAddr = Input(UInt(32.W))
    })

    val mem = SyncReadMem(1024, SInt(8.W))

    val wrDataReg = RegNext(io.wrData)
    val doForwardReg = RegNext(io.wrAddr === io.rdAddr && io.wrEna)

    val memData = mem.read(io.rdAddr)

    when(io.wrEna) {
        mem.write(io.wrAddr , io.wrData)
    }
    
    io.rdData := Mux(doForwardReg , wrDataReg , memData)
}

object Memory extends App{
    (new chisel3.stage.ChiselStage).emitVerilog(new Memory())
}