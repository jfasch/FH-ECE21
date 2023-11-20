#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <sink-logger.h>

class SinkMock : public SinkLogger
{
    public:
        void output(SensorValues data)
        {
            for (auto [name, value] : data)
            {
                // Check if the name is already present
                if (_givenSensorValues.find(name) == _givenSensorValues.end())
                {
                    // If not present, insert the name and initialize the vector
                    _givenSensorValues[name] = std::vector<double>();
                }

                // Add the value to the vector associated with the sensor name
                _givenSensorValues[name].push_back(value);
            }
        }

        // returns the temperature for a given sensorname
        std::vector<double> getAllReadingsForSensor(const std::string& sensorName)
        {
            if (_givenSensorValues.find(sensorName) != _givenSensorValues.end())
            {
                return _givenSensorValues[sensorName];
            }
            else
            {
                std::cerr << "Sensor name not found." << std::endl;
                return {}; // Return an empty vector if sensor name is not found
            }
        }

    private:
        std::map<std::string, std::vector<double>> _givenSensorValues;
};
