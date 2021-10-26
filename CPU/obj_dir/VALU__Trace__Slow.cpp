// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VALU__Syms.h"


//======================

void VALU::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback(&VALU::traceInit, &VALU::traceFull, &VALU::traceChg, this);
}
void VALU::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    VALU* t = (VALU*)userthis;
    VALU__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vcdp->scopeEscape(' ');
    t->traceInitThis(vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void VALU::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VALU* t = (VALU*)userthis;
    VALU__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis(vlSymsp, vcdp, code);
}

//======================


void VALU::traceInitThis(VALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
        vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void VALU::traceFullThis(VALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void VALU::traceInitThis__1(VALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->declBit(c+329,"clock", false,-1);
        vcdp->declBit(c+337,"reset", false,-1);
        vcdp->declBus(c+345,"io_RS1", false,-1, 4,0);
        vcdp->declBus(c+353,"io_RS2", false,-1, 4,0);
        vcdp->declBus(c+361,"io_RD", false,-1, 4,0);
        vcdp->declBit(c+369,"io_WRITE_EN", false,-1);
        vcdp->declBus(c+377,"io_ALU_OP", false,-1, 3,0);
        vcdp->declBit(c+385,"io_EQUAL", false,-1);
        vcdp->declBit(c+393,"io_LESS_THAN", false,-1);
        vcdp->declBit(c+401,"io_SIGNED_LESS_THAN", false,-1);
        vcdp->declBus(c+409,"io_store_data", false,-1, 31,0);
        vcdp->declBus(c+417,"io_store_address", false,-1, 31,0);
        vcdp->declBus(c+425,"io_load_data", false,-1, 31,0);
        vcdp->declBus(c+433,"io_load_address", false,-1, 31,0);
        vcdp->declBit(c+441,"io_CHOOSE_IMMEDIATE", false,-1);
        vcdp->declBit(c+449,"io_CHOOSE_MEMORY_LOAD", false,-1);
        vcdp->declBus(c+457,"io_IMMEDIATE", false,-1, 31,0);
        vcdp->declBus(c+465,"io_ALU_RD", false,-1, 4,0);
        vcdp->declBus(c+473,"io_instruction_return_address", false,-1, 31,0);
        vcdp->declBus(c+481,"io_instruction_next_address", false,-1, 31,0);
        vcdp->declBit(c+489,"io_PROCEDURE_BRANCHING", false,-1);
        vcdp->declBit(c+497,"io_CHOOSE_PC", false,-1);
        vcdp->declBus(c+505,"io_PC", false,-1, 31,0);
        vcdp->declBit(c+329,"data_path clock", false,-1);
        vcdp->declBit(c+337,"data_path reset", false,-1);
        vcdp->declBus(c+345,"data_path io_RS1", false,-1, 4,0);
        vcdp->declBus(c+353,"data_path io_RS2", false,-1, 4,0);
        vcdp->declBus(c+361,"data_path io_RD", false,-1, 4,0);
        vcdp->declBit(c+369,"data_path io_WRITE_EN", false,-1);
        vcdp->declBus(c+377,"data_path io_ALU_OP", false,-1, 3,0);
        vcdp->declBit(c+385,"data_path io_EQUAL", false,-1);
        vcdp->declBit(c+393,"data_path io_LESS_THAN", false,-1);
        vcdp->declBit(c+401,"data_path io_SIGNED_LESS_THAN", false,-1);
        vcdp->declBus(c+409,"data_path io_store_data", false,-1, 31,0);
        vcdp->declBus(c+417,"data_path io_store_address", false,-1, 31,0);
        vcdp->declBus(c+425,"data_path io_load_data", false,-1, 31,0);
        vcdp->declBus(c+433,"data_path io_load_address", false,-1, 31,0);
        vcdp->declBit(c+441,"data_path io_CHOOSE_IMMEDIATE", false,-1);
        vcdp->declBit(c+449,"data_path io_CHOOSE_MEMORY_LOAD", false,-1);
        vcdp->declBus(c+457,"data_path io_IMMEDIATE", false,-1, 31,0);
        vcdp->declBus(c+465,"data_path io_ALU_RD", false,-1, 4,0);
        vcdp->declBus(c+473,"data_path io_instruction_return_address", false,-1, 31,0);
        vcdp->declBus(c+481,"data_path io_instruction_next_address", false,-1, 31,0);
        vcdp->declBit(c+489,"data_path io_PROCEDURE_BRANCHING", false,-1);
        vcdp->declBit(c+497,"data_path io_CHOOSE_PC", false,-1);
        vcdp->declBus(c+505,"data_path io_PC", false,-1, 31,0);
        vcdp->declBit(c+329,"data_path cpuALU_clock", false,-1);
        vcdp->declBit(c+337,"data_path cpuALU_reset", false,-1);
        vcdp->declBus(c+377,"data_path cpuALU_io_ALU_OP", false,-1, 3,0);
        vcdp->declBit(c+25,"data_path cpuALU_io_EQUAL", false,-1);
        vcdp->declBit(c+33,"data_path cpuALU_io_LESS_THAN", false,-1);
        vcdp->declBit(c+41,"data_path cpuALU_io_SIGNED_LESS_THAN", false,-1);
        vcdp->declBus(c+49,"data_path cpuALU_io_ALUinput1", false,-1, 31,0);
        vcdp->declBus(c+57,"data_path cpuALU_io_ALUinput2", false,-1, 31,0);
        vcdp->declBus(c+65,"data_path cpuALU_io_ALUoutput", false,-1, 31,0);
        vcdp->declBit(c+329,"data_path registerFile_clock", false,-1);
        vcdp->declBus(c+345,"data_path registerFile_io_RS1", false,-1, 4,0);
        vcdp->declBus(c+353,"data_path registerFile_io_RS2", false,-1, 4,0);
        vcdp->declBus(c+361,"data_path registerFile_io_RD", false,-1, 4,0);
        vcdp->declBit(c+369,"data_path registerFile_io_WRITE_EN", false,-1);
        vcdp->declBus(c+513,"data_path registerFile_io_rs1Data", false,-1, 31,0);
        vcdp->declBus(c+521,"data_path registerFile_io_rs2Data", false,-1, 31,0);
        vcdp->declBus(c+1,"data_path registerFile_io_rdData", false,-1, 31,0);
        vcdp->declBus(c+49,"data_path ALU_in1", false,-1, 31,0);
        vcdp->declBus(c+57,"data_path ALU_in2", false,-1, 31,0);
        vcdp->declBus(c+9,"data_path rdData", false,-1, 31,0);
        vcdp->declBus(c+529,"data_path rs1_ALU", false,-1, 31,0);
        vcdp->declBus(c+17,"data_path rs2_ALU", false,-1, 31,0);
        vcdp->declBus(c+537,"data_path rs2_ALU_rd", false,-1, 31,0);
        vcdp->declBit(c+329,"data_path cpuALU clock", false,-1);
        vcdp->declBit(c+337,"data_path cpuALU reset", false,-1);
        vcdp->declBus(c+377,"data_path cpuALU io_ALU_OP", false,-1, 3,0);
        vcdp->declBit(c+25,"data_path cpuALU io_EQUAL", false,-1);
        vcdp->declBit(c+33,"data_path cpuALU io_LESS_THAN", false,-1);
        vcdp->declBit(c+41,"data_path cpuALU io_SIGNED_LESS_THAN", false,-1);
        vcdp->declBus(c+49,"data_path cpuALU io_ALUinput1", false,-1, 31,0);
        vcdp->declBus(c+57,"data_path cpuALU io_ALUinput2", false,-1, 31,0);
        vcdp->declBus(c+65,"data_path cpuALU io_ALUoutput", false,-1, 31,0);
        vcdp->declBus(c+65,"data_path cpuALU ALUoutput", false,-1, 31,0);
        vcdp->declBit(c+25,"data_path cpuALU EQUAL", false,-1);
        vcdp->declBit(c+33,"data_path cpuALU LESS_THAN", false,-1);
        vcdp->declBit(c+41,"data_path cpuALU SIGNED_LESS_THAN", false,-1);
        vcdp->declBit(c+329,"data_path registerFile clock", false,-1);
        vcdp->declBit(c+545,"data_path registerFile reset", false,-1);
        vcdp->declBus(c+345,"data_path registerFile io_RS1", false,-1, 4,0);
        vcdp->declBus(c+353,"data_path registerFile io_RS2", false,-1, 4,0);
        vcdp->declBus(c+361,"data_path registerFile io_RD", false,-1, 4,0);
        vcdp->declBit(c+369,"data_path registerFile io_WRITE_EN", false,-1);
        vcdp->declBus(c+513,"data_path registerFile io_rs1Data", false,-1, 31,0);
        vcdp->declBus(c+521,"data_path registerFile io_rs2Data", false,-1, 31,0);
        vcdp->declBus(c+1,"data_path registerFile io_rdData", false,-1, 31,0);
        vcdp->declBus(c+73,"data_path registerFile registerFile_0", false,-1, 31,0);
        vcdp->declBus(c+81,"data_path registerFile registerFile_1", false,-1, 31,0);
        vcdp->declBus(c+89,"data_path registerFile registerFile_2", false,-1, 31,0);
        vcdp->declBus(c+97,"data_path registerFile registerFile_3", false,-1, 31,0);
        vcdp->declBus(c+105,"data_path registerFile registerFile_4", false,-1, 31,0);
        vcdp->declBus(c+113,"data_path registerFile registerFile_5", false,-1, 31,0);
        vcdp->declBus(c+121,"data_path registerFile registerFile_6", false,-1, 31,0);
        vcdp->declBus(c+129,"data_path registerFile registerFile_7", false,-1, 31,0);
        vcdp->declBus(c+137,"data_path registerFile registerFile_8", false,-1, 31,0);
        vcdp->declBus(c+145,"data_path registerFile registerFile_9", false,-1, 31,0);
        vcdp->declBus(c+153,"data_path registerFile registerFile_10", false,-1, 31,0);
        vcdp->declBus(c+161,"data_path registerFile registerFile_11", false,-1, 31,0);
        vcdp->declBus(c+169,"data_path registerFile registerFile_12", false,-1, 31,0);
        vcdp->declBus(c+177,"data_path registerFile registerFile_13", false,-1, 31,0);
        vcdp->declBus(c+185,"data_path registerFile registerFile_14", false,-1, 31,0);
        vcdp->declBus(c+193,"data_path registerFile registerFile_15", false,-1, 31,0);
        vcdp->declBus(c+201,"data_path registerFile registerFile_16", false,-1, 31,0);
        vcdp->declBus(c+209,"data_path registerFile registerFile_17", false,-1, 31,0);
        vcdp->declBus(c+217,"data_path registerFile registerFile_18", false,-1, 31,0);
        vcdp->declBus(c+225,"data_path registerFile registerFile_19", false,-1, 31,0);
        vcdp->declBus(c+233,"data_path registerFile registerFile_20", false,-1, 31,0);
        vcdp->declBus(c+241,"data_path registerFile registerFile_21", false,-1, 31,0);
        vcdp->declBus(c+249,"data_path registerFile registerFile_22", false,-1, 31,0);
        vcdp->declBus(c+257,"data_path registerFile registerFile_23", false,-1, 31,0);
        vcdp->declBus(c+265,"data_path registerFile registerFile_24", false,-1, 31,0);
        vcdp->declBus(c+273,"data_path registerFile registerFile_25", false,-1, 31,0);
        vcdp->declBus(c+281,"data_path registerFile registerFile_26", false,-1, 31,0);
        vcdp->declBus(c+289,"data_path registerFile registerFile_27", false,-1, 31,0);
        vcdp->declBus(c+297,"data_path registerFile registerFile_28", false,-1, 31,0);
        vcdp->declBus(c+305,"data_path registerFile registerFile_29", false,-1, 31,0);
        vcdp->declBus(c+313,"data_path registerFile registerFile_30", false,-1, 31,0);
        vcdp->declBus(c+321,"data_path registerFile registerFile_31", false,-1, 31,0);
    }
}

void VALU::traceFullThis__1(VALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->fullBus(c+1,(vlTOPp->data_path__DOT__registerFile_io_rdData),32);
        vcdp->fullBus(c+9,(vlTOPp->data_path__DOT__rdData),32);
        vcdp->fullBus(c+17,(vlTOPp->data_path__DOT__rs2_ALU),32);
        vcdp->fullBit(c+25,(vlTOPp->data_path__DOT__cpuALU__DOT__EQUAL));
        vcdp->fullBit(c+33,(vlTOPp->data_path__DOT__cpuALU__DOT__LESS_THAN));
        vcdp->fullBit(c+41,(vlTOPp->data_path__DOT__cpuALU__DOT__SIGNED_LESS_THAN));
        vcdp->fullBus(c+49,(vlTOPp->data_path__DOT__ALU_in1),32);
        vcdp->fullBus(c+57,(vlTOPp->data_path__DOT__ALU_in2),32);
        vcdp->fullBus(c+65,(vlTOPp->data_path__DOT__cpuALU__DOT__ALUoutput),32);
        vcdp->fullBus(c+73,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_0),32);
        vcdp->fullBus(c+81,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_1),32);
        vcdp->fullBus(c+89,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_2),32);
        vcdp->fullBus(c+97,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_3),32);
        vcdp->fullBus(c+105,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_4),32);
        vcdp->fullBus(c+113,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_5),32);
        vcdp->fullBus(c+121,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_6),32);
        vcdp->fullBus(c+129,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_7),32);
        vcdp->fullBus(c+137,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_8),32);
        vcdp->fullBus(c+145,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_9),32);
        vcdp->fullBus(c+153,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_10),32);
        vcdp->fullBus(c+161,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_11),32);
        vcdp->fullBus(c+169,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_12),32);
        vcdp->fullBus(c+177,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_13),32);
        vcdp->fullBus(c+185,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_14),32);
        vcdp->fullBus(c+193,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_15),32);
        vcdp->fullBus(c+201,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_16),32);
        vcdp->fullBus(c+209,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_17),32);
        vcdp->fullBus(c+217,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_18),32);
        vcdp->fullBus(c+225,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_19),32);
        vcdp->fullBus(c+233,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_20),32);
        vcdp->fullBus(c+241,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_21),32);
        vcdp->fullBus(c+249,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_22),32);
        vcdp->fullBus(c+257,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_23),32);
        vcdp->fullBus(c+265,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_24),32);
        vcdp->fullBus(c+273,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_25),32);
        vcdp->fullBus(c+281,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_26),32);
        vcdp->fullBus(c+289,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_27),32);
        vcdp->fullBus(c+297,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_28),32);
        vcdp->fullBus(c+305,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_29),32);
        vcdp->fullBus(c+313,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_30),32);
        vcdp->fullBus(c+321,(vlTOPp->data_path__DOT__registerFile__DOT__registerFile_31),32);
        vcdp->fullBit(c+329,(vlTOPp->clock));
        vcdp->fullBit(c+337,(vlTOPp->reset));
        vcdp->fullBus(c+345,(vlTOPp->io_RS1),5);
        vcdp->fullBus(c+353,(vlTOPp->io_RS2),5);
        vcdp->fullBus(c+361,(vlTOPp->io_RD),5);
        vcdp->fullBit(c+369,(vlTOPp->io_WRITE_EN));
        vcdp->fullBus(c+377,(vlTOPp->io_ALU_OP),4);
        vcdp->fullBit(c+385,(vlTOPp->io_EQUAL));
        vcdp->fullBit(c+393,(vlTOPp->io_LESS_THAN));
        vcdp->fullBit(c+401,(vlTOPp->io_SIGNED_LESS_THAN));
        vcdp->fullBus(c+409,(vlTOPp->io_store_data),32);
        vcdp->fullBus(c+417,(vlTOPp->io_store_address),32);
        vcdp->fullBus(c+425,(vlTOPp->io_load_data),32);
        vcdp->fullBus(c+433,(vlTOPp->io_load_address),32);
        vcdp->fullBit(c+441,(vlTOPp->io_CHOOSE_IMMEDIATE));
        vcdp->fullBit(c+449,(vlTOPp->io_CHOOSE_MEMORY_LOAD));
        vcdp->fullBus(c+457,(vlTOPp->io_IMMEDIATE),32);
        vcdp->fullBus(c+465,(vlTOPp->io_ALU_RD),5);
        vcdp->fullBus(c+473,(vlTOPp->io_instruction_return_address),32);
        vcdp->fullBus(c+481,(vlTOPp->io_instruction_next_address),32);
        vcdp->fullBit(c+489,(vlTOPp->io_PROCEDURE_BRANCHING));
        vcdp->fullBit(c+497,(vlTOPp->io_CHOOSE_PC));
        vcdp->fullBus(c+505,(vlTOPp->io_PC),32);
        vcdp->fullBus(c+513,(((0U == (IData)(vlTOPp->io_RS1))
                               ? 0U : ((0x1fU == (IData)(vlTOPp->io_RS1))
                                        ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_31
                                        : ((0x1eU == (IData)(vlTOPp->io_RS1))
                                            ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_30
                                            : ((0x1dU 
                                                == (IData)(vlTOPp->io_RS1))
                                                ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_29
                                                : (
                                                   (0x1cU 
                                                    == (IData)(vlTOPp->io_RS1))
                                                    ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_28
                                                    : 
                                                   ((0x1bU 
                                                     == (IData)(vlTOPp->io_RS1))
                                                     ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_27
                                                     : 
                                                    ((0x1aU 
                                                      == (IData)(vlTOPp->io_RS1))
                                                      ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_26
                                                      : 
                                                     ((0x19U 
                                                       == (IData)(vlTOPp->io_RS1))
                                                       ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_25
                                                       : 
                                                      ((0x18U 
                                                        == (IData)(vlTOPp->io_RS1))
                                                        ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_24
                                                        : 
                                                       ((0x17U 
                                                         == (IData)(vlTOPp->io_RS1))
                                                         ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_23
                                                         : 
                                                        ((0x16U 
                                                          == (IData)(vlTOPp->io_RS1))
                                                          ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_22
                                                          : vlTOPp->data_path__DOT__registerFile__DOT___GEN_21)))))))))))),32);
        vcdp->fullBus(c+521,(((0U == (IData)(vlTOPp->io_RS2))
                               ? 0U : ((0x1fU == (IData)(vlTOPp->io_RS2))
                                        ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_31
                                        : ((0x1eU == (IData)(vlTOPp->io_RS2))
                                            ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_30
                                            : ((0x1dU 
                                                == (IData)(vlTOPp->io_RS2))
                                                ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_29
                                                : (
                                                   (0x1cU 
                                                    == (IData)(vlTOPp->io_RS2))
                                                    ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_28
                                                    : 
                                                   ((0x1bU 
                                                     == (IData)(vlTOPp->io_RS2))
                                                     ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_27
                                                     : 
                                                    ((0x1aU 
                                                      == (IData)(vlTOPp->io_RS2))
                                                      ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_26
                                                      : 
                                                     ((0x19U 
                                                       == (IData)(vlTOPp->io_RS2))
                                                       ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_25
                                                       : 
                                                      ((0x18U 
                                                        == (IData)(vlTOPp->io_RS2))
                                                        ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_24
                                                        : 
                                                       ((0x17U 
                                                         == (IData)(vlTOPp->io_RS2))
                                                         ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_23
                                                         : 
                                                        ((0x16U 
                                                          == (IData)(vlTOPp->io_RS2))
                                                          ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_22
                                                          : vlTOPp->data_path__DOT__registerFile__DOT___GEN_54)))))))))))),32);
        vcdp->fullBus(c+529,((((IData)(vlTOPp->io_RS1) 
                               == (IData)(vlTOPp->io_ALU_RD))
                               ? vlTOPp->data_path__DOT__cpuALU__DOT__ALUoutput
                               : ((0U == (IData)(vlTOPp->io_RS1))
                                   ? 0U : ((0x1fU == (IData)(vlTOPp->io_RS1))
                                            ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_31
                                            : ((0x1eU 
                                                == (IData)(vlTOPp->io_RS1))
                                                ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_30
                                                : (
                                                   (0x1dU 
                                                    == (IData)(vlTOPp->io_RS1))
                                                    ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_29
                                                    : 
                                                   ((0x1cU 
                                                     == (IData)(vlTOPp->io_RS1))
                                                     ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_28
                                                     : 
                                                    ((0x1bU 
                                                      == (IData)(vlTOPp->io_RS1))
                                                      ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_27
                                                      : 
                                                     ((0x1aU 
                                                       == (IData)(vlTOPp->io_RS1))
                                                       ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_26
                                                       : 
                                                      ((0x19U 
                                                        == (IData)(vlTOPp->io_RS1))
                                                        ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_25
                                                        : 
                                                       ((0x18U 
                                                         == (IData)(vlTOPp->io_RS1))
                                                         ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_24
                                                         : 
                                                        ((0x17U 
                                                          == (IData)(vlTOPp->io_RS1))
                                                          ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_23
                                                          : 
                                                         ((0x16U 
                                                           == (IData)(vlTOPp->io_RS1))
                                                           ? vlTOPp->data_path__DOT__registerFile__DOT__registerFile_22
                                                           : vlTOPp->data_path__DOT__registerFile__DOT___GEN_21))))))))))))),32);
        vcdp->fullBus(c+537,((((IData)(vlTOPp->io_RS2) 
                               == (IData)(vlTOPp->io_RD))
                               ? vlTOPp->data_path__DOT__rdData
                               : vlTOPp->data_path__DOT__rs2_ALU)),32);
        vcdp->fullBit(c+545,(vlTOPp->data_path__DOT__registerFile__DOT__reset));
    }
}
