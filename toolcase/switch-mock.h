#pragma once


class MockSwitch
{
public:
    enum State
    {
        ON,
        OFF
    };

    MockSwitch(State initial_state);
    
    State state() const { return _state; }
    void on();
    void off();

private:
    State _state;
};
