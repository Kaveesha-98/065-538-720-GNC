;buildInfoPackage: chisel3, version: 3.4.1, scalaVersion: 2.12.12, sbtVersion: 1.3.10
circuit store_memory_connect : 
  module Store_Unit : 
    input clock : Clock
    input reset : Reset
    output io : {mem_write_data : SInt<8>, mem_write_address : UInt<32>, mem_write : UInt<1>, STORE_READY : UInt<1>, flip DATA_IN : UInt<1>, flip STORE_SIZE : UInt<2>, flip ADDRESS_IN : UInt<1>, flip store_data : SInt<32>, flip store_address : UInt<32>}
    
    reg store_data_buffer : UInt<32>, clock with : (reset => (reset, UInt<32>("h00"))) @[Store_Unit.scala 21:40]
    reg store_data_size_buffer : UInt<2>, clock with : (reset => (reset, UInt<2>("h00"))) @[Store_Unit.scala 22:45]
    reg store_data_buffer_address : UInt<32>, clock with : (reset => (reset, UInt<32>("h00"))) @[Store_Unit.scala 23:48]
    reg storing : UInt<1>, clock with : (reset => (reset, UInt<1>("h01"))) @[Store_Unit.scala 25:30]
    reg stateReg : UInt<1>, clock with : (reset => (reset, UInt<1>("h00"))) @[Store_Unit.scala 28:31]
    io.mem_write_data <= asSInt(UInt<1>("h00")) @[Store_Unit.scala 30:27]
    io.STORE_READY <= UInt<1>("h00") @[Store_Unit.scala 31:24]
    node _T = eq(storing, UInt<1>("h00")) @[Store_Unit.scala 34:22]
    when _T : @[Store_Unit.scala 34:34]
      io.mem_write_address <= store_data_buffer_address @[Store_Unit.scala 35:38]
      node _T_1 = bits(store_data_buffer, 7, 0) @[Store_Unit.scala 36:55]
      node _T_2 = asSInt(_T_1) @[Store_Unit.scala 36:62]
      io.mem_write_data <= _T_2 @[Store_Unit.scala 36:35]
      io.mem_write <= UInt<1>("h01") @[Store_Unit.scala 37:30]
      node _T_3 = shr(store_data_buffer, 8) @[Store_Unit.scala 38:56]
      store_data_buffer <= _T_3 @[Store_Unit.scala 38:35]
      node _T_4 = add(store_data_buffer_address, UInt<1>("h01")) @[Store_Unit.scala 39:72]
      node _T_5 = tail(_T_4, 1) @[Store_Unit.scala 39:72]
      store_data_buffer_address <= _T_5 @[Store_Unit.scala 39:43]
      node _T_6 = eq(store_data_size_buffer, UInt<2>("h03")) @[Store_Unit.scala 40:45]
      when _T_6 : @[Store_Unit.scala 40:53]
        stateReg <= UInt<1>("h00") @[Store_Unit.scala 41:34]
        storing <= UInt<1>("h01") @[Store_Unit.scala 42:33]
        skip @[Store_Unit.scala 40:53]
      else : @[Store_Unit.scala 43:18]
        node _T_7 = add(store_data_size_buffer, UInt<1>("h01")) @[Store_Unit.scala 44:74]
        node _T_8 = tail(_T_7, 1) @[Store_Unit.scala 44:74]
        store_data_size_buffer <= _T_8 @[Store_Unit.scala 44:48]
        skip @[Store_Unit.scala 43:18]
      skip @[Store_Unit.scala 34:34]
    else : @[Store_Unit.scala 47:10]
      io.mem_write_data <= asSInt(UInt<1>("h00")) @[Store_Unit.scala 48:35]
      io.mem_write_address <= UInt<1>("h00") @[Store_Unit.scala 49:38]
      io.mem_write <= UInt<1>("h00") @[Store_Unit.scala 50:30]
      skip @[Store_Unit.scala 47:10]
    node _T_9 = eq(UInt<1>("h00"), stateReg) @[Conditional.scala 37:30]
    when _T_9 : @[Conditional.scala 40:58]
      node _T_10 = eq(io.DATA_IN, UInt<1>("h01")) @[Store_Unit.scala 55:41]
      when _T_10 : @[Store_Unit.scala 55:49]
        stateReg <= UInt<1>("h01") @[Store_Unit.scala 56:42]
        node _T_11 = asUInt(io.store_data) @[Store_Unit.scala 57:68]
        store_data_buffer <= _T_11 @[Store_Unit.scala 57:51]
        store_data_size_buffer <= io.STORE_SIZE @[Store_Unit.scala 58:56]
        io.STORE_READY <= UInt<1>("h01") @[Store_Unit.scala 59:48]
        skip @[Store_Unit.scala 55:49]
      skip @[Conditional.scala 40:58]
    else : @[Conditional.scala 39:67]
      node _T_12 = eq(UInt<1>("h01"), stateReg) @[Conditional.scala 37:30]
      when _T_12 : @[Conditional.scala 39:67]
        node _T_13 = eq(io.ADDRESS_IN, UInt<1>("h01")) @[Store_Unit.scala 63:44]
        node _T_14 = eq(storing, UInt<1>("h01")) @[Store_Unit.scala 63:63]
        node _T_15 = and(_T_13, _T_14) @[Store_Unit.scala 63:52]
        when _T_15 : @[Store_Unit.scala 63:74]
          store_data_buffer_address <= io.store_address @[Store_Unit.scala 64:59]
          storing <= UInt<1>("h00") @[Store_Unit.scala 65:41]
          skip @[Store_Unit.scala 63:74]
        io.STORE_READY <= UInt<1>("h00") @[Store_Unit.scala 67:40]
        skip @[Conditional.scala 39:67]
    
  module Memory : 
    input clock : Clock
    input reset : Reset
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
    
  module store_memory_connect : 
    input clock : Clock
    input reset : UInt<1>
    output io : {flip rdAddr : UInt<32>, rdData : SInt<8>, STORE_READY : UInt<1>, flip DATA_IN : UInt<1>, flip STORE_SIZE : UInt<2>, flip ADDRESS_IN : UInt<1>, flip store_data : SInt<32>, flip store_address : UInt<32>}
    
    inst storeUnit of Store_Unit @[store_memory_connect.scala 21:31]
    storeUnit.clock <= clock
    storeUnit.reset <= reset
    inst dataMemory of Memory @[store_memory_connect.scala 22:32]
    dataMemory.clock <= clock
    dataMemory.reset <= reset
    dataMemory.io.rdAddr <= io.rdAddr @[store_memory_connect.scala 25:30]
    io.rdData <= dataMemory.io.rdData @[store_memory_connect.scala 26:19]
    io.STORE_READY <= storeUnit.io.STORE_READY @[store_memory_connect.scala 29:24]
    storeUnit.io.DATA_IN <= io.DATA_IN @[store_memory_connect.scala 30:30]
    storeUnit.io.STORE_SIZE <= io.STORE_SIZE @[store_memory_connect.scala 31:33]
    storeUnit.io.ADDRESS_IN <= io.ADDRESS_IN @[store_memory_connect.scala 32:33]
    storeUnit.io.store_data <= io.store_data @[store_memory_connect.scala 33:33]
    storeUnit.io.store_address <= io.store_address @[store_memory_connect.scala 34:36]
    dataMemory.io.mem_write_data <= storeUnit.io.mem_write_data @[store_memory_connect.scala 37:38]
    dataMemory.io.mem_write_address <= storeUnit.io.mem_write_address @[store_memory_connect.scala 38:41]
    dataMemory.io.mem_write <= storeUnit.io.mem_write @[store_memory_connect.scala 39:33]
    
