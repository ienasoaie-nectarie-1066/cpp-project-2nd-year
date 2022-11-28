#include <iostream>
#include <string>
#include "location.cpp"
//#include "event.cpp"
//#include "ticket.cpp"
using namespace std;

int main() {
	Location a;
	a.set_locationName("DingDong");
	a.set_noVipSeats(13);
	cout << a.get_locationName() << " " << a.get_noNormalSeats() << " and " << a.get_noVipSeats();
}