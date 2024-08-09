#include <SDL.h>
#include <stdio.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <vector>
#include "headers/functions.hpp"
#include "headers/constants.hpp"
#include "headers/load.hpp"

int main(int argc, char* argv[])
 {
    Load();
    SDL_Rect camera = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
    Player player = { 300, 10 , 0, 0, false };
    Lava lava = {1600, LAVA_SPEED, {0, 1600, SCREEN_WIDTH, 10}};


    while (running) {
        processInput(player, running);
        update(player, lava, camera);
        render(renderer, player, lava, camera);
        SDL_Delay(16.67);
    }

    destroy();
    return 0;
}

