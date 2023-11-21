#pragma once
#include <sensor.h>
#include <sensor-values.h>
#include <string>
#include <map>

/**
 * @class Sesnorconfig
 * @brief Hold all sensors which should be logged by the DataLogger class.
 * All sensors are stored in an provate map.
 *
 * new sensors need to be added by the addSensor functions.
 * 
 * getAllMeasurements funciotns returns a class SensorValues object which holds all 
 * measured sensor data.
*/
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

