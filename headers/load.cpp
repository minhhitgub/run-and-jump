#include<SDL.h>
#include<stdio.h>
#include "constants.hpp"
#include "functions.hpp"


int Load()
{
if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf ("Unable to initialize SDL!\n");
        SDL_GetError();
        return -1;
    }


    window = SDL_CreateWindow("Run and Jump", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        printf ("Unable to create window!\n");
        destroy();
        return -1;
    }

    initObstacle();

     renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf ("Unable to create renderer!\n");
        destroy();
        return -1;
    }

    fireTexture = loadTexture("image/dragonFire.png", renderer);
    if (!fireTexture) {
        destroy();
        return -1;
    }

    backgroundTexture[0] = loadTexture("image/bg1.png", renderer);
    if (!backgroundTexture[0]) {
        destroy();
        return -1;
    }

    backgroundTexture[1] = loadTexture("image/bg2.png", renderer);
    if (!backgroundTexture[1]) {
        destroy();
        return -1;
    }

    backgroundTexture[2] = loadTexture("image/bg3.png", renderer);
    if (!backgroundTexture[2]) {
        destroy();
        return -1;
    }

    backgroundTexture[3] = loadTexture("image/bg4.png", renderer);
    if (!backgroundTexture[3]) {
        destroy();
        return -1;
    }

    obstacleTexture = loadTexture("image/obstacle.png", renderer);
    if (!obstacleTexture) {
        destroy();
        return -1;
    }

    dragonTexture[0] = loadTexture("image/dragon1.png", renderer);
    if (!dragonTexture[0]) {
        destroy();
        return -1;
    }

    dragonTexture[1] = loadTexture("image/dragon2.png", renderer);
    if (!dragonTexture[1]) {
        destroy();
        return -1;
    }

    dragonTexture[2] = loadTexture("image/dragon3.png", renderer);
    if (!dragonTexture[2]) {
        destroy();
        return -1;
    }

    dragonTexture[3] = loadTexture("image/dragon4.png", renderer);
    if (!dragonTexture[3]) {
        destroy();
        return -1;
    }


    neutralTexture = loadTexture("image/playerNeutral.png", renderer);
    if (!neutralTexture) {
        destroy();
        return -1;
    }


    runTexture = loadTexture("image/playerRun.png", renderer);
    if (!neutralTexture) {
        destroy();
        return -1;
    }


    attackTexture = loadTexture("image/playerAttack.png", renderer);
    if (!attackTexture) {
        destroy();
        return -1;
    }

    jumpTexture = loadTexture("image/playerJump.png", renderer);
    if (!jumpTexture) {
        destroy();
        return -1;
    }

    hitTexture = loadTexture("image/playerHit.png", renderer);
    if (!hitTexture) {
        destroy();
        return -1;
    }









    if (Mix_Init(MIX_INIT_MP3) == 0)
        {
            printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
        }


    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
       {
            printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
            return -1;
        }


    gMusic = Mix_LoadMUS("music/backgroundMusic.mp3");
    if (!gMusic)
        {
            printf("Failed to load music: %s\n", Mix_GetError());
        }

     if (Mix_PlayMusic(gMusic, -1) == -1)
        {
            printf("Failed to play music! SDL_mixer Error: %s\n", Mix_GetError());
        }
}
