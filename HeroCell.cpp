#include"HeroCell.h"

HeroCell::HeroCell() { ; }

Cell* HeroCell::copy() { return new HeroCell(); }

ostream& HeroCell::visit(ostream& output) { output << 'R'; return output; }
bool HeroCell::canSetHero() { return false; }

Cell* HeroCell::operator+(Hero& hero) { return new HeroCell(); }
Cell* HeroCell::operator-(Hero& hero) { return new VoidCell(); }