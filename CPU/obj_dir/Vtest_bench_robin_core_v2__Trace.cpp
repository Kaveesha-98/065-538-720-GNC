// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtest_bench_robin_core_v2__Syms.h"


//======================

void Vtest_bench_robin_core_v2::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vtest_bench_robin_core_v2* t = (Vtest_bench_robin_core_v2*)userthis;
    Vtest_bench_robin_core_v2__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
        t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void Vtest_bench_robin_core_v2::traceChgThis(Vtest_bench_robin_core_v2__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtest_bench_robin_core_v2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 1U))))) {
            vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 2U))))) {
            vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((2U & vlTOPp->__Vm_traceActivity))) {
            vlTOPp->traceChgThis__4(vlSymsp, vcdp, code);
        }
        vlTOPp->traceChgThis__5(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vtest_bench_robin_core_v2::traceChgThis__2(Vtest_bench_robin_core_v2__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtest_bench_robin_core_v2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+1,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit_io_load_mem_address_out),32);
        vcdp->chgBus(c+9,(vlTOPp->test_bench_robin_core_v2__DOT__memoryInstruction_io_rdData),32);
        vcdp->chgBus(c+17,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit_io_mem_write_data),8);
        vcdp->chgBus(c+25,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit_io_mem_write_address),32);
        vcdp->chgBus(c+33,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1),5);
        vcdp->chgBus(c+41,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2),5);
        vcdp->chgBus(c+49,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD),5);
        vcdp->chgBit(c+57,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_WRITE_EN));
        vcdp->chgBus(c+65,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_ALU_OP),4);
        vcdp->chgBit(c+73,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_PROCEDURE_BRANCHING));
        vcdp->chgBit(c+81,(((0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                            & ((1U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                               & ((2U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                                  & ((3U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                                     & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___GEN_36)))))));
        vcdp->chgBus(c+89,(((0U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                             ? 0U : ((1U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                                      ? ((0x37U == 
                                          (0x7fU & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction))
                                          ? (0xfffff000U 
                                             & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction)
                                          : ((0xfffff000U 
                                              & (VL_NEGATE_I((IData)(
                                                                     (1U 
                                                                      & ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___T_18) 
                                                                         >> 0xbU)))) 
                                                 << 0xcU)) 
                                             | (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___T_18)))
                                      : 0U))),32);
        vcdp->chgBus(c+97,(((0U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                             ? 0U : ((1U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                                      ? 0U : ((2U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                                               ? 0U
                                               : ((3U 
                                                   == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                                                   ? 
                                                  ((0x63U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction))
                                                    ? 
                                                   ((0x80000000U 
                                                     & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction)
                                                     ? 
                                                    (0xffffe000U 
                                                     | (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___T_65))
                                                     : (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___T_65))
                                                    : 
                                                   ((0x80000000U 
                                                     & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction)
                                                     ? 
                                                    (0xffe00000U 
                                                     | vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___T_66)
                                                     : vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___T_66))
                                                   : 0U))))),32);
        vcdp->chgBit(c+105,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_DATA_IN));
        vcdp->chgBit(c+113,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_STORE_ADDRESS_IN));
        vcdp->chgBit(c+121,((1U & ((~ (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__stateReg)) 
                                   & (~ (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_LOAD_ADDRESS_IN))))));
        vcdp->chgBus(c+129,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_LOAD_SIZE),2);
        vcdp->chgBit(c+137,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_LOAD_ADDRESS_IN));
        vcdp->chgBus(c+145,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_BRANCH_SELECT),2);
        vcdp->chgBit(c+153,(((0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                             & ((1U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                                & ((2U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                                    ? (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___GEN_15)
                                    : ((3U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                                       & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___GEN_15)))))));
        vcdp->chgBit(c+161,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_UPDATE_PC));
        vcdp->chgBus(c+169,(((0U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                              ? 0U : (((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2) 
                                       == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD))
                                       ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__rdData
                                       : vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__rs2_ALU))),32);
        vcdp->chgBus(c+177,((vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__PC 
                             + ((0U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                                 ? 0U : ((1U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                                          ? 0U : ((2U 
                                                   == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                                                   ? 0U
                                                   : 
                                                  ((3U 
                                                    == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                                                    ? 
                                                   ((0x63U 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction))
                                                     ? 
                                                    ((0x80000000U 
                                                      & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction)
                                                      ? 
                                                     (0xffffe000U 
                                                      | (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___T_65))
                                                      : (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___T_65))
                                                     : 
                                                    ((0x80000000U 
                                                      & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction)
                                                      ? 
                                                     (0xffe00000U 
                                                      | vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___T_66)
                                                      : vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___T_66))
                                                    : 0U)))))),32);
        vcdp->chgBit(c+185,(((2U & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_BRANCH_SELECT))
                              ? (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT__LESS_THAN)
                              : (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT__SIGNED_LESS_THAN))));
        vcdp->chgBit(c+193,(((1U & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_BRANCH_SELECT))
                              ? ((2U & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_BRANCH_SELECT))
                                  ? (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT__LESS_THAN)
                                  : (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT__SIGNED_LESS_THAN))
                              : (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT__EQUAL))));
        vcdp->chgBit(c+201,((1U & ((~ (((1U & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_BRANCH_SELECT))
                                         ? ((2U & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_BRANCH_SELECT))
                                             ? (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT__LESS_THAN)
                                             : (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT__SIGNED_LESS_THAN))
                                         : (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT__EQUAL)) 
                                       ^ ((0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                                          & ((1U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                                             & ((2U 
                                                 != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                                                & ((3U 
                                                    == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                                                   & ((0x63U 
                                                       == 
                                                       (0x7fU 
                                                        & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction)) 
                                                      & (~ 
                                                         (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                                          >> 0xcU))))))))) 
                                   & (((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_BRANCH_SELECT) 
                                       >> 1U) | (~ (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_BRANCH_SELECT)))))));
        vcdp->chgBus(c+209,(((0U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                              ? 0U : ((0x1fU == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                       ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_31
                                       : ((0x1eU == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                           ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_30
                                           : ((0x1dU 
                                               == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                               ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_29
                                               : ((0x1cU 
                                                   == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                                   ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_28
                                                   : 
                                                  ((0x1bU 
                                                    == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                                    ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_27
                                                    : 
                                                   ((0x1aU 
                                                     == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                                     ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_26
                                                     : 
                                                    ((0x19U 
                                                      == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                                      ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_25
                                                      : 
                                                     ((0x18U 
                                                       == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                                       ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_24
                                                       : 
                                                      ((0x17U 
                                                        == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                                        ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_23
                                                        : 
                                                       ((0x16U 
                                                         == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                                         ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_22
                                                         : vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT___GEN_21)))))))))))),32);
        vcdp->chgBus(c+217,(((0U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                              ? 0U : ((0x1fU == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                       ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_31
                                       : ((0x1eU == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                           ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_30
                                           : ((0x1dU 
                                               == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                               ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_29
                                               : ((0x1cU 
                                                   == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                                   ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_28
                                                   : 
                                                  ((0x1bU 
                                                    == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                                    ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_27
                                                    : 
                                                   ((0x1aU 
                                                     == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                                     ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_26
                                                     : 
                                                    ((0x19U 
                                                      == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                                      ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_25
                                                      : 
                                                     ((0x18U 
                                                       == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                                       ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_24
                                                       : 
                                                      ((0x17U 
                                                        == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                                        ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_23
                                                        : 
                                                       ((0x16U 
                                                         == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                                         ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_22
                                                         : vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT___GEN_54)))))))))))),32);
        vcdp->chgBus(c+225,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile_io_rdData),32);
        vcdp->chgBus(c+233,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__rdData),32);
        vcdp->chgBus(c+241,(((0U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                              ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT__ALUoutput
                              : ((0U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                  ? 0U : ((0x1fU == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                           ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_31
                                           : ((0x1eU 
                                               == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                               ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_30
                                               : ((0x1dU 
                                                   == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                                   ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_29
                                                   : 
                                                  ((0x1cU 
                                                    == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                                    ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_28
                                                    : 
                                                   ((0x1bU 
                                                     == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                                     ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_27
                                                     : 
                                                    ((0x1aU 
                                                      == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                                      ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_26
                                                      : 
                                                     ((0x19U 
                                                       == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                                       ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_25
                                                       : 
                                                      ((0x18U 
                                                        == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                                        ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_24
                                                        : 
                                                       ((0x17U 
                                                         == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                                         ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_23
                                                         : 
                                                        ((0x16U 
                                                          == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                                          ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_22
                                                          : vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT___GEN_21))))))))))))),32);
        vcdp->chgBus(c+249,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__rs2_ALU),32);
        vcdp->chgBus(c+257,((((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2) 
                              == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD))
                              ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__rdData
                              : vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__rs2_ALU)),32);
    }
}

void Vtest_bench_robin_core_v2::traceChgThis__3(Vtest_bench_robin_core_v2__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtest_bench_robin_core_v2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+265,(vlTOPp->test_bench_robin_core_v2__DOT__memoryData_io_mem_write));
        vcdp->chgBus(c+273,(vlTOPp->test_bench_robin_core_v2__DOT__memoryData_io_mem_write_data),8);
        vcdp->chgBus(c+281,(vlTOPp->test_bench_robin_core_v2__DOT__memoryData_io_mem_write_address),32);
        vcdp->chgBus(c+289,((0x3ffU & vlTOPp->test_bench_robin_core_v2__DOT__memoryData_io_mem_write_address)),10);
    }
}

void Vtest_bench_robin_core_v2::traceChgThis__4(Vtest_bench_robin_core_v2__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtest_bench_robin_core_v2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+297,(((IData)(vlTOPp->test_bench_robin_core_v2__DOT__memoryData__DOT__doForwardReg)
                              ? (IData)(vlTOPp->test_bench_robin_core_v2__DOT__memoryData__DOT__wrDataReg)
                              : vlTOPp->test_bench_robin_core_v2__DOT__memoryData__DOT__mem
                             [vlTOPp->test_bench_robin_core_v2__DOT__memoryData__DOT__mem_memData_addr_pipe_0])),8);
        vcdp->chgBus(c+305,((0x3fffffffU & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__PC 
                                            >> 2U))),32);
        vcdp->chgBit(c+313,(vlTOPp->test_bench_robin_core_v2__DOT__PROGRAM_LOADED));
        vcdp->chgBus(c+321,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__PC),32);
        vcdp->chgBit(c+329,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__storing));
        vcdp->chgBus(c+337,((0x3fffffffU & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__PC 
                                            >> 2U))),30);
        vcdp->chgBus(c+345,(vlTOPp->test_bench_robin_core_v2__DOT__memoryData__DOT__mem
                            [vlTOPp->test_bench_robin_core_v2__DOT__memoryData__DOT__mem_memData_addr_pipe_0]),8);
        vcdp->chgBus(c+353,(vlTOPp->test_bench_robin_core_v2__DOT__memoryData__DOT__mem_memData_addr_pipe_0),10);
        vcdp->chgBus(c+361,(vlTOPp->test_bench_robin_core_v2__DOT__memoryData__DOT__wrDataReg),8);
        vcdp->chgBit(c+369,(vlTOPp->test_bench_robin_core_v2__DOT__memoryData__DOT__doForwardReg));
        vcdp->chgBus(c+377,(vlTOPp->test_bench_robin_core_v2__DOT__memoryInstruction__DOT__mem
                            [vlTOPp->test_bench_robin_core_v2__DOT__memoryInstruction__DOT__mem_memData_addr_pipe_0]),32);
        vcdp->chgBus(c+385,(vlTOPp->test_bench_robin_core_v2__DOT__memoryInstruction__DOT__mem_memData_addr_pipe_0),10);
        vcdp->chgBus(c+393,(vlTOPp->test_bench_robin_core_v2__DOT__memoryInstruction__DOT__wrDataReg),32);
        vcdp->chgBit(c+401,(vlTOPp->test_bench_robin_core_v2__DOT__memoryInstruction__DOT__doForwardReg));
        vcdp->chgBit(c+409,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__INSTRUCTION_LOADED));
        vcdp->chgBit(c+417,(((0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                             & ((1U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                                & (~ ((0x33U == (0x7fU 
                                                 & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction)) 
                                      | (0x63U == (0x7fU 
                                                   & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction))))))));
        vcdp->chgBit(c+425,((1U & (~ (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__stateReg)))));
        vcdp->chgBus(c+433,(((0U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                              ? 1U : ((1U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                                       ? ((0x23U == 
                                           (0x7fU & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction))
                                           ? ((0x2000U 
                                               & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction)
                                               ? 0U
                                               : (3U 
                                                  & (~ 
                                                     (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                                      >> 0xcU))))
                                           : 1U) : 1U))),2);
        vcdp->chgBit(c+441,(((0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                             & ((1U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                                & ((2U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                                   & ((3U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                                      & (~ (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                            >> 0xeU))))))));
        vcdp->chgBit(c+449,(((0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                             & ((1U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                                & ((2U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                                   & ((3U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                                      & ((0x63U == 
                                          (0x7fU & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction)) 
                                         & (~ (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                               >> 0xcU)))))))));
        vcdp->chgBit(c+457,(((0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                             & ((1U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                                & (0x17U == (0x7fU 
                                             & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction))))));
        vcdp->chgBit(c+465,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT__EQUAL));
        vcdp->chgBit(c+473,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT__LESS_THAN));
        vcdp->chgBit(c+481,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT__SIGNED_LESS_THAN));
        vcdp->chgBus(c+489,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT__ALUoutput),32);
        vcdp->chgBus(c+497,(((0xffffff00U & ((0xffffff00U 
                                              & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_buffer) 
                                             | (((((1U 
                                                    & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__LOAD_SIZE))
                                                    ? 
                                                   (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_buffer 
                                                    >> 7U)
                                                    : 
                                                   (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_buffer 
                                                    >> 0xfU)) 
                                                  & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__EXTENSION))
                                                  ? 
                                                 ((((2U 
                                                     & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__LOAD_SIZE))
                                                     ? 0xffffU
                                                     : 0U) 
                                                   << 8U) 
                                                  | ((3U 
                                                      == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__LOAD_SIZE))
                                                      ? 0xffU
                                                      : 0U))
                                                  : 0U) 
                                                << 8U))) 
                             | (0xffU & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_buffer))),32);
        vcdp->chgBus(c+505,(((IData)(4U) + vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__PC)),32);
        vcdp->chgBit(c+513,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__PROGRAM_LOADED));
        vcdp->chgBus(c+521,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg),3);
        vcdp->chgBus(c+529,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stallState),3);
        vcdp->chgBus(c+537,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction),32);
        vcdp->chgBit(c+545,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__STORE_READY));
        vcdp->chgBit(c+553,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__LOAD_READY));
        vcdp->chgBus(c+561,((0x7fU & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                      >> 0x19U))),7);
        vcdp->chgBus(c+569,((0x1fU & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                      >> 7U))),5);
        vcdp->chgBit(c+577,(((1U == (3U & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                           >> 0xcU))) 
                             & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                >> 0x1eU))));
        vcdp->chgBus(c+585,((7U & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                   >> 0xcU))),3);
        vcdp->chgBit(c+593,((1U & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                   >> 0x1fU))));
        vcdp->chgBit(c+601,((1U & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                   >> 7U))));
        vcdp->chgBus(c+609,((0x3fU & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                      >> 0x19U))),6);
        vcdp->chgBus(c+617,((0xfU & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                     >> 8U))),4);
        vcdp->chgBus(c+625,((0xffU & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                      >> 0xcU))),8);
        vcdp->chgBit(c+633,((1U & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                   >> 0x14U))));
        vcdp->chgBus(c+641,((0x3ffU & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                       >> 0x15U))),10);
        vcdp->chgBus(c+649,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__ALU_in1),32);
        vcdp->chgBus(c+657,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__ALU_in2),32);
        vcdp->chgBus(c+665,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_0),32);
        vcdp->chgBus(c+673,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_1),32);
        vcdp->chgBus(c+681,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_2),32);
        vcdp->chgBus(c+689,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_3),32);
        vcdp->chgBus(c+697,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_4),32);
        vcdp->chgBus(c+705,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_5),32);
        vcdp->chgBus(c+713,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_6),32);
        vcdp->chgBus(c+721,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_7),32);
        vcdp->chgBus(c+729,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_8),32);
        vcdp->chgBus(c+737,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_9),32);
        vcdp->chgBus(c+745,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_10),32);
        vcdp->chgBus(c+753,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_11),32);
        vcdp->chgBus(c+761,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_12),32);
        vcdp->chgBus(c+769,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_13),32);
        vcdp->chgBus(c+777,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_14),32);
        vcdp->chgBus(c+785,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_15),32);
        vcdp->chgBus(c+793,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_16),32);
        vcdp->chgBus(c+801,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_17),32);
        vcdp->chgBus(c+809,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_18),32);
        vcdp->chgBus(c+817,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_19),32);
        vcdp->chgBus(c+825,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_20),32);
        vcdp->chgBus(c+833,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_21),32);
        vcdp->chgBus(c+841,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_22),32);
        vcdp->chgBus(c+849,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_23),32);
        vcdp->chgBus(c+857,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_24),32);
        vcdp->chgBus(c+865,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_25),32);
        vcdp->chgBus(c+873,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_26),32);
        vcdp->chgBus(c+881,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_27),32);
        vcdp->chgBus(c+889,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_28),32);
        vcdp->chgBus(c+897,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_29),32);
        vcdp->chgBus(c+905,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_30),32);
        vcdp->chgBus(c+913,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_31),32);
        vcdp->chgBus(c+921,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__store_data_buffer),32);
        vcdp->chgBus(c+929,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__store_data_size_buffer),2);
        vcdp->chgBus(c+937,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__store_data_buffer_address),32);
        vcdp->chgBit(c+945,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__stateReg));
        vcdp->chgBus(c+953,((0xffffffU & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__store_data_buffer 
                                          >> 8U))),24);
        vcdp->chgBus(c+961,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_buffer),32);
        vcdp->chgBus(c+969,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_size_buffer),2);
        vcdp->chgBus(c+977,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_address_buffer),32);
        vcdp->chgBus(c+985,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__LOAD_SIZE),2);
        vcdp->chgBit(c+993,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__EXTENSION));
        vcdp->chgBit(c+1001,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__stateReg));
        vcdp->chgBit(c+1009,((1U & ((1U & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__LOAD_SIZE))
                                     ? (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_buffer 
                                        >> 7U) : (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_buffer 
                                                  >> 0xfU)))));
        vcdp->chgBit(c+1017,((((1U & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__LOAD_SIZE))
                                ? (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_buffer 
                                   >> 7U) : (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_buffer 
                                             >> 0xfU)) 
                              & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__EXTENSION))));
        vcdp->chgBus(c+1025,(((2U & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__LOAD_SIZE))
                               ? 0xffffU : 0U)),16);
        vcdp->chgBus(c+1033,(((3U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__LOAD_SIZE))
                               ? 0xffU : 0U)),8);
        vcdp->chgBus(c+1041,(((((2U & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__LOAD_SIZE))
                                 ? 0xffffU : 0U) << 8U) 
                              | ((3U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__LOAD_SIZE))
                                  ? 0xffU : 0U))),24);
        vcdp->chgBus(c+1049,(((((1U & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__LOAD_SIZE))
                                 ? (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_buffer 
                                    >> 7U) : (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_buffer 
                                              >> 0xfU)) 
                               & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__EXTENSION))
                               ? ((((2U & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__LOAD_SIZE))
                                     ? 0xffffU : 0U) 
                                   << 8U) | ((3U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__LOAD_SIZE))
                                              ? 0xffU
                                              : 0U))
                               : 0U)),24);
        vcdp->chgBus(c+1057,((0xffffffU & ((vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_buffer 
                                            >> 8U) 
                                           | ((((1U 
                                                 & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__LOAD_SIZE))
                                                 ? 
                                                (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_buffer 
                                                 >> 7U)
                                                 : 
                                                (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_buffer 
                                                 >> 0xfU)) 
                                               & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__EXTENSION))
                                               ? ((
                                                   ((2U 
                                                     & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__LOAD_SIZE))
                                                     ? 0xffffU
                                                     : 0U) 
                                                   << 8U) 
                                                  | ((3U 
                                                      == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__LOAD_SIZE))
                                                      ? 0xffU
                                                      : 0U))
                                               : 0U)))),24);
        vcdp->chgBus(c+1065,((0xffU & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_buffer)),8);
        vcdp->chgBus(c+1073,((0xffffffU & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_buffer)),24);
    }
}

void Vtest_bench_robin_core_v2::traceChgThis__5(Vtest_bench_robin_core_v2__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtest_bench_robin_core_v2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+1081,(vlTOPp->clock));
        vcdp->chgBit(c+1089,(vlTOPp->reset));
        vcdp->chgBit(c+1097,(vlTOPp->io_signal_mem_write_data));
        vcdp->chgBus(c+1105,(vlTOPp->io_mem_write_data),8);
        vcdp->chgBus(c+1113,(vlTOPp->io_mem_write_address_data),32);
        vcdp->chgBit(c+1121,(vlTOPp->io_signal_mem_write_instruction));
        vcdp->chgBus(c+1129,(vlTOPp->io_mem_write_instruction),32);
        vcdp->chgBus(c+1137,(vlTOPp->io_mem_write_address_instruction),32);
        vcdp->chgBit(c+1145,(vlTOPp->io_START_PROGRAM));
        vcdp->chgBit(c+1153,(vlTOPp->io_outputSake));
        vcdp->chgBit(c+1161,(vlTOPp->io_out_mem_write));
        vcdp->chgBus(c+1169,(vlTOPp->io_out_mem_write_data),8);
        vcdp->chgBus(c+1177,(vlTOPp->io_out_mem_write_address),32);
        vcdp->chgBus(c+1185,(vlTOPp->io_INSTRUCTION),32);
        vcdp->chgBus(c+1193,(vlTOPp->io_PC),32);
        vcdp->chgBus(c+1201,((0x3ffU & vlTOPp->io_mem_write_address_instruction)),10);
    }
}
