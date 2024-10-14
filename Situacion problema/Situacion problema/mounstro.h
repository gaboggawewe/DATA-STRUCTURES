#pragma once
#include <iostream>
using namespace std;

class Monster {
private:
	string name;
	float cr;
	string type;
	string size;
	int armor;
	int hp;
	string align;
public:
	Monster(string name, float cr, string type, string size, int armor, int hp, string align) {
		this->name = name;
		this->cr = cr;
		this->type = type;
		this->size = size;
		this->armor = armor;
		this->hp = hp;
		this->align = align;
	}
};