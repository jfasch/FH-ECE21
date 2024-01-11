#include <sensor-const.h>
#include <sensor-random.h>
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
    ConstantSensor bottom_right(69);
    RandomSensor top_left(35, 45);
    RandomSensor top_right(25, 55);

    SensorConfig config;
    config.addSensor("bl", &bottom_left);
    config.addSensor("br", &bottom_right);
    config.addSensor("tl", &top_left);
    config.addSensor("tr", &top_right);
    
    
    MQTTPublisher client("10.36.40.114", 1883, "fh-ece21");
    SinkMQTT sink(client);
    DataLogger logger(&config, &sink, 1000/*ms*/);
    
    logger.startLogging(0);

    return 0;
}
