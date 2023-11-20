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
                if (_givenSensorValues.find(name) == _givenSensorValues.end())
                {
                    _givenSensorValues[name] = std::vector<double>();
                }
                _givenSensorValues[name].push_back(value);
            }
        }

        double getTemperature(std::string sensorName)
        {
            if (_givenSensorValues.find(sensorName) != _givenSensorValues.end() && !_givenSensorValues[sensorName].empty())
            {
                return _givenSensorValues[sensorName][0];
            }
            else
            {
                std::cerr << "Sensor name not found or no readings available." << std::endl;
                return 0.0;
            }
        }

    private:
        std::map<std::string, std::vector<double>> _givenSensorValues;
};
