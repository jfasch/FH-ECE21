#include <gtest/gtest.h>
#include <data-logger.h>
#include <string>
#include <sensor-const.h>
#include <sensor.h>
#include <sensor-config.h>
#include <sink-mock.h>
#include <filesystem>
#include <sink-file.h>



TEST(logger_suite, LoggerMock)
{
    const std::string testFileName = "loggerFileTest";
    float measurement = 36.4;
    SinkMock sink;
    SensorConfig cfg;
    ConstantSensor cs(measurement);

    cfg.addSensor("ConstantSensor1", &cs);
    cfg.addSensor("ConstantSensor2", &cs);
    cfg.addSensor("ConstantSensor3", &cs);
    DataLogger logger(&cfg, &sink, 5);
    logger.startLogging(1);

    ASSERT_FLOAT_EQ(measurement, sink.getTemperature("ConstantSensor1"));
    ASSERT_FLOAT_EQ(measurement, sink.getTemperature("ConstantSensor2"));
    ASSERT_FLOAT_EQ(measurement, sink.getTemperature("ConstantSensor3"));
    
}
