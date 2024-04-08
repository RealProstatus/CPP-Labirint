#pragma once

#include"ERR_Exception.h"

class Hero {
	int i, j, coins, hp;
public:
	Hero();

	int getI();
	int getJ();
	int getHP();
	void setI(int new_i);
	void setJ(int new_j);
	int getCoins();

	void subHP();
	void addCoin();
};
