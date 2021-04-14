#include "clock.h"

Clock::Clock(sc_module_name, double _period, sc_time_unit _timeUnit) : 
period(_period), timeUnit(_timeUnit)
{
  SC_THREAD(thread);
}

void Clock::thread() 
{
  while(1) 
  {
    clock.write(true);
    wait(period/2, timeUnit);
    clock.write(false);
    wait(period/2, timeUnit);
  }
}

