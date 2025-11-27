#include "Dungeon.h"

Dungeon::Dungeon() {
    // Allocate rooms on heap so references stay valid
    Room * rootRoom = new Room("Root Room");
    Room * room1 = new Room("Room 1");
    Room * room2 = new Room("Room 2");
    Room * room3 = new Room("Room 3");
    Room * room11 = new Room("Room 1.1");
    Room * room12 = new Room("Room 1.2");
    Room * room21 = new Room("Room 2.1");
    Room * room22 = new Room("Room 2.2");

    // Build tree (Tree requires T&, so dereference pointers)
    root = new Tree<Room, CHILD>(*rootRoom);
    Tree<Room, CHILD> * t1 = new Tree<Room, CHILD>(*room1);
    Tree<Room, CHILD> * t2 = new Tree<Room, CHILD>(*room2);
    Tree<Room, CHILD> * t3 = new Tree<Room, CHILD>(*room2);
    Tree<Room, CHILD> * t11 = new Tree<Room, CHILD>(*room11);
    Tree<Room, CHILD> * t12 = new Tree<Room, CHILD>(*room12);
    Tree<Room, CHILD> * t21 = new Tree<Room, CHILD>(*room21);
    Tree<Room, CHILD> * t22 = new Tree<Room, CHILD>(*room22);

    // Attach to structure
    root->attachTree(0, t1);
    root->attachTree(1, t2);
	root->attachTree(2, t3);

    t1->attachTree(0, t11);
    t1->attachTree(1, t12);

    t2->attachTree(0, t21);
    t2->attachTree(1, t22);

    // Start at root
    current = root;

    // Spawn monster
    Monster m1("M1", 10, 2);
    m1.setPosition(600.f, 600.f);

    current->getKey().addMonster(m1);  // Safe & correct
}

Room & Dungeon::GetCurrentRoom() {
    return current->getKey();
}

int Dungeon::SubRoomSize() {
    return current->getSize();
}

int Dungeon::CurrentMonsterSize() {
    return current->getKey().getMonsterCount();
}

string Dungeon::MonsterName(int index) {
    if ( index < 0 || index >= current->getKey().getMonsterCount() )
        throw out_of_range("Invalid monster index.");

    Monster & m = current->getKey().getMonsterRef(index);
    return m.getName();
}

void Dungeon::MoveRoom(int index) {
    if ( index < 0 || index >= SubRoomSize() )
        throw out_of_range("Invalid room index.");

    Tree<Room, CHILD> * next = current->getChild(index);
    if ( next == Tree<Room, CHILD>::NIL )
        return;

    current = next;
}
