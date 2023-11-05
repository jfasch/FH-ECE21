#include <data-logger.h>
#include <stdlib.h> 
#include <chrono>
#include <thread>  
#include <iostream>



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
        for (auto [name, sensor]: *_sensors)
        {
            buffer.append(name + ";" + std::to_string(sensor->get_temperature()) + ";");
        }
        _sink->print(buffer);
        buffer.erase();
        std::this_thread::sleep_for(std::chrono::milliseconds(_interval));
    }
}

