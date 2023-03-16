#pragma once
#include <queue>
#include <map>
#include "Passenger.h"

class Util
{
public:
	static void Menu();
	static void fillStops(map<int, queue<Passenger>>* stopsMap);
// инициализация остановок
	static void addPassengerToStop(int stop, map<int, queue<Passenger>>* stopsMap,
		Passenger* pass);
	static void makeAnAction(map<int, queue<Passenger>>* map);
};

