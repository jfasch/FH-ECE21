#include <gtest/gtest.h>

#include <sensor-mock.h>
#include <sensor-avg.h>


TEST(sensor_avg_suite, basic)
{
    MockSensor s1(3);
    MockSensor s2(4);

    AveragingSensor avg;                               // <--- uses-many Sensor
    avg.add(&s1);                                      // <--- add one sensor
    avg.add(&s2);                                      // <--- add another sensor

    ASSERT_FLOAT_EQ(avg.get_temperature(), 3.5);       // <--- calculates average of all measurements
}
