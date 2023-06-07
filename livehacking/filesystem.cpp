#include <filesystem>
#include <iostream>

using namespace std;

int main()
{
    filesystem::current_path("/");
    cout << filesystem::current_path() << endl;
    
    return 0;
}
