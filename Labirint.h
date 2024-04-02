#pragma once

#include"Cell.h"
#include"VoidCell.h"
#include"Wall.h"
#include"Coin.h"
#include"HeroCell.h"
#include"Exit.h"

class Labirint {
	int height, width;
	Cell*** maze;
public:
	Labirint();//nullptr
	Labirint(int _height, int _width);
	Labirint(const Labirint& labirint);
	~Labirint();

	Cell* getCell(int i, int j);

	Labirint& operator=(const Labirint& labirint);
	friend istream& operator>>(istream& input, Labirint& labirint);
	friend ostream& operator<<(ostream& output, Labirint& labirint);

};
