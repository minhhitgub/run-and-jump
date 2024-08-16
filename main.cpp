
#include "headers/functions.hpp"
#include "headers/constants.hpp"
#include "headers/load.hpp"
#include "headers/player.hpp"
#include "headers/object.hpp"




int main(int argc, char* argv[])
 {

    Load();


    Player player;
    Object object;




    while (running) {
            while (SDL_PollEvent(&g_even))
        {
            player.processInput(g_even);
        }


            if (checkPause) {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 128);
    SDL_Rect pauseOverlay = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
    SDL_RenderFillRect(renderer, &pauseOverlay);
    SDL_Delay(16.67);
    }



else{
    lava.y -= lava.vy;
    lava.rect.y = lava.y;

    camera.y = lava.y + lava.rect.h - SCREEN_HEIGHT;
    if (camera.y < 0) camera.y = 0;


    frame++;
    if (frame > 300){
        frame = 0;
    }




    SDL_Texture* currentBackground = backgroundTexture[frame/30 % 4];
    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, currentBackground, NULL, NULL);


    player.processInput(g_even);
    player.render();
    player.update();


    object.render();
    object.update();


    SDL_SetRenderDrawColor(renderer, 255, 69, 0, 255);
    SDL_Rect lavaRect = {0, SCREEN_HEIGHT - lava.rect.h, SCREEN_WIDTH, lava.rect.h};
    SDL_RenderFillRect(renderer, &lavaRect);


    SDL_RenderPresent(renderer);
    SDL_Delay(16.67);
}
}
    destroy();
    return 0;

 }

