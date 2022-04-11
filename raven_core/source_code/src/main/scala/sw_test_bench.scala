import chisel3._
import chisel3.util._
import chisel3.Driver

class channel_a_buffer(z: Int, o: Int, a: Int, w: Int) extends Module {
    val io = IO(new Bundle{
        val channel_a_in = Flipped(new channel_a(4, o, a, w))
        val channel_a_out = new channel_a(z, o, a, w)
        val update = Input(Bool())
        val reset = Input(Bool())
    })

    val empty :: full :: Nil = Enum(2)
    val stateReg = RegInit(empty)

    val opcode 	= Reg(UInt(3.W))
	val param 	= Reg(UInt(3.W))
	val size 	= Reg(UInt(z.W))
	val source 	= Reg(UInt(o.W))
	val address	= Reg(UInt(a.W))
	val mask 	= Reg(UInt(w.W))
	val data 	= Reg(UInt((8*w).W))

    io.channel_a_in.ready := stateReg === empty
    io.channel_a_out.valid := stateReg === full

    when(io.update){
        opcode := io.channel_a_in.opcode
        param := io.channel_a_in.param
        size := io.channel_a_in.size
        source := io.channel_a_in.source
        address := io.channel_a_in.address
        mask := io.channel_a_in.mask
        data := io.channel_a_in.data
        stateReg := full
    }.elsewhen(io.reset){
        stateReg := empty
    }

    io.channel_a_out.opcode := opcode
    io.channel_a_out.param := param
    io.channel_a_out.size := size
    io.channel_a_out.source := source
    io.channel_a_out.address := address
    io.channel_a_out.mask := mask
    io.channel_a_out.data := data

}

class sw_testbench_memory_interface(addrWidth: Int) extends Bundle {
    //memory stores 8-bit words
    val read_address = Output(UInt(addrWidth.W))
    val read_data = Input(UInt(8.W))
    val write_address = Output(UInt(addrWidth.W))
    val write_data = Output(UInt(8.W))
    val write_enable = Output(Bool())
}

class sw_testbench_memory_controller(sourceBits: Int) extends Module {
    val io = IO(new Bundle{
        //contacts only with two masters
        val channel_a_data = Flipped(new channel_a(4, 1, 32, 4))
        val channel_a_instruction = Flipped(new channel_a(4, 1, 32, 4))
        val channel_d_out = new channel_d(4, 1, 1, 4)
        val memory_channel = new sw_testbench_memory_interface(32)
    })

    def nBitWidthIncrement[T <: Data](bitCnt: T, with: Int): T = {
        val partialProducts = new Array[chisel3.UInt]((width)

        for(i <- 0 until width){
            partialProducts(i) = Wire(UInt(1.W))
        }

        partialProducts(0) = true.B
        partialProducts(1) = bitCnt(0).asBool

        for(i <- 2 until width){
            partialProducts(i) := bitCnt(i-1, 0).andR
        }

        val nextBitCntArray = new Array[chisel3.UInt](width)

        for(i <- 0 until width){
            nextBitCntArray(i) = Wire(UInt(1.W))

            nextBitCntArray(i) := Mux(partialProducts(i), ~bitCnt(i), bitCnt)
        }

        val nextBitCnt = Cat(nextBitCntArray.reverse)
        nextBitCnt
    }

    val channel_a_ready :: memory_fetch :: Nil      = Enum(2)
    val channel_instruction :: channel_data :: Nil  = Enum(2)

    val stateReg    = RegInit(channel_a_ready)
    val msgSource   = RegInit(channel_instruction)

    val channel_a_buffer_instruction    = Module(new channel_a_buffer(4, 1, 32, 4))
    val channel_a_buffer_data           = Module(new channel_a_buffer(4, 1, 32, 4))

    switch(stateReg){
        is(channel_a_ready){
            
        }
    }
}