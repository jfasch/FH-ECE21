#include <gtest/gtest.h>
#include <fstream>
#include <string>
#include <filesystem>
#include <sink-file.h>
#include <sensor-values.h>
#include <sensor-const.h>
#include <sensor.h>
#include <sensor-config.h>

namespace fs = std::filesystem;


TEST(SinkFileTest, FileCreationAndContentTest)
{
    std::string testFileName = "sinkFileTest";
    SinkFile sink(testFileName);
    SensorValues values;
    values.addMeasurement("ConstantSensor", 36.4);
    values.addMeasurement("Temperature", 36.4);

    sink.output(values);

    ASSERT_TRUE(std::filesystem::exists(testFileName));

    std::ifstream file(testFileName);
    std::string line;
    std::getline(file, line);
    EXPECT_EQ(line, "ConstantSensor; 36.4");
    std::getline(file, line);
    EXPECT_EQ(line, "Temperature; 36.4");

    file.close();
    
}


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

TEST(sensor_config_suite, config_test_allMeasurements)
{
    const std::string sensorName = "ConstantSensor";
    float measurement = 36.4;
    ConstantSensor cs(measurement);
    SensorConfig cfg;
    cfg.addSensor(sensorName, &cs);
    cfg.addSensor(sensorName, &cs);
    cfg.addSensor(sensorName, &cs);
    SensorValues values = cfg.getAllMeasurements();
    for (auto [name, value]: values)
    {
        EXPECT_EQ(sensorName, name);
        ASSERT_FLOAT_EQ(measurement, value);
    }

}

