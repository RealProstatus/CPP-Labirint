#include"VoidCell.h"
#include"HeroCell.h"

VoidCell::VoidCell() { ; }

Cell* VoidCell::copy() { return new VoidCell(); }

ostream& VoidCell::visit(ostream& output) { output << ' '; return output; }
bool VoidCell::canSetHero() { return true; }

Cell* VoidCell::operator+(Hero& hero) { return new HeroCell(); }
Cell* VoidCell::operator-(Hero& hero) { return this; }