#include <sensor-const.h>
#include <sensor-random.h>

#include <map>
#include <iostream>
#include <unistd.h>


int main()
{
    ConstantSensor bottom_left(37.5);
    ConstantSensor bottom_right(-273.15);
    RandomSensor top_left(0, 666);
    RandomSensor top_right(-273.15, 0);

    // <input>
#if 1
    std::map<std::string, Sensor*> sensors;

    sensors["bl"] = &bottom_left;
    sensors["br"] = &bottom_right;
    sensors["tl"] = &top_left;
    sensors["tr"] = &top_right;
#else
    SensorConfig sensors;
    sensors.add("bl", &bottom_left);
    // ...
#endif

    // </input>

    // <loop>
#if 1
    while (true) {
        std::map<std::string, double> measurements;
        for (auto [name, sensor]: sensors)
            measurements[name] = sensor->get_temperature();

        // <output>
        for (auto [name, value]: measurements) {
            std::cout << name << ';' << value << ';';
        }
        std::cout << std::endl;

        // or store measurements in a std::vector, for easy testing?

        // </output>

        sleep(1);
    }
#else
    AcquisitionLoop loop(1, 5/*infinity?*/, sensors, /*sink?*/);
#endif
    // </loop>

    return 0;
}
