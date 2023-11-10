#include <gtest/gtest.h>
#include <string>
#include <sensor-const.h>
#include <sensor.h>
#include <sensor-config.h>
#include <sink-mock.h>

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

