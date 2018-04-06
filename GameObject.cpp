/// \file
/// GameObject.h

/*
*  Created on: Jan 30, 2015
*      Author: frits
*       Group: TA's
*/
#include "GameObject.h"

GameObject::~GameObject() {
}

//constructor of gameobject
GameObject::GameObject(int x, int y, Type type, Direction dir) {
	this->x = x;
	this->y = y;
	this->type = type;
	this->dir = dir;
}

//position function
void GameObject::setPosition(int x, int y) {
	this->x = x;
	this->y = y;
}
//type function
void GameObject::setType(Type type) {
	this->type = type;
}
//direction function
void GameObject::setDirection(Direction dir) {
	this->dir = dir;
}
//get x function
int GameObject::getX() {
	return this->x;
}
//get y function
int GameObject::getY() {
	return this->y;
}
//get type function
Type GameObject::getType() {
	return this->type;
}
//get direction function
Direction GameObject::getDirection() {
	return this->dir;
}