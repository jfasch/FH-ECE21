#include <gtest/gtest.h>
#include <sensor-mock.h>
#include <switch-mock.h>
#include <hysteresis.h>

TEST(hysteresis_suite, rises_above_range_when_on)
{
    MockSensor sensor(30.2);
    MockSwitch switcH(MockSwitch::OFF);

    Hysteresis hyst(&sensor, &switcH, 20.1, 30.4);

    sensor.set_temperature(-273.15);                   // <--- ensure that switch will be 
                                                       //      on after next check()

    hyst.check();
    ASSERT_EQ(switcH.state(), MockSwitch::ON);

    sensor.set_temperature(35);                        // <--- rises above range

    hyst.check();
    ASSERT_EQ(switcH.state(), MockSwitch::OFF);
}
