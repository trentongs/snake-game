#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Snake.h"
using namespace std;

int main()
{
	Snake board(20, 20);
	board.Setup();
	return 0;
}