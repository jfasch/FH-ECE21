#include <boiling-pot.h>
#include <sensor-mock.h>
#include <switch-mock.h>
#include <hysteresis.h>

BoilingPot::BoilingPot(
    Sensor* sensor, 
    Switch* switcH, 
    Reporter* reporter,
    PercentageDisplay* percentage_display) 
: _sensor(sensor),
  _switch(switcH),
  _reporter(reporter),
  _percentage_display(percentage_display),
  _hysteresis(_sensor, _switch, 0, 0)
{}

void BoilingPot::heat(double set_temperature)
{
    _hysteresis.set_range(set_temperature-1, set_temperature+1);
}

void BoilingPot::check()
{
    _hysteresis.check();
    if(_percentage_display)
    {
        double t = _sensor->get_temperature();
        _percentage_display->show_percentage(t/100);
    }
}

