#include <gtest/gtest.h>

#include <sensor-mock.h>
#include <sensor-avg.h>


TEST(sensor_avg_suite, change_temperatures)
{
    MockSensor s1(3);
    MockSensor s2(4);

    AveragingSensor avg;
    avg.add(&s1);
    avg.add(&s2);

    ASSERT_FLOAT_EQ(avg.get_temperature(), 3.5);

    s1.set_temperature(10);
    s2.set_temperature(20);

    ASSERT_FLOAT_EQ(avg.get_temperature(), 15);
}
