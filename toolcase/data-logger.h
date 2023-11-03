#pragma once
#include <LoggerSink.h>
#include <Sensorconfig.h>

class DataLogger
{
public:
    DataLogger(SensorConfig* sensors, LoggerSink* sink, uint16_t interval);

    void startLogging();

private:
    LoggerSink* _sink;
    SensorConfig* _sensors;
    uint16_t _interval;
};