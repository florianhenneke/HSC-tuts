//toplevel.h
#ifndef TOPLEVEL_H
#define TOPLEVEL_H
#include <systemc>
#include "clock.h"
using namespace sc_core;

struct Testbench;
struct MovingAverage;

struct Toplevel : public sc_module {
  //Module Pointers
  Testbench *tb;
  MovingAverage *ma;
  //Constructor
  Toplevel(sc_module_name name);
  ~Toplevel();
private:
  Clock clock;
  sc_signal<bool> clk;
  sc_signal<int> xSignal, ySignal; 
  sc_signal<bool> resetSignal;
};
#endif