import chisel3._
import chisel3.util._
import chisel3.Driver

class datapath_read() extends Bundle{
	//datapath signals for read stage
	val PC = UInt(32.W)							/*PC of the instruction*/
	//rs1 and rs2 are extracted from the corresponding fields in the instruction
	val rs1 = UInt(5.W)							
	val rs2 = UInt(5.W)
	val immediate = UInt(32.W)
	//signals that the given signals are valid
	val update = UInt(1.W)
}

class datapath_alu() extends Bundle{
	//data path signals for alu stage
	//signals to choose the correct value for alu input
	val choose_immediate = UInt(32.W)
	val choose_pc = UInt(32.W)
	val alu_op = UInt(4.W)						/*alu operation for instruction executed*/
	//signals that the given signals are valid
	val update = UInt(1.W)
}

class datapath_writeback() extends Bundle{
	//datapath signals for writeback stage
	val choose_data = UInt(2.W)					/*chooses the correct data for write back*/
	val rd = UInt(5.W)
	//signals that the given signals are valid
	val update = UInt(1.W)
}

class datapath_branch_stage1() extends Bundle{
	val immediate = UInt(32.W)					/*branch immediate for conditional and jal branches*/
	//signals that the given signals are valid
	val update = UInt(1.W)
}

class datapath_branch_stage2() extends Bundle{
	val branch_op = UInt(5.W)					/*{Uncoditional branch type 3 bits, branching type}*/
	//signals that the given signals are valid
	val update = UInt(1.W)
}

class datapath_branch_stage3() extends Bundle{
	val update = UInt(1.W)
}
