//movaverage_cppstyle.cpp
#include "movaverage.h"
//Constructor
MovingAverage::MovingAverage(sc_module_name name){
	SC_THREAD(thread);
	sensitive << clk << reset;
}

void MovingAverage::thread() {
	while(1)
	{
		wait();
		if (reset.read() == true) {
		xn1.write(0);
		xn2.write(0);
		xn3.write(0);
		yn.write(0);
		} 
		else if (clk.posedge() == true) {
			int i1, i2, i3;

			i1 = xn.read() + xn1.read();
			i2 = i1 + xn2.read();
			i3 = i2 + xn3.read();
			int result = i3/4;
			//result.write(i3 / 4);

			xn1.write( xn.read() );
			xn2.write( xn1.read() );
			xn3.write( xn2.read() );
			yn.write( result );
		}
	}
}