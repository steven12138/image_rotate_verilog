// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadapter.h for the primary calling header

#include "Vadapter__pch.h"
#include "Vadapter___024root.h"

VL_ATTR_COLD void Vadapter___024root___eval_static(Vadapter___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vadapter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadapter___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vadapter___024root___eval_initial__TOP(Vadapter___024root* vlSelf);

VL_ATTR_COLD void Vadapter___024root___eval_initial(Vadapter___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vadapter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadapter___024root___eval_initial\n"); );
    // Body
    Vadapter___024root___eval_initial__TOP(vlSelf);
}

VL_ATTR_COLD void Vadapter___024root___eval_initial__TOP(Vadapter___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vadapter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadapter___024root___eval_initial__TOP\n"); );
    // Body
    VL_WRITEF_NX("Hello World!\n",0);
}

VL_ATTR_COLD void Vadapter___024root___eval_final(Vadapter___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vadapter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadapter___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadapter___024root___dump_triggers__stl(Vadapter___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vadapter___024root___eval_phase__stl(Vadapter___024root* vlSelf);

VL_ATTR_COLD void Vadapter___024root___eval_settle(Vadapter___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vadapter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadapter___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vadapter___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("src/adapter.v", 5, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vadapter___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadapter___024root___dump_triggers__stl(Vadapter___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vadapter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadapter___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ vlSelf->__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void Vadapter___024root___ico_sequent__TOP__0(Vadapter___024root* vlSelf);

VL_ATTR_COLD void Vadapter___024root___eval_stl(Vadapter___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vadapter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadapter___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vadapter___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vadapter___024root___eval_triggers__stl(Vadapter___024root* vlSelf);

VL_ATTR_COLD bool Vadapter___024root___eval_phase__stl(Vadapter___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vadapter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadapter___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vadapter___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vadapter___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadapter___024root___dump_triggers__ico(Vadapter___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vadapter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadapter___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ vlSelf->__VicoTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadapter___024root___dump_triggers__act(Vadapter___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vadapter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadapter___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ vlSelf->__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadapter___024root___dump_triggers__nba(Vadapter___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vadapter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadapter___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ vlSelf->__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vadapter___024root___ctor_var_reset(Vadapter___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vadapter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadapter___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->mode = VL_RAND_RESET_I(1);
    vlSelf->clk_in = VL_RAND_RESET_I(1);
    vlSelf->start_in = VL_RAND_RESET_I(1);
    vlSelf->data_in = VL_RAND_RESET_I(24);
    vlSelf->jump_in = VL_RAND_RESET_I(1);
    vlSelf->clk_out = VL_RAND_RESET_I(1);
    vlSelf->start_out = VL_RAND_RESET_I(1);
    vlSelf->data_out = VL_RAND_RESET_I(24);
    vlSelf->jump_out = VL_RAND_RESET_I(1);
}
