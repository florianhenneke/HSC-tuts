//testbench.cpp
#include "testbench.h"
#include <iostream>
using namespace std;
//Constructor
Testbench::Testbench(sc_module_name name){
  SC_THREAD(generateStimuli);
  sensitive << clk.neg(); 
}
//Process
void Testbench::generateStimuli() {
  mode.write(true);
  out1.write(15);
  out2.write(5);
  wait();
  cout << result.read() << "  " << overflow.read() << endl;

  mode.write(false);
  out1.write(15);
  out2.write(5);
  wait();
  cout << result.read() << "  " << overflow.read() << endl;

  mode.write(true);
  out1.write(255);
  out2.write(2);
  wait();
  cout << result.read() << "  " << overflow.read() << endl;

  mode.write(false);
  out1.write(1);
  out2.write(5);
  wait();
  cout << result.read() << "  " << overflow.read() << endl;
}