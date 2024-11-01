#pragma once
#include <iostream>
#include "templates/template_doble_ligadas.h"
#include "monster.h"
using namespace std;

class Player {
private:

	string name;
	string race;
	int hp;
	int mp;
	Double_list<Monster> mounstrosDerrotados;

public:

	Player() {
		name = " ";
		race = " ";
		hp = 0;
		mp = 0;
	}

	Player(string name, string race, int hp, int mp) {
		this->name = name;
		this->race = race;
		this->hp = hp;
		this->mp = mp;
	}

	Player(string name, string race, int hp, int mp, Double_list<Monster> mounstrosDerrotados) {
		this->name = name;
		this->race = race;
		this->hp = hp;
		this->mp = mp;
		this->mounstrosDerrotados = mounstrosDerrotados;
	}

	~Player() {
	}

	void setName(string name) {
		this->name = name;
	}

	string getName() const {
		return name;
	}

	void setRace(string race) {
		this->race = race;
	}

	string getRace() const {
		return race;
	}

	void setHp(int hp) {
		this->hp = hp;
	}

	int getHp() const {
		return hp;
	}

	void setMp(int mp) {
		this->mp = mp;
	}

	int getMp() const {
		return mp;
	}

	void setMounstrosDerrotados(Double_list<Monster> mounstrosDerrotados) {
		this->mounstrosDerrotados = mounstrosDerrotados;
	}

	Double_list<Monster> getMounstrosDerrotados() const {
		return mounstrosDerrotados;
	}

	bool insertDerrotado(Monster* mounstro);
	void print();
};