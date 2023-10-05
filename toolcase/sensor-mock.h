#pragma once
#include <sensor.h>

class MockSensor : public Sensor
{
public:
    MockSensor(double initial_temperature);
    double get_temperature();
    void set_temperature(double temperature);

private:
    double _temperature;
};
