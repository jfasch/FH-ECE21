#include <gtest/gtest.h>
#include <sensor-mock.h>
#include <switch-mock.h>
#include <boiling-pot.h>

TEST(BoilingPot_suite, basic)
{

    MockSensor sensor(30.2);
    MockSwitch switcH(MockSwitch::OFF);
    BoilingPot pot(&sensor, &switcH);

    pot.heat(37.5);
                                    
    ASSERT_EQ(switcH.state(), MockSwitch::ON);
}

TEST(BoilingPot_suite, cheat)
{

    MockSensor sensor(30.2);
    MockSwitch switcH(MockSwitch::OFF);
    BoilingPot pot(&sensor, &switcH);

    pot.heat(37.5);                               
    ASSERT_EQ(switcH.state(), MockSwitch::ON);

    sensor.set_temperature(100);
    ASSERT_EQ(switcH.state(), MockSwitch::OFF);

}