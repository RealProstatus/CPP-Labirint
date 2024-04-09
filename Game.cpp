#include"Game.h"

Game::Game(Hero& hero) :main_hero(hero) { map = Labirint(); }

Game::Game(const Game& game) :main_hero(game.main_hero) { map = Labirint(game.map); }
	
void Game::cinputMap() { this->finputMap(cin); }
void Game::finputMap(istream& input) { input >> map; }

void Game::move(ACTIONS act) {
	int ip = main_hero.getI();
	int jp = main_hero.getJ();
	switch (act) {
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
	}
	catch (ERR_StepInWall) { main_hero.subHP(); }
	catch (ERR_StepInMonster) { main_hero.subHP(); }
	catch (ERR_Unexpected exc) { exc.show(); }
}
void Game::update(ostream& output) {
	system("cls");
	output << "HP: " << main_hero.getHP() << endl;
	output << "Coins: " << main_hero.getCoins()<<endl;
	output << endl << map;
}