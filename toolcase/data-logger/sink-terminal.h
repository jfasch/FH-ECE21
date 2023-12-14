#pragma once
#include <string>
#include <iostream>
#include <sink-logger.h>

/**
 * @class SinkTermianl
 * @brief Outputs data given via a SensorValues object to the stdout
 * 
*/
class SinkTerminal : public SinkLogger
{
    public:
        void output(SensorValues data)
        {
            for (auto [name, value]: data)
            {
                std::cout << name << " " << value << std::endl;
            }
        }
};