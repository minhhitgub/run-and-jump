#include "player.hpp"



Player::Player() {
    x = 300;
    y = LAVA_DEPTH-500;
    vx = 0;
    vy = 0;
    isJumping = false;
    flip = SDL_FLIP_NONE;

    neutralTexture = loadTexture("image/playerNeutral.png", renderer);
    runTexture = loadTexture("image/playerRun.png", renderer);
    jumpTexture = loadTexture("image/playerJump.png", renderer);
    hitTexture = loadTexture("image/playerHit.png", renderer);
}
Player::~Player(){
;
}


void Player::processInput(SDL_Event& e)
{
    if (e.type == SDL_KEYDOWN) {
        switch (e.key.keysym.sym) {
            case SDLK_TAB:
                pause();
                break;

            case SDLK_ESCAPE:
            running = false;
            break;
            case SDLK_LEFT:
                vx = -PLAYER_SPEED;
                currentState = RUN;
                flip = SDL_FLIP_NONE;
                break;
            case SDLK_RIGHT:
                vx = PLAYER_SPEED;
                currentState = RUN;
                flip = SDL_FLIP_HORIZONTAL;
                break;
            case SDLK_SPACE:
                if (!isJumping) {
                    vy = JUMP_SPEED;
                    currentState = JUMP;
                    isJumping = true;
                }
                break;
        }
    } else if (e.type == SDL_KEYUP) {
        switch (e.key.keysym.sym) {
            case SDLK_LEFT:
            case SDLK_RIGHT:
                vx = 0;
                currentState = NEUTRAL;
                break;
        }
    }
}

void Player::update()
{
    x += vx;
    y += vy;

    vy += GRAVITY;

    if (x < 0) x = 0;
    if (x + PLAYER_WIDTH > SCREEN_WIDTH) x = SCREEN_WIDTH - PLAYER_WIDTH;
    handleCollision();
    //if (y + PLAYER_HEIGHT > lava.y) {
       //     printf("Game Over");
       // destroy();
      //  exit(0);
   // }

}

void Player::handleCollision()
{
    SDL_Rect playerRect = { x, y, PLAYER_WIDTH, PLAYER_HEIGHT };



    for (const auto& it : Object::platforms) {


        if (checkCollision(playerRect, it.rect)) {
            if (playerRect.y + playerRect.h > it.rect.y && playerRect.y < it.rect.y + it.rect.h) {
                if (vy > 0 && playerRect.y + playerRect.h - vy <= it.rect.y + 5) {
                    y = it.rect.y - PLAYER_HEIGHT;
                    vy = 0;
                    isJumping = false;


                } else if (vy < 0 && playerRect.y >= it.rect.y + it.rect.h + vy) {
                    y = it.rect.y + it.rect.h;
                    vy = 0;
                }
            }

            if (playerRect.x + playerRect.w > it.rect.x && playerRect.x < it.rect.x + it.rect.w) {
                if (vx > 0 && playerRect.x + playerRect.w - vx <= it.rect.x) {
                    x = it.rect.x - PLAYER_WIDTH;
                } else if (vx < 0 && playerRect.x >= it.rect.x + it.rect.w + vx) {
                    x = it.rect.x + it.rect.w;
                }
            }

        }
    }


if (frame >= 0 && frame <= 29 || frame >= 150 && frame <= 179 ){
    for (const auto& fire : Object::fires) {

        if (checkCollision(playerRect, fire.rect)) {
                currentState = HIT;

            }

        }
    }
}


void Player::render()
{
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
        case HIT:
            currentTexture = hitTexture;
    }
    if (currentTexture) {
        SDL_Rect playerRect = { x, y - camera.y , PLAYER_WIDTH, PLAYER_HEIGHT };
        SDL_RenderCopyEx(renderer, currentTexture, NULL, &playerRect, 0, NULL, flip);
    }
}
