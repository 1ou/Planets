#ifndef MAINWORKER_H
#define MAINWORKER_H
#include <list>
#include <memory>
#include <fstream>
#include <QDateTime>
#include <QDebug>
#include "planet.h"
#include "calculator.h"
#include "coordinate.h"

class MainWorker
{
public:
    MainWorker();

    std::list<coordinate> getPlanetList() const;
    void setPlanetList(const std::list<coordinate> &value);

    void mathPositionPlanet();

    int getViewDistance() const;
    void setViewDistance(int value);

    void mathOrbitPlanet();
private:
    std::list<coordinate> planetList;
    std::shared_ptr<Calculator> m_helper;
    int viewDistance;

};

#endif // MAINWORKER_H
