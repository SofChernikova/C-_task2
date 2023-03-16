// task2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Passenger.h"
#include "RouteTaxi.h"
#include "StartMove.h"
#include "Util.h"
#include <set>

void printPassOnStops(map<int, queue<Passenger>>* cursor) {
    map<int, queue<Passenger>> ::iterator iter = cursor->begin();
    while (iter != cursor->end()) {        
        cout <<"This stop " << iter->first << " need ";

        if (!iter->second.empty()) {
            cout << iter->second.size() << " people" << endl;
        }
        else {
            cout << " 0 people" << endl;
        }
        iter++;
    }
}

int main()
{//crate passangers and stops
    setlocale(LC_ALL, "Russian");
    map<int, queue<Passenger>> stopsMap;
    map<int, queue<Passenger>>* cursorMap = &stopsMap;
    Util::fillStops(cursorMap);
    
    for (int j = 0; j <= 3; j++) {
        for (int i = 0; i <= 11; i++) {
            Passenger pass{i+2};
            Passenger* passCur = &pass;
            Util::addPassengerToStop(i+1, cursorMap, passCur);
        }
    }
    
    printPassOnStops(cursorMap);

    RouteTaxi taxi{};
    RouteTaxi* cursorTaxi = &taxi;

    StartMove start{};
    start.start(cursorMap, cursorTaxi);

    delete cursorMap;
    delete cursorTaxi;

}

