// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VCONTROL_STORE_H_
#define _VCONTROL_STORE_H_  // guard

#include "verilated.h"

//==========

class Vcontrol_store__Syms;
class Vcontrol_store_VerilatedVcd;


//----------

VL_MODULE(Vcontrol_store) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    VL_OUT8(io_RECIEVED,0,0);
    VL_IN8(io_INSTRUCTION_LOADED,0,0);
    VL_OUT8(io_RS1,4,0);
    VL_OUT8(io_RS2,4,0);
    VL_OUT8(io_RD,4,0);
    VL_OUT8(io_WRITE_EN,0,0);
    VL_OUT8(io_ALU_OP,3,0);
    VL_OUT8(io_PROCEDURE_BRANCHING,0,0);
    VL_OUT8(io_CHOOSE_IMMEDIATE,0,0);
    VL_OUT8(io_CHOOSE_MEMORY_LOAD,0,0);
    VL_OUT8(io_ALU_RD,4,0);
    VL_IN8(io_STORE_READY,0,0);
    VL_OUT8(io_DATA_IN,0,0);
    VL_OUT8(io_STORE_SIZE,1,0);
    VL_OUT8(io_STORE_ADDRESS_IN,0,0);
    VL_IN8(io_LOAD_READY,0,0);
    VL_OUT8(io_LOAD_SIZE,1,0);
    VL_OUT8(io_LOAD_ADDRESS_IN,0,0);
    VL_OUT8(io_EXTENSION,0,0);
    VL_OUT8(io_BRANCH_SELECT,1,0);
    VL_OUT8(io_BRANCH_CONDITION,0,0);
    VL_OUT8(io_BRANCH_ADDRESS_SOURCE_ALU,0,0);
    VL_OUT8(io_UPDATE_PC,0,0);
    VL_IN(io_INSTRUCTION,31,0);
    VL_OUT(io_IMMEDIATE,31,0);
    VL_OUT(io_BRANCH_IMMEDIATE,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*2:0*/ control_store__DOT__stateReg;
    CData/*2:0*/ control_store__DOT__stallState;
    CData/*0:0*/ control_store__DOT__RECIEVED;
    CData/*0:0*/ control_store__DOT___T;
    CData/*0:0*/ control_store__DOT___T_2;
    CData/*2:0*/ control_store__DOT___GEN_5;
    CData/*0:0*/ control_store__DOT___T_43;
    CData/*0:0*/ control_store__DOT___GEN_32;
    CData/*2:0*/ control_store__DOT___GEN_39;
    CData/*2:0*/ control_store__DOT___GEN_41;
    SData/*11:0*/ control_store__DOT___T_15;
    SData/*12:0*/ control_store__DOT___T_23;
    IData/*31:0*/ control_store__DOT__instruction;
    IData/*20:0*/ control_store__DOT___T_24;
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__clock;
    IData/*31:0*/ __Vm_traceActivity;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vcontrol_store__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vcontrol_store);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vcontrol_store(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vcontrol_store();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vcontrol_store__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vcontrol_store__Syms* symsp, bool first);
  private:
    static QData _change_request(Vcontrol_store__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__4(Vcontrol_store__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vcontrol_store__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vcontrol_store__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vcontrol_store__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(Vcontrol_store__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__2(Vcontrol_store__Syms* __restrict vlSymsp);
    static void _settle__TOP__3(Vcontrol_store__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void traceChgThis(Vcontrol_store__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__2(Vcontrol_store__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__3(Vcontrol_store__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceFullThis(Vcontrol_store__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceFullThis__1(Vcontrol_store__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis(Vcontrol_store__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis__1(Vcontrol_store__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
