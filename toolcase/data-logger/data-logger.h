#pragma once
#include <sink-logger.h>
#include <sensor-config.h>
/**
 * @class DataLogger
 * @brief A class responsible for logging sensor data at specified intervals.
 *
 * @param sensors Pointer to the SensorConfig object specifying sensor configurations.
 * @param sink Pointer to the SinkLogger object defining the logging sink.
 * @param interval Logging interval in seconds. 
*/
class DataLogger
{
public:
    DataLogger(SensorConfig* sensors, SinkLogger* sink, uint16_t interval);

    // starts logging forever with given interval _interval
    void startLogging();
    // starts logging for 'count' times
    void startLogging(uint16_t count);

    std::string getTime()
    {
        time_t currentTime;
        time(&currentTime);
        timeBuffer = ctime(&currentTime);
        timeBuffer.erase(20, 5); // remove newline 
        return timeBuffer;
    }
    


private:
    SinkLogger* _sink;
    SensorConfig* _sensors;
    uint16_t _interval;
    SensorValues _measurements;

    std::string timeBuffer;
};