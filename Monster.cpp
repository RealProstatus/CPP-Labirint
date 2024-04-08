#include"Monster.h"

Monster::Monster() { hp = -1; }
Monster::Monster(int _hp) { hp = _hp; }

inline int Monster::getHP() { return hp; }

Cell* Monster::copy() { return new Monster(hp); }

ostream& Monster::visit(ostream& output) {
	output << hp; return output; 
}
bool Monster::canSetHero() { return false; }

Cell* Monster::operator+(Hero& hero) {
	if (hero.getHP() == 1) {
		throw ERR_HPZero();
	}
	if (hp == 1) {
		hero.subHP();
		hp--;
		hero.addCoin();
		return new HeroCell();
	}
	else {
		hp--;
		throw ERR_StepInMonster();
	}	
}
Cell* Monster::operator-(Hero& hero) { return new Coin(); }