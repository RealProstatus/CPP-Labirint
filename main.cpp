#include<iostream>
#include<fstream>
#include<conio.h>
#include"Model.h"
#include"Controller.h"

int main() {
	Hero mouse;
	Model game(mouse);
	Controller c(&game);

	ShowMap viewMap(cout);
	ShowHP viewHP(cout);
	ShowCoins viewCoins(cout);
	game.addNewObserver(&viewHP);
	game.addNewObserver(&viewCoins);
	game.addNewObserver(&viewMap);

	{
		ifstream file("maze.txt");
		game.inputMap(file);
	}

	c.start();
}