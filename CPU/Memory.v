module Memory(
  input         clock,
  input         reset,
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
