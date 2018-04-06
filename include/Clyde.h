#ifndef CLYDE_H
#define CLYDE_H
#pragma once
#include "Ghost.h"
#include <vector>
#include <ctime>
class Clyde :
	public Ghost
{
public:
	Clyde(int x, int y);;
	~Clyde();

	void move(std::vector<std::vector<int>> &map);
};

#endif //CLYDE_H
