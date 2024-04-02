#pragma once

#include"Cell.h"

class VoidCell :public Cell {
public:
	VoidCell();
	VoidCell(int _i, int _j);

	virtual Cell* copy();

	ostream& visit(ostream& output);
	bool canSetHero();

	virtual Cell* operator+(Hero& hero);
	virtual Cell* operator-(Hero& hero);
};
