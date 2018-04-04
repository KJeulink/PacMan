#ifndef PINKY_H
#define PINKY_H

#pragma once
#include "Ghost.h"
class Pinky :
	public Ghost
{
public:
	Pinky(int x, int y, Type ype, Direction dir);;
	~Pinky();
};

#endif //PINKY_H
