#include "pwm_controll.h"
#include <chrono>
#include <thread>
#include <stdexcept>


int main()
{
	while(true)
	{
		LEDDisplay display; 
		for(int i = 0;i <= 100;i++)
		{
			display.LEDDisplay_set(i);
			std::this_thread::sleep_for(std::chrono::milliseconds(20));
		}
		for(int i = 100;i >= 0;i--)
		{
			display.LEDDisplay_set(i);
			std::this_thread::sleep_for(std::chrono::milliseconds(20));
		}
	}
	return 0;
}
