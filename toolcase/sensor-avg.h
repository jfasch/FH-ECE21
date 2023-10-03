#pragma once

#include <sensor-mock.h>

#include <vector>


class AveragingSensor
{
public:
    void add(MockSensor*);
    double get_temperature();

private:
    std::vector<MockSensor*> _sensors;
};
