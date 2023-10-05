#include <gtest/gtest.h>

#include <sensor-mock.h>
#include <sensor-avg.h>
#include <sensor-const.h>


TEST(sensor_avg_suite, basic)
{
    MockSensor s1(3);
    MockSensor s2(4);

    AveragingSensor avg;                               // <--- uses-many Sensor
    avg.add(&s1);                                      // <--- add one sensor
    avg.add(&s2);                                      // <--- add another sensor

    ASSERT_FLOAT_EQ(avg.get_temperature(), 3.5);       // <--- calculates average of all measurements
}

TEST(sensor_avg_suite, is_a_sensor)
{
    MockSensor s1(3);
    ConstantSensor s2(4);

    AveragingSensor avg;
    avg.add(&s1);  // <-- is-a
    avg.add(&s2);  // <-- is-a

    Sensor* s = &avg; // <-- is-a!!
    ASSERT_FLOAT_EQ(s->get_temperature(), 3.5);
    ASSERT_TRUE(dynamic_cast<AveragingSensor*>(s));
}
