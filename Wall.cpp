#include"Wall.h"

Wall::Wall() { i = j = -1; }
Wall::Wall(int _i, int _j){ i = _i; j = _j; }

Cell* Wall::copy() { return new Wall(); }

ostream& Wall::visit(ostream& output) { output << '#'; return output; }
bool Wall::canSetHero() { return false; }

Cell* Wall::operator+(Hero& hero) { throw 1; }
Cell* Wall::operator-(Hero& hero) { return new Wall(i, j); }