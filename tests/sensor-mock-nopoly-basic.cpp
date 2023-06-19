#include <gtest/gtest.h>
#include <sensor-mock-nopoly.h>

TEST(sensor_mock_nopoly_suite, basic)
{
    MockSensor_nopoly ms(/*initial temperature:*/36.4);
    ASSERT_FLOAT_EQ(ms.get_temperature(), 36.4);
    ms.set_temperature(42.8);
    ASSERT_FLOAT_EQ(ms.get_temperature(), 42.8);
}
