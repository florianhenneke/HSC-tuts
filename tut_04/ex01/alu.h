#pragma once
#include <systemc>
using namespace sc_core;
using namespace sc_dt;


struct Alu : public sc_module {
  public:
    SC_HAS_PROCESS(Alu);
    Alu(sc_module_name name);
    void thread();
    sc_in<bool> mode;
    sc_in<sc_uint<8> > in1, in2;
    sc_out<sc_uint<8> > out;
    sc_out<bool> overflow;
  private:
};