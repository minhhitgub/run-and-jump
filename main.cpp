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
    Player player = { 300, LAVA_DEPTH - 500  , 0, 0, false };
    Lava lava = {LAVA_DEPTH, LAVA_SPEED, {0, 1200, SCREEN_WIDTH, 200}};


    while (running) {
        processInput(player, running);
        update(player, lava, camera);
        render(renderer, player, lava, camera);
        SDL_Delay(16.67);
    }

    destroy();
    return 0;
}

