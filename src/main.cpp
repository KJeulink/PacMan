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

std::vector<GameObject> getStructs(std::vector<std::vector<std::vector<GameObject*>>> &objects) {
	std::vector<GameObject> structs = {};
	for (auto rows : objects) {
		for (auto columns : rows) {
			for (auto object : columns) {
				structs.push_back(*object);
			}
		}
	}
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

    // Example object, this can be removed later
    PacMan pacman(14, 21);

	Inky inky(14, 13);
	Pinky pinky(13, 13);
	Clyde clyde(12, 13);
	Blinky blinky(15, 13);


	//initialize gameObjects vector of map
	std::vector<std::vector<std::vector<GameObject*>>> objects(
		map[0].size(),
		std::vector<std::vector<GameObject*>>(map.size()));

    // Call game init code here
	// Placing dots in the map
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
	bool fruitPlaced = false;

	//Always render Pacman And Ghosts last
	objects[pacman.getX()][pacman.getY()].push_back(&pacman);

	objects[inky.getX()][inky.getY()].push_back(&inky);
	objects[pinky.getX()][pinky.getY()].push_back(&pinky);
	objects[blinky.getX()][blinky.getY()].push_back(&blinky);
	objects[clyde.getX()][clyde.getY()].push_back(&clyde);

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
					case SDLK_LEFT: // YOUR CODE HERE
						pacman.setDirection(LEFT);
						break;
					case SDLK_RIGHT: // YOUR CODE HERE
						pacman.setDirection(RIGHT);
						break;
					case SDLK_UP: // YOUR CODE HERE
						pacman.setDirection(UP);
						break;
					case SDLK_DOWN: // YOUR CODE HERE
						pacman.setDirection(DOWN);
						break;
					case SDLK_ESCAPE:
						quit = true;
						break;
					}
            }
        }
		//PacMan* pacman = objects[0][0];
		pacman.move(map);

		for (size_t x = 0; x < objects[pacman.getX()][pacman.getY()].size(); x++) {
			if (objects[pacman.getX()][pacman.getY()][x]->getType() == DOT) {
				delete objects[pacman.getX()][pacman.getY()][x];
				objects[pacman.getX()][pacman.getY()].erase(objects[pacman.getX()][pacman.getY()].begin() + x);
				score = score + 10;
			}
			else if (objects[pacman.getX()][pacman.getY()][x]->getType() == CHERRY) {
				delete objects[pacman.getX()][pacman.getY()][x];
				objects[pacman.getX()][pacman.getY()].erase(objects[pacman.getX()][pacman.getY()].begin() + x);
				score = score + 200;
				fruitPlaced = false;
			}
		}

		inky.move(map);


		// Placing fruit in the map at random position after certain score
		if (((score % 200) == 0) && !fruitPlaced) {
			Fruit* fruit = new Fruit(0, 0);
			fruit->generateFruitPos(map);
			objects[fruit->getX()][fruit->getY()].push_back(fruit);
			fruitPlaced = true;
		}

        // Set the score
        ui.setScore(score); // <-- Pass correct value to the setter

        // Set the amount of lives
        ui.setLives(3); // <-- Pass correct value to the setter

        // Render the scene
        //std::vector<GameObject> objects = {pacman};
        // ^-- Your code should provide this vector somehow (e.g.
        // game->getStructs())
        ui.update(getStructs(objects));

        while (!SDL_TICKS_PASSED(SDL_GetTicks(), timeout)) {
            // ... do work until timeout has elapsed
        }
    }

    SDL_RemoveTimer(timer_id);

    return 0;
}
