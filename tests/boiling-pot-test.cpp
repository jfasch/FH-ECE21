#include <gtest/gtest.h>
#include <sensor-mock.h>
#include <switch-mock.h>
#include <boiling-pot.h>
#include <mock-reporter.h>

TEST(BoilingPot_suite, basic)
{
    MockSensor sensor(30.2);
    MockSwitch switcH(MockSwitch::State::OFF);
    BoilingPot pot(&sensor, &switcH, /*reporter*/nullptr);

    pot.heat(37.5);
    pot.check();
                                    
    ASSERT_EQ(switcH.state(), MockSwitch::State::ON);
}

TEST(BoilingPot_suite, cheat)
{
    MockSensor sensor(30.2);
    MockSwitch switcH(MockSwitch::State::OFF);
    BoilingPot pot(&sensor, &switcH, /*reporter*/nullptr);

    pot.heat(37.5);  
    pot.check();                             
    ASSERT_EQ(switcH.state(), MockSwitch::State::ON);

    sensor.set_temperature(100);
    pot.check(); 
    ASSERT_EQ(switcH.state(), MockSwitch::State::OFF);
}

TEST(BoilingPot_suite, status_report)
{
    MockReporter reporter;

    MockSensor sensor(30.2);
    MockSwitch switcH(MockSwitch::State::OFF);
    BoilingPot pot(&sensor, &switcH, &reporter);

    pot.heat(37.5);  
    pot.check();  // -> on, current temperature 30.2

    ASSERT_EQ(reporter.size(), 1);
    ASSERT_TRUE(reporter[0].switch_state);
    ASSERT_FLOAT_EQ(reporter[0].current_temperature, 30.2);

    sensor.set_temperature(100);
    pot.check();  // -> off, current temperature 100.0

    ASSERT_EQ(reporter.size(), 2);
    ASSERT_FALSE(reporter[1].switch_state);
    ASSERT_FLOAT_EQ(reporter[1].current_temperature, 100.0);

}
