#include <iostream>

struct point
{
    int x;
    int y;
};

void point_print(struct point p)
{
    std::cout << '(' << p.x << ',' << p.y << ')' << std::endl;
}

int main()
{
    // arrays of arbitrary types
    {
        point my_points[3];

        my_points[0] = {1, 2};
        my_points[1] = {3, 4};
        my_points[2] = {5, 6};
        my_points[3] = {666,666};

        for (int i=0; i<4; i++) {
            std::cout << "i: " << i << std::endl;
            point_print(my_points[i]);
        }

        point_print(my_points[-1]);
    }

    // arrays of char
    {
        char my_chars[4];
        my_chars[0] = 'a';
        my_chars[1] = 'b';
        my_chars[2] = 'c';
        my_chars[3] = '\0';
        // my_chars[3] = 0;

        printf("%s\n", my_chars);
    }

    return 0;
}
