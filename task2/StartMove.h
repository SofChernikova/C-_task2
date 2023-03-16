#pragma once
#include "RouteTaxi.h"
#include <queue>
class StartMove
{
public:
	void start(map<int, queue<Passenger>>* cursorMap,
		RouteTaxi* cursorTaxi);
};

