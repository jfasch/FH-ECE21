#include <gtest/gtest.h>

#include <switch-mock.h>
#include <sensor-mock.h>
#include <display-led-stripe.h>

#include <vector>

TEST(display_led_stripe_suite, variation_2_switches)
{
    MockSensor sensor(36.5);                    // <--- right in the middle of [0,80]
    MockSwitch sw0(MockSwitch::OFF);
    MockSwitch sw1(MockSwitch::OFF);

    std::vector<MockSwitch*> switches = { &sw0, &sw1 };
    LEDStripeDisplay display(
        0, 80,                                         // <--- [0,80]
        &sensor, switches);

    display.check();

    ASSERT_EQ(sw0.state(), MockSwitch::ON);
    ASSERT_EQ(sw1.state(), MockSwitch::OFF);
}

TEST(display_led_stripe_suite, variation_interval_not_from_0)
{
    MockSensor sensor(10.7);                    // <--- right above low
    MockSwitch sw0(MockSwitch::OFF);
    MockSwitch sw1(MockSwitch::OFF);

    std::vector<MockSwitch*> switches = { &sw0, &sw1 };
    LEDStripeDisplay display(
        10.5, 80,                                      // <--- [10.5,80]
        &sensor, switches);

    display.check();

    ASSERT_EQ(sw0.state(), MockSwitch::ON);
    ASSERT_EQ(sw1.state(), MockSwitch::OFF);

    sensor.set_temperature(45.7);                      // <--- into second LED

    display.check();

    ASSERT_EQ(sw0.state(), MockSwitch::ON);
    ASSERT_EQ(sw1.state(), MockSwitch::ON);
}
