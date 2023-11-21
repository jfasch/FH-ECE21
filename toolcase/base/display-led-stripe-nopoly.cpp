#include "display-led-stripe-nopoly.h"

//Implementierung

void LEDStripeDisplay_nopoly::check()
{
    //Rücksetzten aller LEDs
    for(std::size_t i = 0; i < _switches.size();i++)
    {
        _switches[i]->off();
    }

    //Erhalten der Temperatur vom Sensor
    double temp = _sensor->get_temperature();
    double counter_led = (temp/(_high - _low))*_switches.size();

    //Abfrage ob Temperatur unter der unteren Grenze liegt
    if(temp < _low)
    {
        counter_led = 0;
    }

    //Setzen der LEDs
    for(std::size_t i = 0; i < counter_led && i < _switches.size(); i++)
    {
        _switches[i]->on();
    }
}
