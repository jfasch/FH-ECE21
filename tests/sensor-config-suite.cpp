#include <gtest/gtest.h>
#include <string>
#include <sensor-const.h>
#include <sensor.h>
#include <sensor-config.h>

TEST(sensor_config_suite, config_test)
{
    const std::string sensorName = "ConstantSensor";
    float measurement = 36.4;
    ConstantSensor cs(measurement);
    SensorConfig cfg;
    cfg.addSensor(sensorName, &cs);
    cfg.addSensor(sensorName, &cs);
    cfg.addSensor(sensorName, &cs);

    for (auto [name, sensor]: cfg)
    {
        EXPECT_EQ(sensorName, name);
        ASSERT_FLOAT_EQ(measurement, sensor->get_temperature());
    }

}

