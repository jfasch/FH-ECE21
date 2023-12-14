#include "sysfs-switch.h"

#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include <iostream>


SysFSGPIOSwitch::SysFSGPIOSwitch(int gpioPin) : pinNumber(gpioPin)
{
    exportGPIO();
    usleep(100000); // 0.1s sleep (assumed value that can be adjusted if necessary)
    configureOutput();
}

void SysFSGPIOSwitch::set_state(bool state)
{
    std::string valueFilePath = "/sys/class/gpio/gpio" + std::to_string(pinNumber) + "/value";
    int valueFile = open(valueFilePath.c_str(), O_WRONLY);

    if (valueFile != -1)
    {
        const char *value = (state ? "1" : "0");
        write(valueFile, value, strlen(value));
        close(valueFile);
    }
    else
    {
        perror("Failed to open GPIO value file");
    }
}

bool SysFSGPIOSwitch::get_state()
{
    std::string valueFilePath = "/sys/class/gpio/gpio" + std::to_string(pinNumber) + "/value";
    int valueFile = open(valueFilePath.c_str(), O_RDONLY);

    if (valueFile != -1)
    {
        char buffer;
        read(valueFile, &buffer, 1);
        close(valueFile);

        return (buffer == '1');
    }
    else
    {
        perror("Failed to open GPIO value file");
        return false; // Return a default value if the file cannot be opened
    }
}


SysFSGPIOSwitch::~SysFSGPIOSwitch()
{
    unexportGPIO();
}

void SysFSGPIOSwitch::exportGPIO()
{
    const char *exportFilePath = "/sys/class/gpio/export";
    int exportFile = open(exportFilePath, O_WRONLY);

    if (exportFile != -1)
    {
        const char *pin = std::to_string(pinNumber).c_str();
        write(exportFile, pin, strlen(pin));
        close(exportFile);
    }
    else
    {
        perror("Failed to open GPIO export file");
    }
}

void SysFSGPIOSwitch::configureOutput()
{
    std::string directionFilePath = "/sys/class/gpio/gpio" + std::to_string(pinNumber) + "/direction";
    int directionFile = open(directionFilePath.c_str(), O_WRONLY);

    if (directionFile != -1)
    {
        const char *direction = "out";
        write(directionFile, direction, strlen(direction));
        close(directionFile);
    }
    else
    {
        perror("Failed to open GPIO direction file");
    }
}

void SysFSGPIOSwitch::unexportGPIO()
{
    const char *unexportFilePath = "/sys/class/gpio/unexport";
    int unexportFile = open(unexportFilePath, O_WRONLY);

    if (unexportFile != -1)
    {
        const char *pin = std::to_string(pinNumber).c_str();
        write(unexportFile, pin, strlen(pin));
        close(unexportFile);
    }
    else
    {
        perror("Failed to open GPIO unexport file");
    }
}
