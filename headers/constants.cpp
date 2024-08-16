#include "constants.hpp"

SDL_Rect camera = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
Lava lava = {LAVA_DEPTH, LAVA_SPEED, {0, 1200, SCREEN_WIDTH, 200}};
SDL_Renderer* renderer = nullptr;
SDL_Surface* surface = nullptr;
SDL_Texture* backgroundTexture[4] = {nullptr};
SDL_Texture* obstacleTexture = nullptr;
SDL_Texture* dragonTexture[4] = {nullptr};

SDL_Texture* fireTexture = nullptr;
SDL_Texture* hitTexture = nullptr;

int frame = 0;
bool running = true;
bool checkPause = false;
SDL_Window* window = nullptr;
Mix_Music* gMusic = nullptr;
