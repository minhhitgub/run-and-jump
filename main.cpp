#include <SDL.h>
#include <stdio.h>
#include<SDL_image.h>
#include<vector>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;


const int PLAYER_WIDTH = 20;
const int PLAYER_HEIGHT = 20;
const int PLAYER_SPEED = 5;
const int GRAVITY = 1;
const int JUMP_SPEED = -20;

const int GROUND = 450;

struct Player
{
    int x, y;
    int vx, vy;
    bool isJumping;
};

struct obstacle {
    SDL_Rect rect;
};

std::vector<obstacle> obstacles;

void initObstacle()
{
    obstacles.push_back(obstacle {SDL_Rect{200, GROUND - 100, 100, 100}});
    obstacles.push_back(obstacle {SDL_Rect{500, GROUND - 150, 100, 150}});
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


int main(int argc, char* argv[])
 {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf ("Unable to initialize SDL!\n");
        SDL_GetError();
        return -1;
    }


    SDL_Window* window = SDL_CreateWindow("Run and Jump", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        printf ("Unable to create window!\n");
        SDL_GetError();
        SDL_Quit();
        return -1;
    }

    initObstacle();

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf ("Unable to create renderer!\n");
        SDL_GetError();
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }


    SDL_Surface* surface = IMG_Load("image/bg.jpg");
    if (!surface) {
        printf ("Unable to load image!\n");
        SDL_GetError();
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }


    SDL_Texture* backgroundTexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if (!backgroundTexture) {
        printf ("Unable to create texture from surface!\n");
        SDL_GetError();
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    Player player = { 100, GROUND , 0, 0, false };
    bool running = true;

    while (running) {
        processInput(player, running);
        update(player);
        handleCollision(player);
        render(renderer, backgroundTexture , player);
        SDL_Delay(16.67);
    }
    SDL_DestroyTexture(backgroundTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    IMG_Quit();
    return 0;
}

