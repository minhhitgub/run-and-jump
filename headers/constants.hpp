#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <vector>
#include <SDL.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

const int PLAYER_WIDTH = 20;
const int PLAYER_HEIGHT = 20;
const int PLAYER_SPEED = 5;
const int GRAVITY = 1;
const int JUMP_SPEED = -20;

const int GROUND = 450;

struct Player
{
    int x, y;
    int vx, vy;
    bool isJumping;
};

struct obstacle {
    SDL_Rect rect;
};

extern std::vector<obstacle> obstacles;

extern SDL_Renderer* renderer;

extern SDL_Surface* surface;

extern SDL_Texture* backgroundTexture;

extern SDL_Window* window;

#endif
