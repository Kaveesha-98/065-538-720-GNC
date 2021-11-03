// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VMemory.h for the primary calling header

#include "VMemory.h"
#include "VMemory__Syms.h"

//==========

VL_CTOR_IMP(VMemory) {
    VMemory__Syms* __restrict vlSymsp = __VlSymsp = new VMemory__Syms(this, name());
    VMemory* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VMemory::__Vconfigure(VMemory__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VMemory::~VMemory() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void VMemory::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VMemory::eval\n"); );
    VMemory__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VMemory* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("Memory.v", 2, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VMemory::_eval_initial_loop(VMemory__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("Memory.v", 2, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void VMemory::_sequent__TOP__1(VMemory__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMemory::_sequent__TOP__1\n"); );
    VMemory* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*7:0*/ __Vdlyvval__Memory__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__Memory__DOT__mem__v0;
    SData/*9:0*/ __Vdlyvdim0__Memory__DOT__mem__v0;
    // Body
    __Vdlyvset__Memory__DOT__mem__v0 = 0U;
    vlTOPp->Memory__DOT__wrDataReg = vlTOPp->io_mem_write_data;
    vlTOPp->Memory__DOT__mem_memData_addr_pipe_0 = 
        (0x3ffU & vlTOPp->io_rdAddr);
    vlTOPp->Memory__DOT__doForwardReg = ((vlTOPp->io_mem_write_address 
                                          == vlTOPp->io_rdAddr) 
                                         & (IData)(vlTOPp->io_mem_write));
    if (vlTOPp->io_mem_write) {
        __Vdlyvval__Memory__DOT__mem__v0 = vlTOPp->io_mem_write_data;
        __Vdlyvset__Memory__DOT__mem__v0 = 1U;
        __Vdlyvdim0__Memory__DOT__mem__v0 = (0x3ffU 
                                             & vlTOPp->io_mem_write_address);
    }
    if (__Vdlyvset__Memory__DOT__mem__v0) {
        vlTOPp->Memory__DOT__mem[__Vdlyvdim0__Memory__DOT__mem__v0] 
            = __Vdlyvval__Memory__DOT__mem__v0;
    }
    vlTOPp->io_rdData = ((IData)(vlTOPp->Memory__DOT__doForwardReg)
                          ? (IData)(vlTOPp->Memory__DOT__wrDataReg)
                          : vlTOPp->Memory__DOT__mem
                         [vlTOPp->Memory__DOT__mem_memData_addr_pipe_0]);
}

void VMemory::_settle__TOP__2(VMemory__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMemory::_settle__TOP__2\n"); );
    VMemory* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->io_rdData = ((IData)(vlTOPp->Memory__DOT__doForwardReg)
                          ? (IData)(vlTOPp->Memory__DOT__wrDataReg)
                          : vlTOPp->Memory__DOT__mem
                         [vlTOPp->Memory__DOT__mem_memData_addr_pipe_0]);
}

void VMemory::_eval(VMemory__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMemory::_eval\n"); );
    VMemory* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
        vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void VMemory::_eval_initial(VMemory__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMemory::_eval_initial\n"); );
    VMemory* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void VMemory::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMemory::final\n"); );
    // Variables
    VMemory__Syms* __restrict vlSymsp = this->__VlSymsp;
    VMemory* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VMemory::_eval_settle(VMemory__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMemory::_eval_settle\n"); );
    VMemory* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

VL_INLINE_OPT QData VMemory::_change_request(VMemory__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMemory::_change_request\n"); );
    VMemory* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VMemory::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMemory::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((io_mem_write & 0xfeU))) {
        Verilated::overWidthError("io_mem_write");}
}
#endif  // VL_DEBUG

void VMemory::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMemory::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    io_rdAddr = VL_RAND_RESET_I(32);
    io_rdData = VL_RAND_RESET_I(8);
    io_mem_write = VL_RAND_RESET_I(1);
    io_mem_write_data = VL_RAND_RESET_I(8);
    io_mem_write_address = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<1024; ++__Vi0) {
            Memory__DOT__mem[__Vi0] = VL_RAND_RESET_I(8);
    }}
    Memory__DOT__mem_memData_addr_pipe_0 = VL_RAND_RESET_I(10);
    Memory__DOT__wrDataReg = VL_RAND_RESET_I(8);
    Memory__DOT__doForwardReg = VL_RAND_RESET_I(1);
    __Vm_traceActivity = 0;
}
