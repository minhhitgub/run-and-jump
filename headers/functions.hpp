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




bool checkCollision(const SDL_Rect& player, const SDL_Rect& obs);




void pause();

void processInput(SDL_Event& e);
SDL_Texture* loadTexture(const char* file_path, SDL_Renderer* renderer);

SDL_Texture* loadTextTexture(const std::string& text, const SDL_Color& color);

void showHealth();

void destroy();
