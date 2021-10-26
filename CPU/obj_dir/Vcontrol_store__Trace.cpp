// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vcontrol_store__Syms.h"


//======================

void Vcontrol_store::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vcontrol_store* t = (Vcontrol_store*)userthis;
    Vcontrol_store__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
        t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void Vcontrol_store::traceChgThis(Vcontrol_store__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vcontrol_store* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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

void Vcontrol_store::traceChgThis__2(Vcontrol_store__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vcontrol_store* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+1,(vlTOPp->control_store__DOT__stateReg),3);
        vcdp->chgBus(c+9,(vlTOPp->control_store__DOT__stallState),3);
        vcdp->chgBus(c+17,(vlTOPp->control_store__DOT__instruction),32);
        vcdp->chgBit(c+25,(vlTOPp->control_store__DOT__RECIEVED));
        vcdp->chgBit(c+33,(vlTOPp->control_store__DOT__STORE_READY));
        vcdp->chgBit(c+41,(vlTOPp->control_store__DOT__LOAD_READY));
        vcdp->chgBus(c+49,((0x7fU & (vlTOPp->control_store__DOT__instruction 
                                     >> 0x19U))),7);
        vcdp->chgBus(c+57,((0x1fU & (vlTOPp->control_store__DOT__instruction 
                                     >> 7U))),5);
        vcdp->chgBit(c+65,((1U & (vlTOPp->control_store__DOT__instruction 
                                  >> 0x1fU))));
        vcdp->chgBit(c+73,((1U & (vlTOPp->control_store__DOT__instruction 
                                  >> 7U))));
        vcdp->chgBus(c+81,((0xfU & (vlTOPp->control_store__DOT__instruction 
                                    >> 8U))),4);
        vcdp->chgBus(c+89,((0x3fU & (vlTOPp->control_store__DOT__instruction 
                                     >> 0x19U))),6);
        vcdp->chgBus(c+97,((0xffU & (vlTOPp->control_store__DOT__instruction 
                                     >> 0xcU))),8);
        vcdp->chgBit(c+105,((1U & (vlTOPp->control_store__DOT__instruction 
                                   >> 0x14U))));
        vcdp->chgBus(c+113,((0x3ffU & (vlTOPp->control_store__DOT__instruction 
                                       >> 0x15U))),10);
        vcdp->chgBit(c+121,(((1U == (3U & (vlTOPp->control_store__DOT__instruction 
                                           >> 0xcU))) 
                             & (vlTOPp->control_store__DOT__instruction 
                                >> 0x1eU))));
        vcdp->chgBus(c+129,((7U & (vlTOPp->control_store__DOT__instruction 
                                   >> 0xcU))),3);
    }
}

void Vcontrol_store::traceChgThis__3(Vcontrol_store__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vcontrol_store* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+137,(vlTOPp->clock));
        vcdp->chgBit(c+145,(vlTOPp->reset));
        vcdp->chgBus(c+153,(vlTOPp->io_INSTRUCTION),32);
        vcdp->chgBit(c+161,(vlTOPp->io_RECIEVED));
        vcdp->chgBit(c+169,(vlTOPp->io_INSTRUCTION_LOADED));
        vcdp->chgBus(c+177,(vlTOPp->io_RS1),5);
        vcdp->chgBus(c+185,(vlTOPp->io_RS2),5);
        vcdp->chgBus(c+193,(vlTOPp->io_RD),5);
        vcdp->chgBit(c+201,(vlTOPp->io_WRITE_EN));
        vcdp->chgBus(c+209,(vlTOPp->io_ALU_OP),4);
        vcdp->chgBit(c+217,(vlTOPp->io_PROCEDURE_BRANCHING));
        vcdp->chgBit(c+225,(vlTOPp->io_CHOOSE_IMMEDIATE));
        vcdp->chgBit(c+233,(vlTOPp->io_CHOOSE_MEMORY_LOAD));
        vcdp->chgBus(c+241,(vlTOPp->io_IMMEDIATE),32);
        vcdp->chgBus(c+249,(vlTOPp->io_BRANCH_IMMEDIATE),32);
        vcdp->chgBus(c+257,(vlTOPp->io_ALU_RD),5);
        vcdp->chgBit(c+265,(vlTOPp->io_STORE_READY));
        vcdp->chgBit(c+273,(vlTOPp->io_DATA_IN));
        vcdp->chgBus(c+281,(vlTOPp->io_STORE_SIZE),2);
        vcdp->chgBit(c+289,(vlTOPp->io_STORE_ADDRESS_IN));
        vcdp->chgBit(c+297,(vlTOPp->io_LOAD_READY));
        vcdp->chgBus(c+305,(vlTOPp->io_LOAD_SIZE),2);
        vcdp->chgBit(c+313,(vlTOPp->io_LOAD_ADDRESS_IN));
        vcdp->chgBit(c+321,(vlTOPp->io_EXTENSION));
        vcdp->chgBus(c+329,(vlTOPp->io_BRANCH_SELECT),2);
        vcdp->chgBit(c+337,(vlTOPp->io_BRANCH_CONDITION));
        vcdp->chgBit(c+345,(vlTOPp->io_BRANCH_ADDRESS_SOURCE_ALU));
        vcdp->chgBit(c+353,(vlTOPp->io_UPDATE_PC));
        vcdp->chgBit(c+361,(vlTOPp->io_CHOOSE_PC));
    }
}
