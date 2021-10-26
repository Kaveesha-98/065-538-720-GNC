// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VDATA_PATH_H_
#define _VDATA_PATH_H_  // guard

#include "verilated.h"

//==========

class Vdata_path__Syms;
class Vdata_path_VerilatedVcd;


//----------

VL_MODULE(Vdata_path) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(io_RS1,4,0);
    VL_IN8(io_RS2,4,0);
    VL_IN8(io_RD,4,0);
    VL_IN8(io_WRITE_EN,0,0);
    VL_IN8(io_ALU_OP,3,0);
    VL_OUT8(io_EQUAL,0,0);
    VL_OUT8(io_LESS_THAN,0,0);
    VL_OUT8(io_SIGNED_LESS_THAN,0,0);
    VL_IN8(io_CHOOSE_IMMEDIATE,0,0);
    VL_IN8(io_CHOOSE_MEMORY_LOAD,0,0);
    VL_IN8(io_ALU_RD,4,0);
    VL_IN8(io_PROCEDURE_BRANCHING,0,0);
    VL_IN8(io_CHOOSE_PC,0,0);
    VL_OUT(io_store_data,31,0);
    VL_OUT(io_store_address,31,0);
    VL_IN(io_load_data,31,0);
    VL_OUT(io_load_address,31,0);
    VL_IN(io_IMMEDIATE,31,0);
    VL_IN(io_instruction_return_address,31,0);
    VL_OUT(io_instruction_next_address,31,0);
    VL_IN(io_PC,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*0:0*/ data_path__DOT__cpuALU__DOT__EQUAL;
    CData/*0:0*/ data_path__DOT__cpuALU__DOT__LESS_THAN;
    CData/*0:0*/ data_path__DOT__cpuALU__DOT__SIGNED_LESS_THAN;
    IData/*31:0*/ data_path__DOT__registerFile_io_rdData;
    IData/*31:0*/ data_path__DOT__ALU_in1;
    IData/*31:0*/ data_path__DOT__ALU_in2;
    IData/*31:0*/ data_path__DOT__rdData;
    IData/*31:0*/ data_path__DOT__rs2_ALU;
    IData/*31:0*/ data_path__DOT__cpuALU__DOT__ALUoutput;
    IData/*31:0*/ data_path__DOT__cpuALU__DOT___T_3;
    IData/*31:0*/ data_path__DOT__cpuALU__DOT___T_7;
    IData/*31:0*/ data_path__DOT__cpuALU__DOT___GEN_4;
    IData/*31:0*/ data_path__DOT__registerFile__DOT__registerFile_0;
    IData/*31:0*/ data_path__DOT__registerFile__DOT__registerFile_1;
    IData/*31:0*/ data_path__DOT__registerFile__DOT__registerFile_2;
    IData/*31:0*/ data_path__DOT__registerFile__DOT__registerFile_3;
    IData/*31:0*/ data_path__DOT__registerFile__DOT__registerFile_4;
    IData/*31:0*/ data_path__DOT__registerFile__DOT__registerFile_5;
    IData/*31:0*/ data_path__DOT__registerFile__DOT__registerFile_6;
    IData/*31:0*/ data_path__DOT__registerFile__DOT__registerFile_7;
    IData/*31:0*/ data_path__DOT__registerFile__DOT__registerFile_8;
    IData/*31:0*/ data_path__DOT__registerFile__DOT__registerFile_9;
    IData/*31:0*/ data_path__DOT__registerFile__DOT__registerFile_10;
    IData/*31:0*/ data_path__DOT__registerFile__DOT__registerFile_11;
    IData/*31:0*/ data_path__DOT__registerFile__DOT__registerFile_12;
    IData/*31:0*/ data_path__DOT__registerFile__DOT__registerFile_13;
    IData/*31:0*/ data_path__DOT__registerFile__DOT__registerFile_14;
    IData/*31:0*/ data_path__DOT__registerFile__DOT__registerFile_15;
    IData/*31:0*/ data_path__DOT__registerFile__DOT__registerFile_16;
    IData/*31:0*/ data_path__DOT__registerFile__DOT__registerFile_17;
    IData/*31:0*/ data_path__DOT__registerFile__DOT__registerFile_18;
    IData/*31:0*/ data_path__DOT__registerFile__DOT__registerFile_19;
    IData/*31:0*/ data_path__DOT__registerFile__DOT__registerFile_20;
    IData/*31:0*/ data_path__DOT__registerFile__DOT__registerFile_21;
    IData/*31:0*/ data_path__DOT__registerFile__DOT__registerFile_22;
    IData/*31:0*/ data_path__DOT__registerFile__DOT__registerFile_23;
    IData/*31:0*/ data_path__DOT__registerFile__DOT__registerFile_24;
    IData/*31:0*/ data_path__DOT__registerFile__DOT__registerFile_25;
    IData/*31:0*/ data_path__DOT__registerFile__DOT__registerFile_26;
    IData/*31:0*/ data_path__DOT__registerFile__DOT__registerFile_27;
    IData/*31:0*/ data_path__DOT__registerFile__DOT__registerFile_28;
    IData/*31:0*/ data_path__DOT__registerFile__DOT__registerFile_29;
    IData/*31:0*/ data_path__DOT__registerFile__DOT__registerFile_30;
    IData/*31:0*/ data_path__DOT__registerFile__DOT__registerFile_31;
    IData/*31:0*/ data_path__DOT__registerFile__DOT___GEN_21;
    IData/*31:0*/ data_path__DOT__registerFile__DOT___GEN_54;
    QData/*62:0*/ data_path__DOT__cpuALU__DOT___GEN_7;
    QData/*62:0*/ data_path__DOT__cpuALU__DOT___GEN_11;
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__clock;
    IData/*31:0*/ __Vm_traceActivity;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vdata_path__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vdata_path);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vdata_path(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vdata_path();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vdata_path__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vdata_path__Syms* symsp, bool first);
  private:
    static QData _change_request(Vdata_path__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__3(Vdata_path__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vdata_path__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vdata_path__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vdata_path__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__1(Vdata_path__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(Vdata_path__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void traceChgThis(Vdata_path__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__2(Vdata_path__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__3(Vdata_path__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__4(Vdata_path__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceFullThis(Vdata_path__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceFullThis__1(Vdata_path__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis(Vdata_path__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis__1(Vdata_path__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
