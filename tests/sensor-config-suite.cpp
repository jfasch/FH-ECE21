#include <gtest/gtest.h>
#include <fstream>
#include <string>
#include <sensor-values.h>
#include <sensor-const.h>
#include <sensor.h>
#include <sensor-config.h>



TEST(sensor_config_suite, Sensorconfig_Test)
{
    float measurement = 36.4;
    ConstantSensor cs(measurement);
    SensorConfig cfg;
    ASSERT_TRUE(cfg.addSensor("Sensor1", &cs));
    ASSERT_TRUE(cfg.addSensor("Sensor2", &cs));
    ASSERT_TRUE(cfg.addSensor("Sensor3", &cs));
    ASSERT_FALSE(cfg.addSensor("Sensor3", &cs));
    SensorValues values = cfg.getAllMeasurements();

    ASSERT_FLOAT_EQ(values.getMeasurement("Sensor1"), measurement);
    ASSERT_FLOAT_EQ(values.getMeasurement("Sensor2"), measurement);
    ASSERT_FLOAT_EQ(values.getMeasurement("Sensor3"), measurement);

}

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

