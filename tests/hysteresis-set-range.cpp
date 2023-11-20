#include <gtest/gtest.h>
#include <sensor-mock.h>
#include <switch-mock.h>
#include <hysteresis.h>

TEST(hysteresis_suite, set_range)
{

    MockSensor sensor(30.2);
    MockSwitch switcH(MockSwitch::State::OFF);

    Hysteresis hyst(&sensor, &switcH, 
                    20.1, 30.4);                       // <--- initially within range
    hyst.check();
    ASSERT_EQ(switcH.state(),MockSwitch::State::OFF);

    hyst.set_range(0,2); //low range
    hyst.check();
    ASSERT_EQ(switcH.state(),MockSwitch::State::OFF);

    sensor.set_temperature(-2);

    hyst.check();
    ASSERT_EQ(switcH.state(),MockSwitch::State::ON);

    hyst.set_range(100,102); //high range
    hyst.check();
    ASSERT_EQ(switcH.state(), MockSwitch::State::ON);
    sensor.set_temperature(90);
    hyst.check();
    ASSERT_EQ(switcH.state(),MockSwitch::State::ON);
    sensor.set_temperature(105);
    hyst.check();
    ASSERT_EQ(switcH.state(),MockSwitch::State::OFF);


}
