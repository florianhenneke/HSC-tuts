//toplevel.cpp
#include "testbench.h"
#include "toplevel.h"

//Constructor
Toplevel::Toplevel(sc_module_name name): 
clock ("clock", 10, SC_NS), tb("tb"), alu("alu")
{
	//Connect instances
	clock.clock(clk);
	tb.clk(clk);
	tb.mode(mode);
	tb.out1(number1);
	tb.out2(number2);
	tb.result(result);
	tb.overflow(overflow);
	
	alu.mode(mode);
	alu.in1(number1);
	alu.in2(number2);
	alu.out(result);
	alu.overflow(overflow);
}
Toplevel::~Toplevel(){
}
