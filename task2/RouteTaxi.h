#pragma once
#include <vector>
#include <string>
#include <map>
#include "Passenger.h"
using namespace std;

class RouteTaxi
{
private:
	vector<int> stops; // список остановок маршрутки
	map<int, vector<Passenger>> passengers; // салон маршрутки  
	// (остановка -> некотрое кол-во пассажиров
	int size;
	int occupied;
	bool forward;

	vector<int> initStops(); // первоначальная инициализация остановок
	map<int, vector<Passenger>> initPassengers(); // первоначальная инициализация пассажиров

	bool hasStop(int name);
	bool hasFreeSpace();
	void takeSeat();
	void freeUpSpace(int count);

public:
	RouteTaxi();
	~RouteTaxi();
	vector<int> getStops();
	map<int, vector<Passenger>> getPassengers();
	void setDirection(bool value);


	void addPassengers(int currStop, Passenger pass);
	void dropOff(int currStop);
};

