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

        // Returns the temperature for a given sensor name
        double getTemperature(const std::string& sensorName)
        {
            if (_givenSensorValues.find(sensorName) != _givenSensorValues.end() && !_givenSensorValues[sensorName].empty())
            {
                // Return the most recent value
                return _givenSensorValues[sensorName].back();
            }
            else
            {
                std::cerr << "Sensor name not found or no readings available." << std::endl;
                return 0.0; // Or some other appropriate default value/error indication
            }
        }

    private:
        std::map<std::string, std::vector<double>> _givenSensorValues;
};
