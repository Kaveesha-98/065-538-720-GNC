import chisel3._
import chisel3.util._
import chisel3.Driver

class control_store extends Module{
	val io = IO(new Bundle{
		//Connections to instruction fetch unit
		val INSTRUCTION = Input(UInt(32.W))
		val RECIEVED = Output(UInt(1.W))
		val INSTRUCTION_LOADED = Input(UInt(1.W))
		//Register file to control unit connections
        val RS1 = Output(UInt(5.W))
        val RS2 = Output(UInt(5.W))
        val RD = Output(UInt(5.W))
        val WRITE_EN = Output(UInt(1.W))
        //ALU to control unit connections
        val ALU_OP = Output(UInt(4.W)) //ALUOperations{add, sub, sll, sra, srl, xor, or, and}
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
		val BRANCH_ADDRESS_SOURCE_ALU = Output(UInt(1.W))
		//PC update
		val UPDATE_PC = Output(UInt(1.W))
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
	
	val waiting :: stage1 :: stage2 :: stage3 :: stage4 :: stalling :: Nil = Enum(6)
	val stateReg = RegInit(waiting)
	val stallState = RegInit(stalling)
	val instruction = RegInit(0.U(32.W))
	val RECIEVED = RegInit(0.U(1.W))
	val STORE_READY = RegInit(0.U(1.W))
	val LOAD_READY = RegInit(0.U(1.W))
	
	io.RECIEVED := RECIEVED
	io.RS1 := 0.U
	io.RS2 := 0.U
	io.IMMEDIATE := 0.S
	io.CHOOSE_IMMEDIATE := 0.U
	io.BRANCH_IMMEDIATE := 0.U
	io.BRANCH_SELECT := 1.U
	io.BRANCH_CONDITION := 0.U
	io.STORE_SIZE := 1.U
	io.DATA_IN := 0.U
	io.RD := 0.U
    io.WRITE_EN := 0.U
    io.ALU_OP := 0.U
	io.CHOOSE_MEMORY_LOAD := 0.U
	io.ALU_RD := 0.U
	io.STORE_ADDRESS_IN := 0.U
	io.LOAD_SIZE := 0.U
	io.LOAD_ADDRESS_IN := 0.U
	io.EXTENSION := 0.U
	io.PROCEDURE_BRANCHING := 0.U
	io.BRANCH_ADDRESS_SOURCE_ALU := 0.U
	io.UPDATE_PC := 0.U
	RECIEVED := 0.U
	STORE_READY := io.STORE_READY
	LOAD_READY := io.LOAD_READY
	
	switch(stateReg){
		is(waiting){
			when(io.INSTRUCTION_LOADED === 1.U){
				RECIEVED := 1.U
				stateReg := stage1
				instruction := io.INSTRUCTION
			}
		}
		is(stage1){
			//Pipeline stage1-------------------------------------------------
			//Read registers
			//Immediate generation
			//enabling/disabling immediate
			//branching immediate generation
			//give data and data size to store unit
			
			stateReg := stage2
			
			//--Read registers
			when(io.INSTRUCTION === "b011_0111".U){
				io.RS1 := 0.U//for load upperimmediate immediate + "0"
			}otherwise{
				io.RS1 := instruction(19, 15)
			}
    		io.RS2 := instruction(24, 20)
			
			//--Immediate generation
			val imm12bit = Mux(instruction(6, 0) === "b010_0011".U, Cat(instruction(31, 25), instruction(11, 7)), instruction(31, 20))
			io.IMMEDIATE := Mux(instruction(6,0) === "b011_0111".U, (instruction&"hfffff000".U).asSInt, imm12bit.asSInt)
			
			//--enabling/disabling immediate
			io.CHOOSE_IMMEDIATE := Mux((instruction(6, 0) === "b0110011".U | instruction(6, 0) === "b1100011".U), 0.U, 1.U)
			
			//--branching immediate generation
			val imm12bitBranch = Cat(Cat(Cat(instruction(31), instruction(7)), Cat(instruction(11, 8), instruction(30, 25))),"b0".U)
			val imm20bitBranch = Cat(Cat(Cat(instruction(31), instruction(19, 12)), Cat(instruction(20), instruction(30, 21))), "b0".U)
			when(instruction(6, 0) === "b1100011".U){
				io.BRANCH_IMMEDIATE := Mux(instruction(31), "hffffe000".U | imm12bitBranch, "h00001fff".U & imm12bitBranch)
			}otherwise{
				io.BRANCH_IMMEDIATE := Mux(instruction(31), "hffe00000".U | imm20bitBranch, "h001fffff".U & imm20bitBranch)
			}
			
			//--give data and data size to store unit
			when(instruction(6, 0) === "b0100011".U){
				
				io.STORE_SIZE := Mux(instruction(13) === 1.U, "b00".U, ~instruction(13, 12))
				when(STORE_READY === 0.U){
					//store unit unavailable
					stallState := stateReg
					stateReg := stalling
				}otherwise{
					io.DATA_IN := 1.U
				}
			}
		}
		is(stage2){
			//setting ALU signals
			//saving return address
			//saving return address, for jump and link
			//updating pc
			
			//--setting ALU signals
			switch(instruction(6, 0)){
			//only arithmetic require special setup others all use add
				is("b0010011".U){
					io.ALU_OP := Cat(Mux(instruction(13, 12) === "b01".U, instruction(30), "b0".U), instruction(14, 12))
				}
				is("b0110011".U){
					io.ALU_OP := Cat(instruction(30), instruction(14, 12))
				}
			}
			
			//--saving return address, for jump and link
			when((instruction(6, 0)&"b1110111".U) === "b1100111".U){
				io.RD := instruction(11, 7)
				io.WRITE_EN := 1.U
				io.PROCEDURE_BRANCHING := 1.U
				io.BRANCH_ADDRESS_SOURCE_ALU := Mux(instruction(6, 0) === "b1100111".U, 1.U, 0.U)
			}
			
			when(instruction(6, 0) === "b1100011".U){
				io.BRANCH_SELECT := instruction(14, 13)
				io.BRANCH_CONDITION := ~instruction(12)
			}
			
			//updating pc
			io.UPDATE_PC := 1.U
			
			//ending branching operations
			when(instruction(6, 0) === "b1101111".U | instruction(6, 0) === "b1100111".U | instruction(6, 0) === "b1100011".U){
				stateReg := waiting
			}
						
			stateReg := stage3
		}
		is(stage3){
			//Give address to store
			//Give address to load
			//writeback on arithmetic
			
			//--Give address to store
			io.STORE_ADDRESS_IN := Mux(instruction(6, 0) === "b0100011".U, 1.U, 0.U)
			
			//--Give address to load
			io.LOAD_ADDRESS_IN := Mux(instruction(6, 0) === "b0000011".U, 1.U, 0.U)
			io.LOAD_SIZE := Mux(instruction(13, 12) === "b10".U, "b11".U, ~instruction(13, 12))
			io.EXTENSION := ~instruction(14)
			
			//--writeback on arithmetic
			io.RD := instruction(11, 7)
			
			when(instruction(6, 0) === "b0110011".U | instruction(6, 0) === "b0010011".U){
				io.WRITE_EN := 1.U
				stateReg := waiting
				io.CHOOSE_MEMORY_LOAD := 0.U
			}
			
			stateReg := Mux(instruction(6, 0) === "b0000011".U, stage4, waiting)
		}
		is(stage4){
			io.RD := instruction(11, 7)
			when(LOAD_READY === 0.U){
				stallState := stateReg
				stateReg := stalling
				io.WRITE_EN := 0.U
			}otherwise{
				io.WRITE_EN := 1.U
				io.CHOOSE_MEMORY_LOAD := 1.U
				stateReg := waiting
			}
		}
		is(stalling){
			switch(stallState){
				is(stage1){
					when(io.STORE_READY === 1.U){
						stateReg := stallState
					}
				}
				is(stage4){
					when(LOAD_READY === 1.U){
						stateReg := stallState
					}
				}
			}
		}
	}
}

object control_store extends App{
    (new chisel3.stage.ChiselStage).emitVerilog(new control_store())
}
