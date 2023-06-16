#pragma once

#include <random>


class RandomSensor
{
public:
    RandomSensor(double low, double high)
    : _low(low), _high(high), _engine(_rd()), _distribution(_low, _high)
    {}

    double low() const { return _low; }
    double high() const { return _high; }

    double get_temperature()
    {
        double number = _distribution(_engine);
        return number;
    }

private:
    const double _low;
    const double _high;

    std::random_device _rd;
    std::default_random_engine _engine;
    std::uniform_real_distribution<double> _distribution;
};
