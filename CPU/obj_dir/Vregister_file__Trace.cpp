// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vregister_file__Syms.h"


//======================

void Vregister_file::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vregister_file* t = (Vregister_file*)userthis;
    Vregister_file__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
        t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void Vregister_file::traceChgThis(Vregister_file__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vregister_file* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY((2U & vlTOPp->__Vm_traceActivity))) {
            vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
        }
        vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vregister_file::traceChgThis__2(Vregister_file__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vregister_file* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+1,(vlTOPp->register_file__DOT__registerFile_0),32);
        vcdp->chgBus(c+9,(vlTOPp->register_file__DOT__registerFile_1),32);
        vcdp->chgBus(c+17,(vlTOPp->register_file__DOT__registerFile_2),32);
        vcdp->chgBus(c+25,(vlTOPp->register_file__DOT__registerFile_3),32);
        vcdp->chgBus(c+33,(vlTOPp->register_file__DOT__registerFile_4),32);
        vcdp->chgBus(c+41,(vlTOPp->register_file__DOT__registerFile_5),32);
        vcdp->chgBus(c+49,(vlTOPp->register_file__DOT__registerFile_6),32);
        vcdp->chgBus(c+57,(vlTOPp->register_file__DOT__registerFile_7),32);
        vcdp->chgBus(c+65,(vlTOPp->register_file__DOT__registerFile_8),32);
        vcdp->chgBus(c+73,(vlTOPp->register_file__DOT__registerFile_9),32);
        vcdp->chgBus(c+81,(vlTOPp->register_file__DOT__registerFile_10),32);
        vcdp->chgBus(c+89,(vlTOPp->register_file__DOT__registerFile_11),32);
        vcdp->chgBus(c+97,(vlTOPp->register_file__DOT__registerFile_12),32);
        vcdp->chgBus(c+105,(vlTOPp->register_file__DOT__registerFile_13),32);
        vcdp->chgBus(c+113,(vlTOPp->register_file__DOT__registerFile_14),32);
        vcdp->chgBus(c+121,(vlTOPp->register_file__DOT__registerFile_15),32);
        vcdp->chgBus(c+129,(vlTOPp->register_file__DOT__registerFile_16),32);
        vcdp->chgBus(c+137,(vlTOPp->register_file__DOT__registerFile_17),32);
        vcdp->chgBus(c+145,(vlTOPp->register_file__DOT__registerFile_18),32);
        vcdp->chgBus(c+153,(vlTOPp->register_file__DOT__registerFile_19),32);
        vcdp->chgBus(c+161,(vlTOPp->register_file__DOT__registerFile_20),32);
        vcdp->chgBus(c+169,(vlTOPp->register_file__DOT__registerFile_21),32);
        vcdp->chgBus(c+177,(vlTOPp->register_file__DOT__registerFile_22),32);
        vcdp->chgBus(c+185,(vlTOPp->register_file__DOT__registerFile_23),32);
        vcdp->chgBus(c+193,(vlTOPp->register_file__DOT__registerFile_24),32);
        vcdp->chgBus(c+201,(vlTOPp->register_file__DOT__registerFile_25),32);
        vcdp->chgBus(c+209,(vlTOPp->register_file__DOT__registerFile_26),32);
        vcdp->chgBus(c+217,(vlTOPp->register_file__DOT__registerFile_27),32);
        vcdp->chgBus(c+225,(vlTOPp->register_file__DOT__registerFile_28),32);
        vcdp->chgBus(c+233,(vlTOPp->register_file__DOT__registerFile_29),32);
        vcdp->chgBus(c+241,(vlTOPp->register_file__DOT__registerFile_30),32);
        vcdp->chgBus(c+249,(vlTOPp->register_file__DOT__registerFile_31),32);
    }
}

void Vregister_file::traceChgThis__3(Vregister_file__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vregister_file* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+257,(vlTOPp->clock));
        vcdp->chgBit(c+265,(vlTOPp->reset));
        vcdp->chgBus(c+273,(vlTOPp->io_RS1),5);
        vcdp->chgBus(c+281,(vlTOPp->io_RS2),5);
        vcdp->chgBus(c+289,(vlTOPp->io_RD),5);
        vcdp->chgBit(c+297,(vlTOPp->io_WRITE_EN));
        vcdp->chgBus(c+305,(vlTOPp->io_rs1Data),32);
        vcdp->chgBus(c+313,(vlTOPp->io_rs2Data),32);
        vcdp->chgBus(c+321,(vlTOPp->io_rdData),32);
    }
}
