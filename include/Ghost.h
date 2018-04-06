#ifndef GHOST_H
#define GHOST_H

#pragma once
#include "MovingObject.h"

class Ghost :
	public MovingObject
{
	bool moving;
public:
	Ghost(int x, int y, Type type, Direction dir);
	virtual ~Ghost();

	void setMoving(bool moving);

	bool isMoving();
};


#endif //GHOST_H
