#pragma once

#include <random>


class RandomSensor
{
public:
    RandomSensor(double low, double high);

    double low() const { return _low; }
    double high() const { return _high; }

    double get_temperature();

private:
    std::uniform_real_distribution<double> _distribution;
    std::default_random_engine _engine;

    double _low;
    double _high;
};
