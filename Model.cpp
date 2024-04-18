#include"Model.h"

Model::Model(Hero hero) {
	map = Labirint();
	main_hero = hero;
}

int Model::getHP() { return main_hero.getHP(); }
int Model::getCoins() { return main_hero.getCoins(); }
void Model::outputMap(ostream& out) { out << map; }
void Model::inputMap(istream& inp) { inp >> map; }

void Model::move(ACTIONS act) {
	int ip = main_hero.getI();
	int jp = main_hero.getJ();
	switch (act)
	{
	case UP:
		ip--;
		break;
	case RIGHT:
		jp++;
		break;
	case DOWN:
		ip++;
		break;
	case LEFT:
		jp--;
		break;
	default:
		break;
	}
	try {
		Cell* tmp = map.getCell(ip, jp);
		map.getCell(ip, jp) = *tmp + main_hero;
		delete tmp;
		Cell* t = map.getCell(main_hero.getI(), main_hero.getJ());
		map.getCell(main_hero.getI(), main_hero.getJ()) = *t - main_hero;
		delete t;
		main_hero.setI(ip);
		main_hero.setJ(jp);
		eventAllObservers();
	}
	catch (ERR_StepInWall) { main_hero.subHP(); eventAllObservers(); }
	catch (ERR_StepInMonster) { main_hero.subHP(); eventAllObservers(); }
	catch (ERR_Unexpected exc) { exc.show(); }
}