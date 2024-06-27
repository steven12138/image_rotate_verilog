// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadapter.h for the primary calling header

#include "Vadapter__pch.h"
#include "Vadapter___024root.h"

void Vadapter___024root___eval_act(Vadapter___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vadapter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadapter___024root___eval_act\n"); );
}

void Vadapter___024root___nba_sequent__TOP__0(Vadapter___024root* vlSelf);
void Vadapter___024root___nba_sequent__TOP__1(Vadapter___024root* vlSelf);

void Vadapter___024root___eval_nba(Vadapter___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vadapter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadapter___024root___eval_nba\n"); );
    // Body
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vadapter___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vadapter___024root___nba_sequent__TOP__1(vlSelf);
    }
}

VL_INLINE_OPT void Vadapter___024root___nba_sequent__TOP__0(Vadapter___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vadapter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadapter___024root___nba_sequent__TOP__0\n"); );
    // Init
    IData/*31:0*/ __VdlyVal__adapter__DOT__ram__DOT__mem__v0;
    __VdlyVal__adapter__DOT__ram__DOT__mem__v0 = 0;
    IData/*19:0*/ __VdlyDim0__adapter__DOT__ram__DOT__mem__v0;
    __VdlyDim0__adapter__DOT__ram__DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__adapter__DOT__ram__DOT__mem__v0;
    __VdlySet__adapter__DOT__ram__DOT__mem__v0 = 0;
    // Body
    __VdlySet__adapter__DOT__ram__DOT__mem__v0 = 0U;
    if ((1U & (~ (IData)(vlSelf->mode)))) {
        __VdlyVal__adapter__DOT__ram__DOT__mem__v0 
            = vlSelf->data_in;
        __VdlyDim0__adapter__DOT__ram__DOT__mem__v0 
            = vlSelf->adapter__DOT__addr;
        __VdlySet__adapter__DOT__ram__DOT__mem__v0 = 1U;
    }
    if (vlSelf->mode) {
        vlSelf->adapter__DOT__mem_out = vlSelf->adapter__DOT__ram__DOT__mem
            [vlSelf->adapter__DOT__addr];
    }
    if (__VdlySet__adapter__DOT__ram__DOT__mem__v0) {
        vlSelf->adapter__DOT__ram__DOT__mem[__VdlyDim0__adapter__DOT__ram__DOT__mem__v0] 
            = __VdlyVal__adapter__DOT__ram__DOT__mem__v0;
    }
    vlSelf->data_out = (0xffffffU & vlSelf->adapter__DOT__mem_out);
}

VL_INLINE_OPT void Vadapter___024root___nba_sequent__TOP__1(Vadapter___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vadapter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadapter___024root___nba_sequent__TOP__1\n"); );
    // Init
    CData/*7:0*/ __Vdly__adapter__DOT__y;
    __Vdly__adapter__DOT__y = 0;
    CData/*7:0*/ __Vdly__adapter__DOT__x;
    __Vdly__adapter__DOT__x = 0;
    CData/*2:0*/ __Vdly__adapter__DOT__next_state;
    __Vdly__adapter__DOT__next_state = 0;
    // Body
    __Vdly__adapter__DOT__next_state = vlSelf->adapter__DOT__next_state;
    __Vdly__adapter__DOT__x = vlSelf->adapter__DOT__x;
    __Vdly__adapter__DOT__y = vlSelf->adapter__DOT__y;
    if ((1U & (~ (IData)(vlSelf->rst)))) {
        if ((1U & (~ ((IData)(vlSelf->adapter__DOT__state) 
                      >> 2U)))) {
            if ((2U & (IData)(vlSelf->adapter__DOT__state))) {
                vlSelf->jump_out = (1U & (IData)(vlSelf->adapter__DOT__state));
            }
        }
    }
    if (vlSelf->rst) {
        __Vdly__adapter__DOT__next_state = 0U;
        __Vdly__adapter__DOT__x = 0U;
        __Vdly__adapter__DOT__y = 0U;
        vlSelf->adapter__DOT__state = 0U;
    } else {
        if ((4U & (IData)(vlSelf->adapter__DOT__state))) {
            __Vdly__adapter__DOT__next_state = ((2U 
                                                 & (IData)(vlSelf->adapter__DOT__state))
                                                 ? 0U
                                                 : 
                                                ((1U 
                                                  & (IData)(vlSelf->adapter__DOT__state))
                                                  ? 4U
                                                  : 
                                                 ((IData)(vlSelf->jump_in)
                                                   ? 5U
                                                   : 4U)));
            if ((1U & (~ ((IData)(vlSelf->adapter__DOT__state) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlSelf->adapter__DOT__state)))) {
                    if (vlSelf->jump_in) {
                        __Vdly__adapter__DOT__x = 0U;
                        __Vdly__adapter__DOT__y = (0xffU 
                                                   & ((IData)(1U) 
                                                      + (IData)(vlSelf->adapter__DOT__y)));
                    } else {
                        __Vdly__adapter__DOT__x = (0xffU 
                                                   & ((IData)(1U) 
                                                      + (IData)(vlSelf->adapter__DOT__x)));
                    }
                }
            }
        } else if ((2U & (IData)(vlSelf->adapter__DOT__state))) {
            __Vdly__adapter__DOT__next_state = ((1U 
                                                 & (IData)(vlSelf->adapter__DOT__state))
                                                 ? 2U
                                                 : 
                                                ((IData)(vlSelf->jump_in)
                                                  ? 3U
                                                  : 2U));
            if ((1U & (~ (IData)(vlSelf->adapter__DOT__state)))) {
                if (vlSelf->jump_in) {
                    __Vdly__adapter__DOT__x = 0U;
                    __Vdly__adapter__DOT__y = (0xffU 
                                               & ((IData)(1U) 
                                                  + (IData)(vlSelf->adapter__DOT__y)));
                } else {
                    __Vdly__adapter__DOT__x = (0xffU 
                                               & ((IData)(1U) 
                                                  + (IData)(vlSelf->adapter__DOT__x)));
                }
            }
        } else {
            __Vdly__adapter__DOT__next_state = ((1U 
                                                 & (IData)(vlSelf->adapter__DOT__state))
                                                 ? 0U
                                                 : 
                                                (((IData)(vlSelf->start_in) 
                                                  & (~ (IData)(vlSelf->mode)))
                                                  ? 4U
                                                  : 
                                                 (((IData)(vlSelf->start_in) 
                                                   & (IData)(vlSelf->mode))
                                                   ? 2U
                                                   : 0U)));
            if ((1U & (~ (IData)(vlSelf->adapter__DOT__state)))) {
                if (((IData)(vlSelf->start_in) & (~ (IData)(vlSelf->mode)))) {
                    __Vdly__adapter__DOT__x = 0U;
                    __Vdly__adapter__DOT__y = 0U;
                } else if (((IData)(vlSelf->start_in) 
                            & (IData)(vlSelf->mode))) {
                    __Vdly__adapter__DOT__x = 0U;
                    __Vdly__adapter__DOT__y = 0U;
                }
            }
        }
        vlSelf->adapter__DOT__state = vlSelf->adapter__DOT__next_state;
    }
    vlSelf->adapter__DOT__x = __Vdly__adapter__DOT__x;
    vlSelf->adapter__DOT__y = __Vdly__adapter__DOT__y;
    vlSelf->adapter__DOT__addr = (((IData)(vlSelf->adapter__DOT__x) 
                                   << 8U) | (IData)(vlSelf->adapter__DOT__y));
    vlSelf->adapter__DOT__next_state = __Vdly__adapter__DOT__next_state;
}

void Vadapter___024root___eval_triggers__act(Vadapter___024root* vlSelf);

bool Vadapter___024root___eval_phase__act(Vadapter___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vadapter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadapter___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vadapter___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vadapter___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vadapter___024root___eval_phase__nba(Vadapter___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vadapter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadapter___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vadapter___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadapter___024root___dump_triggers__nba(Vadapter___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vadapter___024root___dump_triggers__act(Vadapter___024root* vlSelf);
#endif  // VL_DEBUG

void Vadapter___024root___eval(Vadapter___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vadapter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadapter___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vadapter___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("src/adapter.v", 5, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vadapter___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("src/adapter.v", 5, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vadapter___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vadapter___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vadapter___024root___eval_debug_assertions(Vadapter___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vadapter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadapter___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->mode & 0xfeU))) {
        Verilated::overWidthError("mode");}
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->start_in & 0xfeU))) {
        Verilated::overWidthError("start_in");}
    if (VL_UNLIKELY((vlSelf->data_in & 0xff000000U))) {
        Verilated::overWidthError("data_in");}
    if (VL_UNLIKELY((vlSelf->jump_in & 0xfeU))) {
        Verilated::overWidthError("jump_in");}
}
#endif  // VL_DEBUG
