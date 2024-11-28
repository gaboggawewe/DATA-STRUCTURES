#include <iostream>
#include <fstream>
using namespace std;
#include "catalogue.h"
#include "dungeon.h"
#include "monster.h"
#include "room.h"
#include "player.h"

int main() {
    srand(time(0));
    unsigned int inicio, fin;
    Catalogue    miCatalogo;
    Dungeon     miDungeon;

    if (!miCatalogo.loadFromCSV("monsters.csv")) {
        cout << "No se pudo crear el catalogo" << endl;
        return 0;
    }

    cout << "Creando Dungeon..." << endl;
    if (!miDungeon.createDungeon("dungeon.txt")) {
        cout << "No se pudo crear el Dungeon" << endl;
        return 0;
    }

    for (unsigned int c = 0; c < miDungeon.getSize(); c++) {
        Monster* pMonster = nullptr, copiaMonstruo;

        pMonster = miCatalogo.aleatorio();
        if (!pMonster) {
            cout << "No se pudo obtener un monstruo del catalogo" << endl;
            return 0;
        }

        copiaMonstruo = *pMonster;
        if (!miDungeon.createRoom(c, copiaMonstruo)) {
            cout << "No se pudo insertar cuarto con monstruo al calabozo" << endl;
            return 0;
        }
    }

    miDungeon.print();

    cout << "Elije una ruta:\n";
    do {
        cout << "Dame el cuarto inicial: ";
        cin >> inicio;
        cout << "Dame el cuarto final: ";
        cin >> fin;
    } while (fin > miDungeon.getSize() || inicio == fin);

    if (!miDungeon.obtainRoute(inicio, fin)) {
        cout << "No existe ruta de " << inicio << " a " << fin << "\n";
        return 0;
    }

    cout << "     (\\___/)\n";
    cout << "     (o   o)\n";
    cout << "     (  -  )\n";
    cout << "    /       \\\n";
    cout << "   /|       |\\\n";
    cout << "  / |       | \\\n";
    cout << " *  |_______|  *\n";
    cout << "    *       *\n";
    cout << endl;
    cout << "  BBBBB   III  EEEEE  N   N  VVV   V  EEEEE  N   N  III  DDDD   OOO\n";
    cout << "  B    B   I   E      NN  N  VVV   V  E      NN  N   I   D   D O   O\n";
    cout << "  BBBBB    I   EEEE   N N N  VVV   V  EEEE   N N N   I   D   D O   O\n";
    cout << "  B    B   I   E      N  NN   VVV V   E      N  NN   I   D   D O   O\n";
    cout << "  BBBBB   III  EEEEE  N   N    VVV    EEEEE  N   N  III  DDDD   OOO\n";
    cout << "\n";
    cout << "  AAAAA  RRRR   TTTTT  EEEEE  M   M  III   OOO\n";
    cout << "  A   A  R   R    T    E      MM MM   I   O   O\n";
    cout << "  AAAAA  RRRR     T    EEEE   M M M   I   O   O\n";
    cout << "  A   A  R  R     T    E      M   M   I   O   O\n";
    cout << "  A   A  R   R    T    EEEEE  M   M  III   OOO\n";

    do {
        Room* actual = nullptr;

        actual = miDungeon.currentRoomRoute();
        if (actual) {
            cout << "Entrando a cuarto " << *actual << "\n";
        }
    } while (miDungeon.forwardInRoute());

    return 0;
};