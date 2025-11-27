#pragma once
#include <iostream>
#include "Room.h"
#include "Tree.h"
using namespace std;

class Dungeon {
private:
	const static int CHILD = 3;

	Tree<Room, CHILD> * root;
	Tree<Room, CHILD> * current;

public:
	Dungeon();

	// Getter
	Room & GetCurrentRoom();    // return reference

	int SubRoomSize(); // Return the Number of Sub Rooms

	int CurrentMonsterSize(); // Get the Monster size in this current room
	string MonsterName(int index); // Get the Monster name in this current room

	void MoveRoom(int index); // Move into the room
};