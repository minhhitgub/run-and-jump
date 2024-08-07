#include <SDL.h>
#include <stdio.h>
#include<SDL_image.h>
#include<vector>
#include "functions.hpp"
#include "constants.hpp"

void initObstacle()
{
    obstacles.push_back(obstacle {SDL_Rect{200, GROUND - 100, 100, 100}});
    obstacles.push_back(obstacle {SDL_Rect{500, GROUND - 150, 100, 150}});
}

bool checkCollision(const SDL_Rect& player, const SDL_Rect& obs) {
    return SDL_HasIntersection(&player, &obs);
}


void handleCollision(Player& player) {
    SDL_Rect playerRect = { player.x, player.y, PLAYER_WIDTH, PLAYER_HEIGHT };

    for (const auto& obs : obstacles) {
        if (checkCollision(playerRect, obs.rect)) {

            if (playerRect.y + playerRect.h > obs.rect.y && playerRect.y < obs.rect.y + obs.rect.h) {
                if (player.vy > 0 && playerRect.y + playerRect.h - player.vy <= obs.rect.y) {

                    player.y = obs.rect.y - PLAYER_HEIGHT;
                    player.vy = 0;
                    player.isJumping = false;
                } else if (player.vy < 0 && playerRect.y >= obs.rect.y + obs.rect.h - player.vy) {

                    player.y = obs.rect.y + obs.rect.h;
                    player.vy = 0;
                }
            }

    playerRect = { player.x, player.y, PLAYER_WIDTH, PLAYER_HEIGHT };

            if (playerRect.x + playerRect.w > obs.rect.x && playerRect.x < obs.rect.x + obs.rect.w) {
                if (player.vx > 0 && playerRect.x + playerRect.w - player.vx <= obs.rect.x) {

                    player.x = obs.rect.x - PLAYER_WIDTH;
                }
                else if (player.vx < 0 && playerRect.x >= obs.rect.x + obs.rect.w + player.vx) {

                    player.x = obs.rect.x + obs.rect.w;
                }
            }
        }
    }
}


void processInput(Player& player, bool& running)
{
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            running = false;
        }
        else if (e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
                case SDLK_ESCAPE:
                    running = false;
                case SDLK_LEFT:
                    player.vx = -PLAYER_SPEED;
                    break;
                case SDLK_RIGHT:
                    player.vx = PLAYER_SPEED;
                    break;
                case SDLK_SPACE:
                    if (!player.isJumping) {
                        player.vy = JUMP_SPEED;
                        player.isJumping = true;
                    }
                    break;

            }
        }
        else if (e.type == SDL_KEYUP) {
            switch (e.key.keysym.sym) {
                case SDLK_LEFT:
                case SDLK_RIGHT:
                    player.vx = 0;
                    break;
            }
        }
    }
}


void update(Player& player)
{

    player.x += player.vx;
    player.y += player.vy;


    player.vy += GRAVITY;


    if (player.y + PLAYER_HEIGHT > GROUND ) {
        player.y = GROUND - PLAYER_HEIGHT ;
        player.vy = 0;
        player.isJumping = false;
    }
    if (player.y == GROUND - 100){player.y == GROUND; }

    if (player.x < 0) player.x = 0;
    if (player.x + PLAYER_WIDTH > SCREEN_WIDTH) player.x = SCREEN_WIDTH - PLAYER_WIDTH;
    handleCollision(player);
}


void render(SDL_Renderer* renderer, SDL_Texture* backgroundTexture, Player& player)
{
    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

    SDL_Rect playerRect = { player.x, player.y, PLAYER_WIDTH, PLAYER_HEIGHT };
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &playerRect);

    SDL_SetRenderDrawColor(renderer, 139, 69, 19, 255);
    for (const auto& obstacle : obstacles) {
    SDL_RenderFillRect(renderer, &obstacle.rect);
    }

    SDL_RenderPresent(renderer);
}

void destroy()
{
    SDL_DestroyTexture(backgroundTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    IMG_Quit();
}
