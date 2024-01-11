#include <sensor-const.h>
#include <sensor-w1.h>
#include <sink-terminal.h>
#include <data-logger.h>
#include <MQTT_publisher.h>
#include <sink-MQTT.h>

#include <map>
#include <iostream>
#include <unistd.h>


int main()
{
    ConstantSensor bottom_left(37.5);
    ConstantSensor bottom_right(-273.15);
    W1Sensor potSensor(".");

    SensorConfig config;
    config.addSensor("BoilingPort", &potSensor);
    
    MQTTPublisher client("10.36.40.114", 1883, "fh-ece21");
    SinkMQTT sink(client);

    //SinkTerminal sink;
    DataLogger logger(&config, &sink, 1000/*ms*/);
    logger.startLogging(0);

    return 0;
}
