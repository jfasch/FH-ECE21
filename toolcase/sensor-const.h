#pragma once

class ConstantSensor
{
public:
    ConstantSensor(double value);

    double value() const { return _value; }
    double get_temperature();

private:
    double _value;
};
