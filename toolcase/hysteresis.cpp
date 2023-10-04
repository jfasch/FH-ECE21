#include "hysteresis.h"


Hysteresis::Hysteresis(
    MockSensor* sensor, 
    MockSwitch* switcH, 
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
        _switch->on();
    else if (current_temperature > _high)
        _switch->off();
    else { /* leave as-is */ }
}
