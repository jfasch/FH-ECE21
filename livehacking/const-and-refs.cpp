#include <cmath>
#include <stdio.h>
#include <iostream>

class Point
{
public:
    Point(double x, double y)
    {
        _x = x;
        _y = y;
    }

    double x() const
    {
        return _x;
    }

    double y() const
    {
        return _y;
    }

    void move(double x, double y)
    {
        _x += x;
        _y += y;
    }

    double abs() const
    {
        return std::sqrt(_x*_x+_y*_y);
    }

private:
    double _x;
    double _y;
};

void print(const Point& p)
{
    std::cout << '(' << p.x() << ',' << p.y() << ')' << std::endl;
}

int main()
{
    const Point a(3,4);
    print(a);

    return 0;
}
