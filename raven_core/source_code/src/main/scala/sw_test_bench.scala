import chisel3._
import chisel3.util._
import chisel3.Driver

class sw_testbench_memory_interface(addrWidth: Int) extends Bundle {
    //memory stores 8-bit words
    val read_address = Output(UInt(addrWidth.W))
    val read_data = Input(UInt(8.W))
    val write_address = Output(UInt(addrWidth.W))
    val write_data = Output(UInt(8.W))
    val write_enable = Output(Bool())
}

class sw_testbench_buffer_channel_io(size: Int) extends Bundle {
    val ready       = Output(Bool())
    val bufferData  = Input(UInt(size.W))
    val valid       = Input(Bool())
}

class sw_testbench_buffer_array_memory(regWidth: Int, depth: Int){
    val io = IO(new Bundle{
        val enq = Flipped(new sw_testbench_buffer_channel_io(regWidth))
        val deq = new sw_testbench_buffer_channel_io(regWidth)
    })
    
    val bufferRegisters = new Array[chisel3.UInt](depth)
    val validBits       = new Array[chisel3.Bool](depth)

    for(i <- 0 until depth){
        bufferRegisters(i)  = Reg(UInt(regWidth.W))
        validBits(i)        = RegInit(false.B)
    }

    for(i <- 1 until depth){
        when(!validBits(i)){
            //when the current register empty move data from previous buffer
            validBits(i)        := validBits(i-1)
            bufferRegisters(i)  := bufferRegisters(i-1)
        }
    }

    validBits(0)        := io.enq.valid
    bufferRegisters(0)  := io.enq.bufferData

    io.deq.valid        := validBits(depth - 1)
    io.deq.bufferData   := bufferRegisters(depth - 1)

    //buffer array is not ready only when all buffers are full and deq is no ready 
    io.enq.ready := !Cat(validBits).andR || io.deq.ready
}

class sw_testbench_memory_controller(sourceBits: Int) extends Module {
    val io = IO(new Bundle{
        //contacts only with two masters
        val channel_a_data = Flipped(new channel_a(4, 1, 32, 4))
        val channel_a_instruction = Flipped(new channel_a(4, 1, 32, 4))
        val channel_d_out = new channel_d(4, 1, 1, 4)
        val memory_channel = new sw_testbench_memory_interface(32)
    })

    def nBitWidthIncrement[T <: Data](bitCnt: chisel3.UInt, width: Int): chisel3.UInt = {
        val partialProducts = new Array[chisel3.UInt](width)

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

            nextBitCntArray(i) := Mux(partialProducts(i).asBool, ~bitCnt(i), bitCnt)
        }

        val nextBitCnt = Cat(nextBitCntArray.reverse)
        nextBitCnt
    }

    val channel_a_ready :: memory_fetch :: Nil      = Enum(2)
    val channel_instruction :: channel_data :: Nil  = Enum(2)

    val stateReg    = RegInit(channel_a_ready)
    val msgSource   = RegInit(channel_instruction)

    val channel_a_buffer_instruction    = Reg(new channel_a_signals(4, 1, 32, 4))
    val channel_a_buffer_data           = Reg(new channel_a_signals(4, 1, 32, 4))

    val inst_channel :: data_channel :: Nil = Enum(2)

    val addressBufferArray  = Module(new sw_testbench_buffer_array_memory(32, 2))

    val memAddress = Reg(UInt(32.W))

    io.channel_a_instruction.ready  := false.B
    io.channel_a_data.ready         := false.B

    switch(stateReg){
        is(channel_a_ready){
            io.channel_a_instruction.ready  := true.B
            io.channel_a_data.ready         := true.B
            channel_a_buffer_instruction    := io.channel_a_instruction.signals
            channel_a_buffer_data           := io.channel_a_data.signals
            when(io.channel_a_instruction.valid){
                memAddress  := io.channel_a_instruction.signals.address
                msgSource   := channel_instruction
                switch(io.channel_a_instruction.signals.opcode){
                    is(channel_a_opcodes.GET){
                        stateReg := memory_fetch
                    }
                }
            }
        }
        is(memory_fetch){
            
        }
    }
}