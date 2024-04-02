#include"Exit.h"

Exit::Exit() { i = j = -1; }
Exit::Exit(int _i, int _j) { i = _i; j = _j; }

Cell* Exit::copy() { return new Exit(); }

ostream& Exit::visit(ostream& output) { output << '0'; return output; }
bool Exit::canSetHero() { return true; }

Cell* Exit::operator+(Hero& hero) { throw "Victory!"; }
Cell* Exit::operator-(Hero& hero) { throw 1; }