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

/// Callback function to update the game state.
///
/// This function is called by an SDL timer at regular intervals.
Uint32 gameUpdate(Uint32 interval, void * /*param*/)
{
    // Do game loop update here
    return interval;
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
    PacMan pacman(1, 1);

    // Call game init code here

	for (int y = 0; y < map.size(); y++) {
		for (int x = 0; x < map[y].size(); x++) {
			if ((y == 13) && ((x == 6) || (x == 21))) {
				if (map.at(y).at(x) == 0) {
					Dots dot(x, y);
				}
			}
			else if ((y < 8) || (y > 17) && ((x < 8) || (x > 17))) {
				if (map[y][x] == 0) {
					Dots dot(x, y);
				}
			}
			else {
				if (map[y][x] == 0) {
					Dots dot(x, y);
				}
			}
		}
	}

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
			int tempX = 0;
			int tempY = 0;
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
					}
            }

			if (pacman.getDirection() == LEFT) {
				tempX = pacman.getX() - 1;
				tempY = pacman.getY();
				if ((tempX >= 0) && (map[tempY][tempX] == 0)) {
					pacman.setPosition(tempX, tempY);
				}
				else if ((tempX < 0) && (map[tempY][map[tempY].size() - 1] == 0)) {
					pacman.setPosition(map[tempY].size() - 1, tempY);
				}
			}
			else if (pacman.getDirection() == RIGHT) {
				tempX = pacman.getX() + 1;
				tempY = pacman.getY();
				if ((tempX < map[tempY].size()) && (map[tempY][tempX] == 0)) {
					pacman.setPosition(tempX, tempY);
				}
				else if ((tempX == map[tempY].size()) && (map[tempY][0] == 0)) {
					pacman.setPosition(0, tempY);
				}
			}
			else if (pacman.getDirection() == UP) {
				tempX = pacman.getX();
				tempY = pacman.getY() - 1;
				if ((tempY >= 0) && (map[tempY][tempX] == 0)) {
					pacman.setPosition(tempX, tempY);
				}
				else if ((tempY < 0) && (map[map.size() - 1][tempX] == 0)) {
					pacman.setPosition(tempX, map.size() - 1);
				}
			}
			else if (pacman.getDirection() == DOWN) {
				tempX = pacman.getX();
				tempY = pacman.getY() + 1;
				if ((tempY < map.size()) && (map[tempY][tempX] == 0)) {
					pacman.setPosition(tempX, tempY);
				}
				else if ((tempY == map.size()) && (map[tempY][0] == 0)) {
					pacman.setPosition(tempX, 0);
				}
			}
        }

        // Set the score
        ui.setScore(12345); // <-- Pass correct value to the setter

        // Set the amount of lives
        ui.setLives(3); // <-- Pass correct value to the setter

        // Render the scene
        std::vector<GameObject> objects = {pacman};
        // ^-- Your code should provide this vector somehow (e.g.
        // game->getStructs())
        ui.update(objects);

        while (!SDL_TICKS_PASSED(SDL_GetTicks(), timeout)) {
            // ... do work until timeout has elapsed
        }
    }

    SDL_RemoveTimer(timer_id);

    return 0;
}
