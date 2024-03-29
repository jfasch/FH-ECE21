#pragma once

#include "sensor.h"

#include <string>
#include <cassert>
#include <fcntl.h>
#include <unistd.h>
#include <stdexcept>  


class W1Sensor : public Sensor
{
public:
    W1Sensor(std::string filename)
    {
        _filename = filename;
    }

    double get_temperature() override
    { 
        int fd = open(this->_filename.c_str(), O_RDONLY);
        if (fd == -1)
            throw std::runtime_error(std::string("Cannot open ") + _filename);
        
        char buffer[32];
        ssize_t nread = read(fd, buffer, sizeof(buffer));
        if (nread == -1) 
            throw std::runtime_error(std::string("Cannot read ") + _filename);

        int error = close(fd);
        assert(error != -1);

        long millis = std::stol(buffer);
        double temperature = (double)millis/1000;
        return temperature;
    }

private:
    std::string _filename;
};
