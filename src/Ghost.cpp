#include "Ghost.h"

Ghost::Ghost(int x, int y, Type type, Direction dir) : MovingObject(x, y, type, dir)
{
	this->moving = false;
}


Ghost::~Ghost()
{
}

void Ghost::setMoving(bool moving) {
	this->moving = moving;
	if (moving) {
		setPosition(14, 11);
		setPrevX(14);
		setPrevY(11);
	}
}

bool Ghost::isMoving() {
	return moving;
}
