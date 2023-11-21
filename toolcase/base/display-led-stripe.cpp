#include "display-led-stripe.h"

void LEDStripeDisplay::check()
{
    const double step = (_high - _low) / _leds.size();
    const double temperature = _sensor->get_temperature();
    for (std::size_t i=0; i<_leds.size(); i++)
        if (temperature >= _low + i*step)
            _leds[i]->on();
        else
            _leds[i]->off();
}
