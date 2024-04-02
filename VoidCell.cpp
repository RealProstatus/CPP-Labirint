#include"VoidCell.h"
#include"HeroCell.h"

VoidCell::VoidCell() { i = j = -1; }
VoidCell::VoidCell(int _i, int _j) { i = _i; j = _j; }

Cell* VoidCell::copy() { return new VoidCell(); }

ostream& VoidCell::visit(ostream& output) { output << ' '; return output; }
bool VoidCell::canSetHero() { return true; }

Cell* VoidCell::operator+(Hero& hero) { return new HeroCell(this->i, this->j); }
Cell* VoidCell::operator-(Hero& hero) { return this; }