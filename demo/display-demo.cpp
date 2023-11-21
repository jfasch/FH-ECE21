#include "pwm_controll.h"
#include <chrono>
#include <thread>
#include <stdexcept>

const std::string CONTROLLER_PATH = "/sys/class/pwm/pwmchip0";
#define PERIOD 1000000

int main()
{
	while(true)
	{
		LEDDisplay display(CONTROLLER_PATH,PERIOD,10); 
		for(int i = 0;i <= 100;i++)
		{
			display.set_percentage(i);
			std::this_thread::sleep_for(std::chrono::milliseconds(20));
		}
		for(int i = 100;i >= 0;i--)
		{
			display.set_percentage(i);
			std::this_thread::sleep_for(std::chrono::milliseconds(20));
		}
	}
	return 0;
}
