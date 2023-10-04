#pragma once

#include <sensor-mock.h>
#include <switch-mock.h>

class Hysteresis
{
public:
    Hysteresis(MockSensor* sensor, MockSwitch* switcH, double low, double high);
    void check();

private:
    MockSensor* _sensor;
    MockSwitch* _switch;
    double _low;
    double _high;
};
