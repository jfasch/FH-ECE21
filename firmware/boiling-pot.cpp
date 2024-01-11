#include <boiling-pot.h>
#include <sensor-w1.h>
#include <switch-mock.h>
#include <display-led-stripe.h>
#include <sysfs-switch.h>
#include <pwm_controller.h>
#include <display-pwm-stripe.h>
#include <composite-display.h>

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
        switcH = std::make_unique<SysFSGPIOSwitch>(gpio, true);
    else
        switcH = std::make_unique<StdOutSwitch>();
    
    SysFSGPIOSwitch sw1(26);
    SysFSGPIOSwitch sw2(19);
    SysFSGPIOSwitch sw3(13);
    SysFSGPIOSwitch sw4(6);
    SysFSGPIOSwitch sw5(5);
    SysFSGPIOSwitch sw6(0);
    SysFSGPIOSwitch sw7(11);
    SysFSGPIOSwitch sw8(9);
    SysFSGPIOSwitch sw9(10);
    SysFSGPIOSwitch sw10(22);

    std::vector<Switch*> leds{&sw1,&sw2,&sw3,&sw4,&sw5,&sw6,&sw7,&sw8,&sw9,&sw10};

  

    LEDStripeDisplay display1(leds);
    PWMStripeDisplay display2;


    std::vector<PercentageDisplay*> displays{&display1,&display2};

    CompositeDisplay compositedisplay(displays);


    BoilingPot pot(&sensor, switcH.get(), /*reporter*/nullptr, &compositedisplay);

    pot.heat(55);

    while (true) {
        sleep(1);
        try {
            pot.check();
        }
        catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
            switcH->off();
        }
    }
}
