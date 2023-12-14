#include <sensor-values.h>

#include <gtest/gtest.h>

TEST(sensor_values_suite, basic)
{
    SensorValues values;
    values.addMeasurement("sensor-a", 37.5);
    values.addMeasurement("sensor-b", 42.3);

    ASSERT_EQ(values.size(), 2);
    ASSERT_FLOAT_EQ(values.getMeasurement("sensor-a"), 37.5);
    ASSERT_FLOAT_EQ(values.getMeasurement("sensor-b"), 42.3);
}

TEST(sensor_values_suite, error)
{
    SensorValues values;

    ASSERT_THROW(values.getMeasurement("not-exist"), std::out_of_range);
}
