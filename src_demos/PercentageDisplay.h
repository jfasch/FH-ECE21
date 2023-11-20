#pragma once

class PercentageDisplay {
public:
    virtual void setPercentage(unsigned long percentage) = 0;
    virtual ~PercentageDisplay() = default;
};

