#include <gtest/gtest.h>
#include <data-logger.h>
#include <string>
#include <sensor-const.h>
#include <sensor.h>
#include <sensor-config.h>
#include <sink-mock.h>
#include <filesystem>
#include <sink-file.h>

/*
TEST(sink_suite, config_test)
{
    const std::string sensorName = "ConstantSensor";
    float measurement = 36.4;

    ConstantSensor cs(measurement);


    SensorValues values = cfg.getAllMeasurements();

    sink.output(values);
    for (auto [name, sensor]: cfg)
    {
        ASSERT_FLOAT_EQ(measurement, sink.getTemperature(name));
    }

}
*/

TEST(logger_suite, LoggerFileTest)
{
    const std::string testFileName = "loggerFileTest";
    float measurement = 36.4;
    SinkFile sink(testFileName);
    SensorConfig cfg;
    ConstantSensor cs(measurement);

    cfg.addSensor("ConstantSensor1", &cs);
    cfg.addSensor("ConstantSensor2", &cs);
    cfg.addSensor("ConstantSensor3", &cs);
    DataLogger logger(&cfg, &sink, 5);
    logger.startLogging(1);

    ASSERT_TRUE(std::filesystem::exists(testFileName));

    std::ifstream file(testFileName);
    std::string line;
    std::getline(file, line);
    EXPECT_EQ(line, "ConstantSensor1; 36.4");
    std::getline(file, line);
    EXPECT_EQ(line, "ConstantSensor2; 36.4");
    std::getline(file, line);
    EXPECT_EQ(line, "ConstantSensor3; 36.4");

    file.close();
    std::remove(testFileName.c_str());
    
}
