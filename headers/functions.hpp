#include <SDL.h>
#include<SDL_image.h>
#include<vector>
#include "constants.hpp"

void initObstacle();

bool checkCollision(const SDL_Rect& player, const SDL_Rect& obs);

void handleCollision(Player& player);

void processInput(Player& player, bool& running);

void update(Player& player, Lava& lava, SDL_Rect& camera);

void render(SDL_Renderer* renderer, Player& player, Lava& lava, SDL_Rect& camera);

SDL_Texture* loadTexture(const char* file_path, SDL_Renderer* renderer);

void destroy();
