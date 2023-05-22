#include <iostream>
using namespace std;

class point
{
public:
    point()
    {
        this->_x = 0;
        this->_y = 0;
    }

    point(int x, int y)
    {
        this->_x = x;
        this->_y = y;
    }

    int x()
    {
        return this->_x;
    }

    int y()
    {
        return this->_y;
    }

    void move(point vec)
    {
        this->_x += vec._x;
        this->_y += vec._y;
    }

    // void point_move(point* p, point vec)
    // {
    //     p->x += vec.x;
    //     p->y += vec.y;
    // }

    // p1.move(v);

    static point add(point p, point vec)
    {
        int x = p._x + vec._x;
        int y = p._y + vec._y;
        return point(x, y);
    }

private:
    int _x;
    int _y;
};

void point_print(point p)
{
    cout << '(' << p.x() << ',' << p.y() << ')' << endl;
}

int main()
{
    {
        point p1 = {1,2};  // <--- struct initialization

        point vec = {3,4};
        p1.move(vec);

        point_print(p1);

        point moved = point::add(p1, vec);
        point_print(moved);
    }

    {
        point p1;   // <--- default ctor
        point_print(p1);

        point p2 = {42, 666};   // <--- ctor point(int x, int y)
        point_print(p2);
    }

    return 0;
}
