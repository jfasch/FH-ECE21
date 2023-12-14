#include "MQTT_publisher.h"



MQTTPublisher::MQTTPublisher(const std::string host, int port, const std::string topic)
    :_host(host), _port(port), _topic(topic)
{
    _client = mosquitto_new(
        _id,
        false, // clean_session
        nullptr
    );
    if (_client == nullptr) {
        perror("mosquitto_new");
        throw std::runtime_error("Error: Cannot inititalize MQTT!");
    }

    int error = mosquitto_connect(_client, _host.c_str(), _port, /*keepalive*/10);
    if (error != MOSQ_ERR_SUCCESS) {
        assert(error != MOSQ_ERR_INVAL);
        // must be MOSQ_ERR_ERRNO, according to documentation
        perror("mosquitto_connect");
        throw std::runtime_error("Error: Cannot connect to MQTT!");
    }
}

MQTTPublisher::~MQTTPublisher()
{
    mosquitto_destroy(_client);
}

void MQTTPublisher::publish(std::string msg)
{
    int error = mosquitto_publish(_client, nullptr, _topic.c_str(), msg.size(), msg.c_str(), /*qos*/0, /*retain*/false);
    if (error != MOSQ_ERR_SUCCESS) {
        std::cerr << mosquitto_strerror(error) << std::endl;
        throw std::runtime_error("Error: Cannot publish message to MQTT!");
    }
    
}

