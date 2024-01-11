#pragma once

#include <vector>
#include <memory>
#include "sink-logger.h"
#include <sensor-values.h>

/**
 * @class SinkComposite
 * @brief A composite sink class that forwards data to multiple sinks.
 *
 * This class acts as a composite sink, holding multiple sink objects 
 * and delegating the output call to each of them in turn.
 */
class SinkComposite : public SinkLogger {
public:
    SinkComposite() = default;
    virtual ~SinkComposite() = default;

    // Adds a new sink to the composite.
    void addSink(const std::shared_ptr<SinkLogger>& sink) {
        _sinks.push_back(sink);
    }

    // Outputs data to all contained sinks.
    void output(const SensorValues& data) override {
        for (const auto& sink : _sinks) {
            sink->output(data);
        }
    }

private:
    std::vector<std::shared_ptr<SinkLogger>> _sinks;  // Collection of sink objects
};
