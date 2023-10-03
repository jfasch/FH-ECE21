#pragma once

class MockSensor
{
public:
    MockSensor(double initial_temperature);
    double get_temperature();
    void set_temperature(double temperature);

private:
    double _temperature;
};
