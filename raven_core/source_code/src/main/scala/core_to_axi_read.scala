/* 
Core to axi translation for core reads
 */

import chisel3._
import chisel3.util._
import chisel3.Driver

class xilinx6_mig_read_only_port extends Bundle{

    val cmd = new xilinx6_mig_command_access_signals()
    val rd  = new xilinx6_mig_read_access_signals()

}

case class core_to_axi_core_read(address: chisel3.UInt, size: chisel3.UInt) extends Bundle

class core_to_axi extends Module{
    val io = IO(new Bundle{

        val readPort = Flipped(new xilinx6_mig_read_only_port())

        //load_address channel signals
        val load_address_ready = Output(UInt(1.W))
        val load_address_valid = Input(UInt(1.W))
        val load_address_size = Input(UInt(2.W))
        val load_address = Input(UInt(32.W))
        
        //load_data channel signals
        val load_data_valid = Output(UInt(1.W))
        val load_data_ready = Input(UInt(1.W))
        val load_data = Output(UInt(32.W))

    })

    def beatCount(request: core_to_axi_core_read): chisel3.UInt = {

        val burstLength = WireInit(0.U(6.W))

        val alignShift = request.address(1, 0)

        val need2Beats = (alignShift === 3.U && request.size === 1.U) || (alignShift =/= 0.U && request.size === 2.U)

        burstLength := Mux(need2Beats, 1.U, 0.U)

        burstLength

    }

    def getLowerBytes(request: core_to_axi_core_read, readData: chisel3.UInt): chisel3.UInt = {

        val lowerBytes = VecInit.tabulate(4)(i => if (i == 0) readData else Cat(Fill(8*i, 0.U(1.W)), readData(31, 8*i)))

        lowerBytes(request.address(1, 0))

    }

    def getUpperBytes(request: core_to_axi_core_read, readData: chisel3.UInt, lowerBytes: chisel3.UInt): chisel3.UInt = {

        val finalLoadData = VecInit.tabulate(4)(i => if (i == 0) lowerBytes else Cat(readData(8*i - 1, 0), lowerBytes(8*(4 - i) - 1, 0)))

        finalLoadData(request.address(1, 0))

    }

    val coreReadBuffer = Reg(new core_to_axi_core_read(UInt(32.W), UInt(2.W)))

    val idle :: translate :: issueRead :: readData :: presentData :: Nil = Enum(5)

    val stateReg = RegInit(idle)

    val burstCount = Reg(UInt(6.W))

    val loadData = Reg(UInt(32.W))

    io.load_address_ready := (stateReg === idle).asUInt

    io.readPort.cmd.instr := "b001".U
    io.readPort.cmd.addr  := Cat(coreReadBuffer.address(29, 2), 0.U(2.W))
    io.readPort.cmd.bl    := burstCount

    io.readPort.cmd.en := stateReg === issueRead
    io.readPort.rd.en  := stateReg === readData

    io.load_data := loadData

    io.load_data_valid := (stateReg === presentData).asUInt

    switch(stateReg){
        is(idle){
            coreReadBuffer.address  := io.load_address
            coreReadBuffer.size     := io.load_address_size
            when(io.load_address_valid.asBool){
                stateReg := translate
            }
        }
        is(translate){
            burstCount := beatCount(coreReadBuffer)
        }
        is(issueRead){
            when(~io.readPort.cmd.full){
                stateReg := readData
            }
        }
        is(readData){
            when(beatCount(coreReadBuffer) === burstCount){
                loadData := getLowerBytes(coreReadBuffer, io.readPort.rd.data)
            }.otherwise{
                loadData := getUpperBytes(coreReadBuffer, io.readPort.rd.data, loadData)
            }
            when(~io.readPort.rd.empty){
                when(burstCount === 0.U){
                    stateReg := presentData
                }.otherwise{
                    burstCount := 0.U
                }
            }
        }
        is(presentData){
            when(io.load_address_ready.asBool){
                stateReg := idle
            }
        }
    }

}

object core_to_axi extends App{

    val addressWidth: Int = 32
    val sizeWidth: Int = 2
    val dataWidth: Int = 32

    (new chisel3.stage.ChiselStage).emitVerilog(new core_to_axi())
}