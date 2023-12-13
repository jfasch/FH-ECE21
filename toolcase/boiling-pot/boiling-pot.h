#pragma once

#include <sensor.h>
#include <switch.h>
#include <percentage-display.h>
#include <hysteresis.h>

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
    BoilingPot(Sensor*, Switch*, Reporter*, PercentageDisplay*);
    void heat(double set_temperature);
    void check();
    
private:
    Sensor* _sensor;
    Switch* _switch;
    Hysteresis _hysteresis;
    double _set_temperature;

};
