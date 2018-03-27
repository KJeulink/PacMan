/// \file
/// GameObject.h

/*
 *  Created on: Jan 30, 2015
 *      Author: frits
 *       Group: TA's
 */

#ifndef SRC_GAMEOBJECT_H
#define SRC_GAMEOBJECT_H

/// These enum values denote the sprite sets available for items on screen.
enum Type {
    PACMAN,
    BLINKY,
    PINKY,
    INKY,
    CLYDE,
    SCARED,
    SCAREDINV,
    CHERRY,
    STRAWBERRY,
    ORANGE,
    LEMON,
    APPEL,
    GRAPES,
    DOT,
    ENERGIZER,
    WALL,
    ZERO,
    ONE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE
};

/// An enum to denote the direction of an item on screen.
enum Direction { UP, DOWN, LEFT, RIGHT };

/// This represents an item that is drawn onto the screen.
class GameObject {
    /// x-position of the item.
    int x;
    /// y-position of the item.
    int y;
    /// The appearance of the item (sprite set).
    Type type;
    /// The direction of the item (sprite selection).
    Direction dir;

public:
	void setPosition(int x, int y);
	void setType(Type type);
	void setDirection(Direction dir);

	int getX();
	int getY();
	Type getType();
	Direction getDirection();
};

#endif // SRC_GAMEOBJECT_H
