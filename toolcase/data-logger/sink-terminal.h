#pragma once

#include <string>
#include <iostream>
#include "sink-logger.h"
#include "sensor-values.h" // Ensure this include is correct

/**
 * @class SinkTerminal
 * @brief Outputs data given via a SensorValues object to the stdout.
 * 
 */
class SinkTerminal : public SinkLogger
{
public:
    void output(const SensorValues& data) override // Match the signature with SinkLogger
    {
        for (const auto& [name, value]: data)
        {
            std::cout << name << " " << value << std::endl;
        }
    }
};