#include "Util.h"
#include <iostream>
using namespace std;


void Util::Menu()
{
	cout << "Выберете одну из следующих цифр: " << endl;
	cout << "1. Добавить пассажира на остановку" << endl;	
	cout << "2. Выход" << endl;
}

void Util::fillStops(map<int, queue<Passenger>>* stopsMap)
{
	for (int i = 1; i <= 10; i++) {
		queue<Passenger> awaiting;
		//stopsMap[i] = awaiting;
		stopsMap->insert(make_pair(i, awaiting));
	}
}

void Util::addPassengerToStop(int stop, map<int, queue<Passenger>>* stopsMap, 
	Passenger* pass)
{
	try {
		stopsMap->at(stop).push(*pass);
	}
	catch (out_of_range) {
		queue<Passenger> queue;
		queue.push(*pass);
		stopsMap->insert(make_pair(stop, queue));
	}
	
}

void Util::makeAnAction(map<int, queue<Passenger>>* map)
{
	Util::Menu();
	int choose;
	cin >> choose;

	switch (choose)
	{
	case 1:
	{
		cout << "Print departure station and the number of station of destination: " << endl;
		int stop;
		int path;
		cin >> stop >> path;
		Passenger passenger{ path };
		Passenger* cursor = &passenger;
		Util::addPassengerToStop(stop, map, cursor);	
		break;
	}	
	case 2:
		cout << "OK";
		exit(2);
	}		
}

