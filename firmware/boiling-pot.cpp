#include <boiling-pot.h>
#include <sensor-w1.h>
#include <switch-mock.h>
#include <sysfs-switch.h>

#include <iostream>
#include <memory>


class StdOutSwitch : public Switch
{
public:
    void set_state(bool state) override
    {
        std::cout << (state? "ON" : "OFF") << '\n';
    }
};

int main(int argc, char** argv)
{
    if (argc != 2 && argc != 3) {
        std::cerr << "Usage: " << argv[0] << " TEMPERATURE-FILE [GPIO-NUMBER]\n";
        std::cerr << "    TEMPERATURE-FILE   contains temperature in milli-celsius\n";
        std::cerr << "    GPIO-NUMBER        gpio number (as per raspi pinout)\n";
        std::cerr << "                       default stdout messages\n";
        return 1;
    }

    std::string temperature_file = argv[1];
    int gpio = -1;
    if (argc == 3)
        gpio = std::stoi(argv[2]);

    W1Sensor sensor{temperature_file};
    std::unique_ptr<Switch> switcH;
    if (gpio >= 0)
        switcH = std::make_unique<SysFSGPIOSwitch>(gpio);
    else
        switcH = std::make_unique<StdOutSwitch>();


    BoilingPot pot(&sensor, switcH.get(), /*reporter*/nullptr, /*reporter*/nullptr);

    pot.heat(37.5);

    while (true) {
        sleep(1);
        try {
            pot.check();
        }
        catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
}
