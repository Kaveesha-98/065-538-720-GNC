// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtest_bench_robin_core_v2.h for the primary calling header

#include "Vtest_bench_robin_core_v2.h"
#include "Vtest_bench_robin_core_v2__Syms.h"

//==========

VL_CTOR_IMP(Vtest_bench_robin_core_v2) {
    Vtest_bench_robin_core_v2__Syms* __restrict vlSymsp = __VlSymsp = new Vtest_bench_robin_core_v2__Syms(this, name());
    Vtest_bench_robin_core_v2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vtest_bench_robin_core_v2::__Vconfigure(Vtest_bench_robin_core_v2__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vtest_bench_robin_core_v2::~Vtest_bench_robin_core_v2() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void Vtest_bench_robin_core_v2::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtest_bench_robin_core_v2::eval\n"); );
    Vtest_bench_robin_core_v2__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtest_bench_robin_core_v2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("test_bench_robin_core_v2.v", 1776, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vtest_bench_robin_core_v2::_eval_initial_loop(Vtest_bench_robin_core_v2__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("test_bench_robin_core_v2.v", 1776, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vtest_bench_robin_core_v2::_initial__TOP__1(Vtest_bench_robin_core_v2__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_bench_robin_core_v2::_initial__TOP__1\n"); );
    Vtest_bench_robin_core_v2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->io_outputSake = 1U;
}

VL_INLINE_OPT void Vtest_bench_robin_core_v2::_sequent__TOP__2(Vtest_bench_robin_core_v2__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_bench_robin_core_v2::_sequent__TOP__2\n"); );
    Vtest_bench_robin_core_v2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*7:0*/ __Vdlyvval__test_bench_robin_core_v2__DOT__memoryData__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__test_bench_robin_core_v2__DOT__memoryData__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__test_bench_robin_core_v2__DOT__memoryInstruction__DOT__mem__v0;
    CData/*0:0*/ __Vdly__test_bench_robin_core_v2__DOT__robinCore__DOT__INSTRUCTION_LOADED;
    CData/*0:0*/ __Vdly__test_bench_robin_core_v2__DOT__robinCore__DOT__PROGRAM_LOADED;
    CData/*1:0*/ __Vdly__test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__store_data_size_buffer;
    CData/*0:0*/ __Vdly__test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__storing;
    CData/*0:0*/ __Vdly__test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__stateReg;
    CData/*1:0*/ __Vdly__test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_size_buffer;
    CData/*0:0*/ __Vdly__test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__stateReg;
    SData/*9:0*/ __Vdlyvdim0__test_bench_robin_core_v2__DOT__memoryData__DOT__mem__v0;
    SData/*9:0*/ __Vdlyvdim0__test_bench_robin_core_v2__DOT__memoryInstruction__DOT__mem__v0;
    IData/*31:0*/ __Vdlyvval__test_bench_robin_core_v2__DOT__memoryInstruction__DOT__mem__v0;
    IData/*31:0*/ __Vdly__test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction;
    IData/*31:0*/ __Vdly__test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__ALU_in1;
    // Body
    __Vdlyvset__test_bench_robin_core_v2__DOT__memoryData__DOT__mem__v0 = 0U;
    __Vdly__test_bench_robin_core_v2__DOT__robinCore__DOT__PROGRAM_LOADED 
        = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__PROGRAM_LOADED;
    __Vdly__test_bench_robin_core_v2__DOT__robinCore__DOT__INSTRUCTION_LOADED 
        = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__INSTRUCTION_LOADED;
    __Vdlyvset__test_bench_robin_core_v2__DOT__memoryInstruction__DOT__mem__v0 = 0U;
    __Vdly__test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__store_data_size_buffer 
        = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__store_data_size_buffer;
    __Vdly__test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__stateReg 
        = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__stateReg;
    __Vdly__test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__storing 
        = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__storing;
    __Vdly__test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
        = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction;
    __Vdly__test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_size_buffer 
        = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_size_buffer;
    __Vdly__test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__stateReg 
        = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__stateReg;
    __Vdly__test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__ALU_in1 
        = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__ALU_in1;
    vlTOPp->test_bench_robin_core_v2__DOT__memoryData__DOT__mem_memData_addr_pipe_0 
        = (0x3ffU & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit_io_load_mem_address_out);
    vlTOPp->test_bench_robin_core_v2__DOT__memoryData__DOT__wrDataReg 
        = vlTOPp->test_bench_robin_core_v2__DOT__memoryData_io_mem_write_data;
    vlTOPp->test_bench_robin_core_v2__DOT__memoryData__DOT__doForwardReg 
        = ((vlTOPp->test_bench_robin_core_v2__DOT__memoryData_io_mem_write_address 
            == vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit_io_load_mem_address_out) 
           & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__memoryData_io_mem_write));
    if (vlTOPp->test_bench_robin_core_v2__DOT__memoryData_io_mem_write) {
        __Vdlyvval__test_bench_robin_core_v2__DOT__memoryData__DOT__mem__v0 
            = vlTOPp->test_bench_robin_core_v2__DOT__memoryData_io_mem_write_data;
        __Vdlyvset__test_bench_robin_core_v2__DOT__memoryData__DOT__mem__v0 = 1U;
        __Vdlyvdim0__test_bench_robin_core_v2__DOT__memoryData__DOT__mem__v0 
            = (0x3ffU & vlTOPp->test_bench_robin_core_v2__DOT__memoryData_io_mem_write_address);
    }
    if (vlTOPp->reset) {
        vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__LOAD_SIZE = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__stateReg)))) {
            if (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_LOAD_ADDRESS_IN) {
                vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__LOAD_SIZE 
                    = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_LOAD_SIZE;
            }
        }
    }
    if (vlTOPp->reset) {
        __Vdly__test_bench_robin_core_v2__DOT__robinCore__DOT__INSTRUCTION_LOADED = 0U;
    } else {
        if (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__PROGRAM_LOADED) {
            __Vdly__test_bench_robin_core_v2__DOT__robinCore__DOT__INSTRUCTION_LOADED 
                = (1U & ((~ (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__INSTRUCTION_LOADED)) 
                         | (~ (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_UPDATE_PC))));
        }
    }
    if (vlTOPp->reset) {
        __Vdly__test_bench_robin_core_v2__DOT__robinCore__DOT__PROGRAM_LOADED = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__PROGRAM_LOADED)))) {
            __Vdly__test_bench_robin_core_v2__DOT__robinCore__DOT__PROGRAM_LOADED 
                = vlTOPp->test_bench_robin_core_v2__DOT__PROGRAM_LOADED;
        }
    }
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__LOAD_READY 
        = (1U & ((~ (IData)(vlTOPp->reset)) & ((~ (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__stateReg)) 
                                               & (~ (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_LOAD_ADDRESS_IN)))));
    if (((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD)))) {
        if ((0x12U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD))) {
            vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_18 
                = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD)))) {
        if ((0x11U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD))) {
            vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_17 
                = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD)))) {
        if ((0x10U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD))) {
            vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_16 
                = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD)))) {
        if ((0xfU == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD))) {
            vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_15 
                = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD)))) {
        if ((6U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD))) {
            vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_6 
                = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD)))) {
        if ((5U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD))) {
            vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_5 
                = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD)))) {
        if ((0xeU == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD))) {
            vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_14 
                = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD)))) {
        if ((4U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD))) {
            vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_4 
                = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD)))) {
        if ((3U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD))) {
            vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_3 
                = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD)))) {
        if ((0U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD))) {
            vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_0 
                = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD)))) {
        if ((2U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD))) {
            vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_2 
                = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD)))) {
        if ((0xdU == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD))) {
            vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_13 
                = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD)))) {
        if ((0x14U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD))) {
            vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_20 
                = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD)))) {
        if ((0xaU == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD))) {
            vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_10 
                = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD)))) {
        if ((0x13U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD))) {
            vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_19 
                = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD)))) {
        if ((9U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD))) {
            vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_9 
                = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD)))) {
        if ((1U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD))) {
            vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_1 
                = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD)))) {
        if ((0x15U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD))) {
            vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_21 
                = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD)))) {
        if ((0xbU == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD))) {
            vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_11 
                = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD)))) {
        if ((0xcU == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD))) {
            vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_12 
                = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD)))) {
        if ((7U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD))) {
            vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_7 
                = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD)))) {
        if ((8U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD))) {
            vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_8 
                = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    vlTOPp->test_bench_robin_core_v2__DOT__memoryInstruction__DOT__wrDataReg 
        = vlTOPp->io_mem_write_instruction;
    if (vlTOPp->io_signal_mem_write_instruction) {
        __Vdlyvval__test_bench_robin_core_v2__DOT__memoryInstruction__DOT__mem__v0 
            = vlTOPp->io_mem_write_instruction;
        __Vdlyvset__test_bench_robin_core_v2__DOT__memoryInstruction__DOT__mem__v0 = 1U;
        __Vdlyvdim0__test_bench_robin_core_v2__DOT__memoryInstruction__DOT__mem__v0 
            = (0x3ffU & vlTOPp->io_mem_write_address_instruction);
    }
    if (vlTOPp->reset) {
        vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__store_data_buffer = 0U;
    } else {
        if (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__storing) {
            vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__store_data_buffer 
                = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT___T_10;
        } else {
            if (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT___T) {
                if (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_DATA_IN) {
                    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__store_data_buffer 
                        = ((0U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                            ? 0U : (((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2) 
                                     == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD))
                                     ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__rdData
                                     : vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__rs2_ALU));
                }
            }
        }
    }
    __Vdly__test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__store_data_size_buffer 
        = ((IData)(vlTOPp->reset) ? 0U : ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__storing)
                                           ? ((3U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__store_data_size_buffer))
                                               ? (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT___GEN_11)
                                               : (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT___T_15))
                                           : (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT___GEN_11)));
    if (vlTOPp->reset) {
        vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__store_data_buffer_address = 0U;
    } else {
        if (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__storing) {
            vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__store_data_buffer_address 
                = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT___T_12;
        } else {
            if ((1U & (~ (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT___T)))) {
                if (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__stateReg) {
                    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__store_data_buffer_address 
                        = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT___GEN_4;
                }
            }
        }
    }
    __Vdly__test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__storing 
        = ((~ (IData)(vlTOPp->reset)) & ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__storing)
                                          ? ((3U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__store_data_size_buffer)) 
                                             & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT___GEN_14))
                                          : (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT___GEN_14)));
    __Vdly__test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__stateReg 
        = ((~ (IData)(vlTOPp->reset)) & ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__storing)
                                          ? ((3U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__store_data_size_buffer)) 
                                             & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT___GEN_9))
                                          : (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT___GEN_9)));
    if (vlTOPp->reset) {
        vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stallState = 5U;
    } else {
        if ((0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))) {
            if ((1U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))) {
                if ((0x23U == (0x7fU & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction))) {
                    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stallState 
                        = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___GEN_4;
                }
            } else {
                if ((2U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))) {
                    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stallState 
                        = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___GEN_51;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__EXTENSION = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__stateReg)))) {
            if (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_LOAD_ADDRESS_IN) {
                vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__EXTENSION 
                    = ((0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                       & ((1U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                          & ((2U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                             & ((3U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                                & (~ (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                      >> 0xeU))))));
            }
        }
    }
    if (vlTOPp->reset) {
        __Vdly__test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))) {
            if (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__INSTRUCTION_LOADED) {
                __Vdly__test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                    = vlTOPp->test_bench_robin_core_v2__DOT__memoryInstruction_io_rdData;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_buffer = 0U;
    } else {
        if (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT___T_10) {
            if (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_LOAD_ADDRESS_IN) {
                vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_buffer = 0U;
            }
        } else {
            if (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__stateReg) {
                vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_buffer 
                    = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT___T_13;
            }
        }
    }
    if (vlTOPp->reset) {
        __Vdly__test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_size_buffer = 0U;
    } else {
        if (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT___T_10) {
            if (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_LOAD_ADDRESS_IN) {
                __Vdly__test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_size_buffer 
                    = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_LOAD_SIZE;
            }
        } else {
            if (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__stateReg) {
                if ((3U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_size_buffer))) {
                    __Vdly__test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_size_buffer 
                        = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT___T_18;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_address_buffer = 0U;
    } else {
        if (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT___T_10) {
            if (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_LOAD_ADDRESS_IN) {
                vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_address_buffer 
                    = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT__ALUoutput;
            }
        } else {
            if (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__stateReg) {
                if ((3U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_size_buffer))) {
                    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_address_buffer 
                        = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT___T_16;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        __Vdly__test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__stateReg = 0U;
    } else {
        if (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT___T_10) {
            __Vdly__test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__stateReg 
                = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT___GEN_0;
        } else {
            if (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__stateReg) {
                if ((3U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_size_buffer))) {
                    __Vdly__test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__stateReg = 0U;
                }
            }
        }
    }
    vlTOPp->test_bench_robin_core_v2__DOT__memoryInstruction__DOT__mem_memData_addr_pipe_0 
        = (0x3ffU & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__PC 
                     >> 2U));
    vlTOPp->test_bench_robin_core_v2__DOT__memoryInstruction__DOT__doForwardReg 
        = ((vlTOPp->io_mem_write_address_instruction 
            == (0x3fffffffU & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__PC 
                               >> 2U))) & (IData)(vlTOPp->io_signal_mem_write_instruction));
    __Vdly__test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__ALU_in1 
        = ((IData)(vlTOPp->reset) ? 0U : (((0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                                           & ((1U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                                              & (0x17U 
                                                 == 
                                                 (0x7fU 
                                                  & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction))))
                                           ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__PC
                                           : ((0U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                               ? 0U
                                               : (((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1) 
                                                   == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD))
                                                   ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__rdData
                                                   : 
                                                  ((0U 
                                                    == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                                    ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT__ALUoutput
                                                    : 
                                                   ((0U 
                                                     == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                                     ? 0U
                                                     : 
                                                    ((0x1fU 
                                                      == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                                      ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_31
                                                      : 
                                                     ((0x1eU 
                                                       == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                                       ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_30
                                                       : 
                                                      ((0x1dU 
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
                                                               : vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT___GEN_21))))))))))))))));
    if (__Vdlyvset__test_bench_robin_core_v2__DOT__memoryData__DOT__mem__v0) {
        vlTOPp->test_bench_robin_core_v2__DOT__memoryData__DOT__mem[__Vdlyvdim0__test_bench_robin_core_v2__DOT__memoryData__DOT__mem__v0] 
            = __Vdlyvval__test_bench_robin_core_v2__DOT__memoryData__DOT__mem__v0;
    }
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__PROGRAM_LOADED 
        = __Vdly__test_bench_robin_core_v2__DOT__robinCore__DOT__PROGRAM_LOADED;
    if (__Vdlyvset__test_bench_robin_core_v2__DOT__memoryInstruction__DOT__mem__v0) {
        vlTOPp->test_bench_robin_core_v2__DOT__memoryInstruction__DOT__mem[__Vdlyvdim0__test_bench_robin_core_v2__DOT__memoryInstruction__DOT__mem__v0] 
            = __Vdlyvval__test_bench_robin_core_v2__DOT__memoryInstruction__DOT__mem__v0;
    }
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__store_data_size_buffer 
        = __Vdly__test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__store_data_size_buffer;
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__storing 
        = __Vdly__test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__storing;
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_size_buffer 
        = __Vdly__test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_size_buffer;
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__stateReg 
        = __Vdly__test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__stateReg;
    if (vlTOPp->reset) {
        vlTOPp->test_bench_robin_core_v2__DOT__PROGRAM_LOADED = 0U;
    } else {
        if (vlTOPp->test_bench_robin_core_v2__DOT___T_1) {
            vlTOPp->test_bench_robin_core_v2__DOT__PROGRAM_LOADED 
                = vlTOPp->io_START_PROGRAM;
        }
    }
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT___T_15 
        = (3U & ((IData)(1U) + (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__store_data_size_buffer)));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT___T_10 
        = (0xffffffU & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__store_data_buffer 
                        >> 8U));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT___T_12 
        = ((IData)(1U) + vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__store_data_buffer_address);
    vlTOPp->io_out_mem_write = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__storing;
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit_io_mem_write_data 
        = ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__storing)
            ? (0xffU & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__store_data_buffer)
            : 0U);
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit_io_mem_write_address 
        = ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__storing)
            ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__store_data_buffer_address
            : 0U);
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT___T_18 
        = (3U & ((IData)(1U) + (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_size_buffer)));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT___T_16 
        = ((IData)(1U) + vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_address_buffer);
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT___T_10 
        = (1U & (~ (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__stateReg)));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit_io_load_mem_address_out 
        = ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__stateReg)
            ? ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__stateReg)
                ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_address_buffer
                : 0U) : 0U);
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT___T_13 
        = ((0xffffff00U & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_buffer 
                           << 8U)) | ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__memoryData__DOT__doForwardReg)
                                       ? (IData)(vlTOPp->test_bench_robin_core_v2__DOT__memoryData__DOT__wrDataReg)
                                       : vlTOPp->test_bench_robin_core_v2__DOT__memoryData__DOT__mem
                                      [vlTOPp->test_bench_robin_core_v2__DOT__memoryData__DOT__mem_memData_addr_pipe_0]));
    vlTOPp->test_bench_robin_core_v2__DOT__memoryInstruction_io_rdData 
        = ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__memoryInstruction__DOT__doForwardReg)
            ? vlTOPp->test_bench_robin_core_v2__DOT__memoryInstruction__DOT__wrDataReg
            : vlTOPp->test_bench_robin_core_v2__DOT__memoryInstruction__DOT__mem
           [vlTOPp->test_bench_robin_core_v2__DOT__memoryInstruction__DOT__mem_memData_addr_pipe_0]);
    if (((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD)))) {
        if ((0x1fU == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD))) {
            vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_31 
                = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD)))) {
        if ((0x1eU == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD))) {
            vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_30 
                = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD)))) {
        if ((0x1dU == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD))) {
            vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_29 
                = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD)))) {
        if ((0x1cU == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD))) {
            vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_28 
                = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD)))) {
        if ((0x1bU == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD))) {
            vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_27 
                = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD)))) {
        if ((0x1aU == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD))) {
            vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_26 
                = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD)))) {
        if ((0x19U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD))) {
            vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_25 
                = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD)))) {
        if ((0x18U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD))) {
            vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_24 
                = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD)))) {
        if ((0x17U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD))) {
            vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_23 
                = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_WRITE_EN) 
         & (0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD)))) {
        if ((0x16U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD))) {
            vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_22 
                = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile_io_rdData;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__PC = 0U;
    } else {
        if (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_UPDATE_PC) {
            vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__PC 
                = (((0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                    & ((1U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                       & ((2U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                           ? (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___GEN_15)
                           : ((3U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                              & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___GEN_15)))))
                    ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT__ALUoutput
                    : ((1U & (((~ (((1U & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_BRANCH_SELECT))
                                     ? ((2U & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_BRANCH_SELECT))
                                         ? (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT__LESS_THAN)
                                         : (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT__SIGNED_LESS_THAN))
                                     : (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT__EQUAL)) 
                                   ^ ((0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                                      & ((1U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                                         & ((2U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
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
                                   >> 1U) | (~ (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_BRANCH_SELECT)))) 
                              | (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_PROCEDURE_BRANCHING)))
                        ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__branchImmBranchAddr
                        : vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__noBranchNextAddr));
        }
    }
    vlTOPp->io_out_mem_write_data = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit_io_mem_write_data;
    vlTOPp->io_out_mem_write_address = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit_io_mem_write_address;
    vlTOPp->io_INSTRUCTION = vlTOPp->test_bench_robin_core_v2__DOT__memoryInstruction_io_rdData;
    vlTOPp->test_bench_robin_core_v2__DOT___T_1 = (1U 
                                                   & (~ (IData)(vlTOPp->test_bench_robin_core_v2__DOT__PROGRAM_LOADED)));
    vlTOPp->io_PC = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__PC;
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__noBranchNextAddr 
        = ((IData)(4U) + vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__PC);
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT__LESS_THAN 
        = ((~ (IData)(vlTOPp->reset)) & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__ALU_in1 
                                         < vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__ALU_in2));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT__SIGNED_LESS_THAN 
        = ((~ (IData)(vlTOPp->reset)) & VL_LTS_III(1,32,32, vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__ALU_in1, vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__ALU_in2));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT__EQUAL 
        = ((IData)(vlTOPp->reset) | (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__ALU_in1 
                                     == vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__ALU_in2));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT__ALUoutput 
        = ((IData)(vlTOPp->reset) ? 0U : (IData)(((vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__ALU_in1 
                                                   < vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__ALU_in2)
                                                   ? 
                                                  ((3U 
                                                    == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_ALU_OP))
                                                    ? VL_ULL(1)
                                                    : vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT___GEN_11)
                                                   : vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT___GEN_11)));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__ALU_in1 
        = __Vdly__test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__ALU_in1;
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__ALU_in2 
        = ((IData)(vlTOPp->reset) ? 0U : (((0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                                           & ((1U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                                              & (~ 
                                                 ((0x33U 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction)) 
                                                  | (0x63U 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction))))))
                                           ? ((0U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                                               ? 0U
                                               : ((1U 
                                                   == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                                                   ? 
                                                  ((0x37U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction))
                                                    ? 
                                                   (0xfffff000U 
                                                    & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction)
                                                    : 
                                                   ((0xfffff000U 
                                                     & (VL_NEGATE_I((IData)(
                                                                            (1U 
                                                                             & ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___T_18) 
                                                                                >> 0xbU)))) 
                                                        << 0xcU)) 
                                                    | (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___T_18)))
                                                   : 0U))
                                           : ((0U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                               ? 0U
                                               : (((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2) 
                                                   == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD))
                                                   ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__rdData
                                                   : vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__rs2_ALU))));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT___T_3 
        = (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__ALU_in1 
           + vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__ALU_in2);
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT___T_7 
        = (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__ALU_in1 
           - vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__ALU_in2);
    if (vlTOPp->reset) {
        vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg = 0U;
    } else {
        if (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___T) {
            if (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__INSTRUCTION_LOADED) {
                vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg = 1U;
            }
        } else {
            vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg 
                = ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___T_2)
                    ? ((0x23U == (0x7fU & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction))
                        ? ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__STORE_READY)
                            ? 2U : 5U) : 2U) : ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___T_34)
                                                 ? 3U
                                                 : (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___GEN_48)));
        }
    }
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__INSTRUCTION_LOADED 
        = __Vdly__test_bench_robin_core_v2__DOT__robinCore__DOT__INSTRUCTION_LOADED;
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
        = __Vdly__test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction;
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__STORE_READY 
        = (1U & ((~ (IData)(vlTOPp->reset)) & (~ (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__stateReg))));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___T_18 
        = (0xfffU & ((0x23U == (0x7fU & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction))
                      ? ((0xfe0U & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                    >> 0x14U)) | (0x1fU 
                                                  & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                                     >> 7U)))
                      : (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                         >> 0x14U)));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___GEN_15 
        = ((0x67U == (0x77U & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction)) 
           & (0x67U == (0x7fU & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction)));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___T_65 
        = ((0x1000U & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                       >> 0x13U)) | ((0x800U & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                                << 4U)) 
                                     | ((0x7e0U & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                                   >> 0x14U)) 
                                        | (0x1eU & 
                                           (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                            >> 7U)))));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___T_66 
        = ((0x100000U & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                         >> 0xbU)) | ((0xff000U & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction) 
                                      | ((0x800U & 
                                          (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                           >> 9U)) 
                                         | (0x7feU 
                                            & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                               >> 0x14U)))));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___T 
        = (0U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___T_2 
        = (1U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___T_34 
        = (2U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_UPDATE_PC 
        = ((0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
           & ((1U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
              & ((2U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                 & (3U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)))));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD 
        = ((0U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
            ? 0U : ((1U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                     ? 0U : (0x1fU & ((2U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                                       ? ((0x67U == 
                                           (0x77U & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction))
                                           ? (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                              >> 7U)
                                           : 0U) : 
                                      ((3U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                                        ? (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                           >> 7U) : 
                                       ((4U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                                         ? (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                            >> 7U) : 0U))))));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_LOAD_SIZE 
        = ((0U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
            ? 0U : ((1U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                     ? 0U : ((2U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                              ? 0U : ((3U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                                       ? ((2U == (3U 
                                                  & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                                     >> 0xcU)))
                                           ? 3U : (3U 
                                                   & (~ 
                                                      (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                                       >> 0xcU))))
                                       : 0U))));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_BRANCH_SELECT 
        = ((0U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
            ? 1U : ((1U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                     ? 1U : ((2U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                              ? 1U : ((3U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                                       ? ((0x63U == 
                                           (0x7fU & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction))
                                           ? (3U & 
                                              (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                               >> 0xdU))
                                           : 1U) : 1U))));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___GEN_51 
        = ((3U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
            ? (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stallState)
            : ((4U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                ? ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__LOAD_READY)
                    ? (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stallState)
                    : (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                : (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stallState)));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_LOAD_ADDRESS_IN 
        = ((0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
           & ((1U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
              & ((2U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                 & ((3U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                    & (3U == (0x7fU & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction))))));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_PROCEDURE_BRANCHING 
        = ((0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
           & ((1U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
              & ((2U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                  ? (0x67U == (0x77U & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction))
                  : ((3U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                     & (0x67U == (0x77U & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction))))));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_STORE_ADDRESS_IN 
        = ((0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
           & ((1U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
              & ((2U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                 & ((3U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                    & (0x23U == (0x7fU & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction))))));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1 
        = ((0U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
            ? 0U : ((1U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                     ? ((0x37U == vlTOPp->test_bench_robin_core_v2__DOT__memoryInstruction_io_rdData)
                         ? 0U : (0x1fU & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                          >> 0xfU)))
                     : 0U));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___GEN_36 
        = ((4U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
           & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__LOAD_READY));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2 
        = ((0U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
            ? 0U : ((1U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                     ? (0x1fU & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                 >> 0x14U)) : 0U));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_ALU_OP 
        = ((0U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
            ? 0U : ((1U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                     ? 0U : ((2U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                              ? ((0x13U == (0x7fU & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction))
                                  ? ((0x18U & (((1U 
                                                 == 
                                                 (3U 
                                                  & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                                     >> 0xcU))) 
                                                << 3U) 
                                               & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                                  >> 0x1bU))) 
                                     | (7U & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                              >> 0xcU)))
                                  : ((0x33U == (0x7fU 
                                                & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction))
                                      ? ((8U & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                                >> 0x1bU)) 
                                         | (7U & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                                  >> 0xcU)))
                                      : 0U)) : 0U)));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__stateReg 
        = __Vdly__test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__stateReg;
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__branchImmBranchAddr 
        = (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__PC 
           + ((0U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
               ? 0U : ((1U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                        ? 0U : ((2U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                                 ? 0U : ((3U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                                          ? ((0x63U 
                                              == (0x7fU 
                                                  & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction))
                                              ? ((0x80000000U 
                                                  & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction)
                                                  ? 
                                                 (0xffffe000U 
                                                  | (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___T_65))
                                                  : (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___T_65))
                                              : ((0x80000000U 
                                                  & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction)
                                                  ? 
                                                 (0xffe00000U 
                                                  | vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___T_66)
                                                  : vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___T_66))
                                          : 0U)))));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT___GEN_0 
        = ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_LOAD_ADDRESS_IN) 
           | (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__stateReg));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT___GEN_4 
        = (((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_STORE_ADDRESS_IN) 
            & (~ (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__storing)))
            ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT__ALUoutput
            : vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__store_data_buffer_address);
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT___GEN_21 
        = ((0x15U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
            ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_21
            : ((0x14U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_20
                : ((0x13U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                    ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_19
                    : ((0x12U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                        ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_18
                        : ((0x11U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                            ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_17
                            : ((0x10U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_16
                                : ((0xfU == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                    ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_15
                                    : ((0xeU == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                        ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_14
                                        : ((0xdU == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                            ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_13
                                            : ((0xcU 
                                                == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                                ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_12
                                                : (
                                                   (0xbU 
                                                    == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                                    ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_11
                                                    : 
                                                   ((0xaU 
                                                     == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                                     ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_10
                                                     : 
                                                    ((9U 
                                                      == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                                      ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_9
                                                      : 
                                                     ((8U 
                                                       == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                                       ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_8
                                                       : 
                                                      ((7U 
                                                        == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                                        ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_7
                                                        : 
                                                       ((6U 
                                                         == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                                         ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_6
                                                         : 
                                                        ((5U 
                                                          == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                                          ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_5
                                                          : 
                                                         ((4U 
                                                           == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                                           ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_4
                                                           : 
                                                          ((3U 
                                                            == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                                            ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_3
                                                            : 
                                                           ((2U 
                                                             == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                                             ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_2
                                                             : 
                                                            ((1U 
                                                              == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                                              ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_1
                                                              : vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_0)))))))))))))))))))));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_WRITE_EN 
        = ((0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
           & ((1U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
              & ((2U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                  ? (0x67U == (0x77U & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction))
                  : ((3U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                      ? (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                         >> 4U) : (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___GEN_36)))));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__rdData 
        = (((0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
            & ((1U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
               & ((2U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                  & ((3U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                     & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___GEN_36)))))
            ? ((0xffffff00U & ((0xffffff00U & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_buffer) 
                               | (((((1U & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__LOAD_SIZE))
                                      ? (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_buffer 
                                         >> 7U) : (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_buffer 
                                                   >> 0xfU)) 
                                    & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__EXTENSION))
                                    ? ((((2U & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__LOAD_SIZE))
                                          ? 0xffffU
                                          : 0U) << 8U) 
                                       | ((3U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__LOAD_SIZE))
                                           ? 0xffU : 0U))
                                    : 0U) << 8U))) 
               | (0xffU & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_buffer))
            : vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT__ALUoutput);
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT___GEN_54 
        = ((0x15U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
            ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_21
            : ((0x14U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_20
                : ((0x13U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                    ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_19
                    : ((0x12U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                        ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_18
                        : ((0x11U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                            ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_17
                            : ((0x10U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_16
                                : ((0xfU == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                    ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_15
                                    : ((0xeU == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                        ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_14
                                        : ((0xdU == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                            ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_13
                                            : ((0xcU 
                                                == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                                ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_12
                                                : (
                                                   (0xbU 
                                                    == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                                    ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_11
                                                    : 
                                                   ((0xaU 
                                                     == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                                     ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_10
                                                     : 
                                                    ((9U 
                                                      == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                                      ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_9
                                                      : 
                                                     ((8U 
                                                       == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                                       ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_8
                                                       : 
                                                      ((7U 
                                                        == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                                        ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_7
                                                        : 
                                                       ((6U 
                                                         == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                                         ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_6
                                                         : 
                                                        ((5U 
                                                          == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                                          ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_5
                                                          : 
                                                         ((4U 
                                                           == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                                           ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_4
                                                           : 
                                                          ((3U 
                                                            == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                                            ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_3
                                                            : 
                                                           ((2U 
                                                             == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                                             ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_2
                                                             : 
                                                            ((1U 
                                                              == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                                              ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_1
                                                              : vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_0)))))))))))))))))))));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT___GEN_4 
        = ((5U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_ALU_OP))
            ? (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__ALU_in1 
               >> (0x1fU & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__ALU_in2))
            : ((0xdU == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_ALU_OP))
                ? VL_SHIFTRS_III(32,32,5, vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__ALU_in1, 
                                 (0x1fU & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__ALU_in2))
                : ((4U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_ALU_OP))
                    ? (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__ALU_in1 
                       ^ vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__ALU_in2)
                    : ((6U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_ALU_OP))
                        ? (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__ALU_in1 
                           | vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__ALU_in2)
                        : ((7U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_ALU_OP))
                            ? (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__ALU_in1 
                               & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__ALU_in2)
                            : vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT__ALUoutput)))));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT___T 
        = (1U & (~ (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__stateReg)));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT___GEN_14 
        = ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__stateReg)
            ? ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__stateReg)
                ? ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_STORE_ADDRESS_IN) 
                   | (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__storing))
                : (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__storing))
            : (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__storing));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___GEN_48 
        = ((3U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
            ? ((3U == (0x7fU & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction))
                ? 4U : 0U) : ((4U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                               ? ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__LOAD_READY)
                                   ? 0U : 5U) : ((5U 
                                                  == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                                                  ? 
                                                 ((1U 
                                                   == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stallState))
                                                   ? 
                                                  ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__stateReg)
                                                    ? (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)
                                                    : (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stallState))
                                                   : 
                                                  ((4U 
                                                    == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stallState))
                                                    ? 
                                                   ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__LOAD_READY)
                                                     ? (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stallState)
                                                     : (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                                                    : (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)))
                                                  : (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___GEN_4 
        = ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__STORE_READY)
            ? (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stallState)
            : (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_DATA_IN 
        = ((0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
           & ((1U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
              & ((0x23U == (0x7fU & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction)) 
                 & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__STORE_READY))));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile_io_rdData 
        = ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_PROCEDURE_BRANCHING)
            ? ((IData)(4U) + vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__PC)
            : vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__rdData);
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__rs2_ALU 
        = ((0U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
            ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT__ALUoutput
            : ((0U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                ? 0U : ((0x1fU == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                         ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_31
                         : ((0x1eU == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                             ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_30
                             : ((0x1dU == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                 ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_29
                                 : ((0x1cU == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                     ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_28
                                     : ((0x1bU == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                         ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_27
                                         : ((0x1aU 
                                             == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                             ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_26
                                             : ((0x19U 
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
                                                    : vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT___GEN_54))))))))))));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT___GEN_7 
        = (VL_ULL(0x7fffffffffffffff) & ((0U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_ALU_OP))
                                          ? (((QData)((IData)(
                                                              (0x7fffffffU 
                                                               & VL_NEGATE_I((IData)(
                                                                                (1U 
                                                                                & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT___T_3 
                                                                                >> 0x1fU))))))) 
                                              << 0x20U) 
                                             | (QData)((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT___T_3)))
                                          : ((8U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_ALU_OP))
                                              ? (((QData)((IData)(
                                                                  (0x7fffffffU 
                                                                   & VL_NEGATE_I((IData)(
                                                                                (1U 
                                                                                & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT___T_7 
                                                                                >> 0x1fU))))))) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT___T_7)))
                                              : ((1U 
                                                  == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_ALU_OP))
                                                  ? 
                                                 ((((QData)((IData)(
                                                                    (0x7fffffffU 
                                                                     & VL_NEGATE_I((IData)(
                                                                                (1U 
                                                                                & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__ALU_in1 
                                                                                >> 0x1fU))))))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__ALU_in1))) 
                                                  << 
                                                  (0x1fU 
                                                   & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__ALU_in2))
                                                  : 
                                                 (((QData)((IData)(
                                                                   (0x7fffffffU 
                                                                    & VL_NEGATE_I((IData)(
                                                                                (1U 
                                                                                & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT___GEN_4 
                                                                                >> 0x1fU))))))) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT___GEN_4)))))));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT___GEN_9 
        = ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__stateReg)
            ? (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__stateReg)
            : ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_DATA_IN) 
               | (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__stateReg)));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT___GEN_11 
        = (3U & ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__stateReg)
                  ? (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__store_data_size_buffer)
                  : ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_DATA_IN)
                      ? ((0U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                          ? 1U : ((1U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                                   ? ((0x23U == (0x7fU 
                                                 & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction))
                                       ? ((0x2000U 
                                           & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction)
                                           ? 0U : (~ 
                                                   (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                                    >> 0xcU)))
                                       : 1U) : 1U))
                      : (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__store_data_size_buffer))));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT___GEN_11 
        = (VL_LTS_III(1,32,32, vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__ALU_in1, vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__ALU_in2)
            ? ((2U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_ALU_OP))
                ? VL_ULL(1) : vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT___GEN_7)
            : vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT___GEN_7);
}

void Vtest_bench_robin_core_v2::_settle__TOP__3(Vtest_bench_robin_core_v2__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_bench_robin_core_v2::_settle__TOP__3\n"); );
    Vtest_bench_robin_core_v2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->io_out_mem_write = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__storing;
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT___T_10 
        = (0xffffffU & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__store_data_buffer 
                        >> 8U));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT___T_12 
        = ((IData)(1U) + vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__store_data_buffer_address);
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT___T_15 
        = (3U & ((IData)(1U) + (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__store_data_size_buffer)));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT___T_10 
        = (1U & (~ (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__stateReg)));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT___T_16 
        = ((IData)(1U) + vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_address_buffer);
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT___T_18 
        = (3U & ((IData)(1U) + (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_size_buffer)));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit_io_load_mem_address_out 
        = ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__stateReg)
            ? ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__stateReg)
                ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_address_buffer
                : 0U) : 0U);
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT___T_13 
        = ((0xffffff00U & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_buffer 
                           << 8U)) | ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__memoryData__DOT__doForwardReg)
                                       ? (IData)(vlTOPp->test_bench_robin_core_v2__DOT__memoryData__DOT__wrDataReg)
                                       : vlTOPp->test_bench_robin_core_v2__DOT__memoryData__DOT__mem
                                      [vlTOPp->test_bench_robin_core_v2__DOT__memoryData__DOT__mem_memData_addr_pipe_0]));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit_io_mem_write_data 
        = ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__storing)
            ? (0xffU & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__store_data_buffer)
            : 0U);
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit_io_mem_write_address 
        = ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__storing)
            ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__store_data_buffer_address
            : 0U);
    vlTOPp->test_bench_robin_core_v2__DOT__memoryInstruction_io_rdData 
        = ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__memoryInstruction__DOT__doForwardReg)
            ? vlTOPp->test_bench_robin_core_v2__DOT__memoryInstruction__DOT__wrDataReg
            : vlTOPp->test_bench_robin_core_v2__DOT__memoryInstruction__DOT__mem
           [vlTOPp->test_bench_robin_core_v2__DOT__memoryInstruction__DOT__mem_memData_addr_pipe_0]);
    vlTOPp->test_bench_robin_core_v2__DOT___T_1 = (1U 
                                                   & (~ (IData)(vlTOPp->test_bench_robin_core_v2__DOT__PROGRAM_LOADED)));
    vlTOPp->io_PC = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__PC;
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__noBranchNextAddr 
        = ((IData)(4U) + vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__PC);
    vlTOPp->test_bench_robin_core_v2__DOT__memoryData_io_mem_write 
        = ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__PROGRAM_LOADED)
            ? ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__PROGRAM_LOADED) 
               & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__storing))
            : (IData)(vlTOPp->io_signal_mem_write_data));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT___T_3 
        = (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__ALU_in1 
           + vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__ALU_in2);
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT___T_7 
        = (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__ALU_in1 
           - vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__ALU_in2);
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___T 
        = (0U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___T_2 
        = (1U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___T_18 
        = (0xfffU & ((0x23U == (0x7fU & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction))
                      ? ((0xfe0U & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                    >> 0x14U)) | (0x1fU 
                                                  & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                                     >> 7U)))
                      : (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                         >> 0x14U)));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___T_34 
        = (2U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___GEN_15 
        = ((0x67U == (0x77U & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction)) 
           & (0x67U == (0x7fU & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction)));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_UPDATE_PC 
        = ((0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
           & ((1U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
              & ((2U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                 & (3U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)))));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD 
        = ((0U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
            ? 0U : ((1U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                     ? 0U : (0x1fU & ((2U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                                       ? ((0x67U == 
                                           (0x77U & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction))
                                           ? (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                              >> 7U)
                                           : 0U) : 
                                      ((3U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                                        ? (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                           >> 7U) : 
                                       ((4U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                                         ? (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                            >> 7U) : 0U))))));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_LOAD_SIZE 
        = ((0U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
            ? 0U : ((1U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                     ? 0U : ((2U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                              ? 0U : ((3U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                                       ? ((2U == (3U 
                                                  & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                                     >> 0xcU)))
                                           ? 3U : (3U 
                                                   & (~ 
                                                      (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                                       >> 0xcU))))
                                       : 0U))));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_BRANCH_SELECT 
        = ((0U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
            ? 1U : ((1U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                     ? 1U : ((2U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                              ? 1U : ((3U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                                       ? ((0x63U == 
                                           (0x7fU & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction))
                                           ? (3U & 
                                              (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                               >> 0xdU))
                                           : 1U) : 1U))));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___GEN_51 
        = ((3U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
            ? (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stallState)
            : ((4U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                ? ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__LOAD_READY)
                    ? (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stallState)
                    : (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                : (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stallState)));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_LOAD_ADDRESS_IN 
        = ((0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
           & ((1U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
              & ((2U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                 & ((3U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                    & (3U == (0x7fU & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction))))));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_PROCEDURE_BRANCHING 
        = ((0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
           & ((1U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
              & ((2U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                  ? (0x67U == (0x77U & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction))
                  : ((3U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                     & (0x67U == (0x77U & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction))))));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___T_65 
        = ((0x1000U & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                       >> 0x13U)) | ((0x800U & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                                << 4U)) 
                                     | ((0x7e0U & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                                   >> 0x14U)) 
                                        | (0x1eU & 
                                           (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                            >> 7U)))));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___T_66 
        = ((0x100000U & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                         >> 0xbU)) | ((0xff000U & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction) 
                                      | ((0x800U & 
                                          (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                           >> 9U)) 
                                         | (0x7feU 
                                            & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                               >> 0x14U)))));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_STORE_ADDRESS_IN 
        = ((0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
           & ((1U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
              & ((2U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                 & ((3U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                    & (0x23U == (0x7fU & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction))))));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___GEN_36 
        = ((4U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
           & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__LOAD_READY));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2 
        = ((0U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
            ? 0U : ((1U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                     ? (0x1fU & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                 >> 0x14U)) : 0U));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_ALU_OP 
        = ((0U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
            ? 0U : ((1U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                     ? 0U : ((2U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                              ? ((0x13U == (0x7fU & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction))
                                  ? ((0x18U & (((1U 
                                                 == 
                                                 (3U 
                                                  & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                                     >> 0xcU))) 
                                                << 3U) 
                                               & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                                  >> 0x1bU))) 
                                     | (7U & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                              >> 0xcU)))
                                  : ((0x33U == (0x7fU 
                                                & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction))
                                      ? ((8U & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                                >> 0x1bU)) 
                                         | (7U & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                                  >> 0xcU)))
                                      : 0U)) : 0U)));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT___T 
        = (1U & (~ (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__stateReg)));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___GEN_4 
        = ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__STORE_READY)
            ? (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stallState)
            : (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___GEN_48 
        = ((3U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
            ? ((3U == (0x7fU & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction))
                ? 4U : 0U) : ((4U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                               ? ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__LOAD_READY)
                                   ? 0U : 5U) : ((5U 
                                                  == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                                                  ? 
                                                 ((1U 
                                                   == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stallState))
                                                   ? 
                                                  ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__stateReg)
                                                    ? (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)
                                                    : (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stallState))
                                                   : 
                                                  ((4U 
                                                    == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stallState))
                                                    ? 
                                                   ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__LOAD_READY)
                                                     ? (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stallState)
                                                     : (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                                                    : (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)))
                                                  : (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_DATA_IN 
        = ((0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
           & ((1U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
              & ((0x23U == (0x7fU & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction)) 
                 & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__STORE_READY))));
    vlTOPp->io_out_mem_write_data = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit_io_mem_write_data;
    vlTOPp->test_bench_robin_core_v2__DOT__memoryData_io_mem_write_data 
        = ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__PROGRAM_LOADED)
            ? ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__PROGRAM_LOADED)
                ? (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit_io_mem_write_data)
                : 0U) : (IData)(vlTOPp->io_mem_write_data));
    vlTOPp->io_out_mem_write_address = vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit_io_mem_write_address;
    vlTOPp->test_bench_robin_core_v2__DOT__memoryData_io_mem_write_address 
        = ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__PROGRAM_LOADED)
            ? ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__PROGRAM_LOADED)
                ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit_io_mem_write_address
                : 0U) : vlTOPp->io_mem_write_address_data);
    vlTOPp->io_INSTRUCTION = vlTOPp->test_bench_robin_core_v2__DOT__memoryInstruction_io_rdData;
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1 
        = ((0U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
            ? 0U : ((1U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                     ? ((0x37U == vlTOPp->test_bench_robin_core_v2__DOT__memoryInstruction_io_rdData)
                         ? 0U : (0x1fU & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                          >> 0xfU)))
                     : 0U));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT___GEN_0 
        = ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_LOAD_ADDRESS_IN) 
           | (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__stateReg));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__branchImmBranchAddr 
        = (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__PC 
           + ((0U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
               ? 0U : ((1U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                        ? 0U : ((2U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                                 ? 0U : ((3U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                                          ? ((0x63U 
                                              == (0x7fU 
                                                  & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction))
                                              ? ((0x80000000U 
                                                  & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction)
                                                  ? 
                                                 (0xffffe000U 
                                                  | (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___T_65))
                                                  : (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___T_65))
                                              : ((0x80000000U 
                                                  & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction)
                                                  ? 
                                                 (0xffe00000U 
                                                  | vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___T_66)
                                                  : vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___T_66))
                                          : 0U)))));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT___GEN_4 
        = (((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_STORE_ADDRESS_IN) 
            & (~ (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__storing)))
            ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT__ALUoutput
            : vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__store_data_buffer_address);
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT___GEN_14 
        = ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__stateReg)
            ? ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__stateReg)
                ? ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_STORE_ADDRESS_IN) 
                   | (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__storing))
                : (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__storing))
            : (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__storing));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_WRITE_EN 
        = ((0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
           & ((1U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
              & ((2U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                  ? (0x67U == (0x77U & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction))
                  : ((3U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                      ? (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                         >> 4U) : (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___GEN_36)))));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__rdData 
        = (((0U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
            & ((1U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
               & ((2U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                  & ((3U != (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg)) 
                     & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___GEN_36)))))
            ? ((0xffffff00U & ((0xffffff00U & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_buffer) 
                               | (((((1U & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__LOAD_SIZE))
                                      ? (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_buffer 
                                         >> 7U) : (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_buffer 
                                                   >> 0xfU)) 
                                    & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__EXTENSION))
                                    ? ((((2U & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__LOAD_SIZE))
                                          ? 0xffffU
                                          : 0U) << 8U) 
                                       | ((3U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__LOAD_SIZE))
                                           ? 0xffU : 0U))
                                    : 0U) << 8U))) 
               | (0xffU & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_buffer))
            : vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT__ALUoutput);
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT___GEN_54 
        = ((0x15U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
            ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_21
            : ((0x14U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_20
                : ((0x13U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                    ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_19
                    : ((0x12U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                        ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_18
                        : ((0x11U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                            ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_17
                            : ((0x10U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_16
                                : ((0xfU == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                    ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_15
                                    : ((0xeU == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                        ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_14
                                        : ((0xdU == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                            ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_13
                                            : ((0xcU 
                                                == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                                ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_12
                                                : (
                                                   (0xbU 
                                                    == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                                    ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_11
                                                    : 
                                                   ((0xaU 
                                                     == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                                     ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_10
                                                     : 
                                                    ((9U 
                                                      == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                                      ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_9
                                                      : 
                                                     ((8U 
                                                       == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                                       ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_8
                                                       : 
                                                      ((7U 
                                                        == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                                        ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_7
                                                        : 
                                                       ((6U 
                                                         == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                                         ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_6
                                                         : 
                                                        ((5U 
                                                          == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                                          ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_5
                                                          : 
                                                         ((4U 
                                                           == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                                           ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_4
                                                           : 
                                                          ((3U 
                                                            == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                                            ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_3
                                                            : 
                                                           ((2U 
                                                             == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                                             ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_2
                                                             : 
                                                            ((1U 
                                                              == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                                              ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_1
                                                              : vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_0)))))))))))))))))))));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT___GEN_4 
        = ((5U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_ALU_OP))
            ? (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__ALU_in1 
               >> (0x1fU & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__ALU_in2))
            : ((0xdU == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_ALU_OP))
                ? VL_SHIFTRS_III(32,32,5, vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__ALU_in1, 
                                 (0x1fU & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__ALU_in2))
                : ((4U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_ALU_OP))
                    ? (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__ALU_in1 
                       ^ vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__ALU_in2)
                    : ((6U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_ALU_OP))
                        ? (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__ALU_in1 
                           | vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__ALU_in2)
                        : ((7U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_ALU_OP))
                            ? (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__ALU_in1 
                               & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__ALU_in2)
                            : vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT__ALUoutput)))));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT___GEN_9 
        = ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__stateReg)
            ? (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__stateReg)
            : ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_DATA_IN) 
               | (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__stateReg)));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT___GEN_11 
        = (3U & ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__stateReg)
                  ? (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__store_data_size_buffer)
                  : ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_DATA_IN)
                      ? ((0U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                          ? 1U : ((1U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg))
                                   ? ((0x23U == (0x7fU 
                                                 & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction))
                                       ? ((0x2000U 
                                           & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction)
                                           ? 0U : (~ 
                                                   (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction 
                                                    >> 0xcU)))
                                       : 1U) : 1U))
                      : (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__store_data_size_buffer))));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT___GEN_21 
        = ((0x15U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
            ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_21
            : ((0x14U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_20
                : ((0x13U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                    ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_19
                    : ((0x12U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                        ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_18
                        : ((0x11U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                            ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_17
                            : ((0x10U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_16
                                : ((0xfU == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                    ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_15
                                    : ((0xeU == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                        ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_14
                                        : ((0xdU == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                            ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_13
                                            : ((0xcU 
                                                == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                                ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_12
                                                : (
                                                   (0xbU 
                                                    == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                                    ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_11
                                                    : 
                                                   ((0xaU 
                                                     == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                                     ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_10
                                                     : 
                                                    ((9U 
                                                      == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                                      ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_9
                                                      : 
                                                     ((8U 
                                                       == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                                       ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_8
                                                       : 
                                                      ((7U 
                                                        == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                                        ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_7
                                                        : 
                                                       ((6U 
                                                         == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                                         ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_6
                                                         : 
                                                        ((5U 
                                                          == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                                          ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_5
                                                          : 
                                                         ((4U 
                                                           == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                                           ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_4
                                                           : 
                                                          ((3U 
                                                            == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                                            ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_3
                                                            : 
                                                           ((2U 
                                                             == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                                             ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_2
                                                             : 
                                                            ((1U 
                                                              == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1))
                                                              ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_1
                                                              : vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_0)))))))))))))))))))));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile_io_rdData 
        = ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_PROCEDURE_BRANCHING)
            ? ((IData)(4U) + vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__PC)
            : vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__rdData);
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__rs2_ALU 
        = ((0U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
            ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT__ALUoutput
            : ((0U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                ? 0U : ((0x1fU == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                         ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_31
                         : ((0x1eU == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                             ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_30
                             : ((0x1dU == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                 ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_29
                                 : ((0x1cU == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                     ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_28
                                     : ((0x1bU == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                         ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_27
                                         : ((0x1aU 
                                             == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2))
                                             ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_26
                                             : ((0x19U 
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
                                                    : vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT___GEN_54))))))))))));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT___GEN_7 
        = (VL_ULL(0x7fffffffffffffff) & ((0U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_ALU_OP))
                                          ? (((QData)((IData)(
                                                              (0x7fffffffU 
                                                               & VL_NEGATE_I((IData)(
                                                                                (1U 
                                                                                & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT___T_3 
                                                                                >> 0x1fU))))))) 
                                              << 0x20U) 
                                             | (QData)((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT___T_3)))
                                          : ((8U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_ALU_OP))
                                              ? (((QData)((IData)(
                                                                  (0x7fffffffU 
                                                                   & VL_NEGATE_I((IData)(
                                                                                (1U 
                                                                                & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT___T_7 
                                                                                >> 0x1fU))))))) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT___T_7)))
                                              : ((1U 
                                                  == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_ALU_OP))
                                                  ? 
                                                 ((((QData)((IData)(
                                                                    (0x7fffffffU 
                                                                     & VL_NEGATE_I((IData)(
                                                                                (1U 
                                                                                & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__ALU_in1 
                                                                                >> 0x1fU))))))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__ALU_in1))) 
                                                  << 
                                                  (0x1fU 
                                                   & vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__ALU_in2))
                                                  : 
                                                 (((QData)((IData)(
                                                                   (0x7fffffffU 
                                                                    & VL_NEGATE_I((IData)(
                                                                                (1U 
                                                                                & (vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT___GEN_4 
                                                                                >> 0x1fU))))))) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT___GEN_4)))))));
    vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT___GEN_11 
        = (VL_LTS_III(1,32,32, vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__ALU_in1, vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__ALU_in2)
            ? ((2U == (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_ALU_OP))
                ? VL_ULL(1) : vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT___GEN_7)
            : vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT___GEN_7);
}

VL_INLINE_OPT void Vtest_bench_robin_core_v2::_combo__TOP__4(Vtest_bench_robin_core_v2__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_bench_robin_core_v2::_combo__TOP__4\n"); );
    Vtest_bench_robin_core_v2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->test_bench_robin_core_v2__DOT__memoryData_io_mem_write 
        = ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__PROGRAM_LOADED)
            ? ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__PROGRAM_LOADED) 
               & (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__storing))
            : (IData)(vlTOPp->io_signal_mem_write_data));
    vlTOPp->test_bench_robin_core_v2__DOT__memoryData_io_mem_write_data 
        = ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__PROGRAM_LOADED)
            ? ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__PROGRAM_LOADED)
                ? (IData)(vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit_io_mem_write_data)
                : 0U) : (IData)(vlTOPp->io_mem_write_data));
    vlTOPp->test_bench_robin_core_v2__DOT__memoryData_io_mem_write_address 
        = ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__PROGRAM_LOADED)
            ? ((IData)(vlTOPp->test_bench_robin_core_v2__DOT__PROGRAM_LOADED)
                ? vlTOPp->test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit_io_mem_write_address
                : 0U) : vlTOPp->io_mem_write_address_data);
}

void Vtest_bench_robin_core_v2::_eval(Vtest_bench_robin_core_v2__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_bench_robin_core_v2::_eval\n"); );
    Vtest_bench_robin_core_v2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock)))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
        vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
    }
    vlTOPp->_combo__TOP__4(vlSymsp);
    vlTOPp->__Vm_traceActivity = (4U | vlTOPp->__Vm_traceActivity);
    // Final
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void Vtest_bench_robin_core_v2::_eval_initial(Vtest_bench_robin_core_v2__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_bench_robin_core_v2::_eval_initial\n"); );
    Vtest_bench_robin_core_v2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void Vtest_bench_robin_core_v2::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_bench_robin_core_v2::final\n"); );
    // Variables
    Vtest_bench_robin_core_v2__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtest_bench_robin_core_v2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtest_bench_robin_core_v2::_eval_settle(Vtest_bench_robin_core_v2__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_bench_robin_core_v2::_eval_settle\n"); );
    Vtest_bench_robin_core_v2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
}

VL_INLINE_OPT QData Vtest_bench_robin_core_v2::_change_request(Vtest_bench_robin_core_v2__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_bench_robin_core_v2::_change_request\n"); );
    Vtest_bench_robin_core_v2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vtest_bench_robin_core_v2::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_bench_robin_core_v2::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((io_signal_mem_write_data & 0xfeU))) {
        Verilated::overWidthError("io_signal_mem_write_data");}
    if (VL_UNLIKELY((io_signal_mem_write_instruction 
                     & 0xfeU))) {
        Verilated::overWidthError("io_signal_mem_write_instruction");}
    if (VL_UNLIKELY((io_START_PROGRAM & 0xfeU))) {
        Verilated::overWidthError("io_START_PROGRAM");}
}
#endif  // VL_DEBUG

void Vtest_bench_robin_core_v2::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_bench_robin_core_v2::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    io_signal_mem_write_data = VL_RAND_RESET_I(1);
    io_mem_write_data = VL_RAND_RESET_I(8);
    io_mem_write_address_data = VL_RAND_RESET_I(32);
    io_signal_mem_write_instruction = VL_RAND_RESET_I(1);
    io_mem_write_instruction = VL_RAND_RESET_I(32);
    io_mem_write_address_instruction = VL_RAND_RESET_I(32);
    io_START_PROGRAM = VL_RAND_RESET_I(1);
    io_outputSake = VL_RAND_RESET_I(1);
    io_out_mem_write = VL_RAND_RESET_I(1);
    io_out_mem_write_data = VL_RAND_RESET_I(8);
    io_out_mem_write_address = VL_RAND_RESET_I(32);
    io_INSTRUCTION = VL_RAND_RESET_I(32);
    io_PC = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__memoryData_io_mem_write = VL_RAND_RESET_I(1);
    test_bench_robin_core_v2__DOT__memoryData_io_mem_write_data = VL_RAND_RESET_I(8);
    test_bench_robin_core_v2__DOT__memoryData_io_mem_write_address = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__memoryInstruction_io_rdData = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__PROGRAM_LOADED = VL_RAND_RESET_I(1);
    test_bench_robin_core_v2__DOT___T_1 = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<1024; ++__Vi0) {
            test_bench_robin_core_v2__DOT__memoryData__DOT__mem[__Vi0] = VL_RAND_RESET_I(8);
    }}
    test_bench_robin_core_v2__DOT__memoryData__DOT__mem_memData_addr_pipe_0 = VL_RAND_RESET_I(10);
    test_bench_robin_core_v2__DOT__memoryData__DOT__wrDataReg = VL_RAND_RESET_I(8);
    test_bench_robin_core_v2__DOT__memoryData__DOT__doForwardReg = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<1024; ++__Vi0) {
            test_bench_robin_core_v2__DOT__memoryInstruction__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }}
    test_bench_robin_core_v2__DOT__memoryInstruction__DOT__mem_memData_addr_pipe_0 = VL_RAND_RESET_I(10);
    test_bench_robin_core_v2__DOT__memoryInstruction__DOT__wrDataReg = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__memoryInstruction__DOT__doForwardReg = VL_RAND_RESET_I(1);
    test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS1 = VL_RAND_RESET_I(5);
    test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RS2 = VL_RAND_RESET_I(5);
    test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_RD = VL_RAND_RESET_I(5);
    test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_WRITE_EN = VL_RAND_RESET_I(1);
    test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_ALU_OP = VL_RAND_RESET_I(4);
    test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_PROCEDURE_BRANCHING = VL_RAND_RESET_I(1);
    test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_DATA_IN = VL_RAND_RESET_I(1);
    test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_STORE_ADDRESS_IN = VL_RAND_RESET_I(1);
    test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_LOAD_SIZE = VL_RAND_RESET_I(2);
    test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_LOAD_ADDRESS_IN = VL_RAND_RESET_I(1);
    test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_BRANCH_SELECT = VL_RAND_RESET_I(2);
    test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore_io_UPDATE_PC = VL_RAND_RESET_I(1);
    test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit_io_mem_write_data = VL_RAND_RESET_I(8);
    test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit_io_mem_write_address = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit_io_load_mem_address_out = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__robinCore__DOT__PC = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__robinCore__DOT__INSTRUCTION_LOADED = VL_RAND_RESET_I(1);
    test_bench_robin_core_v2__DOT__robinCore__DOT__PROGRAM_LOADED = VL_RAND_RESET_I(1);
    test_bench_robin_core_v2__DOT__robinCore__DOT__noBranchNextAddr = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__robinCore__DOT__branchImmBranchAddr = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stateReg = VL_RAND_RESET_I(3);
    test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__stallState = VL_RAND_RESET_I(3);
    test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__instruction = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__STORE_READY = VL_RAND_RESET_I(1);
    test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT__LOAD_READY = VL_RAND_RESET_I(1);
    test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___T = VL_RAND_RESET_I(1);
    test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___T_2 = VL_RAND_RESET_I(1);
    test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___T_18 = VL_RAND_RESET_I(12);
    test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___GEN_4 = VL_RAND_RESET_I(3);
    test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___T_34 = VL_RAND_RESET_I(1);
    test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___GEN_15 = VL_RAND_RESET_I(1);
    test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___T_65 = VL_RAND_RESET_I(13);
    test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___T_66 = VL_RAND_RESET_I(21);
    test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___GEN_36 = VL_RAND_RESET_I(1);
    test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___GEN_48 = VL_RAND_RESET_I(3);
    test_bench_robin_core_v2__DOT__robinCore__DOT__controlStore__DOT___GEN_51 = VL_RAND_RESET_I(3);
    test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile_io_rdData = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__ALU_in1 = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__ALU_in2 = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__rdData = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__rs2_ALU = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT__ALUoutput = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT__EQUAL = VL_RAND_RESET_I(1);
    test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT__LESS_THAN = VL_RAND_RESET_I(1);
    test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT__SIGNED_LESS_THAN = VL_RAND_RESET_I(1);
    test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT___T_3 = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT___T_7 = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT___GEN_4 = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT___GEN_7 = VL_RAND_RESET_Q(63);
    test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__cpuALU__DOT___GEN_11 = VL_RAND_RESET_Q(63);
    test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_0 = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_1 = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_2 = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_3 = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_4 = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_5 = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_6 = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_7 = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_8 = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_9 = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_10 = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_11 = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_12 = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_13 = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_14 = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_15 = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_16 = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_17 = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_18 = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_19 = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_20 = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_21 = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_22 = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_23 = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_24 = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_25 = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_26 = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_27 = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_28 = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_29 = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_30 = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_31 = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT___GEN_21 = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT___GEN_54 = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__store_data_buffer = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__store_data_size_buffer = VL_RAND_RESET_I(2);
    test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__store_data_buffer_address = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__storing = VL_RAND_RESET_I(1);
    test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT__stateReg = VL_RAND_RESET_I(1);
    test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT___T = VL_RAND_RESET_I(1);
    test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT___GEN_4 = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT___GEN_9 = VL_RAND_RESET_I(1);
    test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT___GEN_11 = VL_RAND_RESET_I(2);
    test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT___GEN_14 = VL_RAND_RESET_I(1);
    test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT___T_10 = VL_RAND_RESET_I(25);
    test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT___T_12 = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__robinCore__DOT__storeUnit__DOT___T_15 = VL_RAND_RESET_I(2);
    test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_buffer = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_size_buffer = VL_RAND_RESET_I(2);
    test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__load_data_address_buffer = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__LOAD_SIZE = VL_RAND_RESET_I(2);
    test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__EXTENSION = VL_RAND_RESET_I(1);
    test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT__stateReg = VL_RAND_RESET_I(1);
    test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT___T_10 = VL_RAND_RESET_I(1);
    test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT___GEN_0 = VL_RAND_RESET_I(1);
    test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT___T_13 = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT___T_16 = VL_RAND_RESET_I(32);
    test_bench_robin_core_v2__DOT__robinCore__DOT__loadUnit__DOT___T_18 = VL_RAND_RESET_I(2);
    __Vm_traceActivity = 0;
}
