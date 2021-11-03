// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VLoad_Unit__Syms.h"


//======================

void VLoad_Unit::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback(&VLoad_Unit::traceInit, &VLoad_Unit::traceFull, &VLoad_Unit::traceChg, this);
}
void VLoad_Unit::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    VLoad_Unit* t = (VLoad_Unit*)userthis;
    VLoad_Unit__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vcdp->scopeEscape(' ');
    t->traceInitThis(vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void VLoad_Unit::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VLoad_Unit* t = (VLoad_Unit*)userthis;
    VLoad_Unit__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis(vlSymsp, vcdp, code);
}

//======================


void VLoad_Unit::traceInitThis(VLoad_Unit__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VLoad_Unit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
        vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void VLoad_Unit::traceFullThis(VLoad_Unit__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VLoad_Unit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void VLoad_Unit::traceInitThis__1(VLoad_Unit__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VLoad_Unit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->declBit(c+41,"clock", false,-1);
        vcdp->declBit(c+49,"reset", false,-1);
        vcdp->declBus(c+57,"io_load_mem_address_in", false,-1, 31,0);
        vcdp->declBus(c+65,"io_load_data", false,-1, 7,0);
        vcdp->declBit(c+73,"io_LOAD_TO_REG", false,-1);
        vcdp->declBus(c+81,"io_LOAD_SIZE", false,-1, 1,0);
        vcdp->declBit(c+89,"io_LOAD_ADDRESS_IN", false,-1);
        vcdp->declBit(c+97,"io_mem_read", false,-1);
        vcdp->declBit(c+105,"io_LOAD_READY", false,-1);
        vcdp->declBus(c+113,"io_load_mem_address_out", false,-1, 31,0);
        vcdp->declBit(c+121,"io_load_begin", false,-1);
        vcdp->declBus(c+129,"io_load_data_out", false,-1, 31,0);
        vcdp->declBit(c+41,"Load_Unit clock", false,-1);
        vcdp->declBit(c+49,"Load_Unit reset", false,-1);
        vcdp->declBus(c+57,"Load_Unit io_load_mem_address_in", false,-1, 31,0);
        vcdp->declBus(c+65,"Load_Unit io_load_data", false,-1, 7,0);
        vcdp->declBit(c+73,"Load_Unit io_LOAD_TO_REG", false,-1);
        vcdp->declBus(c+81,"Load_Unit io_LOAD_SIZE", false,-1, 1,0);
        vcdp->declBit(c+89,"Load_Unit io_LOAD_ADDRESS_IN", false,-1);
        vcdp->declBit(c+97,"Load_Unit io_mem_read", false,-1);
        vcdp->declBit(c+105,"Load_Unit io_LOAD_READY", false,-1);
        vcdp->declBus(c+113,"Load_Unit io_load_mem_address_out", false,-1, 31,0);
        vcdp->declBit(c+121,"Load_Unit io_load_begin", false,-1);
        vcdp->declBus(c+129,"Load_Unit io_load_data_out", false,-1, 31,0);
        vcdp->declBus(c+1,"Load_Unit load_data_buffer", false,-1, 31,0);
        vcdp->declBus(c+9,"Load_Unit load_data_size_buffer", false,-1, 1,0);
        vcdp->declBus(c+17,"Load_Unit load_data_address_buffer", false,-1, 31,0);
        vcdp->declBit(c+25,"Load_Unit stateReg", false,-1);
        vcdp->declBus(c+33,"Load_Unit load_data_buffer_hi", false,-1, 23,0);
    }
}

void VLoad_Unit::traceFullThis__1(VLoad_Unit__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VLoad_Unit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->fullBus(c+1,(vlTOPp->Load_Unit__DOT__load_data_buffer),32);
        vcdp->fullBus(c+9,(vlTOPp->Load_Unit__DOT__load_data_size_buffer),2);
        vcdp->fullBus(c+17,(vlTOPp->Load_Unit__DOT__load_data_address_buffer),32);
        vcdp->fullBit(c+25,(vlTOPp->Load_Unit__DOT__stateReg));
        vcdp->fullBus(c+33,((0xffffffU & vlTOPp->Load_Unit__DOT__load_data_buffer)),24);
        vcdp->fullBit(c+41,(vlTOPp->clock));
        vcdp->fullBit(c+49,(vlTOPp->reset));
        vcdp->fullBus(c+57,(vlTOPp->io_load_mem_address_in),32);
        vcdp->fullBus(c+65,(vlTOPp->io_load_data),8);
        vcdp->fullBit(c+73,(vlTOPp->io_LOAD_TO_REG));
        vcdp->fullBus(c+81,(vlTOPp->io_LOAD_SIZE),2);
        vcdp->fullBit(c+89,(vlTOPp->io_LOAD_ADDRESS_IN));
        vcdp->fullBit(c+97,(vlTOPp->io_mem_read));
        vcdp->fullBit(c+105,(vlTOPp->io_LOAD_READY));
        vcdp->fullBus(c+113,(vlTOPp->io_load_mem_address_out),32);
        vcdp->fullBit(c+121,(vlTOPp->io_load_begin));
        vcdp->fullBus(c+129,(vlTOPp->io_load_data_out),32);
    }
}
