#include "player.hpp"



Player::Player() {
    x = 600;
    y = LAVA_DEPTH - 5300;
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
    if (current_gStatus == PLAY){
    if (e.type == SDL_KEYDOWN) {
        switch (e.key.keysym.sym) {


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
}

void Player::update()
{
    if (current_gStatus == PLAY) {
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
}

void Player::handleCollision()
{

    SDL_Rect playerRect = { x, y, PLAYER_WIDTH, PLAYER_HEIGHT };



    for (const auto& it : Object::platforms) {


        if (checkCollision(playerRect, it.rect)) {
            if (playerRect.y + playerRect.h > it.rect.y && playerRect.y < it.rect.y + it.rect.h) {
                if (vy > 0 && playerRect.y + playerRect.h - vy <= it.rect.y + 5) {
                    y = it.rect.y - PLAYER_HEIGHT ;
                    vy = 0;
                    isJumping = false;
                    if (it.vx !=0 && it.vy !=0){
                    x+=it.vx;
                    }
                    if (it.vx !=0 && it.vy ==0){
                    x+=it.vx*2;
                    }




            } else if (vy < 0 && playerRect.y >= it.rect.y + it.rect.h + vy ) {
                    y = it.rect.y + it.rect.h;
                    vy = 0;
                }
            }

            if (playerRect.x + playerRect.w > it.rect.x && playerRect.x < it.rect.x + it.rect.w) {
                if (vx > 0 && playerRect.x + playerRect.w - vx <= it.rect.x+5) {
                    x = it.rect.x - PLAYER_WIDTH;
                } else if (vx < 0 && playerRect.x >= it.rect.x + it.rect.w + vx) {
                    x = it.rect.x + it.rect.w;
                }
            }
            if(it.vy>0){y+=it.vy*2;}


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



    SDL_Texture* currentBackground = backgroundTexture[frame/30 % 4];
    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, currentBackground, NULL, NULL);

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


    if (current_gStatus == MENU) {


        SDL_Color white = { 255, 255, 255, 255 };
        SDL_Texture* menuText = loadTextTexture("Start Game", white);
        SDL_Rect textRect = { 800, 450, 500, 300 };
        SDL_RenderCopy(renderer, menuText, NULL, &textRect);
        SDL_DestroyTexture(menuText);
    }

}
