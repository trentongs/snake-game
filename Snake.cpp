#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <iomanip>
#include "Mouse.h"
#include "Snake.h"
using namespace std;

int nTail;  
char letter;

Snake::Snake(int w, int h) :Mouse(w, h) //inheritance
{
	nTail = 0; //this fixed restart issue
	w = width;
	h = height;

	Setup();

	while (!gameOver)
	{
		Draw();
		Input();
		Logic();
		Sleep(100); //sleep(10);
	}

	if (gameOver == true)
	{
		cout << "\nDo you want to restart? (Y/N)\n\n";
		do {
			letter = cin.get();
			letter = toupper(letter);
		} while ((letter != 'Y') && (letter != 'N'));
		if (letter == 'Y')
		{
			Snake(w, h);	
		}
		else if (letter == 'N')
		{
			cout << "Exiting game...\n";
		}
	}
}

void Snake::Setup()
{
	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	score = 0;
	getMouse();
}

void Snake::Draw()
{
	system("cls");  //system("clear");
	for (int i = 0; i < width + 2; i++)
		cout << "#";
	cout << endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0)
				cout << "#";
			if (i == y && j == x)
				cout << "0";
			else if (i == mouseY && j == mouseX)
				cout << "M";
			else
			{
				bool print = false;
				for (int k = 0; k < nTail; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						cout << "o";
						print = true;
					}
				}
				if (!print)
					cout << " ";
			}

			if (j == width - 1)
				cout << "#";
		}
		cout << endl;
	}

	for (int i = 0; i < width + 2; i++)
		cout << "#";
	cout << endl;
	cout << "Score:" << score << endl;
}

void Snake::Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'x':
			gameOver = true;
			cout << "\nGAME OVER\n";
			break;
		}
	}
}

void Snake::Logic()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < nTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}

	//Game over when snake hits a wall/boundary
	if (x > width || x < 0 || y > height || y < 0)
	{
		gameOver = true;
		cout << "\nGAME OVER\n";
			 
	}

	//Game over when snake hits itself
	for (int i = 0; i < nTail; i++)
		if (tailX[i] == x && tailY[i] == y)
		{
			gameOver = true;
			cout << "\nGAME OVER\n";
		}

	//Increase score and new mouse appears on board when snake eats mouse
	if (x == mouseX && y == mouseY)
	{
		score += 10;
		getMouse();
		nTail++;
	}

}