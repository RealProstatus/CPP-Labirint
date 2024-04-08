#pragma once

#include<iostream>
using namespace std;

class ERR_Exception {
public:
	virtual void show() = 0;
};



class ERR_Victory :public ERR_Exception {
public:
	void show() { cout << endl << "Victory!" << endl; }
};

class ERR_StepInWall : public ERR_Exception {
public:
	void show() { cout << endl << "Ouch!"; }
};

class ERR_HPZero : public ERR_Exception {
public:
	void show() { cout << endl << "Defeat!" << endl; }
};

class ERR_Exit : public ERR_Exception {
public:
	void show() { cout << endl << "You need to collect 3 coins to exit!"<<endl<<"Tap to continue..."; }
};

class ERR_StepInMonster : public ERR_Exception {
	void show() { cout << endl << "Ouch!"; }
};

class ERR_Unexpected :public ERR_Exception {
public:
	void show() { cout << endl << "WORK IN PROGRESS"; }
};
