#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <sink-logger.h>

/**
 * @class SinkMock
 * @brief stores data given via a SensorValues object in an private map.
 * 
 * Inividual datapoitsncan be retreived via a getTemperature function
*/
class SinkMock : public SinkLogger
{
    public:
        void output(SensorValues data)
        {
            for (auto [name, value]: data)
            {
                if(_givenSensorValues.count(name)==0){
                    std::vector<double> valuesVec;
                    valuesVec.push_back(value);
                    _givenSensorValues.insert(std::pair(name,valuesVec));
                }
                else{
                    auto vec=_givenSensorValues.at(name);
                    vec.push_back(value);
                }
                _givenSensorValues.insert(std::pair(name, value));
            }

        }

        // returns the temperature for a given sensorname
        auto getTemperature(std::string sensorName)
        {
            return _givenSensorValues.at(sensorName);
        }

    private:
        std::map<std::string, std::vector<double> > _givenSensorValues;
};