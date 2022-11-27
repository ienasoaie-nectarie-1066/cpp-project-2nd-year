#include <iostream>
#include <string>
using namespace std;

class Location {
private:
	const int maxSeats = 100;
	int noVipSeats;
	//all VIP seats must be under 99
	int* vipSeats;
	int noNormalSeats;
	string locationName;
public:
	//default constructor;
	Location() {
		this->noVipSeats = 0;
		//as there are no VIP seat allocated, the number of normal seats remains the same
		this->noNormalSeats = maxSeats;
		this->vipSeats = nullptr;
		this->locationName = "Normal looking movie theatre";
	}

	//function to check the validity of the VIP seats, so that no two seats are identical and they are all within the 100 seat limit
	bool check_vipSeats(int noVipSeats, int* vipSeats) {
		for (int i = 0; i < noVipSeats; i++) {
			if (vipSeats[i] > 99) {
				return false;
			}
			for (int j = 0; j < noVipSeats; j++) {
				if (i != j && vipSeats[i] == vipSeats[j]) {
					return false;
				}
			}
		}
		return true;
	}

	//constructor with parameters
	Location(int noVipSeats, int* vipSeats, string locationName) {
		if (noVipSeats <= this->maxSeats) {
			set_noSeats(noVipSeats);
			if (vipSeats != nullptr && check_vipSeats(noVipSeats, vipSeats) == true) {
				this->vipSeats = new int[noVipSeats];
				for (int i = 0; i < noVipSeats; i++) {
					this->vipSeats[i] = vipSeats[i];
				}
			}
			else throw "VIP Seating arrangement is incorrect.";
		}
		else throw "Number of VIP seats exceeds the theatre capacity.";
		this->locationName = locationName;
	}

	//copy constructor
	Location(const Location& loc) {
		this->locationName = loc.locationName;
		if (loc.noVipSeats > 0 && loc.vipSeats != nullptr) {
			set_noSeats(loc.noVipSeats);
			this->vipSeats = new int[loc.noVipSeats];
			for (int i = 0; i < loc.noVipSeats; i++) {
				this->vipSeats[i] = loc.vipSeats[i];
			}
		}
		else {
			set_noSeats(0);
			this->vipSeats = nullptr;
		}
	}

	//destructor
	~Location() {
		if (this->vipSeats != nullptr) {
			delete[] vipSeats;
		}
	}
	//setters
	void set_noSeats(int noVipSeats) {
		this->noNormalSeats = maxSeats - noVipSeats;
		this->noVipSeats = noVipSeats;
	}

	//getters
	int get_noNormalSeats() {
		return this->noNormalSeats;
	}
	int get_maxSeats() {
		return this->maxSeats;
	}
};