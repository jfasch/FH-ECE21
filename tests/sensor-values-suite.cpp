#include <gtest/gtest.h>
#include <fstream>
#include <string>
#include <sensor-values.h>



TEST(sensor_config_suite, SensorValues_Test)
{
    float measurement = 36.4;

    SensorValues values;
    ASSERT_TRUE(values.addMeasurement("value1", measurement	));
    ASSERT_TRUE(values.addMeasurement("value2", measurement	));
    ASSERT_FALSE(values.addMeasurement("value1", measurement));

    ASSERT_FLOAT_EQ(values.getMeasurement("value1"), measurement);
    ASSERT_FLOAT_EQ(values.getMeasurement("value1"), measurement);


}

