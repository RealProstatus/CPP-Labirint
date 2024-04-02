#include"HeroCell.h"

HeroCell::HeroCell() { i = j = -1; }
HeroCell::HeroCell(int _i, int _j) { i = _i; j = _j; }

Cell* HeroCell::copy() { return new HeroCell(); }

ostream& HeroCell::visit(ostream& output) { output << 'R'; return output; }
bool HeroCell::canSetHero() { return false; }

Cell* HeroCell::operator+(Hero& hero) { throw 1; }
Cell* HeroCell::operator-(Hero& hero) { return new VoidCell(this->i, this->j); }