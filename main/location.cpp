#include <iostream>
#include <string>
using namespace std;
#pragma warning(disable: 4996)

class Location {
private:
	const int maxSeats;
	int noVipSeats;
	int noNormalSeats;
	string locationName;
public:
//misc methods
	void theatre_locationName() {
		string t = " theatre";
		size_t found = this->locationName.find(t);
		if (found == string::npos) {
			this->locationName += t;
		}
	}
//setters
	void set_noVipSeats(int noVipSeats) {
		if (noVipSeats <= maxSeats) {
			this->noNormalSeats = maxSeats - noVipSeats;
			this->noVipSeats = noVipSeats;
		}
		else cout << "Number of VIP seats exceeds maximum number of seats, stoopid" << endl;
	}
	void set_locationName(string locName) {
		if (locName.size() > 5) {
			this->locationName = locName;
			theatre_locationName();
		}
		else cout << "Name must be over 5 characters long, stoopid" << endl;
	}
	
	//default constructor
	Location():maxSeats(100) {
		this->noVipSeats = 0;
		//as there are no VIP seat allocated, the number of normal seats remains the same
		this->noNormalSeats = maxSeats;
		this->locationName = "A normal looking movie theatre";
	}

	//constructor with parameters
	Location(int maxSeats, int noVipSeats, string locationName):maxSeats(maxSeats) {
		set_noVipSeats(noVipSeats);
		set_locationName(locationName);
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
	friend inline istream& operator>>(istream& in, Location& loc);
	friend inline ostream& operator<<(ostream& out, Location loc);
};

 inline istream& operator>>(istream& in, Location& loc) {
	cout << endl << "Set location name: ";
	string buffer;
	in >> buffer;
	loc.set_locationName(buffer);
	cout << "Number of VIP seats: ";
	in >> loc.noVipSeats;
	loc.set_noVipSeats(loc.noVipSeats);
	return in;
}
 inline ostream& operator<<(ostream& out, Location loc) {
	out << "Location name is: " << loc.locationName << endl;
	out << "The maximum number of seats is: " << loc.maxSeats << endl;
	out << "Of which VIP seats: " << loc.noVipSeats << endl;
	out << "And normal seats: " << loc.noNormalSeats << endl;
	return out;
}