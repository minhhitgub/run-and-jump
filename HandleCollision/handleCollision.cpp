#include <SDL.h>
#include <stdio.h>
#include<SDL_image.h>
#include<vector>
#include<HandleCollision.hpp>
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
