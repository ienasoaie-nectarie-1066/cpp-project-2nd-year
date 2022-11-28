#include <iostream>
#include <string>
using namespace std;
#pragma warning(disable: 4996)

class Location {
private:
	const int maxSeats = 100;
	int noVipSeats;
	int noNormalSeats;
	string locationName;
public:

//setters
	void set_noSeats(int noVipSeats) {
		if (noVipSeats <= maxSeats) {
			this->noNormalSeats = maxSeats - noVipSeats;
			this->noVipSeats = noVipSeats;
		}
		else cout << "Number of VIP seats exceeds maximum number of seats, stoopid" << endl;
	}
	void set_locationName(string locName) {
		if (locName.size() > 5) {
			this->locationName = locName;
		}
	}

	//default constructor
	Location() {
		this->noVipSeats = 0;
		//as there are no VIP seat allocated, the number of normal seats remains the same
		this->noNormalSeats = maxSeats;
		this->locationName = "A normal looking movie theatre";
	}

	//constructor with parameters
	Location(int noVipSeats, string locationName) {
		set_noSeats(noVipSeats);
		if (locationName.size() > 5) {
			this->locationName = locationName;
		}
		else cout << "Minimum 5 character name, stoopid" << endl; 
	}

	//getters
	int get_noNormalSeats() {
		return this->noNormalSeats;
	}
	int get_noVipSeats() {
		return this->noVipSeats;
	}
	int get_maxSeats() {
		return this->maxSeats;
	}
	string get_locationName() {
		return this->locationName;
	}
};