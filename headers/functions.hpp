#pragma once

#include <SDL.h>
#include<SDL_image.h>
#include <SDL_mixer.h>
#include<SDL_ttf.h>

#include<vector>
#include<string>
#include<stdio.h>

#include "load.hpp"
#include "constants.hpp"
#include "object.hpp"
#include "player.hpp"
#include "textObject.hpp"

void initObstacle();

bool checkCollision(const SDL_Rect& player, const SDL_Rect& obs);


void render();

void pause();



SDL_Texture* loadTexture(const char* file_path, SDL_Renderer* renderer);

void destroy();
