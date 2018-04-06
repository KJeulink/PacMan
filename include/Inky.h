#ifndef INKY_H
#define INKY_H

#pragma once
#include "Ghost.h"
#include <vector>
#include <ctime>

class Inky :
	public Ghost
{
public:
	Inky(int x, int y);;
	~Inky();

	void move(std::vector<std::vector<int>> &map);
};

#endif //INKY_H
