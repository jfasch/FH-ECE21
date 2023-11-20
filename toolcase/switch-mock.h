#pragma once
#include <switch.h>

class MockSwitch : public Switch
{
public:
    enum class State
    {
        ON,
        OFF
    };

    MockSwitch(State initial_state);
    
    State state() const { return _state; }
  
    virtual void set_state(bool state);
    
private:
    State _state;
};
