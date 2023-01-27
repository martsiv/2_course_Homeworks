#pragma once
#include <iostream>
#include "List.h"
using namespace std;
class Point
{
    int x;
    int y;
public:
    Point(int x, int y) : x(x), y(y) {}
    void Print() const
    {
        cout << x << ' ' << y;
    }
    friend std::ostream& operator<< (std::ostream& out, const Point& point);
    friend std::istream& operator>> (std::istream& in, Point& point);
    friend bool operator> (const Point& d1, const Point& d2);
    friend bool operator< (const Point& d1, const Point& d2);
    Point& operator++(); // версія префікс
    Point& operator--(); // версія префікс

    Point operator++(int); // версія постфікс
    Point operator--(int); // версія постфікс
    void operator! ();
};
