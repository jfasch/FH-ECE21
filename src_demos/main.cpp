#include <iostream>
#include "PWMDisplay.h"
#include "LEDStripeDisplay.h"

int main() {
    int pwmChannel = 5;  // Example PWM channel
    unsigned long period = 10000000;  // Example period (10 ms)

    PWMDisplay pwmDisplay(pwmChannel, period);
    LEDStripeDisplay ledStripeDisplay;

    try {
        while (true) {
            unsigned long percentage;
            std::cout << "Enter percentage (0-100): ";
            std::cin >> percentage;

            pwmDisplay.setPercentage(percentage);
            ledStripeDisplay.setPercentage(percentage);
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

