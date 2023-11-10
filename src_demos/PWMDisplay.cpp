#include "PWMDisplay.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <chrono>
#include <thread>

PWMDisplay::PWMDisplay(int channel, unsigned long period) : channel(channel), period(period) {
    exportPWMChannel();
    setPeriod();
}

void PWMDisplay::exportPWMChannel() {
    std::ofstream exportFile("/sys/class/pwm/export");
    if (!exportFile.is_open()) {
        throw std::runtime_error("Failed to export PWM channel.");
    }
    exportFile << channel;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));  // Wait for pwmX directory to become visible
}

void PWMDisplay::setPeriod() {
    std::ofstream periodFile("/sys/class/pwm/pwm" + std::to_string(channel) + "/period");
    if (!periodFile.is_open()) {
        throw std::runtime_error("Failed to set PWM period.");
    }
    periodFile << period;
}

void PWMDisplay::setPercentage(unsigned long percentage) {
    if (percentage < 0 || percentage > 100) {
        throw std::invalid_argument("Percentage should be between 0 and 100");
    }

    unsigned long dutyCycle = (period * percentage) / 100;
    std::ofstream dutyCycleFile("/sys/class/pwm/pwm" + std::to_string(channel) + "/duty_cycle");
    if (!dutyCycleFile.is_open()) {
        throw std::runtime_error("Failed to set PWM duty cycle.");
    }
    dutyCycleFile << dutyCycle;
}
