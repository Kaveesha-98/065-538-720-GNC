import chisel3._
import chisel3.util._
import chisel3.Driver

class Prefetch() extends Module{
    val io = IO(new Bundle{
            val pc = Input(UInt(32.W))
            val BRANCH = Input(UInt(1.W))
            val instr_in = Input(UInt(32.W))
            val instr_out = Output(UInt(32.W))
            val addr_out = Output(UInt(32.W))
            val VALID = Output(UInt(1.W))
    })
    val instr_1 = RegInit(0.U(32.W))
    val instr_2 = RegInit(0.U(32.W))
    val instr_3 = RegInit(0.U(32.W))

    val pc = io.pc
    val BRANCH = io.BRANCH
    val instr_in = io.instr_in
    val instr_out = WireInit(0.U(32.W))
    val addrBuff = RegInit(0.U(32.W))
    val VALID = WireInit(0.U(32.W))

    io.addr_out := addrBuff
    io.instr_out := instr_3
    io.VALID := VALID

    when(BRANCH === 0.U){
        instr_1 := instr_in
        instr_2 := instr_1
        instr_3 := instr_2
        addrBuff := addrBuff + 1.U
    }.otherwise{
        instr_1 := 0.U
        instr_2 := 0.U
        instr_3 := 0.U
        addrBuff := pc
    }

    when(pc === instr_3){
        VALID := 1.U
    }.otherwise{
        VALID := 0.U
    }
}

object Prefetch extends App{
    (new chisel3.stage.ChiselStage).emitVerilog(new Prefetch())
}