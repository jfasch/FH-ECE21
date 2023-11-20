#include "switch-mock.h"
#include <switch.h>


MockSwitch::MockSwitch(State initial_state)//
: _state(initial_state)
{}
    
void MockSwitch::set_state(bool state)
{
    if (state == true) //
    {
       _state = MockSwitch::State::ON;  
    }

    if (state == false) //
    {
       _state = MockSwitch::State::OFF;  
    }

}

