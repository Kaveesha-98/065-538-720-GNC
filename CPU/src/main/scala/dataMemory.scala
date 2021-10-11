import chisel3._
import chisel3.util._
import chisel3.Driver

class Memory() extends Module{
    val io = IO(new Bundle{
        val rdAddr = Input(UInt(32.W))
        val rdData = Output(SInt(8.W))
        val wrEna = Input(UInt(1.W))
        val mem_write_data = Input(SInt(8.W))
        val mem_write_address = Input(UInt(32.W))
    })

    val mem = SyncReadMem(1024, SInt(8.W))

    val wrDataReg = RegNext(io.mem_write_data)
    val doForwardReg = RegNext(io.mem_write_address === io.rdAddr && io.wrEna)

    val memData = mem.read(io.rdAddr)

    when(io.wrEna) {
        mem.write(io.mem_write_address , io.mem_write_data)
    }
    
    io.rdData := Mux(doForwardReg , wrDataReg , memData)
}

object Memory extends App{
    (new chisel3.stage.ChiselStage).emitVerilog(new Memory())
}
