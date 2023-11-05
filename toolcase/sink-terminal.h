#pragma once
#include <string>
#include <iostream>
#include <sink-logger.h>


class SinkTerminal : public SinkLogger
{
    public:
        void print(std::string data)
        {
            std::string timeStamp = getTime();            
            std::cout << timeStamp + ";" + data << std::endl;
        }
};