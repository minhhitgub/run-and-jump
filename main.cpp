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

    Player player = { 100, GROUND , 0, 0, false };
    bool running = true;

    Load();

    while (running) {
        processInput(player, running);
        update(player);
        render(renderer, backgroundTexture , player);
        SDL_Delay(16.67);
    }

    destroy();
    return 0;
}

