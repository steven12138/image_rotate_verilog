// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vadapter__pch.h"

//============================================================
// Constructors

Vadapter::Vadapter(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vadapter__Syms(contextp(), _vcname__, this)}
    , mode{vlSymsp->TOP.mode}
    , clk_in{vlSymsp->TOP.clk_in}
    , start_in{vlSymsp->TOP.start_in}
    , jump_in{vlSymsp->TOP.jump_in}
    , clk_out{vlSymsp->TOP.clk_out}
    , start_out{vlSymsp->TOP.start_out}
    , jump_out{vlSymsp->TOP.jump_out}
    , data_in{vlSymsp->TOP.data_in}
    , data_out{vlSymsp->TOP.data_out}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vadapter::Vadapter(const char* _vcname__)
    : Vadapter(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vadapter::~Vadapter() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vadapter___024root___eval_debug_assertions(Vadapter___024root* vlSelf);
#endif  // VL_DEBUG
void Vadapter___024root___eval_static(Vadapter___024root* vlSelf);
void Vadapter___024root___eval_initial(Vadapter___024root* vlSelf);
void Vadapter___024root___eval_settle(Vadapter___024root* vlSelf);
void Vadapter___024root___eval(Vadapter___024root* vlSelf);

void Vadapter::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vadapter::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vadapter___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vadapter___024root___eval_static(&(vlSymsp->TOP));
        Vadapter___024root___eval_initial(&(vlSymsp->TOP));
        Vadapter___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vadapter___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vadapter::eventsPending() { return false; }

uint64_t Vadapter::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vadapter::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vadapter___024root___eval_final(Vadapter___024root* vlSelf);

VL_ATTR_COLD void Vadapter::final() {
    Vadapter___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vadapter::hierName() const { return vlSymsp->name(); }
const char* Vadapter::modelName() const { return "Vadapter"; }
unsigned Vadapter::threads() const { return 1; }
void Vadapter::prepareClone() const { contextp()->prepareClone(); }
void Vadapter::atClone() const {
    contextp()->threadPoolpOnClone();
}
