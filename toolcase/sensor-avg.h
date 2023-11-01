#pragma once

#include <sensor-mock.h>
#include <sensor.h>
#include <vector>


class AveragingSensor : public Sensor
{
public:
    void add(Sensor*);
    double get_temperature();

private:
    std::vector<Sensor*> _sensors;
};
