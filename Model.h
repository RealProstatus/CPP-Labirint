#pragma once

#include<vector>
#include"Labirint.h"
#include"Hero.h"

using namespace std;

enum ACTIONS {
	UP,
	RIGHT,
	DOWN,
	LEFT
};

class Model;

class Observer {
public:
	virtual void ivent(Model& model) = 0;
};

class Model {
	Labirint map;
	Hero main_hero;

	vector<Observer*> allObservers;

	void eventAllObservers() { system("cls"); for (Observer* o : allObservers) o->ivent(*this); }
public:
	Model(Hero hero);

	void start() { eventAllObservers(); }

	int getHP();
	int getCoins();
	void outputMap(ostream& out);
	void inputMap(istream& inp);

	void move(ACTIONS act);

	void addNewObserver(Observer* o) { allObservers.push_back(o); }
};

class ShowMap :public Observer {
	ostream& out;
public:
	ShowMap(ostream& _out) :out(_out) {}
	void ivent(Model& model) { model.outputMap(out); }// вывод лабиринта в острим
};
class ShowHP :public Observer {
	ostream& out;
public:
	ShowHP(ostream& _out) :out(_out) {}
	void ivent(Model& model) {out<<"HP: "<<model.getHP()<<endl; }// вывод хп в острим
};
class ShowCoins :public Observer {
	ostream& out;
public:
	ShowCoins(ostream& _out) :out(_out) {}
	void ivent(Model& model) { out<<"Coins: "<<model.getCoins()<<endl; }// вывод кол-ва монет в острим
};