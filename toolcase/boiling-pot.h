#pragma once

#include <sensor-mock.h>
#include <switch-mock.h>
#include <hysteresis.h>

class BoilingPot
{
public:
    BoilingPot(MockSensor* sensor, MockSwitch* switcH);
    void heat(double set_temperature);
    void check();
    
private:
    MockSensor* _sensor;
    MockSwitch* _switch;
    Hysteresis _hysteresis;
    double _set_temperature;

};