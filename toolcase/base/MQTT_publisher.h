#pragma once
#include "MQTT.h"
#include <mosquitto.h>
#include <iostream>
#include <stdexcept>  
#include <assert.h>

/**
 * @class MQTTPublisher
 * @brief publishes a string a MQTT server
 * 
 * @param host: host address to which data should be written
 * @param port: port to use. std:1883
 * @param topic: MQTT topic to which the data will be written
**/
class MQTTPublisher : public MQTT
{
public:
    MQTTPublisher(const std::string host="localhost", int port=1883, const std::string topic="fh-ece21");

    ~MQTTPublisher();

    void publish(std::string msg) override;

private:
    std::string _host;
    int _port;
    std::string _topic;    
    mosquitto* _client;
    const char* _id = "logger_client";
};