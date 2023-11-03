
#pragma once

#include <string>

class LoggerSink
{
public:
    virtual ~LoggerSink() {}
    virtual void print(std::string data) = 0;
};
