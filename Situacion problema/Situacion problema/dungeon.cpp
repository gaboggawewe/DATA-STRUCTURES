#include "dungeon.h"


void Dungeon::print() {
	cout << "El calabozo cuenta con los siguientes cuartos: " << endl;
	for (unsigned int i = 0; i < graph.getSize(); i++) {
		cout << "Cuarto " << i << " con monstruo: " << graph.getVertexData(i);
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
	graph.setVertex(vertex,cuarto);
	return true;
}