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
        SDL_GetError();
        SDL_Quit();
        return -1;
    }

    initObstacle();

     renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf ("Unable to create renderer!\n");
        SDL_GetError();
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }


     surface = IMG_Load("image/bg.jpg");
    if (!surface) {
        printf ("Unable to load image!\n");
        SDL_GetError();
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }


    backgroundTexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if (!backgroundTexture) {
        printf ("Unable to create texture from surface!\n");
        SDL_GetError();
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
}
