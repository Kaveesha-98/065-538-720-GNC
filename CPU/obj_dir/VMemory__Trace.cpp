// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VMemory__Syms.h"


//======================

void VMemory::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VMemory* t = (VMemory*)userthis;
    VMemory__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
        t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void VMemory::traceChgThis(VMemory__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VMemory* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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

void VMemory::traceChgThis__2(VMemory__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VMemory* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+1,(vlTOPp->Memory__DOT__mem[vlTOPp->Memory__DOT__mem_memData_addr_pipe_0]),8);
        vcdp->chgBus(c+9,(vlTOPp->Memory__DOT__mem_memData_addr_pipe_0),10);
        vcdp->chgBus(c+17,(vlTOPp->Memory__DOT__wrDataReg),8);
        vcdp->chgBit(c+25,(vlTOPp->Memory__DOT__doForwardReg));
    }
}

void VMemory::traceChgThis__3(VMemory__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VMemory* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+33,(vlTOPp->clock));
        vcdp->chgBit(c+41,(vlTOPp->reset));
        vcdp->chgBus(c+49,(vlTOPp->io_rdAddr),32);
        vcdp->chgBus(c+57,(vlTOPp->io_rdData),8);
        vcdp->chgBit(c+65,(vlTOPp->io_mem_write));
        vcdp->chgBus(c+73,(vlTOPp->io_mem_write_data),8);
        vcdp->chgBus(c+81,(vlTOPp->io_mem_write_address),32);
        vcdp->chgBus(c+89,((0x3ffU & vlTOPp->io_mem_write_address)),10);
    }
}
