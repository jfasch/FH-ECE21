#include "pwm_controller.h"
// #include "display-led-stripe.h"
#include <chrono>
#include <thread>
#include <stdexcept>
#include <vector>

const std::string CONTROLLER_PATH = "/sys/class/pwm/pwmchip0";
#define PERIOD 1000000


int main()
{
	PWMController pwmController(CONTROLLER_PATH,PERIOD,1);
//	LEDStripeDisplay led_stripe(...switches...);
	PercentageDisplay* display = &pwmController;
//	PercentageDisplay* display = &led_stripe;
	
	display->show_percentage(0.10);
}
