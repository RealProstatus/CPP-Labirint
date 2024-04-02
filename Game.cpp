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
	try {//все в одом трае
		Cell* t = map.getCell(main_hero.getI(), main_hero.getJ());
		map.getMaze()[main_hero.getI()][main_hero.getJ()] = *t - main_hero;
		delete t;
		Cell* t = map.getCell(ip,jp);
		map.getCell(ip,jp) = *t + main_hero;
		delete t;
	}
	catch (int exception) {;}
	catch (string exception) { cout << exception; }
	main_hero.setI(ip);
	main_hero.setJ(jp);
}
void Game::update(ostream& output) {
	system("cls");
	output << "Coins: " << main_hero.getCoins()<<endl;
	output << map;
}