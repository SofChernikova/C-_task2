#include "RouteTaxi.h"
#include <iostream>
using namespace std;

vector<int> RouteTaxi::initStops()
{
	vector<int> stops{1, 2, 3, 4, 5};
	return stops;
};

map<int, vector<Passenger>> RouteTaxi::initPassengers()
{
	map<int, vector<Passenger>> passengers;

	for (int i = 1; i <= 5; i++) {
		Passenger* passenger = new Passenger(i);
		vector<Passenger> vector{ *passenger };
		passengers.insert(make_pair(i, vector));
	}
	return passengers;
};

RouteTaxi::RouteTaxi()
{
	RouteTaxi::stops = initStops();
	RouteTaxi::passengers = initPassengers();
	RouteTaxi::size = 10;
	RouteTaxi::occupied = 5;
	RouteTaxi::forward = true;
}
RouteTaxi::~RouteTaxi()
{
	cout << "Delete RouteTaxi";
}
;

 //___________________________________________________________

map<int, vector<Passenger>> RouteTaxi::getPassengers() {
	 return RouteTaxi::passengers;
 } 

 vector<int> RouteTaxi::getStops() {
	 return RouteTaxi::stops;
 };

void RouteTaxi::setDirection(bool value)
{
	RouteTaxi::forward = value;
};


//____________________________________________________________

bool RouteTaxi::hasStop(int name)
{
	for (int i : RouteTaxi::stops) {
		if (name == i) return true;
	}
	return false;
}

bool RouteTaxi::hasFreeSpace()
 {
	 return RouteTaxi::occupied < RouteTaxi::size ? true : false;
 }

 void RouteTaxi::takeSeat()
 {
	 RouteTaxi::occupied++;
 }

 void RouteTaxi::freeUpSpace(int count)
 {
	 RouteTaxi::occupied-=count;
 }
 //----------------------------------------------------

 // add to the taxi
 void RouteTaxi::addPassengers(int currStop, Passenger pass)
 {
	 if(!RouteTaxi::hasStop(pass.getStop())){
		 cout << "Unsutable route" << endl;
		 return;
	 }

	if(RouteTaxi::forward){
		if (pass.getStop() <= currStop) {
			cout << "Unsutable route"<< endl;
			return;
		}
		if (!RouteTaxi::hasFreeSpace()) {
			cout << "No free space :( " << endl;
			return;
		}
		if (RouteTaxi::passengers.count(pass.getStop()) != 1) {
			vector<Passenger> newPass;
			newPass.push_back(pass);
			RouteTaxi::passengers.insert(make_pair(pass.getStop(), newPass));
			RouteTaxi::takeSeat();
		}
		else {
			RouteTaxi::passengers.at(pass.getStop()).push_back(pass);
			RouteTaxi::takeSeat();
		}
		cout << "Sat " << pass.getStop() << endl;
		
	}
 }
 void RouteTaxi::dropOff(int currStop)
 {
	 try {
		 int count = RouteTaxi::passengers.at(currStop).size();
		 RouteTaxi::freeUpSpace(count);
		RouteTaxi::passengers.erase(currStop);	
		cout << "This stop" << currStop << " left " << count << endl;
	 }catch(out_of_range){
		 cout << "There is nobody to leave the taxi" << endl;
	 }
	 
 };
 