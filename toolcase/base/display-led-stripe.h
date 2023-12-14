#pragma once

#include <switch.h>
#include <vector>
#include <stdexcept>
#include "percentage-display.h"

class LEDStripeDisplay : public PercentageDisplay
{
public:
    LEDStripeDisplay(const std::vector<Switch*>& leds);
    void show_percentage(double percentage);

private:
    std::vector<Switch*> _leds;
};

