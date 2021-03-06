#include "Blinky.h"

//implementation of other ghosts are almost the same as blinky, except for the random seed and time when movement is allowed.


//constructor of blinky
Blinky::Blinky(int x, int y) : Ghost(x, y, BLINKY, UP)
{
}


Blinky::~Blinky()
{
}
//reset function blinky (reset position and movement allowence)
void Blinky::reset() {
	setPosition(15, 13);
	setPrevX(15);
	setPrevY(13);
	setType(BLINKY);
	setMoving(false);
}
//move function of blinky
void Blinky::move(std::vector<std::vector<int>> &map) {
	std::vector<Direction> options = { LEFT, RIGHT, UP, DOWN };
	moveHelper(map, options);
}
//actually moves blinky
void Blinky::moveHelper(std::vector<std::vector<int>> &map, std::vector<Direction> options) {
	int back_chance;
	if (options.size() == 0) {
		back_chance = 5;
		options = { LEFT, RIGHT, UP, DOWN };
	}
	else {
		std::srand(std::time(nullptr)); // use current time as seed for random generator
		back_chance = std::rand() % 9 + 0;
	}
	std::srand(std::time(nullptr) + 999); // use current time as seed for random generator
	int random_direction = std::rand() % options.size() + 1;
	random_direction = random_direction - 1;


	//uses random direction to set direction
	setDirection(options[random_direction]);

	int tempX = getX();
	int tempY = getY();
	//check if going to left is possible
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
	//check if going to right is possible
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
	//check if going to up is possible
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
	//check if going to down is possible
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