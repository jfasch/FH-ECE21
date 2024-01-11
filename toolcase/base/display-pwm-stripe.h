#pragma once

#include <switch-mock.h>
#include <sensor-mock.h>
#include <vector>
#include "pwm_controller.h"

class PWMStripeDisplay : public PercentageDisplay
{
public:
    PWMStripeDisplay();
    void show_percentage(double percentage);

private:

};