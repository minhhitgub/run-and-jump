#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <vector>
#include <SDL.h>
#include <SDL_mixer.h>

const int SCREEN_WIDTH = 1600;
const int SCREEN_HEIGHT = 900;

const int PLAYER_WIDTH = 80;
const int PLAYER_HEIGHT = 80;
const int PLAYER_SPEED = 5;
const int GRAVITY = 1;
const int JUMP_SPEED = -20;

const int DRAGON_X = 100;
const int DRAGON_Y = 300;

const int LAVA_SPEED = 1;
const int LAVA_DEPTH = 4000;

struct Player
{
    int x, y;
    int vx, vy;
    bool isJumping;
    SDL_RendererFlip flip;
    int hitDuration;
};

struct obstacle {
    SDL_Rect rect;
    int vx;
    obstacle(SDL_Rect rect, int vx) : rect(rect), vx(vx) {};
};

enum playerState {
    NEUTRAL,
    RUN,
    JUMP,
    ATTACK,
    HIT
};

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
extern bool running;
extern playerState currentState;

extern SDL_Texture* backgroundTexture[4];

extern SDL_Texture* obstacleTexture;
extern SDL_Texture* dragonTexture[4];
extern SDL_Texture* neutralTexture;
extern SDL_Texture* runTexture;
extern SDL_Texture* jumpTexture;
extern SDL_Texture* attackTexture;
extern SDL_Texture* fireTexture;
extern SDL_Texture* hitTexture;
extern std::vector<obstacle> obstacles;

extern SDL_Renderer* renderer;

extern SDL_Surface* surface;

extern SDL_Window* window;

extern Mix_Music* gMusic;

#endif
