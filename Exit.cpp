#include"Exit.h"

Exit::Exit() { ; }

Cell* Exit::copy() { return new Exit(); }

ostream& Exit::visit(ostream& output) { output << '0'; return output; }
bool Exit::canSetHero() { return true; }

Cell* Exit::operator+(Hero& hero) {
	if (hero.getCoins() >= 3) throw ERR_Victory();
	else throw ERR_Exit();
}
Cell* Exit::operator-(Hero& hero) { return new Exit(); }