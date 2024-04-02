#include"Hero.h"

Hero::Hero() {
	i = j = 1;
	coins = 0;
	hp = 5;
}

int Hero::getI() { return i; }
int Hero::getJ() { return j; }
void Hero::setI(int new_i) { i = new_i; }
void Hero::setJ(int new_j) { j = new_j; }
int Hero::getCoins() { return coins; }

void Hero::addCoin() { coins++; }