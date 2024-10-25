#pragma once
#include "monster.h"

class Room{
private:

	Monster monster;

public:

	Room() {
	}

	Room(Monster monster) {
		this->monster = monster;
	}

	~Room() {
	}

	friend ostream& operator<<(ostream& os, const Room& room);
};