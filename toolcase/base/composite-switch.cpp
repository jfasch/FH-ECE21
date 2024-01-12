#include "composite-switch.h"
#include <vector>

CompositeSwitch::CompositeSwitch(){
    _switches={};
}
void CompositeSwitch::addSwitch(Switch *newSwitch){
   _switches.push_back(newSwitch);

}

void CompositeSwitch::set_state(bool state){
    for(int i=0; i<(int)_switches.size();i++){
        _switches[i]->set_state(state);
    }
}

int CompositeSwitch::size(){
    return _switches.size();
}
