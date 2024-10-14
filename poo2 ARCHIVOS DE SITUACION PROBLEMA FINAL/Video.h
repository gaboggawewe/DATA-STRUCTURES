#pragma once
#include <iostream>
#include <string>
using namespace std;


#define VIDEO_ATTRIB_SIZE 5

class Video {
public:
	Video() {
		ID = "0";
		name = " ";
		duration = "0";
		gender = " ";
		rating = "";
	}
	~Video() {
	}
	void setID(string ID);
	void setName(string name);
	void setDuration(string duration);
	void setGender(string gender);
	void setRating(string rating);
	string getRating();
	string getGender();
	string getName();
	virtual void print();

protected:
	string ID;
	string name;
	string duration;
	string gender;
	string rating;
};