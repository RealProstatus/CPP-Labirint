#include"Wall.h"

Wall::Wall() { ; }

Cell* Wall::copy() { return new Wall(); }

ostream& Wall::visit(ostream& output) { output << '#'; return output; }
bool Wall::canSetHero() { return false; }

Cell* Wall::operator+(Hero& hero) { throw ERR_StepInWall(); }
Cell* Wall::operator-(Hero& hero) { return new Wall(); }