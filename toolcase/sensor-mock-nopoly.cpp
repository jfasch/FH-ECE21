#include "sensor-mock-nopoly.h"


MockSensor_nopoly::MockSensor_nopoly(double initial_temperature)
: _temperature(initial_temperature) {}

double MockSensor_nopoly::get_temperature()
{
    return _temperature;
}

void MockSensor_nopoly::set_temperature(double temperature)
{
    _temperature = temperature;
}
