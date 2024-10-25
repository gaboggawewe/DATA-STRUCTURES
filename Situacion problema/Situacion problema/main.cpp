#include <iostream>
#include <fstream>
using namespace std;
#include "catalogue.h"
#include "dungeon.h"
#include "monster.h"
#include "room.h"
#include "player.h"
#define NUM_CUARTOS 20

int main() {
	srand(time(0));
	Catalogue miCatalogo;
	Dungeon miDungeon;
	Player player1 ("Awewe", "Elfo", 100, 50);
	if (!miCatalogo.loadFromCSV("monsters.csv")) {
		cout << "No se pudo cargar el catalogo" << endl;
		return 0;
	}
	cout << "Creating Dungeon" << endl;

	for (int i = 0; i < NUM_CUARTOS; i++) {
		Monster *pMonster = nullptr, copiaMounstro;
		pMonster = miCatalogo.aleatorio();
		if (!pMonster) {
			cout << "No se pudo obtener un mounstro del catalogo" << endl;
			return 0;
		}
		copiaMounstro = *pMonster;
		if (!miDungeon.createRoom(copiaMounstro)) {
			cout << "No se pudo insertar el cuarto con un mounstro al calabozo" << endl;
			return 0;
		}
		player1.insertDerrotado(&copiaMounstro); //inserto todos los mounstros del calabozo a la lista ligada que tiene el jugador, para probar funcionalidad
	}
	miDungeon.print();
	player1.print();

	return 0;
}