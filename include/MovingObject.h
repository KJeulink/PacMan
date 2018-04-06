#ifndef MOVINGBJECT_H
#define MOVINGOBJECT_H

#pragma once
#include "GameObject.h"

class MovingObject : public GameObject {
public:
	MovingObject(int x, int y, Type type, Direction dir);
	virtual ~MovingObject();
};

#endif //MOVINGOBJECT_H
