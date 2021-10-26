import chisel3._
import chisel3.util._
import chisel3.Driver

class core_robin extends Module{
	val io = IO(new Bundle{
		//temporary ports to be removed after pretech unit
		val INSTRUCTION = Input(UInt(32.W))
		val RECIEVED = Output(UInt(1.W))
		val INSTRUCTION_LOADED = Input(UInt(1.W))
		//data memory connections
		val rdAddr = Output(UInt(32.W))
        val rdData = Input(SInt(8.W))
        val mem_write = Output(UInt(1.W))
        val mem_write_data = Output(SInt(8.W))
        val mem_write_address = Output(UInt(32.W))
	})
	
	val controlStore = Module(new control_store())
	val dataPath = Module(new data_path())
	val storeUnit = Module(new Store_Unit())
	val loadUnit = Module(new Load_Unit())
	
	val PC = RegInit(0.U(32.W))
	
	//find the next address of PC
	val noBranchNextAddr = PC + 4.U
	val branchImmBranchAddr = PC + controlStore.io.BRANCH_IMMEDIATE
	//choosing which branch condition signed or unsigned compare
	val lessThanGreaterThanALUResult = Mux(controlStore.io.BRANCH_SELECT(1) === 1.U, dataPath.io.LESS_THAN, dataPath.io.SIGNED_LESS_THAN)
	//choosing which branch condition is needed
	val branchCheck = Mux(controlStore.io.BRANCH_SELECT(0) === 1.U, lessThanGreaterThanALUResult, dataPath.io.EQUAL)
	//look if conditional branching
	val conditionalBranching = branchCheck & controlStore.io.BRANCH_CONDITION
	//all address except jalr
	val conditionaljalOrnoBranch = Mux((conditionalBranching | controlStore.io.PROCEDURE_BRANCHING) === 1.U, branchImmBranchAddr, noBranchNextAddr)
	val nexAddress = Mux(controlStore.io.BRANCH_ADDRESS_SOURCE_ALU === 1.U, dataPath.io.instruction_next_address, conditionaljalOrnoBranch)
	
	//connecting to prefech
	controlStore.io.INSTRUCTION := io.INSTRUCTION
	controlStore.io.INSTRUCTION_LOADED := io.INSTRUCTION_LOADED
	io.RECIEVED := controlStore.io.RECIEVED
	
	//register file control
	dataPath.io.RS1 := controlStore.io.RS1
	dataPath.io.RS2 := controlStore.io.RS2
	dataPath.io.RD := controlStore.io.RD
	dataPath.io.WRITE_EN := controlStore.io.WRITE_EN
	dataPath.io.ALU_RD := controlStore.io.ALU_RD
	
	//ALU operation
	dataPath.io.ALU_OP := controlStore.io.ALU_OP
	
	//ALU input control
	dataPath.io.IMMEDIATE := controlStore.io.IMMEDIATE
	dataPath.io.CHOOSE_IMMEDIATE := controlStore.io.CHOOSE_IMMEDIATE
	dataPath.io.CHOOSE_PC := controlStore.io.CHOOSE_PC
	
	//Branching, saving return address to register file
	dataPath.io.PROCEDURE_BRANCHING := controlStore.io.PROCEDURE_BRANCHING
	//selecting load data
	dataPath.io.CHOOSE_MEMORY_LOAD := controlStore.io.CHOOSE_MEMORY_LOAD
	
	dataPath.io.instruction_return_address := noBranchNextAddr
	
	dataPath.io.PC := PC
	
	//connecting store unit to control store
	controlStore.io.STORE_READY := storeUnit.io.STORE_READY
	storeUnit.io.DATA_IN := controlStore.io.DATA_IN
	storeUnit.io.STORE_SIZE := controlStore.io.STORE_SIZE
	storeUnit.io.ADDRESS_IN := controlStore.io.STORE_ADDRESS_IN
	
	//connecting store unit to datapath
	storeUnit.io.store_data := dataPath.io.store_data
	storeUnit.io.store_address := dataPath.io.store_address
	
	//connecting store unit to IO
	io.mem_write_data := storeUnit.io.mem_write_data
	io.mem_write_address := storeUnit.io.mem_write_address
	io.mem_write := storeUnit.io.mem_write
	
	//connecting load unit to control store
	controlStore.io.LOAD_READY := loadUnit.io.LOAD_READY
	loadUnit.io.LOAD_SIZE := controlStore.io.LOAD_SIZE
	loadUnit.io.ADDRESS_IN := controlStore.io.LOAD_ADDRESS_IN
	loadUnit.io.EXTENSION := controlStore.io.EXTENSION
	
	//connecting load unit to datapath
	dataPath.io.load_data := loadUnit.io.load_data
	loadUnit.io.load_address := dataPath.io.load_address
	
	//connecting load unit to IO
	loadUnit.io.rdData := io.rdData
	io.rdAddr := loadUnit.io.rdAddr
}

object core_robin extends App{
    (new chisel3.stage.ChiselStage).emitVerilog(new core_robin())
}