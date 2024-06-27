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
    VL_IN8(mode,0,0);
    VL_IN8(clk_in,0,0);
    VL_IN8(start_in,0,0);
    VL_IN8(jump_in,0,0);
    VL_OUT8(clk_out,0,0);
    VL_OUT8(start_out,0,0);
    VL_OUT8(jump_out,0,0);
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __VactContinue;
    VL_IN(data_in,23,0);
    VL_OUT(data_out,23,0);
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

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
