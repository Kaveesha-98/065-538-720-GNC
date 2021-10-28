// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vcore_robin__Syms.h"


//======================

void Vcore_robin::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vcore_robin* t = (Vcore_robin*)userthis;
    Vcore_robin__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
        t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void Vcore_robin::traceChgThis(Vcore_robin__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vcore_robin* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 1U))))) {
            vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((1U & ((vlTOPp->__Vm_traceActivity 
                                | (vlTOPp->__Vm_traceActivity 
                                   >> 1U)) | (vlTOPp->__Vm_traceActivity 
                                              >> 2U))))) {
            vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 2U))))) {
            vlTOPp->traceChgThis__4(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((2U & vlTOPp->__Vm_traceActivity))) {
            vlTOPp->traceChgThis__5(vlSymsp, vcdp, code);
        }
        vlTOPp->traceChgThis__6(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vcore_robin::traceChgThis__2(Vcore_robin__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vcore_robin* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+1,(vlTOPp->core_robin__DOT__controlStore_io_RS2),5);
        vcdp->chgBus(c+9,(vlTOPp->core_robin__DOT__controlStore_io_RD),5);
        vcdp->chgBit(c+17,(vlTOPp->core_robin__DOT__controlStore_io_WRITE_EN));
        vcdp->chgBus(c+25,(vlTOPp->core_robin__DOT__controlStore_io_ALU_OP),4);
        vcdp->chgBit(c+33,(vlTOPp->core_robin__DOT__controlStore_io_PROCEDURE_BRANCHING));
        vcdp->chgBit(c+41,(((0U != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                            & ((1U != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                               & ((2U != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                                  & ((3U != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                                     & (IData)(vlTOPp->core_robin__DOT__controlStore__DOT___GEN_34)))))));
        vcdp->chgBus(c+49,(((0U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                             ? 0U : ((1U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                                      ? ((0x37U == 
                                          (0x7fU & vlTOPp->core_robin__DOT__controlStore__DOT__instruction))
                                          ? (0xfffff000U 
                                             & vlTOPp->core_robin__DOT__controlStore__DOT__instruction)
                                          : ((0xfffff000U 
                                              & (VL_NEGATE_I((IData)(
                                                                     (1U 
                                                                      & ((IData)(vlTOPp->core_robin__DOT__controlStore__DOT___T_18) 
                                                                         >> 0xbU)))) 
                                                 << 0xcU)) 
                                             | (IData)(vlTOPp->core_robin__DOT__controlStore__DOT___T_18)))
                                      : 0U))),32);
        vcdp->chgBus(c+57,(((0U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                             ? 0U : ((1U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                                      ? 0U : ((2U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                                               ? ((0x63U 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->core_robin__DOT__controlStore__DOT__instruction))
                                                   ? 
                                                  ((0x80000000U 
                                                    & vlTOPp->core_robin__DOT__controlStore__DOT__instruction)
                                                    ? 
                                                   (0xffffe000U 
                                                    | (IData)(vlTOPp->core_robin__DOT__controlStore__DOT___T_55))
                                                    : (IData)(vlTOPp->core_robin__DOT__controlStore__DOT___T_55))
                                                   : 
                                                  ((0x80000000U 
                                                    & vlTOPp->core_robin__DOT__controlStore__DOT__instruction)
                                                    ? 
                                                   (0xffe00000U 
                                                    | vlTOPp->core_robin__DOT__controlStore__DOT___T_56)
                                                    : vlTOPp->core_robin__DOT__controlStore__DOT___T_56))
                                               : 0U)))),32);
        vcdp->chgBit(c+65,(vlTOPp->core_robin__DOT__controlStore_io_DATA_IN));
        vcdp->chgBit(c+73,(vlTOPp->core_robin__DOT__controlStore_io_STORE_ADDRESS_IN));
        vcdp->chgBus(c+81,(vlTOPp->core_robin__DOT__controlStore_io_BRANCH_SELECT),2);
        vcdp->chgBus(c+89,(((0U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                             ? 0U : (((IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2) 
                                      == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD))
                                      ? vlTOPp->core_robin__DOT__dataPath__DOT__rdData
                                      : vlTOPp->core_robin__DOT__dataPath__DOT__rs2_ALU))),32);
        vcdp->chgBus(c+97,((vlTOPp->core_robin__DOT__PC 
                            + ((0U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                                ? 0U : ((1U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                                         ? 0U : ((2U 
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
                                                    | (IData)(vlTOPp->core_robin__DOT__controlStore__DOT___T_55))
                                                    : (IData)(vlTOPp->core_robin__DOT__controlStore__DOT___T_55))
                                                   : 
                                                  ((0x80000000U 
                                                    & vlTOPp->core_robin__DOT__controlStore__DOT__instruction)
                                                    ? 
                                                   (0xffe00000U 
                                                    | vlTOPp->core_robin__DOT__controlStore__DOT___T_56)
                                                    : vlTOPp->core_robin__DOT__controlStore__DOT___T_56))
                                                  : 0U))))),32);
        vcdp->chgBit(c+105,(((2U & (IData)(vlTOPp->core_robin__DOT__controlStore_io_BRANCH_SELECT))
                              ? (IData)(vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT__LESS_THAN)
                              : (IData)(vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT__SIGNED_LESS_THAN))));
        vcdp->chgBit(c+113,(((1U & (IData)(vlTOPp->core_robin__DOT__controlStore_io_BRANCH_SELECT))
                              ? ((2U & (IData)(vlTOPp->core_robin__DOT__controlStore_io_BRANCH_SELECT))
                                  ? (IData)(vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT__LESS_THAN)
                                  : (IData)(vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT__SIGNED_LESS_THAN))
                              : (IData)(vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT__EQUAL))));
        vcdp->chgBit(c+121,(((((1U & (IData)(vlTOPp->core_robin__DOT__controlStore_io_BRANCH_SELECT))
                                ? ((2U & (IData)(vlTOPp->core_robin__DOT__controlStore_io_BRANCH_SELECT))
                                    ? (IData)(vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT__LESS_THAN)
                                    : (IData)(vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT__SIGNED_LESS_THAN))
                                : (IData)(vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT__EQUAL)) 
                              & ((0U != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                                 & ((1U != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                                    & ((2U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                                       & ((0x63U == 
                                           (0x7fU & vlTOPp->core_robin__DOT__controlStore__DOT__instruction)) 
                                          & (~ (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                                >> 0xcU))))))) 
                             & (((IData)(vlTOPp->core_robin__DOT__controlStore_io_BRANCH_SELECT) 
                                 >> 1U) & (~ (IData)(vlTOPp->core_robin__DOT__controlStore_io_BRANCH_SELECT))))));
        vcdp->chgBus(c+129,(((0U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                              ? 0U : ((0x1fU == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                       ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_31
                                       : ((0x1eU == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                           ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_30
                                           : ((0x1dU 
                                               == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                               ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_29
                                               : ((0x1cU 
                                                   == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                                   ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_28
                                                   : 
                                                  ((0x1bU 
                                                    == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                                    ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_27
                                                    : 
                                                   ((0x1aU 
                                                     == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                                     ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_26
                                                     : 
                                                    ((0x19U 
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
                                                         : vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT___GEN_54)))))))))))),32);
        vcdp->chgBus(c+137,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile_io_rdData),32);
        vcdp->chgBus(c+145,(vlTOPp->core_robin__DOT__dataPath__DOT__rdData),32);
        vcdp->chgBus(c+153,(vlTOPp->core_robin__DOT__dataPath__DOT__rs2_ALU),32);
        vcdp->chgBus(c+161,((((IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2) 
                              == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD))
                              ? vlTOPp->core_robin__DOT__dataPath__DOT__rdData
                              : vlTOPp->core_robin__DOT__dataPath__DOT__rs2_ALU)),32);
    }
}

void Vcore_robin::traceChgThis__3(Vcore_robin__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vcore_robin* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+169,(((0U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                              ? 0U : ((0x1fU == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                       ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_31
                                       : ((0x1eU == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                           ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_30
                                           : ((0x1dU 
                                               == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                               ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_29
                                               : ((0x1cU 
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
                                                         : vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT___GEN_21)))))))))))),32);
        vcdp->chgBus(c+177,(((0U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                              ? vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT__ALUoutput
                              : ((0U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                  ? 0U : ((0x1fU == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                           ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_31
                                           : ((0x1eU 
                                               == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                               ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_30
                                               : ((0x1dU 
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
                                                          : vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT___GEN_21))))))))))))),32);
    }
}

void Vcore_robin::traceChgThis__4(Vcore_robin__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vcore_robin* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+185,(vlTOPp->core_robin__DOT__controlStore_io_RS1),5);
    }
}

void Vcore_robin::traceChgThis__5(Vcore_robin__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vcore_robin* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+193,(vlTOPp->core_robin__DOT__controlStore__DOT__RECIEVED));
        vcdp->chgBit(c+201,(((0U != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                             & ((1U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                                & (~ ((0x33U == (0x7fU 
                                                 & vlTOPp->core_robin__DOT__controlStore__DOT__instruction)) 
                                      | (0x63U == (0x7fU 
                                                   & vlTOPp->core_robin__DOT__controlStore__DOT__instruction))))))));
        vcdp->chgBit(c+209,((1U & (~ (IData)(vlTOPp->core_robin__DOT__storeUnit__DOT__stateReg)))));
        vcdp->chgBus(c+217,(((0U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                              ? 1U : ((1U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                                       ? ((0x23U == 
                                           (0x7fU & vlTOPp->core_robin__DOT__controlStore__DOT__instruction))
                                           ? ((0x2000U 
                                               & vlTOPp->core_robin__DOT__controlStore__DOT__instruction)
                                               ? 0U
                                               : (3U 
                                                  & (~ 
                                                     (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                                      >> 0xcU))))
                                           : 1U) : 1U))),2);
        vcdp->chgBit(c+225,(((0U != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                             & ((1U != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                                & ((2U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                                   & ((0x63U == (0x7fU 
                                                 & vlTOPp->core_robin__DOT__controlStore__DOT__instruction)) 
                                      & (~ (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                            >> 0xcU))))))));
        vcdp->chgBit(c+233,(((0U != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                             & ((1U != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                                & ((2U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                                   & ((0x67U == (0x77U 
                                                 & vlTOPp->core_robin__DOT__controlStore__DOT__instruction)) 
                                      & (0x67U == (0x7fU 
                                                   & vlTOPp->core_robin__DOT__controlStore__DOT__instruction))))))));
        vcdp->chgBit(c+241,(((0U != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                             & ((1U != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                                & (2U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))))));
        vcdp->chgBit(c+249,(((0U != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                             & ((1U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                                & (0x17U == (0x7fU 
                                             & vlTOPp->core_robin__DOT__controlStore__DOT__instruction))))));
        vcdp->chgBit(c+257,(vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT__EQUAL));
        vcdp->chgBit(c+265,(vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT__LESS_THAN));
        vcdp->chgBit(c+273,(vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT__SIGNED_LESS_THAN));
        vcdp->chgBus(c+281,(vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT__ALUoutput),32);
        vcdp->chgBus(c+289,(((IData)(4U) + vlTOPp->core_robin__DOT__PC)),32);
        vcdp->chgBus(c+297,(vlTOPp->core_robin__DOT__PC),32);
        vcdp->chgBus(c+305,(((IData)(vlTOPp->core_robin__DOT__storeUnit__DOT__storing)
                              ? (0xffU & vlTOPp->core_robin__DOT__storeUnit__DOT__store_data_buffer)
                              : 0U)),8);
        vcdp->chgBus(c+313,(((IData)(vlTOPp->core_robin__DOT__storeUnit__DOT__storing)
                              ? vlTOPp->core_robin__DOT__storeUnit__DOT__store_data_buffer_address
                              : 0U)),32);
        vcdp->chgBit(c+321,(vlTOPp->core_robin__DOT__storeUnit__DOT__storing));
        vcdp->chgBus(c+329,(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg),3);
        vcdp->chgBus(c+337,(vlTOPp->core_robin__DOT__controlStore__DOT__stallState),3);
        vcdp->chgBus(c+345,(vlTOPp->core_robin__DOT__controlStore__DOT__instruction),32);
        vcdp->chgBit(c+353,(vlTOPp->core_robin__DOT__controlStore__DOT__STORE_READY));
        vcdp->chgBit(c+361,(vlTOPp->core_robin__DOT__controlStore__DOT__LOAD_READY));
        vcdp->chgBus(c+369,((0x7fU & (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                      >> 0x19U))),7);
        vcdp->chgBus(c+377,((0x1fU & (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                      >> 7U))),5);
        vcdp->chgBit(c+385,(((1U == (3U & (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                           >> 0xcU))) 
                             & (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                >> 0x1eU))));
        vcdp->chgBus(c+393,((7U & (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                   >> 0xcU))),3);
        vcdp->chgBit(c+401,((1U & (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                   >> 0x1fU))));
        vcdp->chgBit(c+409,((1U & (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                   >> 7U))));
        vcdp->chgBus(c+417,((0x3fU & (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                      >> 0x19U))),6);
        vcdp->chgBus(c+425,((0xfU & (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                     >> 8U))),4);
        vcdp->chgBus(c+433,((0xffU & (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                      >> 0xcU))),8);
        vcdp->chgBit(c+441,((1U & (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                   >> 0x14U))));
        vcdp->chgBus(c+449,((0x3ffU & (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                       >> 0x15U))),10);
        vcdp->chgBus(c+457,(vlTOPp->core_robin__DOT__dataPath__DOT__ALU_in1),32);
        vcdp->chgBus(c+465,(vlTOPp->core_robin__DOT__dataPath__DOT__ALU_in2),32);
        vcdp->chgBus(c+473,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_0),32);
        vcdp->chgBus(c+481,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_1),32);
        vcdp->chgBus(c+489,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_2),32);
        vcdp->chgBus(c+497,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_3),32);
        vcdp->chgBus(c+505,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_4),32);
        vcdp->chgBus(c+513,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_5),32);
        vcdp->chgBus(c+521,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_6),32);
        vcdp->chgBus(c+529,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_7),32);
        vcdp->chgBus(c+537,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_8),32);
        vcdp->chgBus(c+545,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_9),32);
        vcdp->chgBus(c+553,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_10),32);
        vcdp->chgBus(c+561,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_11),32);
        vcdp->chgBus(c+569,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_12),32);
        vcdp->chgBus(c+577,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_13),32);
        vcdp->chgBus(c+585,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_14),32);
        vcdp->chgBus(c+593,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_15),32);
        vcdp->chgBus(c+601,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_16),32);
        vcdp->chgBus(c+609,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_17),32);
        vcdp->chgBus(c+617,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_18),32);
        vcdp->chgBus(c+625,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_19),32);
        vcdp->chgBus(c+633,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_20),32);
        vcdp->chgBus(c+641,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_21),32);
        vcdp->chgBus(c+649,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_22),32);
        vcdp->chgBus(c+657,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_23),32);
        vcdp->chgBus(c+665,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_24),32);
        vcdp->chgBus(c+673,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_25),32);
        vcdp->chgBus(c+681,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_26),32);
        vcdp->chgBus(c+689,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_27),32);
        vcdp->chgBus(c+697,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_28),32);
        vcdp->chgBus(c+705,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_29),32);
        vcdp->chgBus(c+713,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_30),32);
        vcdp->chgBus(c+721,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_31),32);
        vcdp->chgBus(c+729,(vlTOPp->core_robin__DOT__storeUnit__DOT__store_data_buffer),32);
        vcdp->chgBus(c+737,(vlTOPp->core_robin__DOT__storeUnit__DOT__store_data_size_buffer),2);
        vcdp->chgBus(c+745,(vlTOPp->core_robin__DOT__storeUnit__DOT__store_data_buffer_address),32);
        vcdp->chgBit(c+753,(vlTOPp->core_robin__DOT__storeUnit__DOT__stateReg));
        vcdp->chgBus(c+761,((0xffffffU & (vlTOPp->core_robin__DOT__storeUnit__DOT__store_data_buffer 
                                          >> 8U))),24);
    }
}

void Vcore_robin::traceChgThis__6(Vcore_robin__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vcore_robin* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+769,(vlTOPp->clock));
        vcdp->chgBit(c+777,(vlTOPp->reset));
        vcdp->chgBus(c+785,(vlTOPp->io_INSTRUCTION),32);
        vcdp->chgBit(c+793,(vlTOPp->io_RECIEVED));
        vcdp->chgBit(c+801,(vlTOPp->io_INSTRUCTION_LOADED));
        vcdp->chgBus(c+809,(vlTOPp->io_PC),32);
        vcdp->chgBus(c+817,(vlTOPp->io_rdAddr),32);
        vcdp->chgBus(c+825,(vlTOPp->io_rdData),8);
        vcdp->chgBit(c+833,(vlTOPp->io_mem_write));
        vcdp->chgBus(c+841,(vlTOPp->io_mem_write_data),8);
        vcdp->chgBus(c+849,(vlTOPp->io_mem_write_address),32);
    }
}
