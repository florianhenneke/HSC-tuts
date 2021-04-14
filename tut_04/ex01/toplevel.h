//toplevel.h
#ifndef TOPLEVEL_H
#define TOPLEVEL_H
#include <systemc>
#include "clock.h"
#include "alu.h"
#include "testbench.h"
using namespace sc_core;
using namespace sc_dt;

struct Toplevel : public sc_module {
  //Module Pointers
  Testbench tb;
  Alu alu;
  //Constructor
  Toplevel(sc_module_name name);
  ~Toplevel();
private:
  Clock clock;
  sc_signal<bool> clk;
  sc_signal<sc_uint<8> > number1, number2, result;
  sc_signal<bool> mode;
  sc_signal<bool> overflow;
};
#endif