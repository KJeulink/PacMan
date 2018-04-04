#ifndef INKY_H
#define INKY_H

#pragma once
#include "Ghost.h"
class Inky :
	public Ghost
{
public:
	Inky(int x, int y, Type ype, Direction dir);;
	~Inky();
};

#endif //INKY_H
