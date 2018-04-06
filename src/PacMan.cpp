#include "PacMan.h"



PacMan::PacMan(int x, int y) : MovingObject(x, y, PACMAN, UP)
{
}


PacMan::~PacMan()
{
}

void PacMan::reset() {
	changePosition(14, 21);
	setDirection(UP);
	setType(PACMAN);
}

//PacMan move function which moves PacMan in the direction corresponding to the input of the player and check if it is allowed to move a certain direction
void PacMan::move(std::vector<std::vector<int>> &map) {
	int tempX = getX();
	int tempY = getY();
	if (getDirection() == LEFT) {
		tempX = tempX - 1;
		tempY = tempY;
		int sizeX = map[tempY].size();
		if ((tempX >= 0) && (map[tempY][tempX] == 0)) {
			changePosition(tempX, tempY);
		}
		else if ((tempX < 0) && (map[tempY][sizeX - 1] == 0)) {
			tempX = sizeX - 1;
			changePosition(tempX, tempY);
		}
	}
	else if (getDirection() == RIGHT) {
		tempX = tempX + 1;
		tempY = tempY;
		int sizeX = map[tempY].size();
		if ((tempX < sizeX) && (map[tempY][tempX] == 0)) {
			changePosition(tempX, tempY);
		}
		else if ((tempX == sizeX) && (map[tempY][0] == 0)) {
			tempX = 0;
			changePosition(tempX, tempY);
		}
	}
	else if (getDirection() == UP) {
		tempX = tempX;
		tempY = tempY - 1;
		int sizeY = map.size();
		if ((tempY >= 0) && (map[tempY][tempX] == 0)) {
			changePosition(tempX, tempY);
		}
		else if ((tempY < 0) && (map[sizeY - 1][tempX] == 0)) {
			tempY = sizeY - 1;
			changePosition(tempX, tempY);
		}
	}
	else if (getDirection() == DOWN) {
		tempX = tempX;
		tempY = tempY + 1;
		int sizeY = map.size();
		if ((tempY < sizeY) && (map[tempY][tempX] == 0)) {
			changePosition(tempX, tempY);
		}
		else if ((tempY == sizeY) && (map[tempY][0] == 0)) {
			tempY = 0;
			changePosition(tempX, tempY);
		}
	}
}
