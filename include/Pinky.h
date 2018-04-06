#ifndef PINKY_H
#define PINKY_H

#pragma once
#include "Ghost.h"
#include <vector>
#include <ctime>
class Pinky :
	public Ghost
{
public:
	Pinky(int x, int y);
	~Pinky();

	void reset();

	void move(std::vector<std::vector<int>> &map);
	void moveHelper(std::vector<std::vector<int>> &map, std::vector<Direction> options);
};

#endif //PINKY_H
