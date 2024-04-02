#pragma once

#include"Cell.h"
#include"VoidCell.h"

class HeroCell :public Cell {
public:
	HeroCell();
	HeroCell(int _i, int _j);

	virtual Cell* copy();

	virtual ostream& visit(ostream& output);
	virtual bool canSetHero();

	virtual Cell* operator+(Hero& hero);
	virtual Cell* operator-(Hero& hero);
};
