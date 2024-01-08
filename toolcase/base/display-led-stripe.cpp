#include <switch-mock.h>
#include <sensor-mock.h>
#include <vector>
#include "display-led-stripe.h"

void LEDStripeDisplay::show_percentage(double percentage)
{
    if (percentage < 0 || percentage > 1)
	{
		throw std::runtime_error("Input has to be between 0 and 1!");
	}
    for(std::size_t i = 0; i < percentage*_leds.size(); i++)
    {
        _leds[i]->on();
    }
    for(std::size_t i = percentage*_leds.size(); i < _leds.size(); i++)
    {
        _leds[i]->off();
    }
}

