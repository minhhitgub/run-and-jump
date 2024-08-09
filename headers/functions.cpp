#include <SDL.h>
#include <stdio.h>
#include<SDL_image.h>
#include<vector>
#include "functions.hpp"
#include "constants.hpp"

void initObstacle()
{
    obstacles.push_back(obstacle {SDL_Rect{300, 800, 100, 100}});
    obstacles.push_back(obstacle {SDL_Rect{600, 800, 100, 150}});
    obstacles.push_back(obstacle {SDL_Rect{900, 1200, 100, 100}});
    obstacles.push_back(obstacle {SDL_Rect{0, 400, 100, 100}});
    obstacles.push_back(obstacle {SDL_Rect{600, 200, 100, 150}});
    obstacles.push_back(obstacle {SDL_Rect{900, -200, 100, 100}});
    obstacles.push_back(obstacle {SDL_Rect{900, 500, 200, 50}});
    obstacles.push_back(obstacle {SDL_Rect{900, 900, 200, 50}});

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
                } else if (player.vy < 0 && playerRect.y >= obs.rect.y + obs.rect.h + player.vy) {

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
                    currentState = RUN;
                    player.flip = SDL_FLIP_NONE;
                    break;
                case SDLK_RIGHT:
                    player.vx = PLAYER_SPEED;
                    currentState = RUN;
                    player.flip = SDL_FLIP_HORIZONTAL;
                    break;
                case SDLK_SPACE:
                    if (!player.isJumping) {
                        player.vy = JUMP_SPEED;
                        currentState = JUMP;
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
                    currentState = NEUTRAL;
                    break;
            }
        }
    }
}


void update(Player& player, Lava& lava, SDL_Rect& camera)
{

    player.x += player.vx;
    player.y += player.vy;


    player.vy += GRAVITY;

    if (player.x < 0) player.x = 0;
    if (player.x + PLAYER_WIDTH > SCREEN_WIDTH) player.x = SCREEN_WIDTH - PLAYER_WIDTH;
    handleCollision(player);


    lava.y -= lava.vy;
    lava.rect.y = lava.y;

    camera.y = lava.y + lava.rect.h - SCREEN_HEIGHT;
    if (camera.y < 0) camera.y = 0;


    if (player.y + PLAYER_HEIGHT > lava.y) {
            printf("Game Over");
        destroy();
        exit(0);
    }
}


void render(SDL_Renderer* renderer, Player& player, Lava& lava, SDL_Rect& camera)
{
    static int frame = 0;
    frame++;
    if (frame > 100){
        frame = 0;
    }

    SDL_Texture* currentBackground = backgroundTexture[frame/30 % 4];

    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, currentBackground, NULL, NULL);



    SDL_Texture* currentDragon = dragonTexture[frame/30 %4];

    SDL_Rect dragonRect = { 100 , 300, 200, 200 };

    SDL_RenderCopy(renderer, currentDragon, NULL, &dragonRect);


    SDL_Texture* currentTexture = nullptr;
    switch (currentState) {
        case NEUTRAL:
            currentTexture = neutralTexture;
            break;
        case RUN:
            currentTexture = runTexture;
            break;
        case JUMP:
            currentTexture = jumpTexture;
            break;
        case ATTACK:
            currentTexture = attackTexture;
            break;
    }
    if (currentTexture) {
        SDL_Rect playerRect = { player.x - camera.x, player.y - camera.y, PLAYER_WIDTH, PLAYER_HEIGHT };
        SDL_RenderCopyEx(renderer, currentTexture, NULL, &playerRect, 0, NULL, player.flip);
    }




    SDL_SetRenderDrawColor(renderer, 139, 69, 19, 255);
    for (const auto& obstacle : obstacles) {
        SDL_Rect obstacleRect = { obstacle.rect.x - camera.x, obstacle.rect.y - camera.y, obstacle.rect.w, obstacle.rect.h };
        SDL_RenderFillRect(renderer, &obstacleRect);
    }


    SDL_SetRenderDrawColor(renderer, 255, 69, 0, 255);
    SDL_Rect lavaRect = { lava.rect.x - camera.x, lava.rect.y - camera.y, lava.rect.w, lava.rect.h };
    SDL_RenderFillRect(renderer, &lavaRect);

    SDL_RenderPresent(renderer);
}

SDL_Texture* loadTexture(const char* file_path, SDL_Renderer* renderer) {
    SDL_Surface* surface = IMG_Load(file_path);
    if (!surface) {
        printf("Unable to load image");
        return nullptr;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    if (!texture) {
        printf("Unable to create texture");
        return nullptr;
    }

    return texture;
}


void destroy()
{
    SDL_DestroyTexture(backgroundTexture[1]);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    IMG_Quit();
    Mix_FreeMusic(gMusic);
    Mix_CloseAudio();
    Mix_Quit();
}
