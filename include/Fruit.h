#ifndef FRUIT_H
#define FRUIT_H

#pragma once
#include "GameObject.h"
class Fruit :
	public GameObject
{
public:
	Fruit(int x, int y);
	~Fruit();
};

#endif //FRUIT
