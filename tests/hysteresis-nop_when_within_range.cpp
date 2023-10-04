#include <gtest/gtest.h>
#include <sensor-mock.h>
#include <switch-mock.h>
#include <hysteresis.h>

TEST(hysteresis_suite, nop_when_within_range)
{
    MockSensor sensor(30.2);
    MockSwitch switcH(MockSwitch::OFF);

    Hysteresis hyst(&sensor, &switcH, 20.1, 30.4);

    hyst.check();                                      // <--- sees sensor well within range
    ASSERT_EQ(switcH.state(), MockSwitch::OFF);
}
