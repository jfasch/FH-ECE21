#include <sensor-mock.h>
#include <switch-mock.h>
#include <hysteresis.h>
#include <boiling-pot.h>

int main()
{
    
    MockSensor sensor(0);
    MockSwitch switcH(MockSwitch::OFF);

    BoilingPot pot(sensor, switcH);
    // pot.configure(37.5);
    pot.heat(37.5);

    while (true) {
       sleep(1);
       pot.check();
    }
}
