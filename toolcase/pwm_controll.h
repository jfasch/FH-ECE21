#pragma once

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string> 
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>


class LEDDisplay
{
    private:
        std::string _path;
        unsigned int _period;
    public:
    LEDDisplay(std::string controller_path, unsigned int period)
    {
        _path = controller_path;
        _period = period;

        int period_file_descriptor = open((_path + "/period").c_str(), O_WRONLY);

        if(period_file_descriptor == -1)
        {
            throw std::runtime_error("Failed to open PWM controller Period file!");
        }
        
        std::string str = std::to_string(period);

        if(write(period_file_descriptor,str.c_str(), str.size()) == -1)
        {
            throw std::runtime_error("Failed to write to PWM controller Period file!");
        }
        close(period_file_descriptor);	
    }
    void set_percentage(int percentage);
};
