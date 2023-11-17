#pragma once

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

class LEDDisplay
{
    private:

    public:
    LEDDisplay(std::string controller_path, unsigned int period)
    {
        std::ofstream periodFile(controller_path + "/period");
		
		if(!periodFile.is_open())
		{
			throw std::runtime_error("Failed to open PWM controller file!");
		}
			
		periodFile << period;
		
    }
    void set_percentage(int percentage);
};
