#include <iostream>
#include <string>
#include "location.cpp"
//#include "event.cpp"
//#include "ticket.cpp"
using namespace std;

int main() {
	Location a;
	a.set_noSeats(100);
	cout << a.get_noNormalSeats();
}