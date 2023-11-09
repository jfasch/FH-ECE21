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
        for (auto [name, sensor]: *_sensors)
        {
            _measurements.addMeasurement(name, sensor->get_temperature());
            //buffer.append(name + ";" + std::to_string(sensor->get_temperature()) + ";");
        }
        _sink->output(_measurements);
        //buffer.erase();
        std::this_thread::sleep_for(std::chrono::milliseconds(_interval));
    }
}

