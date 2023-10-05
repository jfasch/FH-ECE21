#include <gtest/gtest.h>
#include <sensor-const.h>
#include <sensor.h>

TEST(sensor_const_suite, basic)
{
    ConstantSensor cs(36.4);

    ASSERT_FLOAT_EQ(cs.get_temperature(), 36.4);       // <--- Sensor interface
    ASSERT_FLOAT_EQ(cs.value(), 36.4);                 // <--- ConstantSensor specific interface
}

TEST(sensor_const_suite, is_a_sensor)
{
    ConstantSensor cs(36.4);

    Sensor* s = &cs;
    ASSERT_FLOAT_EQ(s->get_temperature(), 36.4);
    ASSERT_TRUE(dynamic_cast<ConstantSensor*>(s));
}
