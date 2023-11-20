#include <gtest/gtest.h>
#include <sensor-mock.h>
#include <switch-mock.h>
#include <boiling-pot.h>

TEST(BoilingPot_suite, basic)
{

    MockSensor sensor(30.2);  //MockSensor
    MockSwitch switcH(MockSwitch::State::OFF); //MockSwitch
    BoilingPot pot(&sensor, &switcH);

    pot.heat(37.5);
    pot.check();
                                    
    ASSERT_EQ(switcH.state(), MockSwitch::State::ON); //MockSwitch
}

TEST(BoilingPot_suite, cheat)
{

    MockSensor sensor(30.2); //
    MockSwitch switcH(MockSwitch::State::OFF); //
    BoilingPot pot(&sensor, &switcH);

    pot.heat(37.5);  
    pot.check();                             
    ASSERT_EQ(switcH.state(), MockSwitch::State::ON);

    sensor.set_temperature(100);
    pot.check(); 
    ASSERT_EQ(switcH.state(), MockSwitch::State::OFF);


}