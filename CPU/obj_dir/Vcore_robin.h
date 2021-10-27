// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VCORE_ROBIN_H_
#define _VCORE_ROBIN_H_  // guard

#include "verilated.h"

//==========

class Vcore_robin__Syms;
class Vcore_robin_VerilatedVcd;


//----------

VL_MODULE(Vcore_robin) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    VL_OUT8(io_RECIEVED,0,0);
    VL_IN8(io_INSTRUCTION_LOADED,0,0);
    VL_IN8(io_rdData,7,0);
    VL_OUT8(io_mem_write,0,0);
    VL_OUT8(io_mem_write_data,7,0);
    VL_IN(io_INSTRUCTION,31,0);
    VL_OUT(io_PC,31,0);
    VL_OUT(io_rdAddr,31,0);
    VL_OUT(io_mem_write_address,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*4:0*/ core_robin__DOT__controlStore_io_RS1;
        CData/*4:0*/ core_robin__DOT__controlStore_io_RS2;
        CData/*4:0*/ core_robin__DOT__controlStore_io_RD;
        CData/*0:0*/ core_robin__DOT__controlStore_io_WRITE_EN;
        CData/*3:0*/ core_robin__DOT__controlStore_io_ALU_OP;
        CData/*0:0*/ core_robin__DOT__controlStore_io_PROCEDURE_BRANCHING;
        CData/*0:0*/ core_robin__DOT__controlStore_io_DATA_IN;
        CData/*0:0*/ core_robin__DOT__controlStore_io_STORE_ADDRESS_IN;
        CData/*1:0*/ core_robin__DOT__controlStore_io_BRANCH_SELECT;
        CData/*2:0*/ core_robin__DOT__controlStore__DOT__stateReg;
        CData/*2:0*/ core_robin__DOT__controlStore__DOT__stallState;
        CData/*0:0*/ core_robin__DOT__controlStore__DOT__RECIEVED;
        CData/*0:0*/ core_robin__DOT__controlStore__DOT__STORE_READY;
        CData/*0:0*/ core_robin__DOT__controlStore__DOT__LOAD_READY;
        CData/*0:0*/ core_robin__DOT__controlStore__DOT___T;
        CData/*0:0*/ core_robin__DOT__controlStore__DOT___T_2;
        CData/*2:0*/ core_robin__DOT__controlStore__DOT___GEN_4;
        CData/*0:0*/ core_robin__DOT__controlStore__DOT___T_34;
        CData/*0:0*/ core_robin__DOT__controlStore__DOT___GEN_34;
        CData/*2:0*/ core_robin__DOT__controlStore__DOT___GEN_41;
        CData/*2:0*/ core_robin__DOT__controlStore__DOT___GEN_43;
        CData/*0:0*/ core_robin__DOT__dataPath__DOT__cpuALU__DOT__EQUAL;
        CData/*0:0*/ core_robin__DOT__dataPath__DOT__cpuALU__DOT__LESS_THAN;
        CData/*0:0*/ core_robin__DOT__dataPath__DOT__cpuALU__DOT__SIGNED_LESS_THAN;
        CData/*1:0*/ core_robin__DOT__storeUnit__DOT__store_data_size_buffer;
        CData/*0:0*/ core_robin__DOT__storeUnit__DOT__storing;
        CData/*0:0*/ core_robin__DOT__storeUnit__DOT__stateReg;
        CData/*0:0*/ core_robin__DOT__storeUnit__DOT___GEN_9;
        CData/*1:0*/ core_robin__DOT__storeUnit__DOT___GEN_10;
        CData/*0:0*/ core_robin__DOT__storeUnit__DOT___T_9;
        CData/*0:0*/ core_robin__DOT__storeUnit__DOT___GEN_11;
        CData/*0:0*/ core_robin__DOT__storeUnit__DOT___GEN_25;
        SData/*11:0*/ core_robin__DOT__controlStore__DOT___T_18;
        SData/*12:0*/ core_robin__DOT__controlStore__DOT___T_55;
        IData/*31:0*/ core_robin__DOT__PC;
        IData/*31:0*/ core_robin__DOT__noBranchNextAddr;
        IData/*31:0*/ core_robin__DOT__branchImmBranchAddr;
        IData/*31:0*/ core_robin__DOT__controlStore__DOT__instruction;
        IData/*20:0*/ core_robin__DOT__controlStore__DOT___T_56;
        IData/*31:0*/ core_robin__DOT__dataPath__DOT__registerFile_io_rdData;
        IData/*31:0*/ core_robin__DOT__dataPath__DOT__ALU_in1;
        IData/*31:0*/ core_robin__DOT__dataPath__DOT__ALU_in2;
        IData/*31:0*/ core_robin__DOT__dataPath__DOT__rdData;
        IData/*31:0*/ core_robin__DOT__dataPath__DOT__rs2_ALU;
        IData/*31:0*/ core_robin__DOT__dataPath__DOT__cpuALU__DOT__ALUoutput;
        IData/*31:0*/ core_robin__DOT__dataPath__DOT__cpuALU__DOT___T_3;
        IData/*31:0*/ core_robin__DOT__dataPath__DOT__cpuALU__DOT___T_7;
        IData/*31:0*/ core_robin__DOT__dataPath__DOT__cpuALU__DOT___GEN_4;
        IData/*31:0*/ core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_0;
        IData/*31:0*/ core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_1;
        IData/*31:0*/ core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_2;
        IData/*31:0*/ core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_3;
        IData/*31:0*/ core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_4;
        IData/*31:0*/ core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_5;
        IData/*31:0*/ core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_6;
        IData/*31:0*/ core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_7;
        IData/*31:0*/ core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_8;
        IData/*31:0*/ core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_9;
        IData/*31:0*/ core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_10;
        IData/*31:0*/ core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_11;
        IData/*31:0*/ core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_12;
        IData/*31:0*/ core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_13;
        IData/*31:0*/ core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_14;
        IData/*31:0*/ core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_15;
    };
    struct {
        IData/*31:0*/ core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_16;
        IData/*31:0*/ core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_17;
        IData/*31:0*/ core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_18;
        IData/*31:0*/ core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_19;
        IData/*31:0*/ core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_20;
        IData/*31:0*/ core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_21;
        IData/*31:0*/ core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_22;
        IData/*31:0*/ core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_23;
        IData/*31:0*/ core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_24;
        IData/*31:0*/ core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_25;
        IData/*31:0*/ core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_26;
        IData/*31:0*/ core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_27;
        IData/*31:0*/ core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_28;
        IData/*31:0*/ core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_29;
        IData/*31:0*/ core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_30;
        IData/*31:0*/ core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_31;
        IData/*31:0*/ core_robin__DOT__dataPath__DOT__registerFile__DOT___GEN_21;
        IData/*31:0*/ core_robin__DOT__dataPath__DOT__registerFile__DOT___GEN_54;
        IData/*31:0*/ core_robin__DOT__storeUnit__DOT__store_data_buffer;
        IData/*31:0*/ core_robin__DOT__storeUnit__DOT__store_data_buffer_address;
        IData/*31:0*/ core_robin__DOT__storeUnit__DOT___GEN_6;
        IData/*31:0*/ core_robin__DOT__storeUnit__DOT___GEN_7;
        QData/*62:0*/ core_robin__DOT__dataPath__DOT__cpuALU__DOT___GEN_7;
        QData/*62:0*/ core_robin__DOT__dataPath__DOT__cpuALU__DOT___GEN_11;
    };
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__clock;
    IData/*31:0*/ __Vm_traceActivity;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vcore_robin__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vcore_robin);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vcore_robin(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vcore_robin();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vcore_robin__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vcore_robin__Syms* symsp, bool first);
  private:
    static QData _change_request(Vcore_robin__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__4(Vcore_robin__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vcore_robin__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vcore_robin__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vcore_robin__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(Vcore_robin__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__2(Vcore_robin__Syms* __restrict vlSymsp);
    static void _settle__TOP__3(Vcore_robin__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void traceChgThis(Vcore_robin__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__2(Vcore_robin__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__3(Vcore_robin__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__4(Vcore_robin__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__5(Vcore_robin__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__6(Vcore_robin__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceFullThis(Vcore_robin__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceFullThis__1(Vcore_robin__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis(Vcore_robin__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis__1(Vcore_robin__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
