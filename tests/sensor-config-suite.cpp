#include <gtest/gtest.h>
#include <fstream>
#include <string>
#include <sensor-values.h>
#include <sensor-const.h>
#include <sensor.h>
#include <sensor-config.h>



TEST(sensor_config_suite, get_measurements)
{
    SensorConfig cfg;
    ConstantSensor s1(37.1);
    ConstantSensor s2(37.2);
    ConstantSensor s3(37.3);
    cfg.addSensor("sensor-1", &s1);
    cfg.addSensor("sensor-2", &s2);
    cfg.addSensor("sensor-3", &s3);

    SensorValues values = cfg.getAllMeasurements();

    ASSERT_EQ(values.size(), 3);
    ASSERT_FLOAT_EQ(values.getMeasurement("sensor-1"), 37.1);
    ASSERT_FLOAT_EQ(values.getMeasurement("sensor-2"), 37.2);
    ASSERT_FLOAT_EQ(values.getMeasurement("sensor-3"), 37.3);
}

TEST(sensor_config_suite, duplicate_sensor)
{
    SensorConfig cfg;

    ConstantSensor s1(37.1);
    ConstantSensor s2(37.2);
    cfg.addSensor("sensor-1", &s1);

    ASSERT_THROW(cfg.addSensor("sensor-1", &s2), std::runtime_error);
}

