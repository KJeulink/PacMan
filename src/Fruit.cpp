#include "Fruit.h"



Fruit::Fruit(int x, int y) : GameObject(x, y, CHERRY, UP)
{
}


Fruit::~Fruit()
{
}

void Fruit::generateFruitPos(std::vector<std::vector<int>> &map) {
	//std::srand(std::time(nullptr)); // use current time as seed for random generator
	//yFruit = std::rand() % map.size() + 0;
	//xFruit = std::rand() % map[yFruit].size() + 0;
	//no fruit in spawn area of ghost
	std::srand(std::time(nullptr)); // use current time as seed for random generator
	while (1) {

		yFruit = std::rand() % map.size() + 0;
		xFruit = std::rand() % map[yFruit].size() + 0;
		if ((map[yFruit][xFruit] == 1) || (((yFruit > 11) && (yFruit < 15)) && ((xFruit > 9) && (xFruit < 18)))) {
			//generateFruitPos(map);
		}
		else {
			setPosition(xFruit, yFruit);
			break;
		}
	}
}
