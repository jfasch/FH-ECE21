
#pragma once

#include <sensor-values.h>
#include <string>
#include <ctime>

/**
 * @class SinkLogger
 * @brief virtual class to handle different sinks for the DataLogger
 *
 * every Sink needs an output functions which outputs data given via a 
 * SensorValues Object.
 * 
*/
class SinkLogger
{
public:
    virtual ~SinkLogger() {}
    virtual void output(SensorValues data) = 0;

};
