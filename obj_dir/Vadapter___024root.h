// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vadapter.h for the primary calling header

#ifndef VERILATED_VADAPTER___024ROOT_H_
#define VERILATED_VADAPTER___024ROOT_H_  // guard

#include "verilated.h"


class Vadapter__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vadapter___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(rst,0,0);
    VL_IN8(clk,0,0);
    VL_IN8(mode,0,0);
    VL_IN8(start_in,0,0);
    VL_IN8(jump_in,0,0);
    VL_OUT8(jump_out,0,0);
    CData/*2:0*/ adapter__DOT__state;
    CData/*2:0*/ adapter__DOT__next_state;
    CData/*7:0*/ adapter__DOT__x;
    CData/*7:0*/ adapter__DOT__y;
    CData/*7:0*/ adapter__DOT__img_width;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst__0;
    CData/*0:0*/ __VactContinue;
    VL_IN(data_in,23,0);
    VL_OUT(data_out,23,0);
    IData/*19:0*/ adapter__DOT__addr;
    IData/*31:0*/ adapter__DOT__cycle_count;
    IData/*31:0*/ adapter__DOT__mem_out;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<IData/*31:0*/, 1048576> adapter__DOT__ram__DOT__mem;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vadapter__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vadapter___024root(Vadapter__Syms* symsp, const char* v__name);
    ~Vadapter___024root();
    VL_UNCOPYABLE(Vadapter___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
