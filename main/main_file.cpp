#include <iostream>
#include <string>
#include "location.cpp"
//#include "event.cpp"
//#include "ticket.cpp"
using namespace std;

int main() {
	int noVipSeats = 3;
	int* vipSeats = new int[noVipSeats];
	for (int i = 0; i < noVipSeats; i++) {
		vipSeats[i] = i;
	}
	Location a(noVipSeats, vipSeats, "peepee :)");
	cout << a.get_locationName()<<endl;
	cout << a.get_noNormalSeats()<<endl;
	for (int i = 0; i < noVipSeats; i++) {
		cout << a.get_specific_VipSeat(i) << endl;
	}
}