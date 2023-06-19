#pragma once

class MockSensor_nopoly
{
public:
    MockSensor_nopoly(double initial_temperature);
    double get_temperature();
    void set_temperature(double temperature);

private:
    double _temperature;
};
