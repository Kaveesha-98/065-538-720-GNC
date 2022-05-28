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

    val hart_data_out = Input(UInt(dataWidth.W))

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
    assert (dataWidth % 8 == 0)

    val data = UInt(dataWidth.W)
    val mask = UInt((dataWidth/8).W)
    val en = Bool()

}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - Bundle - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class xilinx6_mig_write_data_access_signals(dataWidth: Int) extends Bundle{
    //address width must be divisible by 8 for correct mask length
    assert (dataWidth % 8 == 0)

    val data = UInt(dataWidth.W)
    val mask = UInt((dataWidth/8).W)

}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - Bundle - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class xilinx6_mig_write_data_port_hart_signals(dataWidth:Int) extends Bundle{

    val access_signals = Input(new xilinx6_mig_write_data_access_signals(dataWidth))

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

class write_translation_write_buffer(addressWidth:Int, sizeWidth: Int, dataWidth: Int) extends Module{
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
            writeIssueBuffer.hart_data_out := io.writeDataChannel.hart_data_out

            when(io.writeDataChannel.valid){
                bufferState := waitingInstruction
            }
        }
        is(waitingInstruction){
            writeIssueBuffer.address := io.writeAddressChannel.address
            writeIssueBuffer.size := io.writeAddressChannel.size

            when(io.writeAddressChannel.valid){
                bufferState := bufferFull
            }
        }
        is(bufferFull){
            //wait for issue to be translated
            when(io.mainControlHandShake.ready){
                bufferState := waitingData
            }
        }
    }


    io.translatingAddress := writeIssueBuffer.address

    io.writeInstructionForward := writeIssueBuffer

}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * Module * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

class write_translation_mem_access(addressWidth: Int, sizeWidth: Int, dataWidth: Int) extends Module{
    //performs mem write access
    val io = IO(new Bundle{
        val writeInstructionIn = Input(new write_translation_write_instruction(addressWidth, sizeWidth, dataWidth))
        
        val mainControlHandShake = new write_translation_intra_handshake()

        val memWriteInterfaceData = Flipped(new xilinx6_mig_write_data_port_hart_signals(dataWidth))

        val memWriteInterfaceCmd = Flipped(new xilinx6_mig_command_data_port_hart_signals())
    })

    def isRequiringTwoBursts(writeInput: write_translation_write_instruction): chisel3.Bool = {

        val ret = WireInit(false.B)
        switch(writeInput.size(1, 0)){
            is("b01".U){
                ret := writeInput.address(1, 0) === "b11".U
            }
            is("b10".U){
                ret := writeInput.address(1, 0) =/= "b00".U
            }
        }
        ret

    }

    def decodeDataIssue[T <: Data](writeInput: write_translation_write_instruction): chisel3.Vec[xilinx6_mig_write_data_access_signals] = {

        val ret = Wire(Vec(2, new xilinx6_mig_write_data_access_signals(dataWidth)))

        ret(0).data := writeInput.hart_data_out
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
                ret(0).data := Cat(writeInput.hart_data_out(23, 0), "h00".U)
                ret(0).data := Cat("h000000".U, writeInput.hart_data_out(31, 24))

                ret(0).mask := "b0010".U
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
                ret(0).data := Cat(writeInput.hart_data_out(15, 0), "h0000".U)
                ret(0).data := Cat("h0000".U, writeInput.hart_data_out(31, 16))

                ret(0).mask := "b0100".U
                ret(1).mask := "b0000".U

                switch(writeInput.size){
                    is("b01".U){
                        ret(0).mask := "b1100".U
                        ret(1).mask := "b0000".U
                    }
                    is("b10".U){
                        ret(0).mask := "b1100".U
                        ret(1).mask := "b0011".U
                    }
                }

            }
            is("b11".U){
                ret(0).data := Cat(writeInput.hart_data_out(7, 0), "h000000".U)
                ret(0).data := Cat("h00".U, writeInput.hart_data_out(31, 8))

                ret(0).mask := "b1000".U
                ret(1).mask := "b0000".U

                switch(writeInput.size){
                    is("b01".U){
                        ret(0).mask := "b1000".U
                        ret(1).mask := "b0001".U
                    }
                    is("b10".U){
                        ret(0).mask := "b1000".U
                        ret(1).mask := "b0111".U
                    }
                }

            }
        }
        ret

    }

    def decodeCmdIssue[T <: Data](writeInput: write_translation_write_instruction): xilinx6_mig_command_access_signals = {

        val ret = Wire(new xilinx6_mig_command_access_signals())
        ret.addr := Cat(writeInput.address(29, 2), "b00".U)
        ret.bl := Mux(isRequiringTwoBursts(writeInput), "b000001".U, "b000000".U)
        ret.instr := "b000".U
        ret

    }

    val dataPortAccessSignalsBuffer = Reg(Vec(2, new xilinx6_mig_write_data_access_signals(dataWidth)))
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
                dataPortAccessSignalsBuffer := decodeDataIssue(io.writeInstructionIn)
                commandPortAccessSignalBuffer := decodeCmdIssue(io.writeInstructionIn)
                
            }
        }
    }
}

/* object write_translation_mem_access extends App{

    val addressWidth: Int = 32
    val sizeWidth: Int = 2
    val dataWidth: Int = 32

    (new chisel3.stage.ChiselStage).emitVerilog(new write_translation_mem_access(addressWidth, sizeWidth, dataWidth))
} */