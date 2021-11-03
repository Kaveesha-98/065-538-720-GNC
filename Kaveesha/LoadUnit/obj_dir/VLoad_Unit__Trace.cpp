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
        vcdp->chgBus(c+25,(vlTOPp->Load_Unit__DOT__LOAD_SIZE),2);
        vcdp->chgBit(c+33,(vlTOPp->Load_Unit__DOT__EXTENSION));
        vcdp->chgBit(c+41,(vlTOPp->Load_Unit__DOT__stateReg));
        vcdp->chgBit(c+49,((1U & ((1U & (IData)(vlTOPp->Load_Unit__DOT__LOAD_SIZE))
                                   ? (vlTOPp->Load_Unit__DOT__load_data_buffer 
                                      >> 7U) : (vlTOPp->Load_Unit__DOT__load_data_buffer 
                                                >> 0xfU)))));
        vcdp->chgBit(c+57,((((1U & (IData)(vlTOPp->Load_Unit__DOT__LOAD_SIZE))
                              ? (vlTOPp->Load_Unit__DOT__load_data_buffer 
                                 >> 7U) : (vlTOPp->Load_Unit__DOT__load_data_buffer 
                                           >> 0xfU)) 
                            & (IData)(vlTOPp->Load_Unit__DOT__EXTENSION))));
        vcdp->chgBus(c+65,(((2U & (IData)(vlTOPp->Load_Unit__DOT__LOAD_SIZE))
                             ? 0xffffU : 0U)),16);
        vcdp->chgBus(c+73,(((3U == (IData)(vlTOPp->Load_Unit__DOT__LOAD_SIZE))
                             ? 0xffU : 0U)),8);
        vcdp->chgBus(c+81,(((((2U & (IData)(vlTOPp->Load_Unit__DOT__LOAD_SIZE))
                               ? 0xffffU : 0U) << 8U) 
                            | ((3U == (IData)(vlTOPp->Load_Unit__DOT__LOAD_SIZE))
                                ? 0xffU : 0U))),24);
        vcdp->chgBus(c+89,(((((1U & (IData)(vlTOPp->Load_Unit__DOT__LOAD_SIZE))
                               ? (vlTOPp->Load_Unit__DOT__load_data_buffer 
                                  >> 7U) : (vlTOPp->Load_Unit__DOT__load_data_buffer 
                                            >> 0xfU)) 
                             & (IData)(vlTOPp->Load_Unit__DOT__EXTENSION))
                             ? ((((2U & (IData)(vlTOPp->Load_Unit__DOT__LOAD_SIZE))
                                   ? 0xffffU : 0U) 
                                 << 8U) | ((3U == (IData)(vlTOPp->Load_Unit__DOT__LOAD_SIZE))
                                            ? 0xffU
                                            : 0U)) : 0U)),24);
        vcdp->chgBus(c+97,((0xffffffU & ((vlTOPp->Load_Unit__DOT__load_data_buffer 
                                          >> 8U) | 
                                         ((((1U & (IData)(vlTOPp->Load_Unit__DOT__LOAD_SIZE))
                                             ? (vlTOPp->Load_Unit__DOT__load_data_buffer 
                                                >> 7U)
                                             : (vlTOPp->Load_Unit__DOT__load_data_buffer 
                                                >> 0xfU)) 
                                           & (IData)(vlTOPp->Load_Unit__DOT__EXTENSION))
                                           ? ((((2U 
                                                 & (IData)(vlTOPp->Load_Unit__DOT__LOAD_SIZE))
                                                 ? 0xffffU
                                                 : 0U) 
                                               << 8U) 
                                              | ((3U 
                                                  == (IData)(vlTOPp->Load_Unit__DOT__LOAD_SIZE))
                                                  ? 0xffU
                                                  : 0U))
                                           : 0U)))),24);
        vcdp->chgBus(c+105,((0xffU & vlTOPp->Load_Unit__DOT__load_data_buffer)),8);
        vcdp->chgBus(c+113,((0xffffffU & vlTOPp->Load_Unit__DOT__load_data_buffer)),24);
    }
}

void VLoad_Unit::traceChgThis__3(VLoad_Unit__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VLoad_Unit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+121,(vlTOPp->clock));
        vcdp->chgBit(c+129,(vlTOPp->reset));
        vcdp->chgBus(c+137,(vlTOPp->io_load_mem_address_in),32);
        vcdp->chgBus(c+145,(vlTOPp->io_load_data),8);
        vcdp->chgBit(c+153,(vlTOPp->io_LOAD_TO_REG));
        vcdp->chgBus(c+161,(vlTOPp->io_LOAD_SIZE),2);
        vcdp->chgBit(c+169,(vlTOPp->io_LOAD_ADDRESS_IN));
        vcdp->chgBit(c+177,(vlTOPp->io_mem_read));
        vcdp->chgBit(c+185,(vlTOPp->io_LOAD_READY));
        vcdp->chgBus(c+193,(vlTOPp->io_load_mem_address_out),32);
        vcdp->chgBit(c+201,(vlTOPp->io_load_begin));
        vcdp->chgBus(c+209,(vlTOPp->io_load_data_out),32);
        vcdp->chgBit(c+217,(vlTOPp->io_EXTENSION));
    }
}
