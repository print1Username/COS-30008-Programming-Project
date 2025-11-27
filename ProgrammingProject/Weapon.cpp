#include "Weapon.h"

Weapon::Weapon(string n, int dmg) :
	Equipment(n), damage(dmg) {}

Weapon::Weapon(string n, string d, int dmg) :
	Equipment(n, d), damage(dmg) {}

int Weapon::getDamage() {
	return damage;
}

string Weapon::print() {
	string o;
	o += "Weapon Name: " + name + "\n";
	o += "Damage: " + to_string(damage) + "\n";
	o += "Description:\n";
	o += " " + description + "\n";
	o += "--------------------\n";
	return o;
}