circuit Store_Unit :
  module Store_Unit :
    input clock : Clock
    input reset : UInt<1>
    output io_mem_write_data : UInt<8>
    output io_mem_write_address : UInt<32>
    output io_mem_write : UInt<1>
    output io_STORE_READY : UInt<1>
    input io_DATA_IN : UInt<1>
    input io_STORE_SIZE : UInt<2>
    input io_ADDRESS_IN : UInt<1>
    input io_store_data : UInt<32>
    input io_store_address : UInt<32>

    reg store_data_buffer : UInt<32>, clock with :
      reset => (UInt<1>("h0"), store_data_buffer) @[Store_Unit.scala 21:40]
    reg store_data_size_buffer : UInt<2>, clock with :
      reset => (UInt<1>("h0"), store_data_size_buffer) @[Store_Unit.scala 22:45]
    reg store_data_buffer_address : UInt<32>, clock with :
      reset => (UInt<1>("h0"), store_data_buffer_address) @[Store_Unit.scala 23:48]
    reg storing : UInt<1>, clock with :
      reset => (UInt<1>("h0"), storing) @[Store_Unit.scala 25:30]
    reg stateReg : UInt<1>, clock with :
      reset => (UInt<1>("h0"), stateReg) @[Store_Unit.scala 28:31]
    node _T = eq(storing, UInt<1>("h0")) @[Store_Unit.scala 34:22]
    node _T_1 = bits(store_data_buffer, 7, 0) @[Store_Unit.scala 36:55]
    node _T_2 = shr(store_data_buffer, 8) @[Store_Unit.scala 38:56]
    node _T_3 = add(store_data_buffer_address, UInt<1>("h1")) @[Store_Unit.scala 39:72]
    node _T_4 = tail(_T_3, 1) @[Store_Unit.scala 39:72]
    node _T_5 = eq(store_data_size_buffer, UInt<2>("h3")) @[Store_Unit.scala 40:45]
    node _T_6 = add(store_data_size_buffer, UInt<1>("h1")) @[Store_Unit.scala 44:74]
    node _T_7 = tail(_T_6, 1) @[Store_Unit.scala 44:74]
    node _GEN_0 = mux(_T_5, UInt<1>("h0"), stateReg) @[Store_Unit.scala 40:53 Store_Unit.scala 41:34 Store_Unit.scala 28:31]
    node _GEN_1 = mux(_T_5, UInt<1>("h1"), storing) @[Store_Unit.scala 40:53 Store_Unit.scala 42:33 Store_Unit.scala 25:30]
    node _GEN_2 = mux(_T_5, store_data_size_buffer, _T_7) @[Store_Unit.scala 40:53 Store_Unit.scala 22:45 Store_Unit.scala 44:48]
    node _GEN_3 = mux(_T, store_data_buffer_address, UInt<1>("h0")) @[Store_Unit.scala 34:34 Store_Unit.scala 35:38 Store_Unit.scala 49:38]
    node _GEN_4 = mux(_T, _T_1, UInt<1>("h0")) @[Store_Unit.scala 34:34 Store_Unit.scala 36:35 Store_Unit.scala 48:35]
    node _GEN_5 = mux(_T, UInt<1>("h1"), UInt<1>("h0")) @[Store_Unit.scala 34:34 Store_Unit.scala 37:30 Store_Unit.scala 50:30]
    node _GEN_6 = mux(_T, _T_2, store_data_buffer) @[Store_Unit.scala 34:34 Store_Unit.scala 38:35 Store_Unit.scala 21:40]
    node _GEN_7 = mux(_T, _T_4, store_data_buffer_address) @[Store_Unit.scala 34:34 Store_Unit.scala 39:43 Store_Unit.scala 23:48]
    node _GEN_8 = mux(_T, _GEN_0, stateReg) @[Store_Unit.scala 34:34 Store_Unit.scala 28:31]
    node _GEN_9 = mux(_T, _GEN_1, storing) @[Store_Unit.scala 34:34 Store_Unit.scala 25:30]
    node _GEN_10 = mux(_T, _GEN_2, store_data_size_buffer) @[Store_Unit.scala 34:34 Store_Unit.scala 22:45]
    node _T_8 = eq(UInt<1>("h0"), stateReg) @[Conditional.scala 37:30]
    node _T_9 = eq(io_DATA_IN, UInt<1>("h1")) @[Store_Unit.scala 55:41]
    node _GEN_11 = mux(_T_9, UInt<1>("h1"), _GEN_8) @[Store_Unit.scala 55:49 Store_Unit.scala 56:42]
    node _GEN_12 = mux(_T_9, io_store_data, _GEN_6) @[Store_Unit.scala 55:49 Store_Unit.scala 57:51]
    node _GEN_13 = mux(_T_9, io_STORE_SIZE, _GEN_10) @[Store_Unit.scala 55:49 Store_Unit.scala 58:56]
    node _GEN_14 = mux(_T_9, UInt<1>("h1"), UInt<1>("h0")) @[Store_Unit.scala 55:49 Store_Unit.scala 59:48 Store_Unit.scala 31:24]
    node _T_10 = eq(UInt<1>("h1"), stateReg) @[Conditional.scala 37:30]
    node _T_11 = eq(io_ADDRESS_IN, UInt<1>("h1")) @[Store_Unit.scala 63:44]
    node _T_12 = eq(storing, UInt<1>("h1")) @[Store_Unit.scala 63:63]
    node _T_13 = and(_T_11, _T_12) @[Store_Unit.scala 63:52]
    node _GEN_15 = mux(_T_13, io_store_address, _GEN_7) @[Store_Unit.scala 63:74 Store_Unit.scala 64:59]
    node _GEN_16 = mux(_T_13, UInt<1>("h0"), _GEN_9) @[Store_Unit.scala 63:74 Store_Unit.scala 65:41]
    node _GEN_17 = mux(_T_10, _GEN_15, _GEN_7) @[Conditional.scala 39:67]
    node _GEN_18 = mux(_T_10, _GEN_16, _GEN_9) @[Conditional.scala 39:67]
    node _GEN_19 = mux(_T_10, UInt<1>("h0"), UInt<1>("h0")) @[Conditional.scala 39:67 Store_Unit.scala 67:40 Store_Unit.scala 31:24]
    node _GEN_20 = mux(_T_8, _GEN_11, _GEN_8) @[Conditional.scala 40:58]
    node _GEN_21 = mux(_T_8, _GEN_12, _GEN_6) @[Conditional.scala 40:58]
    node _GEN_22 = mux(_T_8, _GEN_13, _GEN_10) @[Conditional.scala 40:58]
    node _GEN_23 = mux(_T_8, _GEN_14, _GEN_19) @[Conditional.scala 40:58]
    node _GEN_24 = mux(_T_8, _GEN_7, _GEN_17) @[Conditional.scala 40:58]
    node _GEN_25 = mux(_T_8, _GEN_9, _GEN_18) @[Conditional.scala 40:58]
    io_mem_write_data <= _GEN_4
    io_mem_write_address <= _GEN_3
    io_mem_write <= _GEN_5
    io_STORE_READY <= _GEN_23
    store_data_buffer <= mux(reset, UInt<32>("h0"), _GEN_21) @[Store_Unit.scala 21:40 Store_Unit.scala 21:40]
    store_data_size_buffer <= mux(reset, UInt<2>("h0"), _GEN_22) @[Store_Unit.scala 22:45 Store_Unit.scala 22:45]
    store_data_buffer_address <= mux(reset, UInt<32>("h0"), _GEN_24) @[Store_Unit.scala 23:48 Store_Unit.scala 23:48]
    storing <= mux(reset, UInt<1>("h1"), _GEN_25) @[Store_Unit.scala 25:30 Store_Unit.scala 25:30]
    stateReg <= mux(reset, UInt<1>("h0"), _GEN_20) @[Store_Unit.scala 28:31 Store_Unit.scala 28:31]