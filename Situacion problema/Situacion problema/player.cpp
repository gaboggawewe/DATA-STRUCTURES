#include "player.h"

bool Player::insertDerrotado(Monster* mounstro) {
	return (mounstrosDerrotados.insertInOrder(*mounstro));
}

void Player::print() {
	cout << "Los mounstros derrotados por el jugador " << name << " son:" << endl;
	mounstrosDerrotados.printListaBeg();
}