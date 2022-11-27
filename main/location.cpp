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
	//default constructor
	Location() {
		this->noVipSeats = 0;
		//as there are no VIP seat allocated, the number of normal seats remains the same
		this->noNormalSeats = maxSeats;
		this->vipSeats = nullptr;
		this->locationName = "Normal looking movie theatre";
	}

	//constructor with parameters
	Location(int noVipSeats, int* vipSeats, string locationName) {
		set_noSeats(noVipSeats);
		if (vipSeats != nullptr && check_vipSeats(noVipSeats, vipSeats) == true) {
				this->vipSeats = new int[noVipSeats];
				for (int i = 0; i < noVipSeats; i++) {
					this->vipSeats[i] = vipSeats[i];
				}
		}
		else throw "VIP Seating arrangement is incorrect.";
		this->locationName = locationName;
	}

	//copy constructor
	Location(const Location& loc) {
		this->locationName = loc.locationName;
		if (loc.noVipSeats > 0 && loc.vipSeats != nullptr && check_vipSeats(loc.noVipSeats, loc.vipSeats)==true) {
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

	//equals operator
	Location& operator=(const Location& loc) {
		if (this != &loc) {
			this->locationName = loc.locationName;
			if (this->vipSeats != nullptr) delete[] this->vipSeats;
			if (loc.noVipSeats > 0 && loc.vipSeats != nullptr && check_vipSeats(loc.noVipSeats, loc.vipSeats)==true) {
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
	}

	//destructor
	~Location() {
		if (this->vipSeats != nullptr) {
			delete[] vipSeats;
		}
	}

	//misc. methods
	//method to check VIP seating validity
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

	//setters
	void set_noSeats(int noVipSeats) {
		if (noVipSeats <= maxSeats) {
			this->noNormalSeats = maxSeats - noVipSeats;
			this->noVipSeats = noVipSeats;
		}
		else throw "Number of VIP seats exceeds theatre capacity.";
	}
	void set_locationName(string locName) {
		this->locationName = locName;
	}
	void set_vipSeats(int noVipSeats, int* vipSeats) {
		if (check_vipSeats(noVipSeats, vipSeats) == true) {
			delete[] this->vipSeats;
			this->vipSeats = new int[noVipSeats];
			for (int i = 0; i < noVipSeats; i++) {
				this->vipSeats[i] = vipSeats[i];
			}
		}
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
	int* get_vipSeats() {
		if (this->noVipSeats > 0 && this->vipSeats != nullptr) {
			int* cVipSeats = new int[this->noVipSeats];
			for (int i = 0; i < this->noVipSeats; i++) {
				cVipSeats[i] = this->vipSeats[i];
			}
			return cVipSeats;
		}
		else return nullptr;
	}
	int get_specific_VipSeat(int index) {
		if (index >= 0 && index < this->noVipSeats && this->vipSeats != nullptr) {
			return this->vipSeats[index];
		}
		else return -1;
	}

};