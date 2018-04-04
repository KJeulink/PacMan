#ifndef BLINKY_H
#define BLINKY_H

#pragma once
#include "Ghost.h"
class Blinky :
	public Ghost
{
public:
	Blinky(int x, int y, Type ype, Direction dir);;
	~Blinky();
};

#endif //BLINKY_H
