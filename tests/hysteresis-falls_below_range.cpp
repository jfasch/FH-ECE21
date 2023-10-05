#include <gtest/gtest.h>
#include <sensor-mock.h>
#include <switch-mock.h>
#include <hysteresis.h>

TEST(hysteresis_suite, falls_below_range)
{
    MockSensor sensor(30.2);
    MockSwitch switcH(MockSwitch::OFF);

    Hysteresis hyst(&sensor, &switcH, 
                    20.1, 30.4);                       // <--- initially within range

    hyst.check();
    ASSERT_EQ(switcH.state(), MockSwitch::OFF);

    sensor.set_temperature(20.0);                      // <--- falls below range

    hyst.check();
    ASSERT_EQ(switcH.state(), MockSwitch::ON);
}
