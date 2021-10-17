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
        vcdp->chgBus(c+25,((0x7fU & (vlTOPp->control_store__DOT__instruction 
                                     >> 0x19U))),7);
        vcdp->chgBus(c+33,((0x1fU & (vlTOPp->control_store__DOT__instruction 
                                     >> 7U))),5);
        vcdp->chgBit(c+41,((1U & (vlTOPp->control_store__DOT__instruction 
                                  >> 0x1fU))));
        vcdp->chgBit(c+49,((1U & (vlTOPp->control_store__DOT__instruction 
                                  >> 7U))));
        vcdp->chgBus(c+57,((0xfU & (vlTOPp->control_store__DOT__instruction 
                                    >> 8U))),4);
        vcdp->chgBus(c+65,((0x3fU & (vlTOPp->control_store__DOT__instruction 
                                     >> 0x19U))),6);
        vcdp->chgBus(c+73,((0xffU & (vlTOPp->control_store__DOT__instruction 
                                     >> 0xcU))),8);
        vcdp->chgBit(c+81,((1U & (vlTOPp->control_store__DOT__instruction 
                                  >> 0x14U))));
        vcdp->chgBus(c+89,((0x3ffU & (vlTOPp->control_store__DOT__instruction 
                                      >> 0x15U))),10);
        vcdp->chgBit(c+97,((1U & (vlTOPp->control_store__DOT__instruction 
                                  >> 0x1eU))));
        vcdp->chgBus(c+105,((7U & (vlTOPp->control_store__DOT__instruction 
                                   >> 0xcU))),3);
    }
}

void Vcontrol_store::traceChgThis__3(Vcontrol_store__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vcontrol_store* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+113,(vlTOPp->clock));
        vcdp->chgBit(c+121,(vlTOPp->reset));
        vcdp->chgBus(c+129,(vlTOPp->io_INSTRUCTION),32);
        vcdp->chgBit(c+137,(vlTOPp->io_RECIEVED));
        vcdp->chgBit(c+145,(vlTOPp->io_INSTRUCTION_LOADED));
        vcdp->chgBus(c+153,(vlTOPp->io_RS1),5);
        vcdp->chgBus(c+161,(vlTOPp->io_RS2),5);
        vcdp->chgBus(c+169,(vlTOPp->io_RD),5);
        vcdp->chgBit(c+177,(vlTOPp->io_WRITE_EN));
        vcdp->chgBus(c+185,(vlTOPp->io_ALU_OP),4);
        vcdp->chgBit(c+193,(vlTOPp->io_PROCEDURE_BRANCHING));
        vcdp->chgBit(c+201,(vlTOPp->io_CHOOSE_IMMEDIATE));
        vcdp->chgBit(c+209,(vlTOPp->io_CHOOSE_MEMORY_LOAD));
        vcdp->chgBus(c+217,(vlTOPp->io_IMMEDIATE),32);
        vcdp->chgBus(c+225,(vlTOPp->io_BRANCH_IMMEDIATE),32);
        vcdp->chgBus(c+233,(vlTOPp->io_ALU_RD),5);
        vcdp->chgBit(c+241,(vlTOPp->io_STORE_READY));
        vcdp->chgBit(c+249,(vlTOPp->io_DATA_IN));
        vcdp->chgBus(c+257,(vlTOPp->io_STORE_SIZE),2);
        vcdp->chgBit(c+265,(vlTOPp->io_STORE_ADDRESS_IN));
        vcdp->chgBit(c+273,(vlTOPp->io_LOAD_READY));
        vcdp->chgBus(c+281,(vlTOPp->io_LOAD_SIZE),2);
        vcdp->chgBit(c+289,(vlTOPp->io_LOAD_ADDRESS_IN));
        vcdp->chgBit(c+297,(vlTOPp->io_EXTENSION));
        vcdp->chgBus(c+305,(vlTOPp->io_BRANCH_SELECT),2);
        vcdp->chgBit(c+313,(vlTOPp->io_BRANCH_CONDITION));
        vcdp->chgBit(c+321,(vlTOPp->io_BRANCH_ADDRESS_SOURCE_ALU));
        vcdp->chgBit(c+329,(vlTOPp->io_UPDATE_PC));
    }
}
