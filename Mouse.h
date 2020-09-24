#pragma once
#ifndef MOUSE_H
#define MOUSE_H

class Mouse  //Base class
{
public:
	Mouse(int, int);
	void getMouse();
	int mouseX, mouseY;

protected:
	int width;
	int height;

};

#endif