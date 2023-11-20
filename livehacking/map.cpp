#include <map>
#include <iostream>

using namespace std;

int main()
{
    map<int, std::string> some_map;

    some_map[1] = "one";             
    some_map[2] = "two";             

    cout << "map after initialization" << endl;

    if (some_map.size() > 0)
        for (auto [key, value]: some_map)
            cout << key << ':' << value << endl;
    else
        cout << "too bad" << endl;

    cout << some_map[1] << endl;
    cout << "and 3? " << some_map[3] << endl;

    // cout << "map after bad seacrh" << endl;
    
    if (some_map.size() > 0)
        for (auto [key, value]: some_map)
            cout << key << ':' << value << endl;
    else
        cout << "too bad" << endl;

    //cout << some_map.at(4) << endl;

    // C++17 "structured binding"
    auto [elem_p, inserted] = some_map.insert(pair(5, "five"));
    if (! inserted)
        cout << "fuck" << endl;
    else {
        cout << elem_p->first << ':' << elem_p->second << endl;

        if (some_map.size() > 0)
            for (auto [key, value]: some_map)
                cout << key << ':' << value << endl;
        else
            cout << "too bad" << endl;
    }

    return 0;
}
