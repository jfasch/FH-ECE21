#pragma once
#include "PercentageDisplay.h"

class PWMDisplay : public PercentageDisplay {
private:
    int channel;
    unsigned long period;

public:
    PWMDisplay(int channel, unsigned long period);
    void exportPWMChannel();
    void setPeriod();
    void setPercentage(unsigned long percentage) override;  // Add this line
};
