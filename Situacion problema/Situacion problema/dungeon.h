#pragma once
#include <iostream>
#include "templates/graphos.h"
#include "room.h"
using namespace std;

class Dungeon {
private:
	Graph<Room> graph;
public:

	Dungeon() {
	}

	~Dungeon() {
	}

	unsigned int getSize();

	bool createDungeon(string filename);

	bool createRoom(unsigned int vertex, Monster monster);

	void print();
};