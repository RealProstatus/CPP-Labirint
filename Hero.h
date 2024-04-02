#pragma once

class Hero {
	int i, j, coins, hp;
public:
	Hero();

	int getI();
	int getJ();
	void setI(int new_i);
	void setJ(int new_j);
	int getCoins();

	void addCoin();
};
