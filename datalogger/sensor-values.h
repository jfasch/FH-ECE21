#pragma once
#include <string>
#include <map>

class SensorValues
{
public:

    void addMeasurement(std::string name, float measurement)
    {
        _measuredData.insert({name, measurement});
    }

    auto begin()       { return _measuredData.begin(); }
    auto end()          { return _measuredData.end(); }

    
private:
    std::map<std::string, float> _measuredData;
};
