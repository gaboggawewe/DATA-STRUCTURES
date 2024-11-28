#include "dungeon.h"

void Dungeon::print() {
	cout << "El calabozo cuenta con los siguientes cuartos: " << endl << endl;
	for (unsigned int i = 0; i < graph.getSize(); i++) {
		cout << "Cuarto " << i << " " << *graph.getVertexData(i);
		cout << " Conexiones: ";
		graph.printEdges(i);
		cout << endl;
	}
}

bool Dungeon::createDungeon(string filename) {
	return graph.loadFile(filename);
}

unsigned int Dungeon::getSize() {
	return graph.getSize();
}

bool Dungeon::createRoom(unsigned int vertex,Monster monster) {
	Room cuarto(monster);
	if (!graph.setVertex(vertex, cuarto)) {
		return false;
	}
	return true;
}

bool Dungeon::obtainRoute(unsigned int origin, unsigned int destination) {
	path.deleteLista();
	if (!graph.BFS_path(origin, destination, path)) {
		cout << "No se encontro una ruta." << endl;
		return false;
	}
	act = path.begin();
	return true;
}

Room* Dungeon::currentRoomRoute() {
	if (act != path.end()) {
		Room* room = graph.getVertexData(*act);
		return room;
	}
	return nullptr;
}

bool Dungeon::forwardInRoute() {
	if (currentRoomRoute()) {
		++act;
		return true;
	}
	return false;
}
