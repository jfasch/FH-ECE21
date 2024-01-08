#pragma once
#include <iostream>



class MQTT 
{
public:    
    virtual ~MQTT() {}

    virtual void publish(std::string msg) = 0;

private:

};