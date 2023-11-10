#include <data-logger.h>
#include <stdlib.h> 
#include <chrono>
#include <thread>  
#include <iostream>
#include <sensor-values.h>



DataLogger::DataLogger(SensorConfig* sensors, SinkLogger* sink, uint16_t interval)
{
    _sink = sink;
    _sensors = sensors;
    _interval = interval;
}

void DataLogger::startLogging()
{
    std::string buffer;

    while (1)
    {
        _measurements = _sensors->getAllMeasurements();
        _sink->output(_measurements);
        std::this_thread::sleep_for(std::chrono::milliseconds(_interval));
    }
}

