/*
This module will translate write issues from hart to io or memory writes
*/

import chisel3._
import chisel3.util._
import chisel3.Driver

class write_translation_address_channel(addressWidth: Int, sizeWidth: Int) extends Bundle{
    //input to write translation module

    val address = Input(UInt(addressWidth.W))
    val size    = Input(UInt(sizeWidth.W))//

    //handshake signals
    val valid   = Input(Bool())
    val ready   = Output(Bool())

}

class write_translation_data_channel(dataWidth: Int) extends Bundle{
    //input to write translation module

    val hart_data_out = Input(UInt(dataWidth))

    //handshake signals
    val valid = Input(Bool())
    val ready = Output(Bool())

}

class write_translation_write_instruction(addressWidth:Int, sizeWidth: Int, dataWidth:Int) extends Bundle{
    //Stores data needed to carry memory write access
    //Used to create buffers for memory access issue
    //Used to forward write issues to memory or io

    val address = UInt(addressWidth.W)
    val size    = UInt(sizeWidth.W)
    val hart_data_out = UInt(dataWidth.W)
}

class write_translation_intra_handshake() extends Bundle{
    val valid = Input(Bool())
    val ready = Output(Bool())
}

class write_translation_mem_write_interface(addressWidth: Int){
    //address width must be divisible by 8 for correct mask length
    assert (addressWidth % 8 == 0)

    val address = UInt(addressWidth.W)
    val mask = UInt((addressWidth/8).W)
    val en = Bool()

}

class write_translation_write_buffer(addressWidth:Int, sizeWidth: Int, dataWidth) extends Module{
    //stores the write issue from hart, then forwards it to memory or io
    val io = IO(new Bundle{
        val writeAddressChannel = new write_translation_address_channel(addressWidth, sizeWidth)
        val writeDataChannel    = new write_translation_data_channel(dataWidth)
        val writeInstructionForward = Output(new write_translation_write_instruction(addressWidth, sizeWidth, dataWidth))

        val translatingAddress = Output(UInt(32.W))

        val mainControlHandShake = Flipped(new write_translation_intra_handshake())
    })

    val writeIssueBuffer = Reg(new write_translation_write_instruction(addressWidth, sizeWidth, dataWidth))

    //states of the buffer
    val waitingData :: waitingInstruction :: bufferFull :: Nil = Enum(3)
    val bufferState = RegInit(waitingData)

    io.writeAddressChannel.ready := bufferState === waitingInstruction
    io.writeDataChannel.ready := bufferState === waitingData

    io.mainControlHandShake.valid := bufferState === bufferFull

    switch(bufferState){
        is(waitingData){
            writeIssueBuffer.hart_data_out := writeDataChannel.hart_data_out

            when(writeDataChannel.valid){
                bufferState := waitingInstruction
            }
        }
        is(waitingInstruction){
            writeIssueBuffer.address := io.writeAddressChannel.address
            writeIssueBuffer.size := io.writeAddressChannel.size

            when(writeAddressChannel.valid){
                bufferState := bufferFull
            }
        }
        is(bufferFull){
            //wait for issue to be translated
            when(mainControlHandShake.ready){
                bufferState := waitingData
            }
        }
    }


    io.translatingAddress := writeIssueBuffer.address

    io.writeInstructionForward := writeIssueBuffer

}

Class write_translation_mem_access(addressWidth: Int, sizeWidth: Int, dataWidth: Int) extends Module{
    //performs mem write access
    val io = IO(new Bundle{
        val writeInstructionIn = Input(new write_translation_write_instruction(addressWidth, sizeWidth, dataWidth))
        
        val mainControlHandShake = new write_translation_intra_handshake()

        val memWriteInterface = Output(new write_translation_mem_access(addressWidth))
        val memWriteBufferFull = Input(Bool()) 
    })
}