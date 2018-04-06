#ifndef BLINKY_H
#define BLINKY_H

#pragma once
#include "Ghost.h"
#include <vector>
#include <ctime>

class Blinky :
	public Ghost
{
public:
	Blinky(int x, int y);
	~Blinky();

	void move(std::vector<std::vector<int>> &map);
	void moveHelper(std::vector<std::vector<int>> &map, std::vector<Direction> options);
};

#endif //BLINKY_H
