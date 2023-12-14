#pragma once
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>
#include "sink-logger.h"
#include "sensor-values.h"  // Include the SensorValues class

/**
 * @class SinkFile
 * @brief Outputs data given via a SensorValues object to a file in CSV style formatting.
 *        The first row contains sensor names, and subsequent rows contain sensor values.
 *
 * @param filename: Filename where data will be stored. Existing file will be overwritten!
 * @param columnMapping: Maps sensor names to CSV column names.
 */
class SinkFile : public SinkLogger {
public:
    explicit SinkFile(const std::string& filename,
                      const std::vector<std::pair<std::string, std::string>>& columnMapping)
        : _outFile(filename, std::ios::out) {  // Open the file in overwrite mode
        if (!_outFile) {
            throw std::runtime_error("Unable to open file: " + filename);
        }

        // Write the column headers
        for (const auto& [csvName, _] : _columnMapping) {
            _outFile << csvName << ";";
        }
        _outFile << std::endl;
    }

    virtual ~SinkFile() {
        if (_outFile.is_open()) {
            _outFile.close();
        }
    }

    void output(const SensorValues& data) override {
        for (const auto& [_, sensorName] : _columnMapping) {
            try {
                float value = data.getMeasurement(sensorName);
                _outFile << value << ";";
            } catch (const std::out_of_range& e) {
                _outFile << "N/A;";
            }
        }
        _outFile << std::endl;
    }

private:
    std::ofstream _outFile;  // File stream for output
    std::vector<std::pair<std::string, std::string>> _columnMapping;  // Maps sensor names to CSV column names
};
