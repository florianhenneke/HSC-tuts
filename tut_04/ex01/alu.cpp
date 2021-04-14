#include "alu.h"

Alu::Alu(sc_module_name name) {
  SC_THREAD(thread);
  sensitive << mode << in1 << in2;
}

void Alu::thread() {
  sc_uint<9> sumWithCarry;
  while(1)
  {
    if(mode.read() == true) {
      //Addition
      sumWithCarry= in1.read() + in2.read();
    } else
    {
      //Subtraktion
      sumWithCarry= (in1.read() - in2.read()) & 511;
    }
    out.write(sumWithCarry & 255);
    overflow = (sumWithCarry & 256) != 0;

    wait();
  }
}