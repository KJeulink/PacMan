#ifndef GHOST_H
#define GHOST_H

#pragma once
#include "MovingObject.h"

class Ghost :
	public MovingObject
{
	int prevX;
	int prevY;
	bool moving;
public:
	Ghost(int x, int y, Type type, Direction dir);
	virtual ~Ghost();

	void setPrevX(int x);
	void setPrevY(int y);
	void setMoving(bool moving);

	int getPrevX();
	int getPrevY();

	bool isMoving();
};


#endif //GHOST_H
