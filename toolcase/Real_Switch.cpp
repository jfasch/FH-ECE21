#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

class SysFSGPIOSwitch {
public:
    SysFSGPIOSwitch(int gpioPin) : pinNumber(gpioPin) {
        // Export the GPIO pin
        exportGPIO();
        // Wait a bit to ensure the GPIO directory becomes visible
        usleep(100000); // Sleep for 100ms (adjust as needed)
        // Configure the GPIO pin as an output
        configureOutput();
    }

    // Set the state of the GPIO pin (0 for low, 1 for high)
    void set_state(bool state) {
        std::string valueFilePath = "/sys/class/gpio/gpio" + std::to_string(pinNumber) + "/value";
        std::ofstream valueFile(valueFilePath.c_str());

        if (valueFile.is_open()) {
            valueFile << (state ? "1" : "0");
            valueFile.close();
        } else {
            std::cerr << "Failed to open GPIO value file for pin " << pinNumber << std::endl;
        }
    }

    ~SysFSGPIOSwitch() {
        // Unexport the GPIO pin when the object is destroyed
        unexportGPIO();
    }

private:
    int pinNumber;

    // Export the GPIO pin
    void exportGPIO() {
        std::ofstream exportFile("/sys/class/gpio/export");

        if (exportFile.is_open()) {
            exportFile << pinNumber;
            exportFile.close();
        } else {
            std::cerr << "Failed to open GPIO export file" << std::endl;
        }
    }

    // Configure the GPIO pin as an output
    void configureOutput() {
        std::string directionFilePath = "/sys/class/gpio/gpio" + std::to_string(pinNumber) + "/direction";
        std::ofstream directionFile(directionFilePath.c_str());

        if (directionFile.is_open()) {
            directionFile << "out";
            directionFile.close();
        } else {
            std::cerr << "Failed to open GPIO direction file for pin " << pinNumber << std::endl;
        }
    }

    // Unexport the GPIO pin
    void unexportGPIO() {
        std::ofstream unexportFile("/sys/class/gpio/unexport");

        if (unexportFile.is_open()) {
            unexportFile << pinNumber;
            unexportFile.close();
        } else {
            std::cerr << "Failed to open GPIO unexport file" << std::endl;
        }
    }
};
