import chisel3._
import chisel3.util._
import chisel3.Driver

class sw_testbench_memory_interface(addrWidth: Int) extends Module {
    //memory stores 8-bit words
    val read_address = Output(UInt(addrWidth.W))
    val read_data = Input(UInt(8.W))
    val write_address = Output(UInt(addrWidth.W))
    val write_data = Output(UInt(8.W))
    val write_enable = Output(Bool())
}

class sw_testbench_memory_controller(a_z: Int, a_o: Int, a_a: Int, a_w: Int, d_z: Int, d_o: Int, d_i: Int, d_w: Int, memAddrWidth: Int) extends Module {
    val io = IO(new Bundle{
        channel_a_in = Flipped(new channel_a(a_z, a_o, a_a, a_w))
        channel_d_out = new channel_d(d_z, d_o, d_i, d_w)
        memory_channel = new sw_testbench_memory_interface(memAddrWidth)
    })
}