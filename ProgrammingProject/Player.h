#pragma once
#include <iostream>
#include "Equipment.h"
#include "List.h"
using namespace std;

class Player {
private:
	string name;
	int hp;

	int damage;

	struct position {
		float x;
		float y;
	} pos;

	const int maxhp;
	const int maxequip = 10;

	const double speed = 1.0;

	List<Equipment> equip;

public:
	Player(string n, int h, int d);

	// Getter
	string getName();
	int getHp();
	int getMaxHp();
	float getPositionX();
	float getPositionY();
	double getSpeed();
	int getDamage();

	// Setter
	int setHp(int h);
	int setPosition(int x, int y);
	void healing(int h);
	void damaging(int h);

	// List
	void addEquipment(const Equipment & e);
	void removeEquipment(int index);
	void listEquipment();

	string printPlayer();

	friend ostream & operator<<(ostream & s, Player & p);
};