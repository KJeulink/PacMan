#ifndef PACMAN_H
#define PACMAN_H

#pragma once
#include "MovingObject.h"
class PacMan :
	public MovingObject
{
public:
	PacMan(int x, int y);
	~PacMan();
};

#endif //PACMAN_H

