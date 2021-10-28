// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vcore_robin__Syms.h"


//======================

void Vcore_robin::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback(&Vcore_robin::traceInit, &Vcore_robin::traceFull, &Vcore_robin::traceChg, this);
}
void Vcore_robin::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    Vcore_robin* t = (Vcore_robin*)userthis;
    Vcore_robin__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vcdp->scopeEscape(' ');
    t->traceInitThis(vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void Vcore_robin::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vcore_robin* t = (Vcore_robin*)userthis;
    Vcore_robin__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis(vlSymsp, vcdp, code);
}

//======================


void Vcore_robin::traceInitThis(Vcore_robin__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vcore_robin* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
        vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void Vcore_robin::traceFullThis(Vcore_robin__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vcore_robin* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vcore_robin::traceInitThis__1(Vcore_robin__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vcore_robin* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->declBit(c+769,"clock", false,-1);
        vcdp->declBit(c+777,"reset", false,-1);
        vcdp->declBus(c+785,"io_INSTRUCTION", false,-1, 31,0);
        vcdp->declBit(c+793,"io_RECIEVED", false,-1);
        vcdp->declBit(c+801,"io_INSTRUCTION_LOADED", false,-1);
        vcdp->declBus(c+809,"io_PC", false,-1, 31,0);
        vcdp->declBus(c+817,"io_rdAddr", false,-1, 31,0);
        vcdp->declBus(c+825,"io_rdData", false,-1, 7,0);
        vcdp->declBit(c+833,"io_mem_write", false,-1);
        vcdp->declBus(c+841,"io_mem_write_data", false,-1, 7,0);
        vcdp->declBus(c+849,"io_mem_write_address", false,-1, 31,0);
        vcdp->declBit(c+769,"core_robin clock", false,-1);
        vcdp->declBit(c+777,"core_robin reset", false,-1);
        vcdp->declBus(c+785,"core_robin io_INSTRUCTION", false,-1, 31,0);
        vcdp->declBit(c+793,"core_robin io_RECIEVED", false,-1);
        vcdp->declBit(c+801,"core_robin io_INSTRUCTION_LOADED", false,-1);
        vcdp->declBus(c+809,"core_robin io_PC", false,-1, 31,0);
        vcdp->declBus(c+817,"core_robin io_rdAddr", false,-1, 31,0);
        vcdp->declBus(c+825,"core_robin io_rdData", false,-1, 7,0);
        vcdp->declBit(c+833,"core_robin io_mem_write", false,-1);
        vcdp->declBus(c+841,"core_robin io_mem_write_data", false,-1, 7,0);
        vcdp->declBus(c+849,"core_robin io_mem_write_address", false,-1, 31,0);
        vcdp->declBit(c+769,"core_robin controlStore_clock", false,-1);
        vcdp->declBit(c+777,"core_robin controlStore_reset", false,-1);
        vcdp->declBus(c+785,"core_robin controlStore_io_INSTRUCTION", false,-1, 31,0);
        vcdp->declBit(c+193,"core_robin controlStore_io_RECIEVED", false,-1);
        vcdp->declBit(c+801,"core_robin controlStore_io_INSTRUCTION_LOADED", false,-1);
        vcdp->declBus(c+185,"core_robin controlStore_io_RS1", false,-1, 4,0);
        vcdp->declBus(c+1,"core_robin controlStore_io_RS2", false,-1, 4,0);
        vcdp->declBus(c+9,"core_robin controlStore_io_RD", false,-1, 4,0);
        vcdp->declBit(c+17,"core_robin controlStore_io_WRITE_EN", false,-1);
        vcdp->declBus(c+25,"core_robin controlStore_io_ALU_OP", false,-1, 3,0);
        vcdp->declBit(c+33,"core_robin controlStore_io_PROCEDURE_BRANCHING", false,-1);
        vcdp->declBit(c+201,"core_robin controlStore_io_CHOOSE_IMMEDIATE", false,-1);
        vcdp->declBit(c+41,"core_robin controlStore_io_CHOOSE_MEMORY_LOAD", false,-1);
        vcdp->declBus(c+49,"core_robin controlStore_io_IMMEDIATE", false,-1, 31,0);
        vcdp->declBus(c+57,"core_robin controlStore_io_BRANCH_IMMEDIATE", false,-1, 31,0);
        vcdp->declBit(c+209,"core_robin controlStore_io_STORE_READY", false,-1);
        vcdp->declBit(c+65,"core_robin controlStore_io_DATA_IN", false,-1);
        vcdp->declBus(c+217,"core_robin controlStore_io_STORE_SIZE", false,-1, 1,0);
        vcdp->declBit(c+73,"core_robin controlStore_io_STORE_ADDRESS_IN", false,-1);
        vcdp->declBus(c+81,"core_robin controlStore_io_BRANCH_SELECT", false,-1, 1,0);
        vcdp->declBit(c+225,"core_robin controlStore_io_BRANCH_CONDITION", false,-1);
        vcdp->declBit(c+233,"core_robin controlStore_io_BRANCH_ADDRESS_SOURCE_ALU", false,-1);
        vcdp->declBit(c+241,"core_robin controlStore_io_UPDATE_PC", false,-1);
        vcdp->declBit(c+249,"core_robin controlStore_io_CHOOSE_PC", false,-1);
        vcdp->declBit(c+769,"core_robin dataPath_clock", false,-1);
        vcdp->declBit(c+777,"core_robin dataPath_reset", false,-1);
        vcdp->declBus(c+185,"core_robin dataPath_io_RS1", false,-1, 4,0);
        vcdp->declBus(c+1,"core_robin dataPath_io_RS2", false,-1, 4,0);
        vcdp->declBus(c+9,"core_robin dataPath_io_RD", false,-1, 4,0);
        vcdp->declBit(c+17,"core_robin dataPath_io_WRITE_EN", false,-1);
        vcdp->declBus(c+25,"core_robin dataPath_io_ALU_OP", false,-1, 3,0);
        vcdp->declBit(c+257,"core_robin dataPath_io_EQUAL", false,-1);
        vcdp->declBit(c+265,"core_robin dataPath_io_LESS_THAN", false,-1);
        vcdp->declBit(c+273,"core_robin dataPath_io_SIGNED_LESS_THAN", false,-1);
        vcdp->declBus(c+89,"core_robin dataPath_io_store_data", false,-1, 31,0);
        vcdp->declBus(c+281,"core_robin dataPath_io_store_address", false,-1, 31,0);
        vcdp->declBit(c+201,"core_robin dataPath_io_CHOOSE_IMMEDIATE", false,-1);
        vcdp->declBit(c+41,"core_robin dataPath_io_CHOOSE_MEMORY_LOAD", false,-1);
        vcdp->declBus(c+49,"core_robin dataPath_io_IMMEDIATE", false,-1, 31,0);
        vcdp->declBus(c+289,"core_robin dataPath_io_instruction_return_address", false,-1, 31,0);
        vcdp->declBus(c+281,"core_robin dataPath_io_instruction_next_address", false,-1, 31,0);
        vcdp->declBit(c+33,"core_robin dataPath_io_PROCEDURE_BRANCHING", false,-1);
        vcdp->declBit(c+249,"core_robin dataPath_io_CHOOSE_PC", false,-1);
        vcdp->declBus(c+297,"core_robin dataPath_io_PC", false,-1, 31,0);
        vcdp->declBit(c+769,"core_robin storeUnit_clock", false,-1);
        vcdp->declBit(c+777,"core_robin storeUnit_reset", false,-1);
        vcdp->declBus(c+305,"core_robin storeUnit_io_mem_write_data", false,-1, 7,0);
        vcdp->declBus(c+313,"core_robin storeUnit_io_mem_write_address", false,-1, 31,0);
        vcdp->declBit(c+321,"core_robin storeUnit_io_mem_write", false,-1);
        vcdp->declBit(c+209,"core_robin storeUnit_io_STORE_READY", false,-1);
        vcdp->declBit(c+65,"core_robin storeUnit_io_DATA_IN", false,-1);
        vcdp->declBus(c+217,"core_robin storeUnit_io_STORE_SIZE", false,-1, 1,0);
        vcdp->declBit(c+73,"core_robin storeUnit_io_ADDRESS_IN", false,-1);
        vcdp->declBus(c+89,"core_robin storeUnit_io_store_data", false,-1, 31,0);
        vcdp->declBus(c+281,"core_robin storeUnit_io_store_address", false,-1, 31,0);
        vcdp->declBus(c+297,"core_robin PC", false,-1, 31,0);
        vcdp->declBus(c+289,"core_robin noBranchNextAddr", false,-1, 31,0);
        vcdp->declBus(c+97,"core_robin branchImmBranchAddr", false,-1, 31,0);
        vcdp->declBit(c+105,"core_robin lessThanGreaterThanALUResult", false,-1);
        vcdp->declBit(c+113,"core_robin branchCheck", false,-1);
        vcdp->declBit(c+121,"core_robin conditionalBranching", false,-1);
        vcdp->declBit(c+769,"core_robin controlStore clock", false,-1);
        vcdp->declBit(c+777,"core_robin controlStore reset", false,-1);
        vcdp->declBus(c+785,"core_robin controlStore io_INSTRUCTION", false,-1, 31,0);
        vcdp->declBit(c+193,"core_robin controlStore io_RECIEVED", false,-1);
        vcdp->declBit(c+801,"core_robin controlStore io_INSTRUCTION_LOADED", false,-1);
        vcdp->declBus(c+185,"core_robin controlStore io_RS1", false,-1, 4,0);
        vcdp->declBus(c+1,"core_robin controlStore io_RS2", false,-1, 4,0);
        vcdp->declBus(c+9,"core_robin controlStore io_RD", false,-1, 4,0);
        vcdp->declBit(c+17,"core_robin controlStore io_WRITE_EN", false,-1);
        vcdp->declBus(c+25,"core_robin controlStore io_ALU_OP", false,-1, 3,0);
        vcdp->declBit(c+33,"core_robin controlStore io_PROCEDURE_BRANCHING", false,-1);
        vcdp->declBit(c+201,"core_robin controlStore io_CHOOSE_IMMEDIATE", false,-1);
        vcdp->declBit(c+41,"core_robin controlStore io_CHOOSE_MEMORY_LOAD", false,-1);
        vcdp->declBus(c+49,"core_robin controlStore io_IMMEDIATE", false,-1, 31,0);
        vcdp->declBus(c+57,"core_robin controlStore io_BRANCH_IMMEDIATE", false,-1, 31,0);
        vcdp->declBit(c+209,"core_robin controlStore io_STORE_READY", false,-1);
        vcdp->declBit(c+65,"core_robin controlStore io_DATA_IN", false,-1);
        vcdp->declBus(c+217,"core_robin controlStore io_STORE_SIZE", false,-1, 1,0);
        vcdp->declBit(c+73,"core_robin controlStore io_STORE_ADDRESS_IN", false,-1);
        vcdp->declBus(c+81,"core_robin controlStore io_BRANCH_SELECT", false,-1, 1,0);
        vcdp->declBit(c+225,"core_robin controlStore io_BRANCH_CONDITION", false,-1);
        vcdp->declBit(c+233,"core_robin controlStore io_BRANCH_ADDRESS_SOURCE_ALU", false,-1);
        vcdp->declBit(c+241,"core_robin controlStore io_UPDATE_PC", false,-1);
        vcdp->declBit(c+249,"core_robin controlStore io_CHOOSE_PC", false,-1);
        vcdp->declBus(c+329,"core_robin controlStore stateReg", false,-1, 2,0);
        vcdp->declBus(c+337,"core_robin controlStore stallState", false,-1, 2,0);
        vcdp->declBus(c+345,"core_robin controlStore instruction", false,-1, 31,0);
        vcdp->declBit(c+193,"core_robin controlStore RECIEVED", false,-1);
        vcdp->declBit(c+353,"core_robin controlStore STORE_READY", false,-1);
        vcdp->declBit(c+361,"core_robin controlStore LOAD_READY", false,-1);
        vcdp->declBus(c+369,"core_robin controlStore hi", false,-1, 6,0);
        vcdp->declBus(c+377,"core_robin controlStore lo", false,-1, 4,0);
        vcdp->declBit(c+385,"core_robin controlStore hi_1", false,-1);
        vcdp->declBus(c+393,"core_robin controlStore lo_1", false,-1, 2,0);
        vcdp->declBit(c+401,"core_robin controlStore hi_3", false,-1);
        vcdp->declBit(c+409,"core_robin controlStore lo_3", false,-1);
        vcdp->declBus(c+417,"core_robin controlStore hi_5", false,-1, 5,0);
        vcdp->declBus(c+425,"core_robin controlStore lo_4", false,-1, 3,0);
        vcdp->declBus(c+433,"core_robin controlStore lo_6", false,-1, 7,0);
        vcdp->declBit(c+441,"core_robin controlStore hi_9", false,-1);
        vcdp->declBus(c+449,"core_robin controlStore lo_7", false,-1, 9,0);
        vcdp->declBit(c+769,"core_robin dataPath clock", false,-1);
        vcdp->declBit(c+777,"core_robin dataPath reset", false,-1);
        vcdp->declBus(c+185,"core_robin dataPath io_RS1", false,-1, 4,0);
        vcdp->declBus(c+1,"core_robin dataPath io_RS2", false,-1, 4,0);
        vcdp->declBus(c+9,"core_robin dataPath io_RD", false,-1, 4,0);
        vcdp->declBit(c+17,"core_robin dataPath io_WRITE_EN", false,-1);
        vcdp->declBus(c+25,"core_robin dataPath io_ALU_OP", false,-1, 3,0);
        vcdp->declBit(c+257,"core_robin dataPath io_EQUAL", false,-1);
        vcdp->declBit(c+265,"core_robin dataPath io_LESS_THAN", false,-1);
        vcdp->declBit(c+273,"core_robin dataPath io_SIGNED_LESS_THAN", false,-1);
        vcdp->declBus(c+89,"core_robin dataPath io_store_data", false,-1, 31,0);
        vcdp->declBus(c+281,"core_robin dataPath io_store_address", false,-1, 31,0);
        vcdp->declBit(c+201,"core_robin dataPath io_CHOOSE_IMMEDIATE", false,-1);
        vcdp->declBit(c+41,"core_robin dataPath io_CHOOSE_MEMORY_LOAD", false,-1);
        vcdp->declBus(c+49,"core_robin dataPath io_IMMEDIATE", false,-1, 31,0);
        vcdp->declBus(c+289,"core_robin dataPath io_instruction_return_address", false,-1, 31,0);
        vcdp->declBus(c+281,"core_robin dataPath io_instruction_next_address", false,-1, 31,0);
        vcdp->declBit(c+33,"core_robin dataPath io_PROCEDURE_BRANCHING", false,-1);
        vcdp->declBit(c+249,"core_robin dataPath io_CHOOSE_PC", false,-1);
        vcdp->declBus(c+297,"core_robin dataPath io_PC", false,-1, 31,0);
        vcdp->declBit(c+769,"core_robin dataPath cpuALU_clock", false,-1);
        vcdp->declBit(c+777,"core_robin dataPath cpuALU_reset", false,-1);
        vcdp->declBus(c+25,"core_robin dataPath cpuALU_io_ALU_OP", false,-1, 3,0);
        vcdp->declBit(c+257,"core_robin dataPath cpuALU_io_EQUAL", false,-1);
        vcdp->declBit(c+265,"core_robin dataPath cpuALU_io_LESS_THAN", false,-1);
        vcdp->declBit(c+273,"core_robin dataPath cpuALU_io_SIGNED_LESS_THAN", false,-1);
        vcdp->declBus(c+457,"core_robin dataPath cpuALU_io_ALUinput1", false,-1, 31,0);
        vcdp->declBus(c+465,"core_robin dataPath cpuALU_io_ALUinput2", false,-1, 31,0);
        vcdp->declBus(c+281,"core_robin dataPath cpuALU_io_ALUoutput", false,-1, 31,0);
        vcdp->declBit(c+769,"core_robin dataPath registerFile_clock", false,-1);
        vcdp->declBus(c+185,"core_robin dataPath registerFile_io_RS1", false,-1, 4,0);
        vcdp->declBus(c+1,"core_robin dataPath registerFile_io_RS2", false,-1, 4,0);
        vcdp->declBus(c+9,"core_robin dataPath registerFile_io_RD", false,-1, 4,0);
        vcdp->declBit(c+17,"core_robin dataPath registerFile_io_WRITE_EN", false,-1);
        vcdp->declBus(c+169,"core_robin dataPath registerFile_io_rs1Data", false,-1, 31,0);
        vcdp->declBus(c+129,"core_robin dataPath registerFile_io_rs2Data", false,-1, 31,0);
        vcdp->declBus(c+137,"core_robin dataPath registerFile_io_rdData", false,-1, 31,0);
        vcdp->declBus(c+457,"core_robin dataPath ALU_in1", false,-1, 31,0);
        vcdp->declBus(c+465,"core_robin dataPath ALU_in2", false,-1, 31,0);
        vcdp->declBus(c+145,"core_robin dataPath rdData", false,-1, 31,0);
        vcdp->declBus(c+177,"core_robin dataPath rs1_ALU", false,-1, 31,0);
        vcdp->declBus(c+153,"core_robin dataPath rs2_ALU", false,-1, 31,0);
        vcdp->declBus(c+161,"core_robin dataPath rs2_ALU_rd", false,-1, 31,0);
        vcdp->declBit(c+769,"core_robin dataPath cpuALU clock", false,-1);
        vcdp->declBit(c+777,"core_robin dataPath cpuALU reset", false,-1);
        vcdp->declBus(c+25,"core_robin dataPath cpuALU io_ALU_OP", false,-1, 3,0);
        vcdp->declBit(c+257,"core_robin dataPath cpuALU io_EQUAL", false,-1);
        vcdp->declBit(c+265,"core_robin dataPath cpuALU io_LESS_THAN", false,-1);
        vcdp->declBit(c+273,"core_robin dataPath cpuALU io_SIGNED_LESS_THAN", false,-1);
        vcdp->declBus(c+457,"core_robin dataPath cpuALU io_ALUinput1", false,-1, 31,0);
        vcdp->declBus(c+465,"core_robin dataPath cpuALU io_ALUinput2", false,-1, 31,0);
        vcdp->declBus(c+281,"core_robin dataPath cpuALU io_ALUoutput", false,-1, 31,0);
        vcdp->declBus(c+281,"core_robin dataPath cpuALU ALUoutput", false,-1, 31,0);
        vcdp->declBit(c+257,"core_robin dataPath cpuALU EQUAL", false,-1);
        vcdp->declBit(c+265,"core_robin dataPath cpuALU LESS_THAN", false,-1);
        vcdp->declBit(c+273,"core_robin dataPath cpuALU SIGNED_LESS_THAN", false,-1);
        vcdp->declBit(c+769,"core_robin dataPath registerFile clock", false,-1);
        vcdp->declBus(c+185,"core_robin dataPath registerFile io_RS1", false,-1, 4,0);
        vcdp->declBus(c+1,"core_robin dataPath registerFile io_RS2", false,-1, 4,0);
        vcdp->declBus(c+9,"core_robin dataPath registerFile io_RD", false,-1, 4,0);
        vcdp->declBit(c+17,"core_robin dataPath registerFile io_WRITE_EN", false,-1);
        vcdp->declBus(c+169,"core_robin dataPath registerFile io_rs1Data", false,-1, 31,0);
        vcdp->declBus(c+129,"core_robin dataPath registerFile io_rs2Data", false,-1, 31,0);
        vcdp->declBus(c+137,"core_robin dataPath registerFile io_rdData", false,-1, 31,0);
        vcdp->declBus(c+473,"core_robin dataPath registerFile registerFile_0", false,-1, 31,0);
        vcdp->declBus(c+481,"core_robin dataPath registerFile registerFile_1", false,-1, 31,0);
        vcdp->declBus(c+489,"core_robin dataPath registerFile registerFile_2", false,-1, 31,0);
        vcdp->declBus(c+497,"core_robin dataPath registerFile registerFile_3", false,-1, 31,0);
        vcdp->declBus(c+505,"core_robin dataPath registerFile registerFile_4", false,-1, 31,0);
        vcdp->declBus(c+513,"core_robin dataPath registerFile registerFile_5", false,-1, 31,0);
        vcdp->declBus(c+521,"core_robin dataPath registerFile registerFile_6", false,-1, 31,0);
        vcdp->declBus(c+529,"core_robin dataPath registerFile registerFile_7", false,-1, 31,0);
        vcdp->declBus(c+537,"core_robin dataPath registerFile registerFile_8", false,-1, 31,0);
        vcdp->declBus(c+545,"core_robin dataPath registerFile registerFile_9", false,-1, 31,0);
        vcdp->declBus(c+553,"core_robin dataPath registerFile registerFile_10", false,-1, 31,0);
        vcdp->declBus(c+561,"core_robin dataPath registerFile registerFile_11", false,-1, 31,0);
        vcdp->declBus(c+569,"core_robin dataPath registerFile registerFile_12", false,-1, 31,0);
        vcdp->declBus(c+577,"core_robin dataPath registerFile registerFile_13", false,-1, 31,0);
        vcdp->declBus(c+585,"core_robin dataPath registerFile registerFile_14", false,-1, 31,0);
        vcdp->declBus(c+593,"core_robin dataPath registerFile registerFile_15", false,-1, 31,0);
        vcdp->declBus(c+601,"core_robin dataPath registerFile registerFile_16", false,-1, 31,0);
        vcdp->declBus(c+609,"core_robin dataPath registerFile registerFile_17", false,-1, 31,0);
        vcdp->declBus(c+617,"core_robin dataPath registerFile registerFile_18", false,-1, 31,0);
        vcdp->declBus(c+625,"core_robin dataPath registerFile registerFile_19", false,-1, 31,0);
        vcdp->declBus(c+633,"core_robin dataPath registerFile registerFile_20", false,-1, 31,0);
        vcdp->declBus(c+641,"core_robin dataPath registerFile registerFile_21", false,-1, 31,0);
        vcdp->declBus(c+649,"core_robin dataPath registerFile registerFile_22", false,-1, 31,0);
        vcdp->declBus(c+657,"core_robin dataPath registerFile registerFile_23", false,-1, 31,0);
        vcdp->declBus(c+665,"core_robin dataPath registerFile registerFile_24", false,-1, 31,0);
        vcdp->declBus(c+673,"core_robin dataPath registerFile registerFile_25", false,-1, 31,0);
        vcdp->declBus(c+681,"core_robin dataPath registerFile registerFile_26", false,-1, 31,0);
        vcdp->declBus(c+689,"core_robin dataPath registerFile registerFile_27", false,-1, 31,0);
        vcdp->declBus(c+697,"core_robin dataPath registerFile registerFile_28", false,-1, 31,0);
        vcdp->declBus(c+705,"core_robin dataPath registerFile registerFile_29", false,-1, 31,0);
        vcdp->declBus(c+713,"core_robin dataPath registerFile registerFile_30", false,-1, 31,0);
        vcdp->declBus(c+721,"core_robin dataPath registerFile registerFile_31", false,-1, 31,0);
        vcdp->declBit(c+769,"core_robin storeUnit clock", false,-1);
        vcdp->declBit(c+777,"core_robin storeUnit reset", false,-1);
        vcdp->declBus(c+305,"core_robin storeUnit io_mem_write_data", false,-1, 7,0);
        vcdp->declBus(c+313,"core_robin storeUnit io_mem_write_address", false,-1, 31,0);
        vcdp->declBit(c+321,"core_robin storeUnit io_mem_write", false,-1);
        vcdp->declBit(c+209,"core_robin storeUnit io_STORE_READY", false,-1);
        vcdp->declBit(c+65,"core_robin storeUnit io_DATA_IN", false,-1);
        vcdp->declBus(c+217,"core_robin storeUnit io_STORE_SIZE", false,-1, 1,0);
        vcdp->declBit(c+73,"core_robin storeUnit io_ADDRESS_IN", false,-1);
        vcdp->declBus(c+89,"core_robin storeUnit io_store_data", false,-1, 31,0);
        vcdp->declBus(c+281,"core_robin storeUnit io_store_address", false,-1, 31,0);
        vcdp->declBus(c+729,"core_robin storeUnit store_data_buffer", false,-1, 31,0);
        vcdp->declBus(c+737,"core_robin storeUnit store_data_size_buffer", false,-1, 1,0);
        vcdp->declBus(c+745,"core_robin storeUnit store_data_buffer_address", false,-1, 31,0);
        vcdp->declBit(c+321,"core_robin storeUnit storing", false,-1);
        vcdp->declBit(c+753,"core_robin storeUnit stateReg", false,-1);
        vcdp->declBus(c+761,"core_robin storeUnit lo", false,-1, 23,0);
    }
}

void Vcore_robin::traceFullThis__1(Vcore_robin__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vcore_robin* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->fullBus(c+1,(vlTOPp->core_robin__DOT__controlStore_io_RS2),5);
        vcdp->fullBus(c+9,(vlTOPp->core_robin__DOT__controlStore_io_RD),5);
        vcdp->fullBit(c+17,(vlTOPp->core_robin__DOT__controlStore_io_WRITE_EN));
        vcdp->fullBus(c+25,(vlTOPp->core_robin__DOT__controlStore_io_ALU_OP),4);
        vcdp->fullBit(c+33,(vlTOPp->core_robin__DOT__controlStore_io_PROCEDURE_BRANCHING));
        vcdp->fullBit(c+41,(((0U != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                             & ((1U != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                                & ((2U != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                                   & ((3U != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                                      & (IData)(vlTOPp->core_robin__DOT__controlStore__DOT___GEN_34)))))));
        vcdp->fullBus(c+49,(((0U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                              ? 0U : ((1U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                                       ? ((0x37U == 
                                           (0x7fU & vlTOPp->core_robin__DOT__controlStore__DOT__instruction))
                                           ? (0xfffff000U 
                                              & vlTOPp->core_robin__DOT__controlStore__DOT__instruction)
                                           : ((0xfffff000U 
                                               & (VL_NEGATE_I((IData)(
                                                                      (1U 
                                                                       & ((IData)(vlTOPp->core_robin__DOT__controlStore__DOT___T_18) 
                                                                          >> 0xbU)))) 
                                                  << 0xcU)) 
                                              | (IData)(vlTOPp->core_robin__DOT__controlStore__DOT___T_18)))
                                       : 0U))),32);
        vcdp->fullBus(c+57,(((0U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                              ? 0U : ((1U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                                       ? 0U : ((2U 
                                                == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                                                ? (
                                                   (0x63U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->core_robin__DOT__controlStore__DOT__instruction))
                                                    ? 
                                                   ((0x80000000U 
                                                     & vlTOPp->core_robin__DOT__controlStore__DOT__instruction)
                                                     ? 
                                                    (0xffffe000U 
                                                     | (IData)(vlTOPp->core_robin__DOT__controlStore__DOT___T_55))
                                                     : (IData)(vlTOPp->core_robin__DOT__controlStore__DOT___T_55))
                                                    : 
                                                   ((0x80000000U 
                                                     & vlTOPp->core_robin__DOT__controlStore__DOT__instruction)
                                                     ? 
                                                    (0xffe00000U 
                                                     | vlTOPp->core_robin__DOT__controlStore__DOT___T_56)
                                                     : vlTOPp->core_robin__DOT__controlStore__DOT___T_56))
                                                : 0U)))),32);
        vcdp->fullBit(c+65,(vlTOPp->core_robin__DOT__controlStore_io_DATA_IN));
        vcdp->fullBit(c+73,(vlTOPp->core_robin__DOT__controlStore_io_STORE_ADDRESS_IN));
        vcdp->fullBus(c+81,(vlTOPp->core_robin__DOT__controlStore_io_BRANCH_SELECT),2);
        vcdp->fullBus(c+89,(((0U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                              ? 0U : (((IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2) 
                                       == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD))
                                       ? vlTOPp->core_robin__DOT__dataPath__DOT__rdData
                                       : vlTOPp->core_robin__DOT__dataPath__DOT__rs2_ALU))),32);
        vcdp->fullBus(c+97,((vlTOPp->core_robin__DOT__PC 
                             + ((0U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                                 ? 0U : ((1U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                                          ? 0U : ((2U 
                                                   == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                                                   ? 
                                                  ((0x63U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->core_robin__DOT__controlStore__DOT__instruction))
                                                    ? 
                                                   ((0x80000000U 
                                                     & vlTOPp->core_robin__DOT__controlStore__DOT__instruction)
                                                     ? 
                                                    (0xffffe000U 
                                                     | (IData)(vlTOPp->core_robin__DOT__controlStore__DOT___T_55))
                                                     : (IData)(vlTOPp->core_robin__DOT__controlStore__DOT___T_55))
                                                    : 
                                                   ((0x80000000U 
                                                     & vlTOPp->core_robin__DOT__controlStore__DOT__instruction)
                                                     ? 
                                                    (0xffe00000U 
                                                     | vlTOPp->core_robin__DOT__controlStore__DOT___T_56)
                                                     : vlTOPp->core_robin__DOT__controlStore__DOT___T_56))
                                                   : 0U))))),32);
        vcdp->fullBit(c+105,(((2U & (IData)(vlTOPp->core_robin__DOT__controlStore_io_BRANCH_SELECT))
                               ? (IData)(vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT__LESS_THAN)
                               : (IData)(vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT__SIGNED_LESS_THAN))));
        vcdp->fullBit(c+113,(((1U & (IData)(vlTOPp->core_robin__DOT__controlStore_io_BRANCH_SELECT))
                               ? ((2U & (IData)(vlTOPp->core_robin__DOT__controlStore_io_BRANCH_SELECT))
                                   ? (IData)(vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT__LESS_THAN)
                                   : (IData)(vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT__SIGNED_LESS_THAN))
                               : (IData)(vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT__EQUAL))));
        vcdp->fullBit(c+121,(((((1U & (IData)(vlTOPp->core_robin__DOT__controlStore_io_BRANCH_SELECT))
                                 ? ((2U & (IData)(vlTOPp->core_robin__DOT__controlStore_io_BRANCH_SELECT))
                                     ? (IData)(vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT__LESS_THAN)
                                     : (IData)(vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT__SIGNED_LESS_THAN))
                                 : (IData)(vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT__EQUAL)) 
                               & ((0U != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                                  & ((1U != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                                     & ((2U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                                        & ((0x63U == 
                                            (0x7fU 
                                             & vlTOPp->core_robin__DOT__controlStore__DOT__instruction)) 
                                           & (~ (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                                 >> 0xcU))))))) 
                              & (((IData)(vlTOPp->core_robin__DOT__controlStore_io_BRANCH_SELECT) 
                                  >> 1U) & (~ (IData)(vlTOPp->core_robin__DOT__controlStore_io_BRANCH_SELECT))))));
        vcdp->fullBus(c+129,(((0U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                               ? 0U : ((0x1fU == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                        ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_31
                                        : ((0x1eU == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                            ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_30
                                            : ((0x1dU 
                                                == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                                ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_29
                                                : (
                                                   (0x1cU 
                                                    == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                                    ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_28
                                                    : 
                                                   ((0x1bU 
                                                     == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                                     ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_27
                                                     : 
                                                    ((0x1aU 
                                                      == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                                      ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_26
                                                      : 
                                                     ((0x19U 
                                                       == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                                       ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_25
                                                       : 
                                                      ((0x18U 
                                                        == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                                        ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_24
                                                        : 
                                                       ((0x17U 
                                                         == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                                         ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_23
                                                         : 
                                                        ((0x16U 
                                                          == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2))
                                                          ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_22
                                                          : vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT___GEN_54)))))))))))),32);
        vcdp->fullBus(c+137,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile_io_rdData),32);
        vcdp->fullBus(c+145,(vlTOPp->core_robin__DOT__dataPath__DOT__rdData),32);
        vcdp->fullBus(c+153,(vlTOPp->core_robin__DOT__dataPath__DOT__rs2_ALU),32);
        vcdp->fullBus(c+161,((((IData)(vlTOPp->core_robin__DOT__controlStore_io_RS2) 
                               == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RD))
                               ? vlTOPp->core_robin__DOT__dataPath__DOT__rdData
                               : vlTOPp->core_robin__DOT__dataPath__DOT__rs2_ALU)),32);
        vcdp->fullBus(c+169,(((0U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                               ? 0U : ((0x1fU == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                        ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_31
                                        : ((0x1eU == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                            ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_30
                                            : ((0x1dU 
                                                == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                                ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_29
                                                : (
                                                   (0x1cU 
                                                    == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                                    ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_28
                                                    : 
                                                   ((0x1bU 
                                                     == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                                     ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_27
                                                     : 
                                                    ((0x1aU 
                                                      == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                                      ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_26
                                                      : 
                                                     ((0x19U 
                                                       == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                                       ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_25
                                                       : 
                                                      ((0x18U 
                                                        == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                                        ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_24
                                                        : 
                                                       ((0x17U 
                                                         == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                                         ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_23
                                                         : 
                                                        ((0x16U 
                                                          == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                                          ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_22
                                                          : vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT___GEN_21)))))))))))),32);
        vcdp->fullBus(c+177,(((0U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                               ? vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT__ALUoutput
                               : ((0U == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                   ? 0U : ((0x1fU == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                            ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_31
                                            : ((0x1eU 
                                                == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                                ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_30
                                                : (
                                                   (0x1dU 
                                                    == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                                    ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_29
                                                    : 
                                                   ((0x1cU 
                                                     == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                                     ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_28
                                                     : 
                                                    ((0x1bU 
                                                      == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                                      ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_27
                                                      : 
                                                     ((0x1aU 
                                                       == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                                       ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_26
                                                       : 
                                                      ((0x19U 
                                                        == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                                        ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_25
                                                        : 
                                                       ((0x18U 
                                                         == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                                         ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_24
                                                         : 
                                                        ((0x17U 
                                                          == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                                          ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_23
                                                          : 
                                                         ((0x16U 
                                                           == (IData)(vlTOPp->core_robin__DOT__controlStore_io_RS1))
                                                           ? vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_22
                                                           : vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT___GEN_21))))))))))))),32);
        vcdp->fullBus(c+185,(vlTOPp->core_robin__DOT__controlStore_io_RS1),5);
        vcdp->fullBit(c+193,(vlTOPp->core_robin__DOT__controlStore__DOT__RECIEVED));
        vcdp->fullBit(c+201,(((0U != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                              & ((1U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                                 & (~ ((0x33U == (0x7fU 
                                                  & vlTOPp->core_robin__DOT__controlStore__DOT__instruction)) 
                                       | (0x63U == 
                                          (0x7fU & vlTOPp->core_robin__DOT__controlStore__DOT__instruction))))))));
        vcdp->fullBit(c+209,((1U & (~ (IData)(vlTOPp->core_robin__DOT__storeUnit__DOT__stateReg)))));
        vcdp->fullBus(c+217,(((0U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                               ? 1U : ((1U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))
                                        ? ((0x23U == 
                                            (0x7fU 
                                             & vlTOPp->core_robin__DOT__controlStore__DOT__instruction))
                                            ? ((0x2000U 
                                                & vlTOPp->core_robin__DOT__controlStore__DOT__instruction)
                                                ? 0U
                                                : (3U 
                                                   & (~ 
                                                      (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                                       >> 0xcU))))
                                            : 1U) : 1U))),2);
        vcdp->fullBit(c+225,(((0U != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                              & ((1U != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                                 & ((2U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                                    & ((0x63U == (0x7fU 
                                                  & vlTOPp->core_robin__DOT__controlStore__DOT__instruction)) 
                                       & (~ (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                             >> 0xcU))))))));
        vcdp->fullBit(c+233,(((0U != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                              & ((1U != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                                 & ((2U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                                    & ((0x67U == (0x77U 
                                                  & vlTOPp->core_robin__DOT__controlStore__DOT__instruction)) 
                                       & (0x67U == 
                                          (0x7fU & vlTOPp->core_robin__DOT__controlStore__DOT__instruction))))))));
        vcdp->fullBit(c+241,(((0U != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                              & ((1U != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                                 & (2U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg))))));
        vcdp->fullBit(c+249,(((0U != (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                              & ((1U == (IData)(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg)) 
                                 & (0x17U == (0x7fU 
                                              & vlTOPp->core_robin__DOT__controlStore__DOT__instruction))))));
        vcdp->fullBit(c+257,(vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT__EQUAL));
        vcdp->fullBit(c+265,(vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT__LESS_THAN));
        vcdp->fullBit(c+273,(vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT__SIGNED_LESS_THAN));
        vcdp->fullBus(c+281,(vlTOPp->core_robin__DOT__dataPath__DOT__cpuALU__DOT__ALUoutput),32);
        vcdp->fullBus(c+289,(((IData)(4U) + vlTOPp->core_robin__DOT__PC)),32);
        vcdp->fullBus(c+297,(vlTOPp->core_robin__DOT__PC),32);
        vcdp->fullBus(c+305,(((IData)(vlTOPp->core_robin__DOT__storeUnit__DOT__storing)
                               ? (0xffU & vlTOPp->core_robin__DOT__storeUnit__DOT__store_data_buffer)
                               : 0U)),8);
        vcdp->fullBus(c+313,(((IData)(vlTOPp->core_robin__DOT__storeUnit__DOT__storing)
                               ? vlTOPp->core_robin__DOT__storeUnit__DOT__store_data_buffer_address
                               : 0U)),32);
        vcdp->fullBit(c+321,(vlTOPp->core_robin__DOT__storeUnit__DOT__storing));
        vcdp->fullBus(c+329,(vlTOPp->core_robin__DOT__controlStore__DOT__stateReg),3);
        vcdp->fullBus(c+337,(vlTOPp->core_robin__DOT__controlStore__DOT__stallState),3);
        vcdp->fullBus(c+345,(vlTOPp->core_robin__DOT__controlStore__DOT__instruction),32);
        vcdp->fullBit(c+353,(vlTOPp->core_robin__DOT__controlStore__DOT__STORE_READY));
        vcdp->fullBit(c+361,(vlTOPp->core_robin__DOT__controlStore__DOT__LOAD_READY));
        vcdp->fullBus(c+369,((0x7fU & (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                       >> 0x19U))),7);
        vcdp->fullBus(c+377,((0x1fU & (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                       >> 7U))),5);
        vcdp->fullBit(c+385,(((1U == (3U & (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                            >> 0xcU))) 
                              & (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                 >> 0x1eU))));
        vcdp->fullBus(c+393,((7U & (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                    >> 0xcU))),3);
        vcdp->fullBit(c+401,((1U & (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                    >> 0x1fU))));
        vcdp->fullBit(c+409,((1U & (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                    >> 7U))));
        vcdp->fullBus(c+417,((0x3fU & (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                       >> 0x19U))),6);
        vcdp->fullBus(c+425,((0xfU & (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                      >> 8U))),4);
        vcdp->fullBus(c+433,((0xffU & (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                       >> 0xcU))),8);
        vcdp->fullBit(c+441,((1U & (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                    >> 0x14U))));
        vcdp->fullBus(c+449,((0x3ffU & (vlTOPp->core_robin__DOT__controlStore__DOT__instruction 
                                        >> 0x15U))),10);
        vcdp->fullBus(c+457,(vlTOPp->core_robin__DOT__dataPath__DOT__ALU_in1),32);
        vcdp->fullBus(c+465,(vlTOPp->core_robin__DOT__dataPath__DOT__ALU_in2),32);
        vcdp->fullBus(c+473,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_0),32);
        vcdp->fullBus(c+481,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_1),32);
        vcdp->fullBus(c+489,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_2),32);
        vcdp->fullBus(c+497,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_3),32);
        vcdp->fullBus(c+505,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_4),32);
        vcdp->fullBus(c+513,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_5),32);
        vcdp->fullBus(c+521,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_6),32);
        vcdp->fullBus(c+529,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_7),32);
        vcdp->fullBus(c+537,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_8),32);
        vcdp->fullBus(c+545,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_9),32);
        vcdp->fullBus(c+553,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_10),32);
        vcdp->fullBus(c+561,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_11),32);
        vcdp->fullBus(c+569,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_12),32);
        vcdp->fullBus(c+577,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_13),32);
        vcdp->fullBus(c+585,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_14),32);
        vcdp->fullBus(c+593,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_15),32);
        vcdp->fullBus(c+601,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_16),32);
        vcdp->fullBus(c+609,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_17),32);
        vcdp->fullBus(c+617,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_18),32);
        vcdp->fullBus(c+625,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_19),32);
        vcdp->fullBus(c+633,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_20),32);
        vcdp->fullBus(c+641,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_21),32);
        vcdp->fullBus(c+649,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_22),32);
        vcdp->fullBus(c+657,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_23),32);
        vcdp->fullBus(c+665,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_24),32);
        vcdp->fullBus(c+673,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_25),32);
        vcdp->fullBus(c+681,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_26),32);
        vcdp->fullBus(c+689,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_27),32);
        vcdp->fullBus(c+697,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_28),32);
        vcdp->fullBus(c+705,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_29),32);
        vcdp->fullBus(c+713,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_30),32);
        vcdp->fullBus(c+721,(vlTOPp->core_robin__DOT__dataPath__DOT__registerFile__DOT__registerFile_31),32);
        vcdp->fullBus(c+729,(vlTOPp->core_robin__DOT__storeUnit__DOT__store_data_buffer),32);
        vcdp->fullBus(c+737,(vlTOPp->core_robin__DOT__storeUnit__DOT__store_data_size_buffer),2);
        vcdp->fullBus(c+745,(vlTOPp->core_robin__DOT__storeUnit__DOT__store_data_buffer_address),32);
        vcdp->fullBit(c+753,(vlTOPp->core_robin__DOT__storeUnit__DOT__stateReg));
        vcdp->fullBus(c+761,((0xffffffU & (vlTOPp->core_robin__DOT__storeUnit__DOT__store_data_buffer 
                                           >> 8U))),24);
        vcdp->fullBit(c+769,(vlTOPp->clock));
        vcdp->fullBit(c+777,(vlTOPp->reset));
        vcdp->fullBus(c+785,(vlTOPp->io_INSTRUCTION),32);
        vcdp->fullBit(c+793,(vlTOPp->io_RECIEVED));
        vcdp->fullBit(c+801,(vlTOPp->io_INSTRUCTION_LOADED));
        vcdp->fullBus(c+809,(vlTOPp->io_PC),32);
        vcdp->fullBus(c+817,(vlTOPp->io_rdAddr),32);
        vcdp->fullBus(c+825,(vlTOPp->io_rdData),8);
        vcdp->fullBit(c+833,(vlTOPp->io_mem_write));
        vcdp->fullBus(c+841,(vlTOPp->io_mem_write_data),8);
        vcdp->fullBus(c+849,(vlTOPp->io_mem_write_address),32);
    }
}
