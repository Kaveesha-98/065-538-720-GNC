// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VALU__Syms.h"


//======================

void VALU::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VALU* t = (VALU*)userthis;
    VALU__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
        t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void VALU::traceChgThis(VALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 2U))))) {
            vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((2U & vlTOPp->__Vm_traceActivity))) {
            vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
        }
        vlTOPp->traceChgThis__4(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void VALU::traceChgThis__2(VALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+1,(vlTOPp->data_path__DOT__registerFile_io_rdData),32);
        vcdp->chgBus(c+9,(vlTOPp->data_path__DOT__rdData),32);
        vcdp->chgBus(c+17,(vlTOPp->data_path__DOT__rs2_ALU),32);
    }
}

void VALU::traceChgThis__3(VALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+25,(vlTOPp->data_path__DOT__cpuALU__DOT__EQUAL));
        vcdp->chgBit(c+33,(vlTOPp->data_path__DOT__cpuALU__DOT__LESS_THAN));
        vcdp->chgBit(c+41,(vlTOPp->data_path__DOT__cpuALU__DOT__SIGNED_LESS_THAN));
        vcdp->chgBus(c+49,(vlTOPp->data_path__DOT__ALU_in1),32);
        vcdp->chgBus(c+57,(vlTOPp->data_path__DOT__ALU_in2),32);
        vcdp->chgBus(c+65,(vlTOPp->data_path__DOT__cpuALU__DOT__ALUoutput),32);
        vcdp->chgBus(c+73,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_0),32);
        vcdp->chgBus(c+81,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_1),32);
        vcdp->chgBus(c+89,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_2),32);
        vcdp->chgBus(c+97,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_3),32);
        vcdp->chgBus(c+105,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_4),32);
        vcdp->chgBus(c+113,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_5),32);
        vcdp->chgBus(c+121,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_6),32);
        vcdp->chgBus(c+129,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_7),32);
        vcdp->chgBus(c+137,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_8),32);
        vcdp->chgBus(c+145,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_9),32);
        vcdp->chgBus(c+153,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_10),32);
        vcdp->chgBus(c+161,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_11),32);
        vcdp->chgBus(c+169,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_12),32);
        vcdp->chgBus(c+177,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_13),32);
        vcdp->chgBus(c+185,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_14),32);
        vcdp->chgBus(c+193,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_15),32);
        vcdp->chgBus(c+201,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_16),32);
        vcdp->chgBus(c+209,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_17),32);
        vcdp->chgBus(c+217,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_18),32);
        vcdp->chgBus(c+225,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_19),32);
        vcdp->chgBus(c+233,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_20),32);
        vcdp->chgBus(c+241,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_21),32);
        vcdp->chgBus(c+249,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_22),32);
        vcdp->chgBus(c+257,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_23),32);
        vcdp->chgBus(c+265,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_24),32);
        vcdp->chgBus(c+273,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_25),32);
        vcdp->chgBus(c+281,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_26),32);
        vcdp->chgBus(c+289,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_27),32);
        vcdp->chgBus(c+297,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_28),32);
        vcdp->chgBus(c+305,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_29),32);
        vcdp->chgBus(c+313,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_30),32);
        vcdp->chgBus(c+321,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_31),32);
    }
}

void VALU::traceChgThis__4(VALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+329,(vlTOPp->clock));
        vcdp->chgBit(c+337,(vlTOPp->reset));
        vcdp->chgBus(c+345,(vlTOPp->io_RS1),5);
        vcdp->chgBus(c+353,(vlTOPp->io_RS2),5);
        vcdp->chgBus(c+361,(vlTOPp->io_RD),5);
        vcdp->chgBit(c+369,(vlTOPp->io_WRITE_EN));
        vcdp->chgBus(c+377,(vlTOPp->io_ALU_OP),4);
        vcdp->chgBit(c+385,(vlTOPp->io_EQUAL));
        vcdp->chgBit(c+393,(vlTOPp->io_LESS_THAN));
        vcdp->chgBit(c+401,(vlTOPp->io_SIGNED_LESS_THAN));
        vcdp->chgBus(c+409,(vlTOPp->io_store_data),32);
        vcdp->chgBus(c+417,(vlTOPp->io_store_address),32);
        vcdp->chgBus(c+425,(vlTOPp->io_load_data),32);
        vcdp->chgBus(c+433,(vlTOPp->io_load_address),32);
        vcdp->chgBit(c+441,(vlTOPp->io_CHOOSE_IMMEDIATE));
        vcdp->chgBit(c+449,(vlTOPp->io_CHOOSE_MEMORY_LOAD));
        vcdp->chgBus(c+457,(vlTOPp->io_IMMEDIATE),32);
        vcdp->chgBus(c+465,(vlTOPp->io_ALU_RD),5);
        vcdp->chgBus(c+473,(vlTOPp->io_instruction_return_address),32);
        vcdp->chgBus(c+481,(vlTOPp->io_instruction_next_address),32);
        vcdp->chgBit(c+489,(vlTOPp->io_PROCEDURE_BRANCHING));
        vcdp->chgBit(c+497,(vlTOPp->io_CHOOSE_PC));
        vcdp->chgBus(c+505,(vlTOPp->io_PC),32);
        vcdp->chgBus(c+513,(((0U == (IData)(vlTOPp->io_RS1))
                              ? 0U : ((0x1fU == (IData)(vlTOPp->io_RS1))
                                       ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_31
                                       : ((0x1eU == (IData)(vlTOPp->io_RS1))
                                           ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_30
                                           : ((0x1dU 
                                               == (IData)(vlTOPp->io_RS1))
                                               ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_29
                                               : ((0x1cU 
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
                                                         : vlTOPp->data_path__DOT__registerFile__DOT___GEN_21)))))))))))),32);
        vcdp->chgBus(c+521,(((0U == (IData)(vlTOPp->io_RS2))
                              ? 0U : ((0x1fU == (IData)(vlTOPp->io_RS2))
                                       ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_31
                                       : ((0x1eU == (IData)(vlTOPp->io_RS2))
                                           ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_30
                                           : ((0x1dU 
                                               == (IData)(vlTOPp->io_RS2))
                                               ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_29
                                               : ((0x1cU 
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
                                                         : vlTOPp->data_path__DOT__registerFile__DOT___GEN_54)))))))))))),32);
        vcdp->chgBus(c+529,((((IData)(vlTOPp->io_RS1) 
                              == (IData)(vlTOPp->io_ALU_RD))
                              ? vlTOPp->data_path__DOT__cpuALU__DOT__ALUoutput
                              : ((0U == (IData)(vlTOPp->io_RS1))
                                  ? 0U : ((0x1fU == (IData)(vlTOPp->io_RS1))
                                           ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_31
                                           : ((0x1eU 
                                               == (IData)(vlTOPp->io_RS1))
                                               ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_30
                                               : ((0x1dU 
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
                                                          : vlTOPp->data_path__DOT__registerFile__DOT___GEN_21))))))))))))),32);
        vcdp->chgBus(c+537,((((IData)(vlTOPp->io_RS2) 
                              == (IData)(vlTOPp->io_RD))
                              ? vlTOPp->data_path__DOT__rdData
                              : vlTOPp->data_path__DOT__rs2_ALU)),32);
    }
}
