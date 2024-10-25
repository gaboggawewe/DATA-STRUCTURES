#pragma once
#include <iostream>
#include "templates/template_doble_ligadas.h"
#include "room.h"
using namespace std;

class Dungeon {
private:
	Double_list<Room> lista;

public:

	Dungeon() {
	}

	~Dungeon() {
	}

	bool createRoom(Monster monster);

	void print();
};