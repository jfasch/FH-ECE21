#include <gtest/gtest.h>
#include <sensor-mock.h>
#include <switch-mock.h>
#include <hysteresis.h>

TEST(hysteresis_suite, rises_above_range)
{
    MockSensor sensor(30.2);
    MockSwitch switcH(MockSwitch::OFF);

    Hysteresis hyst(&sensor, &switcH, 20.1, 30.4);

    hyst.check();
    ASSERT_EQ(switcH.state(), MockSwitch::OFF);

    sensor.set_temperature(35);                        // <--- rises above range

    hyst.check();
    ASSERT_EQ(switcH.state(), MockSwitch::OFF);
}
