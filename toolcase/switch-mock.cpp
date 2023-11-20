#include "switch-mock.h"
#include <iostream>

using namespace std;

MockSwitch::MockSwitch(State initial_state)
: _state(initial_state)
{}
    
void MockSwitch::on()
{
    _state = State::ON;
}

void MockSwitch::off()
{
    _state = State::OFF;
}
