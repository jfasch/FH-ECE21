#include <boiling-pot.h>
#include <sensor-w1.h>
#include <switch-mock.h>
#include <sysfs-switch.h>

#include <iostream>
#include <memory>


using namespace std;

class StdOutSwitch : public Switch
{
public:
    void set_state(bool state) override
    {
        cout << (state? "ON" : "OFF") << '\n';
    }
};

int main(int argc, char** argv)
{
    cout << argc << endl;
    if (argc != 2 && argc != 3) {
        cerr << "Usage: " << argv[0] << " TEMPERATURE-FILE [GPIO-NUMBER]\n";
        cerr << "    TEMPERATURE-FILE   contains temperature in milli-celsius\n";
        cerr << "    GPIO-NUMBER        gpio number (as per raspi pinout)\n";
        cerr << "                       default stdout messages\n";
        return 1;
    }

    string temperature_file = argv[1];
    int gpio = -1;
    if (argc == 3)
        gpio = stoi(argv[2]);

    W1Sensor sensor{temperature_file};
    unique_ptr<Switch> switcH;
    if (gpio >= 0)
        switcH = make_unique<SysFSGPIOSwitch>(gpio);
    else
        switcH = make_unique<StdOutSwitch>();


    BoilingPot pot(&sensor, switcH.get(), /*reporter*/nullptr);

    pot.heat(37.5);

    while (true) {
        sleep(1);
        pot.check();
    }
}
