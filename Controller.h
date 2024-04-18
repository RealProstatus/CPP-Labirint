#pragma once

#include<conio.h>
#include"Model.h"

class Controller {
	Model* model;
public:
	Controller(Model* _model):model(_model){}
	void start();
};
