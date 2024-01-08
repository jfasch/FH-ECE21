#pragma once

class PercentageDisplay
{
public:
    virtual ~PercentageDisplay() = default;
    virtual void show_percentage(double) = 0;
};
