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
    float measurement = 36.4;
    SinkMock sink;
    SensorValues values;

    values.addMeasurement("Value1", measurement);
    values.addMeasurement("Value2", measurement);

    sink.output(values);

    //ASSERT_FLOAT_EQ(sink.getTemperature("Value1"), measurement);
    //ASSERT_FLOAT_EQ(sink.getTemperature("Value2"), measurement);

}


TEST(sink_suite, FileSinkTest)
{
    const std::string testFileName = "sinkFileTest";
    SinkFile sink(testFileName);
    SensorValues values;
    values.addMeasurement("Sensor1", 36.4);
    values.addMeasurement("Sensor2", 36.4);

    sink.output(values);

    ASSERT_TRUE(std::filesystem::exists(testFileName));

    std::ifstream file(testFileName);
    std::string line;
    std::getline(file, line);
    EXPECT_EQ(line, "Sensor1; 36.4");
    std::getline(file, line);
    EXPECT_EQ(line, "Sensor2; 36.4");

    file.close();
    std::remove(testFileName.c_str());
}
