#include <iostream>
#include <string>
#include "location.cpp"
//#include "event.cpp"
//#include "ticket.cpp"
using namespace std;

int main() {
	Location a(102,"pee");
	cout << a.get_locationName() << " " << a.get_noNormalSeats() << " and " << a.get_noVipSeats();
}