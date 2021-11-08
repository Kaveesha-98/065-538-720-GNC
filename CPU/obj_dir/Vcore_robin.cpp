// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcore_robin.h for the primary calling header

#include "Vcore_robin.h"
#include "Vcore_robin__Syms.h"

//==========

VL_CTOR_IMP(Vcore_robin) {
    Vcore_robin__Syms* __restrict vlSymsp = __VlSymsp = new Vcore_robin__Syms(this, name());
    Vcore_robin* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vcore_robin::__Vconfigure(Vcore_robin__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vcore_robin::~Vcore_robin() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void Vcore_robin::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vcore_robin::eval\n"); );
    Vcore_robin__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vcore_robin* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("core_robin.v", 1127, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vcore_robin::_eval_initial_loop(Vcore_robin__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("core_robin.v", 1127, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vcore_robin::_initial__TOP__1(Vcore_robin__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore_robin::_initial__TOP__1\n"); );
    Vcore_robin* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->io_rdAddr = 0U;
}

VL_INLINE_OPT void Vcore_robin::_sequent__TOP__2(Vcore_robin__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore_robin::_sequent__TOP__2\n"); );
    Vcore_robin* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*1:0*/ __Vdly__core_robin__DOT__storeUnit__DOT__store_data_size_buffer;
    CData/*0:0*/ __Vdly__core_robin__DOT__storeUnit__DOT__storing;
    CData/*0:0*/ __Vdly__core_robin__DOT__storeUnit__DOT__stateReg;
    IData/*31:0*/ __Vdly__core_robin__DOT__controlStore__DOT__instruction;
    IData/*31:0*/ __Vdly__core_robin__DOT__dataPath__DOT__ALU_in1;
    // Body
    __Vdly__core_robin__DOT__storeUnit__DOT__store_data_size_buffer 
        = vlTOPp->core_robin__DOT__storeUnit__DOT__store_data_size_buffer;
    __Vdly__core_robin__DOT__storeUnit__DOT__storing 
        = vlTOPp->core_robin__DOT__storeUnit__DOT__storing;
    __Vdly__core_robin__DOT__storeUnit__DOT__stateReg 
        = vlTOPp->core_robin__DOT__storeUnit__DOT__stateReg;
    __Vdly__core_robin__DOT__controlStore__DOT__instruction 
        = vlTOPp->core_robin__DOT__controlStore__DOT__instruction;
    __Vdly__core_robin__DOT__dataPath__DOT__ALU_in1 
        = vlTOPp->core_robin__DOT__dataPath__DOT__ALU_in1;
    vlTOPp->core_robin__DOT__controlStore__DOT__LOAD_READY 
        = (1U & (~ (IData)(vlTOPp->reset)));
    if (((IData)(vlTOPp->core_robin__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD)))) {
        if ((0x12U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD))) {
            vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_18 
                = vlTOPp->core_robin__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->core_robin__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD)))) {
        if ((0x11U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD))) {
            vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_17 
                = vlTOPp->core_robin__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->core_robin__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD)))) {
        if ((0x10U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD))) {
            vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_16 
                = vlTOPp->core_robin__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->core_robin__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD)))) {
        if ((0xfU == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD))) {
            vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_15 
                = vlTOPp->core_robin__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->core_robin__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD)))) {
        if ((6U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD))) {
            vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_6 
                = vlTOPp->core_robin__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->core_robin__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD)))) {
        if ((5U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD))) {
            vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_5 
                = vlTOPp->core_robin__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->core_robin__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD)))) {
        if ((0xeU == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD))) {
            vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_14 
                = vlTOPp->core_robin__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->core_robin__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD)))) {
        if ((4U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD))) {
            vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_4 
                = vlTOPp->core_robin__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->core_robin__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD)))) {
        if ((3U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD))) {
            vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_3 
                = vlTOPp->core_robin__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->core_robin__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD)))) {
        if ((0U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD))) {
            vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_0 
                = vlTOPp->core_robin__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->core_robin__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD)))) {
        if ((2U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD))) {
            vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_2 
                = vlTOPp->core_robin__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->core_robin__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD)))) {
        if ((0xdU == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD))) {
            vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_13 
                = vlTOPp->core_robin__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->core_robin__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD)))) {
        if ((0x14U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD))) {
            vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_20 
                = vlTOPp->core_robin__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->core_robin__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD)))) {
        if ((0xaU == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD))) {
            vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_10 
                = vlTOPp->core_robin__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->core_robin__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD)))) {
        if ((0x13U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD))) {
            vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_19 
                = vlTOPp->core_robin__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->core_robin__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD)))) {
        if ((9U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD))) {
            vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_9 
                = vlTOPp->core_robin__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->core_robin__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD)))) {
        if ((1U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD))) {
            vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_1 
                = vlTOPp->core_robin__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->core_robin__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD)))) {
        if ((0x15U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD))) {
            vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_21 
                = vlTOPp->core_robin__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->core_robin__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD)))) {
        if ((0xbU == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD))) {
            vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_11 
                = vlTOPp->core_robin__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->core_robin__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD)))) {
        if ((0xcU == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD))) {
            vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_12 
                = vlTOPp->core_robin__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->core_robin__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD)))) {
        if ((7U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD))) {
            vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_7 
                = vlTOPp->core_robin__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->core_robin__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD)))) {
        if ((8U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD))) {
            vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_8 
                = vlTOPp->core_robin__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->core_robin__DOT__storeUnit__DOT__store_data_buffer = 0U;
    } else {
        if (vlTOPp->core_robin__DOT__storeUnit__DOT__storing) {
            vlTOPp->core_robin__DOT__storeUnit__DOT__store_data_buffer 
                = vlTOPp->core_robin__DOT__storeUnit__DOT___T_10;
        } else {
            if (vlTOPp->core_robin__DOT__storeUnit__DOT___T) {
                if (vlTOPp->core_robin__DOT__controlStore_io_DATA_IN) {
                    vlTOPp->core_robin__DOT__storeUnit__DOT__store_data_buffer 
                        = ((0U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                            ? 0U : (((IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2) 
                                     == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD))
                                     ? vlTOPp->core_robin__DOT__dataPath__DOT__rdData
                                     : vlTOPp->core_robin__DOT__dataPath__DOT__rs2_ALU));
                }
            }
        }
    }
    __Vdly__core_robin__DOT__storeUnit__DOT__store_data_size_buffer 
        = ((IData)(vlTOPp->reset) ? 0U : ((IData)(vlTOPp->core_robin__DOT__storeUnit__DOT__storing)
                                           ? ((3U == (IData)(vlTOPp->core_robin__DOT__storeUnit__DOT__store_data_size_buffer))
                                               ? (IData)(vlTOPp->core_robin__DOT__storeUnit__DOT___GEN_11)
                                               : (IData)(vlTOPp->core_robin__DOT__storeUnit__DOT___T_15))
                                           : (IData)(vlTOPp->core_robin__DOT__storeUnit__DOT___GEN_11)));
    if (vlTOPp->reset) {
        vlTOPp->core_robin__DOT__storeUnit__DOT__store_data_buffer_address = 0U;
    } else {
        if (vlTOPp->core_robin__DOT__storeUnit__DOT__storing) {
            vlTOPp->core_robin__DOT__storeUnit__DOT__store_data_buffer_address 
                = vlTOPp->core_robin__DOT__storeUnit__DOT___T_12;
        } else {
            if ((1U & (~ (IData)(vlTOPp->core_robin__DOT__storeUnit__DOT___T)))) {
                if (vlTOPp->core_robin__DOT__storeUnit__DOT__stateReg) {
                    vlTOPp->core_robin__DOT__storeUnit__DOT__store_data_buffer_address 
                        = vlTOPp->core_robin__DOT__storeUnit__DOT___GEN_4;
                }
            }
        }
    }
    __Vdly__core_robin__DOT__storeUnit__DOT__storing 
        = ((~ (IData)(vlTOPp->reset)) & ((IData)(vlTOPp->core_robin__DOT__storeUnit__DOT__storing)
                                          ? ((3U != (IData)(vlTOPp->core_robin__DOT__storeUnit__DOT__store_data_size_buffer)) 
                                             & (IData)(vlTOPp->core_robin__DOT__storeUnit__DOT___GEN_14))
                                          : (IData)(vlTOPp->core_robin__DOT__storeUnit__DOT___GEN_14)));
    __Vdly__core_robin__DOT__storeUnit__DOT__stateReg 
        = ((~ (IData)(vlTOPp->reset)) & ((IData)(vlTOPp->core_robin__DOT__storeUnit__DOT__storing)
                                          ? ((3U != (IData)(vlTOPp->core_robin__DOT__storeUnit__DOT__store_data_size_buffer)) 
                                             & (IData)(vlTOPp->core_robin__DOT__storeUnit__DOT___GEN_9))
                                          : (IData)(vlTOPp->core_robin__DOT__storeUnit__DOT___GEN_9)));
    vlTOPp->core_robin__DOT__controlStore__DOT__RECIEVED 
        = ((~ (IData)(vlTOPp->reset)) & ((0U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                                         & (IData)(vlTOPp->io_INSTRUCTION_LOADED)));
    if (vlTOPp->reset) {
        vlTOPp->core_robin__DOT__controlStore__DOT__stallState = 5U;
    } else {
        if ((0U != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))) {
            if ((1U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))) {
                if ((0x23U == (0x7fU & vlTOPp->core_robin__DOT__controlStore__DOT__instruction))) {
                    vlTOPp->core_robin__DOT__controlStore__DOT__stallState 
                        = vlTOPp->core_robin__DOT__controlStore__DOT___GEN_4;
                }
            } else {
                if ((2U != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))) {
                    vlTOPp->core_robin__DOT__controlStore__DOT__stallState 
                        = vlTOPp->core_robin__DOT__controlStore__DOT___GEN_51;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        __Vdly__core_robin__DOT__controlStore__DOT__instruction = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))) {
            if (vlTOPp->io_INSTRUCTION_LOADED) {
                __Vdly__core_robin__DOT__controlStore__DOT__instruction 
                    = vlTOPp->io_INSTRUCTION;
            }
        }
    }
    __Vdly__core_robin__DOT__dataPath__DOT__ALU_in1 
        = ((IData)(vlTOPp->reset) ? 0U : (((0U != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                                           & ((1U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                                              & (0x17U 
                                                 == 
                                                 (0x7fU 
                                                  & vlTOPp->core_robin__DOT__controlStore__DOT__instruction))))
                                           ? vlTOPp->core_robin__DOT__PC
                                           : ((0U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                               ? 0U
                                               : (((IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1) 
                                                   == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD))
                                                   ? vlTOPp->core_robin__DOT__dataPath__DOT__rdData
                                                   : 
                                                  ((0U 
                                                    == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                                    ? vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT__ALUoutput
                                                    : 
                                                   ((0U 
                                                     == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                                     ? 0U
                                                     : 
                                                    ((0x1fU 
                                                      == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                                      ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_31
                                                      : 
                                                     ((0x1eU 
                                                       == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                                       ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_30
                                                       : 
                                                      ((0x1dU 
                                                        == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                                        ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_29
                                                        : 
                                                       ((0x1cU 
                                                         == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                                         ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_28
                                                         : 
                                                        ((0x1bU 
                                                          == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                                          ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_27
                                                          : 
                                                         ((0x1aU 
                                                           == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                                           ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_26
                                                           : 
                                                          ((0x19U 
                                                            == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                                            ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_25
                                                            : 
                                                           ((0x18U 
                                                             == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                                             ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_24
                                                             : 
                                                            ((0x17U 
                                                              == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                                              ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_23
                                                              : 
                                                             ((0x16U 
                                                               == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                                               ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_22
                                                               : vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT___GEN_21))))))))))))))));
    vlTOPp->core_robin__DOT__storeUnit__DOT__store_data_size_buffer 
        = __Vdly__core_robin__DOT__storeUnit__DOT__store_data_size_buffer;
    vlTOPp->core_robin__DOT__storeUnit__DOT__storing 
        = __Vdly__core_robin__DOT__storeUnit__DOT__storing;
    vlTOPp->core_robin__DOT__storeUnit__DOT___T_10 
        = (0xffffffU & (vlTOPp->core_robin__DOT__storeUnit__DOT__store_data_buffer 
                        >> 8U));
    vlTOPp->core_robin__DOT__storeUnit__DOT___T_15 
        = (3U & ((IData)(1U) + (IData)(vlTOPp->core_robin__DOT__storeUnit__DOT__store_data_size_buffer)));
    vlTOPp->core_robin__DOT__storeUnit__DOT___T_12 
        = ((IData)(1U) + vlTOPp->core_robin__DOT__storeUnit__DOT__store_data_buffer_address);
    vlTOPp->io_mem_write = vlTOPp->core_robin__DOT__storeUnit__DOT__storing;
    vlTOPp->io_mem_write_data = ((IData)(vlTOPp->core_robin__DOT__storeUnit__DOT__storing)
                                  ? (0xffU & vlTOPp->core_robin__DOT__storeUnit__DOT__store_data_buffer)
                                  : 0U);
    vlTOPp->io_mem_write_address = ((IData)(vlTOPp->core_robin__DOT__storeUnit__DOT__storing)
                                     ? vlTOPp->core_robin__DOT__storeUnit__DOT__store_data_buffer_address
                                     : 0U);
    vlTOPp->io_RECIEVED = vlTOPp->core_robin__DOT__controlStore__DOT__RECIEVED;
    if (((IData)(vlTOPp->core_robin__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD)))) {
        if ((0x1fU == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD))) {
            vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_31 
                = vlTOPp->core_robin__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->core_robin__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD)))) {
        if ((0x1eU == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD))) {
            vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_30 
                = vlTOPp->core_robin__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->core_robin__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD)))) {
        if ((0x1dU == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD))) {
            vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_29 
                = vlTOPp->core_robin__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->core_robin__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD)))) {
        if ((0x1cU == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD))) {
            vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_28 
                = vlTOPp->core_robin__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->core_robin__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD)))) {
        if ((0x1bU == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD))) {
            vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_27 
                = vlTOPp->core_robin__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->core_robin__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD)))) {
        if ((0x1aU == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD))) {
            vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_26 
                = vlTOPp->core_robin__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->core_robin__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD)))) {
        if ((0x19U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD))) {
            vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_25 
                = vlTOPp->core_robin__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->core_robin__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD)))) {
        if ((0x18U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD))) {
            vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_24 
                = vlTOPp->core_robin__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->core_robin__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD)))) {
        if ((0x17U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD))) {
            vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_23 
                = vlTOPp->core_robin__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->core_robin__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD)))) {
        if ((0x16U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD))) {
            vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_22 
                = vlTOPp->core_robin__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->core_robin__DOT__PC = 0U;
    } else {
        if (((0U != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
             & ((1U != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                & ((2U != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                   & (3U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)))))) {
            vlTOPp->core_robin__DOT__PC = (((0U != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                                            & ((1U 
                                                != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                                               & ((2U 
                                                   == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                                                   ? (IData)(vlTOPp->core_robin__DOT__controlStore__DOT___GEN_15)
                                                   : 
                                                  ((3U 
                                                    == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                                                   & (IData)(vlTOPp->core_robin__DOT__controlStore__DOT___GEN_15)))))
                                            ? vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT__ALUoutput
                                            : ((1U 
                                                & (((~ 
                                                     (((1U 
                                                        & (IData)(vlTOPp->core_robin__DOT__controlStore_io_BRANCH_SELECT))
                                                        ? 
                                                       ((2U 
                                                         & (IData)(vlTOPp->core_robin__DOT__controlStore_io_BRANCH_SELECT))
                                                         ? (IData)(vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT__LESS_THAN)
                                                         : (IData)(vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT__SIGNED_LESS_THAN))
                                                        : (IData)(vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT__EQUAL)) 
                                                      ^ 
                                                      ((0U 
                                                        != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                                                       & ((1U 
                                                           != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                                                          & ((2U 
                                                              != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                                                             & ((3U 
                                                                 == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                                                                & ((0x63U 
                                                                    == 
                                                                    (0x7fU 
                                                                     & vlTOPp->core_robin__DOT__controlStore__DOT__instruction)) 
                                                                   & (~ 
                                                                      (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                                                       >> 0xcU))))))))) 
                                                    & (((IData)(vlTOPp->core_robin__DOT__controlStore_io_BRANCH_SELECT) 
                                                        >> 1U) 
                                                       | (~ (IData)(vlTOPp->core_robin__DOT__controlStore_io_BRANCH_SELECT)))) 
                                                   | (IData)(vlTOPp->core_robin__DOT__controlStore_io_PROCEDURE_BRANCHING)))
                                                ? vlTOPp->core_robin__DOT__branchImmBranchAddr
                                                : vlTOPp->core_robin__DOT__noBranchNextAddr));
        }
    }
    vlTOPp->core_robin__DOT__noBranchNextAddr = ((IData)(4U) 
                                                 + vlTOPp->core_robin__DOT__PC);
    vlTOPp->io_PC = vlTOPp->core_robin__DOT__PC;
    vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT__LESS_THAN 
        = ((~ (IData)(vlTOPp->reset)) & (vlTOPp->core_robin__DOT__dataPath__DOT__ALU_in1 
                                         < vlTOPp->core_robin__DOT__dataPath__DOT__ALU_in2));
    vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT__SIGNED_LESS_THAN 
        = ((~ (IData)(vlTOPp->reset)) & VL_LTS_III(1,32,32, vlTOPp->core_robin__DOT__dataPath__DOT__ALU_in1, vlTOPp->core_robin__DOT__dataPath__DOT__ALU_in2));
    vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT__EQUAL 
        = ((IData)(vlTOPp->reset) | (vlTOPp->core_robin__DOT__dataPath__DOT__ALU_in1 
                                     == vlTOPp->core_robin__DOT__dataPath__DOT__ALU_in2));
    vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT__ALUoutput 
        = ((IData)(vlTOPp->reset) ? 0U : (IData)(((vlTOPp->core_robin__DOT__dataPath__DOT__ALU_in1 
                                                   < vlTOPp->core_robin__DOT__dataPath__DOT__ALU_in2)
                                                   ? 
                                                  ((3U 
                                                    == (IData)(vlTOPp->core_robin__DOT__controlStore_io_ALU_OP))
                                                    ? VL_ULL(1)
                                                    : vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT___GEN_11)
                                                   : vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT___GEN_11)));
    vlTOPp->core_robin__DOT__dataPath__DOT__ALU_in1 
        = __Vdly__core_robin__DOT__dataPath__DOT__ALU_in1;
    vlTOPp->core_robin__DOT__dataPath__DOT__ALU_in2 
        = ((IData)(vlTOPp->reset) ? 0U : (((0U != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                                           & ((1U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                                              & (~ 
                                                 ((0x33U 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->core_robin__DOT__controlStore__DOT__instruction)) 
                                                  | (0x63U 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->core_robin__DOT__controlStore__DOT__instruction))))))
                                           ? ((0U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                                               ? 0U
                                               : ((1U 
                                                   == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                                                   ? 
                                                  ((0x37U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->core_robin__DOT__controlStore__DOT__instruction))
                                                    ? 
                                                   (0xfffff000U 
                                                    & vlTOPp->core_robin__DOT__controlStore__DOT__instruction)
                                                    : 
                                                   ((0xfffff000U 
                                                     & (VL_NEGATE_I((IData)(
                                                                            (1U 
                                                                             & ((IData)(vlTOPp->core_robin__DOT__controlStore__DOT___T_18) 
                                                                                >> 0xbU)))) 
                                                        << 0xcU)) 
                                                    | (IData)(vlTOPp->core_robin__DOT__controlStore__DOT___T_18)))
                                                   : 0U))
                                           : ((0U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                               ? 0U
                                               : (((IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2) 
                                                   == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD))
                                                   ? vlTOPp->core_robin__DOT__dataPath__DOT__rdData
                                                   : vlTOPp->core_robin__DOT__dataPath__DOT__rs2_ALU))));
    vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT___T_3 
        = (vlTOPp->core_robin__DOT__dataPath__DOT__ALU_in1 
           + vlTOPp->core_robin__DOT__dataPath__DOT__ALU_in2);
    vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT___T_7 
        = (vlTOPp->core_robin__DOT__dataPath__DOT__ALU_in1 
           - vlTOPp->core_robin__DOT__dataPath__DOT__ALU_in2);
    if (vlTOPp->reset) {
        vlTOPp->core_robin__DOT__controlStore__DOT__stateReg = 0U;
    } else {
        if (vlTOPp->core_robin__DOT__controlStore__DOT___T) {
            if (vlTOPp->io_INSTRUCTION_LOADED) {
                vlTOPp->core_robin__DOT__controlStore__DOT__stateReg = 1U;
            }
        } else {
            vlTOPp->core_robin__DOT__controlStore__DOT__stateReg 
                = ((IData)(vlTOPp->core_robin__DOT__controlStore__DOT___T_2)
                    ? ((0x23U == (0x7fU & vlTOPp->core_robin__DOT__controlStore__DOT__instruction))
                        ? ((IData)(vlTOPp->core_robin__DOT__controlStore__DOT__STORE_READY)
                            ? 2U : 5U) : 2U) : ((IData)(vlTOPp->core_robin__DOT__controlStore__DOT___T_34)
                                                 ? 3U
                                                 : (IData)(vlTOPp->core_robin__DOT__controlStore__DOT___GEN_48)));
        }
    }
    vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
        = __Vdly__core_robin__DOT__controlStore__DOT__instruction;
    vlTOPp->core_robin__DOT__controlStore__DOT__STORE_READY 
        = (1U & ((~ (IData)(vlTOPp->reset)) & (~ (IData)(vlTOPp->core_robin__DOT__storeUnit__DOT__stateReg))));
    vlTOPp->core_robin__DOT__controlStore__DOT___T_18 
        = (0xfffU & ((0x23U == (0x7fU & vlTOPp->core_robin__DOT__controlStore__DOT__instruction))
                      ? ((0xfe0U & (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                    >> 0x14U)) | (0x1fU 
                                                  & (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                                     >> 7U)))
                      : (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                         >> 0x14U)));
    vlTOPp->core_robin__DOT__controlStore__DOT___GEN_15 
        = ((0x67U == (0x77U & vlTOPp->core_robin__DOT__controlStore__DOT__instruction)) 
           & (0x67U == (0x7fU & vlTOPp->core_robin__DOT__controlStore__DOT__instruction)));
    vlTOPp->core_robin__DOT__controlStore__DOT___T_65 
        = ((0x1000U & (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                       >> 0x13U)) | ((0x800U & (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                                << 4U)) 
                                     | ((0x7e0U & (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                                   >> 0x14U)) 
                                        | (0x1eU & 
                                           (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                            >> 7U)))));
    vlTOPp->core_robin__DOT__controlStore__DOT___T_66 
        = ((0x100000U & (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                         >> 0xbU)) | ((0xff000U & vlTOPp->core_robin__DOT__controlStore__DOT__instruction) 
                                      | ((0x800U & 
                                          (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                           >> 9U)) 
                                         | (0x7feU 
                                            & (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                               >> 0x14U)))));
    vlTOPp->core_robin__DOT__controlStore__DOT___T 
        = (0U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg));
    vlTOPp->core_robin__DOT__controlStore__DOT___T_2 
        = (1U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg));
    vlTOPp->core_robin__DOT__controlStore__DOT___T_34 
        = (2U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg));
    vlTOPp->core_robin__DOT__controlStore_io_RD = (
                                                   (0U 
                                                    == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                                                    ? 0U
                                                    : 
                                                   ((1U 
                                                     == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                                                     ? 0U
                                                     : 
                                                    (0x1fU 
                                                     & ((2U 
                                                         == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                                                         ? 
                                                        ((0x67U 
                                                          == 
                                                          (0x77U 
                                                           & vlTOPp->core_robin__DOT__controlStore__DOT__instruction))
                                                          ? 
                                                         (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                                          >> 7U)
                                                          : 0U)
                                                         : 
                                                        ((3U 
                                                          == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                                                          ? 
                                                         (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                                          >> 7U)
                                                          : 
                                                         ((4U 
                                                           == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                                                           ? 
                                                          (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                                           >> 7U)
                                                           : 0U))))));
    vlTOPp->core_robin__DOT__controlStore_io_BRANCH_SELECT 
        = ((0U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
            ? 1U : ((1U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                     ? 1U : ((2U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                              ? 1U : ((3U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                                       ? ((0x63U == 
                                           (0x7fU & vlTOPp->core_robin__DOT__controlStore__DOT__instruction))
                                           ? (3U & 
                                              (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                               >> 0xdU))
                                           : 1U) : 1U))));
    vlTOPp->core_robin__DOT__controlStore__DOT___GEN_51 
        = ((3U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
            ? (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stallState)
            : ((4U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                ? ((IData)(vlTOPp->core_robin__DOT__controlStore__DOT__LOAD_READY)
                    ? (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stallState)
                    : (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                : (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stallState)));
    vlTOPp->core_robin__DOT__controlStore_io_PROCEDURE_BRANCHING 
        = ((0U != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
           & ((1U != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
              & ((2U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                  ? (0x67U == (0x77U & vlTOPp->core_robin__DOT__controlStore__DOT__instruction))
                  : ((3U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                     & (0x67U == (0x77U & vlTOPp->core_robin__DOT__controlStore__DOT__instruction))))));
    vlTOPp->core_robin__DOT__controlStore_io_STORE_ADDRESS_IN 
        = ((0U != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
           & ((1U != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
              & ((2U != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                 & ((3U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                    & (0x23U == (0x7fU & vlTOPp->core_robin__DOT__controlStore__DOT__instruction))))));
    vlTOPp->core_robin__DOT__controlStore__DOT___GEN_36 
        = ((4U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
           & (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__LOAD_READY));
    vlTOPp->core_robin__DOT__controlStore_io_RS2 = 
        ((0U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
          ? 0U : ((1U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                   ? (0x1fU & (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                               >> 0x14U)) : 0U));
    vlTOPp->core_robin__DOT__controlStore_io_ALU_OP 
        = ((0U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
            ? 0U : ((1U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                     ? 0U : ((2U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                              ? ((0x13U == (0x7fU & vlTOPp->core_robin__DOT__controlStore__DOT__instruction))
                                  ? ((0x18U & (((1U 
                                                 == 
                                                 (3U 
                                                  & (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                                     >> 0xcU))) 
                                                << 3U) 
                                               & (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                                  >> 0x1bU))) 
                                     | (7U & (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                              >> 0xcU)))
                                  : ((0x33U == (0x7fU 
                                                & vlTOPp->core_robin__DOT__controlStore__DOT__instruction))
                                      ? ((8U & (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                                >> 0x1bU)) 
                                         | (7U & (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                                  >> 0xcU)))
                                      : 0U)) : 0U)));
    vlTOPp->core_robin__DOT__storeUnit__DOT__stateReg 
        = __Vdly__core_robin__DOT__storeUnit__DOT__stateReg;
    vlTOPp->core_robin__DOT__branchImmBranchAddr = 
        (vlTOPp->core_robin__DOT__PC + ((0U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                                         ? 0U : ((1U 
                                                  == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                                                  ? 0U
                                                  : 
                                                 ((2U 
                                                   == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                                                   ? 0U
                                                   : 
                                                  ((3U 
                                                    == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                                                    ? 
                                                   ((0x63U 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->core_robin__DOT__controlStore__DOT__instruction))
                                                     ? 
                                                    ((0x80000000U 
                                                      & vlTOPp->core_robin__DOT__controlStore__DOT__instruction)
                                                      ? 
                                                     (0xffffe000U 
                                                      | (IData)(vlTOPp->core_robin__DOT__controlStore__DOT___T_65))
                                                      : (IData)(vlTOPp->core_robin__DOT__controlStore__DOT___T_65))
                                                     : 
                                                    ((0x80000000U 
                                                      & vlTOPp->core_robin__DOT__controlStore__DOT__instruction)
                                                      ? 
                                                     (0xffe00000U 
                                                      | vlTOPp->core_robin__DOT__controlStore__DOT___T_66)
                                                      : vlTOPp->core_robin__DOT__controlStore__DOT___T_66))
                                                    : 0U)))));
    vlTOPp->core_robin__DOT__storeUnit__DOT___GEN_4 
        = (((IData)(vlTOPp->core_robin__DOT__controlStore_io_STORE_ADDRESS_IN) 
            & (~ (IData)(vlTOPp->core_robin__DOT__storeUnit__DOT__storing)))
            ? vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT__ALUoutput
            : vlTOPp->core_robin__DOT__storeUnit__DOT__store_data_buffer_address);
    vlTOPp->core_robin__DOT__controlStore_io_WRITE_EN 
        = ((0U != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
           & ((1U != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
              & ((2U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                  ? (0x67U == (0x77U & vlTOPp->core_robin__DOT__controlStore__DOT__instruction))
                  : ((3U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                      ? (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                         >> 4U) : (IData)(vlTOPp->core_robin__DOT__controlStore__DOT___GEN_36)))));
    vlTOPp->core_robin__DOT__dataPath__DOT__rdData 
        = (((0U != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
            & ((1U != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
               & ((2U != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                  & ((3U != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                     & (IData)(vlTOPp->core_robin__DOT__controlStore__DOT___GEN_36)))))
            ? 0U : vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT__ALUoutput);
    vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT___GEN_54 
        = ((0x15U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
            ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_21
            : ((0x14U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_20
                : ((0x13U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                    ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_19
                    : ((0x12U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                        ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_18
                        : ((0x11U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                            ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_17
                            : ((0x10U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_16
                                : ((0xfU == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                    ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_15
                                    : ((0xeU == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                        ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_14
                                        : ((0xdU == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                            ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_13
                                            : ((0xcU 
                                                == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                                ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_12
                                                : (
                                                   (0xbU 
                                                    == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                                    ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_11
                                                    : 
                                                   ((0xaU 
                                                     == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                                     ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_10
                                                     : 
                                                    ((9U 
                                                      == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                                      ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_9
                                                      : 
                                                     ((8U 
                                                       == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                                       ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_8
                                                       : 
                                                      ((7U 
                                                        == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                                        ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_7
                                                        : 
                                                       ((6U 
                                                         == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                                         ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_6
                                                         : 
                                                        ((5U 
                                                          == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                                          ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_5
                                                          : 
                                                         ((4U 
                                                           == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                                           ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_4
                                                           : 
                                                          ((3U 
                                                            == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                                            ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_3
                                                            : 
                                                           ((2U 
                                                             == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                                             ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_2
                                                             : 
                                                            ((1U 
                                                              == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                                              ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_1
                                                              : vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_0)))))))))))))))))))));
    vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT___GEN_4 
        = ((5U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_ALU_OP))
            ? (vlTOPp->core_robin__DOT__dataPath__DOT__ALU_in1 
               >> (0x1fU & vlTOPp->core_robin__DOT__dataPath__DOT__ALU_in2))
            : ((0xdU == (IData)(vlTOPp->core_robin__DOT__controlStore_io_ALU_OP))
                ? VL_SHIFTRS_III(32,32,5, vlTOPp->core_robin__DOT__dataPath__DOT__ALU_in1, 
                                 (0x1fU & vlTOPp->core_robin__DOT__dataPath__DOT__ALU_in2))
                : ((4U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_ALU_OP))
                    ? (vlTOPp->core_robin__DOT__dataPath__DOT__ALU_in1 
                       ^ vlTOPp->core_robin__DOT__dataPath__DOT__ALU_in2)
                    : ((6U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_ALU_OP))
                        ? (vlTOPp->core_robin__DOT__dataPath__DOT__ALU_in1 
                           | vlTOPp->core_robin__DOT__dataPath__DOT__ALU_in2)
                        : ((7U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_ALU_OP))
                            ? (vlTOPp->core_robin__DOT__dataPath__DOT__ALU_in1 
                               & vlTOPp->core_robin__DOT__dataPath__DOT__ALU_in2)
                            : vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT__ALUoutput)))));
    vlTOPp->core_robin__DOT__storeUnit__DOT___T = (1U 
                                                   & (~ (IData)(vlTOPp->core_robin__DOT__storeUnit__DOT__stateReg)));
    vlTOPp->core_robin__DOT__storeUnit__DOT___GEN_14 
        = ((IData)(vlTOPp->core_robin__DOT__storeUnit__DOT__stateReg)
            ? ((IData)(vlTOPp->core_robin__DOT__storeUnit__DOT__stateReg)
                ? ((IData)(vlTOPp->core_robin__DOT__controlStore_io_STORE_ADDRESS_IN) 
                   | (IData)(vlTOPp->core_robin__DOT__storeUnit__DOT__storing))
                : (IData)(vlTOPp->core_robin__DOT__storeUnit__DOT__storing))
            : (IData)(vlTOPp->core_robin__DOT__storeUnit__DOT__storing));
    vlTOPp->core_robin__DOT__controlStore__DOT___GEN_48 
        = ((3U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
            ? ((3U == (0x7fU & vlTOPp->core_robin__DOT__controlStore__DOT__instruction))
                ? 4U : 0U) : ((4U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                               ? ((IData)(vlTOPp->core_robin__DOT__controlStore__DOT__LOAD_READY)
                                   ? 0U : 5U) : ((5U 
                                                  == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                                                  ? 
                                                 ((1U 
                                                   == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stallState))
                                                   ? 
                                                  ((IData)(vlTOPp->core_robin__DOT__storeUnit__DOT__stateReg)
                                                    ? (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)
                                                    : (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stallState))
                                                   : 
                                                  ((4U 
                                                    == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stallState))
                                                    ? 
                                                   ((IData)(vlTOPp->core_robin__DOT__controlStore__DOT__LOAD_READY)
                                                     ? (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stallState)
                                                     : (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                                                    : (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)))
                                                  : (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))));
    vlTOPp->core_robin__DOT__controlStore__DOT___GEN_4 
        = ((IData)(vlTOPp->core_robin__DOT__controlStore__DOT__STORE_READY)
            ? (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stallState)
            : (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg));
    vlTOPp->core_robin__DOT__controlStore_io_DATA_IN 
        = ((0U != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
           & ((1U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
              & ((0x23U == (0x7fU & vlTOPp->core_robin__DOT__controlStore__DOT__instruction)) 
                 & (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__STORE_READY))));
    vlTOPp->core_robin__DOT__dataPath__DOT__registerFile_io_rdData 
        = ((IData)(vlTOPp->core_robin__DOT__controlStore_io_PROCEDURE_BRANCHING)
            ? ((IData)(4U) + vlTOPp->core_robin__DOT__PC)
            : vlTOPp->core_robin__DOT__dataPath__DOT__rdData);
    vlTOPp->core_robin__DOT__dataPath__DOT__rs2_ALU 
        = ((0U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
            ? vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT__ALUoutput
            : ((0U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                ? 0U : ((0x1fU == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                         ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_31
                         : ((0x1eU == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                             ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_30
                             : ((0x1dU == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                 ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_29
                                 : ((0x1cU == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                     ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_28
                                     : ((0x1bU == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                         ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_27
                                         : ((0x1aU 
                                             == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                             ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_26
                                             : ((0x19U 
                                                 == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                                 ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_25
                                                 : 
                                                ((0x18U 
                                                  == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                                  ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_24
                                                  : 
                                                 ((0x17U 
                                                   == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                                   ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_23
                                                   : 
                                                  ((0x16U 
                                                    == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                                    ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_22
                                                    : vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT___GEN_54))))))))))));
    vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT___GEN_7 
        = (VL_ULL(0x7fffffffffffffff) & ((0U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_ALU_OP))
                                          ? (((QData)((IData)(
                                                              (0x7fffffffU 
                                                               & VL_NEGATE_I((IData)(
                                                                                (1U 
                                                                                & (vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT___T_3 
                                                                                >> 0x1fU))))))) 
                                              << 0x20U) 
                                             | (QData)((IData)(vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT___T_3)))
                                          : ((8U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_ALU_OP))
                                              ? (((QData)((IData)(
                                                                  (0x7fffffffU 
                                                                   & VL_NEGATE_I((IData)(
                                                                                (1U 
                                                                                & (vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT___T_7 
                                                                                >> 0x1fU))))))) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT___T_7)))
                                              : ((1U 
                                                  == (IData)(vlTOPp->core_robin__DOT__controlStore_io_ALU_OP))
                                                  ? 
                                                 ((((QData)((IData)(
                                                                    (0x7fffffffU 
                                                                     & VL_NEGATE_I((IData)(
                                                                                (1U 
                                                                                & (vlTOPp->core_robin__DOT__dataPath__DOT__ALU_in1 
                                                                                >> 0x1fU))))))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(vlTOPp->core_robin__DOT__dataPath__DOT__ALU_in1))) 
                                                  << 
                                                  (0x1fU 
                                                   & vlTOPp->core_robin__DOT__dataPath__DOT__ALU_in2))
                                                  : 
                                                 (((QData)((IData)(
                                                                   (0x7fffffffU 
                                                                    & VL_NEGATE_I((IData)(
                                                                                (1U 
                                                                                & (vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT___GEN_4 
                                                                                >> 0x1fU))))))) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT___GEN_4)))))));
    vlTOPp->core_robin__DOT__storeUnit__DOT___GEN_9 
        = ((IData)(vlTOPp->core_robin__DOT__storeUnit__DOT__stateReg)
            ? (IData)(vlTOPp->core_robin__DOT__storeUnit__DOT__stateReg)
            : ((IData)(vlTOPp->core_robin__DOT__controlStore_io_DATA_IN) 
               | (IData)(vlTOPp->core_robin__DOT__storeUnit__DOT__stateReg)));
    vlTOPp->core_robin__DOT__storeUnit__DOT___GEN_11 
        = (3U & ((IData)(vlTOPp->core_robin__DOT__storeUnit__DOT__stateReg)
                  ? (IData)(vlTOPp->core_robin__DOT__storeUnit__DOT__store_data_size_buffer)
                  : ((IData)(vlTOPp->core_robin__DOT__controlStore_io_DATA_IN)
                      ? ((0U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                          ? 1U : ((1U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                                   ? ((0x23U == (0x7fU 
                                                 & vlTOPp->core_robin__DOT__controlStore__DOT__instruction))
                                       ? ((0x2000U 
                                           & vlTOPp->core_robin__DOT__controlStore__DOT__instruction)
                                           ? 0U : (~ 
                                                   (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                                    >> 0xcU)))
                                       : 1U) : 1U))
                      : (IData)(vlTOPp->core_robin__DOT__storeUnit__DOT__store_data_size_buffer))));
    vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT___GEN_11 
        = (VL_LTS_III(1,32,32, vlTOPp->core_robin__DOT__dataPath__DOT__ALU_in1, vlTOPp->core_robin__DOT__dataPath__DOT__ALU_in2)
            ? ((2U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_ALU_OP))
                ? VL_ULL(1) : vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT___GEN_7)
            : vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT___GEN_7);
}

void Vcore_robin::_settle__TOP__3(Vcore_robin__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore_robin::_settle__TOP__3\n"); );
    Vcore_robin* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->io_RECIEVED = vlTOPp->core_robin__DOT__controlStore__DOT__RECIEVED;
    vlTOPp->io_mem_write = vlTOPp->core_robin__DOT__storeUnit__DOT__storing;
    vlTOPp->core_robin__DOT__storeUnit__DOT___T_10 
        = (0xffffffU & (vlTOPp->core_robin__DOT__storeUnit__DOT__store_data_buffer 
                        >> 8U));
    vlTOPp->core_robin__DOT__storeUnit__DOT___T_12 
        = ((IData)(1U) + vlTOPp->core_robin__DOT__storeUnit__DOT__store_data_buffer_address);
    vlTOPp->core_robin__DOT__storeUnit__DOT___T_15 
        = (3U & ((IData)(1U) + (IData)(vlTOPp->core_robin__DOT__storeUnit__DOT__store_data_size_buffer)));
    vlTOPp->io_mem_write_data = ((IData)(vlTOPp->core_robin__DOT__storeUnit__DOT__storing)
                                  ? (0xffU & vlTOPp->core_robin__DOT__storeUnit__DOT__store_data_buffer)
                                  : 0U);
    vlTOPp->io_mem_write_address = ((IData)(vlTOPp->core_robin__DOT__storeUnit__DOT__storing)
                                     ? vlTOPp->core_robin__DOT__storeUnit__DOT__store_data_buffer_address
                                     : 0U);
    vlTOPp->core_robin__DOT__noBranchNextAddr = ((IData)(4U) 
                                                 + vlTOPp->core_robin__DOT__PC);
    vlTOPp->io_PC = vlTOPp->core_robin__DOT__PC;
    vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT___T_3 
        = (vlTOPp->core_robin__DOT__dataPath__DOT__ALU_in1 
           + vlTOPp->core_robin__DOT__dataPath__DOT__ALU_in2);
    vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT___T_7 
        = (vlTOPp->core_robin__DOT__dataPath__DOT__ALU_in1 
           - vlTOPp->core_robin__DOT__dataPath__DOT__ALU_in2);
    vlTOPp->core_robin__DOT__controlStore__DOT___T 
        = (0U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg));
    vlTOPp->core_robin__DOT__controlStore__DOT___T_2 
        = (1U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg));
    vlTOPp->core_robin__DOT__controlStore__DOT___T_18 
        = (0xfffU & ((0x23U == (0x7fU & vlTOPp->core_robin__DOT__controlStore__DOT__instruction))
                      ? ((0xfe0U & (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                    >> 0x14U)) | (0x1fU 
                                                  & (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                                     >> 7U)))
                      : (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                         >> 0x14U)));
    vlTOPp->core_robin__DOT__controlStore__DOT___T_34 
        = (2U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg));
    vlTOPp->core_robin__DOT__controlStore__DOT___GEN_15 
        = ((0x67U == (0x77U & vlTOPp->core_robin__DOT__controlStore__DOT__instruction)) 
           & (0x67U == (0x7fU & vlTOPp->core_robin__DOT__controlStore__DOT__instruction)));
    vlTOPp->core_robin__DOT__controlStore_io_RD = (
                                                   (0U 
                                                    == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                                                    ? 0U
                                                    : 
                                                   ((1U 
                                                     == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                                                     ? 0U
                                                     : 
                                                    (0x1fU 
                                                     & ((2U 
                                                         == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                                                         ? 
                                                        ((0x67U 
                                                          == 
                                                          (0x77U 
                                                           & vlTOPp->core_robin__DOT__controlStore__DOT__instruction))
                                                          ? 
                                                         (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                                          >> 7U)
                                                          : 0U)
                                                         : 
                                                        ((3U 
                                                          == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                                                          ? 
                                                         (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                                          >> 7U)
                                                          : 
                                                         ((4U 
                                                           == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                                                           ? 
                                                          (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                                           >> 7U)
                                                           : 0U))))));
    vlTOPp->core_robin__DOT__controlStore_io_BRANCH_SELECT 
        = ((0U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
            ? 1U : ((1U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                     ? 1U : ((2U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                              ? 1U : ((3U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                                       ? ((0x63U == 
                                           (0x7fU & vlTOPp->core_robin__DOT__controlStore__DOT__instruction))
                                           ? (3U & 
                                              (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                               >> 0xdU))
                                           : 1U) : 1U))));
    vlTOPp->core_robin__DOT__controlStore__DOT___GEN_51 
        = ((3U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
            ? (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stallState)
            : ((4U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                ? ((IData)(vlTOPp->core_robin__DOT__controlStore__DOT__LOAD_READY)
                    ? (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stallState)
                    : (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                : (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stallState)));
    vlTOPp->core_robin__DOT__controlStore_io_PROCEDURE_BRANCHING 
        = ((0U != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
           & ((1U != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
              & ((2U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                  ? (0x67U == (0x77U & vlTOPp->core_robin__DOT__controlStore__DOT__instruction))
                  : ((3U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                     & (0x67U == (0x77U & vlTOPp->core_robin__DOT__controlStore__DOT__instruction))))));
    vlTOPp->core_robin__DOT__controlStore__DOT___T_65 
        = ((0x1000U & (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                       >> 0x13U)) | ((0x800U & (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                                << 4U)) 
                                     | ((0x7e0U & (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                                   >> 0x14U)) 
                                        | (0x1eU & 
                                           (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                            >> 7U)))));
    vlTOPp->core_robin__DOT__controlStore__DOT___T_66 
        = ((0x100000U & (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                         >> 0xbU)) | ((0xff000U & vlTOPp->core_robin__DOT__controlStore__DOT__instruction) 
                                      | ((0x800U & 
                                          (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                           >> 9U)) 
                                         | (0x7feU 
                                            & (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                               >> 0x14U)))));
    vlTOPp->core_robin__DOT__controlStore_io_STORE_ADDRESS_IN 
        = ((0U != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
           & ((1U != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
              & ((2U != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                 & ((3U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                    & (0x23U == (0x7fU & vlTOPp->core_robin__DOT__controlStore__DOT__instruction))))));
    vlTOPp->core_robin__DOT__controlStore__DOT___GEN_36 
        = ((4U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
           & (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__LOAD_READY));
    vlTOPp->core_robin__DOT__controlStore_io_RS1 = 
        ((0U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
          ? 0U : ((1U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                   ? ((0x37U == vlTOPp->io_INSTRUCTION)
                       ? 0U : (0x1fU & (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                        >> 0xfU))) : 0U));
    vlTOPp->core_robin__DOT__controlStore_io_RS2 = 
        ((0U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
          ? 0U : ((1U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                   ? (0x1fU & (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                               >> 0x14U)) : 0U));
    vlTOPp->core_robin__DOT__controlStore_io_ALU_OP 
        = ((0U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
            ? 0U : ((1U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                     ? 0U : ((2U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                              ? ((0x13U == (0x7fU & vlTOPp->core_robin__DOT__controlStore__DOT__instruction))
                                  ? ((0x18U & (((1U 
                                                 == 
                                                 (3U 
                                                  & (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                                     >> 0xcU))) 
                                                << 3U) 
                                               & (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                                  >> 0x1bU))) 
                                     | (7U & (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                              >> 0xcU)))
                                  : ((0x33U == (0x7fU 
                                                & vlTOPp->core_robin__DOT__controlStore__DOT__instruction))
                                      ? ((8U & (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                                >> 0x1bU)) 
                                         | (7U & (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                                  >> 0xcU)))
                                      : 0U)) : 0U)));
    vlTOPp->core_robin__DOT__storeUnit__DOT___T = (1U 
                                                   & (~ (IData)(vlTOPp->core_robin__DOT__storeUnit__DOT__stateReg)));
    vlTOPp->core_robin__DOT__controlStore__DOT___GEN_4 
        = ((IData)(vlTOPp->core_robin__DOT__controlStore__DOT__STORE_READY)
            ? (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stallState)
            : (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg));
    vlTOPp->core_robin__DOT__controlStore__DOT___GEN_48 
        = ((3U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
            ? ((3U == (0x7fU & vlTOPp->core_robin__DOT__controlStore__DOT__instruction))
                ? 4U : 0U) : ((4U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                               ? ((IData)(vlTOPp->core_robin__DOT__controlStore__DOT__LOAD_READY)
                                   ? 0U : 5U) : ((5U 
                                                  == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                                                  ? 
                                                 ((1U 
                                                   == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stallState))
                                                   ? 
                                                  ((IData)(vlTOPp->core_robin__DOT__storeUnit__DOT__stateReg)
                                                    ? (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)
                                                    : (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stallState))
                                                   : 
                                                  ((4U 
                                                    == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stallState))
                                                    ? 
                                                   ((IData)(vlTOPp->core_robin__DOT__controlStore__DOT__LOAD_READY)
                                                     ? (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stallState)
                                                     : (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                                                    : (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)))
                                                  : (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))));
    vlTOPp->core_robin__DOT__controlStore_io_DATA_IN 
        = ((0U != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
           & ((1U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
              & ((0x23U == (0x7fU & vlTOPp->core_robin__DOT__controlStore__DOT__instruction)) 
                 & (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__STORE_READY))));
    vlTOPp->core_robin__DOT__branchImmBranchAddr = 
        (vlTOPp->core_robin__DOT__PC + ((0U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                                         ? 0U : ((1U 
                                                  == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                                                  ? 0U
                                                  : 
                                                 ((2U 
                                                   == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                                                   ? 0U
                                                   : 
                                                  ((3U 
                                                    == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                                                    ? 
                                                   ((0x63U 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->core_robin__DOT__controlStore__DOT__instruction))
                                                     ? 
                                                    ((0x80000000U 
                                                      & vlTOPp->core_robin__DOT__controlStore__DOT__instruction)
                                                      ? 
                                                     (0xffffe000U 
                                                      | (IData)(vlTOPp->core_robin__DOT__controlStore__DOT___T_65))
                                                      : (IData)(vlTOPp->core_robin__DOT__controlStore__DOT___T_65))
                                                     : 
                                                    ((0x80000000U 
                                                      & vlTOPp->core_robin__DOT__controlStore__DOT__instruction)
                                                      ? 
                                                     (0xffe00000U 
                                                      | vlTOPp->core_robin__DOT__controlStore__DOT___T_66)
                                                      : vlTOPp->core_robin__DOT__controlStore__DOT___T_66))
                                                    : 0U)))));
    vlTOPp->core_robin__DOT__storeUnit__DOT___GEN_4 
        = (((IData)(vlTOPp->core_robin__DOT__controlStore_io_STORE_ADDRESS_IN) 
            & (~ (IData)(vlTOPp->core_robin__DOT__storeUnit__DOT__storing)))
            ? vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT__ALUoutput
            : vlTOPp->core_robin__DOT__storeUnit__DOT__store_data_buffer_address);
    vlTOPp->core_robin__DOT__storeUnit__DOT___GEN_14 
        = ((IData)(vlTOPp->core_robin__DOT__storeUnit__DOT__stateReg)
            ? ((IData)(vlTOPp->core_robin__DOT__storeUnit__DOT__stateReg)
                ? ((IData)(vlTOPp->core_robin__DOT__controlStore_io_STORE_ADDRESS_IN) 
                   | (IData)(vlTOPp->core_robin__DOT__storeUnit__DOT__storing))
                : (IData)(vlTOPp->core_robin__DOT__storeUnit__DOT__storing))
            : (IData)(vlTOPp->core_robin__DOT__storeUnit__DOT__storing));
    vlTOPp->core_robin__DOT__controlStore_io_WRITE_EN 
        = ((0U != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
           & ((1U != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
              & ((2U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                  ? (0x67U == (0x77U & vlTOPp->core_robin__DOT__controlStore__DOT__instruction))
                  : ((3U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                      ? (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                         >> 4U) : (IData)(vlTOPp->core_robin__DOT__controlStore__DOT___GEN_36)))));
    vlTOPp->core_robin__DOT__dataPath__DOT__rdData 
        = (((0U != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
            & ((1U != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
               & ((2U != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                  & ((3U != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                     & (IData)(vlTOPp->core_robin__DOT__controlStore__DOT___GEN_36)))))
            ? 0U : vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT__ALUoutput);
    vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT___GEN_21 
        = ((0x15U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
            ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_21
            : ((0x14U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_20
                : ((0x13U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                    ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_19
                    : ((0x12U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                        ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_18
                        : ((0x11U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                            ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_17
                            : ((0x10U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_16
                                : ((0xfU == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                    ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_15
                                    : ((0xeU == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                        ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_14
                                        : ((0xdU == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                            ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_13
                                            : ((0xcU 
                                                == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                                ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_12
                                                : (
                                                   (0xbU 
                                                    == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                                    ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_11
                                                    : 
                                                   ((0xaU 
                                                     == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                                     ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_10
                                                     : 
                                                    ((9U 
                                                      == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                                      ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_9
                                                      : 
                                                     ((8U 
                                                       == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                                       ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_8
                                                       : 
                                                      ((7U 
                                                        == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                                        ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_7
                                                        : 
                                                       ((6U 
                                                         == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                                         ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_6
                                                         : 
                                                        ((5U 
                                                          == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                                          ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_5
                                                          : 
                                                         ((4U 
                                                           == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                                           ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_4
                                                           : 
                                                          ((3U 
                                                            == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                                            ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_3
                                                            : 
                                                           ((2U 
                                                             == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                                             ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_2
                                                             : 
                                                            ((1U 
                                                              == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                                              ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_1
                                                              : vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_0)))))))))))))))))))));
    vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT___GEN_54 
        = ((0x15U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
            ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_21
            : ((0x14U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_20
                : ((0x13U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                    ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_19
                    : ((0x12U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                        ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_18
                        : ((0x11U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                            ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_17
                            : ((0x10U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_16
                                : ((0xfU == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                    ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_15
                                    : ((0xeU == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                        ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_14
                                        : ((0xdU == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                            ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_13
                                            : ((0xcU 
                                                == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                                ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_12
                                                : (
                                                   (0xbU 
                                                    == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                                    ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_11
                                                    : 
                                                   ((0xaU 
                                                     == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                                     ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_10
                                                     : 
                                                    ((9U 
                                                      == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                                      ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_9
                                                      : 
                                                     ((8U 
                                                       == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                                       ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_8
                                                       : 
                                                      ((7U 
                                                        == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                                        ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_7
                                                        : 
                                                       ((6U 
                                                         == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                                         ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_6
                                                         : 
                                                        ((5U 
                                                          == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                                          ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_5
                                                          : 
                                                         ((4U 
                                                           == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                                           ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_4
                                                           : 
                                                          ((3U 
                                                            == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                                            ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_3
                                                            : 
                                                           ((2U 
                                                             == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                                             ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_2
                                                             : 
                                                            ((1U 
                                                              == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                                              ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_1
                                                              : vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_0)))))))))))))))))))));
    vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT___GEN_4 
        = ((5U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_ALU_OP))
            ? (vlTOPp->core_robin__DOT__dataPath__DOT__ALU_in1 
               >> (0x1fU & vlTOPp->core_robin__DOT__dataPath__DOT__ALU_in2))
            : ((0xdU == (IData)(vlTOPp->core_robin__DOT__controlStore_io_ALU_OP))
                ? VL_SHIFTRS_III(32,32,5, vlTOPp->core_robin__DOT__dataPath__DOT__ALU_in1, 
                                 (0x1fU & vlTOPp->core_robin__DOT__dataPath__DOT__ALU_in2))
                : ((4U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_ALU_OP))
                    ? (vlTOPp->core_robin__DOT__dataPath__DOT__ALU_in1 
                       ^ vlTOPp->core_robin__DOT__dataPath__DOT__ALU_in2)
                    : ((6U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_ALU_OP))
                        ? (vlTOPp->core_robin__DOT__dataPath__DOT__ALU_in1 
                           | vlTOPp->core_robin__DOT__dataPath__DOT__ALU_in2)
                        : ((7U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_ALU_OP))
                            ? (vlTOPp->core_robin__DOT__dataPath__DOT__ALU_in1 
                               & vlTOPp->core_robin__DOT__dataPath__DOT__ALU_in2)
                            : vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT__ALUoutput)))));
    vlTOPp->core_robin__DOT__storeUnit__DOT___GEN_9 
        = ((IData)(vlTOPp->core_robin__DOT__storeUnit__DOT__stateReg)
            ? (IData)(vlTOPp->core_robin__DOT__storeUnit__DOT__stateReg)
            : ((IData)(vlTOPp->core_robin__DOT__controlStore_io_DATA_IN) 
               | (IData)(vlTOPp->core_robin__DOT__storeUnit__DOT__stateReg)));
    vlTOPp->core_robin__DOT__storeUnit__DOT___GEN_11 
        = (3U & ((IData)(vlTOPp->core_robin__DOT__storeUnit__DOT__stateReg)
                  ? (IData)(vlTOPp->core_robin__DOT__storeUnit__DOT__store_data_size_buffer)
                  : ((IData)(vlTOPp->core_robin__DOT__controlStore_io_DATA_IN)
                      ? ((0U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                          ? 1U : ((1U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                                   ? ((0x23U == (0x7fU 
                                                 & vlTOPp->core_robin__DOT__controlStore__DOT__instruction))
                                       ? ((0x2000U 
                                           & vlTOPp->core_robin__DOT__controlStore__DOT__instruction)
                                           ? 0U : (~ 
                                                   (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                                    >> 0xcU)))
                                       : 1U) : 1U))
                      : (IData)(vlTOPp->core_robin__DOT__storeUnit__DOT__store_data_size_buffer))));
    vlTOPp->core_robin__DOT__dataPath__DOT__registerFile_io_rdData 
        = ((IData)(vlTOPp->core_robin__DOT__controlStore_io_PROCEDURE_BRANCHING)
            ? ((IData)(4U) + vlTOPp->core_robin__DOT__PC)
            : vlTOPp->core_robin__DOT__dataPath__DOT__rdData);
    vlTOPp->core_robin__DOT__dataPath__DOT__rs2_ALU 
        = ((0U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
            ? vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT__ALUoutput
            : ((0U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                ? 0U : ((0x1fU == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                         ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_31
                         : ((0x1eU == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                             ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_30
                             : ((0x1dU == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                 ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_29
                                 : ((0x1cU == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                     ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_28
                                     : ((0x1bU == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                         ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_27
                                         : ((0x1aU 
                                             == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                             ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_26
                                             : ((0x19U 
                                                 == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                                 ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_25
                                                 : 
                                                ((0x18U 
                                                  == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                                  ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_24
                                                  : 
                                                 ((0x17U 
                                                   == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                                   ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_23
                                                   : 
                                                  ((0x16U 
                                                    == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                                    ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_22
                                                    : vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT___GEN_54))))))))))));
    vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT___GEN_7 
        = (VL_ULL(0x7fffffffffffffff) & ((0U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_ALU_OP))
                                          ? (((QData)((IData)(
                                                              (0x7fffffffU 
                                                               & VL_NEGATE_I((IData)(
                                                                                (1U 
                                                                                & (vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT___T_3 
                                                                                >> 0x1fU))))))) 
                                              << 0x20U) 
                                             | (QData)((IData)(vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT___T_3)))
                                          : ((8U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_ALU_OP))
                                              ? (((QData)((IData)(
                                                                  (0x7fffffffU 
                                                                   & VL_NEGATE_I((IData)(
                                                                                (1U 
                                                                                & (vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT___T_7 
                                                                                >> 0x1fU))))))) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT___T_7)))
                                              : ((1U 
                                                  == (IData)(vlTOPp->core_robin__DOT__controlStore_io_ALU_OP))
                                                  ? 
                                                 ((((QData)((IData)(
                                                                    (0x7fffffffU 
                                                                     & VL_NEGATE_I((IData)(
                                                                                (1U 
                                                                                & (vlTOPp->core_robin__DOT__dataPath__DOT__ALU_in1 
                                                                                >> 0x1fU))))))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(vlTOPp->core_robin__DOT__dataPath__DOT__ALU_in1))) 
                                                  << 
                                                  (0x1fU 
                                                   & vlTOPp->core_robin__DOT__dataPath__DOT__ALU_in2))
                                                  : 
                                                 (((QData)((IData)(
                                                                   (0x7fffffffU 
                                                                    & VL_NEGATE_I((IData)(
                                                                                (1U 
                                                                                & (vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT___GEN_4 
                                                                                >> 0x1fU))))))) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT___GEN_4)))))));
    vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT___GEN_11 
        = (VL_LTS_III(1,32,32, vlTOPp->core_robin__DOT__dataPath__DOT__ALU_in1, vlTOPp->core_robin__DOT__dataPath__DOT__ALU_in2)
            ? ((2U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_ALU_OP))
                ? VL_ULL(1) : vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT___GEN_7)
            : vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT___GEN_7);
}

VL_INLINE_OPT void Vcore_robin::_combo__TOP__4(Vcore_robin__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore_robin::_combo__TOP__4\n"); );
    Vcore_robin* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->core_robin__DOT__controlStore_io_RS1 = 
        ((0U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
          ? 0U : ((1U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                   ? ((0x37U == vlTOPp->io_INSTRUCTION)
                       ? 0U : (0x1fU & (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                        >> 0xfU))) : 0U));
    vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT___GEN_21 
        = ((0x15U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
            ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_21
            : ((0x14U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_20
                : ((0x13U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                    ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_19
                    : ((0x12U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                        ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_18
                        : ((0x11U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                            ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_17
                            : ((0x10U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_16
                                : ((0xfU == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                    ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_15
                                    : ((0xeU == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                        ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_14
                                        : ((0xdU == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                            ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_13
                                            : ((0xcU 
                                                == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                                ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_12
                                                : (
                                                   (0xbU 
                                                    == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                                    ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_11
                                                    : 
                                                   ((0xaU 
                                                     == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                                     ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_10
                                                     : 
                                                    ((9U 
                                                      == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                                      ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_9
                                                      : 
                                                     ((8U 
                                                       == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                                       ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_8
                                                       : 
                                                      ((7U 
                                                        == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                                        ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_7
                                                        : 
                                                       ((6U 
                                                         == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                                         ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_6
                                                         : 
                                                        ((5U 
                                                          == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                                          ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_5
                                                          : 
                                                         ((4U 
                                                           == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                                           ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_4
                                                           : 
                                                          ((3U 
                                                            == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                                            ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_3
                                                            : 
                                                           ((2U 
                                                             == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                                             ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_2
                                                             : 
                                                            ((1U 
                                                              == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                                              ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_1
                                                              : vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_0)))))))))))))))))))));
}

void Vcore_robin::_eval(Vcore_robin__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore_robin::_eval\n"); );
    Vcore_robin* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock)))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
        vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
    }
    vlTOPp->_combo__TOP__4(vlSymsp);
    vlTOPp->__Vm_traceActivity = (4U | vlTOPp->__Vm_traceActivity);
    // Final
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void Vcore_robin::_eval_initial(Vcore_robin__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore_robin::_eval_initial\n"); );
    Vcore_robin* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void Vcore_robin::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore_robin::final\n"); );
    // Variables
    Vcore_robin__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vcore_robin* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vcore_robin::_eval_settle(Vcore_robin__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore_robin::_eval_settle\n"); );
    Vcore_robin* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
}

VL_INLINE_OPT QData Vcore_robin::_change_request(Vcore_robin__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore_robin::_change_request\n"); );
    Vcore_robin* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vcore_robin::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore_robin::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((io_INSTRUCTION_LOADED & 0xfeU))) {
        Verilated::overWidthError("io_INSTRUCTION_LOADED");}
}
#endif  // VL_DEBUG

void Vcore_robin::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore_robin::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    io_INSTRUCTION = VL_RAND_RESET_I(32);
    io_RECIEVED = VL_RAND_RESET_I(1);
    io_INSTRUCTION_LOADED = VL_RAND_RESET_I(1);
    io_PC = VL_RAND_RESET_I(32);
    io_rdAddr = VL_RAND_RESET_I(32);
    io_rdData = VL_RAND_RESET_I(8);
    io_mem_write = VL_RAND_RESET_I(1);
    io_mem_write_data = VL_RAND_RESET_I(8);
    io_mem_write_address = VL_RAND_RESET_I(32);
    core_robin__DOT__controlStore_io_RS1 = VL_RAND_RESET_I(5);
    core_robin__DOT__controlStore_io_RS2 = VL_RAND_RESET_I(5);
    core_robin__DOT__controlStore_io_RD = VL_RAND_RESET_I(5);
    core_robin__DOT__controlStore_io_WRITE_EN = VL_RAND_RESET_I(1);
    core_robin__DOT__controlStore_io_ALU_OP = VL_RAND_RESET_I(4);
    core_robin__DOT__controlStore_io_PROCEDURE_BRANCHING = VL_RAND_RESET_I(1);
    core_robin__DOT__controlStore_io_DATA_IN = VL_RAND_RESET_I(1);
    core_robin__DOT__controlStore_io_STORE_ADDRESS_IN = VL_RAND_RESET_I(1);
    core_robin__DOT__controlStore_io_BRANCH_SELECT = VL_RAND_RESET_I(2);
    core_robin__DOT__PC = VL_RAND_RESET_I(32);
    core_robin__DOT__noBranchNextAddr = VL_RAND_RESET_I(32);
    core_robin__DOT__branchImmBranchAddr = VL_RAND_RESET_I(32);
    core_robin__DOT__controlStore__DOT__stateReg = VL_RAND_RESET_I(3);
    core_robin__DOT__controlStore__DOT__stallState = VL_RAND_RESET_I(3);
    core_robin__DOT__controlStore__DOT__instruction = VL_RAND_RESET_I(32);
    core_robin__DOT__controlStore__DOT__RECIEVED = VL_RAND_RESET_I(1);
    core_robin__DOT__controlStore__DOT__STORE_READY = VL_RAND_RESET_I(1);
    core_robin__DOT__controlStore__DOT__LOAD_READY = VL_RAND_RESET_I(1);
    core_robin__DOT__controlStore__DOT___T = VL_RAND_RESET_I(1);
    core_robin__DOT__controlStore__DOT___T_2 = VL_RAND_RESET_I(1);
    core_robin__DOT__controlStore__DOT___T_18 = VL_RAND_RESET_I(12);
    core_robin__DOT__controlStore__DOT___GEN_4 = VL_RAND_RESET_I(3);
    core_robin__DOT__controlStore__DOT___T_34 = VL_RAND_RESET_I(1);
    core_robin__DOT__controlStore__DOT___GEN_15 = VL_RAND_RESET_I(1);
    core_robin__DOT__controlStore__DOT___T_65 = VL_RAND_RESET_I(13);
    core_robin__DOT__controlStore__DOT___T_66 = VL_RAND_RESET_I(21);
    core_robin__DOT__controlStore__DOT___GEN_36 = VL_RAND_RESET_I(1);
    core_robin__DOT__controlStore__DOT___GEN_48 = VL_RAND_RESET_I(3);
    core_robin__DOT__controlStore__DOT___GEN_51 = VL_RAND_RESET_I(3);
    core_robin__DOT__dataPath__DOT__registerFile_io_rdData = VL_RAND_RESET_I(32);
    core_robin__DOT__dataPath__DOT__ALU_in1 = VL_RAND_RESET_I(32);
    core_robin__DOT__dataPath__DOT__ALU_in2 = VL_RAND_RESET_I(32);
    core_robin__DOT__dataPath__DOT__rdData = VL_RAND_RESET_I(32);
    core_robin__DOT__dataPath__DOT__rs2_ALU = VL_RAND_RESET_I(32);
    core_robin__DOT__dataPath__DOT__cpuALU__DOT__ALUoutput = VL_RAND_RESET_I(32);
    core_robin__DOT__dataPath__DOT__cpuALU__DOT__EQUAL = VL_RAND_RESET_I(1);
    core_robin__DOT__dataPath__DOT__cpuALU__DOT__LESS_THAN = VL_RAND_RESET_I(1);
    core_robin__DOT__dataPath__DOT__cpuALU__DOT__SIGNED_LESS_THAN = VL_RAND_RESET_I(1);
    core_robin__DOT__dataPath__DOT__cpuALU__DOT___T_3 = VL_RAND_RESET_I(32);
    core_robin__DOT__dataPath__DOT__cpuALU__DOT___T_7 = VL_RAND_RESET_I(32);
    core_robin__DOT__dataPath__DOT__cpuALU__DOT___GEN_4 = VL_RAND_RESET_I(32);
    core_robin__DOT__dataPath__DOT__cpuALU__DOT___GEN_7 = VL_RAND_RESET_Q(63);
    core_robin__DOT__dataPath__DOT__cpuALU__DOT___GEN_11 = VL_RAND_RESET_Q(63);
    core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_0 = VL_RAND_RESET_I(32);
    core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_1 = VL_RAND_RESET_I(32);
    core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_2 = VL_RAND_RESET_I(32);
    core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_3 = VL_RAND_RESET_I(32);
    core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_4 = VL_RAND_RESET_I(32);
    core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_5 = VL_RAND_RESET_I(32);
    core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_6 = VL_RAND_RESET_I(32);
    core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_7 = VL_RAND_RESET_I(32);
    core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_8 = VL_RAND_RESET_I(32);
    core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_9 = VL_RAND_RESET_I(32);
    core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_10 = VL_RAND_RESET_I(32);
    core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_11 = VL_RAND_RESET_I(32);
    core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_12 = VL_RAND_RESET_I(32);
    core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_13 = VL_RAND_RESET_I(32);
    core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_14 = VL_RAND_RESET_I(32);
    core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_15 = VL_RAND_RESET_I(32);
    core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_16 = VL_RAND_RESET_I(32);
    core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_17 = VL_RAND_RESET_I(32);
    core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_18 = VL_RAND_RESET_I(32);
    core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_19 = VL_RAND_RESET_I(32);
    core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_20 = VL_RAND_RESET_I(32);
    core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_21 = VL_RAND_RESET_I(32);
    core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_22 = VL_RAND_RESET_I(32);
    core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_23 = VL_RAND_RESET_I(32);
    core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_24 = VL_RAND_RESET_I(32);
    core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_25 = VL_RAND_RESET_I(32);
    core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_26 = VL_RAND_RESET_I(32);
    core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_27 = VL_RAND_RESET_I(32);
    core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_28 = VL_RAND_RESET_I(32);
    core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_29 = VL_RAND_RESET_I(32);
    core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_30 = VL_RAND_RESET_I(32);
    core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_31 = VL_RAND_RESET_I(32);
    core_robin__DOT__dataPath__DOT__registerFile__DOT___GEN_21 = VL_RAND_RESET_I(32);
    core_robin__DOT__dataPath__DOT__registerFile__DOT___GEN_54 = VL_RAND_RESET_I(32);
    core_robin__DOT__storeUnit__DOT__store_data_buffer = VL_RAND_RESET_I(32);
    core_robin__DOT__storeUnit__DOT__store_data_size_buffer = VL_RAND_RESET_I(2);
    core_robin__DOT__storeUnit__DOT__store_data_buffer_address = VL_RAND_RESET_I(32);
    core_robin__DOT__storeUnit__DOT__storing = VL_RAND_RESET_I(1);
    core_robin__DOT__storeUnit__DOT__stateReg = VL_RAND_RESET_I(1);
    core_robin__DOT__storeUnit__DOT___T = VL_RAND_RESET_I(1);
    core_robin__DOT__storeUnit__DOT___GEN_4 = VL_RAND_RESET_I(32);
    core_robin__DOT__storeUnit__DOT___GEN_9 = VL_RAND_RESET_I(1);
    core_robin__DOT__storeUnit__DOT___GEN_11 = VL_RAND_RESET_I(2);
    core_robin__DOT__storeUnit__DOT___GEN_14 = VL_RAND_RESET_I(1);
    core_robin__DOT__storeUnit__DOT___T_10 = VL_RAND_RESET_I(25);
    core_robin__DOT__storeUnit__DOT___T_12 = VL_RAND_RESET_I(32);
    core_robin__DOT__storeUnit__DOT___T_15 = VL_RAND_RESET_I(2);
    __Vm_traceActivity = 0;
}
