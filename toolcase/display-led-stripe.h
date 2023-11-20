#pragma once

#include <switch-mock.h>
//#include <switch.h> //
#include <sensor-mock.h>

#include <vector>


class LEDStripeDisplay
{
public:
    LEDStripeDisplay(
        double low, double high, 
        MockSensor* sensor, 
        const std::vector<MockSwitch*>& leds) //
    : _low(low), _high(high), _sensor(sensor), _leds(leds) {}

    void check();

private:
    double _low;
    double _high;
    MockSensor* _sensor;
    std::vector<MockSwitch*> _leds; //
};
