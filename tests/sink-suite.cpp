#include <gtest/gtest.h>
#include <string>
#include <sensor-const.h>
#include <sensor.h>
#include <sensor-config.h>
#include <sink-mock.h>
#include <filesystem>
#include <sink-file.h>

TEST(sink_suite, MockSinkTest)
{
    const std::string sensorName = "ConstantSensor";

    ConstantSensor s1(37.1);
    ConstantSensor s2(37.2);
    SensorConfig cfg;
    SinkMock sink;
    SensorValues values;

    cfg.addSensor("sensor-1", &s1);
    cfg.addSensor("sensor-2", &s2);

    values = cfg.getAllMeasurements();

    sink.output(values);

    ASSERT_EQ(sink.size(), 1);
    ASSERT_EQ(sink[0].size(), 2);
    ASSERT_FLOAT_EQ(sink[0].getMeasurement("sensor-1"), 37.1);
    ASSERT_FLOAT_EQ(sink[0].getMeasurement("sensor-2"), 37.2);
}


TEST(sink_suite, FileSinkTest) 
{
    const std::string testFileName = "sinkFileTest.csv";
    std::vector<std::pair<std::string, std::string>> columnMapping = {
        { "Column1", "Sensor1" },
        { "Column2", "Sensor2" }
    };
    SinkFile sink(testFileName, columnMapping);
    SensorValues values;
    values.addMeasurement("Sensor1", 36.4);
    values.addMeasurement("Sensor2", 36.5);

    sink.output(values);

    ASSERT_TRUE(std::filesystem::exists(testFileName));

    std::ifstream file(testFileName);
    ASSERT_TRUE(file.is_open());

    std::string headerLine;
    std::getline(file, headerLine);
    EXPECT_EQ(headerLine, "Column1;Column2;");

    std::string dataLine;
    std::getline(file, dataLine);
    std::stringstream ss(dataLine);
    std::string value;

    std::getline(ss, value, ';');
    EXPECT_EQ(value, "36.4");

    std::getline(ss, value, ';');
    EXPECT_EQ(value, "36.5");

    file.close();
    std::filesystem::remove(testFileName);
}
