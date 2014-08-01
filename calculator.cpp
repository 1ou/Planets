#include "calculator.h"
#include <math.h>
#include<QDateTime>
#include<QTime>
#include<fstream>
#include<string>

using namespace std;

Calculator::Calculator()
{

}

double Calculator::dayNumber(int year, int month, int day, int hours, int min)
{
    double h = hours + min / 60;
    double D = 367 * year - 7 * (year + (month + 9) / 12 ) / 4;
    D += 275 * (month / 9) + day - 730531.5 + h / 24;
    return D;
}


