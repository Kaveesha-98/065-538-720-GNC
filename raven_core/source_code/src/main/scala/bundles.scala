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
	val choose_immediate = UInt(1.W)
	val choose_pc = UInt(1.W)
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
	val branch_op = UInt(5.W)					/*{Uncoditional branch type (func3), branching type(opcode(3, 2))}*/
	//signals that the given signals are valid
	val update = UInt(1.W)
}

class datapath_branch_stage3() extends Bundle{
	val update = UInt(1.W)
}

/*
TileLink per-link channel parameters
w - Width of the data bus in bytes, Must be a power of two
a - Width of each address field in bits. Must be atleast 32
z - Width of each size in bits. Must be at least 4
o - Number of bits needed to disambiguate per-link master sources
i - Number of bits needed to disambiguate per-link slave sinks
*/
class channel_a(z: Int, o: Int, a: Int, w: Int) extends Bundle{
	//signal direction from master to slave
	val opcode 	= Output(UInt(3.W))
	val param 	= Output(UInt(3.W))
	val size 	= Output(UInt(z.W))
	val source 	= Output(UInt(o.W))
	val address = Output(UInt(a.W))
	val mask 	= Output(UInt(w.W))
	val data 	= Output(UInt((8*w).W))
	val valid 	= Output(Bool())
	val ready 	= Input(Bool())
}

class channel_d(z: Int, o: Int, i: Int, w: Int) extends Bundle{
	//signals direction from slave to master
	val opcode 	= Output(UInt(3.W))
	val param 	= Output(UInt(2.W))
	val size 	= Output(UInt(z.W))
	val source 	= Output(UInt(o.W))
	val sink	= Output(UInt(i.W))
	val data	= Output(UInt((8*w).W))
	val error	= Output(Bool())
	val valid	= Output(Bool())
	val ready	= Input(Bool())
}