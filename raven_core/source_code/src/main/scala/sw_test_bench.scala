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
        val channel_a_data = Flipped(new channel_a(4, sourceBits, 32, 4))
        val channel_a_instruction = Flipped(new channel_a(4, sourceBits, 32, 4))
        val channel_d_out = new channel_d(4, sourceBits, 1, 4)
        val memory_channel = new sw_testbench_memory_interface(32)
    })

    def twoBitIncrement[T <: Data](bitCnt: T): T = {
        val nextBitCnt0 = ~bitCnt(0)
        val nextBitCnt1 = Mux(bitCnt(0), ~bitCnt(1), bitCnt(1))
        val nextBitCnt  = Cat(nextBitCnt1, nextBitCnt0)
        nextBitCnt
    }

    def nBitIncrement[T <: Data](bitCnt: T, with: Int): T = {
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

    val memAddress = Reg(UInt(32.W))

    val newMemAddress = nBitIncrement(memAddress, 32)

    val a_ready :: data_get_start :: data_get_cont :: Nil = Enum(2)
    val stateReg = RegInit(a_ready)

    val buffer_channel_a_data = Module(new channel_a_buffer(4, 1, 32, 4))
    val buffer_channel_a_instruction = Module(new channel_a_buffer(4, 1, 32, 4))

    buffer_channel_a_data.io.channel_a_in <> io.channel_a_data
    buffer_channel_a_instruction.io.channel_a_in <> io.channel_a_instruction

    //opsource indicates the which channels request is being addressed
    val op_source = Reg(UInt(sourceBits.W))
    val bitCnt = Reg(UInt(2.W))

    io.channel_a_data.ready     := false.B
    io.channel_a_instruction    := false.B

    buffer_channel_a_data.io.update     := false.B
    buffer_channel_a_instruction.update := false.B

    val channel_inst :: channel_data :: Nil = Enum(2)

    val nextBitCnt = twoBitIncrement(bitCnt)

    val dataBuffer = Reg(Vec(4, UInt (8.W)))

    val size = Reg(UInt(2.W))

    io.memory_channel.read_address  := memAddress
    io.memory_channel.write_address := memAddress

    /*when both instruction and data channel issues a request
    instruction channel is given priority*/
    switch(stateReg){
        is(a_ready){
            //can take requests from instruction channel and data channel
            io.channel_a_data.ready := true.B
            io.channel_a_instruction.ready := true.B
            //buffer requests from instruction and data channels on every channels
            buffer_channel_a_data.io.update := true.B
            buffer_channel_a_instruction.updte := true.B
            when(io.channel_a_instruction.valid){
                //when the instruction channel issues a request
                op_source   := channel_inst
                memAddress  := io.channel_a_instruction.address
                size        := 3.U
                switch(io.channel_a_instruction.opcode){
                    is(channel_a_opcodes.GET){
                        stateReg := data_get_start
                        bitCnt := 0.U
                    }
                }
            }.elsewhen(io.channel_a_data.valid){
                op_source   := channel_data
                memAddress  := io.channel_a_data.address
                switch(io.channel_a_data.size){
                    is(0.U){ size := 0.U }
                    is(1.U){ size := 1.U }
                    is(2.U){ size := 3.U }
                }
                switch(io.channel_a_data.opcode){
                    is(channel_a_opcodes.GET){
                        stateReg := data_get_start
                        bitCnt := 0.U
                    }
                }
            }
        }
        is(data_get_start){
            memAddress  := newMemAddress
            stateReg    := data_get_cont
        }
        is(data_get_cont){
            dataBuffer(memAddress(1, 0))    := io.memory_channel.read_data
            memAddress                      := newMemAddress
            when(bitCnt === size){
                
            }
        }
    }

    val read_base_address := Mux(op_source === channel_inst, io.channel_a_instruction.address, io.channel_a_data.address)

    io.memory_channel.read_address := Cat(read_base_address(31, 2), addrLSBShift(1, 0))
}