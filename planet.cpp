#include "planet.h"
#include<QDateTime>
#include<QTime>
#include<string>
#include<math.h>

#include<string>
using namespace std;


double Planet::getSemimajorAxis() const
{
    return semimajorAxis;
}

void Planet::setSemimajorAxis(double value)
{
    semimajorAxis = value;
}

double Planet::getEccentricity() const
{
    return eccentricity;
}

void Planet::setEccentricity(double value)
{
    eccentricity = value;
}

double Planet::getInclination() const
{
    return inclination;
}

void Planet::setInclination(double value)
{
    inclination = value;
}

double Planet::getLongitudeOfAscendingNode() const
{
    return longitudeOfAscendingNode;
}

void Planet::setLongitudeOfAscendingNode(double value)
{
    longitudeOfAscendingNode = value;
}

double Planet::getArgumentOfPerihelion() const
{
    return argumentOfPerihelion;
}

void Planet::setArgumentOfPerihelion(double value)
{
    argumentOfPerihelion = value;
}

double Planet::getMeanLongitude() const
{
    return meanLongitude;
}

void Planet::setMeanLongitude(double value)
{
    meanLongitude = value;
}


double Planet::getSizeOfPlanet() const
{
    return sizeOfPlanet;
}

void Planet::setSizeOfPlanet(double value)
{
    sizeOfPlanet = value;
}

double Planet::getCoordinate_X() const
{
    return coordinate_X;
}

void Planet::setCoordinate_X(double value)
{
    coordinate_X = value;
}

double Planet::getCoordinate_Y() const
{
    return coordinate_Y;
}

void Planet::setCoordinate_Y(double value)
{
    coordinate_Y = value;
}

double Planet::getCoordinate_Z() const
{
    return coordinate_Z;
}

void Planet::setCoordinate_Z(double value)
{
    coordinate_Z = value;
}
Planet::Planet()
{
    m_Pi = 4 * atan(1);
    m_Degrees =  180 / m_Pi;
    m_Radians = m_Pi / 180;
    m_Error = 0.000001;
}

Planet::Planet(const string value1, const double value2, const double value3,
               const double value4, const double value5, const double value6, const double value7, const double value8)
{
    this->name = value1;
    this->sizeOfPlanet = value2;
    this->semimajorAxis = value3;
    this->eccentricity = value4;
    this->inclination = value5;
    this->longitudeOfAscendingNode = value6;
    this->argumentOfPerihelion = value7;
    this->meanLongitude = value8;
}

Planet::~Planet()
{
    name.clear();
}

void Planet::mainCalculate()
{
    //position of Earth in its orbit
    m_MeanAnomaly = ModTwoPi(meanLongitude - eccentricity);

    trueAnomaly();

    m_HeliocentricRadius = semimajorAxis*(1 - pow(eccentricity, 2))
            / (1 + eccentricity * cos(m_TrueAnomaly));

    //heliocentric rectangular coordinates of planet
    double xh = m_HeliocentricRadius * (cos(longitudeOfAscendingNode)
                         * cos(m_TrueAnomaly + argumentOfPerihelion - longitudeOfAscendingNode)
                         - sin(longitudeOfAscendingNode)
                         * sin(m_TrueAnomaly + argumentOfPerihelion - longitudeOfAscendingNode)
                         * cos(inclination));

    double yh = m_HeliocentricRadius * (sin(longitudeOfAscendingNode)
                         * cos(m_TrueAnomaly + argumentOfPerihelion - longitudeOfAscendingNode)
                         + cos(longitudeOfAscendingNode)
                         * sin(m_TrueAnomaly + argumentOfPerihelion - longitudeOfAscendingNode)
                         * cos(inclination));

    double zh = m_HeliocentricRadius * (sin(m_TrueAnomaly + argumentOfPerihelion - longitudeOfAscendingNode)
                         * sin(inclination));

    double ecl = 23.439281 * m_Radians;
    coordinate_X = xh;
    coordinate_Y = yh*cos(ecl) - zh*sin(ecl);
    coordinate_Z = yh*sin(ecl) + zh*cos(ecl);

    m_Declination = std::atan(zh / (sqrt(pow(xh,2)) + pow(yh,2)));
    //m_Distance = sqrt(pow(coordinate_X ,2)+ pow(coordinate_Y ,2)
    //                 + pow(coordinate_Z ,2));
}

void Planet::trueAnomaly()
{
    double E, E1;
    E = m_MeanAnomaly + eccentricity*sin(m_MeanAnomaly)*(1.0 + eccentricity*cos(m_MeanAnomaly));
    do
    {
        E1 = E;
        E = E1 - (E1 - eccentricity * sin(E1) - m_MeanAnomaly)
                / (1 - eccentricity*cos(E1));
    }
    while(fabs( E - E1 ) > m_Error);

    m_TrueAnomaly = 2 * atan(sqrt((1 + eccentricity) / (1 - eccentricity))
                             * tan(0.5 * E));
    if (m_TrueAnomaly < 0)
        m_TrueAnomaly += 2 * m_Pi;
}

int Planet::AbsFloor(double x)
{
    if (x >= 0.0)
        return floor(x);
    else
        return ceil(x);
}

double Planet::ModTwoPi(double x)
{
    double b = x / (2 * m_Pi);
    double a = (2 * m_Pi) * (b - AbsFloor(b));
    if (a < 0)
        a += (2 * m_Pi);
    return a;
}

double Planet::Abs(double x)
{
    if (x < 0)
        return -x;
    return x;
}

int Planet::sgn(double x)
{
    if (x < 0) return -1; return 1;
}

void Planet::setName(string name)
{
    this->name = name;
}


