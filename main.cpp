
#include "headers/functions.hpp"
#include "headers/constants.hpp"
#include "headers/load.hpp"
#include "headers/player.hpp"
#include "headers/object.hpp"




int main(int argc, char* argv[])
 {
    Load();
    current_gStatus = PLAY;
    lava.vy = 0;

    Player player;
    Object object;


    while (running) {
            while (SDL_PollEvent(&g_even))
        {
            processInput(g_even);
            player.processInput(g_even);

        }

    if (checkPause) {
            showHealth();
         SDL_Color white = { 255, 255, 255, 255 };
        SDL_Texture* menuText = loadTextTexture("PAUSED", white);
        SDL_Rect textRect = { 800, 450, 500, 300 };
        SDL_RenderCopy(renderer, menuText, NULL, &textRect);
        SDL_DestroyTexture(menuText);
        SDL_RenderPresent(renderer);
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
    time++;
    if (time>50)
    {
        hitRecently = false;
    }



    player.processInput(g_even);
    player.render();
    player.update();



    object.render();
    object.update();





    SDL_SetRenderDrawColor(renderer, 255, 69, 0, 255);
    SDL_Rect lavaRect = {0, SCREEN_HEIGHT - lava.rect.h, SCREEN_WIDTH, lava.rect.h};
    SDL_RenderFillRect(renderer, &lavaRect);

    showHealth();
    SDL_RenderPresent(renderer);
    SDL_Delay(16.67);
}
}
    destroy();
    return 0;

 }

