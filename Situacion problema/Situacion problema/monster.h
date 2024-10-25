#pragma once
#include <iostream>
using namespace std;

class Monster {
private:

	string name;
	float cr;
	string type;
	string size;
	int armor;
	int hp;
	string align;

public:

	Monster() {
		name = " ";
		cr = 0;
		type = " ";
		size = " ";
		armor = 0;
		hp = 0;
		align = " ";
	}

	Monster(string name, float cr, string type, string size, int armor, int hp, string align) {
		this->name = name;
		this->cr = cr;
		this->type = type;
		this->size = size;
		this->armor = armor;
		this->hp = hp;
		this->align = align;
	}

	~Monster() {
	}
	
	void setName(string name);
	void setCr(float cr);
	void setType(string type);
	void setSize(string size);
	void setArmor(int armor);
	void setHp(int hp);
	void setAlign(string align);
	string getName() const;
	float getCr() const;
	string getType() const;
	string getSize() const;
	int getArmor() const;
	int getHp() const;
	string getAlign() const;
	bool operator<(const Monster& other) const;
	bool operator>(const Monster& other) const;
	friend ostream& operator<<(ostream& os, const Monster& monster);

};