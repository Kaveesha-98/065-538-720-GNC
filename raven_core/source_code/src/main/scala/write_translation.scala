/*
This module will translate write issues from hart to io or memory writes
*/

import chisel3._
import chisel3.util._
import chisel3.Driver

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - Bundle - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class write_translation_write_forward_channel extends Bundle{
    //address width must be divisible by 8 for correct mask length

    val address = UInt(32.W)
    val data    = UInt(32.W)
    val size    = UInt(2.W)
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - Bundle - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class xilinx6_mig_write_access_signals extends Bundle{
    
    val count       = Output(UInt(7.W))
    val data        = Input(UInt(32.W))
    val empty       = Output(Bool())
    val en          = Input(Bool())
    val error       = Output(Bool())
    val full        = Output(Bool())
    val mask        = Input(UInt(4.W))
    val underrun    = Output(Bool())

}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - Bundle - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class xilinx6_mig_read_access_signals extends Bundle{

    val en          = Input(Bool())
    val data        = Output(UInt(32.W))
    val full        = Output(Bool())
    val empty       = Output(Bool())
    val count       = Output(UInt(7.W))
    val overflow    = Output(Bool())
    val error       = Output(Bool())

}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - Bundle - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class xilinx6_mig_command_access_signals extends Bundle{

    val addr    = Input(UInt(30.W))
    val bl      = Input(UInt(6.W))
    val empty   = Output(Bool())
    val en      = Input(Bool())
    val error   = Output(Bool())
    val full    = Output(Bool())
    val instr   = Input(UInt(3.W))

}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - Bundle - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class xilinx6_mig_write_only_port extends Bundle{

    val cmd = new xilinx6_mig_command_access_signals()
    val wr  = new xilinx6_mig_write_access_signals()

}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - Bundle - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class RVL extends Bundle{

    val ready = Output(Bool())
    val valid = Input(Bool())

}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - Bundle - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class write_beat extends Bundle{

    val data = UInt(32.W)
    val mask = UInt(4.W)

}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * Module * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

class write_translation_write_buffer extends Module{
    //stores the write issue from hart, then forwards it to memory or io
    val io = IO(new Bundle{
        val writeForwardChannel = Output(new write_translation_write_forward_channel())

        val forwardModuleStatus    = Vec(2, Flipped(new RVL()))

        //write_address channel signals
        val write_address_valid = Input(UInt(1.W))
        val write_address_ready = Output(UInt(1.W))
        val write_address_size = Input(UInt(2.W))
        val write_address = Input(UInt(32.W))
        
        //write_data channel signals
        val write_data_valid = Input(UInt(1.W))
        val write_data_ready = Output(UInt(1.W))
        val store_data = Input(UInt(32.W))
        
    })

    def setProperForwardValid(forwardModuleStatus: chisel3.Vec[RVL], address: chisel3.UInt, forwarding: chisel3.Bool): chisel3.Bool = {

        val forwarded = WireInit(false.B)

        forwardModuleStatus(0).valid := false.B 
        forwardModuleStatus(1).valid := false.B 

        val isIO = address(31, 30) === "b11".U
        val isMem = address(31, 30) === "b00".U

        when(forwarding){
            forwardModuleStatus(0).valid := isMem//mem access
            forwardModuleStatus(1).valid := isIO//io access

            forwarded := (forwardModuleStatus(0).ready && isMem) || (forwardModuleStatus(1).ready && isIO)
        }

        forwarded

    }

    val writeForwardBuffer = Reg(new write_translation_write_forward_channel())

    //states of the buffer
    val waitingData :: waitingAddress :: forwarding :: Nil = Enum(3)
    val bufferState = RegInit(waitingData)

    io.write_address_ready  := bufferState === waitingAddress
    io.write_data_ready     := bufferState === waitingData

    io.writeForwardChannel <> writeForwardBuffer

    val forwarded = setProperForwardValid(io.forwardModuleStatus, writeForwardBuffer.address, bufferState === forwarding)

    switch(bufferState){
        is(waitingData){
            writeForwardBuffer.data := io.store_data

            when(io.write_data_valid.asBool){
                bufferState := waitingAddress
            }
        }
        is(waitingAddress){
            writeForwardBuffer.address := io.write_address
            writeForwardBuffer.size := io.write_address_size

            when(io.write_address_valid.asBool){
                bufferState := forwarding
            }
        }
        is(forwarding){
            //wait for issue to be translated
            when(forwarded){
                bufferState := waitingData
            }
        }
    }

}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * Module * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

class write_translation_mem_access extends Module{
    //performs mem write access
    val io = IO(new Bundle{
        val forwardedWrite = Input(new write_translation_write_forward_channel())
        
        val moduleStatus = new RVL()

        val writePort = Flipped(new xilinx6_mig_write_only_port())
    })

    def getBeats(forwardedWrite: write_translation_write_forward_channel): chisel3.Vec[write_beat]= {

        val beats = Wire(Vec(2, new write_beat()))
        
        val maskMap = Map(0 -> 14, 1 -> 12, 2 -> 0)
        
        val masks = VecInit.tabulate(3)(i => maskMap(i).U(4.W))

        val mask = masks(forwardedWrite.size)

        val alignedData = VecInit.tabulate(4)(i => Cat(Fill(8*(4 - i), "b0".U), forwardedWrite.data, Fill(8*i + 1, "b0".U)))

        val alignedMask = VecInit.tabulate(4)(i => Cat(Fill((4 - i), "b1".U), mask, Fill(i + 1, "b1".U)))

        val shift = forwardedWrite.address(1, 0)

        beats(0).data := alignedData(shift)(32, 1)
        beats(1).data := alignedData(shift)(64, 33)

        beats(0).mask := alignedMask(shift)(4, 1)
        beats(1).mask := alignedMask(shift)(8, 5)

        beats

    }

    def getBurstLength(forwardedWrite: write_translation_write_forward_channel): chisel3.UInt = {

        val need2Beats = WireInit(false.B)

        val shift = forwardedWrite.address(1, 0)

        switch(forwardedWrite.size){
            is("b01".U) { need2Beats := shift === "b11".U}
            is("b10".U) { need2Beats := shift =/= "b00".U}
        }

        need2Beats.asUInt

    }

    val forwardedWriteBuffer = Reg(new write_translation_write_forward_channel())

    val ready :: translate :: writeBufferPush :: cmdBufferPush :: Nil = Enum(4)
    val stateReg = RegInit(ready)

    io.moduleStatus.ready := stateReg === ready

    val presentedBeat = Reg(new write_beat())

    val beats = getBeats(forwardedWriteBuffer)
    val need2Beats = Reg(Bool())
    
    val bursts = getBurstLength(forwardedWriteBuffer)

    io.writePort.cmd.instr  := "b000".U 
    io.writePort.cmd.addr   := Cat(forwardedWriteBuffer.address(29, 2), "b00".U) //natural alignment
    io.writePort.cmd.bl     := bursts

    io.writePort.wr.data := presentedBeat.data
    io.writePort.wr.mask := presentedBeat.mask

    io.writePort.cmd.en := stateReg === cmdBufferPush
    io.writePort.wr.en  := stateReg === writeBufferPush

    switch(stateReg){
        is(ready){
            forwardedWriteBuffer := io.forwardedWrite
            when(io.moduleStatus.valid){
                stateReg := translate
            }
        }
        is(translate){
            need2Beats := bursts === 1.U
            presentedBeat := beats(0)
            stateReg := writeBufferPush
        }
        is(writeBufferPush){
            when(!io.writePort.wr.full){
                presentedBeat := beats(1)
                when(!need2Beats){
                    stateReg := cmdBufferPush
                }.otherwise{
                    need2Beats := false.B
                }
            }
        }
        is(cmdBufferPush){
            when(!io.writePort.cmd.full){
                stateReg := ready
            }
        }
    }

}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * Module * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

class write_translation_uart_Tx extends Module{
    val io = IO(new Bundle{
        val forwardedWrite = Input(new write_translation_write_forward_channel())
        val moduleStatus = new RVL()

        val txChannel = new UartIO()
    })
    //supported only for 32-bit data input port
    def decodeByteCount(size: chisel3.UInt): chisel3.UInt = {
        
        val sizeMap = Map(0 -> 0, 1 -> 1, 2 -> 3)
        val sizeTable = VecInit.tabulate(3)(i => sizeMap(i).U(2.W))
        sizeTable(size)

    }

    val forwardedWriteBuffer = Reg(new write_translation_write_forward_channel())
    val byteCount = RegInit(0.U(2.W))

    val ready :: translate :: transmitting :: Nil = Enum(3)
    val stateReg = RegInit(ready)

    io.txChannel.bits := forwardedWriteBuffer.data(7, 0)
    io.txChannel.valid := stateReg === transmitting

    io.moduleStatus.ready := stateReg === ready

    switch(stateReg){
        is(ready){
            forwardedWriteBuffer := io.forwardedWrite
            when(io.moduleStatus.valid){
                stateReg := translate
            }
        }
        is(translate){
            byteCount := decodeByteCount(forwardedWriteBuffer.size)
            stateReg := transmitting
        }
        is(transmitting){
            when(byteCount === 0.U){
                stateReg := ready
            }.otherwise{
                byteCount := byteCount - 1.U
                forwardedWriteBuffer.data := Cat(0.U(8.W), forwardedWriteBuffer.data(31, 8))
            }
        }
    }

}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * Module * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

class write_translation extends Module{
    val io = IO(new Bundle{
        //write_address channel signals
        val write_address_valid = Input(UInt(1.W))
        val write_address_ready = Output(UInt(1.W))
        val write_address_size = Input(UInt(2.W))
        val write_address = Input(UInt(32.W))
        
        //write_data channel signals
        val write_data_valid = Input(UInt(1.W))
        val write_data_ready = Output(UInt(1.W))
        val store_data = Input(UInt(32.W))

        val writePort = Flipped(new xilinx6_mig_write_only_port())

        val txChannel = new UartIO()
    })

    val uartTx = Module(new write_translation_uart_Tx())
    val memAccess = Module(new write_translation_mem_access())
    val writeBuffer = Module(new write_translation_write_buffer())

    writeBuffer.io.write_address_valid := io.write_address_valid
    io.write_address_ready := writeBuffer.io.write_address_ready
    writeBuffer.io.write_address_size := io.write_address_size
    writeBuffer.io.write_address := io.write_address

    writeBuffer.io.write_data_valid := io.write_data_valid
    io.write_data_ready := writeBuffer.io.write_data_ready
    writeBuffer.io.store_data := io.store_data

    uartTx.io.forwardedWrite := writeBuffer.io.writeForwardChannel
    memAccess.io.forwardedWrite := writeBuffer.io.writeForwardChannel

    writeBuffer.io.forwardModuleStatus(0) <> memAccess.io.moduleStatus
    writeBuffer.io.forwardModuleStatus(1) <> uartTx.io.moduleStatus

    io.txChannel <> uartTx.io.txChannel

    memAccess.io.writePort <> io.writePort

}
object write_translation_mem_access extends App{

    val addressWidth: Int = 32
    val sizeWidth: Int = 2
    val dataWidth: Int = 32

    (new chisel3.stage.ChiselStage).emitVerilog(new write_translation())
}