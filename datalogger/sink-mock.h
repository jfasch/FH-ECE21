#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <sink-logger.h>

class SinkMock : public SinkLogger
{
    public:
        // Assume data is a vector of pairs, each pair contains sensor name and its value
        void output(const std::vector<std::pair<std::string, double>>& data)
        {
            for (const auto& [name, value] : data)
            {
                // Add the value to the vector associated with the sensor name
                _givenSensorValues[name].push_back(value);
            }
        }

        // Retrieve the entire array of values for a given sensor
        std::vector<double> getSensorReadings(const std::string& sensorName)
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
