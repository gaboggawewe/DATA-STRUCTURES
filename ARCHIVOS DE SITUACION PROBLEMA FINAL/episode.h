#pragma once

#include "Video.h"
#include <iostream>
#include <string>
using namespace std;

#define EPISODE_ATTRIB_SIZE 7


class Episode : public Video {
public:
	Episode() {
		ID = "";
		name = " ";
		duration = "";
		gender = " ";
		rating = "";
		season = "";
		title = "";
	}
	~Episode() {
	}
	void setSeason(string season);
	void setTitle(string title);
	string getSeason();
	string getTitle();
	void print() override;
	bool loadEpisodeFromCSV(const string& fileName, Episode* videoArray, unsigned int arraySize);

private:
	string title;
	string season;
};