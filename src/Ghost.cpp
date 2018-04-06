#include "Ghost.h"


//constructor of ghosts
Ghost::Ghost(int x, int y, Type type, Direction dir) : MovingObject(x, y, type, dir)
{
	this->moving = false;
}


Ghost::~Ghost()
{
}

//move function of ghosts
void Ghost::setMoving(bool moving) {
	this->moving = moving;
	if (moving) {
		setPosition(14, 11);
		setPrevX(14);
		setPrevY(11);
	}
}

//boolean if ghost is moving
bool Ghost::isMoving() {
	return moving;
}
