#include "sensor-mock.h"


MockSensor::MockSensor(double initial_temperature)
: _temperature(initial_temperature) {}

double MockSensor::get_temperature()
{
    return _temperature;
}

void MockSensor::set_temperature(double temperature)
{
    _temperature = temperature;
}
