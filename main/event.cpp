#include <iostream>
#include <string>
#include "location.cpp"
using namespace std;

class Event {
private:
	//all VIP seats must be under 99
	int* vipSeats;
	int noVipSeats;
public:
	//misc methods
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
	//getters and setters
	void set_noVipSeats(int noVipSeats) {
		if (noVipSeats > 0) {
			this->noVipSeats = noVipSeats;
		}
	}
	void set_vipSeats(int noVipSeats, int* vipSeats) {
		delete[] this->vipSeats;
		this->vipSeats = new int[noVipSeats];
		for (int i = 0; i < noVipSeats; i++) {
				this->vipSeats[i] = vipSeats[i];
		}
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
	Event() {
		this->noVipSeats = 0;
		this->vipSeats = nullptr;
	}
	Event(int noVipSeats, int* vipSeats) {
		if (noVipSeats > 0) {
			if (vipSeats != nullptr && check_vipSeats(noVipSeats, vipSeats) == true) {
				set_vipSeats(noVipSeats, vipSeats);
			}
		}
		else {
			this->noVipSeats = 0;
			this->vipSeats = nullptr;
		}
	}
	Event(const Event& e) {
		if (e.noVipSeats > 0 && e.vipSeats != nullptr) {
			this->vipSeats = new int[e.noVipSeats];
			for (int i = 0; i < e.noVipSeats; i++) {
				this->vipSeats[i] = e.vipSeats[i];
			}
			this->noVipSeats = e.noVipSeats;
		}
	}
	~Event() {
		if (this->vipSeats != nullptr) {
			delete[] this->vipSeats;	
		}
	}
	Event& operator=(const Event& e) {
		if (this != &e) {
			if (this->vipSeats != nullptr) {
				delete[] vipSeats;
			}
			if (e.noVipSeats > 0 && e.vipSeats != nullptr) {
				this->vipSeats = new int[e.noVipSeats];
				for (int i = 0; i < e.noVipSeats; i++) {
					this->vipSeats[i] = e.vipSeats[i];
				}
			}
			else {
				this->noVipSeats = 0;
				this->vipSeats = nullptr;
			}
		}
	}
};