#ifndef PACMAN_H
#define PACMAN_H

#pragma once
#include "MovingObject.h"
#include <vector>

class PacMan :
	public MovingObject
{
public:
	PacMan(int x, int y);
	~PacMan();

	void reset();

	void move(std::vector<std::vector<int>> &map);
};

#endif //PACMAN_H

