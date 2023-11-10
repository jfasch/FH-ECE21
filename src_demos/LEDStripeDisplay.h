#pragma once
#include "PercentageDisplay.h"

class LEDStripeDisplay : public PercentageDisplay {
public:
    void setPercentage(unsigned long percentage) override;
};
