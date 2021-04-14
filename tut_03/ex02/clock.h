//movaverage_cppstyle.h
#ifndef CLOCK_CPPSTYLE_H
#define CLOCK_CPPSTYLE_H
#include <systemc>
using namespace sc_core;

struct Clock : public sc_module {
  //Ports
  sc_out<bool> clock;
  //Processes
  void thread();
  //Constructor
  SC_HAS_PROCESS(Clock);
  Clock(sc_module_name, double _period, sc_time_unit _timeUnit);
private:
  //Internal signals
  double period;
  sc_time_unit timeUnit;
};
#endif