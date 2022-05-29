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

class xilinx6_mig_write_data_port_with_handshake(dataWidth:Int) extends Bundle{

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

        val memWriteInterfaceData = Flipped(new xilinx6_mig_write_data_port_with_handshake(dataWidth))

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
    val idle :: issuingDataBurst1 :: issuingDataBurst2 :: issuingCommand :: Nil = Enum(4)
    val stateReg = RegInit(idle)

    io.mainControlHandShake.ready := stateReg === idle
    io.memWriteInterfaceData.en := stateReg === issuingDataBurst1 || stateReg === issuingDataBurst2
    io.memWriteInterfaceCmd.en := stateReg === issuingCommand

    io.memWriteInterfaceData.access_signals := dataPortAccessSignalsBuffer(0)
    io.memWriteInterfaceCmd.access_signals := commandPortAccessSignalBuffer

    val accessMisaligned = RegInit(false.B)

    switch(stateReg){
        is(idle){
            dataPortAccessSignalsBuffer := decodeDataIssue(io.writeInstructionIn)
            commandPortAccessSignalBuffer := decodeCmdIssue(io.writeInstructionIn)
            
            when(io.mainControlHandShake.valid){
                //only supported for 32bit ports
                stateReg := issuingDataBurst1               
            }
        }
        is(issuingDataBurst1){
            
            when(~io.memWriteInterfaceData.full){
                dataPortAccessSignalsBuffer(0) := dataPortAccessSignalsBuffer(1)
                when(commandPortAccessSignalBuffer.bl === "b000001".U){
                    stateReg := issuingDataBurst2
                }.otherwise{
                    stateReg := issuingCommand
                }
            }
        }
        is(issuingDataBurst2){

            when(~io.memWriteInterfaceData.full){
                stateReg := issuingCommand
            }

        }
        is(issuingCommand){
            when(~io.memWriteInterfaceCmd.full){
                stateReg := idle
            }
        }
    }
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * Module * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

class write_translation_write_assign(addressWidth: Int) extends Module{
    val io = IO(new Bundle{
        val translatingAddress = Input(UInt(addressWidth.W))
        val bufferControls = new write_translation_intra_handshake()

        val memHandshake = Flipped(new write_translation_intra_handshake())
        val ioHandshake = Flipped(new write_translation_intra_handshake())
    })

    val idle :: translatingAddress :: Nil = Enum(2)
    val stateReg = RegInit(idle)

    io.memHandshake.valid := false.B
    io.ioHandshake.valid := false.B

    io.bufferControls.ready := false.B

    switch(stateReg){
        is(idle){
            when(io.bufferControls.valid){
                stateReg := translatingAddress
            }
        }
        is(translatingAddress){
            switch(io.translatingAddress(31, 30)){
                is("b00".U){
                    io.memHandshake.valid := true.B
                    when(io.memHandshake.ready){
                        stateReg := idle
                        io.bufferControls.ready := true.B
                    }
                }
                is("b11".U){
                    io.ioHandshake.valid := true.B
                    when(io.ioHandshake.ready){
                        stateReg := idle
                        io.bufferControls.ready := true.B
                    }
                }
            }
        }
    }
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * Module * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

class write_translation_uart_Tx(addressWidth: Int, sizeWidth: Int, dataWidth: Int, frequency: Int, baudRate: Int) extends Module{
    val io = IO(new Bundle{
        val instructionInput = Input(new write_translation_write_instruction(addressWidth, sizeWidth, dataWidth))
        val mainControlHandShake = new write_translation_intra_handshake()

        val txd = Output(UInt(1.W))
    })
    //supported only for 32-bit data input port
    def decodeByteCount(sizeSignal: chisel3.UInt): chisel3.UInt = {
        val ret = WireInit(0.U(4.W))
        switch(sizeSignal){
            is("b00".U){
                ret := 1.U
            }
            is("b01".U){
                ret := 2.U
            }
            is("b10".U){
                ret := 4.U
            }
        }
        ret
    }

    val dataBuffer = Reg(UInt(dataWidth.W))
    val byteCount = RegInit(0.U(4.W))

    val tx = Module(new Tx(frequency, baudRate))

    tx.io.channel.bits := dataBuffer(7, 0)
    tx.io.channel.valid := byteCount =/= 0.U

    io.mainControlHandShake.ready := byteCount === 0.U

    when(tx.io.channel.ready && byteCount =/= 0.U) {
        byteCount := byteCount - 1.U
        dataBuffer := Cat(dataBuffer(7, 0), dataBuffer(31, 8))
    }.elsewhen(byteCount === 0.U && io.mainControlHandShake.valid){
        dataBuffer := io.instructionInput.hart_data_out
        byteCount := decodeByteCount(io.instructionInput.size)
    }
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * Module * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

class write_translation(addressWidth: Int, sizeWidth: Int, dataWidth: Int, frequency: Int, baudRate: Int) extends Module{
    val io = IO(new Bundle{
        val writeAddressChannel = new write_translation_address_channel(addressWidth, sizeWidth)
        val writeDataChannel    = new write_translation_data_channel(dataWidth)


        val memWriteInterfaceData = Flipped(new xilinx6_mig_write_data_port_with_handshake(dataWidth))

        val memWriteInterfaceCmd = Flipped(new xilinx6_mig_command_data_port_hart_signals())

        val txd = Output(UInt(1.W))
    })

    val uartTx = Module(new write_translation_uart_Tx(addressWidth, sizeWidth, dataWidth, frequency, baudRate))
    val writeAssign = Module(new write_translation_write_assign(addressWidth))
    val memAccess = Module(new write_translation_mem_access(addressWidth, sizeWidth, dataWidth))
    val writeBuffer = Module(new write_translation_write_buffer(addressWidth, sizeWidth, dataWidth))

    writeBuffer.io.writeAddressChannel <> io.writeAddressChannel
    writeBuffer.io.writeDataChannel <> io.writeDataChannel

    memAccess.io.writeInstructionIn := writeBuffer.io.writeInstructionForward

    uartTx.io.instructionInput := writeBuffer.io.writeInstructionForward

    writeAssign.io.translatingAddress := writeBuffer.io.translatingAddress
    writeAssign.io.bufferControls <> writeBuffer.io.mainControlHandShake

    memAccess.io.memWriteInterfaceData <> io.memWriteInterfaceData
    memAccess.io.memWriteInterfaceCmd <> io.memWriteInterfaceCmd

    writeAssign.io.memHandshake <> memAccess.io.mainControlHandShake

    writeAssign.io.ioHandshake <> uartTx.io.mainControlHandShake

}
/* object write_translation_mem_access extends App{

    val addressWidth: Int = 32
    val sizeWidth: Int = 2
    val dataWidth: Int = 32

    (new chisel3.stage.ChiselStage).emitVerilog(new write_translation_mem_access(addressWidth, sizeWidth, dataWidth))
} */