#include <iostream>
#include <string>
using namespace std;

class Location {
private:
	static const int maxSeats = 100;
	int noVipSeats;
	int* vipSeats;
	//the vipSeats vector must contain two digit numbers; first digit is the row, second digit is the column
	int noNormalSeats;
	string locationName;
public:

	//default constructor;
	Location() {
		this->noVipSeats = 0;
		this->noNormalSeats = 0;
		this->vipSeats = nullptr;
		this->locationName = "Normal looking movie theatre";
	}

	//constructor with parameters
	Location(int noVipSeats, int noNormalSeats, int* vipSeats, string locationName) {
		if (noVipSeats + noNormalSeats < this->maxSeats) {
			this->noVipSeats = noVipSeats;
			this->noNormalSeats = noNormalSeats;
			if (vipSeats != nullptr) {
				this->vipSeats = new int[noVipSeats];
				for (int i = 0; i < noVipSeats; i++) {
					this->vipSeats[i] = vipSeats[i];
				}
			}
		}
		this->locationName = locationName;
	}

	//destructor
	~Location() {
		if (this->vipSeats != nullptr) {
			delete[] vipSeats;
		}
	}

	int get_maxSeats() {
		return this->maxSeats;
	}
};