#pragma once

#include<iostream>
#include"Hero.h"

using namespace std;

class Cell {
protected:
	int i, j;
public:
	int getI();
	int getJ();
	void setI(int new_i);
	void setJ(int new_j);//убрать и, ж и геттеры сеттеры

	virtual Cell* copy() = 0;

	virtual ostream& visit(ostream& output) = 0;
	virtual bool canSetHero() = 0;

	virtual Cell* operator+(Hero& hero) = 0;
	virtual Cell* operator-(Hero& hero) = 0;
};
