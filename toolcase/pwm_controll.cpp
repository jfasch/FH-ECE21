#include "pwm_controll.h"

const std::string CONTROLLER_PATH = "/sys/class/pwm/pwmchip0/pwm0";
#define PERIOD 1000000


void LEDDisplay::set_percentage(int percentage)
    {
		if(percentage < 0 || percentage > 100)
		{
			throw std::runtime_error("Input has to be between 0 and 100!");
		}
		
		std::ofstream dutyFile(CONTROLLER_PATH + "/duty_cycle");
		
		if(!dutyFile.is_open())
		{
			throw std::runtime_error("Failed to open PWM controller file!");
		}
		dutyFile << PERIOD * percentage / 100;
	}


