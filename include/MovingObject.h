#ifndef MOVINGBJECT_H
#define MOVINGOBJECT_H

#pragma once
#include "GameObject.h"

class MovingObject : public GameObject {
	int prevX = 0;
	int prevY = 0;
public:
	MovingObject(int x, int y, Type type, Direction dir);
	virtual ~MovingObject();

	void setPrevX(int x);
	void setPrevY(int y);

	void changePosition(int x, int y);

	int getPrevX();
	int getPrevY();
};

#endif //MOVINGOBJECT_H
