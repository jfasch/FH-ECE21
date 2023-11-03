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

    // void set_state(bool) would be better

private:
    State _state;
};
