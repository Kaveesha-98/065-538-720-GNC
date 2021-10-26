// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vregister_file.h for the primary calling header

#include "Vregister_file.h"
#include "Vregister_file__Syms.h"

//==========

VL_CTOR_IMP(Vregister_file) {
    Vregister_file__Syms* __restrict vlSymsp = __VlSymsp = new Vregister_file__Syms(this, name());
    Vregister_file* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vregister_file::__Vconfigure(Vregister_file__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vregister_file::~Vregister_file() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void Vregister_file::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vregister_file::eval\n"); );
    Vregister_file__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vregister_file* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("register_file.v", 3, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vregister_file::_eval_initial_loop(Vregister_file__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("register_file.v", 3, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vregister_file::_sequent__TOP__1(Vregister_file__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_file::_sequent__TOP__1\n"); );
    Vregister_file* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((0x18U == (IData)(vlTOPp->io_RD))) {
            vlTOPp->register_file__DOT__registerFile_24 
                = vlTOPp->io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((0x1aU == (IData)(vlTOPp->io_RD))) {
            vlTOPp->register_file__DOT__registerFile_26 
                = vlTOPp->io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((0x17U == (IData)(vlTOPp->io_RD))) {
            vlTOPp->register_file__DOT__registerFile_23 
                = vlTOPp->io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((0x19U == (IData)(vlTOPp->io_RD))) {
            vlTOPp->register_file__DOT__registerFile_25 
                = vlTOPp->io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((0x16U == (IData)(vlTOPp->io_RD))) {
            vlTOPp->register_file__DOT__registerFile_22 
                = vlTOPp->io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((0x1bU == (IData)(vlTOPp->io_RD))) {
            vlTOPp->register_file__DOT__registerFile_27 
                = vlTOPp->io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((0x1cU == (IData)(vlTOPp->io_RD))) {
            vlTOPp->register_file__DOT__registerFile_28 
                = vlTOPp->io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((0x1dU == (IData)(vlTOPp->io_RD))) {
            vlTOPp->register_file__DOT__registerFile_29 
                = vlTOPp->io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((0x1eU == (IData)(vlTOPp->io_RD))) {
            vlTOPp->register_file__DOT__registerFile_30 
                = vlTOPp->io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((0x1fU == (IData)(vlTOPp->io_RD))) {
            vlTOPp->register_file__DOT__registerFile_31 
                = vlTOPp->io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((0x12U == (IData)(vlTOPp->io_RD))) {
            vlTOPp->register_file__DOT__registerFile_18 
                = vlTOPp->io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((0x11U == (IData)(vlTOPp->io_RD))) {
            vlTOPp->register_file__DOT__registerFile_17 
                = vlTOPp->io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((0x10U == (IData)(vlTOPp->io_RD))) {
            vlTOPp->register_file__DOT__registerFile_16 
                = vlTOPp->io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((0xfU == (IData)(vlTOPp->io_RD))) {
            vlTOPp->register_file__DOT__registerFile_15 
                = vlTOPp->io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((6U == (IData)(vlTOPp->io_RD))) {
            vlTOPp->register_file__DOT__registerFile_6 
                = vlTOPp->io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((5U == (IData)(vlTOPp->io_RD))) {
            vlTOPp->register_file__DOT__registerFile_5 
                = vlTOPp->io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((0xeU == (IData)(vlTOPp->io_RD))) {
            vlTOPp->register_file__DOT__registerFile_14 
                = vlTOPp->io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((4U == (IData)(vlTOPp->io_RD))) {
            vlTOPp->register_file__DOT__registerFile_4 
                = vlTOPp->io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((3U == (IData)(vlTOPp->io_RD))) {
            vlTOPp->register_file__DOT__registerFile_3 
                = vlTOPp->io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((0U == (IData)(vlTOPp->io_RD))) {
            vlTOPp->register_file__DOT__registerFile_0 
                = vlTOPp->io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((2U == (IData)(vlTOPp->io_RD))) {
            vlTOPp->register_file__DOT__registerFile_2 
                = vlTOPp->io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((0xdU == (IData)(vlTOPp->io_RD))) {
            vlTOPp->register_file__DOT__registerFile_13 
                = vlTOPp->io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((0x14U == (IData)(vlTOPp->io_RD))) {
            vlTOPp->register_file__DOT__registerFile_20 
                = vlTOPp->io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((0xaU == (IData)(vlTOPp->io_RD))) {
            vlTOPp->register_file__DOT__registerFile_10 
                = vlTOPp->io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((0x13U == (IData)(vlTOPp->io_RD))) {
            vlTOPp->register_file__DOT__registerFile_19 
                = vlTOPp->io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((9U == (IData)(vlTOPp->io_RD))) {
            vlTOPp->register_file__DOT__registerFile_9 
                = vlTOPp->io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((1U == (IData)(vlTOPp->io_RD))) {
            vlTOPp->register_file__DOT__registerFile_1 
                = vlTOPp->io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((0x15U == (IData)(vlTOPp->io_RD))) {
            vlTOPp->register_file__DOT__registerFile_21 
                = vlTOPp->io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((0xbU == (IData)(vlTOPp->io_RD))) {
            vlTOPp->register_file__DOT__registerFile_11 
                = vlTOPp->io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((0xcU == (IData)(vlTOPp->io_RD))) {
            vlTOPp->register_file__DOT__registerFile_12 
                = vlTOPp->io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((7U == (IData)(vlTOPp->io_RD))) {
            vlTOPp->register_file__DOT__registerFile_7 
                = vlTOPp->io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((8U == (IData)(vlTOPp->io_RD))) {
            vlTOPp->register_file__DOT__registerFile_8 
                = vlTOPp->io_rdData;
        }
    }
}

VL_INLINE_OPT void Vregister_file::_settle__TOP__2(Vregister_file__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_file::_settle__TOP__2\n"); );
    Vregister_file* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->register_file__DOT___GEN_21 = ((0x15U == (IData)(vlTOPp->io_RS1))
                                            ? vlTOPp->register_file__DOT__registerFile_21
                                            : ((0x14U 
                                                == (IData)(vlTOPp->io_RS1))
                                                ? vlTOPp->register_file__DOT__registerFile_20
                                                : (
                                                   (0x13U 
                                                    == (IData)(vlTOPp->io_RS1))
                                                    ? vlTOPp->register_file__DOT__registerFile_19
                                                    : 
                                                   ((0x12U 
                                                     == (IData)(vlTOPp->io_RS1))
                                                     ? vlTOPp->register_file__DOT__registerFile_18
                                                     : 
                                                    ((0x11U 
                                                      == (IData)(vlTOPp->io_RS1))
                                                      ? vlTOPp->register_file__DOT__registerFile_17
                                                      : 
                                                     ((0x10U 
                                                       == (IData)(vlTOPp->io_RS1))
                                                       ? vlTOPp->register_file__DOT__registerFile_16
                                                       : 
                                                      ((0xfU 
                                                        == (IData)(vlTOPp->io_RS1))
                                                        ? vlTOPp->register_file__DOT__registerFile_15
                                                        : 
                                                       ((0xeU 
                                                         == (IData)(vlTOPp->io_RS1))
                                                         ? vlTOPp->register_file__DOT__registerFile_14
                                                         : 
                                                        ((0xdU 
                                                          == (IData)(vlTOPp->io_RS1))
                                                          ? vlTOPp->register_file__DOT__registerFile_13
                                                          : 
                                                         ((0xcU 
                                                           == (IData)(vlTOPp->io_RS1))
                                                           ? vlTOPp->register_file__DOT__registerFile_12
                                                           : 
                                                          ((0xbU 
                                                            == (IData)(vlTOPp->io_RS1))
                                                            ? vlTOPp->register_file__DOT__registerFile_11
                                                            : 
                                                           ((0xaU 
                                                             == (IData)(vlTOPp->io_RS1))
                                                             ? vlTOPp->register_file__DOT__registerFile_10
                                                             : 
                                                            ((9U 
                                                              == (IData)(vlTOPp->io_RS1))
                                                              ? vlTOPp->register_file__DOT__registerFile_9
                                                              : 
                                                             ((8U 
                                                               == (IData)(vlTOPp->io_RS1))
                                                               ? vlTOPp->register_file__DOT__registerFile_8
                                                               : 
                                                              ((7U 
                                                                == (IData)(vlTOPp->io_RS1))
                                                                ? vlTOPp->register_file__DOT__registerFile_7
                                                                : 
                                                               ((6U 
                                                                 == (IData)(vlTOPp->io_RS1))
                                                                 ? vlTOPp->register_file__DOT__registerFile_6
                                                                 : 
                                                                ((5U 
                                                                  == (IData)(vlTOPp->io_RS1))
                                                                  ? vlTOPp->register_file__DOT__registerFile_5
                                                                  : 
                                                                 ((4U 
                                                                   == (IData)(vlTOPp->io_RS1))
                                                                   ? vlTOPp->register_file__DOT__registerFile_4
                                                                   : 
                                                                  ((3U 
                                                                    == (IData)(vlTOPp->io_RS1))
                                                                    ? vlTOPp->register_file__DOT__registerFile_3
                                                                    : 
                                                                   ((2U 
                                                                     == (IData)(vlTOPp->io_RS1))
                                                                     ? vlTOPp->register_file__DOT__registerFile_2
                                                                     : 
                                                                    ((1U 
                                                                      == (IData)(vlTOPp->io_RS1))
                                                                      ? vlTOPp->register_file__DOT__registerFile_1
                                                                      : vlTOPp->register_file__DOT__registerFile_0)))))))))))))))))))));
    vlTOPp->register_file__DOT___GEN_54 = ((0x15U == (IData)(vlTOPp->io_RS2))
                                            ? vlTOPp->register_file__DOT__registerFile_21
                                            : ((0x14U 
                                                == (IData)(vlTOPp->io_RS2))
                                                ? vlTOPp->register_file__DOT__registerFile_20
                                                : (
                                                   (0x13U 
                                                    == (IData)(vlTOPp->io_RS2))
                                                    ? vlTOPp->register_file__DOT__registerFile_19
                                                    : 
                                                   ((0x12U 
                                                     == (IData)(vlTOPp->io_RS2))
                                                     ? vlTOPp->register_file__DOT__registerFile_18
                                                     : 
                                                    ((0x11U 
                                                      == (IData)(vlTOPp->io_RS2))
                                                      ? vlTOPp->register_file__DOT__registerFile_17
                                                      : 
                                                     ((0x10U 
                                                       == (IData)(vlTOPp->io_RS2))
                                                       ? vlTOPp->register_file__DOT__registerFile_16
                                                       : 
                                                      ((0xfU 
                                                        == (IData)(vlTOPp->io_RS2))
                                                        ? vlTOPp->register_file__DOT__registerFile_15
                                                        : 
                                                       ((0xeU 
                                                         == (IData)(vlTOPp->io_RS2))
                                                         ? vlTOPp->register_file__DOT__registerFile_14
                                                         : 
                                                        ((0xdU 
                                                          == (IData)(vlTOPp->io_RS2))
                                                          ? vlTOPp->register_file__DOT__registerFile_13
                                                          : 
                                                         ((0xcU 
                                                           == (IData)(vlTOPp->io_RS2))
                                                           ? vlTOPp->register_file__DOT__registerFile_12
                                                           : 
                                                          ((0xbU 
                                                            == (IData)(vlTOPp->io_RS2))
                                                            ? vlTOPp->register_file__DOT__registerFile_11
                                                            : 
                                                           ((0xaU 
                                                             == (IData)(vlTOPp->io_RS2))
                                                             ? vlTOPp->register_file__DOT__registerFile_10
                                                             : 
                                                            ((9U 
                                                              == (IData)(vlTOPp->io_RS2))
                                                              ? vlTOPp->register_file__DOT__registerFile_9
                                                              : 
                                                             ((8U 
                                                               == (IData)(vlTOPp->io_RS2))
                                                               ? vlTOPp->register_file__DOT__registerFile_8
                                                               : 
                                                              ((7U 
                                                                == (IData)(vlTOPp->io_RS2))
                                                                ? vlTOPp->register_file__DOT__registerFile_7
                                                                : 
                                                               ((6U 
                                                                 == (IData)(vlTOPp->io_RS2))
                                                                 ? vlTOPp->register_file__DOT__registerFile_6
                                                                 : 
                                                                ((5U 
                                                                  == (IData)(vlTOPp->io_RS2))
                                                                  ? vlTOPp->register_file__DOT__registerFile_5
                                                                  : 
                                                                 ((4U 
                                                                   == (IData)(vlTOPp->io_RS2))
                                                                   ? vlTOPp->register_file__DOT__registerFile_4
                                                                   : 
                                                                  ((3U 
                                                                    == (IData)(vlTOPp->io_RS2))
                                                                    ? vlTOPp->register_file__DOT__registerFile_3
                                                                    : 
                                                                   ((2U 
                                                                     == (IData)(vlTOPp->io_RS2))
                                                                     ? vlTOPp->register_file__DOT__registerFile_2
                                                                     : 
                                                                    ((1U 
                                                                      == (IData)(vlTOPp->io_RS2))
                                                                      ? vlTOPp->register_file__DOT__registerFile_1
                                                                      : vlTOPp->register_file__DOT__registerFile_0)))))))))))))))))))));
    vlTOPp->io_rs1Data = ((0U == (IData)(vlTOPp->io_RS1))
                           ? 0U : ((0x1fU == (IData)(vlTOPp->io_RS1))
                                    ? vlTOPp->register_file__DOT__registerFile_31
                                    : ((0x1eU == (IData)(vlTOPp->io_RS1))
                                        ? vlTOPp->register_file__DOT__registerFile_30
                                        : ((0x1dU == (IData)(vlTOPp->io_RS1))
                                            ? vlTOPp->register_file__DOT__registerFile_29
                                            : ((0x1cU 
                                                == (IData)(vlTOPp->io_RS1))
                                                ? vlTOPp->register_file__DOT__registerFile_28
                                                : (
                                                   (0x1bU 
                                                    == (IData)(vlTOPp->io_RS1))
                                                    ? vlTOPp->register_file__DOT__registerFile_27
                                                    : 
                                                   ((0x1aU 
                                                     == (IData)(vlTOPp->io_RS1))
                                                     ? vlTOPp->register_file__DOT__registerFile_26
                                                     : 
                                                    ((0x19U 
                                                      == (IData)(vlTOPp->io_RS1))
                                                      ? vlTOPp->register_file__DOT__registerFile_25
                                                      : 
                                                     ((0x18U 
                                                       == (IData)(vlTOPp->io_RS1))
                                                       ? vlTOPp->register_file__DOT__registerFile_24
                                                       : 
                                                      ((0x17U 
                                                        == (IData)(vlTOPp->io_RS1))
                                                        ? vlTOPp->register_file__DOT__registerFile_23
                                                        : 
                                                       ((0x16U 
                                                         == (IData)(vlTOPp->io_RS1))
                                                         ? vlTOPp->register_file__DOT__registerFile_22
                                                         : vlTOPp->register_file__DOT___GEN_21)))))))))));
    vlTOPp->io_rs2Data = ((0U == (IData)(vlTOPp->io_RS2))
                           ? 0U : ((0x1fU == (IData)(vlTOPp->io_RS2))
                                    ? vlTOPp->register_file__DOT__registerFile_31
                                    : ((0x1eU == (IData)(vlTOPp->io_RS2))
                                        ? vlTOPp->register_file__DOT__registerFile_30
                                        : ((0x1dU == (IData)(vlTOPp->io_RS2))
                                            ? vlTOPp->register_file__DOT__registerFile_29
                                            : ((0x1cU 
                                                == (IData)(vlTOPp->io_RS2))
                                                ? vlTOPp->register_file__DOT__registerFile_28
                                                : (
                                                   (0x1bU 
                                                    == (IData)(vlTOPp->io_RS2))
                                                    ? vlTOPp->register_file__DOT__registerFile_27
                                                    : 
                                                   ((0x1aU 
                                                     == (IData)(vlTOPp->io_RS2))
                                                     ? vlTOPp->register_file__DOT__registerFile_26
                                                     : 
                                                    ((0x19U 
                                                      == (IData)(vlTOPp->io_RS2))
                                                      ? vlTOPp->register_file__DOT__registerFile_25
                                                      : 
                                                     ((0x18U 
                                                       == (IData)(vlTOPp->io_RS2))
                                                       ? vlTOPp->register_file__DOT__registerFile_24
                                                       : 
                                                      ((0x17U 
                                                        == (IData)(vlTOPp->io_RS2))
                                                        ? vlTOPp->register_file__DOT__registerFile_23
                                                        : 
                                                       ((0x16U 
                                                         == (IData)(vlTOPp->io_RS2))
                                                         ? vlTOPp->register_file__DOT__registerFile_22
                                                         : vlTOPp->register_file__DOT___GEN_54)))))))))));
}

void Vregister_file::_eval(Vregister_file__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_file::_eval\n"); );
    Vregister_file* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
        vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
    }
    vlTOPp->_settle__TOP__2(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void Vregister_file::_eval_initial(Vregister_file__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_file::_eval_initial\n"); );
    Vregister_file* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void Vregister_file::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_file::final\n"); );
    // Variables
    Vregister_file__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vregister_file* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vregister_file::_eval_settle(Vregister_file__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_file::_eval_settle\n"); );
    Vregister_file* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

VL_INLINE_OPT QData Vregister_file::_change_request(Vregister_file__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_file::_change_request\n"); );
    Vregister_file* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vregister_file::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_file::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((io_RS1 & 0xe0U))) {
        Verilated::overWidthError("io_RS1");}
    if (VL_UNLIKELY((io_RS2 & 0xe0U))) {
        Verilated::overWidthError("io_RS2");}
    if (VL_UNLIKELY((io_RD & 0xe0U))) {
        Verilated::overWidthError("io_RD");}
    if (VL_UNLIKELY((io_WRITE_EN & 0xfeU))) {
        Verilated::overWidthError("io_WRITE_EN");}
}
#endif  // VL_DEBUG

void Vregister_file::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_file::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    io_RS1 = VL_RAND_RESET_I(5);
    io_RS2 = VL_RAND_RESET_I(5);
    io_RD = VL_RAND_RESET_I(5);
    io_WRITE_EN = VL_RAND_RESET_I(1);
    io_rs1Data = VL_RAND_RESET_I(32);
    io_rs2Data = VL_RAND_RESET_I(32);
    io_rdData = VL_RAND_RESET_I(32);
    register_file__DOT__registerFile_0 = VL_RAND_RESET_I(32);
    register_file__DOT__registerFile_1 = VL_RAND_RESET_I(32);
    register_file__DOT__registerFile_2 = VL_RAND_RESET_I(32);
    register_file__DOT__registerFile_3 = VL_RAND_RESET_I(32);
    register_file__DOT__registerFile_4 = VL_RAND_RESET_I(32);
    register_file__DOT__registerFile_5 = VL_RAND_RESET_I(32);
    register_file__DOT__registerFile_6 = VL_RAND_RESET_I(32);
    register_file__DOT__registerFile_7 = VL_RAND_RESET_I(32);
    register_file__DOT__registerFile_8 = VL_RAND_RESET_I(32);
    register_file__DOT__registerFile_9 = VL_RAND_RESET_I(32);
    register_file__DOT__registerFile_10 = VL_RAND_RESET_I(32);
    register_file__DOT__registerFile_11 = VL_RAND_RESET_I(32);
    register_file__DOT__registerFile_12 = VL_RAND_RESET_I(32);
    register_file__DOT__registerFile_13 = VL_RAND_RESET_I(32);
    register_file__DOT__registerFile_14 = VL_RAND_RESET_I(32);
    register_file__DOT__registerFile_15 = VL_RAND_RESET_I(32);
    register_file__DOT__registerFile_16 = VL_RAND_RESET_I(32);
    register_file__DOT__registerFile_17 = VL_RAND_RESET_I(32);
    register_file__DOT__registerFile_18 = VL_RAND_RESET_I(32);
    register_file__DOT__registerFile_19 = VL_RAND_RESET_I(32);
    register_file__DOT__registerFile_20 = VL_RAND_RESET_I(32);
    register_file__DOT__registerFile_21 = VL_RAND_RESET_I(32);
    register_file__DOT__registerFile_22 = VL_RAND_RESET_I(32);
    register_file__DOT__registerFile_23 = VL_RAND_RESET_I(32);
    register_file__DOT__registerFile_24 = VL_RAND_RESET_I(32);
    register_file__DOT__registerFile_25 = VL_RAND_RESET_I(32);
    register_file__DOT__registerFile_26 = VL_RAND_RESET_I(32);
    register_file__DOT__registerFile_27 = VL_RAND_RESET_I(32);
    register_file__DOT__registerFile_28 = VL_RAND_RESET_I(32);
    register_file__DOT__registerFile_29 = VL_RAND_RESET_I(32);
    register_file__DOT__registerFile_30 = VL_RAND_RESET_I(32);
    register_file__DOT__registerFile_31 = VL_RAND_RESET_I(32);
    register_file__DOT___GEN_21 = VL_RAND_RESET_I(32);
    register_file__DOT___GEN_54 = VL_RAND_RESET_I(32);
    __Vm_traceActivity = 0;
}
