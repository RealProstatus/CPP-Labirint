#pragma once

#include"Cell.h"

class Wall :public Cell {
public:
	Wall();

	virtual Cell* copy();

	virtual ostream& visit(ostream& output);
	virtual bool canSetHero();

	virtual Cell* operator+(Hero& hero);
	virtual Cell* operator-(Hero& hero);
};