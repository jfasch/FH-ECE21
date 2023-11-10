#pragma once
#include <sink-logger.h>
#include <sensor-config.h>

class DataLogger
{
public:
    DataLogger(SensorConfig* sensors, SinkLogger* sink, uint16_t interval);

    void startLogging();
    void startLogging(uint16_t count);

private:
    SinkLogger* _sink;
    SensorConfig* _sensors;
    uint16_t _interval;
    SensorValues _measurements;
};