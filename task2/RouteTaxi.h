#pragma once
#include <vector>
#include <string>
#include <map>
#include "Passenger.h"
using namespace std;

class RouteTaxi
{
private:
	vector<int> stops; // ������ ��������� ���������
	map<int, vector<Passenger>> passengers; // ����� ���������  
	// (��������� -> �������� ���-�� ����������
	int size;
	int occupied;
	bool forward;

	vector<int> initStops(); // �������������� ������������� ���������
	map<int, vector<Passenger>> initPassengers(); // �������������� ������������� ����������

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

