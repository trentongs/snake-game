#pragma once
#ifndef SNAKE_H
#define SNAKE_H

#include "Mouse.h"

class Snake :public Mouse  //Derived class
{

public:
	Snake(int, int);
	void Setup();
	void Draw();
	void Input();
	void Logic();
	bool gameOver;

private:
	int x, y, score;
	int tailX[100], tailY[100];
	enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
	eDirection dir;
};

#endif