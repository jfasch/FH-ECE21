#include <mosquitto.h>
#include <cstdio>
#include <iostream>
#include <cassert>
#include <MQTT_publisher.h>



static const char id[] = "my_client";


int main(int argc, char** argv)
{
    // <parameters>
    if (argc != 5) {
        std::cerr << "Usage: " << argv[0] << " <host> <port> <topic> <msg>\n";
        return 1;
    }
    std::string host = argv[1];
    int port = std::stoi(argv[2]);
    std::string topic = argv[3];
    std::string msg = argv[4];
    // </parameters>

    // <connection establishment>
    mosquitto* client = mosquitto_new(
        id,
        false, // clean_session
        nullptr
    );
    if (client == nullptr) {
        perror("mosquitto_new");
        return 1;
    }

    int error = mosquitto_connect(client, host.c_str(), port, /*keepalive*/10);
    if (error != MOSQ_ERR_SUCCESS) {
        assert(error != MOSQ_ERR_INVAL);
        // must be MOSQ_ERR_ERRNO, according to documentation
        perror("mosquitto_connect");
        return 1;
    }
    // </connection establishment>

    // <message>
    error = mosquitto_publish(client, nullptr, topic.c_str(), msg.size(), msg.c_str(), /*qos*/0, /*retain*/false);
    if (error != MOSQ_ERR_SUCCESS) {
        std::cerr << mosquitto_strerror(error) << '\n';
        return 1;
    }
    // </message>

    // <cleanup>
    mosquitto_destroy(client);
    // </cleanup>

   

    return 0;
}
