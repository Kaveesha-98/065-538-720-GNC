;buildInfoPackage: chisel3, version: 3.4.1, scalaVersion: 2.12.12, sbtVersion: 1.3.10
circuit Memory : 
  module Memory : 
    input clock : Clock
    input reset : UInt<1>
    output io : {flip rdAddr : UInt<32>, rdData : SInt<8>, flip mem_write : UInt<1>, flip mem_write_data : SInt<8>, flip mem_write_address : UInt<32>}
    
    smem mem : SInt<8>[1024], undefined @[dataMemory.scala 14:26]
    reg wrDataReg : SInt, clock @[dataMemory.scala 16:28]
    wrDataReg <= io.mem_write_data @[dataMemory.scala 16:28]
    node _T = eq(io.mem_write_address, io.rdAddr) @[dataMemory.scala 17:53]
    node _T_1 = eq(io.mem_write, UInt<1>("h01")) @[dataMemory.scala 17:83]
    node _T_2 = and(_T, _T_1) @[dataMemory.scala 17:67]
    reg doForwardReg : UInt<1>, clock @[dataMemory.scala 17:31]
    doForwardReg <= _T_2 @[dataMemory.scala 17:31]
    node _T_3 = bits(io.rdAddr, 9, 0) @[dataMemory.scala 19:27]
    read mport memData = mem[_T_3], clock @[dataMemory.scala 19:27]
    node _T_4 = eq(io.mem_write, UInt<1>("h01")) @[dataMemory.scala 21:23]
    when _T_4 : @[dataMemory.scala 21:31]
      node _T_5 = bits(io.mem_write_address, 9, 0)
      write mport MPORT = mem[_T_5], clock
      MPORT <= io.mem_write_data
      skip @[dataMemory.scala 21:31]
    node _T_6 = mux(doForwardReg, wrDataReg, memData) @[dataMemory.scala 25:21]
    io.rdData <= _T_6 @[dataMemory.scala 25:15]
    
