#pragma once
#include <iostream>
#include <string>
#include "Video.h"
using namespace std;

#define MOVIE_ATTRIB_SIZE 5


class Movie :public Video {
public:
	Movie() {
		ID = "";
		name = " ";
		duration = "";
		gender = " ";
		rating = "";
	}
	~Movie() {
	}
	bool loadMovieFromCSV(const string& fileName, Movie* movieArray, unsigned int arraySize);
};