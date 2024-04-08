#include"Hero.h"

Hero::Hero() {
	i = j = 1;
	coins = 0;
	hp = 10;
}

int Hero::getI() { return i; }
int Hero::getJ() { return j; }
int Hero::getHP(){ return hp; }
void Hero::setI(int new_i) { i = new_i; }
void Hero::setJ(int new_j) { j = new_j; }
int Hero::getCoins() { return coins; }

void Hero::subHP() {
	if (hp == 1) {
		throw ERR_HPZero();
	}
	hp--;
}
void Hero::addCoin() { coins++; }