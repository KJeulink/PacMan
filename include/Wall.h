#ifndef WALL_H
#define WALL_H

#pragma once
#include "GameObject.h"
class Wall :
	public GameObject
{
public:
	Wall(int x, int y);
	~Wall();
};

#endif //WALL_H
