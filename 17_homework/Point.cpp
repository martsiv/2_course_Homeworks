#include "Point.h"
std::ostream& operator<< (std::ostream& out, const Point& point)
{
    out << point.x << " " << point.y << " ";
    return out;
}
std::istream& operator>> (std::istream& in, Point& point)
{
    in >> point.x;
    in >> point.y;
    return in;
}
bool operator> (const Point& d1, const Point& d2)
{
    int res1 = (d1.x < d1.y) ? d1.y : d1.x;
    int res2 = (d2.x < d2.y) ? d2.y : d2.x;
    return res1 > res2;
}
bool operator< (const Point& d1, const Point& d2)
{
    int res1 = (d1.x < d1.y) ? d1.y : d1.x;
    int res2 = (d2.x < d2.y) ? d2.y : d2.x;
    return res1 < res2;
}
Point& Point::operator++()
{
    ++x;
    ++y;
    return *this;
}
Point& Point::operator--()
{
    --x;
    --y;
    return *this;
}
Point Point::operator++(int)
{
    ++x;
    ++y;
    return *this;
}
Point Point::operator--(int)
{
    --x;
    --y;
    return *this;
}
void Point::operator! ()
{
    int tmp = x;
    x = y;
    y = tmp;
}