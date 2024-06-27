// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vour.h for the primary calling header

#include "Vour__pch.h"
#include "Vour___024root.h"

VL_ATTR_COLD void Vour___024root___eval_static(Vour___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vour__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vour___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vour___024root___eval_initial__TOP(Vour___024root* vlSelf);

VL_ATTR_COLD void Vour___024root___eval_initial(Vour___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vour__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vour___024root___eval_initial\n"); );
    // Body
    Vour___024root___eval_initial__TOP(vlSelf);
}

VL_ATTR_COLD void Vour___024root___eval_initial__TOP(Vour___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vour__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vour___024root___eval_initial__TOP\n"); );
    // Body
    if (VL_UNLIKELY(vlSelf->clk)) {
        VL_WRITEF_NX("Hello World\n",0);
    }
    VL_FINISH_MT("src/our.v", 8, "");
}

VL_ATTR_COLD void Vour___024root___eval_final(Vour___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vour__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vour___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vour___024root___eval_settle(Vour___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vour__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vour___024root___eval_settle\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vour___024root___dump_triggers__act(Vour___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vour__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vour___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ vlSelf->__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vour___024root___dump_triggers__nba(Vour___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vour__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vour___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ vlSelf->__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vour___024root___ctor_var_reset(Vour___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vour__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vour___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
}
