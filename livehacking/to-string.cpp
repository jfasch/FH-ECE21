#include <string>
#include <unistd.h>

int main()
{
    unsigned int i = 10000000;

    std::string si = std::to_string(i);

    write(STDOUT_FILENO, si.c_str(), si.size());

    return 0;
}
