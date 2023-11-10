#pragma once
#include <sensor.h>
#include <sensor-values.h>
#include <string>
#include <map>

class SensorConfig
{
public:

    void addSensor(std::string name, Sensor *sensor)
    {
        _sensors.insert({name, sensor});
    }

    SensorValues getAllMeasurements()
    {
        SensorValues measurements;
        for (auto [name, sensor]: _sensors)
        {
            measurements.addMeasurement(name, sensor->get_temperature());
        }
        return measurements;
    }
    
private:
    std::map<std::string, Sensor*> _sensors;
};

