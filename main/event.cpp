#include <iostream>
#include <string>
#include "location.cpp"
using namespace std;

class Event {
private:
	Location l;
	int* vipSeats;
	int noVipSeats;
public:
	//misc methods
	bool check_vipSeats(int noVipSeats, int* vipSeats) {
		for (int i = 0; i < noVipSeats; i++) {
			if (vipSeats[i] > this->l.get_maxSeats()) {
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
		if (noVipSeats > 0 && noVipSeats < this->l.get_maxSeats()) {
			this->noVipSeats = noVipSeats;
		}
		else cout << "Something's wrong with your number of VIP seats, stoopid.";
	}
	void set_vipSeats(int noVipSeats, int* vipSeats) {
		delete[] this->vipSeats;
		this->vipSeats = new int[noVipSeats];
		if (check_vipSeats(noVipSeats, vipSeats) == true) {
			for (int i = 0; i < noVipSeats; i++) {
				this->vipSeats[i] = vipSeats[i];
			}
		}
		else cout << "Some seat in your arrangement is wrong, stoopid.";
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
			set_noVipSeats(noVipSeats);
			if (vipSeats != nullptr) {
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
	static float get_avg_noVipSeats(Event* event, int noEvents) {
		float sum=0;
		if (event != nullptr && noEvents > 0) {
			for (int i = 0; i < noEvents; i++) {
				sum += event[i].noVipSeats;
			}
			sum /= noEvents;
		}
		return sum;
	}
	friend inline istream& operator>>(istream& in, Event& e);
	friend inline ostream& operator<<(ostream& out, Event e);
};

inline istream& operator>>(istream& in, Event& e) {
	cout << endl << "Set location first: ";
	in >> e.l;
	e.noVipSeats = e.l.get_noVipSeats();
	cout << endl << "Set the list of VIP seats: ";
	int* veepseets = new int[e.l.get_noVipSeats()];
	for (int i = 0; i < e.noVipSeats; i++) {
		in >> veepseets[i];
	}
	e.set_vipSeats(e.l.get_noVipSeats(), veepseets);
	return in;
}
inline ostream& operator<< (ostream& out, Event e) {
	out << "Location details: " << endl;
	out << e.l << endl;
	out << "And the list of VIP seats: " << endl;
	for (int i = 0; i < e.noVipSeats; i++) {
		out << e.get_specific_VipSeat(i) << " ";
	}
	return out;
}

