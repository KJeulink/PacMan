#ifndef GHOSTPENDOOR_H
#define GHOSTPENDOOR_H

#pragma once
#include "Wall.h"
class GhostPenDoor :
	public Wall
{
public:
	GhostPenDoor(int x, int y);
	~GhostPenDoor();
};

#endif //GHOSTPENDOOR_H
