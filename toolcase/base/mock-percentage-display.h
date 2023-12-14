#pragma once

#include "percentage-display.h"


class MockPercentageDisplay : public PercentageDisplay
{
public:
    MockPercentageDisplay(double initial_value)
    : _current_percentage(initial_value) {}

    virtual void show_percentage(double value) 
    {
        _current_percentage = value;
    }

    double percentage_shown() const
    {
        return _current_percentage;
    }
    
private:
    double _current_percentage;
};
