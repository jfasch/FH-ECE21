#pragma once
#include <switch.h>
#include <vector>

class CompositeSwitch : public Switch
{
public:
CompositeSwitch();
virtual void set_state(bool state);
void addSwitch(Switch* newSwitch);
int size();

private:
std::vector<Switch*> _switches;
} ;