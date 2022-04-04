import chisel3._
import chisel3.util._
import chisel3.Driver

class channel_a_buffer(z: Int, o: Int, a: Int, w: Int) extends Module {
    val io = IO(new Bundle{
        val channel_a_in = Flipped(new channel_a(z, o, a, w))
        val channel_a_out = new channel_a(z, o, a, w)
        val update = Input(Bool())
    })

    val opcode 	= Reg(UInt(3.W))
	val param 	= Reg(UInt(3.W))
	val size 	= Reg(UInt(z.W))
	val source 	= Reg(UInt(o.W))
	val address	= Reg(UInt(a.W))
	val mask 	= Reg(UInt(w.W))
	val data 	= Reg(UInt((8*w).W))

    io.channel_a_in.ready := true.B

    when(io.update){
        opcode := io.channel_a_in.opcode
        param := io.channel_a_in.param
        size := io.channel_a_in.size
        source := io.channel_a_in.source
        address := io.channel_a_in.address
        mask := io.channel_a_in.mask
        data := io.channel_a_in.data
    }

    io.channel_a_out.opcode := opcode
    io.channel_a_out.param := param
    io.channel_a_out.size := size
    io.channel_a_out.source := source
    io.channel_a_out.address := address
    io.channel_a_out.mask := mask
    io.channel_a_out.data := data

    io.channel_a_out.valid := true.B
}

class sw_testbench_memory_interface(addrWidth: Int) extends Bundle {
    //memory stores 8-bit words
    val read_address = Output(UInt(addrWidth.W))
    val read_data = Input(UInt(8.W))
    val write_address = Output(UInt(addrWidth.W))
    val write_data = Output(UInt(8.W))
    val write_enable = Output(Bool())
}

class sw_testbench_memory_controller(z: Int, a_o: Int, a_a: Int, w: Int, d_o: Int, d_i: Int) extends Module {
    val io = IO(new Bundle{
        val channel_a_in = Flipped(new channel_a(z, a_o, a_a, w))
        val channel_d_out = new channel_d(z, d_o, d_i, w)
        val memory_channel = new sw_testbench_memory_interface(a_a)
    })

    val a_ready :: data_transfer :: d_valid :: Nil = Enum(3)
    val stateReg = RegInit(a_ready)
    val byte_size = Reg(UInt())

    val channel_a_in_buffer = Module(new channel_a_buffer(z, a_o, a_a, w))
    channel_a_in_buffer.io.channel_a_in <> io.channel_a_in

    channel_a_in_buffer.io.update := false.B

    val address_buffer = Reg(UInt(a_a.W))
    val cntReg = Reg(UInt(scala.math.pow(2,z).toInt.W))

    switch(stateReg){
        is(a_ready){
            //continously read and store input channel a
            io.channel_a_in.ready := true.B
            channel_a_in_buffer.io.update := true.B
            when(io.channel_a_in.valid){
                switch(io.channel_a_in.opcode){
                    is(channel_a_opcodes.GET){

                    }
                }
            }
        }
    }
}