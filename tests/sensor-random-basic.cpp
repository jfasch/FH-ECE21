#include <gtest/gtest.h>
#include <sensor-random.h>

TEST(sensor_random_suite, basic)
{
    RandomSensor rs(36.4, 42.3);                       // <--- give measurements between lo and hi

    double t = rs.get_temperature();
    ASSERT_GE(t, 36.4);                                // <--- greater equal to lo
    ASSERT_LE(t, 42.3);                                // <--- less equal to hi

    ASSERT_FLOAT_EQ(rs.low(), 36.4);                   // <--- RandomSensor specific interface
    ASSERT_FLOAT_EQ(rs.high(), 42.3);                  // <--- RandomSensor specific interface
}
