#include "sensor-avg-nopoly.h"

void AveragingSensor_nopoly::add(MockSensor_nopoly* s)
{
    _sensors.push_back(s);
}
 
double AveragingSensor_nopoly::get_temperature()
{
    double sum_temperatures = 0;
    for (MockSensor_nopoly* s: _sensors)
        sum_temperatures += s->get_temperature();

    return sum_temperatures / _sensors.size();
}
