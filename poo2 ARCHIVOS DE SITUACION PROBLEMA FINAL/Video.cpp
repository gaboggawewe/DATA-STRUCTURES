#include <iostream>
#include <fstream>
#include <sstream>
#include "Video.h"
using namespace std;


void Video::setID(string ID) {
    this->ID = ID;
}
void Video::setName(string name) {
    this->name = name;
}
void Video::setDuration(string duration) {
    this->duration = duration;
}
void Video::setGender(string gender) {
    this->gender = gender;
}
void Video::setRating(string rating) {
    this->rating = rating;
}
string Video::getRating() {
    return rating;
}
string Video::getGender() {
    return gender;
}
string Video::getName() {
    return name;
}
void Video::print() {
    cout << "ID: " << ID << endl;
    cout << "Name: " << name << endl;
    cout << "Duration: " << duration << endl;
    cout << "Gender: " << gender << endl;
    cout << "Rating: " << rating << endl;
}