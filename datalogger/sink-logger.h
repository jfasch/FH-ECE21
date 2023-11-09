
#pragma once

#include <sensor-values.h>
#include <string>
#include <ctime>

class SinkLogger
{
public:
    virtual ~SinkLogger() {}
    virtual void output(SensorValues data) = 0;

    std::string getTime()
    {
        time_t currentTime;
        time(&currentTime);
        timeBuffer = ctime(&currentTime);
        timeBuffer.erase(20, 5); // remove newline 
        return timeBuffer;
    }
    
private:
std::string timeBuffer;

};
