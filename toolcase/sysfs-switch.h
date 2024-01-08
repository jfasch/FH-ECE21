#ifndef SYSFS_SWITCH_H
#define SYSFS_SWITCH_H

#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include <iostream>

class SysFSGPIOSwitch
{
public:
    SysFSGPIOSwitch(int gpioPin, int actLow);
    void set_state(bool state);
    bool get_state();
    ~SysFSGPIOSwitch();

private:
    int pinNumber;
    int activeLow;
    void exportGPIO();
    void configureOutput();
    void unexportGPIO();
};

#endif // SYSFS_SWITCH_H