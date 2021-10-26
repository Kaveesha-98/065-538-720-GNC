// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vregister_file__Syms.h"


//======================

void Vregister_file::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback(&Vregister_file::traceInit, &Vregister_file::traceFull, &Vregister_file::traceChg, this);
}
void Vregister_file::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    Vregister_file* t = (Vregister_file*)userthis;
    Vregister_file__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vcdp->scopeEscape(' ');
    t->traceInitThis(vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void Vregister_file::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vregister_file* t = (Vregister_file*)userthis;
    Vregister_file__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis(vlSymsp, vcdp, code);
}

//======================


void Vregister_file::traceInitThis(Vregister_file__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vregister_file* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
        vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void Vregister_file::traceFullThis(Vregister_file__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vregister_file* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vregister_file::traceInitThis__1(Vregister_file__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vregister_file* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->declBit(c+257,"clock", false,-1);
        vcdp->declBit(c+265,"reset", false,-1);
        vcdp->declBus(c+273,"io_RS1", false,-1, 4,0);
        vcdp->declBus(c+281,"io_RS2", false,-1, 4,0);
        vcdp->declBus(c+289,"io_RD", false,-1, 4,0);
        vcdp->declBit(c+297,"io_WRITE_EN", false,-1);
        vcdp->declBus(c+305,"io_rs1Data", false,-1, 31,0);
        vcdp->declBus(c+313,"io_rs2Data", false,-1, 31,0);
        vcdp->declBus(c+321,"io_rdData", false,-1, 31,0);
        vcdp->declBit(c+257,"register_file clock", false,-1);
        vcdp->declBit(c+265,"register_file reset", false,-1);
        vcdp->declBus(c+273,"register_file io_RS1", false,-1, 4,0);
        vcdp->declBus(c+281,"register_file io_RS2", false,-1, 4,0);
        vcdp->declBus(c+289,"register_file io_RD", false,-1, 4,0);
        vcdp->declBit(c+297,"register_file io_WRITE_EN", false,-1);
        vcdp->declBus(c+305,"register_file io_rs1Data", false,-1, 31,0);
        vcdp->declBus(c+313,"register_file io_rs2Data", false,-1, 31,0);
        vcdp->declBus(c+321,"register_file io_rdData", false,-1, 31,0);
        vcdp->declBus(c+1,"register_file registerFile_0", false,-1, 31,0);
        vcdp->declBus(c+9,"register_file registerFile_1", false,-1, 31,0);
        vcdp->declBus(c+17,"register_file registerFile_2", false,-1, 31,0);
        vcdp->declBus(c+25,"register_file registerFile_3", false,-1, 31,0);
        vcdp->declBus(c+33,"register_file registerFile_4", false,-1, 31,0);
        vcdp->declBus(c+41,"register_file registerFile_5", false,-1, 31,0);
        vcdp->declBus(c+49,"register_file registerFile_6", false,-1, 31,0);
        vcdp->declBus(c+57,"register_file registerFile_7", false,-1, 31,0);
        vcdp->declBus(c+65,"register_file registerFile_8", false,-1, 31,0);
        vcdp->declBus(c+73,"register_file registerFile_9", false,-1, 31,0);
        vcdp->declBus(c+81,"register_file registerFile_10", false,-1, 31,0);
        vcdp->declBus(c+89,"register_file registerFile_11", false,-1, 31,0);
        vcdp->declBus(c+97,"register_file registerFile_12", false,-1, 31,0);
        vcdp->declBus(c+105,"register_file registerFile_13", false,-1, 31,0);
        vcdp->declBus(c+113,"register_file registerFile_14", false,-1, 31,0);
        vcdp->declBus(c+121,"register_file registerFile_15", false,-1, 31,0);
        vcdp->declBus(c+129,"register_file registerFile_16", false,-1, 31,0);
        vcdp->declBus(c+137,"register_file registerFile_17", false,-1, 31,0);
        vcdp->declBus(c+145,"register_file registerFile_18", false,-1, 31,0);
        vcdp->declBus(c+153,"register_file registerFile_19", false,-1, 31,0);
        vcdp->declBus(c+161,"register_file registerFile_20", false,-1, 31,0);
        vcdp->declBus(c+169,"register_file registerFile_21", false,-1, 31,0);
        vcdp->declBus(c+177,"register_file registerFile_22", false,-1, 31,0);
        vcdp->declBus(c+185,"register_file registerFile_23", false,-1, 31,0);
        vcdp->declBus(c+193,"register_file registerFile_24", false,-1, 31,0);
        vcdp->declBus(c+201,"register_file registerFile_25", false,-1, 31,0);
        vcdp->declBus(c+209,"register_file registerFile_26", false,-1, 31,0);
        vcdp->declBus(c+217,"register_file registerFile_27", false,-1, 31,0);
        vcdp->declBus(c+225,"register_file registerFile_28", false,-1, 31,0);
        vcdp->declBus(c+233,"register_file registerFile_29", false,-1, 31,0);
        vcdp->declBus(c+241,"register_file registerFile_30", false,-1, 31,0);
        vcdp->declBus(c+249,"register_file registerFile_31", false,-1, 31,0);
    }
}

void Vregister_file::traceFullThis__1(Vregister_file__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vregister_file* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->fullBus(c+1,(vlTOPp->register_file__DOT__registerFile_0),32);
        vcdp->fullBus(c+9,(vlTOPp->register_file__DOT__registerFile_1),32);
        vcdp->fullBus(c+17,(vlTOPp->register_file__DOT__registerFile_2),32);
        vcdp->fullBus(c+25,(vlTOPp->register_file__DOT__registerFile_3),32);
        vcdp->fullBus(c+33,(vlTOPp->register_file__DOT__registerFile_4),32);
        vcdp->fullBus(c+41,(vlTOPp->register_file__DOT__registerFile_5),32);
        vcdp->fullBus(c+49,(vlTOPp->register_file__DOT__registerFile_6),32);
        vcdp->fullBus(c+57,(vlTOPp->register_file__DOT__registerFile_7),32);
        vcdp->fullBus(c+65,(vlTOPp->register_file__DOT__registerFile_8),32);
        vcdp->fullBus(c+73,(vlTOPp->register_file__DOT__registerFile_9),32);
        vcdp->fullBus(c+81,(vlTOPp->register_file__DOT__registerFile_10),32);
        vcdp->fullBus(c+89,(vlTOPp->register_file__DOT__registerFile_11),32);
        vcdp->fullBus(c+97,(vlTOPp->register_file__DOT__registerFile_12),32);
        vcdp->fullBus(c+105,(vlTOPp->register_file__DOT__registerFile_13),32);
        vcdp->fullBus(c+113,(vlTOPp->register_file__DOT__registerFile_14),32);
        vcdp->fullBus(c+121,(vlTOPp->register_file__DOT__registerFile_15),32);
        vcdp->fullBus(c+129,(vlTOPp->register_file__DOT__registerFile_16),32);
        vcdp->fullBus(c+137,(vlTOPp->register_file__DOT__registerFile_17),32);
        vcdp->fullBus(c+145,(vlTOPp->register_file__DOT__registerFile_18),32);
        vcdp->fullBus(c+153,(vlTOPp->register_file__DOT__registerFile_19),32);
        vcdp->fullBus(c+161,(vlTOPp->register_file__DOT__registerFile_20),32);
        vcdp->fullBus(c+169,(vlTOPp->register_file__DOT__registerFile_21),32);
        vcdp->fullBus(c+177,(vlTOPp->register_file__DOT__registerFile_22),32);
        vcdp->fullBus(c+185,(vlTOPp->register_file__DOT__registerFile_23),32);
        vcdp->fullBus(c+193,(vlTOPp->register_file__DOT__registerFile_24),32);
        vcdp->fullBus(c+201,(vlTOPp->register_file__DOT__registerFile_25),32);
        vcdp->fullBus(c+209,(vlTOPp->register_file__DOT__registerFile_26),32);
        vcdp->fullBus(c+217,(vlTOPp->register_file__DOT__registerFile_27),32);
        vcdp->fullBus(c+225,(vlTOPp->register_file__DOT__registerFile_28),32);
        vcdp->fullBus(c+233,(vlTOPp->register_file__DOT__registerFile_29),32);
        vcdp->fullBus(c+241,(vlTOPp->register_file__DOT__registerFile_30),32);
        vcdp->fullBus(c+249,(vlTOPp->register_file__DOT__registerFile_31),32);
        vcdp->fullBit(c+257,(vlTOPp->clock));
        vcdp->fullBit(c+265,(vlTOPp->reset));
        vcdp->fullBus(c+273,(vlTOPp->io_RS1),5);
        vcdp->fullBus(c+281,(vlTOPp->io_RS2),5);
        vcdp->fullBus(c+289,(vlTOPp->io_RD),5);
        vcdp->fullBit(c+297,(vlTOPp->io_WRITE_EN));
        vcdp->fullBus(c+305,(vlTOPp->io_rs1Data),32);
        vcdp->fullBus(c+313,(vlTOPp->io_rs2Data),32);
        vcdp->fullBus(c+321,(vlTOPp->io_rdData),32);
    }
}
