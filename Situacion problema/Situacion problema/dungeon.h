#pragma once
#include <iostream>
#include "templates/graphos.h"
#include "room.h"
using namespace std;

class Dungeon {
private:
	Graph<Room> graph;
	Double_list<unsigned int> path;
	Double_list<unsigned int>::iterator act;
public:

	Dungeon() {
	}

	~Dungeon() {
	}

	unsigned int getSize();

	bool createDungeon(string filename);

	bool createRoom(unsigned int vertex, Monster monster);

	bool obtainRoute(unsigned int origin, unsigned int destination);

	Room* currentRoomRoute();

	bool forwardInRoute();

	void print();
};