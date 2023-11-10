#include "pwm_controll.h"

const std::string CONTROLLER_PATH = "/sys/class/pwm/pwmchip0/pwm0";
#define PERIOD 1000000


void LEDDisplay::LEDDisplay_set(int percentage)
    {
		if(percentage < 0 || percentage > 100)
		{
			throw std::runtime_error("Input has to be between 0 and 100!");
		}
		
		std::ofstream periodFile(CONTROLLER_PATH + "/period");
		
		if(!periodFile.is_open())
		{
			throw std::runtime_error("Failed to open PWM controller file!");
		}
			
		periodFile << PERIOD;
		
		std::ofstream dutyFile(CONTROLLER_PATH + "/duty_cycle");
		
		if(!dutyFile.is_open())
		{
			throw std::runtime_error("Failed to open PWM controller file!");
		}
		dutyFile << PERIOD * percentage / 100;
	}


