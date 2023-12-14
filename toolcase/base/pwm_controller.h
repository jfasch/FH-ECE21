#pragma once

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string> 
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>


class PWMController
{
private:
        std::string _path;
        unsigned int _period;
        std::string _channel;
public:
    PWMController(std::string controller_path, unsigned int period,unsigned int channel)
    {
        _path = controller_path;
        _period = period;
        _channel = std::to_string(channel);
        int period_file_descriptor;

        while(1)
        {
            period_file_descriptor = open((_path + "/pwm" + _channel + "/period").c_str(), O_WRONLY);

            if(period_file_descriptor == -1)
            {
                if(errno == ENOENT)
                {
                    int export_file_descriptor = open((_path + "/export").c_str(), O_WRONLY);
                    if(export_file_descriptor == -1)
                    {
                        throw std::runtime_error("Failed to open PWM controller directory!");
                    }
                    if(write(export_file_descriptor,_channel.c_str(), _channel.size()) == -1)
                    {
                        throw std::runtime_error("Failed to write to PWM controller Period file!");
                    }
                    close(export_file_descriptor);	
                }
            }
            else
            {
                break;
            }
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
