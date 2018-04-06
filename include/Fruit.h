#ifndef FRUIT_H
#define FRUIT_H

#pragma once
#include "GameObject.h"
#include <ctime>
#include <array>
#include <vector>
class Fruit :
	public GameObject
{
public:
	Fruit(int x, int y);
	~Fruit();

	void generateFruitPos(std::vector<std::vector<int>> &map);

private:
	int yFruit;
	int xFruit;
};

#endif //FRUIT
