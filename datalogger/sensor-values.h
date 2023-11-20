#pragma once
#include <string>
#include <map>

/**
 * @class Sensorvalues
 * @brief Hold all sensor data which 
 * All data is stored in an provate map.
 *
 * new data need to be added by the addMeasurement functions.
 * 
 * individial measurements can be retreives via the getMeasurement function.
 * it is also possible to loop over the private map via a for loop
*/
class SensorValues
{
public:

    bool addMeasurement(std::string name, float measurement)
    {
        auto [ptr, result] = _measuredData.insert(std::pair(name, measurement));
        return result;
    }

    double getMeasurement(std::string name)
    {
        return _measuredData.at(name);
    }


    auto begin()       { return _measuredData.begin(); }
    auto end()          { return _measuredData.end(); }

private:
    std::map<std::string, float> _measuredData;
};

