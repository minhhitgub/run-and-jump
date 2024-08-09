#include <SDL.h>
#include <stdio.h>
#include<SDL_image.h>
#include<vector>
#include "functions.hpp"
#include "constants.hpp"

void initObstacle()
{

    obstacles.push_back(obstacle {SDL_Rect{1000, LAVA_DEPTH - 2300, 50, 50}, 0});
    obstacles.push_back(obstacle {SDL_Rect{800, LAVA_DEPTH - 2100, 50, 50}, 0});
    obstacles.push_back(obstacle {SDL_Rect{600, LAVA_DEPTH - 1900, 50, 50}, 0});


     obstacles.push_back(obstacle {SDL_Rect{400, LAVA_DEPTH - 1900, 100, 150}, 0});
    obstacles.push_back(obstacle {SDL_Rect{200, LAVA_DEPTH - 1700, 50, 50}, 0});


    obstacles.push_back(obstacle {SDL_Rect{200, LAVA_DEPTH - 1500, 600, 50}, 0});
    obstacles.push_back(obstacle {SDL_Rect{1000, LAVA_DEPTH - 1500, 500, 50}, 0});

    obstacles.push_back(obstacle {SDL_Rect{900, LAVA_DEPTH - 1300, 100, 100}, 0});
    obstacles.push_back(obstacle {SDL_Rect{700, LAVA_DEPTH - 1100, 100, 150}, 0});
    obstacles.push_back(obstacle {SDL_Rect{900, LAVA_DEPTH - 900, 100, 50}, 0});
    obstacles.push_back(obstacle {SDL_Rect{1100, LAVA_DEPTH - 700, 100, 100}, 0});
    obstacles.push_back(obstacle {SDL_Rect{900, LAVA_DEPTH - 600, 130, 50}, 2});
    obstacles.push_back(obstacle {SDL_Rect{600, LAVA_DEPTH - 400, 200, 100}, 0});
    obstacles.push_back(obstacle {SDL_Rect{300, LAVA_DEPTH - 300, 200, 50}, 0});

}

bool checkCollision(const SDL_Rect& obj1, const SDL_Rect& obj2) {
    return SDL_HasIntersection(&obj1, &obj2);
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
    static int hp = 0;
    static int frame = 0;
    frame++;
    if (frame > 200){
        frame = 0;
    }
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


    SDL_Rect fireRect;
    if (frame > -1 && frame < 15 || frame > 99 && frame < 115) {
        fireRect = {210 - camera.x, LAVA_DEPTH - 1650 - camera.y, 1300, 150};


        SDL_Rect playerRect = {player.x - camera.x, player.y - camera.y, PLAYER_WIDTH, PLAYER_HEIGHT};
        if (checkCollision(playerRect, fireRect)) {
            if (currentState != HIT) {
            currentState = HIT;
            player.hitDuration = 60;
            hp++;
        }
        if (hp == 200){
            printf("Hit by fire. Game Over");
            destroy();
            exit(0);
        }
        }
    }


    for (auto it = obstacles.begin(); it != obstacles.end();) {
        if (checkCollision(it->rect, lava.rect)) {
            it = obstacles.erase(it);
        } else {
            it++;
        }
    }


    for (auto& obs : obstacles) {
        obs.rect.x += obs.vx;

        if ( obs.rect.x + obs.rect.w > 1200 || obs.rect.x  < 600) {
            obs.vx = -obs.vx;
        }
    }
}


void render(SDL_Renderer* renderer, Player& player, Lava& lava, SDL_Rect& camera)
{
    SDL_RendererFlip flipType = SDL_FLIP_HORIZONTAL;
    static int frame = 0;
    frame++;
    if (frame > 200){
        frame = 0;
    }

    SDL_Texture* currentBackground = backgroundTexture[frame/30 % 4];

    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, currentBackground, NULL, NULL);



    SDL_Texture* currentDragon = dragonTexture[frame/30 %4];

    SDL_Rect dragonRect = {0 - camera.x, LAVA_DEPTH - 1700 - camera.y, 200, 200 };

    SDL_RenderCopy(renderer, currentDragon, NULL, &dragonRect);

    dragonRect = {1400 - camera.x, LAVA_DEPTH - 2000 - camera.y, 200, 200 };

    SDL_RenderCopyEx(renderer, currentDragon, NULL, &dragonRect, 0, NULL, flipType);




    if (frame > -1 && frame < 15 || frame > 99 && frame < 115  ){
            SDL_Rect fireRect =   {210 - camera.x, LAVA_DEPTH - 1650 - camera.y, 1300, 150};

            SDL_RenderCopy(renderer, fireTexture, NULL, &fireRect);
            }


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
        case HIT:
            currentTexture = hitTexture;
    }
    if (currentTexture) {
        SDL_Rect playerRect = { player.x - camera.x, player.y - camera.y, PLAYER_WIDTH, PLAYER_HEIGHT };
        SDL_RenderCopyEx(renderer, currentTexture, NULL, &playerRect, 0, NULL, player.flip);
    }




    SDL_SetRenderDrawColor(renderer, 139, 69, 19, 255);
    for (const auto& obstacle : obstacles) {
        SDL_Rect obstacleRect = { obstacle.rect.x -camera.x, obstacle.rect.y -camera.y, obstacle.rect.w, obstacle.rect.h };
        SDL_RenderCopy(renderer, obstacleTexture, NULL, &obstacleRect);
    }


    SDL_SetRenderDrawColor(renderer, 255, 69, 0, 255);
    SDL_Rect lavaRect = { lava.rect.x - camera.x, lava.rect.y - camera.y, lava.rect.w, lava.rect.h };


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
