#include <string>
#include <vector>
#include <iostream>

int main()
{
    // <int>, and basic functionality
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
    }

    // <std::string>
    {
        std::vector<std::string> my_strings;
        std::string s1 = "abc";
        my_strings.push_back(s1);
        my_strings.push_back("hallo");

        std::cout << "std::string: size = " << my_strings.size() << std::endl;
        for (std::string elem: my_strings)
            std::cout << elem << std::endl;
    }

    // std::move?
    {
        std::vector<std::string> my_strings;
        std::string s = "hallo";
        my_strings.push_back(std::move(s));
        std::cout << "moved from?  --->" << s << "<---" << std::endl;
    }
    
    return 0;
}
