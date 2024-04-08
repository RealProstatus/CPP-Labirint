#pragma once

#include"ERR_Exception.h"
#include"Labirint.h"
#include"Hero.h"

enum ACTIONS {
	UP,
	RIGHT,
	DOWN,
	LEFT
};

class Game {
	Labirint map;
	Hero& main_hero;
public:
	Game(Hero& hero);
	Game(const Game& game);

	void cinputMap();
	void finputMap(istream& input);

	void move(ACTIONS act);
	void update(ostream& output);
};