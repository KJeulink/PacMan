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

	void move(std::vector<std::vector<int>> &map);
};

#endif //PINKY_H
