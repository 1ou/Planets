#ifndef PLANET_H
#define PLANET_H

#include<string>
using namespace std;

class Planet
{
private:
    //name of planet
    string name;

    double coordinate_X;
    double coordinate_Y;
    double coordinate_Z;

    //mean distance (AU), the value of the semi-major axis of the orbit
    //(AU - Astronomical Unit - average Sun to Earth distance)
    double semimajorAxis;

    //eccentricity of the ellipse which describes the orbit (dimensionless)
    double eccentricity;

    //inclination (degrees), angle between the plane of the ecliptic
    //(the plane of Earth's orbit about the Sun) and the plane of the planets orbit
    double inclination;

    //longitude of ascending node (degrees), the position in the orbit where the elliptical
    //path of the planet passes through the plane of the ecliptic, from below the plane to above the plane
    double longitudeOfAscendingNode;

    //longitude of perihelion (degrees), the position in the orbit where the planet is closest to the Sun
    double argumentOfPerihelion;

    //mean longitude (degrees), the position of the planet in the orbit
    double meanLongitude;

    double m_MeanAnomaly; //mean anomaly (degrees)
    double m_TrueAnomaly; //true anomaly (degrees)
    double m_HeliocentricRadius; //heliocentric radius (AU)
    double m_RightAscension; //right ascension (hour angle)
    double m_Declination; //declination (degrees)

    double m_Pi;
    double m_Degrees;
    double m_Radians;
    double m_Error;
    double sizeOfPlanet;
public:
    Planet();
    Planet(const string value1,
           const double value2,
           const double value3,
           const double value4,
           const double value5,
           const double value6,
           const double value7,
           const double value8);
    ~Planet();
    int AbsFloor(double );
    double ModTwoPi(double);
    double Abs(double);
    int sgn(double x);
    void mainCalculate();
    void trueAnomaly();
    void setName(string);
    double getSemimajorAxis() const;
    void setSemimajorAxis(double value);
    double getEccentricity() const;
    void setEccentricity(double value);
    double getInclination() const;
    void setInclination(double value);
    double getLongitudeOfAscendingNode() const;
    void setLongitudeOfAscendingNode(double value);
    double getArgumentOfPerihelion() const;
    void setArgumentOfPerihelion(double value);
    double getMeanLongitude() const;
    void setMeanLongitude(double value);
    double getSizeOfPlanet() const;
    void setSizeOfPlanet(double value);
    double getCoordinate_X() const;
    void setCoordinate_X(double value);
    double getCoordinate_Y() const;
    void setCoordinate_Y(double value);
    double getCoordinate_Z() const;
    void setCoordinate_Z(double value);
};

#endif // PLANET_H
