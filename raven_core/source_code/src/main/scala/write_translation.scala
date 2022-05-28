/*
This module will translate write issues from hart to io or memory writes
*/

import chisel3._
import chisel3.util._
import chisel3.Driver

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - Bundle - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class write_translation_address_channel(addressWidth: Int, sizeWidth: Int) extends Bundle{
    //input to write translation module

    val address = Input(UInt(addressWidth.W))
    val size    = Input(UInt(sizeWidth.W))//

    //handshake signals
    val valid   = Input(Bool())
    val ready   = Output(Bool())

}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - Bundle - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class write_translation_data_channel(dataWidth: Int) extends Bundle{
    //input to write translation module

    val hart_data_out = Input(UInt(dataWidth))

    //handshake signals
    val valid = Input(Bool())
    val ready = Output(Bool())

}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - Bundle - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class write_translation_write_instruction(addressWidth:Int, sizeWidth: Int, dataWidth:Int) extends Bundle{
    //Stores data needed to carry memory write access
    //Used to create buffers for memory access issue
    //Used to forward write issues to memory or io

    val address = UInt(addressWidth.W)
    val size    = UInt(sizeWidth.W)
    val hart_data_out = UInt(dataWidth.W)
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - Bundle - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class write_translation_intra_handshake() extends Bundle{
    val valid = Input(Bool())
    val ready = Output(Bool())
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - Bundle - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class write_translation_mem_write_interface_data(dataWidth: Int) extends Bundle{
    //address width must be divisible by 8 for correct mask length
    assert (addressWidth % 8 == 0)

    val data = UInt(addressWidth.W)
    val mask = UInt((addressWidth/8).W)
    val en = Bool()

}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - Bundle - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class xilinx6_mig_write_data_access_signals(dataWidth: Int) extends Bundle{
    //address width must be divisible by 8 for correct mask length
    assert (addressWidth % 8 == 0)

    val data = UInt(addressWidth.W)
    val mask = UInt((addressWidth/8).W)

}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - Bundle - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class xilinx6_mig_write_data_port_hart_signals(dataWidth:Int) extends Bundle{

    val access_signals = Input(new xilinx_mig_write_data_access_signals(dataWidth))

    val en = Input(Bool())
    val full = Output(Bool())

}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - Bundle - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class xilinx6_mig_command_access_signals() extends Bundle{

    val addr = UInt(30.W)
    val instr = UInt(3.W)
    val bl = UInt(6.W)

}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - Bundle - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class xilinx6_mig_command_data_port_hart_signals() extends Bundle{

    val access_signals = Input(new xilinx6_mig_command_access_signals())

    val en = Input(Bool())
    val full = Output(Bool())

}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * Module * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

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

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * Module * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

Class write_translation_mem_access(addressWidth: Int, sizeWidth: Int, dataWidth: Int) extends Module{
    //performs mem write access
    val io = IO(new Bundle{
        val writeInstructionIn = Input(new write_translation_write_instruction(addressWidth, sizeWidth, dataWidth))
        
        val mainControlHandShake = new write_translation_intra_handshake()

        val memWriteInterfaceData = Flipped(new xilinx6_mig_write_data_port_hart_signals(dataWidth))

        val memWriteInterfaceCmd = Flipped(new xilinx6_mig_command_data_port_hart_signals())
    })

    def checkMemAlignment(writeInput: write_translation_write_instruction): Chisel3.Bool = {

        val ret := WireInit(Bool(false.B))
        switch(writeInput.size(1, 0)){
            is("b01".U){
                ret := writeInput.address(0) =/= "b0".U
            }
            is("b10".U){
                ret := writeInput.address(1, 0) =/= "b00".U
            }
        }
        ret

    }

    def decodeDataIssue[T <: Data](writeInput: write_translation_write_instruction): T = {

        val ret = Wire(Vec(2, xilinx6_mig_write_data_access_signals(dataWidth)))

        ret(0).data := writeInput.data
        ret(1).data := 0.U

        ret(0).mask := "b0001".U
        ret(1).mask := "b0000".U

        switch(writeInput.size){
            is("b01".U){
                ret(0).mask := "b0011".U
                ret(1).mask := "b0000".U
            }
            is("b10".U){
                ret(0).mask := "b1111".U
                ret(1).mask := "b0000".U
            }
        }

        switch(writeInput.address(1, 0)){
            is("b01".U){
                ret(0).data := Cat(writeInput.data(23, 0), "h00".U)
                ret(0).data := Cat("h000000".U, writeInput.data(31, 24))

                ret(0).mask := "b0001".U
                ret(1).mask := "b0000".U

                switch(writeInput.size){
                    is("b01".U){
                        ret(0).mask := "b0110".U
                        ret(1).mask := "b0000".U
                    }
                    is("b10".U){
                        ret(0).mask := "b1110".U
                        ret(1).mask := "b0001".U
                    }
                }

            }
            is("b10".U){
                ret(0).data := Cat(writeInput.data(15, 0), "h0000".U)
                ret(0).data := Cat("h0000".U, writeInput.data(31, 16))

                switch(writeInput.size){
                    is("b01".U){
                        ret(0).mask := "b1100".U
                        ret(1).mask := "b0000".U
                    }
                    is("b10".U){
                        ret(0).mask := "b1110".U
                        ret(1).mask := "b0001".U
                    }
                }

            }
            is("b11".U){
                ret(0).data := Cat(writeInput.data(7, 0), "h000000".U)
                ret(0).data := Cat("h00".U, writeInput.data(31, 8))
            }
        }
        ret(0).mask := 0.U
        ret(1).mask := 0.U


    }

    val dataPortAccessSignalsBuffer = Reg(Vec(2, xilinx6_mig_write_data_access_signals(dataWidth)))
    val commandPortAccessSignalBuffer = Reg(new xilinx6_mig_command_access_signals())

    //states of the module
    val idle :: issuingData :: issuingCommand :: Nil = Enum(3)
    val stateReg = RegInit(idle)

    io.mainControlHandShake.ready := stateReg === idle

    val accessMisaligned = RegInit(Bool())

    switch(stateReg){
        is(idle){
            when(io.mainControlHandShake.valid){
                //only supported for 32bit ports
                commandPortAccessSignalBuffer.addr := Cat(io.writeInstructionForward.address(29, 2), "b00")
                commandPortAccessSignalBuffer.instr := "b000".U
                //setting burst length - misaligned access "b001".U else "b000000".U
                commandPortAccessSignalBuffer.bl := "b000000".U
                switch(io.writeInstructionIn.size(1, 0)){
                    is("b01".U){
                        commandPortAccessSignalBuffer.bl := Mux()
                    }
                }
            }
        }
    }
}