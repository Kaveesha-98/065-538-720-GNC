// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VMemory__Syms.h"


//======================

void VMemory::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback(&VMemory::traceInit, &VMemory::traceFull, &VMemory::traceChg, this);
}
void VMemory::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    VMemory* t = (VMemory*)userthis;
    VMemory__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vcdp->scopeEscape(' ');
    t->traceInitThis(vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void VMemory::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VMemory* t = (VMemory*)userthis;
    VMemory__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis(vlSymsp, vcdp, code);
}

//======================


void VMemory::traceInitThis(VMemory__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VMemory* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
        vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void VMemory::traceFullThis(VMemory__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VMemory* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void VMemory::traceInitThis__1(VMemory__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VMemory* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->declBit(c+33,"clock", false,-1);
        vcdp->declBit(c+41,"reset", false,-1);
        vcdp->declBus(c+49,"io_rdAddr", false,-1, 31,0);
        vcdp->declBus(c+57,"io_rdData", false,-1, 7,0);
        vcdp->declBit(c+65,"io_mem_write", false,-1);
        vcdp->declBus(c+73,"io_mem_write_data", false,-1, 7,0);
        vcdp->declBus(c+81,"io_mem_write_address", false,-1, 31,0);
        vcdp->declBit(c+33,"Memory clock", false,-1);
        vcdp->declBit(c+41,"Memory reset", false,-1);
        vcdp->declBus(c+49,"Memory io_rdAddr", false,-1, 31,0);
        vcdp->declBus(c+57,"Memory io_rdData", false,-1, 7,0);
        vcdp->declBit(c+65,"Memory io_mem_write", false,-1);
        vcdp->declBus(c+73,"Memory io_mem_write_data", false,-1, 7,0);
        vcdp->declBus(c+81,"Memory io_mem_write_address", false,-1, 31,0);
        vcdp->declBus(c+1,"Memory mem_memData_data", false,-1, 7,0);
        vcdp->declBus(c+9,"Memory mem_memData_addr", false,-1, 9,0);
        vcdp->declBus(c+73,"Memory mem_MPORT_data", false,-1, 7,0);
        vcdp->declBus(c+89,"Memory mem_MPORT_addr", false,-1, 9,0);
        vcdp->declBit(c+97,"Memory mem_MPORT_mask", false,-1);
        vcdp->declBit(c+65,"Memory mem_MPORT_en", false,-1);
        vcdp->declBus(c+9,"Memory mem_memData_addr_pipe_0", false,-1, 9,0);
        vcdp->declBus(c+17,"Memory wrDataReg", false,-1, 7,0);
        vcdp->declBit(c+25,"Memory doForwardReg", false,-1);
    }
}

void VMemory::traceFullThis__1(VMemory__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VMemory* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->fullBus(c+1,(vlTOPp->Memory__DOT__mem
                           [vlTOPp->Memory__DOT__mem_memData_addr_pipe_0]),8);
        vcdp->fullBus(c+9,(vlTOPp->Memory__DOT__mem_memData_addr_pipe_0),10);
        vcdp->fullBus(c+17,(vlTOPp->Memory__DOT__wrDataReg),8);
        vcdp->fullBit(c+25,(vlTOPp->Memory__DOT__doForwardReg));
        vcdp->fullBit(c+33,(vlTOPp->clock));
        vcdp->fullBit(c+41,(vlTOPp->reset));
        vcdp->fullBus(c+49,(vlTOPp->io_rdAddr),32);
        vcdp->fullBus(c+57,(vlTOPp->io_rdData),8);
        vcdp->fullBit(c+65,(vlTOPp->io_mem_write));
        vcdp->fullBus(c+73,(vlTOPp->io_mem_write_data),8);
        vcdp->fullBus(c+81,(vlTOPp->io_mem_write_address),32);
        vcdp->fullBus(c+89,((0x3ffU & vlTOPp->io_mem_write_address)),10);
        vcdp->fullBit(c+97,(1U));
    }
}
