#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Movie.h"
#include "Episode.h"
#include "FunctionLoad.h"


Movie* movieArray = nullptr;
Episode* episodeArray = nullptr;
int dataSize = 0;
int dataSize2 = 0;
int main() {
    int menu = 1;
    while (menu < 6) {
        cout << "Menu\n";
        cout << "1. Cargar archivo de datos(ver mas abajo, te proporcionamos un ejemplo del codigo)" << endl;
        cout << "2. Mostrar los textos de los videos en general con una cierta calificacion o de un cierto genero" << endl;
        cout << "3. Mostrar los episodios de una determinada serie con una calificacion determinada" << endl;
        cout << "4. Mostrar las peliculas con cierta calificacion" << endl;
        cout << "5. Calificar un video" << endl;
        cout << "0. Salir" << endl;
        cin >> menu;
        string calificacion;
        string eleccion;
        string nombre;
        switch (menu) {
        case 0:
            cout << "Ha salido" << endl;
            return 0;
            break;
        case 1:
        {
            FunctionLoad(MOVIES_FILE);
            FunctionLoad(SERIES_FILE);
            break;

        }
        case 2:
        {
            cout << "Mostrar los textos de los videos en general con una cierta calificacion o de un cierto genero" << endl;
            cout << "¿Desea filtrar por calificacion ('c') o por genero ('g') ? " << endl;
            cin >> eleccion;
            if (eleccion == "c") {
                cout << "Ingrese la calificacion:" << endl;
                cin >> calificacion;
                cout << "Los videos con la calificacion " << calificacion << " son los siguientes:" << endl;
                for (int i = 0; i < dataSize; i++) {
                    if (movieArray[i].getRating() == calificacion) {
                        movieArray[i].print();
                    }
                }
                for (int i = 0; i < dataSize2; i++) {
                    if (episodeArray[i].getRating() == calificacion) {
                        episodeArray[i].print();
                    }
                }
            }
            else if (eleccion == "g") {
                cout << "Ingrese el genero: " << endl;
                string genero;
                cin >> genero;
                for (int i = 0; i < dataSize; i++)
                    if (movieArray[i].getGender() == genero) {
                        movieArray[i].print();
                    }
                for (int i = 0; i < dataSize2; i++)
                    if (episodeArray[i].getGender() == genero) {
                        episodeArray[i].print();
                    }
            }
            else {
                cout << "Eleccion no valida."<<endl;
            }
            break;
        }
        case 3:
        {
            cout << "3. Mostrar los episodios de una determinada serie con una calificacion determinada" << endl;
            cout << "Elija la serie que desea: ";
            string serie_elegida;
            cin.ignore();
            getline(cin, serie_elegida);
            cout << "Ingrese la calificacion deseada: ";
            cin >> calificacion;
            for (int i = 0; i < dataSize2; i++) {
                if (serie_elegida == episodeArray[i].getName()) {
                    if (calificacion == episodeArray[i].getRating()) {
                        episodeArray[i].print();
                    }
                }
            }
            break;
        }
        case 4:
            cout << "4. Mostrar las peliculas con cierta calificacion" << endl;
            cout << "Ingrese la calificacion deseada: ";
            cin >> calificacion;
            for (int i = 0; i < dataSize; i++) {
                if (calificacion == movieArray[i].getRating()) {
                    movieArray[i].print();
                }
            }
            break;
        case 5:
        {
            cout << "5. Calificar un video" << endl;
            cout << "¿Desea calificar una pelicula(p) o una serie(s)?" << endl;
            cin >> eleccion;
            if (eleccion == "p") {
                cout << "¿Cual es el nombre de la pelicula que desea calificar? ";
                cin.ignore();
                getline(cin, nombre);
                cout << "¿Cual es la calificacion que desea asignarle? ";
                cin >> calificacion;
                for (int i = 0; i < dataSize; i++) {
                    if (nombre == movieArray[i].getName()) {
                        movieArray[i].setRating(calificacion);
                    }
                }
            }
            else if (eleccion == "s") {
                cout << "¿Cual es el nombre de la serie en donde esta el capitulo que desea calificar? ";
                cin.ignore();
                getline(cin, nombre);
                cout << "¿De que temporada es? ";
                string temporada;
                cin >> temporada;
                cout << "¿Cual es el titulo del capitulo? ";
                string titulo;
                cin.ignore();
                getline(cin, titulo);
                cout << "¿Cual es la calificacion que desea asignarle al capitulo? ";
                cin >> calificacion;
                for (int i = 0; i < dataSize2; i++) {
                    if (nombre == episodeArray[i].getName()) {
                        if (temporada == episodeArray[i].getSeason()) {
                            if (titulo == episodeArray[i].getTitle()) {
                                episodeArray[i].setRating(calificacion);
                            }
                        }
                    }
                }
            }
            else {
                cout << "Eleccion no valida." << endl;
            }
            break;
        }


        }
    }
    delete[] movieArray;
    delete[] episodeArray;
};

