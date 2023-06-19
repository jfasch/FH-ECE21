#include <gtest/gtest.h>

#include <sensor-mock-nopoly.h>
#include <sensor-avg-nopoly.h>


TEST(sensor_avg_nopoly_suite, change_temperatures)
{
    MockSensor_nopoly s1(3);
    MockSensor_nopoly s2(4);

    AveragingSensor_nopoly avg;
    avg.add(&s1);
    avg.add(&s2);

    ASSERT_FLOAT_EQ(avg.get_temperature(), 3.5);

    s1.set_temperature(10);
    s2.set_temperature(20);

    ASSERT_FLOAT_EQ(avg.get_temperature(), 15);
}
