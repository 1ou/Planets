#include "mainworker.h"

MainWorker::MainWorker()
{
    m_helper = std::make_shared<Calculator>();
    viewDistance = 7;
}
std::list<coordinate> MainWorker::getPlanetList() const
{
    return planetList;
}

void MainWorker::setPlanetList(const std::list<coordinate> &value)
{
    planetList = value;
}

void MainWorker::mathPositionPlanet()
{
    planetList.clear();

    double pi = 4 * atan(1);
    double radians = pi / 180;
    QDateTime dateTime;
    dateTime.currentDateTime();
    double Julian = m_helper->dayNumber(dateTime.date().year(),
                                        dateTime.date().month(),
                                        dateTime.date().day(),
                                        dateTime.time().hour(),
                                        dateTime.time().minute()) / 36525; //Julian date
    ifstream file("Data.dat");
    while (!file.eof())
    {
        //std::shared_ptr<Planet> LoadPlanet(new Planet());
        std::string Name;
        double One, Two, Three, Four, Five, Six,
                Seven, Eith, Nine, Ten, Eleven, Twelth, Thetin;
        file >> Name >> One >> Two >> Three >> Four >> Five >> Six;
        file >> Seven >> Eith >> Nine >> Ten >> Eleven >> Twelth >> Thetin;

        Planet *LoadPlanet = new Planet();
        LoadPlanet->setName(Name);
        LoadPlanet->setSizeOfPlanet(One);
        LoadPlanet->setSemimajorAxis(Two + Three * Julian);
        LoadPlanet->setEccentricity(Four + Five * Julian);
        LoadPlanet->setInclination((Six + Seven * Julian / 3600) * radians);
        LoadPlanet->setLongitudeOfAscendingNode((Eith + Nine * Julian / 3600) * radians);
        LoadPlanet->setArgumentOfPerihelion((Ten + Eleven * Julian / 3600) *radians);
        LoadPlanet->setMeanLongitude(LoadPlanet->ModTwoPi((Twelth + Thetin * Julian / 3600) * radians));
        LoadPlanet->mainCalculate();

        this->planetList.push_back(*(new coordinate(LoadPlanet->getCoordinate_X(),
                                                  LoadPlanet->getCoordinate_Y(),
                                                  LoadPlanet->getCoordinate_Z(),
                                                  int(LoadPlanet->getSizeOfPlanet()))));
        delete LoadPlanet;
    }
}

int MainWorker::getViewDistance() const
{
    return viewDistance;
}

void MainWorker::setViewDistance(int value)
{
    if(value < 0)
        viewDistance = 0;
    else
        viewDistance = value;
}

void MainWorker::mathOrbitPlanet()
{
    planetList.clear();

    double pi = 4 * atan(1);
    double radians = pi / 180;
    QDateTime dateTime;
    dateTime.currentDateTime();
    for(int i = 0; i < 500; i++)
    {
        double Julian = m_helper->dayNumber(dateTime.date().year() - i,
                                            dateTime.date().month(),
                                            dateTime.date().day() + i,
                                            0,
                                            0) / 36525; //Julian date
        ifstream file("Data.dat");
        while (!file.eof())
        { //std::shared_ptr<Planet> LoadPlanet(new Planet());
            std::string Name;
            double One, Two, Three, Four, Five, Six,
                    Seven, Eith, Nine, Ten, Eleven, Twelth, Thetin;
            file >> Name >> One >> Two >> Three >> Four >> Five >> Six;
            file >> Seven >> Eith >> Nine >> Ten >> Eleven >> Twelth >> Thetin;

            Planet *LoadPlanet = new Planet();
            LoadPlanet->setName(Name);
            LoadPlanet->setSizeOfPlanet(One);
            LoadPlanet->setSemimajorAxis(Two + Three * Julian);
            LoadPlanet->setEccentricity(Four + Five * Julian);
            LoadPlanet->setInclination((Six + Seven * Julian / 3600) * radians);
            LoadPlanet->setLongitudeOfAscendingNode((Eith + Nine * Julian / 3600) * radians);
            LoadPlanet->setArgumentOfPerihelion((Ten + Eleven * Julian / 3600) *radians);
            LoadPlanet->setMeanLongitude(LoadPlanet->ModTwoPi((Twelth + Thetin * Julian / 3600) * radians));
            LoadPlanet->mainCalculate();

            this->planetList.push_back(*(new coordinate(LoadPlanet->getCoordinate_X(),
                                                      LoadPlanet->getCoordinate_Y(),
                                                      LoadPlanet->getCoordinate_Z(),
                                                      LoadPlanet->getSizeOfPlanet())));
            delete LoadPlanet;
        }
    }
}



