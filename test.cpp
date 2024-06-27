#include "Vadapter.h"
#include "verilated.h"

int main(int argc, char **argv) {
  VerilatedContext *contextp = new VerilatedContext;
  contextp->commandArgs(argc, argv);
  Vadapter *top = new Vadapter{contextp};
  top->clk_in=0;
  top->eval();
  delete top;
  delete contextp;
  return 0;
}
