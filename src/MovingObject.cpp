#include "MovingObject.h"


//constructor of movingObject
MovingObject::MovingObject(int x, int y, Type type, Direction dir) : GameObject(x, y, type, dir) {
	this->prevX = x;
	this->prevY = y;
}


MovingObject::~MovingObject() {
}

//function to change position
void MovingObject::changePosition(int x, int y) {
	this->prevX = this->getX();
	this->prevY = this->getY();
	setPosition(x, y);
}

//function to set previous x position
void MovingObject::setPrevX(int x) {
	this->prevX = x;
}
//function to set previous y position
void MovingObject::setPrevY(int y) {
	this->prevY = y;
}

//function to get previous x position
int MovingObject::getPrevX() {
	return prevX;
}
//function to get previous y position
int MovingObject::getPrevY() {
	return prevY;
}
