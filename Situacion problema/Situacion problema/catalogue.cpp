#include "catalogue.h"

bool Catalogue::loadFromCSV(const string& fileName) {
    ifstream        file(fileName);
    string          line;
    unsigned int    size = 0;

    if (!file.is_open()) {
        cerr << "Error al abrir el archivo: " << fileName << endl;
        return false;
    }

    if (!getline(file, line)) {
        cerr << "El archivo no tiene header" << endl;
        file.close();
        return false;
    }

    cout << "Cargando archivo: " << fileName << endl;

    while (getline(file, line)) {
        Monster         nMonster;
        stringstream    ss(line);
        string          cell;
        int             campo = 0, errores = 0;

        while (getline(ss, cell, ',')) {
            if (!cell.length())
                errores++;
            switch (campo) {
            case 0:
                nMonster.setName(cell);
                break;
            case 1:
                nMonster.setCr(stof(cell)); // Convertir string a float
                break;
            case 2:
                nMonster.setType(cell);
                break;
            case 3:
                nMonster.setSize(cell);
                break;
            case 4:
                nMonster.setArmor(stoi(cell)); // Convertir string a int
                break;
            case 5:
                nMonster.setHp(stoi(cell)); // Convertir string a int
                break;
            case 6:
                nMonster.setAlign(cell);
                break;
            default:
                errores++;
                break;
            }

            campo++;
        }
        if (errores) {
            cerr << "Error en la linea: " << endl << line << endl;
            file.close();
            return false;
        }
        tree.inserta(nMonster);
    }
    file.close();
    return true;
}

Monster* Catalogue::aleatorio() {
    int total_monsters = tree.contarNodos();
    if (total_monsters == 0) {
        throw std::out_of_range("El árbol está vacío");
    }
    int random = rand() % total_monsters + 1;
    Monster* selected_monster;
    selected_monster = tree.obtainSelection(random);
    return selected_monster;
}

void Catalogue::print() {
    tree.printInOrder();
}