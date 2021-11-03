// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VMEMORY_H_
#define _VMEMORY_H_  // guard

#include "verilated.h"

//==========

class VMemory__Syms;
class VMemory_VerilatedVcd;


//----------

VL_MODULE(VMemory) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    VL_OUT8(io_rdData,7,0);
    VL_IN8(io_mem_write,0,0);
    VL_IN8(io_mem_write_data,7,0);
    VL_IN(io_rdAddr,31,0);
    VL_IN(io_mem_write_address,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*7:0*/ Memory__DOT__wrDataReg;
    CData/*0:0*/ Memory__DOT__doForwardReg;
    SData/*9:0*/ Memory__DOT__mem_memData_addr_pipe_0;
    CData/*7:0*/ Memory__DOT__mem[1024];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__clock;
    IData/*31:0*/ __Vm_traceActivity;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    VMemory__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VMemory);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    VMemory(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VMemory();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(VMemory__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VMemory__Syms* symsp, bool first);
  private:
    static QData _change_request(VMemory__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(VMemory__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(VMemory__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(VMemory__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__1(VMemory__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(VMemory__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void traceChgThis(VMemory__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__2(VMemory__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__3(VMemory__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceFullThis(VMemory__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceFullThis__1(VMemory__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis(VMemory__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis__1(VMemory__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
