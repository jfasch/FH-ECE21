#include <iostream>
#include "sysfs-switch.h"

int main() 
{
    // Specify the GPIO pin number you want to use
    int gpioPin = 20;  // You can change this to the desired GPIO pin number

    // Create an instance of SysFSGPIOSwitch
    SysFSGPIOSwitch gpioSwitch(gpioPin);

    // Interactively control the GPIO state
    char userInput;
    do 
    {
        std::cout << "Enter '1' to turn ON, '0' to turn OFF, or 'q' to quit: ";
        std::cin >> userInput;

        if (userInput == '1') 
        {
            gpioSwitch.set_state(true);
            std::cout << "GPIO turned ON\n";
        } 
        else if (userInput == '0') 
        {
            gpioSwitch.set_state(false);
            std::cout << "GPIO turned OFF\n";
        } 
        else if (userInput != 'q') 
        {
            std::cout << "Invalid input. Try again.\n";
        }

    } 
    while (userInput != 'q');

    std::cout << "Exiting test program.\n";

    return 0;
}
