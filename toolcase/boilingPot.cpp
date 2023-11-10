#include <boiling-pot.h>
#include <sensor-mock.h>
#include <switch-mock.h>
#include <hysteresis.h>

BoilingPot::BoilingPot(
    MockSensor* sensor, 
    MockSwitch* switcH) 
: _sensor(sensor),
  _switch(switcH),
  _hysteresis(_sensor, _switch, 0, 0)
{}


void BoilingPot::heat(double set_temperature)
{
    _hysteresis.set_range(set_temperature-1, set_temperature+1);
}

void BoilingPot::check()
{
    _hysteresis.check();
}


 