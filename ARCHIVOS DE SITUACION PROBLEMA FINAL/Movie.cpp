#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Movie.h"
using namespace std;

bool Movie::loadMovieFromCSV(const string& fileName, Movie* movieArray, unsigned int arraySize) {
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
        Movie         nMovie;
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
                nMovie.setID(cell);
                break;
            case 1:
                nMovie.setName(cell);
                break;
            case 2:
                nMovie.setDuration(cell);
                break;
            case 3:
                nMovie.setGender(cell);
                break;
            case 4:
                nMovie.setRating(cell);
                break;
            default:
                errores++;
                break;
            }
            campo++;
        }
        if (errores || campo != MOVIE_ATTRIB_SIZE) {
            cerr << "Error en la linea: " << endl << line << endl;
            file.close();

            return false;
        }

        if (size < arraySize) {
            movieArray[size] = nMovie;
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
};