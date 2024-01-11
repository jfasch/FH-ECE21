#include "composite-display.h"

void CompositeDisplay::show_percentage(double percentage)
{
    for(std::size_t i = 0; i < _displays.size(); i++)
    {
        _displays[i]->show_percentage(percentage);
    }
}