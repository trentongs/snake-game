#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Mouse.h"
#include <iomanip>
using namespace std;

Mouse::Mouse(int w, int h)
{
	width = w;
	height = h;
}


void Mouse::getMouse()   //function that randomizes coordinates of Mouse
{
	mouseX = rand() % width;
	mouseY = rand() % height;
}