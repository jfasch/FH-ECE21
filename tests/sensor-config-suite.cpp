#include <gtest/gtest.h>
#include <fstream>
#include <string>
#include <filesystem>
#include <sink-file.h>
#include <sensor-values.h>
#include <sensor-const.h>
#include <sensor.h>
#include <sensor-config.h>
/*
TEST(sensor_config_suite, basic_config_test)

namespace fs = std::filesystem;

class SinkFileTest:public::testing::Test 
{
    protected:
        std::string testFileName = "test_log.txt";

        void SetUp() override // Remove the test file if it exists before each test
        {
            fs::remove(testFileName)
        }

        void TearDown() override // Clean up: Remove the test file after each test
        {
            fs::remove(testFileName);
        }
};


TEST_F(SinkFileTest, FileCreationAndContentTest)
{
    SinkFile sink(testFileName);
    SensorValues values;
    values.addMeasurement("ConstantSensor");
    values.addMeasurement("Temperature", 36.4);

    sink.output(values);

    ASSERT_TRUE(fs::exists(SinkFileTest))

    std::ifstream file(testFileName);
    std::string line;
    std::getline(file, line);
    EXPECT_EQ(line, "ConstantSensor");
    std::getline(file, line);
    EXPECT_EQ(line, "Temperature; 36.4");

    file.close();
    
}
*/

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

