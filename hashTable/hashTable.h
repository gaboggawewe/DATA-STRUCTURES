#pragma once
#include "template_doble_ligadas.h"

template <typename T>
class HashTable {
private:
    Double_list<T>* array;
    unsigned int size;

    unsigned int getIndex(T data) {
        if (!HashFunction) {
            return 0;
        }
        return HashFunction(data, size) % size;
    }

    HashFunction hashFunction;

public:
    using HashFunction = unsigned int (*)(T&, unsigned int tableSize);

    HashTable() {
        hashFunction = nullptr;
        array = nullptr;
        size = 0;
    }
    ~HashTable() { 
        deleteTable(); 
    }

    bool createArray(unsigned int size, HashFunction hashF) {
        if (!size || array || !hashFunction) {
            return false;
        }
        array = new(nothrow) Double_list<T>[size];
        if (!array) {
            return false;
        }
        this-> size = size;
        hashFunction = hashF;
        return true;
    }

    void deleteTable() {
        if (!size) {
            return;
        }
        if (array) {
            delete[] array;
            array = nullptr;
            size = 0;
        }
    }

    bool insert(T data) {
        unsigned int index = 0;
        if (!array) {
            return false;
        }
        index = getIndex(data);
        if (!array[index].append(data)) {
            return false;
        }
        return true;
    }

    bool remove(T data) {
        if (!array) {
            return false;
        }
        unsigned int index = getIndex(data);
        return array[index].remove(data);
    }

    T* search(T data) {
        unsigned int index = 0;
        if (!array) {
            return nullptr;
        }
        index = getIndex(data);
        return (array[index].search(data));
    }

    void print() {
        int biggest = 0;
        for (unsigned int i = 0; i < size; i++) {
            int lSize = 0;
            lSize = array[i].getSize();
            cout << "Entry[" << i << "]: " << lSize << endl;
            if (lSize > biggest) {
                biggest = lSize;
            }
        }
        cout << "Biggest was: " << biggest << endl;
    }
};