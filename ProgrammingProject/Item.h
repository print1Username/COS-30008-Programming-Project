#pragma once
#include <iostream>
#include <string>
#include "Equipment.h"
using namespace std;

class Item : public Equipment {
private: 
	int value;

public:
	Item();
};