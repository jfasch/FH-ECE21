#include <cmath>
#include <stdio.h>
#include <iostream>

class Point
{
public:
    Point(double x, double y)
    : _x(x), _y(y)
    {}

    Point add(double x, double y) const
    {
        return Point(_x+x, _y+y);
    }

    double x() const { return _x; }
    double y() const { return _y; }

private:
    const double _x;
    const double _y;
};

int main()
{
    Point a(3,4);
    Point new_point = a.add(1,1);

    std::cout << '(' << new_point.x() << ',' << new_point.y() << ')' << std::endl;

    return 0;
}
