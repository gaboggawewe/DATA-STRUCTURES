#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "monster.h"
#include "templates/arbolbinario.h"
#include <ctime>
using namespace std;

class Catalogue{
private:

    ArbolBinario<Monster> tree;

public:

    Catalogue() {
    }

    ~Catalogue() {
    }

    bool loadFromCSV(const string& fileName);
    Monster* aleatorio();
    void print();


};