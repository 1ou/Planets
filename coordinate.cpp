#include "coordinate.h"

coordinate::coordinate()
{
}

coordinate::coordinate(const double value1, const double value2,
                       const double value3, const int value4)
{
    x = value1;
    y = value2;
    z = value3;
    size = value4;
}

int coordinate::getSize() const
{
    return size;
}

void coordinate::setSize(int value)
{
    size = value;
}
double coordinate::getX() const
{
    return x;
}

void coordinate::setX(double value)
{
    x = value;
}
double coordinate::getY() const
{
    return y;
}

void coordinate::setY(double value)
{
    y = value;
}
double coordinate::getZ() const
{
    return z;
}

void coordinate::setZ(double value)
{
    z = value;
}







