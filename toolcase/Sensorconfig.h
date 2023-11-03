#pragma once
#include <sensor.h>
#include <string>
#include <map>

class SensorConfig
{
public:
    SensorConfig();

    void addSensor(std::string name, Sensor* sensor)
    {
        _sensors[name] = sensor;
    }

    auto getSensorMap()
    {
        return _sensors;
    }
    
private:
    std::map<std::string, Sensor*> _sensors;
};

