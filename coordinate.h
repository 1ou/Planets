#ifndef COORDINATE_H
#define COORDINATE_H

class coordinate
{
public:
    coordinate();
    coordinate(const double value1, const double value2, const double value3, const int value4);


    int getSize() const;
    void setSize(int value);

    double getX() const;
    void setX(double value);

    double getY() const;
    void setY(double value);

    double getZ() const;
    void setZ(double value);

private:
    double x;
    double y;
    double z;
    int size;
};

#endif // COORDINATE_H
