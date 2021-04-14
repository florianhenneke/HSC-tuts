//toplevel.cpp
#include "testbench.h"
#include "movaverage.h"
#include "toplevel.h"

//Constructor
Toplevel::Toplevel(sc_module_name name): 
	clock ("clock", 10, SC_NS){
	//Create instances
	tb = new Testbench("tb");
	ma = new MovingAverage("ma");
	//Connect instances
	tb->clk(clock);
	tb->xn(xSignal);
	tb->yn(ySignal);
	tb->reset(resetSignal);
	ma->clk(clock);
	ma->xn(xSignal);
	ma->yn(ySignal);
	ma->reset(resetSignal);
}
Toplevel::~Toplevel(){
  delete tb;
  delete ma;
}
