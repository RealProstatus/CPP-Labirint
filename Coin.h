#pragma once

#include"Cell.h"
#include"HeroCell.h"
#include"VoidCell.h"

class Coin :public Cell {
public:
	Coin();

	virtual Cell* copy();

	virtual ostream& visit(ostream& output);
	virtual bool canSetHero();

	virtual Cell* operator+(Hero& hero);
	virtual Cell* operator-(Hero& hero);
};