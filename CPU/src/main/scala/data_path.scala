import chisel3._
import chisel3.util._
import chisel3.Driver

class data_path extends Module{
	val io = IO(new Bundle{
		//Register file to control unit connections
        val RS1 = Input(UInt(5.W))
        val RS2 = Input(UInt(5.W))
        val RD = Input(UInt(5.W))
        val WRITE_EN = Input(UInt(1.W))
        //ALU to control unit connections
        val ALU_OP = Input(UInt(3.W)) //ALUOperations{add, sub, sll, sra, srl, xor, or, and}
        val EQUAL = Output(UInt(1.W)) //When two registers are equal
        val LESS_THAN = Output(UInt(1.W)) // When input1 is less than input 2
        //data memory connections
        val store_data = Output(SInt(32.W))
		val store_address = Output(UInt(32.W))
		val load_data = Input(SInt(32.W))
		val load_address = Output(UInt(32.W))
		//For data Flow conrol
		val CHOOSE_IMMEDIATE = Input(UInt(1.W))
		val CHOOSE_MEMORY_LOAD = Input(UInt(1.W))
		val IMMEDIATE = Input(SInt(32.W))
		//For pipeline
		val ALU_RD = Input(UInt(5.W))
	})
	
	val cpuALU = Module(new ALU())
	val registerFile = Module(new register_file())
	
	//Value storing registers between cycles
	val ALU_in1 = Reg(SInt(32.W))
	val ALU_in2 = Reg(SInt(32.W))
	val ALU_out = Reg(SInt(32.W))
	
	//Writing to registerFile
	val rdData = Mux(io.CHOOSE_MEMORY_LOAD === 1.U, io.load_data, ALU_out)
	registerFile.io.rdData := rdData
	
	//Finding input for ALU
	//Input1
	val rs1_ALU = Mux(io.RS1 === io.ALU_RD, ALU_out, registerFile.io.rs1Data)
	val rs1_ALU_rd = Mux(io.RS1 === io.RD, rdData, rs1_ALU)
	ALU_in1 := Mux(io.RS1 === 0.U, 0.S, rs1_ALU_rd)
	//Input2
	val rs2_ALU = Mux(io.RS2 === io.ALU_RD, ALU_out, registerFile.io.rs2Data)
	val rs2_ALU_rd = Mux(io.RS2 === io.RD, rdData, rs2_ALU)
	val rs2_ALU_rd_0U = Mux(io.RS2 === 0.U, 0.S, rs2_ALU_rd)
	ALU_in2 := Mux(io.CHOOSE_IMMEDIATE === 1.U, io.IMMEDIATE, rs2_ALU_rd_0U)
	
	//Connecting Register file to control signals
	registerFile.io.RS1 := io.RS1
	registerFile.io.RS2 := io.RS2
	registerFile.io.RD := io.RD
	registerFile.io.WRITE_EN := io.WRITE_EN
	
	//Connecting ALU to control signals
	io.EQUAL := cpuALU.io.EQUAL
	io.LESS_THAN := cpuALU.io.LESS_THAN
	cpuALU.io.ALU_OP := io.ALU_OP
	
	io.store_data := rs2_ALU_rd_0U
	io.store_address := ALU_out.asUInt
	io.load_address := ALU_out.asUInt
	
	cpuALU.io.ALUinput1 := ALU_in1
	cpuALU.io.ALUinput2 := ALU_in2
}

object data_path extends App{
    (new chisel3.stage.ChiselStage).emitVerilog(new data_path())
}
