#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Movie.h"
#include "episode.h"
#include "FunctionLoad.h"

extern Movie* movieArray;
extern Episode* episodeArray;
extern int dataSize;
extern int dataSize2;

// Regresa -1 si hay un error al leer el archivo o regresa
// la cantidad de lineas de 0 a la cantidad de datos en el csv
int countDataLinesInCSV(const string& fileName) {
    ifstream    file(fileName);
    int         lineCount = 0;
    string      line;

    // Contar la cantidad de líneas en el archivo csv
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo: " << fileName << endl;
        return -1;
    }

    // skip header
    if (!getline(file, line)) {
        cerr << "El archivo no tiene header" << endl;
        file.close();
        return -1;
    }

    // Contar lineas 
    while (getline(file, line)) {
        lineCount++;
    }

    file.close();
    cout << lineCount;
    return(lineCount);
}

int FunctionLoad(string archivo) {
    if (archivo == "movies.csv") {
        cout << "Cargando archivos de datos de peliculas" << endl;

        dataSize = countDataLinesInCSV(MOVIES_FILE);
        if (dataSize == -1) {
            cerr << "No se pudo cargar el data set de " << MOVIES_FILE << "\n";
            return 0;
        }

        cout << MOVIES_FILE << " tiene: " << dataSize << " entradas\n";
        movieArray = new(nothrow) Movie[dataSize];
        if (movieArray == nullptr) {
            cerr << "No hubo memoria para el arreglo de " << MOVIES_FILE << "\n";
            return 0;
        }

        Movie tempMovie;
        if (!tempMovie.loadMovieFromCSV(MOVIES_FILE, movieArray, dataSize)) {
            delete[] movieArray;
            return 0;
        }

        cout << "Mostrando el dato " << "1" << " del arreglo:\n";
        movieArray[0].print();
    }
    else if (archivo == "series.csv") {
        cout << "Cargando archivos de datos de series" << endl;

        dataSize2 = countDataLinesInCSV(SERIES_FILE);
        if (dataSize2 == -1) {
            cerr << "No se pudo cargar el data set de " << SERIES_FILE << "\n";
            return 0;
        }

        cout << SERIES_FILE << " tiene: " << dataSize2 << " entradas\n";
        episodeArray = new(nothrow) Episode[dataSize2];
        if (episodeArray == nullptr) {
            cerr << "No hubo memoria para el arreglo de " << SERIES_FILE << "\n";
            return 0;
        }

        Episode tempEpisode;
        if (!tempEpisode.loadEpisodeFromCSV(SERIES_FILE, episodeArray, dataSize2)) {
            delete[] episodeArray;
            return 0;
        }

        cout << "Mostrando el dato " << "1" << " del arreglo:\n";
        episodeArray[0].print();
    }
    return 0;
};