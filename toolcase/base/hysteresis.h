#pragma once

#include <sensor.h>
#include <switch.h>

class Hysteresis
{
public:
    Hysteresis(Sensor* sensor, Switch* switcH, double low, double high);
    void check();
    void set_range(double low, double high);

private:
    Sensor* _sensor;
    Switch* _switch;
    double _low;
    double _high;
};
