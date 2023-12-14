#pragma once

#include "boiling-pot.h"

#include <vector>


class MockReporter : public BoilingPot::Reporter
{
public:
    struct Item
    {
        bool switch_state;
        double current_temperature;
    };

    void report(bool switch_state, double current_temperature) override
    {
        _items.push_back({switch_state, current_temperature});
    }

    auto size() const { return _items.size(); }
    auto operator[](size_t i) const { return _items[i]; }

    
private:    
    std::vector<Item> _items;
};
