#include "pwm_controller.h"


void PWMController::set_percentage(int percentage)
    {
		if(percentage < 0 || percentage > 100)
		{
			throw std::runtime_error("Input has to be between 0 and 100!");
		}
		
		int duty_file_descriptor = open((_path + "/pwm" + _channel +"/duty_cycle").c_str(), O_WRONLY);

		if(duty_file_descriptor == -1)
		{
			throw std::runtime_error("Failed to open PWM controller duty cycle file!");
		}

		std::string str = std::to_string(_period * percentage / 100);

		if(write(duty_file_descriptor,str.c_str(), str.size()) == -1)
        {
            throw std::runtime_error("Failed to write to PWM controller duty cycle file!");
        }
        close(duty_file_descriptor);	
	}


