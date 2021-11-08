import chisel3._
import chisel3.util._
import chisel3.Driver

class Prefetch() extends Module{
    val io = IO(new Bundle{
            // IO from datapath
            val pc        = Input(UInt(32.W))       // Program counter
            val BRANCH    = Input(UInt(1.W))        // Branch signal
            val instr_out = Output(UInt(32.W))      // Output instruction
            val VALID     = Output(UInt(1.W))       // Valid bit
            // IO from instruction memory
            val instr_in  = Input(UInt(32.W))       // Instruction from instruction memory
            val addr_out  = Output(UInt(32.W))      // Address for instruction memory
    })
    // Registers for pre-loaded instructions
    val instr_1 = RegInit(0.U(32.W))
    val instr_2 = RegInit(0.U(32.W))
    val instr_3 = RegInit(0.U(32.W))
    // Set variables for inputs and set default values to outputs
    val pc = io.pc
    val BRANCH    = io.BRANCH
    val instr_in  = io.instr_in
    val instr_out = WireInit(0.U(32.W))
    val addrBuff  = RegInit(0.U(32.W))
    val VALID     = WireInit(0.U(32.W))

    io.addr_out  := addrBuff
    io.instr_out := instr_3
    io.VALID     := VALID

    when(BRANCH === 0.U){               // When there is no branching
        instr_1  := instr_in
        instr_2  := instr_1
        instr_3  := instr_2
        addrBuff := addrBuff + 1.U      // Incrementing instruction address
    }.otherwise{                        // When there is a branching
        instr_1  := 0.U
        instr_2  := 0.U
        instr_3  := 0.U
        addrBuff := pc                  // Give the pc value to instruction memory
    }

    when(pc === instr_3){               // Check the pc with the instruction
        VALID := 1.U                    // Correct instruction
    }.otherwise{
        VALID := 0.U                    // Incorrect instruction
    }
}

object Prefetch extends App{
    (new chisel3.stage.ChiselStage).emitVerilog(new Prefetch())
}