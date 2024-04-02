#include"Coin.h"

Coin::Coin() { i = j = -1; }
Coin::Coin(int _i, int _j) { i = _i; j = _j; }

Cell* Coin::copy() { return new Coin(); }

ostream& Coin::visit(ostream& output) { output << '@'; return output; }
bool Coin::canSetHero() { return true; }

Cell* Coin::operator+(Hero& hero) { hero.addCoin(); return new HeroCell(this->i,this->j); }
Cell* Coin::operator-(Hero& hero) { return new VoidCell(this->i,this->j); }