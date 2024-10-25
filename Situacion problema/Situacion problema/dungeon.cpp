#include "dungeon.h"

void Dungeon::print() {
	cout << "El calabozo cuenta con los siguientes cuartos: " << endl;
	lista.printListaBeg();
}

bool Dungeon::createRoom(Monster monster) {
	Room cuarto(monster);
	return (lista.insertarInicio(cuarto));
}