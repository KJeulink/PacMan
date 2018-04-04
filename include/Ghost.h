#ifndef GHOST_H
#define GHOST_H

#pragma once
#include "MovingObject.h"
class Ghost :
	public MovingObject
{
public:
	Ghost(int x, int y, Type ype, Direction dir);
	virtual ~Ghost();
};

#endif //GHOST_H
