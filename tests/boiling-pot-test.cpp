#include <gtest/gtest.h>
#include <sensor-mock.h>
#include <switch-mock.h>
#include <boiling-pot.h>
#include <mock-reporter.h>
#include <mock-percentage-display.h>

TEST(BoilingPot_suite, basic)
{
    MockSensor sensor(30.2);
    MockSwitch switcH(MockSwitch::State::OFF);
    BoilingPot pot(&sensor, &switcH, /*reporter*/nullptr, /*percentage-display*/nullptr);

    pot.heat(37.5);
    pot.check();
                                    
    ASSERT_EQ(switcH.state(), MockSwitch::State::ON);
}

TEST(BoilingPot_suite, cheat)
{
    MockSensor sensor(30.2);
    MockSwitch switcH(MockSwitch::State::OFF);
    BoilingPot pot(&sensor, &switcH, /*reporter*/nullptr, /*percentage-display*/nullptr);

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
    BoilingPot pot(&sensor, &switcH, &reporter, /*percentage-display*/nullptr);

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

TEST(BoilingPot_suite, percentage_display)
{
    // BoilingPot currently uses a PercentageDisplay to display the
    // temperature. In doing so, it uses temperature as percentage -
    // unmapped. That is, 37.5 celsius are shown as 37.5 percent.

    MockPercentageDisplay display(/*initial percentage*/0);

    MockSensor sensor(30.2);
    MockSwitch switcH(MockSwitch::State::OFF);
    BoilingPot pot(&sensor, &switcH, /*reporter*/nullptr, &display);

    pot.heat(37.5);  
    pot.check();

    ASSERT_FLOAT_EQ(display.percentage_shown(), 30.2);

    sensor.set_temperature(100);
    pot.check();

    ASSERT_FLOAT_EQ(display.percentage_shown(), 100.0);
}

