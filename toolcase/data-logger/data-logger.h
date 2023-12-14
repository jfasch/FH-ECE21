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

    // starts logging for 'count' times
    // 0 means logging forever
    void startLogging(uint16_t count);

private:
    SinkLogger* _sink;
    SensorConfig* _sensors;
    uint16_t _interval;
    SensorValues _measurements;

    std::string timeBuffer;
};