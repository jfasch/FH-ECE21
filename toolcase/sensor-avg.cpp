#include "sensor-avg.h"

void AveragingSensor::add(Sensor* s)
{
    _sensors.push_back(s);
}
 
double AveragingSensor::get_temperature()
{
    double sum_temperatures = 0;
    for (Sensor* s: _sensors)
        sum_temperatures += s->get_temperature();

    return sum_temperatures / _sensors.size();
}
