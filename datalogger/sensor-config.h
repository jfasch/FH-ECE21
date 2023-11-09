#pragma once
#include <sensor.h>
#include <string>
#include <map>

class SensorConfig
{
public:

    void addSensor(std::string name, Sensor *sensor)
    {
        _sensors.insert({name, sensor});
    }

    auto begin()       { return _sensors.begin(); }
    auto end()          { return _sensors.end(); }

    
private:
    std::map<std::string, Sensor*> _sensors;
};

