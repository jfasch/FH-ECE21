#pragma once
#include <fstream>
#include <sink-logger.h>

class SinkFile : public SinkLogger
{
public:
    SinkFile(const std::string& filename) : _outFile(filename, std::ios::out | std::ios::app)
    {
        if (!_outFile.is_open())
        {
            throw std::runtime_error("Unable to open file: " + filename);
        }
    }

    virtual ~SinkFile()
    {
        if (_outFile.is_open())
        {
            _outFile.close();
        }
    }

    void output(SensorValues data) override
    {
        for (auto [name, value]: data)
        {
            _outFile << getTime() << "; " << name << "; " << value << std::endl;
        }
    }

private:
    std::ofstream _outFile;
};