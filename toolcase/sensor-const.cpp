#include "sensor-const.h"

ConstantSensor::ConstantSensor(double value)
: _value(value) {}

double ConstantSensor::get_temperature()
{
    return _value;
}
