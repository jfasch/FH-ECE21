#ifndef SYSFS_SWITCH_H
#define SYSFS_SWITCH_H

#include "switch.h"

class SysFSGPIOSwitch : public Switch
{
public:
    SysFSGPIOSwitch(int gpioPin, bool actLow = 0);
    void set_state(bool state) override;
    bool get_state();
    ~SysFSGPIOSwitch();

private:
    int pinNumber;
    bool activeLow;
    void exportGPIO();
    void configureOutput();
    void unexportGPIO();
};

#endif // SYSFS_SWITCH_H
