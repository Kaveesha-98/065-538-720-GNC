// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdata_path.h for the primary calling header

#include "Vdata_path.h"
#include "Vdata_path__Syms.h"

//==========

VL_CTOR_IMP(Vdata_path) {
    Vdata_path__Syms* __restrict vlSymsp = __VlSymsp = new Vdata_path__Syms(this, name());
    Vdata_path* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vdata_path::__Vconfigure(Vdata_path__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vdata_path::~Vdata_path() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void Vdata_path::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vdata_path::eval\n"); );
    Vdata_path__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vdata_path* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("data_path.v", 541, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vdata_path::_eval_initial_loop(Vdata_path__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("data_path.v", 541, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vdata_path::_sequent__TOP__1(Vdata_path__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdata_path::_sequent__TOP__1\n"); );
    Vdata_path* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    IData/*31:0*/ __Vdly__data_path__DOT__cpuALU__DOT__ALUoutput;
    // Body
    __Vdly__data_path__DOT__cpuALU__DOT__ALUoutput 
        = vlTOPp->data_path__DOT__cpuALU__DOT__ALUoutput;
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((0x12U == (IData)(vlTOPp->io_RD))) {
            vlTOPp->data_path__DOT__registerFile__DOT__registerFile_18 
                = vlTOPp->data_path__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((0x11U == (IData)(vlTOPp->io_RD))) {
            vlTOPp->data_path__DOT__registerFile__DOT__registerFile_17 
                = vlTOPp->data_path__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((0x10U == (IData)(vlTOPp->io_RD))) {
            vlTOPp->data_path__DOT__registerFile__DOT__registerFile_16 
                = vlTOPp->data_path__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((0xfU == (IData)(vlTOPp->io_RD))) {
            vlTOPp->data_path__DOT__registerFile__DOT__registerFile_15 
                = vlTOPp->data_path__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((6U == (IData)(vlTOPp->io_RD))) {
            vlTOPp->data_path__DOT__registerFile__DOT__registerFile_6 
                = vlTOPp->data_path__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((5U == (IData)(vlTOPp->io_RD))) {
            vlTOPp->data_path__DOT__registerFile__DOT__registerFile_5 
                = vlTOPp->data_path__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((0xeU == (IData)(vlTOPp->io_RD))) {
            vlTOPp->data_path__DOT__registerFile__DOT__registerFile_14 
                = vlTOPp->data_path__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((4U == (IData)(vlTOPp->io_RD))) {
            vlTOPp->data_path__DOT__registerFile__DOT__registerFile_4 
                = vlTOPp->data_path__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((3U == (IData)(vlTOPp->io_RD))) {
            vlTOPp->data_path__DOT__registerFile__DOT__registerFile_3 
                = vlTOPp->data_path__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((0U == (IData)(vlTOPp->io_RD))) {
            vlTOPp->data_path__DOT__registerFile__DOT__registerFile_0 
                = vlTOPp->data_path__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((2U == (IData)(vlTOPp->io_RD))) {
            vlTOPp->data_path__DOT__registerFile__DOT__registerFile_2 
                = vlTOPp->data_path__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((0xdU == (IData)(vlTOPp->io_RD))) {
            vlTOPp->data_path__DOT__registerFile__DOT__registerFile_13 
                = vlTOPp->data_path__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((0x14U == (IData)(vlTOPp->io_RD))) {
            vlTOPp->data_path__DOT__registerFile__DOT__registerFile_20 
                = vlTOPp->data_path__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((0xaU == (IData)(vlTOPp->io_RD))) {
            vlTOPp->data_path__DOT__registerFile__DOT__registerFile_10 
                = vlTOPp->data_path__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((0x13U == (IData)(vlTOPp->io_RD))) {
            vlTOPp->data_path__DOT__registerFile__DOT__registerFile_19 
                = vlTOPp->data_path__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((9U == (IData)(vlTOPp->io_RD))) {
            vlTOPp->data_path__DOT__registerFile__DOT__registerFile_9 
                = vlTOPp->data_path__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((1U == (IData)(vlTOPp->io_RD))) {
            vlTOPp->data_path__DOT__registerFile__DOT__registerFile_1 
                = vlTOPp->data_path__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((0x15U == (IData)(vlTOPp->io_RD))) {
            vlTOPp->data_path__DOT__registerFile__DOT__registerFile_21 
                = vlTOPp->data_path__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((0xbU == (IData)(vlTOPp->io_RD))) {
            vlTOPp->data_path__DOT__registerFile__DOT__registerFile_11 
                = vlTOPp->data_path__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((0xcU == (IData)(vlTOPp->io_RD))) {
            vlTOPp->data_path__DOT__registerFile__DOT__registerFile_12 
                = vlTOPp->data_path__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((7U == (IData)(vlTOPp->io_RD))) {
            vlTOPp->data_path__DOT__registerFile__DOT__registerFile_7 
                = vlTOPp->data_path__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((8U == (IData)(vlTOPp->io_RD))) {
            vlTOPp->data_path__DOT__registerFile__DOT__registerFile_8 
                = vlTOPp->data_path__DOT__registerFile_io_rdData;
        }
    }
    vlTOPp->data_path__DOT__cpuALU__DOT__SIGNED_LESS_THAN 
        = ((~ (IData)(vlTOPp->reset)) & VL_LTS_III(1,32,32, vlTOPp->data_path__DOT__ALU_in1, vlTOPp->data_path__DOT__ALU_in2));
    vlTOPp->data_path__DOT__cpuALU__DOT__LESS_THAN 
        = ((~ (IData)(vlTOPp->reset)) & (vlTOPp->data_path__DOT__ALU_in1 
                                         < vlTOPp->data_path__DOT__ALU_in2));
    vlTOPp->data_path__DOT__cpuALU__DOT__EQUAL = ((IData)(vlTOPp->reset) 
                                                  | (vlTOPp->data_path__DOT__ALU_in1 
                                                     == vlTOPp->data_path__DOT__ALU_in2));
    __Vdly__data_path__DOT__cpuALU__DOT__ALUoutput 
        = ((IData)(vlTOPp->reset) ? 0U : (IData)(((vlTOPp->data_path__DOT__ALU_in1 
                                                   < vlTOPp->data_path__DOT__ALU_in2)
                                                   ? 
                                                  ((3U 
                                                    == (IData)(vlTOPp->io_ALU_OP))
                                                    ? VL_ULL(1)
                                                    : vlTOPp->data_path__DOT__cpuALU__DOT___GEN_11)
                                                   : vlTOPp->data_path__DOT__cpuALU__DOT___GEN_11)));
    vlTOPp->io_SIGNED_LESS_THAN = vlTOPp->data_path__DOT__cpuALU__DOT__SIGNED_LESS_THAN;
    vlTOPp->io_LESS_THAN = vlTOPp->data_path__DOT__cpuALU__DOT__LESS_THAN;
    vlTOPp->io_EQUAL = vlTOPp->data_path__DOT__cpuALU__DOT__EQUAL;
    vlTOPp->data_path__DOT__ALU_in2 = ((IData)(vlTOPp->reset)
                                        ? 0U : ((IData)(vlTOPp->io_CHOOSE_IMMEDIATE)
                                                 ? vlTOPp->io_IMMEDIATE
                                                 : 
                                                ((0U 
                                                  == (IData)(vlTOPp->io_RS2))
                                                  ? 0U
                                                  : 
                                                 (((IData)(vlTOPp->io_RS2) 
                                                   == (IData)(vlTOPp->io_RD))
                                                   ? vlTOPp->data_path__DOT__rdData
                                                   : vlTOPp->data_path__DOT__rs2_ALU))));
    vlTOPp->data_path__DOT__ALU_in1 = ((IData)(vlTOPp->reset)
                                        ? 0U : ((IData)(vlTOPp->io_CHOOSE_PC)
                                                 ? vlTOPp->io_PC
                                                 : 
                                                ((0U 
                                                  == (IData)(vlTOPp->io_RS1))
                                                  ? 0U
                                                  : 
                                                 (((IData)(vlTOPp->io_RS1) 
                                                   == (IData)(vlTOPp->io_RD))
                                                   ? vlTOPp->data_path__DOT__rdData
                                                   : 
                                                  (((IData)(vlTOPp->io_RS1) 
                                                    == (IData)(vlTOPp->io_ALU_RD))
                                                    ? vlTOPp->data_path__DOT__cpuALU__DOT__ALUoutput
                                                    : 
                                                   ((0U 
                                                     == (IData)(vlTOPp->io_RS1))
                                                     ? 0U
                                                     : 
                                                    ((0x1fU 
                                                      == (IData)(vlTOPp->io_RS1))
                                                      ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_31
                                                      : 
                                                     ((0x1eU 
                                                       == (IData)(vlTOPp->io_RS1))
                                                       ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_30
                                                       : 
                                                      ((0x1dU 
                                                        == (IData)(vlTOPp->io_RS1))
                                                        ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_29
                                                        : 
                                                       ((0x1cU 
                                                         == (IData)(vlTOPp->io_RS1))
                                                         ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_28
                                                         : 
                                                        ((0x1bU 
                                                          == (IData)(vlTOPp->io_RS1))
                                                          ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_27
                                                          : 
                                                         ((0x1aU 
                                                           == (IData)(vlTOPp->io_RS1))
                                                           ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_26
                                                           : 
                                                          ((0x19U 
                                                            == (IData)(vlTOPp->io_RS1))
                                                            ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_25
                                                            : 
                                                           ((0x18U 
                                                             == (IData)(vlTOPp->io_RS1))
                                                             ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_24
                                                             : 
                                                            ((0x17U 
                                                              == (IData)(vlTOPp->io_RS1))
                                                              ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_23
                                                              : 
                                                             ((0x16U 
                                                               == (IData)(vlTOPp->io_RS1))
                                                               ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_22
                                                               : vlTOPp->data_path__DOT__registerFile__DOT___GEN_21))))))))))))))));
    vlTOPp->data_path__DOT__cpuALU__DOT__ALUoutput 
        = __Vdly__data_path__DOT__cpuALU__DOT__ALUoutput;
    vlTOPp->io_store_address = vlTOPp->data_path__DOT__cpuALU__DOT__ALUoutput;
    vlTOPp->io_load_address = vlTOPp->data_path__DOT__cpuALU__DOT__ALUoutput;
    vlTOPp->io_instruction_next_address = vlTOPp->data_path__DOT__cpuALU__DOT__ALUoutput;
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((0x1fU == (IData)(vlTOPp->io_RD))) {
            vlTOPp->data_path__DOT__registerFile__DOT__registerFile_31 
                = vlTOPp->data_path__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((0x1eU == (IData)(vlTOPp->io_RD))) {
            vlTOPp->data_path__DOT__registerFile__DOT__registerFile_30 
                = vlTOPp->data_path__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((0x1dU == (IData)(vlTOPp->io_RD))) {
            vlTOPp->data_path__DOT__registerFile__DOT__registerFile_29 
                = vlTOPp->data_path__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((0x1cU == (IData)(vlTOPp->io_RD))) {
            vlTOPp->data_path__DOT__registerFile__DOT__registerFile_28 
                = vlTOPp->data_path__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((0x1bU == (IData)(vlTOPp->io_RD))) {
            vlTOPp->data_path__DOT__registerFile__DOT__registerFile_27 
                = vlTOPp->data_path__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((0x1aU == (IData)(vlTOPp->io_RD))) {
            vlTOPp->data_path__DOT__registerFile__DOT__registerFile_26 
                = vlTOPp->data_path__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((0x19U == (IData)(vlTOPp->io_RD))) {
            vlTOPp->data_path__DOT__registerFile__DOT__registerFile_25 
                = vlTOPp->data_path__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((0x18U == (IData)(vlTOPp->io_RD))) {
            vlTOPp->data_path__DOT__registerFile__DOT__registerFile_24 
                = vlTOPp->data_path__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((0x17U == (IData)(vlTOPp->io_RD))) {
            vlTOPp->data_path__DOT__registerFile__DOT__registerFile_23 
                = vlTOPp->data_path__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->io_WRITE_EN) & (0U != (IData)(vlTOPp->io_RD)))) {
        if ((0x16U == (IData)(vlTOPp->io_RD))) {
            vlTOPp->data_path__DOT__registerFile__DOT__registerFile_22 
                = vlTOPp->data_path__DOT__registerFile_io_rdData;
        }
    }
    vlTOPp->data_path__DOT__cpuALU__DOT___T_3 = (vlTOPp->data_path__DOT__ALU_in1 
                                                 + vlTOPp->data_path__DOT__ALU_in2);
    vlTOPp->data_path__DOT__cpuALU__DOT___T_7 = (vlTOPp->data_path__DOT__ALU_in1 
                                                 - vlTOPp->data_path__DOT__ALU_in2);
}

void Vdata_path::_settle__TOP__2(Vdata_path__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdata_path::_settle__TOP__2\n"); );
    Vdata_path* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->io_EQUAL = vlTOPp->data_path__DOT__cpuALU__DOT__EQUAL;
    vlTOPp->io_LESS_THAN = vlTOPp->data_path__DOT__cpuALU__DOT__LESS_THAN;
    vlTOPp->io_SIGNED_LESS_THAN = vlTOPp->data_path__DOT__cpuALU__DOT__SIGNED_LESS_THAN;
    vlTOPp->data_path__DOT__registerFile__DOT___GEN_54 
        = ((0x15U == (IData)(vlTOPp->io_RS2)) ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_21
            : ((0x14U == (IData)(vlTOPp->io_RS2)) ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_20
                : ((0x13U == (IData)(vlTOPp->io_RS2))
                    ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_19
                    : ((0x12U == (IData)(vlTOPp->io_RS2))
                        ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_18
                        : ((0x11U == (IData)(vlTOPp->io_RS2))
                            ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_17
                            : ((0x10U == (IData)(vlTOPp->io_RS2))
                                ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_16
                                : ((0xfU == (IData)(vlTOPp->io_RS2))
                                    ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_15
                                    : ((0xeU == (IData)(vlTOPp->io_RS2))
                                        ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_14
                                        : ((0xdU == (IData)(vlTOPp->io_RS2))
                                            ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_13
                                            : ((0xcU 
                                                == (IData)(vlTOPp->io_RS2))
                                                ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_12
                                                : (
                                                   (0xbU 
                                                    == (IData)(vlTOPp->io_RS2))
                                                    ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_11
                                                    : 
                                                   ((0xaU 
                                                     == (IData)(vlTOPp->io_RS2))
                                                     ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_10
                                                     : 
                                                    ((9U 
                                                      == (IData)(vlTOPp->io_RS2))
                                                      ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_9
                                                      : 
                                                     ((8U 
                                                       == (IData)(vlTOPp->io_RS2))
                                                       ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_8
                                                       : 
                                                      ((7U 
                                                        == (IData)(vlTOPp->io_RS2))
                                                        ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_7
                                                        : 
                                                       ((6U 
                                                         == (IData)(vlTOPp->io_RS2))
                                                         ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_6
                                                         : 
                                                        ((5U 
                                                          == (IData)(vlTOPp->io_RS2))
                                                          ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_5
                                                          : 
                                                         ((4U 
                                                           == (IData)(vlTOPp->io_RS2))
                                                           ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_4
                                                           : 
                                                          ((3U 
                                                            == (IData)(vlTOPp->io_RS2))
                                                            ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_3
                                                            : 
                                                           ((2U 
                                                             == (IData)(vlTOPp->io_RS2))
                                                             ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_2
                                                             : 
                                                            ((1U 
                                                              == (IData)(vlTOPp->io_RS2))
                                                              ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_1
                                                              : vlTOPp->data_path__DOT__registerFile__DOT__registerFile_0)))))))))))))))))))));
    vlTOPp->data_path__DOT__registerFile__DOT___GEN_21 
        = ((0x15U == (IData)(vlTOPp->io_RS1)) ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_21
            : ((0x14U == (IData)(vlTOPp->io_RS1)) ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_20
                : ((0x13U == (IData)(vlTOPp->io_RS1))
                    ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_19
                    : ((0x12U == (IData)(vlTOPp->io_RS1))
                        ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_18
                        : ((0x11U == (IData)(vlTOPp->io_RS1))
                            ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_17
                            : ((0x10U == (IData)(vlTOPp->io_RS1))
                                ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_16
                                : ((0xfU == (IData)(vlTOPp->io_RS1))
                                    ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_15
                                    : ((0xeU == (IData)(vlTOPp->io_RS1))
                                        ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_14
                                        : ((0xdU == (IData)(vlTOPp->io_RS1))
                                            ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_13
                                            : ((0xcU 
                                                == (IData)(vlTOPp->io_RS1))
                                                ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_12
                                                : (
                                                   (0xbU 
                                                    == (IData)(vlTOPp->io_RS1))
                                                    ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_11
                                                    : 
                                                   ((0xaU 
                                                     == (IData)(vlTOPp->io_RS1))
                                                     ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_10
                                                     : 
                                                    ((9U 
                                                      == (IData)(vlTOPp->io_RS1))
                                                      ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_9
                                                      : 
                                                     ((8U 
                                                       == (IData)(vlTOPp->io_RS1))
                                                       ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_8
                                                       : 
                                                      ((7U 
                                                        == (IData)(vlTOPp->io_RS1))
                                                        ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_7
                                                        : 
                                                       ((6U 
                                                         == (IData)(vlTOPp->io_RS1))
                                                         ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_6
                                                         : 
                                                        ((5U 
                                                          == (IData)(vlTOPp->io_RS1))
                                                          ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_5
                                                          : 
                                                         ((4U 
                                                           == (IData)(vlTOPp->io_RS1))
                                                           ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_4
                                                           : 
                                                          ((3U 
                                                            == (IData)(vlTOPp->io_RS1))
                                                            ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_3
                                                            : 
                                                           ((2U 
                                                             == (IData)(vlTOPp->io_RS1))
                                                             ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_2
                                                             : 
                                                            ((1U 
                                                              == (IData)(vlTOPp->io_RS1))
                                                              ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_1
                                                              : vlTOPp->data_path__DOT__registerFile__DOT__registerFile_0)))))))))))))))))))));
    vlTOPp->io_store_address = vlTOPp->data_path__DOT__cpuALU__DOT__ALUoutput;
    vlTOPp->io_load_address = vlTOPp->data_path__DOT__cpuALU__DOT__ALUoutput;
    vlTOPp->io_instruction_next_address = vlTOPp->data_path__DOT__cpuALU__DOT__ALUoutput;
    vlTOPp->data_path__DOT__rdData = ((IData)(vlTOPp->io_CHOOSE_MEMORY_LOAD)
                                       ? vlTOPp->io_load_data
                                       : vlTOPp->data_path__DOT__cpuALU__DOT__ALUoutput);
    vlTOPp->data_path__DOT__cpuALU__DOT___T_3 = (vlTOPp->data_path__DOT__ALU_in1 
                                                 + vlTOPp->data_path__DOT__ALU_in2);
    vlTOPp->data_path__DOT__cpuALU__DOT___T_7 = (vlTOPp->data_path__DOT__ALU_in1 
                                                 - vlTOPp->data_path__DOT__ALU_in2);
    vlTOPp->data_path__DOT__cpuALU__DOT___GEN_4 = (
                                                   (5U 
                                                    == (IData)(vlTOPp->io_ALU_OP))
                                                    ? 
                                                   (vlTOPp->data_path__DOT__ALU_in1 
                                                    >> 
                                                    (0x1fU 
                                                     & vlTOPp->data_path__DOT__ALU_in2))
                                                    : 
                                                   ((0xdU 
                                                     == (IData)(vlTOPp->io_ALU_OP))
                                                     ? 
                                                    VL_SHIFTRS_III(32,32,5, vlTOPp->data_path__DOT__ALU_in1, 
                                                                   (0x1fU 
                                                                    & vlTOPp->data_path__DOT__ALU_in2))
                                                     : 
                                                    ((4U 
                                                      == (IData)(vlTOPp->io_ALU_OP))
                                                      ? 
                                                     (vlTOPp->data_path__DOT__ALU_in1 
                                                      ^ vlTOPp->data_path__DOT__ALU_in2)
                                                      : 
                                                     ((6U 
                                                       == (IData)(vlTOPp->io_ALU_OP))
                                                       ? 
                                                      (vlTOPp->data_path__DOT__ALU_in1 
                                                       | vlTOPp->data_path__DOT__ALU_in2)
                                                       : 
                                                      ((7U 
                                                        == (IData)(vlTOPp->io_ALU_OP))
                                                        ? 
                                                       (vlTOPp->data_path__DOT__ALU_in1 
                                                        & vlTOPp->data_path__DOT__ALU_in2)
                                                        : vlTOPp->data_path__DOT__cpuALU__DOT__ALUoutput)))));
    vlTOPp->data_path__DOT__rs2_ALU = (((IData)(vlTOPp->io_RS2) 
                                        == (IData)(vlTOPp->io_ALU_RD))
                                        ? vlTOPp->data_path__DOT__cpuALU__DOT__ALUoutput
                                        : ((0U == (IData)(vlTOPp->io_RS2))
                                            ? 0U : 
                                           ((0x1fU 
                                             == (IData)(vlTOPp->io_RS2))
                                             ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_31
                                             : ((0x1eU 
                                                 == (IData)(vlTOPp->io_RS2))
                                                 ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_30
                                                 : 
                                                ((0x1dU 
                                                  == (IData)(vlTOPp->io_RS2))
                                                  ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_29
                                                  : 
                                                 ((0x1cU 
                                                   == (IData)(vlTOPp->io_RS2))
                                                   ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_28
                                                   : 
                                                  ((0x1bU 
                                                    == (IData)(vlTOPp->io_RS2))
                                                    ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_27
                                                    : 
                                                   ((0x1aU 
                                                     == (IData)(vlTOPp->io_RS2))
                                                     ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_26
                                                     : 
                                                    ((0x19U 
                                                      == (IData)(vlTOPp->io_RS2))
                                                      ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_25
                                                      : 
                                                     ((0x18U 
                                                       == (IData)(vlTOPp->io_RS2))
                                                       ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_24
                                                       : 
                                                      ((0x17U 
                                                        == (IData)(vlTOPp->io_RS2))
                                                        ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_23
                                                        : 
                                                       ((0x16U 
                                                         == (IData)(vlTOPp->io_RS2))
                                                         ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_22
                                                         : vlTOPp->data_path__DOT__registerFile__DOT___GEN_54))))))))))));
    vlTOPp->data_path__DOT__registerFile_io_rdData 
        = ((IData)(vlTOPp->io_PROCEDURE_BRANCHING) ? vlTOPp->io_instruction_return_address
            : vlTOPp->data_path__DOT__rdData);
    vlTOPp->data_path__DOT__cpuALU__DOT___GEN_7 = (VL_ULL(0x7fffffffffffffff) 
                                                   & ((0U 
                                                       == (IData)(vlTOPp->io_ALU_OP))
                                                       ? 
                                                      (((QData)((IData)(
                                                                        (0x7fffffffU 
                                                                         & VL_NEGATE_I((IData)(
                                                                                (1U 
                                                                                & (vlTOPp->data_path__DOT__cpuALU__DOT___T_3 
                                                                                >> 0x1fU))))))) 
                                                        << 0x20U) 
                                                       | (QData)((IData)(vlTOPp->data_path__DOT__cpuALU__DOT___T_3)))
                                                       : 
                                                      ((8U 
                                                        == (IData)(vlTOPp->io_ALU_OP))
                                                        ? 
                                                       (((QData)((IData)(
                                                                         (0x7fffffffU 
                                                                          & VL_NEGATE_I((IData)(
                                                                                (1U 
                                                                                & (vlTOPp->data_path__DOT__cpuALU__DOT___T_7 
                                                                                >> 0x1fU))))))) 
                                                         << 0x20U) 
                                                        | (QData)((IData)(vlTOPp->data_path__DOT__cpuALU__DOT___T_7)))
                                                        : 
                                                       ((1U 
                                                         == (IData)(vlTOPp->io_ALU_OP))
                                                         ? 
                                                        ((((QData)((IData)(
                                                                           (0x7fffffffU 
                                                                            & VL_NEGATE_I((IData)(
                                                                                (1U 
                                                                                & (vlTOPp->data_path__DOT__ALU_in1 
                                                                                >> 0x1fU))))))) 
                                                           << 0x20U) 
                                                          | (QData)((IData)(vlTOPp->data_path__DOT__ALU_in1))) 
                                                         << 
                                                         (0x1fU 
                                                          & vlTOPp->data_path__DOT__ALU_in2))
                                                         : 
                                                        (((QData)((IData)(
                                                                          (0x7fffffffU 
                                                                           & VL_NEGATE_I((IData)(
                                                                                (1U 
                                                                                & (vlTOPp->data_path__DOT__cpuALU__DOT___GEN_4 
                                                                                >> 0x1fU))))))) 
                                                          << 0x20U) 
                                                         | (QData)((IData)(vlTOPp->data_path__DOT__cpuALU__DOT___GEN_4)))))));
    vlTOPp->io_store_data = ((0U == (IData)(vlTOPp->io_RS2))
                              ? 0U : (((IData)(vlTOPp->io_RS2) 
                                       == (IData)(vlTOPp->io_RD))
                                       ? vlTOPp->data_path__DOT__rdData
                                       : vlTOPp->data_path__DOT__rs2_ALU));
    vlTOPp->data_path__DOT__cpuALU__DOT___GEN_11 = 
        (VL_LTS_III(1,32,32, vlTOPp->data_path__DOT__ALU_in1, vlTOPp->data_path__DOT__ALU_in2)
          ? ((2U == (IData)(vlTOPp->io_ALU_OP)) ? VL_ULL(1)
              : vlTOPp->data_path__DOT__cpuALU__DOT___GEN_7)
          : vlTOPp->data_path__DOT__cpuALU__DOT___GEN_7);
}

VL_INLINE_OPT void Vdata_path::_combo__TOP__3(Vdata_path__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdata_path::_combo__TOP__3\n"); );
    Vdata_path* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->data_path__DOT__registerFile__DOT___GEN_54 
        = ((0x15U == (IData)(vlTOPp->io_RS2)) ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_21
            : ((0x14U == (IData)(vlTOPp->io_RS2)) ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_20
                : ((0x13U == (IData)(vlTOPp->io_RS2))
                    ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_19
                    : ((0x12U == (IData)(vlTOPp->io_RS2))
                        ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_18
                        : ((0x11U == (IData)(vlTOPp->io_RS2))
                            ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_17
                            : ((0x10U == (IData)(vlTOPp->io_RS2))
                                ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_16
                                : ((0xfU == (IData)(vlTOPp->io_RS2))
                                    ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_15
                                    : ((0xeU == (IData)(vlTOPp->io_RS2))
                                        ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_14
                                        : ((0xdU == (IData)(vlTOPp->io_RS2))
                                            ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_13
                                            : ((0xcU 
                                                == (IData)(vlTOPp->io_RS2))
                                                ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_12
                                                : (
                                                   (0xbU 
                                                    == (IData)(vlTOPp->io_RS2))
                                                    ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_11
                                                    : 
                                                   ((0xaU 
                                                     == (IData)(vlTOPp->io_RS2))
                                                     ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_10
                                                     : 
                                                    ((9U 
                                                      == (IData)(vlTOPp->io_RS2))
                                                      ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_9
                                                      : 
                                                     ((8U 
                                                       == (IData)(vlTOPp->io_RS2))
                                                       ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_8
                                                       : 
                                                      ((7U 
                                                        == (IData)(vlTOPp->io_RS2))
                                                        ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_7
                                                        : 
                                                       ((6U 
                                                         == (IData)(vlTOPp->io_RS2))
                                                         ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_6
                                                         : 
                                                        ((5U 
                                                          == (IData)(vlTOPp->io_RS2))
                                                          ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_5
                                                          : 
                                                         ((4U 
                                                           == (IData)(vlTOPp->io_RS2))
                                                           ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_4
                                                           : 
                                                          ((3U 
                                                            == (IData)(vlTOPp->io_RS2))
                                                            ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_3
                                                            : 
                                                           ((2U 
                                                             == (IData)(vlTOPp->io_RS2))
                                                             ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_2
                                                             : 
                                                            ((1U 
                                                              == (IData)(vlTOPp->io_RS2))
                                                              ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_1
                                                              : vlTOPp->data_path__DOT__registerFile__DOT__registerFile_0)))))))))))))))))))));
    vlTOPp->data_path__DOT__registerFile__DOT___GEN_21 
        = ((0x15U == (IData)(vlTOPp->io_RS1)) ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_21
            : ((0x14U == (IData)(vlTOPp->io_RS1)) ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_20
                : ((0x13U == (IData)(vlTOPp->io_RS1))
                    ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_19
                    : ((0x12U == (IData)(vlTOPp->io_RS1))
                        ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_18
                        : ((0x11U == (IData)(vlTOPp->io_RS1))
                            ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_17
                            : ((0x10U == (IData)(vlTOPp->io_RS1))
                                ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_16
                                : ((0xfU == (IData)(vlTOPp->io_RS1))
                                    ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_15
                                    : ((0xeU == (IData)(vlTOPp->io_RS1))
                                        ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_14
                                        : ((0xdU == (IData)(vlTOPp->io_RS1))
                                            ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_13
                                            : ((0xcU 
                                                == (IData)(vlTOPp->io_RS1))
                                                ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_12
                                                : (
                                                   (0xbU 
                                                    == (IData)(vlTOPp->io_RS1))
                                                    ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_11
                                                    : 
                                                   ((0xaU 
                                                     == (IData)(vlTOPp->io_RS1))
                                                     ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_10
                                                     : 
                                                    ((9U 
                                                      == (IData)(vlTOPp->io_RS1))
                                                      ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_9
                                                      : 
                                                     ((8U 
                                                       == (IData)(vlTOPp->io_RS1))
                                                       ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_8
                                                       : 
                                                      ((7U 
                                                        == (IData)(vlTOPp->io_RS1))
                                                        ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_7
                                                        : 
                                                       ((6U 
                                                         == (IData)(vlTOPp->io_RS1))
                                                         ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_6
                                                         : 
                                                        ((5U 
                                                          == (IData)(vlTOPp->io_RS1))
                                                          ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_5
                                                          : 
                                                         ((4U 
                                                           == (IData)(vlTOPp->io_RS1))
                                                           ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_4
                                                           : 
                                                          ((3U 
                                                            == (IData)(vlTOPp->io_RS1))
                                                            ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_3
                                                            : 
                                                           ((2U 
                                                             == (IData)(vlTOPp->io_RS1))
                                                             ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_2
                                                             : 
                                                            ((1U 
                                                              == (IData)(vlTOPp->io_RS1))
                                                              ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_1
                                                              : vlTOPp->data_path__DOT__registerFile__DOT__registerFile_0)))))))))))))))))))));
    vlTOPp->data_path__DOT__rdData = ((IData)(vlTOPp->io_CHOOSE_MEMORY_LOAD)
                                       ? vlTOPp->io_load_data
                                       : vlTOPp->data_path__DOT__cpuALU__DOT__ALUoutput);
    vlTOPp->data_path__DOT__cpuALU__DOT___GEN_4 = (
                                                   (5U 
                                                    == (IData)(vlTOPp->io_ALU_OP))
                                                    ? 
                                                   (vlTOPp->data_path__DOT__ALU_in1 
                                                    >> 
                                                    (0x1fU 
                                                     & vlTOPp->data_path__DOT__ALU_in2))
                                                    : 
                                                   ((0xdU 
                                                     == (IData)(vlTOPp->io_ALU_OP))
                                                     ? 
                                                    VL_SHIFTRS_III(32,32,5, vlTOPp->data_path__DOT__ALU_in1, 
                                                                   (0x1fU 
                                                                    & vlTOPp->data_path__DOT__ALU_in2))
                                                     : 
                                                    ((4U 
                                                      == (IData)(vlTOPp->io_ALU_OP))
                                                      ? 
                                                     (vlTOPp->data_path__DOT__ALU_in1 
                                                      ^ vlTOPp->data_path__DOT__ALU_in2)
                                                      : 
                                                     ((6U 
                                                       == (IData)(vlTOPp->io_ALU_OP))
                                                       ? 
                                                      (vlTOPp->data_path__DOT__ALU_in1 
                                                       | vlTOPp->data_path__DOT__ALU_in2)
                                                       : 
                                                      ((7U 
                                                        == (IData)(vlTOPp->io_ALU_OP))
                                                        ? 
                                                       (vlTOPp->data_path__DOT__ALU_in1 
                                                        & vlTOPp->data_path__DOT__ALU_in2)
                                                        : vlTOPp->data_path__DOT__cpuALU__DOT__ALUoutput)))));
    vlTOPp->data_path__DOT__rs2_ALU = (((IData)(vlTOPp->io_RS2) 
                                        == (IData)(vlTOPp->io_ALU_RD))
                                        ? vlTOPp->data_path__DOT__cpuALU__DOT__ALUoutput
                                        : ((0U == (IData)(vlTOPp->io_RS2))
                                            ? 0U : 
                                           ((0x1fU 
                                             == (IData)(vlTOPp->io_RS2))
                                             ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_31
                                             : ((0x1eU 
                                                 == (IData)(vlTOPp->io_RS2))
                                                 ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_30
                                                 : 
                                                ((0x1dU 
                                                  == (IData)(vlTOPp->io_RS2))
                                                  ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_29
                                                  : 
                                                 ((0x1cU 
                                                   == (IData)(vlTOPp->io_RS2))
                                                   ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_28
                                                   : 
                                                  ((0x1bU 
                                                    == (IData)(vlTOPp->io_RS2))
                                                    ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_27
                                                    : 
                                                   ((0x1aU 
                                                     == (IData)(vlTOPp->io_RS2))
                                                     ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_26
                                                     : 
                                                    ((0x19U 
                                                      == (IData)(vlTOPp->io_RS2))
                                                      ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_25
                                                      : 
                                                     ((0x18U 
                                                       == (IData)(vlTOPp->io_RS2))
                                                       ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_24
                                                       : 
                                                      ((0x17U 
                                                        == (IData)(vlTOPp->io_RS2))
                                                        ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_23
                                                        : 
                                                       ((0x16U 
                                                         == (IData)(vlTOPp->io_RS2))
                                                         ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_22
                                                         : vlTOPp->data_path__DOT__registerFile__DOT___GEN_54))))))))))));
    vlTOPp->data_path__DOT__registerFile_io_rdData 
        = ((IData)(vlTOPp->io_PROCEDURE_BRANCHING) ? vlTOPp->io_instruction_return_address
            : vlTOPp->data_path__DOT__rdData);
    vlTOPp->data_path__DOT__cpuALU__DOT___GEN_7 = (VL_ULL(0x7fffffffffffffff) 
                                                   & ((0U 
                                                       == (IData)(vlTOPp->io_ALU_OP))
                                                       ? 
                                                      (((QData)((IData)(
                                                                        (0x7fffffffU 
                                                                         & VL_NEGATE_I((IData)(
                                                                                (1U 
                                                                                & (vlTOPp->data_path__DOT__cpuALU__DOT___T_3 
                                                                                >> 0x1fU))))))) 
                                                        << 0x20U) 
                                                       | (QData)((IData)(vlTOPp->data_path__DOT__cpuALU__DOT___T_3)))
                                                       : 
                                                      ((8U 
                                                        == (IData)(vlTOPp->io_ALU_OP))
                                                        ? 
                                                       (((QData)((IData)(
                                                                         (0x7fffffffU 
                                                                          & VL_NEGATE_I((IData)(
                                                                                (1U 
                                                                                & (vlTOPp->data_path__DOT__cpuALU__DOT___T_7 
                                                                                >> 0x1fU))))))) 
                                                         << 0x20U) 
                                                        | (QData)((IData)(vlTOPp->data_path__DOT__cpuALU__DOT___T_7)))
                                                        : 
                                                       ((1U 
                                                         == (IData)(vlTOPp->io_ALU_OP))
                                                         ? 
                                                        ((((QData)((IData)(
                                                                           (0x7fffffffU 
                                                                            & VL_NEGATE_I((IData)(
                                                                                (1U 
                                                                                & (vlTOPp->data_path__DOT__ALU_in1 
                                                                                >> 0x1fU))))))) 
                                                           << 0x20U) 
                                                          | (QData)((IData)(vlTOPp->data_path__DOT__ALU_in1))) 
                                                         << 
                                                         (0x1fU 
                                                          & vlTOPp->data_path__DOT__ALU_in2))
                                                         : 
                                                        (((QData)((IData)(
                                                                          (0x7fffffffU 
                                                                           & VL_NEGATE_I((IData)(
                                                                                (1U 
                                                                                & (vlTOPp->data_path__DOT__cpuALU__DOT___GEN_4 
                                                                                >> 0x1fU))))))) 
                                                          << 0x20U) 
                                                         | (QData)((IData)(vlTOPp->data_path__DOT__cpuALU__DOT___GEN_4)))))));
    vlTOPp->io_store_data = ((0U == (IData)(vlTOPp->io_RS2))
                              ? 0U : (((IData)(vlTOPp->io_RS2) 
                                       == (IData)(vlTOPp->io_RD))
                                       ? vlTOPp->data_path__DOT__rdData
                                       : vlTOPp->data_path__DOT__rs2_ALU));
    vlTOPp->data_path__DOT__cpuALU__DOT___GEN_11 = 
        (VL_LTS_III(1,32,32, vlTOPp->data_path__DOT__ALU_in1, vlTOPp->data_path__DOT__ALU_in2)
          ? ((2U == (IData)(vlTOPp->io_ALU_OP)) ? VL_ULL(1)
              : vlTOPp->data_path__DOT__cpuALU__DOT___GEN_7)
          : vlTOPp->data_path__DOT__cpuALU__DOT___GEN_7);
}

void Vdata_path::_eval(Vdata_path__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdata_path::_eval\n"); );
    Vdata_path* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
        vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
    }
    vlTOPp->_combo__TOP__3(vlSymsp);
    vlTOPp->__Vm_traceActivity = (4U | vlTOPp->__Vm_traceActivity);
    // Final
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void Vdata_path::_eval_initial(Vdata_path__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdata_path::_eval_initial\n"); );
    Vdata_path* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void Vdata_path::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdata_path::final\n"); );
    // Variables
    Vdata_path__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vdata_path* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vdata_path::_eval_settle(Vdata_path__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdata_path::_eval_settle\n"); );
    Vdata_path* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
}

VL_INLINE_OPT QData Vdata_path::_change_request(Vdata_path__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdata_path::_change_request\n"); );
    Vdata_path* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vdata_path::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdata_path::_eval_debug_assertions\n"); );
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
    if (VL_UNLIKELY((io_ALU_OP & 0xf0U))) {
        Verilated::overWidthError("io_ALU_OP");}
    if (VL_UNLIKELY((io_CHOOSE_IMMEDIATE & 0xfeU))) {
        Verilated::overWidthError("io_CHOOSE_IMMEDIATE");}
    if (VL_UNLIKELY((io_CHOOSE_MEMORY_LOAD & 0xfeU))) {
        Verilated::overWidthError("io_CHOOSE_MEMORY_LOAD");}
    if (VL_UNLIKELY((io_ALU_RD & 0xe0U))) {
        Verilated::overWidthError("io_ALU_RD");}
    if (VL_UNLIKELY((io_PROCEDURE_BRANCHING & 0xfeU))) {
        Verilated::overWidthError("io_PROCEDURE_BRANCHING");}
    if (VL_UNLIKELY((io_CHOOSE_PC & 0xfeU))) {
        Verilated::overWidthError("io_CHOOSE_PC");}
}
#endif  // VL_DEBUG

void Vdata_path::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdata_path::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    io_RS1 = VL_RAND_RESET_I(5);
    io_RS2 = VL_RAND_RESET_I(5);
    io_RD = VL_RAND_RESET_I(5);
    io_WRITE_EN = VL_RAND_RESET_I(1);
    io_ALU_OP = VL_RAND_RESET_I(4);
    io_EQUAL = VL_RAND_RESET_I(1);
    io_LESS_THAN = VL_RAND_RESET_I(1);
    io_SIGNED_LESS_THAN = VL_RAND_RESET_I(1);
    io_store_data = VL_RAND_RESET_I(32);
    io_store_address = VL_RAND_RESET_I(32);
    io_load_data = VL_RAND_RESET_I(32);
    io_load_address = VL_RAND_RESET_I(32);
    io_CHOOSE_IMMEDIATE = VL_RAND_RESET_I(1);
    io_CHOOSE_MEMORY_LOAD = VL_RAND_RESET_I(1);
    io_IMMEDIATE = VL_RAND_RESET_I(32);
    io_ALU_RD = VL_RAND_RESET_I(5);
    io_instruction_return_address = VL_RAND_RESET_I(32);
    io_instruction_next_address = VL_RAND_RESET_I(32);
    io_PROCEDURE_BRANCHING = VL_RAND_RESET_I(1);
    io_CHOOSE_PC = VL_RAND_RESET_I(1);
    io_PC = VL_RAND_RESET_I(32);
    data_path__DOT__registerFile_io_rdData = VL_RAND_RESET_I(32);
    data_path__DOT__ALU_in1 = VL_RAND_RESET_I(32);
    data_path__DOT__ALU_in2 = VL_RAND_RESET_I(32);
    data_path__DOT__rdData = VL_RAND_RESET_I(32);
    data_path__DOT__rs2_ALU = VL_RAND_RESET_I(32);
    data_path__DOT__cpuALU__DOT__ALUoutput = VL_RAND_RESET_I(32);
    data_path__DOT__cpuALU__DOT__EQUAL = VL_RAND_RESET_I(1);
    data_path__DOT__cpuALU__DOT__LESS_THAN = VL_RAND_RESET_I(1);
    data_path__DOT__cpuALU__DOT__SIGNED_LESS_THAN = VL_RAND_RESET_I(1);
    data_path__DOT__cpuALU__DOT___T_3 = VL_RAND_RESET_I(32);
    data_path__DOT__cpuALU__DOT___T_7 = VL_RAND_RESET_I(32);
    data_path__DOT__cpuALU__DOT___GEN_4 = VL_RAND_RESET_I(32);
    data_path__DOT__cpuALU__DOT___GEN_7 = VL_RAND_RESET_Q(63);
    data_path__DOT__cpuALU__DOT___GEN_11 = VL_RAND_RESET_Q(63);
    data_path__DOT__registerFile__DOT__registerFile_0 = VL_RAND_RESET_I(32);
    data_path__DOT__registerFile__DOT__registerFile_1 = VL_RAND_RESET_I(32);
    data_path__DOT__registerFile__DOT__registerFile_2 = VL_RAND_RESET_I(32);
    data_path__DOT__registerFile__DOT__registerFile_3 = VL_RAND_RESET_I(32);
    data_path__DOT__registerFile__DOT__registerFile_4 = VL_RAND_RESET_I(32);
    data_path__DOT__registerFile__DOT__registerFile_5 = VL_RAND_RESET_I(32);
    data_path__DOT__registerFile__DOT__registerFile_6 = VL_RAND_RESET_I(32);
    data_path__DOT__registerFile__DOT__registerFile_7 = VL_RAND_RESET_I(32);
    data_path__DOT__registerFile__DOT__registerFile_8 = VL_RAND_RESET_I(32);
    data_path__DOT__registerFile__DOT__registerFile_9 = VL_RAND_RESET_I(32);
    data_path__DOT__registerFile__DOT__registerFile_10 = VL_RAND_RESET_I(32);
    data_path__DOT__registerFile__DOT__registerFile_11 = VL_RAND_RESET_I(32);
    data_path__DOT__registerFile__DOT__registerFile_12 = VL_RAND_RESET_I(32);
    data_path__DOT__registerFile__DOT__registerFile_13 = VL_RAND_RESET_I(32);
    data_path__DOT__registerFile__DOT__registerFile_14 = VL_RAND_RESET_I(32);
    data_path__DOT__registerFile__DOT__registerFile_15 = VL_RAND_RESET_I(32);
    data_path__DOT__registerFile__DOT__registerFile_16 = VL_RAND_RESET_I(32);
    data_path__DOT__registerFile__DOT__registerFile_17 = VL_RAND_RESET_I(32);
    data_path__DOT__registerFile__DOT__registerFile_18 = VL_RAND_RESET_I(32);
    data_path__DOT__registerFile__DOT__registerFile_19 = VL_RAND_RESET_I(32);
    data_path__DOT__registerFile__DOT__registerFile_20 = VL_RAND_RESET_I(32);
    data_path__DOT__registerFile__DOT__registerFile_21 = VL_RAND_RESET_I(32);
    data_path__DOT__registerFile__DOT__registerFile_22 = VL_RAND_RESET_I(32);
    data_path__DOT__registerFile__DOT__registerFile_23 = VL_RAND_RESET_I(32);
    data_path__DOT__registerFile__DOT__registerFile_24 = VL_RAND_RESET_I(32);
    data_path__DOT__registerFile__DOT__registerFile_25 = VL_RAND_RESET_I(32);
    data_path__DOT__registerFile__DOT__registerFile_26 = VL_RAND_RESET_I(32);
    data_path__DOT__registerFile__DOT__registerFile_27 = VL_RAND_RESET_I(32);
    data_path__DOT__registerFile__DOT__registerFile_28 = VL_RAND_RESET_I(32);
    data_path__DOT__registerFile__DOT__registerFile_29 = VL_RAND_RESET_I(32);
    data_path__DOT__registerFile__DOT__registerFile_30 = VL_RAND_RESET_I(32);
    data_path__DOT__registerFile__DOT__registerFile_31 = VL_RAND_RESET_I(32);
    data_path__DOT__registerFile__DOT___GEN_21 = VL_RAND_RESET_I(32);
    data_path__DOT__registerFile__DOT___GEN_54 = VL_RAND_RESET_I(32);
    __Vm_traceActivity = 0;
}
