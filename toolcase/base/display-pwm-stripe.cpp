#include "display-pwm-stripe.h"

const std::string CONTROLLER_PATH = "/sys/class/pwm/pwmchip0";
const uint period = 1000000;

std::vector<PWMController> display;

PWMStripeDisplay::PWMStripeDisplay()
{
    for(int i = 0; i < 10;i++)
    {
        display.emplace_back(CONTROLLER_PATH,period,i);	
    }
}

void PWMStripeDisplay::show_percentage(double percentage)
{
    for(int i = 0;i < 10;i++)
    {
        display[i].show_percentage(0);
    }
    if (percentage < 0 || percentage > 1)
	{
		throw std::runtime_error("Input has to be between 0 and 1!(pwm-stripe)");
	}

    float remainder = 0;
    std::size_t i;

    for(i = 0; i < percentage* display.size(); i++)
    {
        display[i].show_percentage(1);   
    }
    remainder = (percentage * display.size() - (i-1));
    if(i == display.size()-1)
    {
        return;
    }
    display[i].show_percentage(remainder);
}



