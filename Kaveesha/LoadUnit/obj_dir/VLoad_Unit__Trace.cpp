// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VLoad_Unit__Syms.h"


//======================

void VLoad_Unit::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VLoad_Unit* t = (VLoad_Unit*)userthis;
    VLoad_Unit__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
        t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void VLoad_Unit::traceChgThis(VLoad_Unit__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VLoad_Unit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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

void VLoad_Unit::traceChgThis__2(VLoad_Unit__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VLoad_Unit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+1,(vlTOPp->Load_Unit__DOT__load_data_buffer),32);
        vcdp->chgBus(c+9,(vlTOPp->Load_Unit__DOT__load_data_size_buffer),2);
        vcdp->chgBus(c+17,(vlTOPp->Load_Unit__DOT__load_data_address_buffer),32);
        vcdp->chgBit(c+25,(vlTOPp->Load_Unit__DOT__stateReg));
        vcdp->chgBus(c+33,((0xffffffU & vlTOPp->Load_Unit__DOT__load_data_buffer)),24);
    }
}

void VLoad_Unit::traceChgThis__3(VLoad_Unit__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VLoad_Unit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+41,(vlTOPp->clock));
        vcdp->chgBit(c+49,(vlTOPp->reset));
        vcdp->chgBus(c+57,(vlTOPp->io_load_mem_address_in),32);
        vcdp->chgBus(c+65,(vlTOPp->io_load_data),8);
        vcdp->chgBit(c+73,(vlTOPp->io_LOAD_TO_REG));
        vcdp->chgBus(c+81,(vlTOPp->io_LOAD_SIZE),2);
        vcdp->chgBit(c+89,(vlTOPp->io_LOAD_ADDRESS_IN));
        vcdp->chgBit(c+97,(vlTOPp->io_mem_read));
        vcdp->chgBit(c+105,(vlTOPp->io_LOAD_READY));
        vcdp->chgBus(c+113,(vlTOPp->io_load_mem_address_out),32);
        vcdp->chgBit(c+121,(vlTOPp->io_load_begin));
        vcdp->chgBus(c+129,(vlTOPp->io_load_data_out),32);
    }
}
