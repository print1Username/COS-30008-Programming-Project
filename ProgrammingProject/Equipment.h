#pragma once
#include <iostream>
#include <string>
using namespace std;

class Equipment {
protected:
	string name;
	string description;

public:
	// Constructor
	Equipment();
	Equipment(string n);
	Equipment(string n, string d);

	// Getter
	string getName();
	string getDescription();

	virtual string print();

	// operator
	friend ostream & operator<<(ostream & s, Equipment & e);
};