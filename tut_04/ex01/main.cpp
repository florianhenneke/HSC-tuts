//main.cpp
#include "toplevel.h"
#include "testbench.h" //Necessary for traces

int sc_main(int argc, char *argv[]) {
  Toplevel *top;
  top = new Toplevel("top");

  //Create trace file
  sc_trace_file *fp;
  fp = sc_create_vcd_trace_file("traces");
  sc_trace(fp, top->tb.clk, "clk");
  sc_trace(fp, top->tb.mode, "mode");
  sc_trace(fp, top->tb.out1, "number1");
  sc_trace(fp, top->tb.out2, "number2");
  sc_trace(fp, top->tb.result, "result");
  sc_trace(fp, top->tb.overflow, "overflow");

  //Start simulation
  sc_start(100, SC_NS);

  //Close trace file
  sc_close_vcd_trace_file(fp);
  
  delete top;

  return 0;
}


