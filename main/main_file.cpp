#include <iostream>
#include <string>
//#include "location.cpp"
#include "event.cpp"
//#include "ticket.cpp"
using namespace std;

int main() {
	Location a;
	int vipSeats1[] = { 3,12,9,18,6 };
	int vipSeats2[] = { 6, 8 };
	Event e1(5, vipSeats1);
	Event e2(2, vipSeats2);
	Event event[] = {e1,e2};
	cout << Event::get_avg_noVipSeats(event, 2) << endl;
	cout << e1.get_specific_VipSeat(2) << endl;

}