#pragma once

#include<iostream>
#include"Hero.h"
#include"ERR_Exception.h"

using namespace std;

class Cell {
public:
	virtual Cell* copy() = 0;

	virtual ostream& visit(ostream& output) = 0;
	virtual bool canSetHero() = 0;

	virtual Cell* operator+(Hero& hero) = 0;
	virtual Cell* operator-(Hero& hero) = 0;
};
