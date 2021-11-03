// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VLOAD_UNIT_H_
#define _VLOAD_UNIT_H_  // guard

#include "verilated.h"

//==========

class VLoad_Unit__Syms;
class VLoad_Unit_VerilatedVcd;


//----------

VL_MODULE(VLoad_Unit) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(io_load_data,7,0);
    VL_IN8(io_LOAD_TO_REG,0,0);
    VL_IN8(io_LOAD_SIZE,1,0);
    VL_IN8(io_LOAD_ADDRESS_IN,0,0);
    VL_OUT8(io_mem_read,0,0);
    VL_OUT8(io_LOAD_READY,0,0);
    VL_IN8(io_load_begin,0,0);
    VL_IN8(io_EXTENSION,0,0);
    VL_IN(io_load_mem_address_in,31,0);
    VL_OUT(io_load_mem_address_out,31,0);
    VL_OUT(io_load_data_out,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*1:0*/ Load_Unit__DOT__load_data_size_buffer;
    CData/*1:0*/ Load_Unit__DOT__LOAD_SIZE;
    CData/*0:0*/ Load_Unit__DOT__EXTENSION;
    CData/*0:0*/ Load_Unit__DOT__stateReg;
    CData/*0:0*/ Load_Unit__DOT___T;
    CData/*0:0*/ Load_Unit__DOT___GEN_0;
    CData/*1:0*/ Load_Unit__DOT___load_data_size_buffer_T_1;
    IData/*31:0*/ Load_Unit__DOT__load_data_buffer;
    IData/*31:0*/ Load_Unit__DOT__load_data_address_buffer;
    IData/*31:0*/ Load_Unit__DOT___load_data_buffer_T;
    IData/*31:0*/ Load_Unit__DOT___load_data_address_buffer_T_1;
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__clock;
    IData/*31:0*/ __Vm_traceActivity;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    VLoad_Unit__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VLoad_Unit);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    VLoad_Unit(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VLoad_Unit();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(VLoad_Unit__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VLoad_Unit__Syms* symsp, bool first);
  private:
    static QData _change_request(VLoad_Unit__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__3(VLoad_Unit__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(VLoad_Unit__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(VLoad_Unit__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(VLoad_Unit__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__1(VLoad_Unit__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(VLoad_Unit__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void traceChgThis(VLoad_Unit__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__2(VLoad_Unit__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__3(VLoad_Unit__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceFullThis(VLoad_Unit__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceFullThis__1(VLoad_Unit__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis(VLoad_Unit__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis__1(VLoad_Unit__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
