import chisel3._
import chisel3.util._
import chisel3.Driver

class control_store extends Module{
	val io = IO(new Bundle{
		//Connections to instruction fetch unit
		val INSTRUCTION = Input(UInt(32.W))
		val READY = Output(UInt(1.W))
		val INSTRUCTION_LOADED = Input(UInt(1.W))
		//Register file to control unit connections
        val RS1 = Output(UInt(5.W))
        val RS2 = Output(UInt(5.W))
        val RD = Output(UInt(5.W))
        val WRITE_EN = Output(UInt(1.W))
        //ALU to control unit connections
        val ALU_OP = Output(UInt(3.W)) //ALUOperations{add, sub, sll, sra, srl, xor, or, and}
		//For data Flow conrol
		val PROCEDURE_BRANCHING = Output(UInt(1.W))//=1 choose return address
		val CHOOSE_IMMEDIATE = Output(UInt(1.W))
		val CHOOSE_MEMORY_LOAD = Output(UInt(1.W))
		val IMMEDIATE = Output(SInt(32.W))
		val BRANCH_IMMEDIATE = Output(UInt(32.W))
		//For pipeline
		val ALU_RD = Output(UInt(5.W))
		val STORE_READY = Input(UInt(1.W))//Indicates that the Store unit is ready for a store operation
		val DATA_IN = Output(UInt(1.W))//Signals the store unit that data has been given
		val STORE_SIZE = Output(UInt(2.W))//11-byte, 10-halfword, 00-word
		val STORE_ADDRESS_IN = Output(UInt(1.W))//Signals the store unit that address has been given
		val LOAD_READY = Input(UInt(1.W))//Indicates that the Load unit is ready for a store operation
		val LOAD_SIZE = Output(UInt(2.W))//11-byte, 10-halfword, 00-word
		val LOAD_ADDRESS_IN = Output(UInt(1.W))//Signals the store unit that address has been given
		val EXTENSION = Output(UInt(1.W))//=0 unsigned extension
		//Branch opertions
		val BRANCH_SELECT = Output(UInt(2.W))
		val BRANCH_CONDITION = Output(UInt(1.W))
	})
	
	//opcodes
	//0110111 - Load upper immediate
	//1101111 - Jump and Link,
	//1100111 - Jum and link register
	//1100011 - Conditional branches
	//0000011 - Load
	//0100011 - Store
	//0010011 - Immediate arithmetic
	//0110011 - Register arithmetic
	
	val waiting :: stage1 :: stage2 :: Nil = Enum(3)
	val stateReg = RegInit(waiting)
	val instruction = RegInit(0.U(32.W))
	
	io.READY := 0.U
	io.RS1 := 0.U
	io.RS2 := 0.U
	io.IMMEDIATE := 0.S
	
	switch(stateReg){
		is(waiting){
			io.READY := 1.U
			when(io.INSTRUCTION_LOADED === 1.U){
				io.READY := 0.U
				stateReg := stage1
				instruction := io.INSTRUCTION
			}
		}
		is(stage1){
			//Pipeline stage1-------------------------------------------------
			//Read registers
			//Immediate generation
			
			//--Read registers
			when(io.INSTRUCTION === "b011_0111".U){
				io.RS1 := 0.U//for load upperimmediate immediate + "0"
			}otherwise{
				io.RS1 := instruction(19, 15)
			}
    		io.RS2 := instruction(24, 20)
			
			//--Immediate generation
			val imm12bit = Mux(instruction(7, 0) === "b010_0011".U, Cat(instruction(31, 25), instruction(11, 7)), instruction(31, 20))
			io.IMMEDIATE := Mux(instruction === "b011_0111".U, (instruction&"hfffff000".U).asSInt, imm12bit.asSInt)
			
			//--enabling/disabling immediate
			
			stateReg := stage2
		}
		is(stage2){
			stateReg := waiting
		}
	}
	io.RD := 0.U
    io.WRITE_EN := 0.U
    io.ALU_OP := 0.U
	io.CHOOSE_IMMEDIATE := 0.U
	io.CHOOSE_MEMORY_LOAD := 0.U
	io.ALU_RD := 0.U
	io.DATA_IN := 0.U
	io.STORE_SIZE := 0.U
	io.STORE_ADDRESS_IN := 0.U
	io.LOAD_SIZE := 0.U
	io.LOAD_ADDRESS_IN := 0.U
	io.EXTENSION := 0.U
	io.PROCEDURE_BRANCHING := 0.U
	io.BRANCH_IMMEDIATE := 0.U
	io.BRANCH_SELECT := 0.U
	io.BRANCH_CONDITION := 0.U
}

object control_store extends App{
    (new chisel3.stage.ChiselStage).emitVerilog(new control_store())
}
