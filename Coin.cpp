#include"Coin.h"

Coin::Coin() { ; }

Cell* Coin::copy() { return new Coin(); }

ostream& Coin::visit(ostream& output) { output << '@'; return output; }
bool Coin::canSetHero() { return true; }

Cell* Coin::operator+(Hero& hero) { hero.addCoin(); return new HeroCell(); }
Cell* Coin::operator-(Hero& hero) { return new VoidCell(); }