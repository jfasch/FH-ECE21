#include <sensor-mock.h>
#include <switch-mock.h>
#include <hysteresis.h>

int main()
{
    // BoilingPot pot(sensor, switcH);
    // pot.configure(37.5);

    MockSensor sensor(0);
    MockSwitch switcH(MockSwitch::OFF);

    double wanted_temperature = 37.5;

    Hysteresis hyst(&sensor, &switcH, wanted_temperature-2, wanted_temperature+2);

    while (true) {
        sleep(1);
        hyst.check();
    }
}
