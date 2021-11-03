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
        vcdp->declBit(c+121,"clock", false,-1);
        vcdp->declBit(c+129,"reset", false,-1);
        vcdp->declBus(c+137,"io_load_mem_address_in", false,-1, 31,0);
        vcdp->declBus(c+145,"io_load_data", false,-1, 7,0);
        vcdp->declBit(c+153,"io_LOAD_TO_REG", false,-1);
        vcdp->declBus(c+161,"io_LOAD_SIZE", false,-1, 1,0);
        vcdp->declBit(c+169,"io_LOAD_ADDRESS_IN", false,-1);
        vcdp->declBit(c+177,"io_mem_read", false,-1);
        vcdp->declBit(c+185,"io_LOAD_READY", false,-1);
        vcdp->declBus(c+193,"io_load_mem_address_out", false,-1, 31,0);
        vcdp->declBit(c+201,"io_load_begin", false,-1);
        vcdp->declBus(c+209,"io_load_data_out", false,-1, 31,0);
        vcdp->declBit(c+217,"io_EXTENSION", false,-1);
        vcdp->declBit(c+121,"Load_Unit clock", false,-1);
        vcdp->declBit(c+129,"Load_Unit reset", false,-1);
        vcdp->declBus(c+137,"Load_Unit io_load_mem_address_in", false,-1, 31,0);
        vcdp->declBus(c+145,"Load_Unit io_load_data", false,-1, 7,0);
        vcdp->declBit(c+153,"Load_Unit io_LOAD_TO_REG", false,-1);
        vcdp->declBus(c+161,"Load_Unit io_LOAD_SIZE", false,-1, 1,0);
        vcdp->declBit(c+169,"Load_Unit io_LOAD_ADDRESS_IN", false,-1);
        vcdp->declBit(c+177,"Load_Unit io_mem_read", false,-1);
        vcdp->declBit(c+185,"Load_Unit io_LOAD_READY", false,-1);
        vcdp->declBus(c+193,"Load_Unit io_load_mem_address_out", false,-1, 31,0);
        vcdp->declBit(c+201,"Load_Unit io_load_begin", false,-1);
        vcdp->declBus(c+209,"Load_Unit io_load_data_out", false,-1, 31,0);
        vcdp->declBit(c+217,"Load_Unit io_EXTENSION", false,-1);
        vcdp->declBus(c+1,"Load_Unit load_data_buffer", false,-1, 31,0);
        vcdp->declBus(c+9,"Load_Unit load_data_size_buffer", false,-1, 1,0);
        vcdp->declBus(c+17,"Load_Unit load_data_address_buffer", false,-1, 31,0);
        vcdp->declBus(c+25,"Load_Unit LOAD_SIZE", false,-1, 1,0);
        vcdp->declBit(c+33,"Load_Unit EXTENSION", false,-1);
        vcdp->declBit(c+41,"Load_Unit stateReg", false,-1);
        vcdp->declBit(c+49,"Load_Unit MSB", false,-1);
        vcdp->declBit(c+57,"Load_Unit needMask", false,-1);
        vcdp->declBus(c+65,"Load_Unit mask_hi", false,-1, 15,0);
        vcdp->declBus(c+73,"Load_Unit mask_lo", false,-1, 7,0);
        vcdp->declBus(c+81,"Load_Unit mask", false,-1, 23,0);
        vcdp->declBus(c+89,"Load_Unit extending_mask", false,-1, 23,0);
        vcdp->declBus(c+97,"Load_Unit data_out_hi", false,-1, 23,0);
        vcdp->declBus(c+105,"Load_Unit data_out_lo", false,-1, 7,0);
        vcdp->declBus(c+113,"Load_Unit load_data_buffer_hi", false,-1, 23,0);
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
        vcdp->fullBus(c+25,(vlTOPp->Load_Unit__DOT__LOAD_SIZE),2);
        vcdp->fullBit(c+33,(vlTOPp->Load_Unit__DOT__EXTENSION));
        vcdp->fullBit(c+41,(vlTOPp->Load_Unit__DOT__stateReg));
        vcdp->fullBit(c+49,((1U & ((1U & (IData)(vlTOPp->Load_Unit__DOT__LOAD_SIZE))
                                    ? (vlTOPp->Load_Unit__DOT__load_data_buffer 
                                       >> 7U) : (vlTOPp->Load_Unit__DOT__load_data_buffer 
                                                 >> 0xfU)))));
        vcdp->fullBit(c+57,((((1U & (IData)(vlTOPp->Load_Unit__DOT__LOAD_SIZE))
                               ? (vlTOPp->Load_Unit__DOT__load_data_buffer 
                                  >> 7U) : (vlTOPp->Load_Unit__DOT__load_data_buffer 
                                            >> 0xfU)) 
                             & (IData)(vlTOPp->Load_Unit__DOT__EXTENSION))));
        vcdp->fullBus(c+65,(((2U & (IData)(vlTOPp->Load_Unit__DOT__LOAD_SIZE))
                              ? 0xffffU : 0U)),16);
        vcdp->fullBus(c+73,(((3U == (IData)(vlTOPp->Load_Unit__DOT__LOAD_SIZE))
                              ? 0xffU : 0U)),8);
        vcdp->fullBus(c+81,(((((2U & (IData)(vlTOPp->Load_Unit__DOT__LOAD_SIZE))
                                ? 0xffffU : 0U) << 8U) 
                             | ((3U == (IData)(vlTOPp->Load_Unit__DOT__LOAD_SIZE))
                                 ? 0xffU : 0U))),24);
        vcdp->fullBus(c+89,(((((1U & (IData)(vlTOPp->Load_Unit__DOT__LOAD_SIZE))
                                ? (vlTOPp->Load_Unit__DOT__load_data_buffer 
                                   >> 7U) : (vlTOPp->Load_Unit__DOT__load_data_buffer 
                                             >> 0xfU)) 
                              & (IData)(vlTOPp->Load_Unit__DOT__EXTENSION))
                              ? ((((2U & (IData)(vlTOPp->Load_Unit__DOT__LOAD_SIZE))
                                    ? 0xffffU : 0U) 
                                  << 8U) | ((3U == (IData)(vlTOPp->Load_Unit__DOT__LOAD_SIZE))
                                             ? 0xffU
                                             : 0U))
                              : 0U)),24);
        vcdp->fullBus(c+97,((0xffffffU & ((vlTOPp->Load_Unit__DOT__load_data_buffer 
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
        vcdp->fullBus(c+105,((0xffU & vlTOPp->Load_Unit__DOT__load_data_buffer)),8);
        vcdp->fullBus(c+113,((0xffffffU & vlTOPp->Load_Unit__DOT__load_data_buffer)),24);
        vcdp->fullBit(c+121,(vlTOPp->clock));
        vcdp->fullBit(c+129,(vlTOPp->reset));
        vcdp->fullBus(c+137,(vlTOPp->io_load_mem_address_in),32);
        vcdp->fullBus(c+145,(vlTOPp->io_load_data),8);
        vcdp->fullBit(c+153,(vlTOPp->io_LOAD_TO_REG));
        vcdp->fullBus(c+161,(vlTOPp->io_LOAD_SIZE),2);
        vcdp->fullBit(c+169,(vlTOPp->io_LOAD_ADDRESS_IN));
        vcdp->fullBit(c+177,(vlTOPp->io_mem_read));
        vcdp->fullBit(c+185,(vlTOPp->io_LOAD_READY));
        vcdp->fullBus(c+193,(vlTOPp->io_load_mem_address_out),32);
        vcdp->fullBit(c+201,(vlTOPp->io_load_begin));
        vcdp->fullBus(c+209,(vlTOPp->io_load_data_out),32);
        vcdp->fullBit(c+217,(vlTOPp->io_EXTENSION));
    }
}
