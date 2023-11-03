#include <data-logger.h>
#include <stdlib.h>     

DataLogger::DataLogger(SensorConfig* sensors, LoggerSink* sink, uint16_t interval)
{
    _sink = sink;
    _sensors = sensors;
    _interval = interval;
}

void DataLogger::startLogging()
{
    for (auto [name, sensor]: _sensors->getSensorMap())
    {
        _sink->print(name + ";" + std::to_string(sensor->get_temperature()) + "\n");
    }
    // TODO wait
}