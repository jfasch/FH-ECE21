#include <map>
#include <iostream>
#include <string>

int main()
{
    std::map<int, std::string> my_whatever;

    my_whatever[1] = "one";
    my_whatever[2] = "two";

    std::cout << my_whatever[1] << std::endl;

    for (auto [key, value]: my_whatever)
        std::cout << "Key: " << key << ", Value: " << value << std::endl;

    return 0;
}
