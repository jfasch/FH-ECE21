#pragma once
#include "MQTT.h"
#include <vector>
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
class MQTTMock : public MQTT
{
public:
    MQTTMock() {}

    ~MQTTMock() {}

    void publish(std::string msg) override
    {
        _buffer.push_back(msg);
    }

    std::string getBuffer()
    {
        std::string msg = _buffer[0];
        _buffer.erase(_buffer.begin());
        return msg;
    }

private:
std::vector<std::string> _buffer;
};