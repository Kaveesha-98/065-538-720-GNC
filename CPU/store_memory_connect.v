module Store_Unit(
  input         clock,
  input         reset,
  output [7:0]  io_mem_write_data,
  output [31:0] io_mem_write_address,
  output        io_mem_write,
  output        io_STORE_READY,
  input         io_DATA_IN,
  input  [1:0]  io_STORE_SIZE,
  input         io_ADDRESS_IN,
  input  [31:0] io_store_data,
  input  [31:0] io_store_address
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
  reg [31:0] _RAND_4;
`endif // RANDOMIZE_REG_INIT
  reg [31:0] store_data_buffer; // @[Store_Unit.scala 21:40]
  reg [1:0] store_data_size_buffer; // @[Store_Unit.scala 22:45]
  reg [31:0] store_data_buffer_address; // @[Store_Unit.scala 23:48]
  reg  storing; // @[Store_Unit.scala 25:30]
  reg  stateReg; // @[Store_Unit.scala 28:31]
  wire [7:0] _T_2 = store_data_buffer[7:0]; // @[Store_Unit.scala 36:62]
  wire [31:0] _T_5 = store_data_buffer_address + 32'h1; // @[Store_Unit.scala 39:72]
  wire [1:0] _T_8 = store_data_size_buffer + 2'h1; // @[Store_Unit.scala 44:74]
  wire  _GEN_0 = store_data_size_buffer == 2'h3 ? 1'h0 : stateReg; // @[Store_Unit.scala 40:53 Store_Unit.scala 41:34 Store_Unit.scala 28:31]
  wire  _GEN_1 = store_data_size_buffer == 2'h3 | storing; // @[Store_Unit.scala 40:53 Store_Unit.scala 42:33 Store_Unit.scala 25:30]
  wire [1:0] _GEN_2 = store_data_size_buffer == 2'h3 ? store_data_size_buffer : _T_8; // @[Store_Unit.scala 40:53 Store_Unit.scala 22:45 Store_Unit.scala 44:48]
  wire [31:0] _GEN_6 = ~storing ? {{8'd0}, store_data_buffer[31:8]} : store_data_buffer; // @[Store_Unit.scala 34:34 Store_Unit.scala 38:35 Store_Unit.scala 21:40]
  wire [31:0] _GEN_7 = ~storing ? _T_5 : store_data_buffer_address; // @[Store_Unit.scala 34:34 Store_Unit.scala 39:43 Store_Unit.scala 23:48]
  wire  _GEN_8 = ~storing ? _GEN_0 : stateReg; // @[Store_Unit.scala 34:34 Store_Unit.scala 28:31]
  wire  _GEN_9 = ~storing ? _GEN_1 : storing; // @[Store_Unit.scala 34:34 Store_Unit.scala 25:30]
  wire [1:0] _GEN_10 = ~storing ? _GEN_2 : store_data_size_buffer; // @[Store_Unit.scala 34:34 Store_Unit.scala 22:45]
  wire  _T_9 = ~stateReg; // @[Conditional.scala 37:30]
  wire  _GEN_11 = io_DATA_IN | _GEN_8; // @[Store_Unit.scala 55:49 Store_Unit.scala 56:42]
  wire  _GEN_16 = io_ADDRESS_IN & storing ? 1'h0 : _GEN_9; // @[Store_Unit.scala 63:74 Store_Unit.scala 65:41]
  wire  _GEN_18 = stateReg ? _GEN_16 : _GEN_9; // @[Conditional.scala 39:67]
  wire  _GEN_25 = _T_9 ? _GEN_9 : _GEN_18; // @[Conditional.scala 40:58]
  assign io_mem_write_data = ~storing ? $signed(_T_2) : $signed(8'sh0); // @[Store_Unit.scala 34:34 Store_Unit.scala 36:35 Store_Unit.scala 48:35]
  assign io_mem_write_address = ~storing ? store_data_buffer_address : 32'h0; // @[Store_Unit.scala 34:34 Store_Unit.scala 35:38 Store_Unit.scala 49:38]
  assign io_mem_write = ~storing; // @[Store_Unit.scala 34:22]
  assign io_STORE_READY = _T_9 & io_DATA_IN; // @[Conditional.scala 40:58]
  always @(posedge clock) begin
    if (reset) begin // @[Store_Unit.scala 21:40]
      store_data_buffer <= 32'h0; // @[Store_Unit.scala 21:40]
    end else if (_T_9) begin // @[Conditional.scala 40:58]
      if (io_DATA_IN) begin // @[Store_Unit.scala 55:49]
        store_data_buffer <= io_store_data; // @[Store_Unit.scala 57:51]
      end else begin
        store_data_buffer <= _GEN_6;
      end
    end else begin
      store_data_buffer <= _GEN_6;
    end
    if (reset) begin // @[Store_Unit.scala 22:45]
      store_data_size_buffer <= 2'h0; // @[Store_Unit.scala 22:45]
    end else if (_T_9) begin // @[Conditional.scala 40:58]
      if (io_DATA_IN) begin // @[Store_Unit.scala 55:49]
        store_data_size_buffer <= io_STORE_SIZE; // @[Store_Unit.scala 58:56]
      end else begin
        store_data_size_buffer <= _GEN_10;
      end
    end else begin
      store_data_size_buffer <= _GEN_10;
    end
    if (reset) begin // @[Store_Unit.scala 23:48]
      store_data_buffer_address <= 32'h0; // @[Store_Unit.scala 23:48]
    end else if (_T_9) begin // @[Conditional.scala 40:58]
      store_data_buffer_address <= _GEN_7;
    end else if (stateReg) begin // @[Conditional.scala 39:67]
      if (io_ADDRESS_IN & storing) begin // @[Store_Unit.scala 63:74]
        store_data_buffer_address <= io_store_address; // @[Store_Unit.scala 64:59]
      end else begin
        store_data_buffer_address <= _GEN_7;
      end
    end else begin
      store_data_buffer_address <= _GEN_7;
    end
    storing <= reset | _GEN_25; // @[Store_Unit.scala 25:30 Store_Unit.scala 25:30]
    if (reset) begin // @[Store_Unit.scala 28:31]
      stateReg <= 1'h0; // @[Store_Unit.scala 28:31]
    end else if (_T_9) begin // @[Conditional.scala 40:58]
      stateReg <= _GEN_11;
    end else if (~storing) begin // @[Store_Unit.scala 34:34]
      if (store_data_size_buffer == 2'h3) begin // @[Store_Unit.scala 40:53]
        stateReg <= 1'h0; // @[Store_Unit.scala 41:34]
      end
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  store_data_buffer = _RAND_0[31:0];
  _RAND_1 = {1{`RANDOM}};
  store_data_size_buffer = _RAND_1[1:0];
  _RAND_2 = {1{`RANDOM}};
  store_data_buffer_address = _RAND_2[31:0];
  _RAND_3 = {1{`RANDOM}};
  storing = _RAND_3[0:0];
  _RAND_4 = {1{`RANDOM}};
  stateReg = _RAND_4[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module Memory(
  input         clock,
  input  [31:0] io_rdAddr,
  output [7:0]  io_rdData,
  input         io_mem_write,
  input  [7:0]  io_mem_write_data,
  input  [31:0] io_mem_write_address
);
`ifdef RANDOMIZE_MEM_INIT
  reg [31:0] _RAND_0;
`endif // RANDOMIZE_MEM_INIT
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
`endif // RANDOMIZE_REG_INIT
  reg [7:0] mem [0:1023]; // @[dataMemory.scala 14:26]
  wire [7:0] mem_memData_data; // @[dataMemory.scala 14:26]
  wire [9:0] mem_memData_addr; // @[dataMemory.scala 14:26]
  wire [7:0] mem_MPORT_data; // @[dataMemory.scala 14:26]
  wire [9:0] mem_MPORT_addr; // @[dataMemory.scala 14:26]
  wire  mem_MPORT_mask; // @[dataMemory.scala 14:26]
  wire  mem_MPORT_en; // @[dataMemory.scala 14:26]
  reg [9:0] mem_memData_addr_pipe_0;
  reg [7:0] wrDataReg; // @[dataMemory.scala 16:28]
  reg  doForwardReg; // @[dataMemory.scala 17:31]
  assign mem_memData_addr = mem_memData_addr_pipe_0;
  assign mem_memData_data = mem[mem_memData_addr]; // @[dataMemory.scala 14:26]
  assign mem_MPORT_data = io_mem_write_data;
  assign mem_MPORT_addr = io_mem_write_address[9:0];
  assign mem_MPORT_mask = 1'h1;
  assign mem_MPORT_en = io_mem_write;
  assign io_rdData = doForwardReg ? $signed(wrDataReg) : $signed(mem_memData_data); // @[dataMemory.scala 25:21]
  always @(posedge clock) begin
    if(mem_MPORT_en & mem_MPORT_mask) begin
      mem[mem_MPORT_addr] <= mem_MPORT_data; // @[dataMemory.scala 14:26]
    end
    mem_memData_addr_pipe_0 <= io_rdAddr[9:0];
    wrDataReg <= io_mem_write_data; // @[dataMemory.scala 16:28]
    doForwardReg <= io_mem_write_address == io_rdAddr & io_mem_write; // @[dataMemory.scala 17:67]
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_MEM_INIT
  _RAND_0 = {1{`RANDOM}};
  for (initvar = 0; initvar < 1024; initvar = initvar+1)
    mem[initvar] = _RAND_0[7:0];
`endif // RANDOMIZE_MEM_INIT
`ifdef RANDOMIZE_REG_INIT
  _RAND_1 = {1{`RANDOM}};
  mem_memData_addr_pipe_0 = _RAND_1[9:0];
  _RAND_2 = {1{`RANDOM}};
  wrDataReg = _RAND_2[7:0];
  _RAND_3 = {1{`RANDOM}};
  doForwardReg = _RAND_3[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module store_memory_connect(
  input         clock,
  input         reset,
  input  [31:0] io_rdAddr,
  output [7:0]  io_rdData,
  output        io_STORE_READY,
  input         io_DATA_IN,
  input  [1:0]  io_STORE_SIZE,
  input         io_ADDRESS_IN,
  input  [31:0] io_store_data,
  input  [31:0] io_store_address
);
  wire  storeUnit_clock; // @[store_memory_connect.scala 21:31]
  wire  storeUnit_reset; // @[store_memory_connect.scala 21:31]
  wire [7:0] storeUnit_io_mem_write_data; // @[store_memory_connect.scala 21:31]
  wire [31:0] storeUnit_io_mem_write_address; // @[store_memory_connect.scala 21:31]
  wire  storeUnit_io_mem_write; // @[store_memory_connect.scala 21:31]
  wire  storeUnit_io_STORE_READY; // @[store_memory_connect.scala 21:31]
  wire  storeUnit_io_DATA_IN; // @[store_memory_connect.scala 21:31]
  wire [1:0] storeUnit_io_STORE_SIZE; // @[store_memory_connect.scala 21:31]
  wire  storeUnit_io_ADDRESS_IN; // @[store_memory_connect.scala 21:31]
  wire [31:0] storeUnit_io_store_data; // @[store_memory_connect.scala 21:31]
  wire [31:0] storeUnit_io_store_address; // @[store_memory_connect.scala 21:31]
  wire  dataMemory_clock; // @[store_memory_connect.scala 22:32]
  wire [31:0] dataMemory_io_rdAddr; // @[store_memory_connect.scala 22:32]
  wire [7:0] dataMemory_io_rdData; // @[store_memory_connect.scala 22:32]
  wire  dataMemory_io_mem_write; // @[store_memory_connect.scala 22:32]
  wire [7:0] dataMemory_io_mem_write_data; // @[store_memory_connect.scala 22:32]
  wire [31:0] dataMemory_io_mem_write_address; // @[store_memory_connect.scala 22:32]
  Store_Unit storeUnit ( // @[store_memory_connect.scala 21:31]
    .clock(storeUnit_clock),
    .reset(storeUnit_reset),
    .io_mem_write_data(storeUnit_io_mem_write_data),
    .io_mem_write_address(storeUnit_io_mem_write_address),
    .io_mem_write(storeUnit_io_mem_write),
    .io_STORE_READY(storeUnit_io_STORE_READY),
    .io_DATA_IN(storeUnit_io_DATA_IN),
    .io_STORE_SIZE(storeUnit_io_STORE_SIZE),
    .io_ADDRESS_IN(storeUnit_io_ADDRESS_IN),
    .io_store_data(storeUnit_io_store_data),
    .io_store_address(storeUnit_io_store_address)
  );
  Memory dataMemory ( // @[store_memory_connect.scala 22:32]
    .clock(dataMemory_clock),
    .io_rdAddr(dataMemory_io_rdAddr),
    .io_rdData(dataMemory_io_rdData),
    .io_mem_write(dataMemory_io_mem_write),
    .io_mem_write_data(dataMemory_io_mem_write_data),
    .io_mem_write_address(dataMemory_io_mem_write_address)
  );
  assign io_rdData = dataMemory_io_rdData; // @[store_memory_connect.scala 26:19]
  assign io_STORE_READY = storeUnit_io_STORE_READY; // @[store_memory_connect.scala 29:24]
  assign storeUnit_clock = clock;
  assign storeUnit_reset = reset;
  assign storeUnit_io_DATA_IN = io_DATA_IN; // @[store_memory_connect.scala 30:30]
  assign storeUnit_io_STORE_SIZE = io_STORE_SIZE; // @[store_memory_connect.scala 31:33]
  assign storeUnit_io_ADDRESS_IN = io_ADDRESS_IN; // @[store_memory_connect.scala 32:33]
  assign storeUnit_io_store_data = io_store_data; // @[store_memory_connect.scala 33:33]
  assign storeUnit_io_store_address = io_store_address; // @[store_memory_connect.scala 34:36]
  assign dataMemory_clock = clock;
  assign dataMemory_io_rdAddr = io_rdAddr; // @[store_memory_connect.scala 25:30]
  assign dataMemory_io_mem_write = storeUnit_io_mem_write; // @[store_memory_connect.scala 39:33]
  assign dataMemory_io_mem_write_data = storeUnit_io_mem_write_data; // @[store_memory_connect.scala 37:38]
  assign dataMemory_io_mem_write_address = storeUnit_io_mem_write_address; // @[store_memory_connect.scala 38:41]
endmodule
