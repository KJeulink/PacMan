#include "Ghost.h"



Ghost::Ghost(int x, int y, Type type, Direction dir) : MovingObject(x, y, type, dir)
{
	this->moving = false;
	this->prevX = x;
	this->prevY = y;
}


Ghost::~Ghost()
{
}

void Ghost::setPrevX(int x) {
	this->prevX = x;
}
void Ghost::setPrevY(int y) {
	this->prevY = y;
}

int Ghost::getPrevX() {
	return prevX;
}

int Ghost::getPrevY() {
	return prevY;
}

void Ghost::setMoving(bool moving) {
	this->moving = moving;
	setPosition(14, 11);
	this->prevX = 14;
	this->prevY = 11;
}

bool Ghost::isMoving() {
	return moving;
}
