#pragma once

#include <switch-mock-nopoly.h>
#include <sensor-mock-nopoly.h>
#include <vector>

using namespace std;

class LEDStripeDisplay_nopoly
{
    private:
    double _low;
    double _high;
    MockSensor_nopoly *_sensor;
    std::vector<MockSwitch_nopoly*> _switches;

    public:
    LEDStripeDisplay_nopoly(double low_border, double high_border, MockSensor_nopoly *sensor, const std::vector<MockSwitch_nopoly*>& switches)
    {
        _low = low_border;
        _high = high_border;
        _sensor = sensor;
        _switches = switches;
    }
    void check();

};

