#include <iostream>

int main()
{
    int* i = (int*)malloc(4);

    *i = 666;
    std::cout << *i << std::endl;

    free(i);

                                                 // malloc(4)



    //free(i);
    return 0;
}
