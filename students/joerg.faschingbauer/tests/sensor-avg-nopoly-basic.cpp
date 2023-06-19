#include <gtest/gtest.h>

#include <sensor-mock-nopoly.h>
#include <sensor-avg-nopoly.h>


TEST(sensor_avg_nopoly_suite, basic)
{
    MockSensor_nopoly s1(3);
    MockSensor_nopoly s2(4);

    AveragingSensor_nopoly avg;                        // <--- uses-many Sensor
    avg.add(&s1);                                      // <--- add one sensor
    avg.add(&s2);                                      // <--- add another sensor

    ASSERT_FLOAT_EQ(avg.get_temperature(), 3.5);       // <--- calculates average of all measurements
}
