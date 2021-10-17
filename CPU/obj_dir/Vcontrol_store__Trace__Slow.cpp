// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vcontrol_store__Syms.h"


//======================

void Vcontrol_store::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback(&Vcontrol_store::traceInit, &Vcontrol_store::traceFull, &Vcontrol_store::traceChg, this);
}
void Vcontrol_store::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    Vcontrol_store* t = (Vcontrol_store*)userthis;
    Vcontrol_store__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vcdp->scopeEscape(' ');
    t->traceInitThis(vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void Vcontrol_store::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vcontrol_store* t = (Vcontrol_store*)userthis;
    Vcontrol_store__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis(vlSymsp, vcdp, code);
}

//======================


void Vcontrol_store::traceInitThis(Vcontrol_store__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vcontrol_store* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
        vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void Vcontrol_store::traceFullThis(Vcontrol_store__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vcontrol_store* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vcontrol_store::traceInitThis__1(Vcontrol_store__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vcontrol_store* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->declBit(c+113,"clock", false,-1);
        vcdp->declBit(c+121,"reset", false,-1);
        vcdp->declBus(c+129,"io_INSTRUCTION", false,-1, 31,0);
        vcdp->declBit(c+137,"io_RECIEVED", false,-1);
        vcdp->declBit(c+145,"io_INSTRUCTION_LOADED", false,-1);
        vcdp->declBus(c+153,"io_RS1", false,-1, 4,0);
        vcdp->declBus(c+161,"io_RS2", false,-1, 4,0);
        vcdp->declBus(c+169,"io_RD", false,-1, 4,0);
        vcdp->declBit(c+177,"io_WRITE_EN", false,-1);
        vcdp->declBus(c+185,"io_ALU_OP", false,-1, 3,0);
        vcdp->declBit(c+193,"io_PROCEDURE_BRANCHING", false,-1);
        vcdp->declBit(c+201,"io_CHOOSE_IMMEDIATE", false,-1);
        vcdp->declBit(c+209,"io_CHOOSE_MEMORY_LOAD", false,-1);
        vcdp->declBus(c+217,"io_IMMEDIATE", false,-1, 31,0);
        vcdp->declBus(c+225,"io_BRANCH_IMMEDIATE", false,-1, 31,0);
        vcdp->declBus(c+233,"io_ALU_RD", false,-1, 4,0);
        vcdp->declBit(c+241,"io_STORE_READY", false,-1);
        vcdp->declBit(c+249,"io_DATA_IN", false,-1);
        vcdp->declBus(c+257,"io_STORE_SIZE", false,-1, 1,0);
        vcdp->declBit(c+265,"io_STORE_ADDRESS_IN", false,-1);
        vcdp->declBit(c+273,"io_LOAD_READY", false,-1);
        vcdp->declBus(c+281,"io_LOAD_SIZE", false,-1, 1,0);
        vcdp->declBit(c+289,"io_LOAD_ADDRESS_IN", false,-1);
        vcdp->declBit(c+297,"io_EXTENSION", false,-1);
        vcdp->declBus(c+305,"io_BRANCH_SELECT", false,-1, 1,0);
        vcdp->declBit(c+313,"io_BRANCH_CONDITION", false,-1);
        vcdp->declBit(c+321,"io_BRANCH_ADDRESS_SOURCE_ALU", false,-1);
        vcdp->declBit(c+329,"io_UPDATE_PC", false,-1);
        vcdp->declBit(c+113,"control_store clock", false,-1);
        vcdp->declBit(c+121,"control_store reset", false,-1);
        vcdp->declBus(c+129,"control_store io_INSTRUCTION", false,-1, 31,0);
        vcdp->declBit(c+137,"control_store io_RECIEVED", false,-1);
        vcdp->declBit(c+145,"control_store io_INSTRUCTION_LOADED", false,-1);
        vcdp->declBus(c+153,"control_store io_RS1", false,-1, 4,0);
        vcdp->declBus(c+161,"control_store io_RS2", false,-1, 4,0);
        vcdp->declBus(c+169,"control_store io_RD", false,-1, 4,0);
        vcdp->declBit(c+177,"control_store io_WRITE_EN", false,-1);
        vcdp->declBus(c+185,"control_store io_ALU_OP", false,-1, 3,0);
        vcdp->declBit(c+193,"control_store io_PROCEDURE_BRANCHING", false,-1);
        vcdp->declBit(c+201,"control_store io_CHOOSE_IMMEDIATE", false,-1);
        vcdp->declBit(c+209,"control_store io_CHOOSE_MEMORY_LOAD", false,-1);
        vcdp->declBus(c+217,"control_store io_IMMEDIATE", false,-1, 31,0);
        vcdp->declBus(c+225,"control_store io_BRANCH_IMMEDIATE", false,-1, 31,0);
        vcdp->declBus(c+233,"control_store io_ALU_RD", false,-1, 4,0);
        vcdp->declBit(c+241,"control_store io_STORE_READY", false,-1);
        vcdp->declBit(c+249,"control_store io_DATA_IN", false,-1);
        vcdp->declBus(c+257,"control_store io_STORE_SIZE", false,-1, 1,0);
        vcdp->declBit(c+265,"control_store io_STORE_ADDRESS_IN", false,-1);
        vcdp->declBit(c+273,"control_store io_LOAD_READY", false,-1);
        vcdp->declBus(c+281,"control_store io_LOAD_SIZE", false,-1, 1,0);
        vcdp->declBit(c+289,"control_store io_LOAD_ADDRESS_IN", false,-1);
        vcdp->declBit(c+297,"control_store io_EXTENSION", false,-1);
        vcdp->declBus(c+305,"control_store io_BRANCH_SELECT", false,-1, 1,0);
        vcdp->declBit(c+313,"control_store io_BRANCH_CONDITION", false,-1);
        vcdp->declBit(c+321,"control_store io_BRANCH_ADDRESS_SOURCE_ALU", false,-1);
        vcdp->declBit(c+329,"control_store io_UPDATE_PC", false,-1);
        vcdp->declBus(c+1,"control_store stateReg", false,-1, 2,0);
        vcdp->declBus(c+9,"control_store stallState", false,-1, 2,0);
        vcdp->declBus(c+17,"control_store instruction", false,-1, 31,0);
        vcdp->declBus(c+25,"control_store hi", false,-1, 6,0);
        vcdp->declBus(c+33,"control_store lo", false,-1, 4,0);
        vcdp->declBit(c+41,"control_store hi_1", false,-1);
        vcdp->declBit(c+49,"control_store lo_1", false,-1);
        vcdp->declBus(c+57,"control_store hi_3", false,-1, 3,0);
        vcdp->declBus(c+65,"control_store lo_2", false,-1, 5,0);
        vcdp->declBus(c+73,"control_store lo_4", false,-1, 7,0);
        vcdp->declBit(c+81,"control_store hi_7", false,-1);
        vcdp->declBus(c+89,"control_store lo_5", false,-1, 9,0);
        vcdp->declBit(c+97,"control_store hi_9", false,-1);
        vcdp->declBus(c+105,"control_store lo_7", false,-1, 2,0);
    }
}

void Vcontrol_store::traceFullThis__1(Vcontrol_store__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vcontrol_store* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->fullBus(c+1,(vlTOPp->control_store__DOT__stateReg),3);
        vcdp->fullBus(c+9,(vlTOPp->control_store__DOT__stallState),3);
        vcdp->fullBus(c+17,(vlTOPp->control_store__DOT__instruction),32);
        vcdp->fullBus(c+25,((0x7fU & (vlTOPp->control_store__DOT__instruction 
                                      >> 0x19U))),7);
        vcdp->fullBus(c+33,((0x1fU & (vlTOPp->control_store__DOT__instruction 
                                      >> 7U))),5);
        vcdp->fullBit(c+41,((1U & (vlTOPp->control_store__DOT__instruction 
                                   >> 0x1fU))));
        vcdp->fullBit(c+49,((1U & (vlTOPp->control_store__DOT__instruction 
                                   >> 7U))));
        vcdp->fullBus(c+57,((0xfU & (vlTOPp->control_store__DOT__instruction 
                                     >> 8U))),4);
        vcdp->fullBus(c+65,((0x3fU & (vlTOPp->control_store__DOT__instruction 
                                      >> 0x19U))),6);
        vcdp->fullBus(c+73,((0xffU & (vlTOPp->control_store__DOT__instruction 
                                      >> 0xcU))),8);
        vcdp->fullBit(c+81,((1U & (vlTOPp->control_store__DOT__instruction 
                                   >> 0x14U))));
        vcdp->fullBus(c+89,((0x3ffU & (vlTOPp->control_store__DOT__instruction 
                                       >> 0x15U))),10);
        vcdp->fullBit(c+97,((1U & (vlTOPp->control_store__DOT__instruction 
                                   >> 0x1eU))));
        vcdp->fullBus(c+105,((7U & (vlTOPp->control_store__DOT__instruction 
                                    >> 0xcU))),3);
        vcdp->fullBit(c+113,(vlTOPp->clock));
        vcdp->fullBit(c+121,(vlTOPp->reset));
        vcdp->fullBus(c+129,(vlTOPp->io_INSTRUCTION),32);
        vcdp->fullBit(c+137,(vlTOPp->io_RECIEVED));
        vcdp->fullBit(c+145,(vlTOPp->io_INSTRUCTION_LOADED));
        vcdp->fullBus(c+153,(vlTOPp->io_RS1),5);
        vcdp->fullBus(c+161,(vlTOPp->io_RS2),5);
        vcdp->fullBus(c+169,(vlTOPp->io_RD),5);
        vcdp->fullBit(c+177,(vlTOPp->io_WRITE_EN));
        vcdp->fullBus(c+185,(vlTOPp->io_ALU_OP),4);
        vcdp->fullBit(c+193,(vlTOPp->io_PROCEDURE_BRANCHING));
        vcdp->fullBit(c+201,(vlTOPp->io_CHOOSE_IMMEDIATE));
        vcdp->fullBit(c+209,(vlTOPp->io_CHOOSE_MEMORY_LOAD));
        vcdp->fullBus(c+217,(vlTOPp->io_IMMEDIATE),32);
        vcdp->fullBus(c+225,(vlTOPp->io_BRANCH_IMMEDIATE),32);
        vcdp->fullBus(c+233,(vlTOPp->io_ALU_RD),5);
        vcdp->fullBit(c+241,(vlTOPp->io_STORE_READY));
        vcdp->fullBit(c+249,(vlTOPp->io_DATA_IN));
        vcdp->fullBus(c+257,(vlTOPp->io_STORE_SIZE),2);
        vcdp->fullBit(c+265,(vlTOPp->io_STORE_ADDRESS_IN));
        vcdp->fullBit(c+273,(vlTOPp->io_LOAD_READY));
        vcdp->fullBus(c+281,(vlTOPp->io_LOAD_SIZE),2);
        vcdp->fullBit(c+289,(vlTOPp->io_LOAD_ADDRESS_IN));
        vcdp->fullBit(c+297,(vlTOPp->io_EXTENSION));
        vcdp->fullBus(c+305,(vlTOPp->io_BRANCH_SELECT),2);
        vcdp->fullBit(c+313,(vlTOPp->io_BRANCH_CONDITION));
        vcdp->fullBit(c+321,(vlTOPp->io_BRANCH_ADDRESS_SOURCE_ALU));
        vcdp->fullBit(c+329,(vlTOPp->io_UPDATE_PC));
    }
}
