#include "hashtable.h"
using namespace std;

bool HashTable::createTable(unsigned int nsize) {
	if (!table) {
		if (nsize == 0) {
			return false;
		}
		table = new(nothrow) Double_list<Monster>[nsize];
		if (!table) {
			return false;
		}
		size = nsize;
		return true;
	}
	return false;
}

void HashTable::deleteTable() {
	if (table) {
		delete[] table;
		table = nullptr;
		size = 0;
	}
}

unsigned int HashTable::hashMonster(Monster mounstro) {
	string name;
	unsigned int hashValue = 0, len = 0;
	name = mounstro.getName();
	len = name.length();
	for (unsigned int l = 0; l < len; l++) {
		hashValue = hashValue + name[l];
	}
	return hashValue % size;
}

bool HashTable::insert(Monster mounstro) {
	unsigned int index = 0;
	if (!table) {
		return false;
	}
	index = hashMonster(mounstro);
	return table[index].insertarFinal(mounstro);
}

bool HashTable::deleteM(Monster mounstro) {
	return true;
}

Monster* HashTable::search(string name) {
	unsigned int index = 0;
	if (!table) {
		return nullptr;
	}
	index = hashMonster(mounstro);
	return table[index].search(mounstro);
}


