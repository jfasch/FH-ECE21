#include "pwm_controller.h"

PWMController::PWMController(std::string controller_path, unsigned int period, unsigned int channel)
{
	_path = controller_path;
	_period = period;
	_channel = std::to_string(channel);
	int period_file_descriptor;

	while (1)
	{
		period_file_descriptor = open((_path + "/pwm" + _channel + "/period").c_str(), O_WRONLY);

		if (period_file_descriptor == -1)
		{
			if (errno == ENOENT)
			{
				int export_file_descriptor = open((_path + "/export").c_str(), O_WRONLY);
				if (export_file_descriptor == -1)
				{
					throw std::runtime_error("Failed to open PWM controller directory!");
				}
				if (write(export_file_descriptor, _channel.c_str(), _channel.size()) == -1)
				{
					throw std::runtime_error("Failed to write to PWM controller Period file!");
				}
				close(export_file_descriptor);
			}
		}
		else
		{
			break;
		}
	}
	std::string str = std::to_string(period);

	if (write(period_file_descriptor, str.c_str(), str.size()) == -1)
	{
		throw std::runtime_error("Failed to write to PWM controller Period file!");
	}
	close(period_file_descriptor);
}

void PWMController::show_percentage(double percentage)
{
	percentage *= 100;
	if (percentage < 0 || percentage > 100)
	{
		throw std::runtime_error("Input has to be between 0 and 100!");
	}

	int duty_file_descriptor = open((_path + "/pwm" + _channel + "/duty_cycle").c_str(), O_WRONLY);

	if (duty_file_descriptor == -1)
	{
		throw std::runtime_error("Failed to open PWM controller duty cycle file!");
	}

	std::string str = std::to_string(_period * (unsigned int)percentage / 100);

	if (write(duty_file_descriptor, str.c_str(), str.size()) == -1)
	{
		throw std::runtime_error("Failed to write to PWM controller duty cycle file!");
	}
	close(duty_file_descriptor);
}
