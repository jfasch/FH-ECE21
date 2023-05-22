#include <iostream>
#include <string.h> // <--- good old C strings
#include <string>   // <--- shiny new C++ string
#include <stdexcept>


int main()
{
    // good old C
    {
        char s1[4];
        s1[0] = 'f';
        s1[1] = 'o';
        s1[2] = 'o';
        s1[3] = 0;

        char s2[] = "bar"; // <--- C string initialization

        char s3[7];
        s3[0] = '\0';
        strcat(s3, s1);
        strcat(s3, s2);

        std::cout << s3 << std::endl;
    }

    // C++: std::string
    {
        std::string s1 = "foo";
        std::string s2 = "bar";

        std::string s3;

        s3 += s1;
        s3 += s2;

        std::cout << s3 << std::endl;
    }

    // operator+()
    {
        std::string s1 = "foo";
        std::string s2 = "bar";

        std::string s3 = s1 + s2;

        std::cout << s3 << std::endl;
    }

    // conversion from string
    {
        std::string numstr = "42";
        int answer = std::stoi(numstr);
        std::cout << answer << std::endl;

        try {
            std::string no_numstr = "blah";
            int no_answer = std::stoi(no_numstr);
            std::cout << no_answer << std::endl;
        }
        catch (const std::invalid_argument&) {}
    }

    // conversion to string
    {
        int i = 42;
        std::string numstr = std::to_string(i);
        std::cout << numstr << std::endl;

        float f = 42.666;
        numstr = std::to_string(f);
        std::cout << numstr << std::endl;
    }

    // searching
    {
        std::string s = "Mississippi";
        size_t pos = s.find("ss");
        std::cout << pos << std::endl;

        pos = s.find("ss", 3);
        std::cout << pos << std::endl;
    }

    // substrings
    {
        std::string s = "Mississippi";
        std::string substr = s.substr(2,/*length*/5);
        std::cout << substr << std::endl;
    }

    return 0;
}
