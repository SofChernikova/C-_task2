#include "StartMove.h"
#include "Util.h"
#include "Passenger.h"
#include <iostream>
using namespace std;

void StartMove::start(map<int, queue<Passenger>>* cursorMap, RouteTaxi* cursorTaxi)
{
	while (true) {
		for (int i : cursorTaxi->getStops()) {
			cout << "Do you want to see a menu? Print 1 - yes," 
			"smth else - no"<< endl;
			int choose;
			cin >> choose;
			if (choose == 1) {
				Util::makeAnAction(cursorMap);
			}
		
			cursorTaxi->dropOff(i);

			try {
				queue<Passenger> currQueue = cursorMap->at(i);
				while (!currQueue.empty()) {
					Passenger pass = currQueue.front();
					currQueue.pop();
					cursorTaxi->addPassengers(i, pass);
				}			
			}
			catch (out_of_range) {
				cout << "Nobody on this stop " << i << endl;
			}

		}
		
		cursorTaxi->setÂirection(false);

		for (int i = cursorTaxi->getStops().size()-1; i >= 0; i--) {
			cout << "Do you want to see a menu? Print 1 - yes,"
			"smth else - no" << endl;
			int choose;
			cin >> choose;
			if (choose == 1) {
				Util::makeAnAction(cursorMap);
			}

			int stop = cursorTaxi->getStops()[i];
			cursorTaxi->dropOff(stop);

			try {
				queue<Passenger> currQueue = cursorMap->at(stop);
				while (!currQueue.empty()) {
					Passenger pass = currQueue.front();
					currQueue.pop();
					cursorTaxi->addPassengers(stop, pass);
				}
			}
			catch (out_of_range) {
				cout << "Nobody on this stop " << stop << endl;
			}
		}

		cursorTaxi->setÂirection(true);
		cout << "Change direction" << endl;
	}
	
}
