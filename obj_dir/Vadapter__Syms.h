// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VADAPTER__SYMS_H_
#define VERILATED_VADAPTER__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vadapter.h"

// INCLUDE MODULE CLASSES
#include "Vadapter___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vadapter__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vadapter* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vadapter___024root             TOP;

    // CONSTRUCTORS
    Vadapter__Syms(VerilatedContext* contextp, const char* namep, Vadapter* modelp);
    ~Vadapter__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
