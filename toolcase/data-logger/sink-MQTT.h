#pragma once
#include <iostream>
#include <sink-logger.h>
#include <string>
#include <stdexcept>  
#include <assert.h>
#include <MQTT.h>

/**
 * @class SinkMQTT
 * @brief publishes data given via a Sensorvalues Object as JSON to a MQTT server
 * 
 * @param host: host address to which data should be written
 * @param port: port to use. std:1883
 * @param topic: MQTT topic to which the data will be written
**/
class SinkMQTT : public SinkLogger
{
public:
    SinkMQTT(MQTT& client)
        :_client(&client){}

    ~SinkMQTT(){}


    void output(const SensorValues& data) override
    {
        std::string msg;
        // create json like string
        msg = "{";
        for (const auto& [name, value] : data)
        {
            msg += " \"";
            msg += name;
            msg += "\" : ";
            msg += std::to_string(value);
            msg += ",";
        }
        msg.pop_back();
        msg += " }";

        _client->publish(msg);
    }

private:
    MQTT* _client;
    std::string _host;
    int _port;
    std::string _topic;    

    const char* _id = "logger_client";
};