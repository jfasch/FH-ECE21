#pragma once

#include <sensor-mock.h>
#include <switch-mock.h>
#include <hysteresis.h>
//#include <switch.h>

class BoilingPot
{
public:
    class Reporter
    {
    public:
        virtual ~Reporter() {}
        virtual void report(bool switch_state, double current_temperature) = 0;
    };

public:
    BoilingPot(Sensor*, Switch*, Reporter*);
    void heat(double set_temperature);
    void check();
    
private:
    Sensor* _sensor;
    Switch* _switch;
    Hysteresis _hysteresis;
    double _set_temperature;

};
