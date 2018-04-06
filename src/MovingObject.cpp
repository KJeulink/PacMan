#include "MovingObject.h"

MovingObject::MovingObject(int x, int y, Type type, Direction dir) : GameObject(x, y, type, dir) {
	this->prevX = x;
	this->prevY = y;
}


MovingObject::~MovingObject() {
}

void MovingObject::changePosition(int x, int y) {
	this->prevX = this->getX();
	this->prevY = this->getY();
	setPosition(x, y);
}

void MovingObject::setPrevX(int x) {
	this->prevX = x;
}

void MovingObject::setPrevY(int y) {
	this->prevY = y;
}

int MovingObject::getPrevX() {
	return prevX;
}

int MovingObject::getPrevY() {
	return prevY;
}
