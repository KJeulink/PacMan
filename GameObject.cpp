/// \file
/// GameObject.h

/*
*  Created on: Jan 30, 2015
*      Author: frits
*       Group: TA's
*/
#include "GameObject.h"

void GameObject::setPosition(int x, int y) {
	this->x = x;
	this->y = y;
}

void GameObject::setType(Type type) {
	this->type = type;
}

void GameObject::setDirection(Direction dir) {
	this->dir = dir;
}

int GameObject::getX() {
	return this->x;
}
int GameObject::getY() {
	return this->y;
}
Type GameObject::getType() {
	return this->type;
}
Direction GameObject::getDirection() {
	return this->dir;
}