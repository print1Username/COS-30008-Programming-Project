#pragma once
#include <iostream>
#include <string>
#include "Equipment.h"
using namespace std;

class Weapon : public Equipment {
private:
	int damage;

public:
	Weapon(string n, int dmg);
	Weapon(string n, string d, int dmg);
	
	// Getter
	int getDamage();

	string print() override;
};