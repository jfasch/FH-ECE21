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
    void output(const SensorValues& data) override
    {
        _measurements.push_back(data);
    }
    size_t size() const { return _measurements.size(); }
    const SensorValues& operator[](size_t i) const { return _measurements[i]; }

private:
    std::vector<SensorValues> _measurements;
};
