#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "episode.h"
using namespace std;



void Episode::setSeason(string season) {
    this->season = season;
}
void Episode::setTitle(string title) {
    this->title = title;
}
string Episode::getSeason() {
    return season;
}
string Episode::getTitle() {
    return title;
}

void Episode::print() {
    cout << "ID: " << ID << endl;
    cout << "Name: " << name << endl;
    cout << "Duration: " << duration << endl;
    cout << "Gender: " << gender << endl;
    cout << "Title: " << title << endl;
    cout << "Season: " << season << endl;
    cout << "Rating: " << rating << endl;
}

bool Episode::loadEpisodeFromCSV(const string& fileName, Episode* episodeArray, unsigned int arraySize) {
    ifstream        file(fileName);
    string          line;
    unsigned int    size = 0;

    if (!file.is_open()) {
        cerr << "Error al abrir el archivo: " << fileName << endl;
        return false;
    }

    // skip header
    if (!getline(file, line)) {
        cerr << "El archivo no tiene header" << endl;
        file.close();
        return false;
    }

    cout << "Cargando archivo: " << fileName << endl;

    while (getline(file, line)) {
        Episode         nEpisode;
        stringstream    ss(line);
        string          cell;
        int             campo = 0, errores = 0;

        while (getline(ss, cell, ',')) {
            if (!cell.length())
                errores++;
            // ir coma por coma, esta version no valida que sean enteros o floats
            // por simplicidad
            switch (campo) {
            case 0:
                nEpisode.setID(cell);
                break;
            case 1:
                nEpisode.setName(cell);
                break;
            case 2:
                nEpisode.setDuration(cell);
                break;
            case 3:
                nEpisode.setGender(cell);
                break;
            case 4:
                nEpisode.setTitle(cell);
                break;
            case 5:
                nEpisode.setSeason(cell);
                break;
            case 6:
                nEpisode.setRating(cell);
                break;
            default:
                errores++;
                break;
            }
            campo++;
        }
        if (errores || campo != EPISODE_ATTRIB_SIZE) {
            cerr << "Error en la linea: " << endl << line << endl;
            file.close();

            return false;
        }

        if (size < arraySize) {
            episodeArray[size] = nEpisode;
            size++;
        }
        else {
            cerr << "Error, el arreglo es muy pequeño" << endl;
            file.close();
            return false;
        }
    }

    file.close();

    return true;
}