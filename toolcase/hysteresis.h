#pragma once

#include <sensor-mock.h>
#include <switch-mock.h>

class Hysteresis
{
public:
    Hysteresis(MockSensor* sensor, MockSwitch* switcH, double low, double high);
    void check();
    void set_range(double low, double high);

private:
    MockSensor* _sensor;
    MockSwitch* _switch;
    double _low;
    double _high;
   // double _new_low;
   // double _new_high;
};
