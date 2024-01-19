#include <gtest/gtest.h>
#include <string>
#include <switch.h>
#include <switch-mock.h>
#include <sysfs-switch.h>
#include <composite-switch.h>


TEST(compositeSwitch_suite, basic)
{

    MockSwitch mock1(MockSwitch::State::OFF);
    MockSwitch mock2(MockSwitch::State::ON);
    MockSwitch mock3(MockSwitch::State::OFF);
    CompositeSwitch compositeS;
    compositeS.addSwitch(&mock1);
    compositeS.addSwitch(&mock2);
    compositeS.addSwitch(&mock3);


    ASSERT_EQ(compositeS.size(), 3);

    compositeS.set_state(false);
    ASSERT_TRUE(mock1.state() == MockSwitch::State::OFF);
    ASSERT_TRUE(mock2.state() == MockSwitch::State::OFF);
    ASSERT_TRUE(mock3.state() == MockSwitch::State::OFF);

    compositeS.set_state(true);
    ASSERT_TRUE(mock1.state() == MockSwitch::State::ON);
    ASSERT_TRUE(mock2.state() == MockSwitch::State::ON);
    ASSERT_TRUE(mock3.state() == MockSwitch::State::ON);

}