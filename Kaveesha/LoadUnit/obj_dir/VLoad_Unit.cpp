// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VLoad_Unit.h for the primary calling header

#include "VLoad_Unit.h"
#include "VLoad_Unit__Syms.h"

//==========

VL_CTOR_IMP(VLoad_Unit) {
    VLoad_Unit__Syms* __restrict vlSymsp = __VlSymsp = new VLoad_Unit__Syms(this, name());
    VLoad_Unit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VLoad_Unit::__Vconfigure(VLoad_Unit__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VLoad_Unit::~VLoad_Unit() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void VLoad_Unit::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VLoad_Unit::eval\n"); );
    VLoad_Unit__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VLoad_Unit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("Load_Unit.v", 2, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VLoad_Unit::_eval_initial_loop(VLoad_Unit__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("Load_Unit.v", 2, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void VLoad_Unit::_sequent__TOP__1(VLoad_Unit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLoad_Unit::_sequent__TOP__1\n"); );
    VLoad_Unit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*1:0*/ __Vdly__Load_Unit__DOT__load_data_size_buffer;
    CData/*0:0*/ __Vdly__Load_Unit__DOT__reading;
    CData/*0:0*/ __Vdly__Load_Unit__DOT__loading;
    // Body
    __Vdly__Load_Unit__DOT__load_data_size_buffer = vlTOPp->Load_Unit__DOT__load_data_size_buffer;
    __Vdly__Load_Unit__DOT__reading = vlTOPp->Load_Unit__DOT__reading;
    __Vdly__Load_Unit__DOT__loading = vlTOPp->Load_Unit__DOT__loading;
    vlTOPp->Load_Unit__DOT__load_data_buffer = ((IData)(vlTOPp->reset)
                                                 ? 0U
                                                 : (IData)(vlTOPp->Load_Unit__DOT___GEN_12));
    __Vdly__Load_Unit__DOT__load_data_size_buffer = 
        ((IData)(vlTOPp->reset) ? 0U : ((IData)(vlTOPp->Load_Unit__DOT__stateReg)
                                         ? (IData)(vlTOPp->Load_Unit__DOT___GEN_7)
                                         : (((IData)(vlTOPp->io_LOAD_ADDRESS_IN) 
                                             & (~ (IData)(vlTOPp->Load_Unit__DOT__reading)))
                                             ? (IData)(vlTOPp->io_LOAD_SIZE)
                                             : (IData)(vlTOPp->Load_Unit__DOT___GEN_7))));
    vlTOPp->Load_Unit__DOT__loaded_data_size_buffer 
        = ((IData)(vlTOPp->reset) ? 0U : ((IData)(vlTOPp->Load_Unit__DOT__stateReg)
                                           ? (IData)(vlTOPp->Load_Unit__DOT___GEN_15)
                                           : (((IData)(vlTOPp->io_LOAD_ADDRESS_IN) 
                                               & (~ (IData)(vlTOPp->Load_Unit__DOT__reading)))
                                               ? (IData)(vlTOPp->io_LOAD_SIZE)
                                               : (IData)(vlTOPp->Load_Unit__DOT___GEN_15))));
    vlTOPp->Load_Unit__DOT__load_data_address_buffer 
        = ((IData)(vlTOPp->reset) ? 0U : ((IData)(vlTOPp->Load_Unit__DOT__stateReg)
                                           ? vlTOPp->Load_Unit__DOT___GEN_6
                                           : (((IData)(vlTOPp->io_LOAD_ADDRESS_IN) 
                                               & (~ (IData)(vlTOPp->Load_Unit__DOT__reading)))
                                               ? vlTOPp->io_load_mem_address_in
                                               : vlTOPp->Load_Unit__DOT___GEN_6)));
    if (vlTOPp->reset) {
        __Vdly__Load_Unit__DOT__reading = 0U;
    } else {
        if (vlTOPp->Load_Unit__DOT__stateReg) {
            if (vlTOPp->Load_Unit__DOT__reading) {
                if ((3U == (IData)(vlTOPp->Load_Unit__DOT__load_data_size_buffer))) {
                    __Vdly__Load_Unit__DOT__reading = 0U;
                }
            }
        } else {
            __Vdly__Load_Unit__DOT__reading = vlTOPp->Load_Unit__DOT___GEN_20;
        }
    }
    __Vdly__Load_Unit__DOT__loading = ((~ (IData)(vlTOPp->reset)) 
                                       & ((IData)(vlTOPp->Load_Unit__DOT___T_4)
                                           ? (IData)(vlTOPp->Load_Unit__DOT___GEN_14)
                                           : ((IData)(vlTOPp->Load_Unit__DOT__stateReg)
                                               ? (((IData)(vlTOPp->io_LOAD_TO_REG) 
                                                   & (~ (IData)(vlTOPp->Load_Unit__DOT__loading)))
                                                   ? (IData)(vlTOPp->Load_Unit__DOT___GEN_14)
                                                   : (IData)(vlTOPp->Load_Unit__DOT___GEN_22))
                                               : (IData)(vlTOPp->Load_Unit__DOT___GEN_14))));
    vlTOPp->Load_Unit__DOT__stateReg = ((~ (IData)(vlTOPp->reset)) 
                                        & ((IData)(vlTOPp->Load_Unit__DOT___T_4)
                                            ? (((IData)(vlTOPp->io_LOAD_ADDRESS_IN) 
                                                & (~ (IData)(vlTOPp->Load_Unit__DOT__reading))) 
                                               | (IData)(vlTOPp->Load_Unit__DOT___GEN_13))
                                            : ((IData)(vlTOPp->Load_Unit__DOT__stateReg)
                                                ? (
                                                   (~ 
                                                    ((IData)(vlTOPp->io_LOAD_TO_REG) 
                                                     & (~ (IData)(vlTOPp->Load_Unit__DOT__loading)))) 
                                                   & (IData)(vlTOPp->Load_Unit__DOT___GEN_13))
                                                : (IData)(vlTOPp->Load_Unit__DOT___GEN_13))));
    vlTOPp->Load_Unit__DOT__load_data_size_buffer = __Vdly__Load_Unit__DOT__load_data_size_buffer;
    vlTOPp->Load_Unit__DOT__reading = __Vdly__Load_Unit__DOT__reading;
    vlTOPp->Load_Unit__DOT__loading = __Vdly__Load_Unit__DOT__loading;
    vlTOPp->Load_Unit__DOT___T_4 = (1U & (~ (IData)(vlTOPp->Load_Unit__DOT__stateReg)));
    vlTOPp->io_mem_read = vlTOPp->Load_Unit__DOT__reading;
    vlTOPp->Load_Unit__DOT___GEN_7 = (3U & ((IData)(vlTOPp->Load_Unit__DOT__reading)
                                             ? ((3U 
                                                 == (IData)(vlTOPp->Load_Unit__DOT__load_data_size_buffer))
                                                 ? (IData)(vlTOPp->Load_Unit__DOT__load_data_size_buffer)
                                                 : 
                                                ((IData)(1U) 
                                                 + (IData)(vlTOPp->Load_Unit__DOT__load_data_size_buffer)))
                                             : (IData)(vlTOPp->Load_Unit__DOT__load_data_size_buffer)));
    vlTOPp->io_load_mem_address_out = ((IData)(vlTOPp->Load_Unit__DOT__reading)
                                        ? vlTOPp->Load_Unit__DOT__load_data_address_buffer
                                        : 0U);
    vlTOPp->Load_Unit__DOT___GEN_6 = ((IData)(vlTOPp->Load_Unit__DOT__reading)
                                       ? ((3U == (IData)(vlTOPp->Load_Unit__DOT__load_data_size_buffer))
                                           ? vlTOPp->Load_Unit__DOT__load_data_address_buffer
                                           : ((IData)(1U) 
                                              + vlTOPp->Load_Unit__DOT__load_data_address_buffer))
                                       : vlTOPp->Load_Unit__DOT__load_data_address_buffer);
    vlTOPp->Load_Unit__DOT___GEN_15 = (3U & ((IData)(vlTOPp->Load_Unit__DOT__loading)
                                              ? ((3U 
                                                  == (IData)(vlTOPp->Load_Unit__DOT__loaded_data_size_buffer))
                                                  ? (IData)(vlTOPp->Load_Unit__DOT__loaded_data_size_buffer)
                                                  : 
                                                 ((IData)(1U) 
                                                  + (IData)(vlTOPp->Load_Unit__DOT__loaded_data_size_buffer)))
                                              : (IData)(vlTOPp->Load_Unit__DOT__loaded_data_size_buffer)));
    vlTOPp->Load_Unit__DOT___GEN_13 = ((IData)(vlTOPp->Load_Unit__DOT__loading)
                                        ? ((3U == (IData)(vlTOPp->Load_Unit__DOT__loaded_data_size_buffer)) 
                                           | (IData)(vlTOPp->Load_Unit__DOT__stateReg))
                                        : (IData)(vlTOPp->Load_Unit__DOT__stateReg));
    vlTOPp->Load_Unit__DOT___GEN_14 = ((IData)(vlTOPp->Load_Unit__DOT__loading)
                                        ? ((3U != (IData)(vlTOPp->Load_Unit__DOT__loaded_data_size_buffer)) 
                                           & (IData)(vlTOPp->Load_Unit__DOT__loading))
                                        : (IData)(vlTOPp->Load_Unit__DOT__loading));
}

void VLoad_Unit::_settle__TOP__2(VLoad_Unit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLoad_Unit::_settle__TOP__2\n"); );
    VLoad_Unit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Load_Unit__DOT___T_4 = (1U & (~ (IData)(vlTOPp->Load_Unit__DOT__stateReg)));
    vlTOPp->io_mem_read = vlTOPp->Load_Unit__DOT__reading;
    vlTOPp->Load_Unit__DOT___GEN_7 = (3U & ((IData)(vlTOPp->Load_Unit__DOT__reading)
                                             ? ((3U 
                                                 == (IData)(vlTOPp->Load_Unit__DOT__load_data_size_buffer))
                                                 ? (IData)(vlTOPp->Load_Unit__DOT__load_data_size_buffer)
                                                 : 
                                                ((IData)(1U) 
                                                 + (IData)(vlTOPp->Load_Unit__DOT__load_data_size_buffer)))
                                             : (IData)(vlTOPp->Load_Unit__DOT__load_data_size_buffer)));
    vlTOPp->Load_Unit__DOT___GEN_15 = (3U & ((IData)(vlTOPp->Load_Unit__DOT__loading)
                                              ? ((3U 
                                                  == (IData)(vlTOPp->Load_Unit__DOT__loaded_data_size_buffer))
                                                  ? (IData)(vlTOPp->Load_Unit__DOT__loaded_data_size_buffer)
                                                  : 
                                                 ((IData)(1U) 
                                                  + (IData)(vlTOPp->Load_Unit__DOT__loaded_data_size_buffer)))
                                              : (IData)(vlTOPp->Load_Unit__DOT__loaded_data_size_buffer)));
    vlTOPp->io_load_mem_address_out = ((IData)(vlTOPp->Load_Unit__DOT__reading)
                                        ? vlTOPp->Load_Unit__DOT__load_data_address_buffer
                                        : 0U);
    vlTOPp->Load_Unit__DOT___GEN_6 = ((IData)(vlTOPp->Load_Unit__DOT__reading)
                                       ? ((3U == (IData)(vlTOPp->Load_Unit__DOT__load_data_size_buffer))
                                           ? vlTOPp->Load_Unit__DOT__load_data_address_buffer
                                           : ((IData)(1U) 
                                              + vlTOPp->Load_Unit__DOT__load_data_address_buffer))
                                       : vlTOPp->Load_Unit__DOT__load_data_address_buffer);
    vlTOPp->Load_Unit__DOT___GEN_13 = ((IData)(vlTOPp->Load_Unit__DOT__loading)
                                        ? ((3U == (IData)(vlTOPp->Load_Unit__DOT__loaded_data_size_buffer)) 
                                           | (IData)(vlTOPp->Load_Unit__DOT__stateReg))
                                        : (IData)(vlTOPp->Load_Unit__DOT__stateReg));
    vlTOPp->Load_Unit__DOT___GEN_20 = (((IData)(vlTOPp->io_LOAD_ADDRESS_IN) 
                                        & (~ (IData)(vlTOPp->Load_Unit__DOT__reading))) 
                                       | ((IData)(vlTOPp->Load_Unit__DOT__reading)
                                           ? ((3U != (IData)(vlTOPp->Load_Unit__DOT__load_data_size_buffer)) 
                                              & (IData)(vlTOPp->Load_Unit__DOT__reading))
                                           : (IData)(vlTOPp->Load_Unit__DOT__reading)));
    vlTOPp->io_LOAD_READY = (1U & ((~ (IData)(vlTOPp->Load_Unit__DOT__stateReg)) 
                                   & (~ ((IData)(vlTOPp->io_LOAD_ADDRESS_IN) 
                                         & (~ (IData)(vlTOPp->Load_Unit__DOT__reading))))));
    vlTOPp->io_load_data_out = ((IData)(vlTOPp->Load_Unit__DOT__stateReg)
                                 ? ((IData)(vlTOPp->Load_Unit__DOT__stateReg)
                                     ? (((IData)(vlTOPp->io_LOAD_TO_REG) 
                                         & (~ (IData)(vlTOPp->Load_Unit__DOT__loading)))
                                         ? vlTOPp->Load_Unit__DOT__load_data_buffer
                                         : 0U) : 0U)
                                 : 0U);
    vlTOPp->Load_Unit__DOT___GEN_14 = ((IData)(vlTOPp->Load_Unit__DOT__loading)
                                        ? ((3U != (IData)(vlTOPp->Load_Unit__DOT__loaded_data_size_buffer)) 
                                           & (IData)(vlTOPp->Load_Unit__DOT__loading))
                                        : (IData)(vlTOPp->Load_Unit__DOT__loading));
    vlTOPp->Load_Unit__DOT___load_data_buffer_T_1 = 
        ((0xffffff00U & vlTOPp->Load_Unit__DOT__load_data_buffer) 
         | (IData)(vlTOPp->io_load_data));
    vlTOPp->Load_Unit__DOT___GEN_22 = (((IData)(vlTOPp->io_load_begin) 
                                        & (~ (IData)(vlTOPp->Load_Unit__DOT__loading))) 
                                       | (IData)(vlTOPp->Load_Unit__DOT___GEN_14));
    vlTOPp->Load_Unit__DOT___GEN_12 = ((IData)(vlTOPp->Load_Unit__DOT__loading)
                                        ? ((3U == (IData)(vlTOPp->Load_Unit__DOT__loaded_data_size_buffer))
                                            ? (((QData)((IData)(
                                                                (0xffU 
                                                                 & VL_NEGATE_I((IData)(
                                                                                (1U 
                                                                                & (vlTOPp->Load_Unit__DOT___load_data_buffer_T_1 
                                                                                >> 0x1fU))))))) 
                                                << 0x20U) 
                                               | (QData)((IData)(vlTOPp->Load_Unit__DOT___load_data_buffer_T_1)))
                                            : ((QData)((IData)(vlTOPp->Load_Unit__DOT__load_data_buffer)) 
                                               << 8U))
                                        : (((QData)((IData)(
                                                            (0xffU 
                                                             & VL_NEGATE_I((IData)(
                                                                                (1U 
                                                                                & (vlTOPp->Load_Unit__DOT__load_data_buffer 
                                                                                >> 0x1fU))))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(vlTOPp->Load_Unit__DOT__load_data_buffer))));
}

VL_INLINE_OPT void VLoad_Unit::_combo__TOP__3(VLoad_Unit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLoad_Unit::_combo__TOP__3\n"); );
    VLoad_Unit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Load_Unit__DOT___load_data_buffer_T_1 = 
        ((0xffffff00U & vlTOPp->Load_Unit__DOT__load_data_buffer) 
         | (IData)(vlTOPp->io_load_data));
    vlTOPp->Load_Unit__DOT___GEN_20 = (((IData)(vlTOPp->io_LOAD_ADDRESS_IN) 
                                        & (~ (IData)(vlTOPp->Load_Unit__DOT__reading))) 
                                       | ((IData)(vlTOPp->Load_Unit__DOT__reading)
                                           ? ((3U != (IData)(vlTOPp->Load_Unit__DOT__load_data_size_buffer)) 
                                              & (IData)(vlTOPp->Load_Unit__DOT__reading))
                                           : (IData)(vlTOPp->Load_Unit__DOT__reading)));
    vlTOPp->io_LOAD_READY = (1U & ((~ (IData)(vlTOPp->Load_Unit__DOT__stateReg)) 
                                   & (~ ((IData)(vlTOPp->io_LOAD_ADDRESS_IN) 
                                         & (~ (IData)(vlTOPp->Load_Unit__DOT__reading))))));
    vlTOPp->io_load_data_out = ((IData)(vlTOPp->Load_Unit__DOT__stateReg)
                                 ? ((IData)(vlTOPp->Load_Unit__DOT__stateReg)
                                     ? (((IData)(vlTOPp->io_LOAD_TO_REG) 
                                         & (~ (IData)(vlTOPp->Load_Unit__DOT__loading)))
                                         ? vlTOPp->Load_Unit__DOT__load_data_buffer
                                         : 0U) : 0U)
                                 : 0U);
    vlTOPp->Load_Unit__DOT___GEN_22 = (((IData)(vlTOPp->io_load_begin) 
                                        & (~ (IData)(vlTOPp->Load_Unit__DOT__loading))) 
                                       | (IData)(vlTOPp->Load_Unit__DOT___GEN_14));
    vlTOPp->Load_Unit__DOT___GEN_12 = ((IData)(vlTOPp->Load_Unit__DOT__loading)
                                        ? ((3U == (IData)(vlTOPp->Load_Unit__DOT__loaded_data_size_buffer))
                                            ? (((QData)((IData)(
                                                                (0xffU 
                                                                 & VL_NEGATE_I((IData)(
                                                                                (1U 
                                                                                & (vlTOPp->Load_Unit__DOT___load_data_buffer_T_1 
                                                                                >> 0x1fU))))))) 
                                                << 0x20U) 
                                               | (QData)((IData)(vlTOPp->Load_Unit__DOT___load_data_buffer_T_1)))
                                            : ((QData)((IData)(vlTOPp->Load_Unit__DOT__load_data_buffer)) 
                                               << 8U))
                                        : (((QData)((IData)(
                                                            (0xffU 
                                                             & VL_NEGATE_I((IData)(
                                                                                (1U 
                                                                                & (vlTOPp->Load_Unit__DOT__load_data_buffer 
                                                                                >> 0x1fU))))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(vlTOPp->Load_Unit__DOT__load_data_buffer))));
}

void VLoad_Unit::_eval(VLoad_Unit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLoad_Unit::_eval\n"); );
    VLoad_Unit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
        vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
    }
    vlTOPp->_combo__TOP__3(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void VLoad_Unit::_eval_initial(VLoad_Unit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLoad_Unit::_eval_initial\n"); );
    VLoad_Unit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void VLoad_Unit::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLoad_Unit::final\n"); );
    // Variables
    VLoad_Unit__Syms* __restrict vlSymsp = this->__VlSymsp;
    VLoad_Unit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VLoad_Unit::_eval_settle(VLoad_Unit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLoad_Unit::_eval_settle\n"); );
    VLoad_Unit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

VL_INLINE_OPT QData VLoad_Unit::_change_request(VLoad_Unit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLoad_Unit::_change_request\n"); );
    VLoad_Unit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VLoad_Unit::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLoad_Unit::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((io_LOAD_TO_REG & 0xfeU))) {
        Verilated::overWidthError("io_LOAD_TO_REG");}
    if (VL_UNLIKELY((io_LOAD_SIZE & 0xfcU))) {
        Verilated::overWidthError("io_LOAD_SIZE");}
    if (VL_UNLIKELY((io_LOAD_ADDRESS_IN & 0xfeU))) {
        Verilated::overWidthError("io_LOAD_ADDRESS_IN");}
    if (VL_UNLIKELY((io_load_begin & 0xfeU))) {
        Verilated::overWidthError("io_load_begin");}
}
#endif  // VL_DEBUG

void VLoad_Unit::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLoad_Unit::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    io_load_mem_address_in = VL_RAND_RESET_I(32);
    io_load_data = VL_RAND_RESET_I(8);
    io_LOAD_TO_REG = VL_RAND_RESET_I(1);
    io_LOAD_SIZE = VL_RAND_RESET_I(2);
    io_LOAD_ADDRESS_IN = VL_RAND_RESET_I(1);
    io_mem_read = VL_RAND_RESET_I(1);
    io_LOAD_READY = VL_RAND_RESET_I(1);
    io_load_mem_address_out = VL_RAND_RESET_I(32);
    io_load_begin = VL_RAND_RESET_I(1);
    io_load_data_out = VL_RAND_RESET_I(32);
    Load_Unit__DOT__load_data_buffer = VL_RAND_RESET_I(32);
    Load_Unit__DOT__load_data_size_buffer = VL_RAND_RESET_I(2);
    Load_Unit__DOT__loaded_data_size_buffer = VL_RAND_RESET_I(2);
    Load_Unit__DOT__load_data_address_buffer = VL_RAND_RESET_I(32);
    Load_Unit__DOT__reading = VL_RAND_RESET_I(1);
    Load_Unit__DOT__loading = VL_RAND_RESET_I(1);
    Load_Unit__DOT__stateReg = VL_RAND_RESET_I(1);
    Load_Unit__DOT___GEN_6 = VL_RAND_RESET_I(32);
    Load_Unit__DOT___GEN_7 = VL_RAND_RESET_I(2);
    Load_Unit__DOT___load_data_buffer_T_1 = VL_RAND_RESET_I(32);
    Load_Unit__DOT___GEN_12 = VL_RAND_RESET_Q(40);
    Load_Unit__DOT___GEN_13 = VL_RAND_RESET_I(1);
    Load_Unit__DOT___GEN_14 = VL_RAND_RESET_I(1);
    Load_Unit__DOT___GEN_15 = VL_RAND_RESET_I(2);
    Load_Unit__DOT___T_4 = VL_RAND_RESET_I(1);
    Load_Unit__DOT___GEN_20 = VL_RAND_RESET_I(1);
    Load_Unit__DOT___GEN_22 = VL_RAND_RESET_I(1);
    __Vm_traceActivity = 0;
}
