#include <vector>
#include <iostream>

int main()
{
    std::vector<int> meine_ints = { 1,2,3,4 };

    // index based iteration
    for (size_t i=0; i<meine_ints.size(); i++)
        std::cout << meine_ints[i] << std::endl;

    meine_ints.push_back(5);

    for (size_t i=0; i<meine_ints.size(); i++)
        std::cout << meine_ints[i] << std::endl;

    // pointer based iteration
    std::vector<int>::iterator begin = meine_ints.begin();
    std::vector<int>::iterator end = meine_ints.end();

    while (begin != end) {
        std::cout << *begin << std::endl;
        ++begin;
    }

    // range-based-for
    for (int elem: meine_ints)
        std::cout << elem << std::endl;
    
    return 0;
}
