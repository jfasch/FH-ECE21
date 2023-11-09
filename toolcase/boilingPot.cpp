#include <boiling-pot.h>
#include <sensor-mock.h>
#include <switch-mock.h>
//#include "hysteresis.h"

BoilingPot::BoilingPot(
    MockSensor* sensor, 
    MockSwitch* switcH) 
: _sensor(sensor),
  _switch(switcH)
{}

void BoilingPot::heat(double set_temperature)
{
    _switch->on();
}
 