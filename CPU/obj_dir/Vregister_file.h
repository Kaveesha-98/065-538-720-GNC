// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VREGISTER_FILE_H_
#define _VREGISTER_FILE_H_  // guard

#include "verilated.h"

//==========

class Vregister_file__Syms;
class Vregister_file_VerilatedVcd;


//----------

VL_MODULE(Vregister_file) {
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
    VL_OUT(io_rs1Data,31,0);
    VL_OUT(io_rs2Data,31,0);
    VL_IN(io_rdData,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    IData/*31:0*/ register_file__DOT__registerFile_0;
    IData/*31:0*/ register_file__DOT__registerFile_1;
    IData/*31:0*/ register_file__DOT__registerFile_2;
    IData/*31:0*/ register_file__DOT__registerFile_3;
    IData/*31:0*/ register_file__DOT__registerFile_4;
    IData/*31:0*/ register_file__DOT__registerFile_5;
    IData/*31:0*/ register_file__DOT__registerFile_6;
    IData/*31:0*/ register_file__DOT__registerFile_7;
    IData/*31:0*/ register_file__DOT__registerFile_8;
    IData/*31:0*/ register_file__DOT__registerFile_9;
    IData/*31:0*/ register_file__DOT__registerFile_10;
    IData/*31:0*/ register_file__DOT__registerFile_11;
    IData/*31:0*/ register_file__DOT__registerFile_12;
    IData/*31:0*/ register_file__DOT__registerFile_13;
    IData/*31:0*/ register_file__DOT__registerFile_14;
    IData/*31:0*/ register_file__DOT__registerFile_15;
    IData/*31:0*/ register_file__DOT__registerFile_16;
    IData/*31:0*/ register_file__DOT__registerFile_17;
    IData/*31:0*/ register_file__DOT__registerFile_18;
    IData/*31:0*/ register_file__DOT__registerFile_19;
    IData/*31:0*/ register_file__DOT__registerFile_20;
    IData/*31:0*/ register_file__DOT__registerFile_21;
    IData/*31:0*/ register_file__DOT__registerFile_22;
    IData/*31:0*/ register_file__DOT__registerFile_23;
    IData/*31:0*/ register_file__DOT__registerFile_24;
    IData/*31:0*/ register_file__DOT__registerFile_25;
    IData/*31:0*/ register_file__DOT__registerFile_26;
    IData/*31:0*/ register_file__DOT__registerFile_27;
    IData/*31:0*/ register_file__DOT__registerFile_28;
    IData/*31:0*/ register_file__DOT__registerFile_29;
    IData/*31:0*/ register_file__DOT__registerFile_30;
    IData/*31:0*/ register_file__DOT__registerFile_31;
    IData/*31:0*/ register_file__DOT___GEN_21;
    IData/*31:0*/ register_file__DOT___GEN_54;
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__clock;
    IData/*31:0*/ __Vm_traceActivity;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vregister_file__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vregister_file);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vregister_file(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vregister_file();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vregister_file__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vregister_file__Syms* symsp, bool first);
  private:
    static QData _change_request(Vregister_file__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vregister_file__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vregister_file__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vregister_file__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__1(Vregister_file__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(Vregister_file__Syms* __restrict vlSymsp);
    static void traceChgThis(Vregister_file__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__2(Vregister_file__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__3(Vregister_file__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceFullThis(Vregister_file__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceFullThis__1(Vregister_file__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis(Vregister_file__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis__1(Vregister_file__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
