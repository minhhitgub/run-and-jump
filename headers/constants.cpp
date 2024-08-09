#include "constants.hpp"
 std::vector<obstacle> obstacles;


SDL_Renderer* renderer = nullptr;
SDL_Surface* surface = nullptr;
SDL_Texture* backgroundTexture[4] = {nullptr};
SDL_Texture* obstacleTexture = nullptr;
SDL_Texture* dragonTexture[4] = {nullptr};
SDL_Texture* neutralTexture = nullptr;
SDL_Texture* runTexture = nullptr;
SDL_Texture* jumpTexture = nullptr;
SDL_Texture* attackTexture = nullptr;
SDL_Texture* fireTexture = nullptr;
SDL_Texture* hitTexture = nullptr;
playerState currentState = NEUTRAL;


bool running = true;
SDL_Window* window = nullptr;
Mix_Music* gMusic = nullptr;
