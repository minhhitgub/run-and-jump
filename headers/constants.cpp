#include "constants.hpp"
 std::vector<obstacle> obstacles;
 Lava lava = {GROUND, LAVA_SPEED, {0, GROUND, SCREEN_WIDTH, 10}};

SDL_Renderer* renderer = nullptr;
SDL_Surface* surface = nullptr;
SDL_Texture* backgroundTexture = nullptr;
SDL_Texture* neutralTexture = nullptr;
SDL_Texture* runTexture = nullptr;
SDL_Texture* jumpTexture = nullptr;
SDL_Texture* attackTexture = nullptr;
playerState currentState = NEUTRAL;

bool running = true;
SDL_Window* window = nullptr;
Mix_Music* gMusic = nullptr;
