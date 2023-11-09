#pragma once

#include <sensor-mock.h>
#include <switch-mock.h>

class BoilingPot
{
public:
    BoilingPot(MockSensor* sensor, MockSwitch* switcH);
    void heat(double set_temperature);

private:
    MockSensor* _sensor;
    MockSwitch* _switch;
    double _set_temperature;

};