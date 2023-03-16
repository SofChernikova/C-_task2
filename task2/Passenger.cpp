#include "Passenger.h"
#include <string>
using namespace std;

int Passenger::getStop()
{
    return Passenger::stop;
}

Passenger::Passenger(int stop)
{
    Passenger::stop = stop;
}

