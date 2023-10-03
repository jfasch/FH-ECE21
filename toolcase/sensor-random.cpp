#include "sensor-random.h"


RandomSensor::RandomSensor(double low, double high)
: _distribution(std::uniform_real_distribution<double>(low, high)),
  _engine(std::random_device()()),
  _low(low),
  _high(high) {}

double RandomSensor::get_temperature() 
{
    return _distribution(_engine);
}
