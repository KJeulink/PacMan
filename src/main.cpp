/// \file
/// main.cpp

/*
 *  Created on: Jan 29, 2015
 *      Author: frits
 *       Group: TA's
 */

#include "GameObject.h"
#include "UI.h"
#include <SDL2/SDL.h>
#include <vector>
#include "PacMan.h"
#include "Dots.h"
#include "Inky.h"
#include "Blinky.h"
#include "Clyde.h"
#include "Pinky.h"
#include "Fruit.h"

/// Callback function to update the game state.
///
/// This function is called by an SDL timer at regular intervals.
Uint32 gameUpdate(Uint32 interval, void * /*param*/)
{
    // Do game loop update here
    return interval;
}

//setting up a 3D vector for all objects
std::vector<GameObject> getStructs(std::vector<std::vector<std::vector<GameObject*>>> &objects) {
	std::vector<GameObject> structs = {};
	std::vector<GameObject> ghosts = {};
	std::vector<GameObject> fruits = {};
	std::vector<GameObject> pacman = {};
	for (auto rows : objects) {
		for (auto columns : rows) {
			for (auto object : columns) {
				if ((object->getType() == INKY) || (object->getType() == BLINKY) || (object->getType() == PINKY) || (object->getType() == CLYDE)) {
					ghosts.push_back(*object);
				}
				else if (object->getType() == CHERRY) {
					fruits.push_back(*object);
				}
				else if (object->getType() == PACMAN) {
					pacman.push_back(*object);
				}
				else {
					structs.push_back(*object);
				}
			}
		}
	}
	structs.insert(std::end(structs), std::begin(fruits), std::end(fruits));
	structs.insert(std::end(structs), std::begin(ghosts), std::end(ghosts));
	structs.insert(std::end(structs), std::begin(pacman), std::end(pacman));
	return structs;
}

/// Program entry point.
int main(int /*argc*/, char ** /*argv*/)
{
    std::vector<std::vector<int>> map = {{
        #include "board.def"
    }};

    // Create a new ui object
    UI ui(map); // <-- use map from your game objects.

    // Start timer for game update, call this function every 100 ms.
    SDL_TimerID timer_id =
        SDL_AddTimer(100, gameUpdate, static_cast<void *>(nullptr));

	//initialize gameObjects vector of map
	std::vector<std::vector<std::vector<GameObject*>>> objects(
		map[0].size(),
		std::vector<std::vector<GameObject*>>(map.size()));

    // Creating objects and put them in the right place
    PacMan pacman(14, 21);

	Inky inky(14, 13);
	Pinky pinky(13, 13);
	Clyde clyde(12, 13);
	Blinky blinky(15, 13);

	// Call game init code here
	// Placing dots in the map only on the paths and not in the middle
	for (int y = 0; y < map.size(); y++) {
		for (int x = 0; x < map[y].size(); x++) {
			if (((y == 13) && (x < 6)) || ((y == 13) && (x > 21))) {

			}
			else if (((y > 8) && (y < 18)) && ((x > 6) && (x < 21))) {

			}
			else {
				if (map[y][x] == 0) {
					Dots* dot = new Dots(x, y);
					objects[x][y].push_back(dot);
				}
			}
		}
	}

	unsigned int score = 0;
	//init flag if already fruit is placed
	bool fruitPlaced = false;
	unsigned int lives = 3;

	//Always render Pacman And Ghosts last
	objects[pacman.getX()][pacman.getY()].push_back(&pacman);

	objects[inky.getX()][inky.getY()].push_back(&inky);
	objects[pinky.getX()][pinky.getY()].push_back(&pinky);
	objects[blinky.getX()][blinky.getY()].push_back(&blinky);
	objects[clyde.getX()][clyde.getY()].push_back(&clyde);

	int counter = 0;
	bool ghostOnPrevPos = false;

    bool quit = false;
    while (!quit) {
        // set timeout to limit frame rate
        Uint32 timeout = SDL_GetTicks() + 200;

        // Handle the input
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            // Quit button.
            if (e.type == SDL_QUIT) {
                quit = true;
            }
			
            // All keydown events
            if (e.type == SDL_KEYDOWN) {
				switch (e.key.keysym.sym) {
					case SDLK_LEFT: 
						pacman.setDirection(LEFT);
						break;
					case SDLK_RIGHT:
						pacman.setDirection(RIGHT);
						break;
					case SDLK_UP:
						pacman.setDirection(UP);
						break;
					case SDLK_DOWN: 
						pacman.setDirection(DOWN);
						break;
					case SDLK_ESCAPE:
						quit = true;
						break;
					}
            }
        }

		//Move Ghosts
		if (!clyde.isMoving()) {
			counter = counter + 1;
		}
		if ((counter > 0) && !inky.isMoving()) {
			inky.setMoving(true);
		}
		if (inky.isMoving()) {
			inky.move(map);
			objects[inky.getX()][inky.getY()].push_back(&inky);
			for (size_t x = 0; x < objects[inky.getPrevX()][inky.getPrevY()].size(); x++) {
				Type type = objects[inky.getPrevX()][inky.getPrevY()][x]->getType();
				if (type == INKY) {
					objects[inky.getPrevX()][inky.getPrevY()].erase(objects[inky.getPrevX()][inky.getPrevY()].begin() + x);
				}
			}
		}

		if ((counter > 20) && !blinky.isMoving()) {
			blinky.setMoving(true);
		}
		if (blinky.isMoving()) {
			blinky.move(map);
			objects[blinky.getX()][blinky.getY()].push_back(&blinky);
			for (size_t x = 0; x < objects[blinky.getPrevX()][blinky.getPrevY()].size(); x++) {
				Type type = objects[blinky.getPrevX()][blinky.getPrevY()][x]->getType();
				if (type == BLINKY) {
					objects[blinky.getPrevX()][blinky.getPrevY()].erase(objects[blinky.getPrevX()][blinky.getPrevY()].begin() + x);
				}
			}
		}

		if ((counter > 40) && !pinky.isMoving()) {
			pinky.setMoving(true);
		}
		if (pinky.isMoving()) {
			pinky.move(map);
			objects[pinky.getX()][pinky.getY()].push_back(&pinky);
			for (size_t x = 0; x < objects[pinky.getPrevX()][pinky.getPrevY()].size(); x++) {
				Type type = objects[pinky.getPrevX()][pinky.getPrevY()][x]->getType();
				if (type == PINKY) {
					objects[pinky.getPrevX()][pinky.getPrevY()].erase(objects[pinky.getPrevX()][pinky.getPrevY()].begin() + x);
				}
			}
		}

		if ((counter > 60) && !clyde.isMoving()) {
			clyde.setMoving(true);
		}
		if (clyde.isMoving()) {
			clyde.move(map);
			objects[clyde.getX()][clyde.getY()].push_back(&clyde);
			for (size_t x = 0; x < objects[clyde.getPrevX()][clyde.getPrevY()].size(); x++) {
				Type type = objects[clyde.getPrevX()][clyde.getPrevY()][x]->getType();
				if (type == CLYDE) {
					objects[clyde.getPrevX()][clyde.getPrevY()].erase(objects[clyde.getPrevX()][clyde.getPrevY()].begin() + x);
				}
			}
		}


		//move PacMan
		pacman.move(map);

		if ((inky.getX() == pacman.getX()) && (inky.getY() == pacman.getY()) || (blinky.getX() == pacman.getX()) && (blinky.getY() == pacman.getY())
				
			|| (pinky.getX() == pacman.getX()) && (pinky.getY() == pacman.getY()) || (clyde.getX() == pacman.getX()) && (clyde.getY() == pacman.getY())
			
			|| ((inky.getPrevX() == pacman.getX()) && (inky.getPrevY() == pacman.getY()) && (inky.getX() == pacman.getPrevX()) && (inky.getY() == pacman.getPrevY()))
			
			|| ((blinky.getPrevX() == pacman.getX()) && (blinky.getPrevY() == pacman.getY()) && (blinky.getX() == pacman.getPrevX()) && (blinky.getY() == pacman.getPrevY()))
			
			|| ((pinky.getPrevX() == pacman.getX()) && (pinky.getPrevY() == pacman.getY()) && (pinky.getX() == pacman.getPrevX()) && (pinky.getY() == pacman.getPrevY()))
			
			|| ((clyde.getPrevX() == pacman.getX()) && (clyde.getPrevY() == pacman.getY()) && (clyde.getX() == pacman.getPrevX()) && (clyde.getY() == pacman.getPrevY()))
			
			) {
			ui.update(getStructs(objects));
			if (lives > 0) {
				lives = lives - 1;
				counter = 0;
				for (size_t x = 0; x < objects[inky.getPrevX()][inky.getPrevY()].size(); x++) {
					Type type = objects[inky.getPrevX()][inky.getPrevY()][x]->getType();
					if (type == INKY) {
						objects[inky.getPrevX()][inky.getPrevY()].erase(objects[inky.getPrevX()][inky.getPrevY()].begin() + x);
					}
				}
				for (size_t x = 0; x < objects[blinky.getPrevX()][blinky.getPrevY()].size(); x++) {
					Type type = objects[blinky.getPrevX()][blinky.getPrevY()][x]->getType();
					if (type == BLINKY) {
						objects[blinky.getPrevX()][blinky.getPrevY()].erase(objects[blinky.getPrevX()][blinky.getPrevY()].begin() + x);
					}
				}
				for (size_t x = 0; x < objects[pinky.getPrevX()][pinky.getPrevY()].size(); x++) {
					Type type = objects[pinky.getPrevX()][pinky.getPrevY()][x]->getType();
					if (type == PINKY) {
						objects[pinky.getPrevX()][pinky.getPrevY()].erase(objects[pinky.getPrevX()][pinky.getPrevY()].begin() + x);
					}
				}
				for (size_t x = 0; x < objects[clyde.getPrevX()][clyde.getPrevY()].size(); x++) {
					Type type = objects[clyde.getPrevX()][clyde.getPrevY()][x]->getType();
					if (type == CLYDE) {
						objects[clyde.getPrevX()][clyde.getPrevY()].erase(objects[clyde.getPrevX()][clyde.getPrevY()].begin() + x);
					}
				}
				pacman.reset();
				inky.reset();
				pinky.reset();
				blinky.reset();
				clyde.reset();
				objects[inky.getX()][inky.getY()].push_back(&inky);
				objects[blinky.getX()][blinky.getY()].push_back(&blinky);
				objects[pinky.getX()][pinky.getY()].push_back(&pinky);
				objects[clyde.getX()][clyde.getY()].push_back(&clyde);
				ui.update(getStructs(objects));
			}
			else {
				quit = true;
			}
		}

		//pacman interacting with dots and fruit using the 3D vector map.
		for (size_t x = 0; x < objects[pacman.getX()][pacman.getY()].size(); x++) {
			Type type = objects[pacman.getX()][pacman.getY()][x]->getType();
			if (type == DOT) {
				delete objects[pacman.getX()][pacman.getY()][x];
				objects[pacman.getX()][pacman.getY()].erase(objects[pacman.getX()][pacman.getY()].begin() + x);
				score = score + 10;
				x--;
			}
			else if (type == CHERRY) {
				delete objects[pacman.getX()][pacman.getY()][x];
				objects[pacman.getX()][pacman.getY()].erase(objects[pacman.getX()][pacman.getY()].begin() + x);
				score = score + 200;
				fruitPlaced = false;
				x--;
			}
		}

		// Placing fruit in the map at random position after certain score is reached.
		if (((score % 200) == 0) && !fruitPlaced) {
			Fruit* fruit = new Fruit(0, 0);
			fruit->generateFruitPos(map);
			objects[fruit->getX()][fruit->getY()].push_back(fruit);
			fruitPlaced = true;
		}


        // Set the score
        ui.setScore(score);

        // Set the amount of lives
        ui.setLives(lives); // <-- Pass correct value to the setter

        // Render the scene
        ui.update(getStructs(objects));

        while (!SDL_TICKS_PASSED(SDL_GetTicks(), timeout)) {
            // ... do work until timeout has elapsed
        }
    }

    SDL_RemoveTimer(timer_id);

    return 0;
}
