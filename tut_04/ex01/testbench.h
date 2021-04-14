//testbench.h
#ifndef TESTBENCH_H
#define TESTBENCH_H
#include <systemc>
using namespace sc_dt;
using namespace sc_core;

struct Testbench : public sc_module {
  //Ports
  sc_in<bool>  clk;
  sc_out<bool> mode;
  sc_out<sc_uint<8> > out1, out2;
  sc_in<sc_uint<8> > result;
  sc_in<bool> overflow;
  //Processes
  void generateStimuli();
  //Constructor
  SC_HAS_PROCESS(Testbench);
  Testbench(sc_module_name);
};
#endif