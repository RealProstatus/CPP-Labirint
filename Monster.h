#pragma once

#include"Cell.h"
#include"HeroCell.h"
#include"ERR_Exception.h"
#include"Coin.h"

class Monster :public Cell {
	int hp;
public:
	Monster();
	Monster(int _hp);

	inline int getHP();

	virtual Cell* copy();

	ostream& visit(ostream& output);
	bool canSetHero();

	virtual Cell* operator+(Hero& hero);
	virtual Cell* operator-(Hero& hero);
};
