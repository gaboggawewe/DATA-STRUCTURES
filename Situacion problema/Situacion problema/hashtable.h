#pragma once
#include "templates/template_doble_ligadas.h"
#include "monster.h"

class HashTable {
public:
    HashTable() {
        table = nullptr;
        size = 0;
    }
    ~HashTable() {
        deleteTable();
    }
    bool createTable(unsigned int nsize);
    void deleteTable();
    bool insert(Monster mounstro);
    bool deleteM(Monster mounstro);
    Monster* search(string name);
private:
    unsigned int hashMonster(Monster mounstro);
    Double_list<Monster>* table;
    unsigned int size;
};