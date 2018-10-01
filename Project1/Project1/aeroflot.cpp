#include "aeroflot.h"

using namespace std;

AEROFLOT::AEROFLOT() {
	destination = "unknown";
	route = 0;
	type = "unknown";

	cout << "Constructor without parameters called" << endl;
}