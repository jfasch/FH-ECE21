#include <gtest/gtest.h>
#include <string>
#include <sensor-const.h>
#include <sensor.h>
#include <sensor-config.h>
#include <sink-mock.h>
#include <filesystem>
#include <sink-file.h>

TEST(sink_suite, config_test)
{
    const std::string sensorName = "ConstantSensor";
    float measurement = 36.4;

    ConstantSensor cs(measurement);
    SensorConfig cfg;
    SinkMock sink;

    cfg.addSensor(sensorName, &cs);
    cfg.addSensor(sensorName, &cs);
    cfg.addSensor(sensorName, &cs);

    SensorValues values = cfg.getAllMeasurements();

    sink.output(values);
    for (auto [name, sensor]: cfg)
    {
        ASSERT_FLOAT_EQ(measurement, sink.getTemperature(name));
    }

}


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
