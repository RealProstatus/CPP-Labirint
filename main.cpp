#include<iostream>
#include<fstream>
#include<conio.h>
#include"Game.h"

int main() {
	Hero mouse;
	Game game(mouse);
	{
		ifstream file("maze.txt");
		game.finputMap(file);
	}
	game.update(cout);
	
	unsigned int val = 0;
	val = _getch();
	while (val != 27) {
		val = _getch();
		if (val == 224) val = _getch();
		switch (val) {
		case 80:
			game.move(DOWN);
			game.update(cout);
			break;
		case 72:
			game.move(UP);
			game.update(cout);
			break;

		case 75:
			game.move(LEFT);
			game.update(cout);
			break;
		case 77:
			game.move(RIGHT);
			game.update(cout);
			break;

		default:
			break;
		}
	}
}