// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtest_bench_robin_core_v2__Syms.h"


//======================

void Vtest_bench_robin_core_v2::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback(&Vtest_bench_robin_core_v2::traceInit, &Vtest_bench_robin_core_v2::traceFull, &Vtest_bench_robin_core_v2::traceChg, this);
}
void Vtest_bench_robin_core_v2::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    Vtest_bench_robin_core_v2* t = (Vtest_bench_robin_core_v2*)userthis;
    Vtest_bench_robin_core_v2__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vcdp->scopeEscape(' ');
    t->traceInitThis(vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void Vtest_bench_robin_core_v2::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vtest_bench_robin_core_v2* t = (Vtest_bench_robin_core_v2*)userthis;
    Vtest_bench_robin_core_v2__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis(vlSymsp, vcdp, code);
}

//======================


void Vtest_bench_robin_core_v2::traceInitThis(Vtest_bench_robin_core_v2__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtest_bench_robin_core_v2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
        vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void Vtest_bench_robin_core_v2::traceFullThis(Vtest_bench_robin_core_v2__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtest_bench_robin_core_v2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vtest_bench_robin_core_v2::traceInitThis__1(Vtest_bench_robin_core_v2__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtest_bench_robin_core_v2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->declBit(c+1113,"clock", false,-1);
        vcdp->declBit(c+1121,"reset", false,-1);
        vcdp->declBus(c+1129,"io_rdAddr", false,-1, 31,0);
        vcdp->declBus(c+1137,"io_rdData", false,-1, 7,0);
        vcdp->declBit(c+1145,"io_signal_mem_write_data", false,-1);
        vcdp->declBus(c+1153,"io_mem_write_data", false,-1, 7,0);
        vcdp->declBus(c+1161,"io_mem_write_address_data", false,-1, 31,0);
        vcdp->declBit(c+1169,"io_signal_mem_write_instruction", false,-1);
        vcdp->declBus(c+1177,"io_mem_write_instruction", false,-1, 31,0);
        vcdp->declBus(c+1185,"io_mem_write_address_instruction", false,-1, 31,0);
        vcdp->declBit(c+1193,"io_START_PROGRAM", false,-1);
        vcdp->declBit(c+1201,"io_outputSake", false,-1);
        vcdp->declBit(c+1209,"io_out_mem_write", false,-1);
        vcdp->declBus(c+1217,"io_out_mem_write_data", false,-1, 7,0);
        vcdp->declBus(c+1225,"io_out_mem_write_address", false,-1, 31,0);
        vcdp->declBus(c+1233,"io_INSTRUCTION", false,-1, 31,0);
        vcdp->declBus(c+1241,"io_PC", false,-1, 31,0);
        vcdp->declBit(c+1113,"test_bench_robin_core_v2 clock", false,-1);
        vcdp->declBit(c+1121,"test_bench_robin_core_v2 reset", false,-1);
        vcdp->declBus(c+1129,"test_bench_robin_core_v2 io_rdAddr", false,-1, 31,0);
        vcdp->declBus(c+1137,"test_bench_robin_core_v2 io_rdData", false,-1, 7,0);
        vcdp->declBit(c+1145,"test_bench_robin_core_v2 io_signal_mem_write_data", false,-1);
        vcdp->declBus(c+1153,"test_bench_robin_core_v2 io_mem_write_data", false,-1, 7,0);
        vcdp->declBus(c+1161,"test_bench_robin_core_v2 io_mem_write_address_data", false,-1, 31,0);
        vcdp->declBit(c+1169,"test_bench_robin_core_v2 io_signal_mem_write_instruction", false,-1);
        vcdp->declBus(c+1177,"test_bench_robin_core_v2 io_mem_write_instruction", false,-1, 31,0);
        vcdp->declBus(c+1185,"test_bench_robin_core_v2 io_mem_write_address_instruction", false,-1, 31,0);
        vcdp->declBit(c+1193,"test_bench_robin_core_v2 io_START_PROGRAM", false,-1);
        vcdp->declBit(c+1201,"test_bench_robin_core_v2 io_outputSake", false,-1);
        vcdp->declBit(c+1209,"test_bench_robin_core_v2 io_out_mem_write", false,-1);
        vcdp->declBus(c+1217,"test_bench_robin_core_v2 io_out_mem_write_data", false,-1, 7,0);
        vcdp->declBus(c+1225,"test_bench_robin_core_v2 io_out_mem_write_address", false,-1, 31,0);
        vcdp->declBus(c+1233,"test_bench_robin_core_v2 io_INSTRUCTION", false,-1, 31,0);
        vcdp->declBus(c+1241,"test_bench_robin_core_v2 io_PC", false,-1, 31,0);
        vcdp->declBit(c+1113,"test_bench_robin_core_v2 memoryData_clock", false,-1);
        vcdp->declBus(c+289,"test_bench_robin_core_v2 memoryData_io_rdAddr", false,-1, 31,0);
        vcdp->declBus(c+1,"test_bench_robin_core_v2 memoryData_io_rdData", false,-1, 7,0);
        vcdp->declBit(c+297,"test_bench_robin_core_v2 memoryData_io_mem_write", false,-1);
        vcdp->declBus(c+305,"test_bench_robin_core_v2 memoryData_io_mem_write_data", false,-1, 7,0);
        vcdp->declBus(c+313,"test_bench_robin_core_v2 memoryData_io_mem_write_address", false,-1, 31,0);
        vcdp->declBit(c+1113,"test_bench_robin_core_v2 memoryInstruction_clock", false,-1);
        vcdp->declBus(c+329,"test_bench_robin_core_v2 memoryInstruction_io_rdAddr", false,-1, 31,0);
        vcdp->declBus(c+9,"test_bench_robin_core_v2 memoryInstruction_io_rdData", false,-1, 31,0);
        vcdp->declBit(c+1169,"test_bench_robin_core_v2 memoryInstruction_io_mem_write", false,-1);
        vcdp->declBus(c+1177,"test_bench_robin_core_v2 memoryInstruction_io_mem_write_data", false,-1, 31,0);
        vcdp->declBus(c+1185,"test_bench_robin_core_v2 memoryInstruction_io_mem_write_address", false,-1, 31,0);
        vcdp->declBit(c+1113,"test_bench_robin_core_v2 robinCore_clock", false,-1);
        vcdp->declBit(c+1121,"test_bench_robin_core_v2 robinCore_reset", false,-1);
        vcdp->declBus(c+9,"test_bench_robin_core_v2 robinCore_io_INSTRUCTION", false,-1, 31,0);
        vcdp->declBit(c+337,"test_bench_robin_core_v2 robinCore_io_START_PROGRAM", false,-1);
        vcdp->declBus(c+345,"test_bench_robin_core_v2 robinCore_io_PC", false,-1, 31,0);
        vcdp->declBus(c+17,"test_bench_robin_core_v2 robinCore_io_rdAddr", false,-1, 31,0);
        vcdp->declBus(c+25,"test_bench_robin_core_v2 robinCore_io_rdData", false,-1, 7,0);
        vcdp->declBit(c+353,"test_bench_robin_core_v2 robinCore_io_mem_write", false,-1);
        vcdp->declBus(c+33,"test_bench_robin_core_v2 robinCore_io_mem_write_data", false,-1, 7,0);
        vcdp->declBus(c+41,"test_bench_robin_core_v2 robinCore_io_mem_write_address", false,-1, 31,0);
        vcdp->declBit(c+337,"test_bench_robin_core_v2 PROGRAM_LOADED", false,-1);
        vcdp->declBus(c+361,"test_bench_robin_core_v2 lo", false,-1, 29,0);
        vcdp->declBit(c+1113,"test_bench_robin_core_v2 memoryData clock", false,-1);
        vcdp->declBus(c+289,"test_bench_robin_core_v2 memoryData io_rdAddr", false,-1, 31,0);
        vcdp->declBus(c+1,"test_bench_robin_core_v2 memoryData io_rdData", false,-1, 7,0);
        vcdp->declBit(c+297,"test_bench_robin_core_v2 memoryData io_mem_write", false,-1);
        vcdp->declBus(c+305,"test_bench_robin_core_v2 memoryData io_mem_write_data", false,-1, 7,0);
        vcdp->declBus(c+313,"test_bench_robin_core_v2 memoryData io_mem_write_address", false,-1, 31,0);
        vcdp->declBus(c+369,"test_bench_robin_core_v2 memoryData mem_memData_data", false,-1, 7,0);
        vcdp->declBus(c+377,"test_bench_robin_core_v2 memoryData mem_memData_addr", false,-1, 17,0);
        vcdp->declBus(c+305,"test_bench_robin_core_v2 memoryData mem_MPORT_data", false,-1, 7,0);
        vcdp->declBus(c+321,"test_bench_robin_core_v2 memoryData mem_MPORT_addr", false,-1, 17,0);
        vcdp->declBit(c+1257,"test_bench_robin_core_v2 memoryData mem_MPORT_mask", false,-1);
        vcdp->declBit(c+297,"test_bench_robin_core_v2 memoryData mem_MPORT_en", false,-1);
        vcdp->declBus(c+377,"test_bench_robin_core_v2 memoryData mem_memData_addr_pipe_0", false,-1, 17,0);
        vcdp->declBus(c+385,"test_bench_robin_core_v2 memoryData wrDataReg", false,-1, 7,0);
        vcdp->declBit(c+393,"test_bench_robin_core_v2 memoryData doForwardReg", false,-1);
        vcdp->declBit(c+1113,"test_bench_robin_core_v2 memoryInstruction clock", false,-1);
        vcdp->declBus(c+329,"test_bench_robin_core_v2 memoryInstruction io_rdAddr", false,-1, 31,0);
        vcdp->declBus(c+9,"test_bench_robin_core_v2 memoryInstruction io_rdData", false,-1, 31,0);
        vcdp->declBit(c+1169,"test_bench_robin_core_v2 memoryInstruction io_mem_write", false,-1);
        vcdp->declBus(c+1177,"test_bench_robin_core_v2 memoryInstruction io_mem_write_data", false,-1, 31,0);
        vcdp->declBus(c+1185,"test_bench_robin_core_v2 memoryInstruction io_mem_write_address", false,-1, 31,0);
        vcdp->declBus(c+401,"test_bench_robin_core_v2 memoryInstruction mem_memData_data", false,-1, 31,0);
        vcdp->declBus(c+409,"test_bench_robin_core_v2 memoryInstruction mem_memData_addr", false,-1, 9,0);
        vcdp->declBus(c+1177,"test_bench_robin_core_v2 memoryInstruction mem_MPORT_data", false,-1, 31,0);
        vcdp->declBus(c+1249,"test_bench_robin_core_v2 memoryInstruction mem_MPORT_addr", false,-1, 9,0);
        vcdp->declBit(c+1257,"test_bench_robin_core_v2 memoryInstruction mem_MPORT_mask", false,-1);
        vcdp->declBit(c+1169,"test_bench_robin_core_v2 memoryInstruction mem_MPORT_en", false,-1);
        vcdp->declBus(c+409,"test_bench_robin_core_v2 memoryInstruction mem_memData_addr_pipe_0", false,-1, 9,0);
        vcdp->declBus(c+417,"test_bench_robin_core_v2 memoryInstruction wrDataReg", false,-1, 31,0);
        vcdp->declBit(c+425,"test_bench_robin_core_v2 memoryInstruction doForwardReg", false,-1);
        vcdp->declBit(c+1113,"test_bench_robin_core_v2 robinCore clock", false,-1);
        vcdp->declBit(c+1121,"test_bench_robin_core_v2 robinCore reset", false,-1);
        vcdp->declBus(c+9,"test_bench_robin_core_v2 robinCore io_INSTRUCTION", false,-1, 31,0);
        vcdp->declBit(c+337,"test_bench_robin_core_v2 robinCore io_START_PROGRAM", false,-1);
        vcdp->declBus(c+345,"test_bench_robin_core_v2 robinCore io_PC", false,-1, 31,0);
        vcdp->declBus(c+17,"test_bench_robin_core_v2 robinCore io_rdAddr", false,-1, 31,0);
        vcdp->declBus(c+25,"test_bench_robin_core_v2 robinCore io_rdData", false,-1, 7,0);
        vcdp->declBit(c+353,"test_bench_robin_core_v2 robinCore io_mem_write", false,-1);
        vcdp->declBus(c+33,"test_bench_robin_core_v2 robinCore io_mem_write_data", false,-1, 7,0);
        vcdp->declBus(c+41,"test_bench_robin_core_v2 robinCore io_mem_write_address", false,-1, 31,0);
        vcdp->declBit(c+1113,"test_bench_robin_core_v2 robinCore controlStore_clock", false,-1);
        vcdp->declBit(c+1121,"test_bench_robin_core_v2 robinCore controlStore_reset", false,-1);
        vcdp->declBus(c+9,"test_bench_robin_core_v2 robinCore controlStore_io_INSTRUCTION", false,-1, 31,0);
        vcdp->declBit(c+433,"test_bench_robin_core_v2 robinCore controlStore_io_INSTRUCTION_LOADED", false,-1);
        vcdp->declBus(c+49,"test_bench_robin_core_v2 robinCore controlStore_io_RS1", false,-1, 4,0);
        vcdp->declBus(c+57,"test_bench_robin_core_v2 robinCore controlStore_io_RS2", false,-1, 4,0);
        vcdp->declBus(c+65,"test_bench_robin_core_v2 robinCore controlStore_io_RD", false,-1, 4,0);
        vcdp->declBit(c+73,"test_bench_robin_core_v2 robinCore controlStore_io_WRITE_EN", false,-1);
        vcdp->declBus(c+81,"test_bench_robin_core_v2 robinCore controlStore_io_ALU_OP", false,-1, 3,0);
        vcdp->declBit(c+89,"test_bench_robin_core_v2 robinCore controlStore_io_PROCEDURE_BRANCHING", false,-1);
        vcdp->declBit(c+441,"test_bench_robin_core_v2 robinCore controlStore_io_CHOOSE_IMMEDIATE", false,-1);
        vcdp->declBit(c+97,"test_bench_robin_core_v2 robinCore controlStore_io_CHOOSE_MEMORY_LOAD", false,-1);
        vcdp->declBus(c+105,"test_bench_robin_core_v2 robinCore controlStore_io_IMMEDIATE", false,-1, 31,0);
        vcdp->declBus(c+113,"test_bench_robin_core_v2 robinCore controlStore_io_BRANCH_IMMEDIATE", false,-1, 31,0);
        vcdp->declBit(c+449,"test_bench_robin_core_v2 robinCore controlStore_io_STORE_READY", false,-1);
        vcdp->declBit(c+121,"test_bench_robin_core_v2 robinCore controlStore_io_DATA_IN", false,-1);
        vcdp->declBus(c+129,"test_bench_robin_core_v2 robinCore controlStore_io_STORE_SIZE", false,-1, 1,0);
        vcdp->declBit(c+137,"test_bench_robin_core_v2 robinCore controlStore_io_STORE_ADDRESS_IN", false,-1);
        vcdp->declBit(c+145,"test_bench_robin_core_v2 robinCore controlStore_io_LOAD_READY", false,-1);
        vcdp->declBus(c+153,"test_bench_robin_core_v2 robinCore controlStore_io_LOAD_SIZE", false,-1, 1,0);
        vcdp->declBit(c+161,"test_bench_robin_core_v2 robinCore controlStore_io_LOAD_ADDRESS_IN", false,-1);
        vcdp->declBit(c+457,"test_bench_robin_core_v2 robinCore controlStore_io_EXTENSION", false,-1);
        vcdp->declBus(c+169,"test_bench_robin_core_v2 robinCore controlStore_io_BRANCH_SELECT", false,-1, 1,0);
        vcdp->declBit(c+465,"test_bench_robin_core_v2 robinCore controlStore_io_BRANCH_CONDITION", false,-1);
        vcdp->declBit(c+177,"test_bench_robin_core_v2 robinCore controlStore_io_BRANCH_ADDRESS_SOURCE_ALU", false,-1);
        vcdp->declBit(c+185,"test_bench_robin_core_v2 robinCore controlStore_io_UPDATE_PC", false,-1);
        vcdp->declBit(c+473,"test_bench_robin_core_v2 robinCore controlStore_io_CHOOSE_PC", false,-1);
        vcdp->declBit(c+1113,"test_bench_robin_core_v2 robinCore dataPath_clock", false,-1);
        vcdp->declBit(c+1121,"test_bench_robin_core_v2 robinCore dataPath_reset", false,-1);
        vcdp->declBus(c+49,"test_bench_robin_core_v2 robinCore dataPath_io_RS1", false,-1, 4,0);
        vcdp->declBus(c+57,"test_bench_robin_core_v2 robinCore dataPath_io_RS2", false,-1, 4,0);
        vcdp->declBus(c+65,"test_bench_robin_core_v2 robinCore dataPath_io_RD", false,-1, 4,0);
        vcdp->declBit(c+73,"test_bench_robin_core_v2 robinCore dataPath_io_WRITE_EN", false,-1);
        vcdp->declBus(c+81,"test_bench_robin_core_v2 robinCore dataPath_io_ALU_OP", false,-1, 3,0);
        vcdp->declBit(c+481,"test_bench_robin_core_v2 robinCore dataPath_io_EQUAL", false,-1);
        vcdp->declBit(c+489,"test_bench_robin_core_v2 robinCore dataPath_io_LESS_THAN", false,-1);
        vcdp->declBit(c+497,"test_bench_robin_core_v2 robinCore dataPath_io_SIGNED_LESS_THAN", false,-1);
        vcdp->declBus(c+193,"test_bench_robin_core_v2 robinCore dataPath_io_store_data", false,-1, 31,0);
        vcdp->declBus(c+505,"test_bench_robin_core_v2 robinCore dataPath_io_store_address", false,-1, 31,0);
        vcdp->declBus(c+513,"test_bench_robin_core_v2 robinCore dataPath_io_load_data", false,-1, 31,0);
        vcdp->declBus(c+505,"test_bench_robin_core_v2 robinCore dataPath_io_load_address", false,-1, 31,0);
        vcdp->declBit(c+441,"test_bench_robin_core_v2 robinCore dataPath_io_CHOOSE_IMMEDIATE", false,-1);
        vcdp->declBit(c+97,"test_bench_robin_core_v2 robinCore dataPath_io_CHOOSE_MEMORY_LOAD", false,-1);
        vcdp->declBus(c+105,"test_bench_robin_core_v2 robinCore dataPath_io_IMMEDIATE", false,-1, 31,0);
        vcdp->declBus(c+521,"test_bench_robin_core_v2 robinCore dataPath_io_instruction_return_address", false,-1, 31,0);
        vcdp->declBus(c+505,"test_bench_robin_core_v2 robinCore dataPath_io_instruction_next_address", false,-1, 31,0);
        vcdp->declBit(c+89,"test_bench_robin_core_v2 robinCore dataPath_io_PROCEDURE_BRANCHING", false,-1);
        vcdp->declBit(c+473,"test_bench_robin_core_v2 robinCore dataPath_io_CHOOSE_PC", false,-1);
        vcdp->declBus(c+345,"test_bench_robin_core_v2 robinCore dataPath_io_PC", false,-1, 31,0);
        vcdp->declBit(c+1113,"test_bench_robin_core_v2 robinCore storeUnit_clock", false,-1);
        vcdp->declBit(c+1121,"test_bench_robin_core_v2 robinCore storeUnit_reset", false,-1);
        vcdp->declBus(c+33,"test_bench_robin_core_v2 robinCore storeUnit_io_mem_write_data", false,-1, 7,0);
        vcdp->declBus(c+41,"test_bench_robin_core_v2 robinCore storeUnit_io_mem_write_address", false,-1, 31,0);
        vcdp->declBit(c+353,"test_bench_robin_core_v2 robinCore storeUnit_io_mem_write", false,-1);
        vcdp->declBit(c+449,"test_bench_robin_core_v2 robinCore storeUnit_io_STORE_READY", false,-1);
        vcdp->declBit(c+121,"test_bench_robin_core_v2 robinCore storeUnit_io_DATA_IN", false,-1);
        vcdp->declBus(c+129,"test_bench_robin_core_v2 robinCore storeUnit_io_STORE_SIZE", false,-1, 1,0);
        vcdp->declBit(c+137,"test_bench_robin_core_v2 robinCore storeUnit_io_ADDRESS_IN", false,-1);
        vcdp->declBus(c+193,"test_bench_robin_core_v2 robinCore storeUnit_io_store_data", false,-1, 31,0);
        vcdp->declBus(c+505,"test_bench_robin_core_v2 robinCore storeUnit_io_store_address", false,-1, 31,0);
        vcdp->declBit(c+1113,"test_bench_robin_core_v2 robinCore loadUnit_clock", false,-1);
        vcdp->declBit(c+1121,"test_bench_robin_core_v2 robinCore loadUnit_reset", false,-1);
        vcdp->declBus(c+505,"test_bench_robin_core_v2 robinCore loadUnit_io_load_mem_address_in", false,-1, 31,0);
        vcdp->declBus(c+25,"test_bench_robin_core_v2 robinCore loadUnit_io_load_data", false,-1, 7,0);
        vcdp->declBus(c+153,"test_bench_robin_core_v2 robinCore loadUnit_io_LOAD_SIZE", false,-1, 1,0);
        vcdp->declBit(c+161,"test_bench_robin_core_v2 robinCore loadUnit_io_LOAD_ADDRESS_IN", false,-1);
        vcdp->declBit(c+145,"test_bench_robin_core_v2 robinCore loadUnit_io_LOAD_READY", false,-1);
        vcdp->declBus(c+17,"test_bench_robin_core_v2 robinCore loadUnit_io_load_mem_address_out", false,-1, 31,0);
        vcdp->declBus(c+513,"test_bench_robin_core_v2 robinCore loadUnit_io_load_data_out", false,-1, 31,0);
        vcdp->declBit(c+457,"test_bench_robin_core_v2 robinCore loadUnit_io_EXTENSION", false,-1);
        vcdp->declBus(c+345,"test_bench_robin_core_v2 robinCore PC", false,-1, 31,0);
        vcdp->declBit(c+433,"test_bench_robin_core_v2 robinCore INSTRUCTION_LOADED", false,-1);
        vcdp->declBit(c+529,"test_bench_robin_core_v2 robinCore PROGRAM_LOADED", false,-1);
        vcdp->declBus(c+521,"test_bench_robin_core_v2 robinCore noBranchNextAddr", false,-1, 31,0);
        vcdp->declBus(c+201,"test_bench_robin_core_v2 robinCore branchImmBranchAddr", false,-1, 31,0);
        vcdp->declBit(c+209,"test_bench_robin_core_v2 robinCore lessThanGreaterThanALUResult", false,-1);
        vcdp->declBit(c+217,"test_bench_robin_core_v2 robinCore branchCheck", false,-1);
        vcdp->declBit(c+225,"test_bench_robin_core_v2 robinCore conditionalBranching", false,-1);
        vcdp->declBit(c+1113,"test_bench_robin_core_v2 robinCore controlStore clock", false,-1);
        vcdp->declBit(c+1121,"test_bench_robin_core_v2 robinCore controlStore reset", false,-1);
        vcdp->declBus(c+9,"test_bench_robin_core_v2 robinCore controlStore io_INSTRUCTION", false,-1, 31,0);
        vcdp->declBit(c+433,"test_bench_robin_core_v2 robinCore controlStore io_INSTRUCTION_LOADED", false,-1);
        vcdp->declBus(c+49,"test_bench_robin_core_v2 robinCore controlStore io_RS1", false,-1, 4,0);
        vcdp->declBus(c+57,"test_bench_robin_core_v2 robinCore controlStore io_RS2", false,-1, 4,0);
        vcdp->declBus(c+65,"test_bench_robin_core_v2 robinCore controlStore io_RD", false,-1, 4,0);
        vcdp->declBit(c+73,"test_bench_robin_core_v2 robinCore controlStore io_WRITE_EN", false,-1);
        vcdp->declBus(c+81,"test_bench_robin_core_v2 robinCore controlStore io_ALU_OP", false,-1, 3,0);
        vcdp->declBit(c+89,"test_bench_robin_core_v2 robinCore controlStore io_PROCEDURE_BRANCHING", false,-1);
        vcdp->declBit(c+441,"test_bench_robin_core_v2 robinCore controlStore io_CHOOSE_IMMEDIATE", false,-1);
        vcdp->declBit(c+97,"test_bench_robin_core_v2 robinCore controlStore io_CHOOSE_MEMORY_LOAD", false,-1);
        vcdp->declBus(c+105,"test_bench_robin_core_v2 robinCore controlStore io_IMMEDIATE", false,-1, 31,0);
        vcdp->declBus(c+113,"test_bench_robin_core_v2 robinCore controlStore io_BRANCH_IMMEDIATE", false,-1, 31,0);
        vcdp->declBit(c+449,"test_bench_robin_core_v2 robinCore controlStore io_STORE_READY", false,-1);
        vcdp->declBit(c+121,"test_bench_robin_core_v2 robinCore controlStore io_DATA_IN", false,-1);
        vcdp->declBus(c+129,"test_bench_robin_core_v2 robinCore controlStore io_STORE_SIZE", false,-1, 1,0);
        vcdp->declBit(c+137,"test_bench_robin_core_v2 robinCore controlStore io_STORE_ADDRESS_IN", false,-1);
        vcdp->declBit(c+145,"test_bench_robin_core_v2 robinCore controlStore io_LOAD_READY", false,-1);
        vcdp->declBus(c+153,"test_bench_robin_core_v2 robinCore controlStore io_LOAD_SIZE", false,-1, 1,0);
        vcdp->declBit(c+161,"test_bench_robin_core_v2 robinCore controlStore io_LOAD_ADDRESS_IN", false,-1);
        vcdp->declBit(c+457,"test_bench_robin_core_v2 robinCore controlStore io_EXTENSION", false,-1);
        vcdp->declBus(c+169,"test_bench_robin_core_v2 robinCore controlStore io_BRANCH_SELECT", false,-1, 1,0);
        vcdp->declBit(c+465,"test_bench_robin_core_v2 robinCore controlStore io_BRANCH_CONDITION", false,-1);
        vcdp->declBit(c+177,"test_bench_robin_core_v2 robinCore controlStore io_BRANCH_ADDRESS_SOURCE_ALU", false,-1);
        vcdp->declBit(c+185,"test_bench_robin_core_v2 robinCore controlStore io_UPDATE_PC", false,-1);
        vcdp->declBit(c+473,"test_bench_robin_core_v2 robinCore controlStore io_CHOOSE_PC", false,-1);
        vcdp->declBus(c+537,"test_bench_robin_core_v2 robinCore controlStore stateReg", false,-1, 2,0);
        vcdp->declBus(c+545,"test_bench_robin_core_v2 robinCore controlStore stallState", false,-1, 2,0);
        vcdp->declBus(c+553,"test_bench_robin_core_v2 robinCore controlStore instruction", false,-1, 31,0);
        vcdp->declBit(c+561,"test_bench_robin_core_v2 robinCore controlStore STORE_READY", false,-1);
        vcdp->declBit(c+569,"test_bench_robin_core_v2 robinCore controlStore LOAD_READY", false,-1);
        vcdp->declBus(c+577,"test_bench_robin_core_v2 robinCore controlStore hi", false,-1, 6,0);
        vcdp->declBus(c+585,"test_bench_robin_core_v2 robinCore controlStore lo", false,-1, 4,0);
        vcdp->declBit(c+593,"test_bench_robin_core_v2 robinCore controlStore hi_1", false,-1);
        vcdp->declBus(c+601,"test_bench_robin_core_v2 robinCore controlStore lo_1", false,-1, 2,0);
        vcdp->declBit(c+609,"test_bench_robin_core_v2 robinCore controlStore hi_3", false,-1);
        vcdp->declBit(c+617,"test_bench_robin_core_v2 robinCore controlStore lo_3", false,-1);
        vcdp->declBus(c+625,"test_bench_robin_core_v2 robinCore controlStore hi_5", false,-1, 5,0);
        vcdp->declBus(c+633,"test_bench_robin_core_v2 robinCore controlStore lo_4", false,-1, 3,0);
        vcdp->declBus(c+641,"test_bench_robin_core_v2 robinCore controlStore lo_6", false,-1, 7,0);
        vcdp->declBit(c+649,"test_bench_robin_core_v2 robinCore controlStore hi_9", false,-1);
        vcdp->declBus(c+657,"test_bench_robin_core_v2 robinCore controlStore lo_7", false,-1, 9,0);
        vcdp->declBit(c+1113,"test_bench_robin_core_v2 robinCore dataPath clock", false,-1);
        vcdp->declBit(c+1121,"test_bench_robin_core_v2 robinCore dataPath reset", false,-1);
        vcdp->declBus(c+49,"test_bench_robin_core_v2 robinCore dataPath io_RS1", false,-1, 4,0);
        vcdp->declBus(c+57,"test_bench_robin_core_v2 robinCore dataPath io_RS2", false,-1, 4,0);
        vcdp->declBus(c+65,"test_bench_robin_core_v2 robinCore dataPath io_RD", false,-1, 4,0);
        vcdp->declBit(c+73,"test_bench_robin_core_v2 robinCore dataPath io_WRITE_EN", false,-1);
        vcdp->declBus(c+81,"test_bench_robin_core_v2 robinCore dataPath io_ALU_OP", false,-1, 3,0);
        vcdp->declBit(c+481,"test_bench_robin_core_v2 robinCore dataPath io_EQUAL", false,-1);
        vcdp->declBit(c+489,"test_bench_robin_core_v2 robinCore dataPath io_LESS_THAN", false,-1);
        vcdp->declBit(c+497,"test_bench_robin_core_v2 robinCore dataPath io_SIGNED_LESS_THAN", false,-1);
        vcdp->declBus(c+193,"test_bench_robin_core_v2 robinCore dataPath io_store_data", false,-1, 31,0);
        vcdp->declBus(c+505,"test_bench_robin_core_v2 robinCore dataPath io_store_address", false,-1, 31,0);
        vcdp->declBus(c+513,"test_bench_robin_core_v2 robinCore dataPath io_load_data", false,-1, 31,0);
        vcdp->declBus(c+505,"test_bench_robin_core_v2 robinCore dataPath io_load_address", false,-1, 31,0);
        vcdp->declBit(c+441,"test_bench_robin_core_v2 robinCore dataPath io_CHOOSE_IMMEDIATE", false,-1);
        vcdp->declBit(c+97,"test_bench_robin_core_v2 robinCore dataPath io_CHOOSE_MEMORY_LOAD", false,-1);
        vcdp->declBus(c+105,"test_bench_robin_core_v2 robinCore dataPath io_IMMEDIATE", false,-1, 31,0);
        vcdp->declBus(c+521,"test_bench_robin_core_v2 robinCore dataPath io_instruction_return_address", false,-1, 31,0);
        vcdp->declBus(c+505,"test_bench_robin_core_v2 robinCore dataPath io_instruction_next_address", false,-1, 31,0);
        vcdp->declBit(c+89,"test_bench_robin_core_v2 robinCore dataPath io_PROCEDURE_BRANCHING", false,-1);
        vcdp->declBit(c+473,"test_bench_robin_core_v2 robinCore dataPath io_CHOOSE_PC", false,-1);
        vcdp->declBus(c+345,"test_bench_robin_core_v2 robinCore dataPath io_PC", false,-1, 31,0);
        vcdp->declBit(c+1113,"test_bench_robin_core_v2 robinCore dataPath cpuALU_clock", false,-1);
        vcdp->declBit(c+1121,"test_bench_robin_core_v2 robinCore dataPath cpuALU_reset", false,-1);
        vcdp->declBus(c+81,"test_bench_robin_core_v2 robinCore dataPath cpuALU_io_ALU_OP", false,-1, 3,0);
        vcdp->declBit(c+481,"test_bench_robin_core_v2 robinCore dataPath cpuALU_io_EQUAL", false,-1);
        vcdp->declBit(c+489,"test_bench_robin_core_v2 robinCore dataPath cpuALU_io_LESS_THAN", false,-1);
        vcdp->declBit(c+497,"test_bench_robin_core_v2 robinCore dataPath cpuALU_io_SIGNED_LESS_THAN", false,-1);
        vcdp->declBus(c+665,"test_bench_robin_core_v2 robinCore dataPath cpuALU_io_ALUinput1", false,-1, 31,0);
        vcdp->declBus(c+673,"test_bench_robin_core_v2 robinCore dataPath cpuALU_io_ALUinput2", false,-1, 31,0);
        vcdp->declBus(c+505,"test_bench_robin_core_v2 robinCore dataPath cpuALU_io_ALUoutput", false,-1, 31,0);
        vcdp->declBit(c+1113,"test_bench_robin_core_v2 robinCore dataPath registerFile_clock", false,-1);
        vcdp->declBus(c+49,"test_bench_robin_core_v2 robinCore dataPath registerFile_io_RS1", false,-1, 4,0);
        vcdp->declBus(c+57,"test_bench_robin_core_v2 robinCore dataPath registerFile_io_RS2", false,-1, 4,0);
        vcdp->declBus(c+65,"test_bench_robin_core_v2 robinCore dataPath registerFile_io_RD", false,-1, 4,0);
        vcdp->declBit(c+73,"test_bench_robin_core_v2 robinCore dataPath registerFile_io_WRITE_EN", false,-1);
        vcdp->declBus(c+233,"test_bench_robin_core_v2 robinCore dataPath registerFile_io_rs1Data", false,-1, 31,0);
        vcdp->declBus(c+241,"test_bench_robin_core_v2 robinCore dataPath registerFile_io_rs2Data", false,-1, 31,0);
        vcdp->declBus(c+249,"test_bench_robin_core_v2 robinCore dataPath registerFile_io_rdData", false,-1, 31,0);
        vcdp->declBus(c+665,"test_bench_robin_core_v2 robinCore dataPath ALU_in1", false,-1, 31,0);
        vcdp->declBus(c+673,"test_bench_robin_core_v2 robinCore dataPath ALU_in2", false,-1, 31,0);
        vcdp->declBus(c+257,"test_bench_robin_core_v2 robinCore dataPath rdData", false,-1, 31,0);
        vcdp->declBus(c+265,"test_bench_robin_core_v2 robinCore dataPath rs1_ALU", false,-1, 31,0);
        vcdp->declBus(c+273,"test_bench_robin_core_v2 robinCore dataPath rs2_ALU", false,-1, 31,0);
        vcdp->declBus(c+281,"test_bench_robin_core_v2 robinCore dataPath rs2_ALU_rd", false,-1, 31,0);
        vcdp->declBit(c+1113,"test_bench_robin_core_v2 robinCore dataPath cpuALU clock", false,-1);
        vcdp->declBit(c+1121,"test_bench_robin_core_v2 robinCore dataPath cpuALU reset", false,-1);
        vcdp->declBus(c+81,"test_bench_robin_core_v2 robinCore dataPath cpuALU io_ALU_OP", false,-1, 3,0);
        vcdp->declBit(c+481,"test_bench_robin_core_v2 robinCore dataPath cpuALU io_EQUAL", false,-1);
        vcdp->declBit(c+489,"test_bench_robin_core_v2 robinCore dataPath cpuALU io_LESS_THAN", false,-1);
        vcdp->declBit(c+497,"test_bench_robin_core_v2 robinCore dataPath cpuALU io_SIGNED_LESS_THAN", false,-1);
        vcdp->declBus(c+665,"test_bench_robin_core_v2 robinCore dataPath cpuALU io_ALUinput1", false,-1, 31,0);
        vcdp->declBus(c+673,"test_bench_robin_core_v2 robinCore dataPath cpuALU io_ALUinput2", false,-1, 31,0);
        vcdp->declBus(c+505,"test_bench_robin_core_v2 robinCore dataPath cpuALU io_ALUoutput", false,-1, 31,0);
        vcdp->declBus(c+505,"test_bench_robin_core_v2 robinCore dataPath cpuALU ALUoutput", false,-1, 31,0);
        vcdp->declBit(c+481,"test_bench_robin_core_v2 robinCore dataPath cpuALU EQUAL", false,-1);
        vcdp->declBit(c+489,"test_bench_robin_core_v2 robinCore dataPath cpuALU LESS_THAN", false,-1);
        vcdp->declBit(c+497,"test_bench_robin_core_v2 robinCore dataPath cpuALU SIGNED_LESS_THAN", false,-1);
        vcdp->declBit(c+1113,"test_bench_robin_core_v2 robinCore dataPath registerFile clock", false,-1);
        vcdp->declBus(c+49,"test_bench_robin_core_v2 robinCore dataPath registerFile io_RS1", false,-1, 4,0);
        vcdp->declBus(c+57,"test_bench_robin_core_v2 robinCore dataPath registerFile io_RS2", false,-1, 4,0);
        vcdp->declBus(c+65,"test_bench_robin_core_v2 robinCore dataPath registerFile io_RD", false,-1, 4,0);
        vcdp->declBit(c+73,"test_bench_robin_core_v2 robinCore dataPath registerFile io_WRITE_EN", false,-1);
        vcdp->declBus(c+233,"test_bench_robin_core_v2 robinCore dataPath registerFile io_rs1Data", false,-1, 31,0);
        vcdp->declBus(c+241,"test_bench_robin_core_v2 robinCore dataPath registerFile io_rs2Data", false,-1, 31,0);
        vcdp->declBus(c+249,"test_bench_robin_core_v2 robinCore dataPath registerFile io_rdData", false,-1, 31,0);
        vcdp->declBus(c+681,"test_bench_robin_core_v2 robinCore dataPath registerFile registerFile_0", false,-1, 31,0);
        vcdp->declBus(c+689,"test_bench_robin_core_v2 robinCore dataPath registerFile registerFile_1", false,-1, 31,0);
        vcdp->declBus(c+697,"test_bench_robin_core_v2 robinCore dataPath registerFile registerFile_2", false,-1, 31,0);
        vcdp->declBus(c+705,"test_bench_robin_core_v2 robinCore dataPath registerFile registerFile_3", false,-1, 31,0);
        vcdp->declBus(c+713,"test_bench_robin_core_v2 robinCore dataPath registerFile registerFile_4", false,-1, 31,0);
        vcdp->declBus(c+721,"test_bench_robin_core_v2 robinCore dataPath registerFile registerFile_5", false,-1, 31,0);
        vcdp->declBus(c+729,"test_bench_robin_core_v2 robinCore dataPath registerFile registerFile_6", false,-1, 31,0);
        vcdp->declBus(c+737,"test_bench_robin_core_v2 robinCore dataPath registerFile registerFile_7", false,-1, 31,0);
        vcdp->declBus(c+745,"test_bench_robin_core_v2 robinCore dataPath registerFile registerFile_8", false,-1, 31,0);
        vcdp->declBus(c+753,"test_bench_robin_core_v2 robinCore dataPath registerFile registerFile_9", false,-1, 31,0);
        vcdp->declBus(c+761,"test_bench_robin_core_v2 robinCore dataPath registerFile registerFile_10", false,-1, 31,0);
        vcdp->declBus(c+769,"test_bench_robin_core_v2 robinCore dataPath registerFile registerFile_11", false,-1, 31,0);
        vcdp->declBus(c+777,"test_bench_robin_core_v2 robinCore dataPath registerFile registerFile_12", false,-1, 31,0);
        vcdp->declBus(c+785,"test_bench_robin_core_v2 robinCore dataPath registerFile registerFile_13", false,-1, 31,0);
        vcdp->declBus(c+793,"test_bench_robin_core_v2 robinCore dataPath registerFile registerFile_14", false,-1, 31,0);
        vcdp->declBus(c+801,"test_bench_robin_core_v2 robinCore dataPath registerFile registerFile_15", false,-1, 31,0);
        vcdp->declBus(c+809,"test_bench_robin_core_v2 robinCore dataPath registerFile registerFile_16", false,-1, 31,0);
        vcdp->declBus(c+817,"test_bench_robin_core_v2 robinCore dataPath registerFile registerFile_17", false,-1, 31,0);
        vcdp->declBus(c+825,"test_bench_robin_core_v2 robinCore dataPath registerFile registerFile_18", false,-1, 31,0);
        vcdp->declBus(c+833,"test_bench_robin_core_v2 robinCore dataPath registerFile registerFile_19", false,-1, 31,0);
        vcdp->declBus(c+841,"test_bench_robin_core_v2 robinCore dataPath registerFile registerFile_20", false,-1, 31,0);
        vcdp->declBus(c+849,"test_bench_robin_core_v2 robinCore dataPath registerFile registerFile_21", false,-1, 31,0);
        vcdp->declBus(c+857,"test_bench_robin_core_v2 robinCore dataPath registerFile registerFile_22", false,-1, 31,0);
        vcdp->declBus(c+865,"test_bench_robin_core_v2 robinCore dataPath registerFile registerFile_23", false,-1, 31,0);
        vcdp->declBus(c+873,"test_bench_robin_core_v2 robinCore dataPath registerFile registerFile_24", false,-1, 31,0);
        vcdp->declBus(c+881,"test_bench_robin_core_v2 robinCore dataPath registerFile registerFile_25", false,-1, 31,0);
        vcdp->declBus(c+889,"test_bench_robin_core_v2 robinCore dataPath registerFile registerFile_26", false,-1, 31,0);
        vcdp->declBus(c+897,"test_bench_robin_core_v2 robinCore dataPath registerFile registerFile_27", false,-1, 31,0);
        vcdp->declBus(c+905,"test_bench_robin_core_v2 robinCore dataPath registerFile registerFile_28", false,-1, 31,0);
        vcdp->declBus(c+913,"test_bench_robin_core_v2 robinCore dataPath registerFile registerFile_29", false,-1, 31,0);
        vcdp->declBus(c+921,"test_bench_robin_core_v2 robinCore dataPath registerFile registerFile_30", false,-1, 31,0);
        vcdp->declBus(c+929,"test_bench_robin_core_v2 robinCore dataPath registerFile registerFile_31", false,-1, 31,0);
        vcdp->declBit(c+1113,"test_bench_robin_core_v2 robinCore storeUnit clock", false,-1);
        vcdp->declBit(c+1121,"test_bench_robin_core_v2 robinCore storeUnit reset", false,-1);
        vcdp->declBus(c+33,"test_bench_robin_core_v2 robinCore storeUnit io_mem_write_data", false,-1, 7,0);
        vcdp->declBus(c+41,"test_bench_robin_core_v2 robinCore storeUnit io_mem_write_address", false,-1, 31,0);
        vcdp->declBit(c+353,"test_bench_robin_core_v2 robinCore storeUnit io_mem_write", false,-1);
        vcdp->declBit(c+449,"test_bench_robin_core_v2 robinCore storeUnit io_STORE_READY", false,-1);
        vcdp->declBit(c+121,"test_bench_robin_core_v2 robinCore storeUnit io_DATA_IN", false,-1);
        vcdp->declBus(c+129,"test_bench_robin_core_v2 robinCore storeUnit io_STORE_SIZE", false,-1, 1,0);
        vcdp->declBit(c+137,"test_bench_robin_core_v2 robinCore storeUnit io_ADDRESS_IN", false,-1);
        vcdp->declBus(c+193,"test_bench_robin_core_v2 robinCore storeUnit io_store_data", false,-1, 31,0);
        vcdp->declBus(c+505,"test_bench_robin_core_v2 robinCore storeUnit io_store_address", false,-1, 31,0);
        vcdp->declBus(c+937,"test_bench_robin_core_v2 robinCore storeUnit store_data_buffer", false,-1, 31,0);
        vcdp->declBus(c+945,"test_bench_robin_core_v2 robinCore storeUnit store_data_size_buffer", false,-1, 1,0);
        vcdp->declBus(c+953,"test_bench_robin_core_v2 robinCore storeUnit store_data_buffer_address", false,-1, 31,0);
        vcdp->declBit(c+353,"test_bench_robin_core_v2 robinCore storeUnit storing", false,-1);
        vcdp->declBit(c+961,"test_bench_robin_core_v2 robinCore storeUnit stateReg", false,-1);
        vcdp->declBus(c+969,"test_bench_robin_core_v2 robinCore storeUnit lo", false,-1, 23,0);
        vcdp->declBit(c+1113,"test_bench_robin_core_v2 robinCore loadUnit clock", false,-1);
        vcdp->declBit(c+1121,"test_bench_robin_core_v2 robinCore loadUnit reset", false,-1);
        vcdp->declBus(c+505,"test_bench_robin_core_v2 robinCore loadUnit io_load_mem_address_in", false,-1, 31,0);
        vcdp->declBus(c+25,"test_bench_robin_core_v2 robinCore loadUnit io_load_data", false,-1, 7,0);
        vcdp->declBus(c+153,"test_bench_robin_core_v2 robinCore loadUnit io_LOAD_SIZE", false,-1, 1,0);
        vcdp->declBit(c+161,"test_bench_robin_core_v2 robinCore loadUnit io_LOAD_ADDRESS_IN", false,-1);
        vcdp->declBit(c+145,"test_bench_robin_core_v2 robinCore loadUnit io_LOAD_READY", false,-1);
        vcdp->declBus(c+17,"test_bench_robin_core_v2 robinCore loadUnit io_load_mem_address_out", false,-1, 31,0);
        vcdp->declBus(c+513,"test_bench_robin_core_v2 robinCore loadUnit io_load_data_out", false,-1, 31,0);
        vcdp->declBit(c+457,"test_bench_robin_core_v2 robinCore loadUnit io_EXTENSION", false,-1);
        vcdp->declBus(c+977,"test_bench_robin_core_v2 robinCore loadUnit load_data_buffer", false,-1, 31,0);
        vcdp->declBus(c+985,"test_bench_robin_core_v2 robinCore loadUnit load_data_size_buffer", false,-1, 1,0);
        vcdp->declBus(c+993,"test_bench_robin_core_v2 robinCore loadUnit load_data_address_buffer", false,-1, 31,0);
        vcdp->declBus(c+1001,"test_bench_robin_core_v2 robinCore loadUnit LOAD_SIZE", false,-1, 1,0);
        vcdp->declBit(c+1009,"test_bench_robin_core_v2 robinCore loadUnit EXTENSION", false,-1);
        vcdp->declBit(c+1017,"test_bench_robin_core_v2 robinCore loadUnit stateReg", false,-1);
        vcdp->declBit(c+1025,"test_bench_robin_core_v2 robinCore loadUnit MSB", false,-1);
        vcdp->declBit(c+1033,"test_bench_robin_core_v2 robinCore loadUnit needMask", false,-1);
        vcdp->declBus(c+1041,"test_bench_robin_core_v2 robinCore loadUnit hi", false,-1, 15,0);
        vcdp->declBus(c+1049,"test_bench_robin_core_v2 robinCore loadUnit lo", false,-1, 7,0);
        vcdp->declBus(c+1057,"test_bench_robin_core_v2 robinCore loadUnit mask", false,-1, 23,0);
        vcdp->declBus(c+1065,"test_bench_robin_core_v2 robinCore loadUnit extending_mask", false,-1, 23,0);
        vcdp->declBus(c+1073,"test_bench_robin_core_v2 robinCore loadUnit hi_1", false,-1, 23,0);
        vcdp->declBus(c+1081,"test_bench_robin_core_v2 robinCore loadUnit lo_1", false,-1, 7,0);
        vcdp->declBus(c+1089,"test_bench_robin_core_v2 robinCore loadUnit hi_2", false,-1, 23,0);
        vcdp->declBus(c+1097,"test_bench_robin_core_v2 robinCore loadUnit hi_4", false,-1, 15,0);
        vcdp->declBus(c+1105,"test_bench_robin_core_v2 robinCore loadUnit lo_4", false,-1, 7,0);
    }
}

void Vtest_bench_robin_core_v2::traceFullThis__1(Vtest_bench_robin_core_v2__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtest_bench_robin_core_v2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->fullBus(c+1,(vlTOPp->test_bench_robin_core_v2__DOT__memoryData_io_rdData),8);
        vcdp->fullBus(c+9,(vlTOPp->test_bench_robin_core_v2__DOT__memoryInstruction_io_rdData),32);
        vcdp->fullBus(c+17,(((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__stateReg)
                              ? ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__stateReg)
                                  ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_address_buffer
                                  : 0U) : ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_LOAD_ADDRESS_IN)
                                            ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT__ALUoutput
                                            : 0U))),32);
        vcdp->fullBus(c+25,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore_io_rdData),8);
        vcdp->fullBus(c+33,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit_io_mem_write_data),8);
        vcdp->fullBus(c+41,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit_io_mem_write_address),32);
        vcdp->fullBus(c+49,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1),5);
        vcdp->fullBus(c+57,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2),5);
        vcdp->fullBus(c+65,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD),5);
        vcdp->fullBit(c+73,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_WRITE_EN));
        vcdp->fullBus(c+81,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_ALU_OP),4);
        vcdp->fullBit(c+89,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_PROCEDURE_BRANCHING));
        vcdp->fullBit(c+97,(((0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                             & ((1U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                                & ((2U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                                   & ((3U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                                      & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___GEN_36)))))));
        vcdp->fullBus(c+105,(((0U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                               ? 0U : ((1U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                                        ? ((0x37U == 
                                            (0x7fU 
                                             & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction))
                                            ? (0xfffff000U 
                                               & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction)
                                            : ((0xfffff000U 
                                                & (VL_NEGATE_I((IData)(
                                                                       (1U 
                                                                        & ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___T_18) 
                                                                           >> 0xbU)))) 
                                                   << 0xcU)) 
                                               | (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___T_18)))
                                        : 0U))),32);
        vcdp->fullBus(c+113,(((0U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                               ? 0U : ((1U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                                        ? 0U : ((2U 
                                                 == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                                                 ? 0U
                                                 : 
                                                ((3U 
                                                  == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                                                  ? 
                                                 ((0x63U 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction))
                                                   ? 
                                                  ((0x80000000U 
                                                    & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction)
                                                    ? 
                                                   (0xffffe000U 
                                                    | (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___T_65))
                                                    : (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___T_65))
                                                   : 
                                                  ((0x80000000U 
                                                    & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction)
                                                    ? 
                                                   (0xffe00000U 
                                                    | vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___T_66)
                                                    : vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___T_66))
                                                  : 0U))))),32);
        vcdp->fullBit(c+121,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_DATA_IN));
        vcdp->fullBus(c+129,(((0U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                               ? 1U : ((1U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                                        ? ((0x23U == 
                                            (0x7fU 
                                             & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction))
                                            ? (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___T_32)
                                            : 1U) : 1U))),2);
        vcdp->fullBit(c+137,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_STORE_ADDRESS_IN));
        vcdp->fullBit(c+145,((1U & ((~ (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__stateReg)) 
                                    & (~ (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_LOAD_ADDRESS_IN))))));
        vcdp->fullBus(c+153,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_LOAD_SIZE),2);
        vcdp->fullBit(c+161,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_LOAD_ADDRESS_IN));
        vcdp->fullBus(c+169,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_BRANCH_SELECT),2);
        vcdp->fullBit(c+177,(((0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                              & ((1U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                                 & ((2U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                                     ? (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___GEN_15)
                                     : ((3U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                                        & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___GEN_15)))))));
        vcdp->fullBit(c+185,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_UPDATE_PC));
        vcdp->fullBus(c+193,(((0U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                               ? 0U : (((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2) 
                                        == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD))
                                        ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__rdData
                                        : vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__rs2_ALU))),32);
        vcdp->fullBus(c+201,((vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__PC 
                              + ((0U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                                  ? 0U : ((1U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                                           ? 0U : (
                                                   (2U 
                                                    == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                                                    ? 0U
                                                    : 
                                                   ((3U 
                                                     == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                                                     ? 
                                                    ((0x63U 
                                                      == 
                                                      (0x7fU 
                                                       & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction))
                                                      ? 
                                                     ((0x80000000U 
                                                       & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction)
                                                       ? 
                                                      (0xffffe000U 
                                                       | (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___T_65))
                                                       : (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___T_65))
                                                      : 
                                                     ((0x80000000U 
                                                       & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction)
                                                       ? 
                                                      (0xffe00000U 
                                                       | vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___T_66)
                                                       : vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___T_66))
                                                     : 0U)))))),32);
        vcdp->fullBit(c+209,(((1U & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_BRANCH_SELECT))
                               ? (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT__LESS_THAN)
                               : (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT__SIGNED_LESS_THAN))));
        vcdp->fullBit(c+217,(((2U & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_BRANCH_SELECT))
                               ? ((1U & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_BRANCH_SELECT))
                                   ? (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT__LESS_THAN)
                                   : (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT__SIGNED_LESS_THAN))
                               : (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT__EQUAL))));
        vcdp->fullBit(c+225,((1U & ((~ (((2U & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_BRANCH_SELECT))
                                          ? ((1U & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_BRANCH_SELECT))
                                              ? (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT__LESS_THAN)
                                              : (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT__SIGNED_LESS_THAN))
                                          : (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT__EQUAL)) 
                                        ^ ((0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                                           & ((1U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                                              & ((2U 
                                                  != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                                                 & ((3U 
                                                     == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                                                    & ((0x63U 
                                                        == 
                                                        (0x7fU 
                                                         & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction)) 
                                                       & (~ 
                                                          (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                                           >> 0xcU))))))))) 
                                    & (((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_BRANCH_SELECT) 
                                        >> 1U) | (~ (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_BRANCH_SELECT)))))));
        vcdp->fullBus(c+233,(((0U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                               ? 0U : ((0x1fU == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                        ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_31
                                        : ((0x1eU == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                            ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_30
                                            : ((0x1dU 
                                                == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                                ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_29
                                                : (
                                                   (0x1cU 
                                                    == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                                    ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_28
                                                    : 
                                                   ((0x1bU 
                                                     == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                                     ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_27
                                                     : 
                                                    ((0x1aU 
                                                      == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                                      ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_26
                                                      : 
                                                     ((0x19U 
                                                       == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                                       ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_25
                                                       : 
                                                      ((0x18U 
                                                        == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                                        ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_24
                                                        : 
                                                       ((0x17U 
                                                         == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                                         ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_23
                                                         : 
                                                        ((0x16U 
                                                          == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                                          ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_22
                                                          : vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT___GEN_21)))))))))))),32);
        vcdp->fullBus(c+241,(((0U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                               ? 0U : ((0x1fU == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                        ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_31
                                        : ((0x1eU == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                            ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_30
                                            : ((0x1dU 
                                                == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                                ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_29
                                                : (
                                                   (0x1cU 
                                                    == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                                    ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_28
                                                    : 
                                                   ((0x1bU 
                                                     == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                                     ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_27
                                                     : 
                                                    ((0x1aU 
                                                      == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                                      ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_26
                                                      : 
                                                     ((0x19U 
                                                       == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                                       ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_25
                                                       : 
                                                      ((0x18U 
                                                        == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                                        ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_24
                                                        : 
                                                       ((0x17U 
                                                         == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                                         ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_23
                                                         : 
                                                        ((0x16U 
                                                          == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                                          ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_22
                                                          : vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT___GEN_54)))))))))))),32);
        vcdp->fullBus(c+249,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile_io_rdData),32);
        vcdp->fullBus(c+257,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__rdData),32);
        vcdp->fullBus(c+265,(((0U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                               ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT__ALUoutput
                               : ((0U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                   ? 0U : ((0x1fU == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                            ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_31
                                            : ((0x1eU 
                                                == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                                ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_30
                                                : (
                                                   (0x1dU 
                                                    == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                                    ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_29
                                                    : 
                                                   ((0x1cU 
                                                     == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                                     ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_28
                                                     : 
                                                    ((0x1bU 
                                                      == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                                      ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_27
                                                      : 
                                                     ((0x1aU 
                                                       == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                                       ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_26
                                                       : 
                                                      ((0x19U 
                                                        == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                                        ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_25
                                                        : 
                                                       ((0x18U 
                                                         == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                                         ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_24
                                                         : 
                                                        ((0x17U 
                                                          == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                                          ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_23
                                                          : 
                                                         ((0x16U 
                                                           == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                                           ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_22
                                                           : vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT___GEN_21))))))))))))),32);
        vcdp->fullBus(c+273,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__rs2_ALU),32);
        vcdp->fullBus(c+281,((((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2) 
                               == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD))
                               ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__rdData
                               : vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__rs2_ALU)),32);
        vcdp->fullBus(c+289,(vlTOPp->test_bench_robin_core_v2__DOT__memoryData_io_rdAddr),32);
        vcdp->fullBit(c+297,(vlTOPp->test_bench_robin_core_v2__DOT__memoryData_io_mem_write));
        vcdp->fullBus(c+305,(vlTOPp->test_bench_robin_core_v2__DOT__memoryData_io_mem_write_data),8);
        vcdp->fullBus(c+313,(vlTOPp->test_bench_robin_core_v2__DOT__memoryData_io_mem_write_address),32);
        vcdp->fullBus(c+321,((0x3ffffU & vlTOPp->test_bench_robin_core_v2__DOT__memoryData_io_mem_write_address)),18);
        vcdp->fullBus(c+329,((0x3fffffffU & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__PC 
                                             >> 2U))),32);
        vcdp->fullBit(c+337,(vlTOPp->test_bench_robin_core_v2__DOT__PROGRAM_LOADED));
        vcdp->fullBus(c+345,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__PC),32);
        vcdp->fullBit(c+353,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__storing));
        vcdp->fullBus(c+361,((0x3fffffffU & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__PC 
                                             >> 2U))),30);
        vcdp->fullBus(c+369,(vlTOPp->test_bench_robin_core_v2__DOT__memoryData__DOT__mem
                             [vlTOPp->test_bench_robin_core_v2__DOT__memoryData__DOT__mem_memData_addr_pipe_0]),8);
        vcdp->fullBus(c+377,(vlTOPp->test_bench_robin_core_v2__DOT__memoryData__DOT__mem_memData_addr_pipe_0),18);
        vcdp->fullBus(c+385,(vlTOPp->test_bench_robin_core_v2__DOT__memoryData__DOT__wrDataReg),8);
        vcdp->fullBit(c+393,(vlTOPp->test_bench_robin_core_v2__DOT__memoryData__DOT__doForwardReg));
        vcdp->fullBus(c+401,(vlTOPp->test_bench_robin_core_v2__DOT__memoryInstruction__DOT__mem
                             [vlTOPp->test_bench_robin_core_v2__DOT__memoryInstruction__DOT__mem_memData_addr_pipe_0]),32);
        vcdp->fullBus(c+409,(vlTOPp->test_bench_robin_core_v2__DOT__memoryInstruction__DOT__mem_memData_addr_pipe_0),10);
        vcdp->fullBus(c+417,(vlTOPp->test_bench_robin_core_v2__DOT__memoryInstruction__DOT__wrDataReg),32);
        vcdp->fullBit(c+425,(vlTOPp->test_bench_robin_core_v2__DOT__memoryInstruction__DOT__doForwardReg));
        vcdp->fullBit(c+433,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__INSTRUCTION_LOADED));
        vcdp->fullBit(c+441,(((0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                              & ((1U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                                 & (~ ((0x33U == (0x7fU 
                                                  & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction)) 
                                       | (0x63U == 
                                          (0x7fU & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction))))))));
        vcdp->fullBit(c+449,((1U & (~ (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__stateReg)))));
        vcdp->fullBit(c+457,(((0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                              & ((1U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                                 & ((2U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                                    & ((3U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                                       & (~ (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                             >> 0xeU))))))));
        vcdp->fullBit(c+465,(((0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                              & ((1U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                                 & ((2U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                                    & ((3U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                                       & ((0x63U == 
                                           (0x7fU & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction)) 
                                          & (~ (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                                >> 0xcU)))))))));
        vcdp->fullBit(c+473,(((0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                              & ((1U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                                 & (0x17U == (0x7fU 
                                              & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction))))));
        vcdp->fullBit(c+481,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT__EQUAL));
        vcdp->fullBit(c+489,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT__LESS_THAN));
        vcdp->fullBit(c+497,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT__SIGNED_LESS_THAN));
        vcdp->fullBus(c+505,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT__ALUoutput),32);
        vcdp->fullBus(c+513,(((0xffffff00U & ((0xffffff00U 
                                               & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_buffer) 
                                              | (((((1U 
                                                     & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__LOAD_SIZE))
                                                     ? 
                                                    (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_buffer 
                                                     >> 7U)
                                                     : 
                                                    (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_buffer 
                                                     >> 0xfU)) 
                                                   & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__EXTENSION))
                                                   ? 
                                                  ((((2U 
                                                      & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__LOAD_SIZE))
                                                      ? 0xffffU
                                                      : 0U) 
                                                    << 8U) 
                                                   | ((3U 
                                                       == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__LOAD_SIZE))
                                                       ? 0xffU
                                                       : 0U))
                                                   : 0U) 
                                                 << 8U))) 
                              | (0xffU & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_buffer))),32);
        vcdp->fullBus(c+521,(((IData)(4U) + vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__PC)),32);
        vcdp->fullBit(c+529,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__PROGRAM_LOADED));
        vcdp->fullBus(c+537,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg),3);
        vcdp->fullBus(c+545,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stallState),3);
        vcdp->fullBus(c+553,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction),32);
        vcdp->fullBit(c+561,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__STORE_READY));
        vcdp->fullBit(c+569,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__LOAD_READY));
        vcdp->fullBus(c+577,((0x7fU & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                       >> 0x19U))),7);
        vcdp->fullBus(c+585,((0x1fU & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                       >> 7U))),5);
        vcdp->fullBit(c+593,(((1U == (3U & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                            >> 0xcU))) 
                              & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                 >> 0x1eU))));
        vcdp->fullBus(c+601,((7U & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                    >> 0xcU))),3);
        vcdp->fullBit(c+609,((1U & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                    >> 0x1fU))));
        vcdp->fullBit(c+617,((1U & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                    >> 7U))));
        vcdp->fullBus(c+625,((0x3fU & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                       >> 0x19U))),6);
        vcdp->fullBus(c+633,((0xfU & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                      >> 8U))),4);
        vcdp->fullBus(c+641,((0xffU & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                       >> 0xcU))),8);
        vcdp->fullBit(c+649,((1U & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                    >> 0x14U))));
        vcdp->fullBus(c+657,((0x3ffU & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                        >> 0x15U))),10);
        vcdp->fullBus(c+665,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__ALU_in1),32);
        vcdp->fullBus(c+673,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__ALU_in2),32);
        vcdp->fullBus(c+681,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_0),32);
        vcdp->fullBus(c+689,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_1),32);
        vcdp->fullBus(c+697,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_2),32);
        vcdp->fullBus(c+705,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_3),32);
        vcdp->fullBus(c+713,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_4),32);
        vcdp->fullBus(c+721,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_5),32);
        vcdp->fullBus(c+729,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_6),32);
        vcdp->fullBus(c+737,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_7),32);
        vcdp->fullBus(c+745,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_8),32);
        vcdp->fullBus(c+753,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_9),32);
        vcdp->fullBus(c+761,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_10),32);
        vcdp->fullBus(c+769,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_11),32);
        vcdp->fullBus(c+777,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_12),32);
        vcdp->fullBus(c+785,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_13),32);
        vcdp->fullBus(c+793,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_14),32);
        vcdp->fullBus(c+801,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_15),32);
        vcdp->fullBus(c+809,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_16),32);
        vcdp->fullBus(c+817,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_17),32);
        vcdp->fullBus(c+825,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_18),32);
        vcdp->fullBus(c+833,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_19),32);
        vcdp->fullBus(c+841,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_20),32);
        vcdp->fullBus(c+849,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_21),32);
        vcdp->fullBus(c+857,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_22),32);
        vcdp->fullBus(c+865,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_23),32);
        vcdp->fullBus(c+873,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_24),32);
        vcdp->fullBus(c+881,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_25),32);
        vcdp->fullBus(c+889,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_26),32);
        vcdp->fullBus(c+897,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_27),32);
        vcdp->fullBus(c+905,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_28),32);
        vcdp->fullBus(c+913,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_29),32);
        vcdp->fullBus(c+921,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_30),32);
        vcdp->fullBus(c+929,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_31),32);
        vcdp->fullBus(c+937,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__store_data_buffer),32);
        vcdp->fullBus(c+945,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__store_data_size_buffer),2);
        vcdp->fullBus(c+953,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__store_data_buffer_address),32);
        vcdp->fullBit(c+961,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__stateReg));
        vcdp->fullBus(c+969,((0xffffffU & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__store_data_buffer 
                                           >> 8U))),24);
        vcdp->fullBus(c+977,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_buffer),32);
        vcdp->fullBus(c+985,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_size_buffer),2);
        vcdp->fullBus(c+993,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_address_buffer),32);
        vcdp->fullBus(c+1001,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__LOAD_SIZE),2);
        vcdp->fullBit(c+1009,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__EXTENSION));
        vcdp->fullBit(c+1017,(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__stateReg));
        vcdp->fullBit(c+1025,((1U & ((1U & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__LOAD_SIZE))
                                      ? (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_buffer 
                                         >> 7U) : (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_buffer 
                                                   >> 0xfU)))));
        vcdp->fullBit(c+1033,((((1U & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__LOAD_SIZE))
                                 ? (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_buffer 
                                    >> 7U) : (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_buffer 
                                              >> 0xfU)) 
                               & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__EXTENSION))));
        vcdp->fullBus(c+1041,(((2U & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__LOAD_SIZE))
                                ? 0xffffU : 0U)),16);
        vcdp->fullBus(c+1049,(((3U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__LOAD_SIZE))
                                ? 0xffU : 0U)),8);
        vcdp->fullBus(c+1057,(((((2U & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__LOAD_SIZE))
                                  ? 0xffffU : 0U) << 8U) 
                               | ((3U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__LOAD_SIZE))
                                   ? 0xffU : 0U))),24);
        vcdp->fullBus(c+1065,(((((1U & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__LOAD_SIZE))
                                  ? (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_buffer 
                                     >> 7U) : (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_buffer 
                                               >> 0xfU)) 
                                & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__EXTENSION))
                                ? ((((2U & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__LOAD_SIZE))
                                      ? 0xffffU : 0U) 
                                    << 8U) | ((3U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__LOAD_SIZE))
                                               ? 0xffU
                                               : 0U))
                                : 0U)),24);
        vcdp->fullBus(c+1073,((0xffffffU & ((vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_buffer 
                                             >> 8U) 
                                            | ((((1U 
                                                  & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__LOAD_SIZE))
                                                  ? 
                                                 (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_buffer 
                                                  >> 7U)
                                                  : 
                                                 (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_buffer 
                                                  >> 0xfU)) 
                                                & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__EXTENSION))
                                                ? (
                                                   (((2U 
                                                      & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__LOAD_SIZE))
                                                      ? 0xffffU
                                                      : 0U) 
                                                    << 8U) 
                                                   | ((3U 
                                                       == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__LOAD_SIZE))
                                                       ? 0xffU
                                                       : 0U))
                                                : 0U)))),24);
        vcdp->fullBus(c+1081,((0xffU & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_buffer)),8);
        vcdp->fullBus(c+1089,((0xffffffU & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_buffer)),24);
        vcdp->fullBus(c+1097,((0xffffU & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_buffer 
                                          >> 0x10U))),16);
        vcdp->fullBus(c+1105,((0xffU & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_buffer 
                                        >> 8U))),8);
        vcdp->fullBit(c+1113,(vlTOPp->clock));
        vcdp->fullBit(c+1121,(vlTOPp->reset));
        vcdp->fullBus(c+1129,(vlTOPp->io_rdAddr),32);
        vcdp->fullBus(c+1137,(vlTOPp->io_rdData),8);
        vcdp->fullBit(c+1145,(vlTOPp->io_signal_mem_write_data));
        vcdp->fullBus(c+1153,(vlTOPp->io_mem_write_data),8);
        vcdp->fullBus(c+1161,(vlTOPp->io_mem_write_address_data),32);
        vcdp->fullBit(c+1169,(vlTOPp->io_signal_mem_write_instruction));
        vcdp->fullBus(c+1177,(vlTOPp->io_mem_write_instruction),32);
        vcdp->fullBus(c+1185,(vlTOPp->io_mem_write_address_instruction),32);
        vcdp->fullBit(c+1193,(vlTOPp->io_START_PROGRAM));
        vcdp->fullBit(c+1201,(vlTOPp->io_outputSake));
        vcdp->fullBit(c+1209,(vlTOPp->io_out_mem_write));
        vcdp->fullBus(c+1217,(vlTOPp->io_out_mem_write_data),8);
        vcdp->fullBus(c+1225,(vlTOPp->io_out_mem_write_address),32);
        vcdp->fullBus(c+1233,(vlTOPp->io_INSTRUCTION),32);
        vcdp->fullBus(c+1241,(vlTOPp->io_PC),32);
        vcdp->fullBus(c+1249,((0x3ffU & vlTOPp->io_mem_write_address_instruction)),10);
        vcdp->fullBit(c+1257,(1U));
    }
}
