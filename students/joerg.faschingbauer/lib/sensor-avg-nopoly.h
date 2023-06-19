#pragma once

#include <sensor-mock-nopoly.h>

#include <vector>


class AveragingSensor_nopoly
{
public:
    void add(MockSensor_nopoly*);
    double get_temperature();

private:
    std::vector<MockSensor_nopoly*> _sensors;
};
