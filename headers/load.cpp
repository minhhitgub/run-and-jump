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


     surface = IMG_Load("image/bg.jpg");
    if (!surface) {
        printf ("Unable to load image!\n");
        destroy();
        return -1;
    }


    backgroundTexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if (!backgroundTexture) {
        printf ("Unable to create texture from surface!\n");
        destroy();
        return -1;
    }

    SDL_Surface* surface = IMG_Load("image/playerNeutral.png");
    if (!surface) {
        printf("Unable to load image: %s\n", IMG_GetError());
        return -1;
    }
    neutralTexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if (!neutralTexture) {
        printf("Unable to create texture: %s\n", SDL_GetError());
        return -1;
    }


    surface = IMG_Load("image/playerRun.png");
    if (!surface) {
        printf("Unable to load image: %s\n", IMG_GetError());
        return -1;
    }
    runTexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if (!runTexture) {
        printf("Unable to create texture: %s\n", SDL_GetError());
        return -1;
    }


    surface = IMG_Load("image/playerAttack.png");
    if (!surface) {
        printf("Unable to load image: %s\n", IMG_GetError());
        return -1;
    }
    attackTexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if (!runTexture) {
        printf("Unable to create texture: %s\n", SDL_GetError());
        return -1;
    }

    surface = IMG_Load("image/playerJump.png");
    if (!surface) {
        printf("Unable to load image: %s\n", IMG_GetError());
        return -1;
    }

    jumpTexture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_FreeSurface(surface);
    if (!runTexture) {
        printf("Unable to create texture: %s\n", SDL_GetError());
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


    gMusic = Mix_LoadMUS("music/ForestWalk.mp3");
    if (!gMusic)
        {
            printf("Failed to load music: %s\n", Mix_GetError());
        }

     if (Mix_PlayMusic(gMusic, -1) == -1)
        {
            printf("Failed to play music! SDL_mixer Error: %s\n", Mix_GetError());
        }
}
