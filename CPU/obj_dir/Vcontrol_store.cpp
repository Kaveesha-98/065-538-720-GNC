// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcontrol_store.h for the primary calling header

#include "Vcontrol_store.h"
#include "Vcontrol_store__Syms.h"

//==========

VL_CTOR_IMP(Vcontrol_store) {
    Vcontrol_store__Syms* __restrict vlSymsp = __VlSymsp = new Vcontrol_store__Syms(this, name());
    Vcontrol_store* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vcontrol_store::__Vconfigure(Vcontrol_store__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vcontrol_store::~Vcontrol_store() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void Vcontrol_store::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vcontrol_store::eval\n"); );
    Vcontrol_store__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vcontrol_store* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("control_store.v", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vcontrol_store::_eval_initial_loop(Vcontrol_store__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("control_store.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vcontrol_store::_initial__TOP__1(Vcontrol_store__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_store::_initial__TOP__1\n"); );
    Vcontrol_store* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->io_ALU_RD = 0U;
}

VL_INLINE_OPT void Vcontrol_store::_sequent__TOP__2(Vcontrol_store__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_store::_sequent__TOP__2\n"); );
    Vcontrol_store* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*2:0*/ __Vdly__control_store__DOT__stateReg;
    // Body
    __Vdly__control_store__DOT__stateReg = vlTOPp->control_store__DOT__stateReg;
    vlTOPp->control_store__DOT__RECIEVED = ((~ (IData)(vlTOPp->reset)) 
                                            & ((0U 
                                                == (IData)(vlTOPp->control_store__DOT__stateReg)) 
                                               & (IData)(vlTOPp->io_INSTRUCTION_LOADED)));
    if (vlTOPp->reset) {
        vlTOPp->control_store__DOT__stallState = 5U;
    } else {
        if ((0U != (IData)(vlTOPp->control_store__DOT__stateReg))) {
            if ((1U == (IData)(vlTOPp->control_store__DOT__stateReg))) {
                if ((0x23U == (0x7fU & vlTOPp->control_store__DOT__instruction))) {
                    vlTOPp->control_store__DOT__stallState 
                        = vlTOPp->control_store__DOT___GEN_5;
                }
            } else {
                if ((2U != (IData)(vlTOPp->control_store__DOT__stateReg))) {
                    vlTOPp->control_store__DOT__stallState 
                        = vlTOPp->control_store__DOT___GEN_42;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        __Vdly__control_store__DOT__stateReg = 0U;
    } else {
        if (vlTOPp->control_store__DOT___T) {
            if (vlTOPp->io_INSTRUCTION_LOADED) {
                __Vdly__control_store__DOT__stateReg = 1U;
            }
        } else {
            __Vdly__control_store__DOT__stateReg = 
                ((IData)(vlTOPp->control_store__DOT___T_2)
                  ? ((0x23U == (0x7fU & vlTOPp->control_store__DOT__instruction))
                      ? ((IData)(vlTOPp->io_STORE_READY)
                          ? 2U : 5U) : 2U) : ((IData)(vlTOPp->control_store__DOT___T_43)
                                               ? 3U
                                               : (IData)(vlTOPp->control_store__DOT___GEN_40)));
        }
    }
    vlTOPp->io_RECIEVED = vlTOPp->control_store__DOT__RECIEVED;
    if (vlTOPp->reset) {
        vlTOPp->control_store__DOT__instruction = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->control_store__DOT__stateReg))) {
            if (vlTOPp->io_INSTRUCTION_LOADED) {
                vlTOPp->control_store__DOT__instruction 
                    = vlTOPp->io_INSTRUCTION;
            }
        }
    }
    vlTOPp->control_store__DOT__stateReg = __Vdly__control_store__DOT__stateReg;
    vlTOPp->control_store__DOT___T_15 = (0xfffU & (
                                                   (0x23U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->control_store__DOT__instruction))
                                                    ? 
                                                   ((0xfe0U 
                                                     & (vlTOPp->control_store__DOT__instruction 
                                                        >> 0x14U)) 
                                                    | (0x1fU 
                                                       & (vlTOPp->control_store__DOT__instruction 
                                                          >> 7U)))
                                                    : 
                                                   (vlTOPp->control_store__DOT__instruction 
                                                    >> 0x14U)));
    vlTOPp->control_store__DOT___T_23 = ((0x1000U & 
                                          (vlTOPp->control_store__DOT__instruction 
                                           >> 0x13U)) 
                                         | ((0x800U 
                                             & (vlTOPp->control_store__DOT__instruction 
                                                << 4U)) 
                                            | ((0x780U 
                                                & (vlTOPp->control_store__DOT__instruction 
                                                   >> 1U)) 
                                               | (0x7eU 
                                                  & (vlTOPp->control_store__DOT__instruction 
                                                     >> 0x18U)))));
    vlTOPp->control_store__DOT___T_24 = ((0x100000U 
                                          & (vlTOPp->control_store__DOT__instruction 
                                             >> 0xbU)) 
                                         | ((0xff000U 
                                             & vlTOPp->control_store__DOT__instruction) 
                                            | ((0x800U 
                                                & (vlTOPp->control_store__DOT__instruction 
                                                   >> 9U)) 
                                               | (0x7feU 
                                                  & (vlTOPp->control_store__DOT__instruction 
                                                     >> 0x14U)))));
    vlTOPp->control_store__DOT___T = (0U == (IData)(vlTOPp->control_store__DOT__stateReg));
    vlTOPp->control_store__DOT___T_2 = (1U == (IData)(vlTOPp->control_store__DOT__stateReg));
    vlTOPp->control_store__DOT___T_43 = (2U == (IData)(vlTOPp->control_store__DOT__stateReg));
    vlTOPp->io_UPDATE_PC = ((0U != (IData)(vlTOPp->control_store__DOT__stateReg)) 
                            & ((1U != (IData)(vlTOPp->control_store__DOT__stateReg)) 
                               & (2U == (IData)(vlTOPp->control_store__DOT__stateReg))));
    vlTOPp->io_RS2 = ((0U == (IData)(vlTOPp->control_store__DOT__stateReg))
                       ? 0U : ((1U == (IData)(vlTOPp->control_store__DOT__stateReg))
                                ? (0x1fU & (vlTOPp->control_store__DOT__instruction 
                                            >> 0x14U))
                                : 0U));
    vlTOPp->io_RD = ((0U == (IData)(vlTOPp->control_store__DOT__stateReg))
                      ? 0U : ((1U == (IData)(vlTOPp->control_store__DOT__stateReg))
                               ? 0U : (0x1fU & ((2U 
                                                 == (IData)(vlTOPp->control_store__DOT__stateReg))
                                                 ? 
                                                ((0x67U 
                                                  == 
                                                  (0x77U 
                                                   & vlTOPp->control_store__DOT__instruction))
                                                  ? 
                                                 (vlTOPp->control_store__DOT__instruction 
                                                  >> 7U)
                                                  : 0U)
                                                 : 
                                                ((3U 
                                                  == (IData)(vlTOPp->control_store__DOT__stateReg))
                                                  ? 
                                                 (vlTOPp->control_store__DOT__instruction 
                                                  >> 7U)
                                                  : 
                                                 ((4U 
                                                   == (IData)(vlTOPp->control_store__DOT__stateReg))
                                                   ? 
                                                  (vlTOPp->control_store__DOT__instruction 
                                                   >> 7U)
                                                   : 0U))))));
    vlTOPp->io_ALU_OP = ((0U == (IData)(vlTOPp->control_store__DOT__stateReg))
                          ? 0U : ((1U == (IData)(vlTOPp->control_store__DOT__stateReg))
                                   ? 0U : ((2U == (IData)(vlTOPp->control_store__DOT__stateReg))
                                            ? ((0x13U 
                                                == 
                                                (0x7fU 
                                                 & vlTOPp->control_store__DOT__instruction))
                                                ? (
                                                   (0x18U 
                                                    & (((1U 
                                                         == 
                                                         (3U 
                                                          & (vlTOPp->control_store__DOT__instruction 
                                                             >> 0xcU))) 
                                                        << 3U) 
                                                       & (vlTOPp->control_store__DOT__instruction 
                                                          >> 0x1bU))) 
                                                   | (7U 
                                                      & (vlTOPp->control_store__DOT__instruction 
                                                         >> 0xcU)))
                                                : (
                                                   (0x33U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->control_store__DOT__instruction))
                                                    ? 
                                                   ((8U 
                                                     & (vlTOPp->control_store__DOT__instruction 
                                                        >> 0x1bU)) 
                                                    | (7U 
                                                       & (vlTOPp->control_store__DOT__instruction 
                                                          >> 0xcU)))
                                                    : 0U))
                                            : 0U)));
    vlTOPp->io_PROCEDURE_BRANCHING = ((0U != (IData)(vlTOPp->control_store__DOT__stateReg)) 
                                      & ((1U != (IData)(vlTOPp->control_store__DOT__stateReg)) 
                                         & ((2U == (IData)(vlTOPp->control_store__DOT__stateReg)) 
                                            & (0x67U 
                                               == (0x77U 
                                                   & vlTOPp->control_store__DOT__instruction)))));
    vlTOPp->io_CHOOSE_IMMEDIATE = ((0U != (IData)(vlTOPp->control_store__DOT__stateReg)) 
                                   & ((1U == (IData)(vlTOPp->control_store__DOT__stateReg)) 
                                      & (~ ((0x33U 
                                             == (0x7fU 
                                                 & vlTOPp->control_store__DOT__instruction)) 
                                            | (0x63U 
                                               == (0x7fU 
                                                   & vlTOPp->control_store__DOT__instruction))))));
    vlTOPp->io_DATA_IN = ((0U != (IData)(vlTOPp->control_store__DOT__stateReg)) 
                          & ((1U == (IData)(vlTOPp->control_store__DOT__stateReg)) 
                             & (0x23U == (0x7fU & vlTOPp->control_store__DOT__instruction))));
    vlTOPp->io_STORE_SIZE = ((0U == (IData)(vlTOPp->control_store__DOT__stateReg))
                              ? 1U : ((1U == (IData)(vlTOPp->control_store__DOT__stateReg))
                                       ? ((0x23U == 
                                           (0x7fU & vlTOPp->control_store__DOT__instruction))
                                           ? ((0x2000U 
                                               & vlTOPp->control_store__DOT__instruction)
                                               ? 0U
                                               : (3U 
                                                  & (~ 
                                                     (vlTOPp->control_store__DOT__instruction 
                                                      >> 0xcU))))
                                           : 1U) : 1U));
    vlTOPp->io_STORE_ADDRESS_IN = ((0U != (IData)(vlTOPp->control_store__DOT__stateReg)) 
                                   & ((1U != (IData)(vlTOPp->control_store__DOT__stateReg)) 
                                      & ((2U != (IData)(vlTOPp->control_store__DOT__stateReg)) 
                                         & ((3U == (IData)(vlTOPp->control_store__DOT__stateReg)) 
                                            & (0x23U 
                                               == (0x7fU 
                                                   & vlTOPp->control_store__DOT__instruction))))));
    vlTOPp->io_LOAD_SIZE = ((0U == (IData)(vlTOPp->control_store__DOT__stateReg))
                             ? 0U : ((1U == (IData)(vlTOPp->control_store__DOT__stateReg))
                                      ? 0U : ((2U == (IData)(vlTOPp->control_store__DOT__stateReg))
                                               ? 0U
                                               : ((3U 
                                                   == (IData)(vlTOPp->control_store__DOT__stateReg))
                                                   ? 
                                                  ((2U 
                                                    == 
                                                    (3U 
                                                     & (vlTOPp->control_store__DOT__instruction 
                                                        >> 0xcU)))
                                                    ? 3U
                                                    : 
                                                   (3U 
                                                    & (~ 
                                                       (vlTOPp->control_store__DOT__instruction 
                                                        >> 0xcU))))
                                                   : 0U))));
    vlTOPp->io_LOAD_ADDRESS_IN = ((0U != (IData)(vlTOPp->control_store__DOT__stateReg)) 
                                  & ((1U != (IData)(vlTOPp->control_store__DOT__stateReg)) 
                                     & ((2U != (IData)(vlTOPp->control_store__DOT__stateReg)) 
                                        & ((3U == (IData)(vlTOPp->control_store__DOT__stateReg)) 
                                           & (3U == 
                                              (0x7fU 
                                               & vlTOPp->control_store__DOT__instruction))))));
    vlTOPp->io_EXTENSION = ((0U != (IData)(vlTOPp->control_store__DOT__stateReg)) 
                            & ((1U != (IData)(vlTOPp->control_store__DOT__stateReg)) 
                               & ((2U != (IData)(vlTOPp->control_store__DOT__stateReg)) 
                                  & ((3U == (IData)(vlTOPp->control_store__DOT__stateReg)) 
                                     & (~ (vlTOPp->control_store__DOT__instruction 
                                           >> 0xeU))))));
    vlTOPp->io_BRANCH_SELECT = ((0U == (IData)(vlTOPp->control_store__DOT__stateReg))
                                 ? 1U : ((1U == (IData)(vlTOPp->control_store__DOT__stateReg))
                                          ? 1U : ((2U 
                                                   == (IData)(vlTOPp->control_store__DOT__stateReg))
                                                   ? 
                                                  ((0x63U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->control_store__DOT__instruction))
                                                    ? 
                                                   (3U 
                                                    & (vlTOPp->control_store__DOT__instruction 
                                                       >> 0xdU))
                                                    : 1U)
                                                   : 1U)));
    vlTOPp->io_BRANCH_CONDITION = ((0U != (IData)(vlTOPp->control_store__DOT__stateReg)) 
                                   & ((1U != (IData)(vlTOPp->control_store__DOT__stateReg)) 
                                      & ((2U == (IData)(vlTOPp->control_store__DOT__stateReg)) 
                                         & ((0x63U 
                                             == (0x7fU 
                                                 & vlTOPp->control_store__DOT__instruction)) 
                                            & (~ (vlTOPp->control_store__DOT__instruction 
                                                  >> 0xcU))))));
    vlTOPp->io_BRANCH_ADDRESS_SOURCE_ALU = ((0U != (IData)(vlTOPp->control_store__DOT__stateReg)) 
                                            & ((1U 
                                                != (IData)(vlTOPp->control_store__DOT__stateReg)) 
                                               & ((2U 
                                                   == (IData)(vlTOPp->control_store__DOT__stateReg)) 
                                                  & ((0x67U 
                                                      == 
                                                      (0x77U 
                                                       & vlTOPp->control_store__DOT__instruction)) 
                                                     & (0x67U 
                                                        == 
                                                        (0x7fU 
                                                         & vlTOPp->control_store__DOT__instruction))))));
    vlTOPp->io_IMMEDIATE = ((0U == (IData)(vlTOPp->control_store__DOT__stateReg))
                             ? 0U : ((1U == (IData)(vlTOPp->control_store__DOT__stateReg))
                                      ? ((0x37U == 
                                          (0x7fU & vlTOPp->control_store__DOT__instruction))
                                          ? (0xfffff000U 
                                             & vlTOPp->control_store__DOT__instruction)
                                          : ((0xfffff000U 
                                              & (VL_NEGATE_I((IData)(
                                                                     (1U 
                                                                      & ((IData)(vlTOPp->control_store__DOT___T_15) 
                                                                         >> 0xbU)))) 
                                                 << 0xcU)) 
                                             | (IData)(vlTOPp->control_store__DOT___T_15)))
                                      : 0U));
    vlTOPp->io_BRANCH_IMMEDIATE = ((0U == (IData)(vlTOPp->control_store__DOT__stateReg))
                                    ? 0U : ((1U == (IData)(vlTOPp->control_store__DOT__stateReg))
                                             ? ((0x63U 
                                                 == 
                                                 (0x7fU 
                                                  & vlTOPp->control_store__DOT__instruction))
                                                 ? 
                                                ((0x80000000U 
                                                  & vlTOPp->control_store__DOT__instruction)
                                                  ? 
                                                 (0xffffe000U 
                                                  | (IData)(vlTOPp->control_store__DOT___T_23))
                                                  : (IData)(vlTOPp->control_store__DOT___T_23))
                                                 : 
                                                ((0x80000000U 
                                                  & vlTOPp->control_store__DOT__instruction)
                                                  ? 
                                                 (0xffe00000U 
                                                  | vlTOPp->control_store__DOT___T_24)
                                                  : vlTOPp->control_store__DOT___T_24))
                                             : 0U));
}

void Vcontrol_store::_settle__TOP__3(Vcontrol_store__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_store::_settle__TOP__3\n"); );
    Vcontrol_store* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->io_RECIEVED = vlTOPp->control_store__DOT__RECIEVED;
    vlTOPp->control_store__DOT___T = (0U == (IData)(vlTOPp->control_store__DOT__stateReg));
    vlTOPp->control_store__DOT___T_2 = (1U == (IData)(vlTOPp->control_store__DOT__stateReg));
    vlTOPp->control_store__DOT___T_43 = (2U == (IData)(vlTOPp->control_store__DOT__stateReg));
    vlTOPp->io_UPDATE_PC = ((0U != (IData)(vlTOPp->control_store__DOT__stateReg)) 
                            & ((1U != (IData)(vlTOPp->control_store__DOT__stateReg)) 
                               & (2U == (IData)(vlTOPp->control_store__DOT__stateReg))));
    vlTOPp->io_RS2 = ((0U == (IData)(vlTOPp->control_store__DOT__stateReg))
                       ? 0U : ((1U == (IData)(vlTOPp->control_store__DOT__stateReg))
                                ? (0x1fU & (vlTOPp->control_store__DOT__instruction 
                                            >> 0x14U))
                                : 0U));
    vlTOPp->io_RD = ((0U == (IData)(vlTOPp->control_store__DOT__stateReg))
                      ? 0U : ((1U == (IData)(vlTOPp->control_store__DOT__stateReg))
                               ? 0U : (0x1fU & ((2U 
                                                 == (IData)(vlTOPp->control_store__DOT__stateReg))
                                                 ? 
                                                ((0x67U 
                                                  == 
                                                  (0x77U 
                                                   & vlTOPp->control_store__DOT__instruction))
                                                  ? 
                                                 (vlTOPp->control_store__DOT__instruction 
                                                  >> 7U)
                                                  : 0U)
                                                 : 
                                                ((3U 
                                                  == (IData)(vlTOPp->control_store__DOT__stateReg))
                                                  ? 
                                                 (vlTOPp->control_store__DOT__instruction 
                                                  >> 7U)
                                                  : 
                                                 ((4U 
                                                   == (IData)(vlTOPp->control_store__DOT__stateReg))
                                                   ? 
                                                  (vlTOPp->control_store__DOT__instruction 
                                                   >> 7U)
                                                   : 0U))))));
    vlTOPp->io_ALU_OP = ((0U == (IData)(vlTOPp->control_store__DOT__stateReg))
                          ? 0U : ((1U == (IData)(vlTOPp->control_store__DOT__stateReg))
                                   ? 0U : ((2U == (IData)(vlTOPp->control_store__DOT__stateReg))
                                            ? ((0x13U 
                                                == 
                                                (0x7fU 
                                                 & vlTOPp->control_store__DOT__instruction))
                                                ? (
                                                   (0x18U 
                                                    & (((1U 
                                                         == 
                                                         (3U 
                                                          & (vlTOPp->control_store__DOT__instruction 
                                                             >> 0xcU))) 
                                                        << 3U) 
                                                       & (vlTOPp->control_store__DOT__instruction 
                                                          >> 0x1bU))) 
                                                   | (7U 
                                                      & (vlTOPp->control_store__DOT__instruction 
                                                         >> 0xcU)))
                                                : (
                                                   (0x33U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->control_store__DOT__instruction))
                                                    ? 
                                                   ((8U 
                                                     & (vlTOPp->control_store__DOT__instruction 
                                                        >> 0x1bU)) 
                                                    | (7U 
                                                       & (vlTOPp->control_store__DOT__instruction 
                                                          >> 0xcU)))
                                                    : 0U))
                                            : 0U)));
    vlTOPp->io_PROCEDURE_BRANCHING = ((0U != (IData)(vlTOPp->control_store__DOT__stateReg)) 
                                      & ((1U != (IData)(vlTOPp->control_store__DOT__stateReg)) 
                                         & ((2U == (IData)(vlTOPp->control_store__DOT__stateReg)) 
                                            & (0x67U 
                                               == (0x77U 
                                                   & vlTOPp->control_store__DOT__instruction)))));
    vlTOPp->io_CHOOSE_IMMEDIATE = ((0U != (IData)(vlTOPp->control_store__DOT__stateReg)) 
                                   & ((1U == (IData)(vlTOPp->control_store__DOT__stateReg)) 
                                      & (~ ((0x33U 
                                             == (0x7fU 
                                                 & vlTOPp->control_store__DOT__instruction)) 
                                            | (0x63U 
                                               == (0x7fU 
                                                   & vlTOPp->control_store__DOT__instruction))))));
    vlTOPp->io_DATA_IN = ((0U != (IData)(vlTOPp->control_store__DOT__stateReg)) 
                          & ((1U == (IData)(vlTOPp->control_store__DOT__stateReg)) 
                             & (0x23U == (0x7fU & vlTOPp->control_store__DOT__instruction))));
    vlTOPp->io_STORE_SIZE = ((0U == (IData)(vlTOPp->control_store__DOT__stateReg))
                              ? 1U : ((1U == (IData)(vlTOPp->control_store__DOT__stateReg))
                                       ? ((0x23U == 
                                           (0x7fU & vlTOPp->control_store__DOT__instruction))
                                           ? ((0x2000U 
                                               & vlTOPp->control_store__DOT__instruction)
                                               ? 0U
                                               : (3U 
                                                  & (~ 
                                                     (vlTOPp->control_store__DOT__instruction 
                                                      >> 0xcU))))
                                           : 1U) : 1U));
    vlTOPp->io_STORE_ADDRESS_IN = ((0U != (IData)(vlTOPp->control_store__DOT__stateReg)) 
                                   & ((1U != (IData)(vlTOPp->control_store__DOT__stateReg)) 
                                      & ((2U != (IData)(vlTOPp->control_store__DOT__stateReg)) 
                                         & ((3U == (IData)(vlTOPp->control_store__DOT__stateReg)) 
                                            & (0x23U 
                                               == (0x7fU 
                                                   & vlTOPp->control_store__DOT__instruction))))));
    vlTOPp->io_LOAD_SIZE = ((0U == (IData)(vlTOPp->control_store__DOT__stateReg))
                             ? 0U : ((1U == (IData)(vlTOPp->control_store__DOT__stateReg))
                                      ? 0U : ((2U == (IData)(vlTOPp->control_store__DOT__stateReg))
                                               ? 0U
                                               : ((3U 
                                                   == (IData)(vlTOPp->control_store__DOT__stateReg))
                                                   ? 
                                                  ((2U 
                                                    == 
                                                    (3U 
                                                     & (vlTOPp->control_store__DOT__instruction 
                                                        >> 0xcU)))
                                                    ? 3U
                                                    : 
                                                   (3U 
                                                    & (~ 
                                                       (vlTOPp->control_store__DOT__instruction 
                                                        >> 0xcU))))
                                                   : 0U))));
    vlTOPp->io_LOAD_ADDRESS_IN = ((0U != (IData)(vlTOPp->control_store__DOT__stateReg)) 
                                  & ((1U != (IData)(vlTOPp->control_store__DOT__stateReg)) 
                                     & ((2U != (IData)(vlTOPp->control_store__DOT__stateReg)) 
                                        & ((3U == (IData)(vlTOPp->control_store__DOT__stateReg)) 
                                           & (3U == 
                                              (0x7fU 
                                               & vlTOPp->control_store__DOT__instruction))))));
    vlTOPp->io_EXTENSION = ((0U != (IData)(vlTOPp->control_store__DOT__stateReg)) 
                            & ((1U != (IData)(vlTOPp->control_store__DOT__stateReg)) 
                               & ((2U != (IData)(vlTOPp->control_store__DOT__stateReg)) 
                                  & ((3U == (IData)(vlTOPp->control_store__DOT__stateReg)) 
                                     & (~ (vlTOPp->control_store__DOT__instruction 
                                           >> 0xeU))))));
    vlTOPp->io_BRANCH_SELECT = ((0U == (IData)(vlTOPp->control_store__DOT__stateReg))
                                 ? 1U : ((1U == (IData)(vlTOPp->control_store__DOT__stateReg))
                                          ? 1U : ((2U 
                                                   == (IData)(vlTOPp->control_store__DOT__stateReg))
                                                   ? 
                                                  ((0x63U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->control_store__DOT__instruction))
                                                    ? 
                                                   (3U 
                                                    & (vlTOPp->control_store__DOT__instruction 
                                                       >> 0xdU))
                                                    : 1U)
                                                   : 1U)));
    vlTOPp->io_BRANCH_CONDITION = ((0U != (IData)(vlTOPp->control_store__DOT__stateReg)) 
                                   & ((1U != (IData)(vlTOPp->control_store__DOT__stateReg)) 
                                      & ((2U == (IData)(vlTOPp->control_store__DOT__stateReg)) 
                                         & ((0x63U 
                                             == (0x7fU 
                                                 & vlTOPp->control_store__DOT__instruction)) 
                                            & (~ (vlTOPp->control_store__DOT__instruction 
                                                  >> 0xcU))))));
    vlTOPp->io_BRANCH_ADDRESS_SOURCE_ALU = ((0U != (IData)(vlTOPp->control_store__DOT__stateReg)) 
                                            & ((1U 
                                                != (IData)(vlTOPp->control_store__DOT__stateReg)) 
                                               & ((2U 
                                                   == (IData)(vlTOPp->control_store__DOT__stateReg)) 
                                                  & ((0x67U 
                                                      == 
                                                      (0x77U 
                                                       & vlTOPp->control_store__DOT__instruction)) 
                                                     & (0x67U 
                                                        == 
                                                        (0x7fU 
                                                         & vlTOPp->control_store__DOT__instruction))))));
    vlTOPp->control_store__DOT___GEN_5 = ((IData)(vlTOPp->io_STORE_READY)
                                           ? (IData)(vlTOPp->control_store__DOT__stallState)
                                           : (IData)(vlTOPp->control_store__DOT__stateReg));
    vlTOPp->control_store__DOT___GEN_42 = ((3U == (IData)(vlTOPp->control_store__DOT__stateReg))
                                            ? (IData)(vlTOPp->control_store__DOT__stallState)
                                            : ((4U 
                                                == (IData)(vlTOPp->control_store__DOT__stateReg))
                                                ? ((IData)(vlTOPp->io_LOAD_READY)
                                                    ? (IData)(vlTOPp->control_store__DOT__stallState)
                                                    : (IData)(vlTOPp->control_store__DOT__stateReg))
                                                : (IData)(vlTOPp->control_store__DOT__stallState)));
    vlTOPp->io_RS1 = ((0U == (IData)(vlTOPp->control_store__DOT__stateReg))
                       ? 0U : ((1U == (IData)(vlTOPp->control_store__DOT__stateReg))
                                ? ((0x37U == vlTOPp->io_INSTRUCTION)
                                    ? 0U : (0x1fU & 
                                            (vlTOPp->control_store__DOT__instruction 
                                             >> 0xfU)))
                                : 0U));
    vlTOPp->control_store__DOT___GEN_40 = ((3U == (IData)(vlTOPp->control_store__DOT__stateReg))
                                            ? ((3U 
                                                == 
                                                (0x7fU 
                                                 & vlTOPp->control_store__DOT__instruction))
                                                ? 4U
                                                : 0U)
                                            : ((4U 
                                                == (IData)(vlTOPp->control_store__DOT__stateReg))
                                                ? 0U
                                                : (
                                                   (5U 
                                                    == (IData)(vlTOPp->control_store__DOT__stateReg))
                                                    ? 
                                                   ((1U 
                                                     == (IData)(vlTOPp->control_store__DOT__stallState))
                                                     ? 
                                                    ((IData)(vlTOPp->io_STORE_READY)
                                                      ? (IData)(vlTOPp->control_store__DOT__stallState)
                                                      : (IData)(vlTOPp->control_store__DOT__stateReg))
                                                     : 
                                                    ((4U 
                                                      == (IData)(vlTOPp->control_store__DOT__stallState))
                                                      ? 
                                                     ((IData)(vlTOPp->io_LOAD_READY)
                                                       ? (IData)(vlTOPp->control_store__DOT__stallState)
                                                       : (IData)(vlTOPp->control_store__DOT__stateReg))
                                                      : (IData)(vlTOPp->control_store__DOT__stateReg)))
                                                    : (IData)(vlTOPp->control_store__DOT__stateReg))));
    vlTOPp->control_store__DOT___T_15 = (0xfffU & (
                                                   (0x23U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->control_store__DOT__instruction))
                                                    ? 
                                                   ((0xfe0U 
                                                     & (vlTOPp->control_store__DOT__instruction 
                                                        >> 0x14U)) 
                                                    | (0x1fU 
                                                       & (vlTOPp->control_store__DOT__instruction 
                                                          >> 7U)))
                                                    : 
                                                   (vlTOPp->control_store__DOT__instruction 
                                                    >> 0x14U)));
    vlTOPp->control_store__DOT___T_23 = ((0x1000U & 
                                          (vlTOPp->control_store__DOT__instruction 
                                           >> 0x13U)) 
                                         | ((0x800U 
                                             & (vlTOPp->control_store__DOT__instruction 
                                                << 4U)) 
                                            | ((0x780U 
                                                & (vlTOPp->control_store__DOT__instruction 
                                                   >> 1U)) 
                                               | (0x7eU 
                                                  & (vlTOPp->control_store__DOT__instruction 
                                                     >> 0x18U)))));
    vlTOPp->control_store__DOT___T_24 = ((0x100000U 
                                          & (vlTOPp->control_store__DOT__instruction 
                                             >> 0xbU)) 
                                         | ((0xff000U 
                                             & vlTOPp->control_store__DOT__instruction) 
                                            | ((0x800U 
                                                & (vlTOPp->control_store__DOT__instruction 
                                                   >> 9U)) 
                                               | (0x7feU 
                                                  & (vlTOPp->control_store__DOT__instruction 
                                                     >> 0x14U)))));
    vlTOPp->control_store__DOT___GEN_33 = ((4U == (IData)(vlTOPp->control_store__DOT__stateReg)) 
                                           & (IData)(vlTOPp->io_LOAD_READY));
    vlTOPp->io_IMMEDIATE = ((0U == (IData)(vlTOPp->control_store__DOT__stateReg))
                             ? 0U : ((1U == (IData)(vlTOPp->control_store__DOT__stateReg))
                                      ? ((0x37U == 
                                          (0x7fU & vlTOPp->control_store__DOT__instruction))
                                          ? (0xfffff000U 
                                             & vlTOPp->control_store__DOT__instruction)
                                          : ((0xfffff000U 
                                              & (VL_NEGATE_I((IData)(
                                                                     (1U 
                                                                      & ((IData)(vlTOPp->control_store__DOT___T_15) 
                                                                         >> 0xbU)))) 
                                                 << 0xcU)) 
                                             | (IData)(vlTOPp->control_store__DOT___T_15)))
                                      : 0U));
    vlTOPp->io_BRANCH_IMMEDIATE = ((0U == (IData)(vlTOPp->control_store__DOT__stateReg))
                                    ? 0U : ((1U == (IData)(vlTOPp->control_store__DOT__stateReg))
                                             ? ((0x63U 
                                                 == 
                                                 (0x7fU 
                                                  & vlTOPp->control_store__DOT__instruction))
                                                 ? 
                                                ((0x80000000U 
                                                  & vlTOPp->control_store__DOT__instruction)
                                                  ? 
                                                 (0xffffe000U 
                                                  | (IData)(vlTOPp->control_store__DOT___T_23))
                                                  : (IData)(vlTOPp->control_store__DOT___T_23))
                                                 : 
                                                ((0x80000000U 
                                                  & vlTOPp->control_store__DOT__instruction)
                                                  ? 
                                                 (0xffe00000U 
                                                  | vlTOPp->control_store__DOT___T_24)
                                                  : vlTOPp->control_store__DOT___T_24))
                                             : 0U));
    vlTOPp->io_CHOOSE_MEMORY_LOAD = ((0U != (IData)(vlTOPp->control_store__DOT__stateReg)) 
                                     & ((1U != (IData)(vlTOPp->control_store__DOT__stateReg)) 
                                        & ((2U != (IData)(vlTOPp->control_store__DOT__stateReg)) 
                                           & ((3U != (IData)(vlTOPp->control_store__DOT__stateReg)) 
                                              & (IData)(vlTOPp->control_store__DOT___GEN_33)))));
    vlTOPp->io_WRITE_EN = ((0U != (IData)(vlTOPp->control_store__DOT__stateReg)) 
                           & ((1U != (IData)(vlTOPp->control_store__DOT__stateReg)) 
                              & ((2U == (IData)(vlTOPp->control_store__DOT__stateReg))
                                  ? (0x67U == (0x77U 
                                               & vlTOPp->control_store__DOT__instruction))
                                  : ((3U == (IData)(vlTOPp->control_store__DOT__stateReg))
                                      ? ((0x33U == 
                                          (0x7fU & vlTOPp->control_store__DOT__instruction)) 
                                         | (0x13U == 
                                            (0x7fU 
                                             & vlTOPp->control_store__DOT__instruction)))
                                      : (IData)(vlTOPp->control_store__DOT___GEN_33)))));
}

VL_INLINE_OPT void Vcontrol_store::_combo__TOP__4(Vcontrol_store__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_store::_combo__TOP__4\n"); );
    Vcontrol_store* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->control_store__DOT___GEN_5 = ((IData)(vlTOPp->io_STORE_READY)
                                           ? (IData)(vlTOPp->control_store__DOT__stallState)
                                           : (IData)(vlTOPp->control_store__DOT__stateReg));
    vlTOPp->control_store__DOT___GEN_42 = ((3U == (IData)(vlTOPp->control_store__DOT__stateReg))
                                            ? (IData)(vlTOPp->control_store__DOT__stallState)
                                            : ((4U 
                                                == (IData)(vlTOPp->control_store__DOT__stateReg))
                                                ? ((IData)(vlTOPp->io_LOAD_READY)
                                                    ? (IData)(vlTOPp->control_store__DOT__stallState)
                                                    : (IData)(vlTOPp->control_store__DOT__stateReg))
                                                : (IData)(vlTOPp->control_store__DOT__stallState)));
    vlTOPp->io_RS1 = ((0U == (IData)(vlTOPp->control_store__DOT__stateReg))
                       ? 0U : ((1U == (IData)(vlTOPp->control_store__DOT__stateReg))
                                ? ((0x37U == vlTOPp->io_INSTRUCTION)
                                    ? 0U : (0x1fU & 
                                            (vlTOPp->control_store__DOT__instruction 
                                             >> 0xfU)))
                                : 0U));
    vlTOPp->control_store__DOT___GEN_40 = ((3U == (IData)(vlTOPp->control_store__DOT__stateReg))
                                            ? ((3U 
                                                == 
                                                (0x7fU 
                                                 & vlTOPp->control_store__DOT__instruction))
                                                ? 4U
                                                : 0U)
                                            : ((4U 
                                                == (IData)(vlTOPp->control_store__DOT__stateReg))
                                                ? 0U
                                                : (
                                                   (5U 
                                                    == (IData)(vlTOPp->control_store__DOT__stateReg))
                                                    ? 
                                                   ((1U 
                                                     == (IData)(vlTOPp->control_store__DOT__stallState))
                                                     ? 
                                                    ((IData)(vlTOPp->io_STORE_READY)
                                                      ? (IData)(vlTOPp->control_store__DOT__stallState)
                                                      : (IData)(vlTOPp->control_store__DOT__stateReg))
                                                     : 
                                                    ((4U 
                                                      == (IData)(vlTOPp->control_store__DOT__stallState))
                                                      ? 
                                                     ((IData)(vlTOPp->io_LOAD_READY)
                                                       ? (IData)(vlTOPp->control_store__DOT__stallState)
                                                       : (IData)(vlTOPp->control_store__DOT__stateReg))
                                                      : (IData)(vlTOPp->control_store__DOT__stateReg)))
                                                    : (IData)(vlTOPp->control_store__DOT__stateReg))));
    vlTOPp->control_store__DOT___GEN_33 = ((4U == (IData)(vlTOPp->control_store__DOT__stateReg)) 
                                           & (IData)(vlTOPp->io_LOAD_READY));
    vlTOPp->io_CHOOSE_MEMORY_LOAD = ((0U != (IData)(vlTOPp->control_store__DOT__stateReg)) 
                                     & ((1U != (IData)(vlTOPp->control_store__DOT__stateReg)) 
                                        & ((2U != (IData)(vlTOPp->control_store__DOT__stateReg)) 
                                           & ((3U != (IData)(vlTOPp->control_store__DOT__stateReg)) 
                                              & (IData)(vlTOPp->control_store__DOT___GEN_33)))));
    vlTOPp->io_WRITE_EN = ((0U != (IData)(vlTOPp->control_store__DOT__stateReg)) 
                           & ((1U != (IData)(vlTOPp->control_store__DOT__stateReg)) 
                              & ((2U == (IData)(vlTOPp->control_store__DOT__stateReg))
                                  ? (0x67U == (0x77U 
                                               & vlTOPp->control_store__DOT__instruction))
                                  : ((3U == (IData)(vlTOPp->control_store__DOT__stateReg))
                                      ? ((0x33U == 
                                          (0x7fU & vlTOPp->control_store__DOT__instruction)) 
                                         | (0x13U == 
                                            (0x7fU 
                                             & vlTOPp->control_store__DOT__instruction)))
                                      : (IData)(vlTOPp->control_store__DOT___GEN_33)))));
}

void Vcontrol_store::_eval(Vcontrol_store__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_store::_eval\n"); );
    Vcontrol_store* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock)))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
        vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
    }
    vlTOPp->_combo__TOP__4(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void Vcontrol_store::_eval_initial(Vcontrol_store__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_store::_eval_initial\n"); );
    Vcontrol_store* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void Vcontrol_store::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_store::final\n"); );
    // Variables
    Vcontrol_store__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vcontrol_store* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vcontrol_store::_eval_settle(Vcontrol_store__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_store::_eval_settle\n"); );
    Vcontrol_store* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
}

VL_INLINE_OPT QData Vcontrol_store::_change_request(Vcontrol_store__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_store::_change_request\n"); );
    Vcontrol_store* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vcontrol_store::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_store::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((io_INSTRUCTION_LOADED & 0xfeU))) {
        Verilated::overWidthError("io_INSTRUCTION_LOADED");}
    if (VL_UNLIKELY((io_STORE_READY & 0xfeU))) {
        Verilated::overWidthError("io_STORE_READY");}
    if (VL_UNLIKELY((io_LOAD_READY & 0xfeU))) {
        Verilated::overWidthError("io_LOAD_READY");}
}
#endif  // VL_DEBUG

void Vcontrol_store::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_store::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    io_INSTRUCTION = VL_RAND_RESET_I(32);
    io_RECIEVED = VL_RAND_RESET_I(1);
    io_INSTRUCTION_LOADED = VL_RAND_RESET_I(1);
    io_RS1 = VL_RAND_RESET_I(5);
    io_RS2 = VL_RAND_RESET_I(5);
    io_RD = VL_RAND_RESET_I(5);
    io_WRITE_EN = VL_RAND_RESET_I(1);
    io_ALU_OP = VL_RAND_RESET_I(4);
    io_PROCEDURE_BRANCHING = VL_RAND_RESET_I(1);
    io_CHOOSE_IMMEDIATE = VL_RAND_RESET_I(1);
    io_CHOOSE_MEMORY_LOAD = VL_RAND_RESET_I(1);
    io_IMMEDIATE = VL_RAND_RESET_I(32);
    io_BRANCH_IMMEDIATE = VL_RAND_RESET_I(32);
    io_ALU_RD = VL_RAND_RESET_I(5);
    io_STORE_READY = VL_RAND_RESET_I(1);
    io_DATA_IN = VL_RAND_RESET_I(1);
    io_STORE_SIZE = VL_RAND_RESET_I(2);
    io_STORE_ADDRESS_IN = VL_RAND_RESET_I(1);
    io_LOAD_READY = VL_RAND_RESET_I(1);
    io_LOAD_SIZE = VL_RAND_RESET_I(2);
    io_LOAD_ADDRESS_IN = VL_RAND_RESET_I(1);
    io_EXTENSION = VL_RAND_RESET_I(1);
    io_BRANCH_SELECT = VL_RAND_RESET_I(2);
    io_BRANCH_CONDITION = VL_RAND_RESET_I(1);
    io_BRANCH_ADDRESS_SOURCE_ALU = VL_RAND_RESET_I(1);
    io_UPDATE_PC = VL_RAND_RESET_I(1);
    control_store__DOT__stateReg = VL_RAND_RESET_I(3);
    control_store__DOT__stallState = VL_RAND_RESET_I(3);
    control_store__DOT__instruction = VL_RAND_RESET_I(32);
    control_store__DOT__RECIEVED = VL_RAND_RESET_I(1);
    control_store__DOT___T = VL_RAND_RESET_I(1);
    control_store__DOT___T_2 = VL_RAND_RESET_I(1);
    control_store__DOT___T_15 = VL_RAND_RESET_I(12);
    control_store__DOT___T_23 = VL_RAND_RESET_I(13);
    control_store__DOT___T_24 = VL_RAND_RESET_I(21);
    control_store__DOT___GEN_5 = VL_RAND_RESET_I(3);
    control_store__DOT___T_43 = VL_RAND_RESET_I(1);
    control_store__DOT___GEN_33 = VL_RAND_RESET_I(1);
    control_store__DOT___GEN_40 = VL_RAND_RESET_I(3);
    control_store__DOT___GEN_42 = VL_RAND_RESET_I(3);
    __Vm_traceActivity = 0;
}
