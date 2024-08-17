#pragma once

#include "functions.hpp"

const int SCREEN_WIDTH = 1600;
const int SCREEN_HEIGHT = 900;

const int PLAYER_WIDTH = 80;
const int PLAYER_HEIGHT = 80;
const int PLAYER_SPEED = 5;
const int GRAVITY = 1;
const int JUMP_SPEED = -20;

const int DRAGON_X = 100;
const int DRAGON_Y = 300;

extern int LAVA_SPEED ;
const int LAVA_DEPTH = 10000;


struct Lava {
    int y;
    int vy;
    SDL_Rect rect;
};

struct dragon {
    int x;
    int y;
    SDL_Rect rect;
};

enum gameStatus {
    MENU,
    PLAY
};

extern gameStatus current_gStatus;


static SDL_Event g_even;

extern bool checkPause;
extern int frame;
extern SDL_Rect camera;

extern bool running;

extern Lava lava;

extern SDL_Texture* g_menuImg;

extern SDL_Texture* backgroundTexture[4];

extern SDL_Texture* obstacleTexture;
extern SDL_Texture* dragonTexture[4];

extern SDL_Texture* fireTexture;



extern SDL_Renderer* renderer;

extern SDL_Surface* surface;

extern SDL_Window* window;

extern Mix_Music* gMusic;


