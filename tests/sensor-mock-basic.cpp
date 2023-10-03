#include <gtest/gtest.h>
#include <sensor-mock.h>

TEST(sensor_mock_suite, basic)
{
    MockSensor ms(/*initial temperature:*/36.4);
    ASSERT_FLOAT_EQ(ms.get_temperature(), 36.4);
    ms.set_temperature(42.8);
    ASSERT_FLOAT_EQ(ms.get_temperature(), 42.8);
}
