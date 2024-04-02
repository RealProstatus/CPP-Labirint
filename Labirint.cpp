#include"Labirint.h"

Labirint::Labirint() { height = width = 0; maze = nullptr; }
Labirint::Labirint(int _height, int _width) {
	height = _height;
	width = _width;
	maze = new Cell * *[height];
	for (int i = 0; i < height; i++) {
		maze[i] = new Cell * [width];
	}
}
Labirint::Labirint(const Labirint& labirint) {
	height = labirint.height;
	width = labirint.width;
	maze = new Cell **[height];
	for (int i = 0; i < height; i++) {
		for (int j=0;j<width;j++)
			maze[i][j] = labirint.maze[i][j]->copy();
	}
}


Labirint::~Labirint() {
	for (int i = 0; i < height; i++) {
		delete[] maze[i];
	}
	delete[] maze;
}

Cell* Labirint::getCell(int i, int j) { return maze[i][j]; }
//возвращать ссылку на €чейку, a не тройной указатель


Labirint& Labirint::operator=(const Labirint& labirint) {
	if (this == &labirint) return *this;

	for (int i = 0; i < height; i++) {
		delete[] maze[i];
	}
	delete[] maze;
	height = labirint.height;
	width = labirint.width;
	maze = new Cell * *[height];
	for (int i = 0; i < height; i++) {
		maze[i] = new Cell * [width];
		for (int j = 0; j < width; j++) {
			maze[i][j] = labirint.maze[i][j]->copy();
		}
	}
}
istream& operator>>(istream& input, Labirint& labirint) {
	input >> labirint.height;
	input >> labirint.width;
	input.ignore();
	labirint.maze = new Cell * *[labirint.height];
	for (int i = 0; i < labirint.height; i++) {
		labirint.maze[i] = new Cell * [labirint.width];
	}

	for (int i = 0; i < labirint.height; i++) {
		for (int j = 0; j < labirint.width; j++) {
			char tmp;
			input >> noskipws >> tmp;
			switch (tmp) {
			case ' ':
				labirint.maze[i][j] = new VoidCell(i, j);
				break;
			case '#':
				labirint.maze[i][j] = new Wall(i, j);
				break;
			case '@':
				labirint.maze[i][j] = new Coin(i, j);
				break;
			case '0':
				labirint.maze[i][j] = new Exit(i, j);
				break;
			case 'R':
				labirint.maze[i][j] = new HeroCell(i, j);
				break;
			default:
				break;
			}
		}
		input.ignore();
	}
	return input;
}
ostream& operator<<(ostream& output, Labirint& labirint) {
	for (int i = 0; i < labirint.height; i++) {
		for (int j = 0; j < labirint.width; j++) {
			labirint.maze[i][j]->visit(output);
		}
		output << endl;
	}

	return output;
}