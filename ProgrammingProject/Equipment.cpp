#include "Equipment.h"

Equipment::Equipment() :
	name("Unknown Item"), description("No description available.") {}

Equipment::Equipment(string n) :
	name(n), description("No description available.") {}

Equipment::Equipment(string n, string d) :
	name(n), description(d) {}

string Equipment::getName() {
	return name;
}

string Equipment::getDescription() {
	return description;
}

string Equipment::print() {
	string o;
	o += "Item Name: " + name + "\n";
	o += "Description:\n";
	o += " " + description + "\n";
	o += "--------------------\n";
	return o;
}

ostream & operator<<(ostream & s, Equipment & e) {
	s << e.print();
	return s;
}