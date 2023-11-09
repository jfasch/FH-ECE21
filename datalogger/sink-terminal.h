#pragma once
#include <string>
#include <iostream>
#include <sink-logger.h>


class SinkTerminal : public SinkLogger
{
    public:
        void output(SensorValues data)
        {
            for (auto [name, value]: data)
            {
                std::cout << name << " " << value << std::endl;
            }
            //std::string timeStamp = getTime();            
            //std::cout << timeStamp + ";" + data << std::endl;
        }
};