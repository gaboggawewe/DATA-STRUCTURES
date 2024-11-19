#include "monster.h"


void Monster::setName(string name) {
    this->name = name;
}

void Monster::setCr(float cr) {
    this->cr = cr;
}

void Monster::setType(string type) {
    this->type = type;
}

void Monster::setSize(string size) {
    this->size = size;
}

void Monster::setArmor(int armor) {
    this->armor = armor;
}

void Monster::setHp(int hp) {
    this->hp = hp;
}

void Monster::setAlign(string align) {
    this->align = align;
}

string Monster::getName() const {
    return name;
}

float Monster::getCr() const {
    return cr;
}

string Monster::getType() const {
    return type;
}

string Monster::getSize() const {
    return size;
}

int Monster::getArmor() const {
    return armor;
}

int Monster::getHp() const {
    return hp;
}

string Monster::getAlign() const {
    return align;
}

bool Monster::operator<(const Monster& other) const {
    return this->name < other.name;
}

bool Monster::operator>(const Monster& other) const {
    return this->name > other.name;   
}

ostream& operator<<(ostream& os, const Monster& monster) {
    os << "Name: " << monster.name;
    return os;
}