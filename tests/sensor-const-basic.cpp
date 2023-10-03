#include <gtest/gtest.h>
#include <sensor-const.h>

TEST(sensor_const_suite, basic)
{
    ConstantSensor cs(36.4);

    ASSERT_FLOAT_EQ(cs.get_temperature(), 36.4);       // <--- Sensor interface
    ASSERT_FLOAT_EQ(cs.value(), 36.4);                 // <--- ConstantSensor specific interface
}
