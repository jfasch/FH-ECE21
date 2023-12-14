#include "pwm_controller.h"
#include <chrono>
#include <thread>
#include <stdexcept>
#include <vector>

const std::string CONTROLLER_PATH = "/sys/class/pwm/pwmchip0";
#define PERIOD 1000000

std::vector<LEDDisplay> display;

int main()
{
	for(int i = 0; i < 10;i++)
	{
		display.emplace_back(CONTROLLER_PATH,PERIOD,i);	
	}
	int k = 0;
	for(int i = 0;i <= 100;i+=10)
	{
		for(int j = k;j < 10;j++)
		{
			display[k].set_percentage(i);
			k++;
			break;
		}
		//std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}

	return 0;
}
