
#include "headers/functions.hpp"
#include "headers/constants.hpp"
#include "headers/load.hpp"
#include "headers/player.hpp"
#include "headers/object.hpp"




int main(int argc, char* argv[])
 {
    Load();
    current_gStatus = MENU;
    lava.vy = 0;

    Player player;
    Object object;



    while (running) {
            while (SDL_PollEvent(&g_even))
        {
            processInput(g_even);
           player.processInput(g_even);
        }
                frame++;
                if (frame > 300) {
                    frame = 0;
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



else if(lava.y >560 && current_gStatus != OVER)
    {

    lava.y -= lava.vy;
    lava.rect.y = lava.y;

    camera.y = lava.y + lava.rect.h - SCREEN_HEIGHT;
    if (camera.y < 0) camera.y = 0;




    time++;
    if (time>50)
    {
        hitRecently = false;
    }

    player.render();
    player.update();



    object.render();
    object.update();


    SDL_Rect lavaRect = {0, SCREEN_HEIGHT - lava.rect.h, SCREEN_WIDTH, lava.rect.h};
    }
    else if (lava.y <560&& current_gStatus != OVER) {

    player.render();
    player.update();

    object.render();
    object.update();

         if ((frame/30)% 2 == 0)
            {
                SDL_Rect victoryRect = {550, 0, 500, 300};
                SDL_RenderCopy(renderer, victoryTexture, NULL, &victoryRect);


            }
    }

    if (current_gStatus == OVER) {
    player.render();
    player.update();

    object.render();
    object.update();
    lava.y = 0;
        if ((frame/30)% 2 == 0)
        {
            SDL_Rect overRect = {550, 0, 500, 300};
            SDL_RenderCopy(renderer, overTexture, NULL, &overRect);
        }

    }

    showHealth();
    SDL_RenderPresent(renderer);
    SDL_Delay(16.67);

}
    destroy();
    return 0;

 }

