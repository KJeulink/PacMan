#include "Inky.h"
#include <iostream>

//implementation of other ghosts are almost the same as blinky, except for the random seed and time when movement is allowed.

Inky::Inky(int x, int y) : Ghost(x, y, INKY, UP)
{
}


Inky::~Inky()
{
}

void Inky::reset() {
	setPosition(14, 13);
	setPrevX(14);
	setPrevY(13);
	setType(INKY);
	setMoving(false);
}

void Inky::move(std::vector<std::vector<int>> &map) {
	std::vector<Direction> options = { LEFT, RIGHT, UP, DOWN };
	moveHelper(map, options);
}

void Inky::moveHelper(std::vector<std::vector<int>> &map, std::vector<Direction> options) {	
	int back_chance;
	if (options.size() == 0) {
		back_chance = 5;
		options = { LEFT, RIGHT, UP, DOWN };
	}
	else {
		std::srand(std::time(nullptr) + 9); // use current time as seed for random generator
		back_chance = std::rand() % 1 + 0;
	}
	std::srand(std::time(nullptr)); // use current time as seed for random generator
	int random_direction = std::rand() % options.size() + 1;
	random_direction = random_direction - 1;

	

	setDirection(options[random_direction]);

	int tempX = getX();
	int tempY = getY();
	if (getDirection() == LEFT) {
		tempX = tempX - 1;
		tempY = tempY;
		int sizeX = map[tempY].size();
		if (((getPrevX() == tempX) && (getPrevY() == tempY)) || ((getPrevX() == tempX) && (getPrevY() == tempY) && (back_chance != 5)) || ((tempY > 12) && (tempY < 14) && (tempX > 10) && (tempX < 17))) {
			options.erase(options.begin() + random_direction);
			moveHelper(map, options);
		}
		else {
			if ((tempX >= 0) && (map[tempY][tempX] == 0)) {
				setPrevX(getX());
				setPrevY(getY());
				changePosition(tempX, tempY);
			}
			else if ((tempX < 0) && (map[tempY][sizeX - 1] == 0)) {
				tempX = sizeX - 1;
				setPrevX(getX());
				setPrevY(getY());
				changePosition(tempX, tempY);
			}
			else {
				options.erase(options.begin() + random_direction);
				moveHelper(map, options);
			}
		}
	}
	else if (getDirection() == RIGHT) {
		tempX = tempX + 1;
		tempY = tempY;
		int sizeX = map[tempY].size();
		if (((getPrevX() == tempX) && (getPrevY() == tempY)) || ((getPrevX() == tempX) && (getPrevY() == tempY) && (back_chance != 5)) || ((tempY > 12) && (tempY < 14) && (tempX > 10) && (tempX < 17))) {
			options.erase(options.begin() + random_direction);
			moveHelper(map, options);
		}
		else {
			if ((tempX < sizeX) && (map[tempY][tempX] == 0)) {
				setPrevX(getX());
				setPrevY(getY());
				changePosition(tempX, tempY);
			}
			else if ((tempX == sizeX) && (map[tempY][0] == 0)) {
				tempX = 0;
				setPrevX(getX());
				setPrevY(getY());
				changePosition(tempX, tempY);
			}
			else {
				options.erase(options.begin() + random_direction);
				moveHelper(map, options);
			}
		}
	}
	else if (getDirection() == UP) {
		tempX = tempX;
		tempY = tempY - 1;
		int sizeY = map.size();
		if (((getPrevX() == tempX) && (getPrevY() == tempY)) || ((getPrevX() == tempX) && (getPrevY() == tempY) && (back_chance != 5)) || ((tempY > 12) && (tempY < 14) && (tempX > 10) && (tempX < 17))) {
			options.erase(options.begin() + random_direction);
			moveHelper(map, options);
		}
		else {
			if ((tempY >= 0) && (map[tempY][tempX] == 0)) {
				setPrevX(getX());
				setPrevY(getY());
				changePosition(tempX, tempY);
			}
			else if ((tempY < 0) && (map[sizeY - 1][tempX] == 0)) {
				tempY = sizeY - 1;
				setPrevX(getX());
				setPrevY(getY());
				changePosition(tempX, tempY);
			}
			else {
				options.erase(options.begin() + random_direction);
				moveHelper(map, options);
			}
		}
	}
	else if (getDirection() == DOWN) {
		tempX = tempX;
		tempY = tempY + 1;
		int sizeY = map.size();
		if (((getPrevX() == tempX) && (getPrevY() == tempY)) || ((getPrevX() == tempX) && (getPrevY() == tempY) && (back_chance != 5)) || ((tempY > 12) && (tempY < 14) && (tempX > 10) && (tempX < 17))) {
			options.erase(options.begin() + random_direction);
			moveHelper(map, options);
		}
		else {
			if ((tempY < sizeY) && (map[tempY][tempX] == 0)) {
				setPrevX(getX());
				setPrevY(getY());
				changePosition(tempX, tempY);
			}
			else if ((tempY == sizeY) && (map[tempY][0] == 0)) {
				tempY = 0;
				setPrevX(getX());
				setPrevY(getY());
				changePosition(tempX, tempY);
			}
			else {
				options.erase(options.begin() + random_direction);
				moveHelper(map, options);
			}
		}
	}
}
