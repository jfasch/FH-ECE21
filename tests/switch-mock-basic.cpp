#include <gtest/gtest.h>

#include <switch-mock.h>


TEST(switch_mock_suite, initial_state)
{
    {
        MockSwitch sw(MockSwitch::State::OFF);
        ASSERT_TRUE(sw.state() == MockSwitch::State::OFF);
    }
    {
        MockSwitch sw(MockSwitch::State::ON);
        ASSERT_TRUE(sw.state() == MockSwitch::State::ON);
    }
}

TEST(switch_mock_suite, set_on_off)
{
    MockSwitch sw(MockSwitch::State::OFF);
    ASSERT_TRUE(sw.state() == MockSwitch::State::OFF);
    sw.on();
    ASSERT_TRUE(sw.state() == MockSwitch::State::ON);
    sw.off();
    ASSERT_TRUE(sw.state() == MockSwitch::State::OFF);
}
