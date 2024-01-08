#pragma once

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <percentage-display.h>

class PWMController : public PercentageDisplay
{
private:
    std::string _path;
    unsigned int _period;
    std::string _channel;

public:
    PWMController(std::string controller_path, unsigned int period, unsigned int channel);
    virtual void show_percentage(double percentage);

};