#pragma once

#include <switch.h>
#include <vector>
#include <stdexcept>
#include "percentage-display.h"

class CompositeDisplay : public PercentageDisplay
{
public:
    CompositeDisplay(const std::vector<PercentageDisplay*>& displays)
    {
        _displays = displays;
    }
    void show_percentage(double percentage);

private:
    std::vector<PercentageDisplay*> _displays;
};