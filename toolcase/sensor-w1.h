#pragma once

#include "sensor.h"

#include <string>
#include <cassert>
#include <fcntl.h>
#include <unistd.h>


class W1Sensor : public Sensor
{
public:
    W1Sensor(std::string filename)
    {
        _filename = filename;
    }

    double get_temperature()
    { 
        int fd = open(this->_filename.c_str(), O_RDONLY);
        assert(fd != -1);    // <--- crashes program
        
        char buffer[32];
        ssize_t nread = read(fd, buffer, sizeof(buffer));
        assert(nread != -1);

        int error = close(fd);
        assert(error != -1);

        long millis = std::stol(buffer);
        double temperature = (double)millis/1000;
        return temperature;
    }

private:
    std::string _filename;
};



