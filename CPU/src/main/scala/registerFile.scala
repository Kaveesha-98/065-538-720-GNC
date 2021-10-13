import chisel3._
import chisel3.util._
import chisel3.Driver

class registerFile() extends Module{
    val io = IO(new Bundle{
    	//Control unit connections
        val RS1 = Input(UInt(5.W))
        val RS2 = Input(UInt(5.W))
        val RD = Input(UInt(5.W))
        val WRITE_EN = Input(UInt(1.W))
        //Datapath connections
        val rs1Data = Output(SInt(32.W))
        val rs2Data = Output(SInt(32.W))
        val rdData = Input(SInt(32.W))
    })

    val registerFile = Reg(Vec(32, SInt(32.W)))
    io.rs1Data := registerFile(io.RS1)
    io.rs2Data := registerFile(io.RS2)
    
    when(io.WRITE_EN === 1.U){
    	registerFile(io.RD) := io.rdData
    }
    
}

object registerFile extends App{
    (new chisel3.stage.ChiselStage).emitVerilog(new registerFile())
}
