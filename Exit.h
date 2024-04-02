#pragma once

#include"Cell.h"

class Exit :public Cell {
public:
	Exit();
	Exit(int _i, int _j);

	virtual Cell* copy();

	virtual ostream& visit(ostream& output);
	virtual bool canSetHero();

	virtual Cell* operator+(Hero& hero);
	virtual Cell* operator-(Hero& hero);
};