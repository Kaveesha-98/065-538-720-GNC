import chisel3._
import chisel3.util._
import chisel3.Driver

class Memory() extends Module{
    val io = IO(new Bundle{
        val rdAddr = Input(UInt(32.W))
        val rdData = Output(SInt(8.W))
        val mem_write = Input(UInt(1.W))
        val mem_write_data = Input(SInt(8.W))
        val mem_write_address = Input(UInt(32.W))
    })

    val mem = SyncReadMem(262144, SInt(8.W))

    val wrDataReg = RegNext(io.mem_write_data)
    val doForwardReg = RegNext(io.mem_write_address === io.rdAddr && io.mem_write === 1.U)

    val memData = mem.read(io.rdAddr)

    when(io.mem_write === 1.U){
        mem.write(io.mem_write_address , io.mem_write_data)
    }
    
    io.rdData := Mux(doForwardReg , wrDataReg , memData)
}

object Memory extends App{
    (new chisel3.stage.ChiselStage).emitVerilog(new Memory())
}
