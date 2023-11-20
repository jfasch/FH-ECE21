#include "hysteresis.h"
//#include <sensor.h>
//#include <switch.h>



Hysteresis::Hysteresis(
    Sensor* sensor, 
    Switch* switcH, 
    double low, 
    double high)
: _sensor(sensor),
  _switch(switcH),
  _low(low),
  _high(high)
{}

void Hysteresis::check()
{
    double current_temperature = _sensor->get_temperature();
    if (current_temperature < _low)
        _switch->set_state(true);  //on();
    else if (current_temperature > _high)
        _switch->set_state(false);  //off();
    else { /* leave as-is */ }
}

void Hysteresis::set_range(double low, double high)
{
    _low = low;
    _high = high;
}