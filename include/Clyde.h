#ifndef CLYDE_H
#define CLYDE_H
#pragma once
#include "Ghost.h"
class Clyde :
	public Ghost
{
public:
	Clyde(int x, int y, Type ype, Direction dir);;
	~Clyde();
};

#endif //CLYDE_H
