#include "Blinky.h"



Blinky::Blinky(int x, int y) : Ghost(x, y, BLINKY, UP)
{
}


Blinky::~Blinky()
{
}

void Blinky::move(std::vector<std::vector<int>> &map) {
	std::srand(std::time(nullptr)); // use current time as seed for random generator
	int random_variable = std::rand();

	int tempX = getX();
	int tempY = getY();
	if (getDirection() == LEFT) {
		tempX = tempX - 1;
		tempY = tempY;
		int sizeX = map[tempY].size();
		if ((tempX >= 0) && (map[tempY][tempX] == 0)) {
			setPosition(tempX, tempY);
		}
		else if ((tempX < 0) && (map[tempY][sizeX - 1] == 0)) {
			tempX = sizeX - 1;
			setPosition(tempX, tempY);
		}
	}
	else if (getDirection() == RIGHT) {
		tempX = tempX + 1;
		tempY = tempY;
		int sizeX = map[tempY].size();
		if ((tempX < sizeX) && (map[tempY][tempX] == 0)) {
			setPosition(tempX, tempY);
		}
		else if ((tempX == sizeX) && (map[tempY][0] == 0)) {
			tempX = 0;
			setPosition(tempX, tempY);
		}
	}
	else if (getDirection() == UP) {
		tempX = tempX;
		tempY = tempY - 1;
		int sizeY = map.size();
		if ((tempY >= 0) && (map[tempY][tempX] == 0)) {
			setPosition(tempX, tempY);
		}
		else if ((tempY < 0) && (map[sizeY - 1][tempX] == 0)) {
			tempY = sizeY - 1;
			setPosition(tempX, tempY);
		}
	}
	else if (getDirection() == DOWN) {
		tempX = tempX;
		tempY = tempY + 1;
		int sizeY = map.size();
		if ((tempY < sizeY) && (map[tempY][tempX] == 0)) {
			setPosition(tempX, tempY);
		}
		else if ((tempY == sizeY) && (map[tempY][0] == 0)) {
			tempY = 0;
			setPosition(tempX, tempY);
		}
	}
}
