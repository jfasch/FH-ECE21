#include "fixture-tmpdir.h"

#include <data-logger.h>
#include <string>
#include <sensor-const.h>
#include <sensor-mock.h>
#include <sensor.h>
#include <sensor-config.h>
#include <sink-mock.h>
#include <filesystem>
#include <sink-file.h>

#include <gtest/gtest.h>


struct logger_suite : public tmpdir_fixture {};


TEST_F(logger_suite, LoggerBasicTest)
{
    SensorConfig cfg;
    MockSensor s1(36.4);
    MockSensor s2(36.5);
    MockSensor s3(36.6);
    cfg.addSensor("Sensor1", &s1);
    cfg.addSensor("Sensor2", &s2);
    cfg.addSensor("Sensor3", &s3);

    SinkMock sink;

    DataLogger logger(&cfg, &sink, 5);

    // round #1
    logger.startLogging(1);

    ASSERT_EQ(sink.size(), 1);

    ASSERT_EQ(sink[0].size(), 3);
    ASSERT_FLOAT_EQ(sink[0].getMeasurement("Sensor1"), 36.4);
    ASSERT_FLOAT_EQ(sink[0].getMeasurement("Sensor2"), 36.5);
    ASSERT_FLOAT_EQ(sink[0].getMeasurement("Sensor3"), 36.6);

    // round #2
    s1.set_temperature(37.1);
    s2.set_temperature(37.2);
    s3.set_temperature(37.3);

    logger.startLogging(1);

    ASSERT_EQ(sink.size(), 2);

    ASSERT_EQ(sink[1].size(), 3);
    ASSERT_FLOAT_EQ(sink[1].getMeasurement("Sensor1"), 37.1);
    ASSERT_FLOAT_EQ(sink[1].getMeasurement("Sensor2"), 37.2);
    ASSERT_FLOAT_EQ(sink[1].getMeasurement("Sensor3"), 37.3);
}

TEST_F(logger_suite, LoggerFileTest)
{
    SensorConfig cfg;
    ConstantSensor cs1(36.4);
    ConstantSensor cs2(36.5);
    ConstantSensor cs3(36.6);
    cfg.addSensor("ConstantSensor1", &cs1);
    cfg.addSensor("ConstantSensor2", &cs2);
    cfg.addSensor("ConstantSensor3", &cs3);

    const std::string testFileName = dirname / "loggerFileTest.csv";
    
    // Define column mapping
    std::vector<std::pair<std::string, std::string>> columnMapping = {
        {"ConstantSensor1", "ConstantSensor1"},
        {"ConstantSensor2", "ConstantSensor2"},
        {"ConstantSensor3", "ConstantSensor3"}
    };

    // Create SinkFile object with the filename and column mapping
    SinkFile sink(testFileName, columnMapping);

    DataLogger logger(&cfg, &sink, 5);

    logger.startLogging(1);

    ASSERT_TRUE(std::filesystem::exists(testFileName));

    std::ifstream file(testFileName);
    ASSERT_TRUE(file.is_open());

    std::string line;

    // Read and validate the header line
    std::getline(file, line);
    EXPECT_EQ(line, "ConstantSensor1;ConstantSensor2;ConstantSensor3;");

    // Read and validate the data line
    std::getline(file, line);
    EXPECT_EQ(line, "36.4;36.5;36.6;");

    file.close();
}