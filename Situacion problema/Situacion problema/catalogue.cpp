#include "catalogue.h"

bool Catalogue::loadFromCSV(const string& fileName) {
    ifstream        file(fileName);
    string          line;

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
                nMonster.setCr(stof(cell));
                break;
            case 2:
                nMonster.setType(cell);
                break;
            case 3:
                nMonster.setSize(cell);
                break;
            case 4:
                nMonster.setArmor(stoi(cell));
                break;
            case 5:
                nMonster.setHp(stoi(cell));
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
        if(!tree.inserta(nMonster)){
            cerr << "No se pudo agregar el mounstro a la lista, no hay memoria" << endl;
            file.close();
            return false;
        }
        size++;
    }
    file.close();
    return true;
}

Monster* Catalogue::aleatorio() {
    if (size == 0) {
        throw std::out_of_range("El arbol esta vacio");
    }
    int random = rand() % size + 1;
    Monster* selected_monster;
    selected_monster = tree.obtainSelection(random);
    return selected_monster;
}

void Catalogue::print() {
    tree.printInOrder();
}