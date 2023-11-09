#pragma once
#include <fstream>
#include <iostream>
#include <sink-logger.h>

class SinkFile : public SinkLogger
{
public:
    explicit SinkFile(const std::string& filename) 
        : _outFile(filename, std::ios::out | std::ios::app) // Open the file in append mode
    {
        if (!_outFile) // Check if the file is open (could not be opened)
        {
            throw std::runtime_error("Unable to open file: " + filename);
        }
    }

    virtual ~SinkFile()
    {
        if (_outFile.is_open())
        {
            _outFile.close(); // Close the file when the SinkFile is destroyed
        }
    }

    void output(SensorValues data) override
    {
        for (const auto& [name, value] : data)
        {
            _outFile << name << "; " << value << std::endl; // Write name and value separated by semicolon
        }
    }

private:
    std::ofstream _outFile; // File stream for output
};