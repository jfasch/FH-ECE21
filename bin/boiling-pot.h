#pragma once

#include <sensor-mock.h>
#include <switch-mock.h>

class BoilingPot{
public:
    pot(MockSensor* sensor, MockSwitch* switcH);
    void head(double set_temperature);

private:
    MockSensor* _sensor;
    MockSwitch* _switch;
    double _set_temperature;

};