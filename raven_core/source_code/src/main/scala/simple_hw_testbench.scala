//simple test bench to test raven_core
//no ddr memory
//no data memory(loads and stores to memory not possible)
//instructions loaded via UART

import chisel3._
import chisel3.util._
import chisel3.Driver

import scala.io.Source 

class simple_hw_testBench(uartFrequency: Int, uartBaudRate: Int, instructionCount: Int, fpgaTesting: Boolean, uartOut: Boolean) extends Module{
    val io = IO(new Bundle{
        val rxd = Input(UInt(1.W))
        
        val startProgram = Input(Bool())

        val txd = Output(UInt((if (uartOut) 1 else 8).W))
        //for hardware implementations Led is used for debugging purposes
        //for chisel testing Led is used for hart_outs
        val Led = Output(UInt((if (uartOut) 8 else 1).W))
        //for hardware implementations sw is used for debugging purposes
        //for chisel testing sw is used for hart_in
        val sw = Input(UInt((if (uartOut) 7 else 1).W))
    })

    val instructionMemory = if (fpgaTesting) Reg(Vec(instructionCount, UInt(32.W))) else WireInit(VecInit(Seq.fill(instructionCount)(0.U(32.W))))

    if (fpgaTesting){
        //val instructionMemory = Reg(Vec(instructionCount, UInt(32.W)))
        
        //Release a byte at a time
        val uartRecieveInstructions = Module(new Rx(uartFrequency, uartBaudRate))

        uartRecieveInstructions.io.rxd := io.rxd
        
        //Bytes will be buffered to form one instruction
        val newInstruction = RegInit(0.U(32.W))
        //For waiting 4 bytes before storing recieved instruction
        val instructionBitCount = RegInit(0.U(6.W))

        //cannot recive instruction byte until fully formed instruction is stored
        val instructionIncomplete = instructionBitCount =/= 32.U
        uartRecieveInstructions.io.channel.ready := instructionIncomplete

        val newInstructionAddress = RegInit(0.U(32.W))

        when(uartRecieveInstructions.io.channel.valid && instructionIncomplete){
            instructionBitCount    := instructionBitCount + 1.U 
            newInstruction          := Cat((uartRecieveInstructions.io.channel.bits === '1'.U).asUInt, newInstruction(31, 1))
        }.elsewhen(~instructionIncomplete){
            instructionMemory(newInstructionAddress) := newInstruction
            //for next instruction
            instructionBitCount    := 0.U
            newInstructionAddress   := newInstructionAddress + 1.U
        }
    } else {
        //val instructionMemory = Wire(Vec(instructionCount, UInt(32.W)))

        //loading instructions
        val fname = "test_instructions.txt"
        val fSource = Source.fromFile(fname) 
        var i: Int = 0
        var textInstruction: String = "12"
        for(line<-fSource.getLines)
        { 
            instructionMemory(i) := ("b" + line).U 
            i += 1
        } 
        fSource.close()


    }

    val ravenHartCore = Module(new raven_core_hart())


    //write address channel does not matter, as write port is only connected to tx
    ravenHartCore.io.write_address_ready := 1.U

    ravenHartCore.io.load_address_ready := 1.U

    ravenHartCore.io.load_data_valid := 1.U
    ravenHartCore.io.load_data := 0.U 

    ravenHartCore.io.fetch_PC := ravenHartCore.io.valid_PC
    ravenHartCore.io.fetch_valid := ravenHartCore.io.ready & io.startProgram.asUInt
    ravenHartCore.io.instruction := instructionMemory(ravenHartCore.io.valid_PC(31, 2))

    if(uartOut){
        val tx = Module(new BufferedTx(uartFrequency, uartBaudRate))
        io.txd := tx.io.txd

        //connecting transmitter to hart write channel
        tx.io.channel.bits := ravenHartCore.io.store_data(7,0)
        tx.io.channel.valid := ravenHartCore.io.write_data_valid.asBool
        ravenHartCore.io.write_data_ready := tx.io.channel.ready.asUInt
        
        val memOut = instructionMemory(io.sw(6, 2))
        val ledOut = WireInit(memOut(7, 0))

        switch(io.sw(1, 0)){
            is("b01".U){
                ledOut := memOut(15, 8)
            }
            is("b10".U){
                ledOut := memOut(23, 16)
            }
            is("b11".U){
                ledOut := memOut(31, 24)
            }
        }

        io.Led := ledOut
    }else{
        io.txd := ravenHartCore.io.store_data(7, 0)

        io.Led := ravenHartCore.io.write_data_valid

        ravenHartCore.io.write_data_ready := io.sw
    }
}

object simple_hw_testBench extends App{

    val uartFrequency: Int = 100000000
    val uartBaudRate: Int = 115200
    val instructionCount: Int = 16
    val fpgaTesting: Boolean = false
    val uartOut: Boolean = true

    (new chisel3.stage.ChiselStage).emitVerilog(new simple_hw_testBench(uartFrequency, 
    uartBaudRate, instructionCount, fpgaTesting, uartOut))
}