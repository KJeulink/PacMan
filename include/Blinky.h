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
};

#endif //BLINKY_H
