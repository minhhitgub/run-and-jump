
#pragma once
#include "functions.hpp"


class Player{

public:
    Player();
    ~Player();
    void processInput(SDL_Event& e);
    void update();
    void render();
    void handleCollision();


    int x, y;
    int vx, vy;
    bool isJumping;
    SDL_RendererFlip flip;
    SDL_Texture* currentTexture;
    SDL_Texture* neutralTexture;
    SDL_Texture* hitTexture;
    SDL_Texture* runTexture;
    SDL_Texture* jumpTexture;



enum state {
    NEUTRAL,
    RUN,
    JUMP,
    ATTACK,
    HIT
};


    state currentState = NEUTRAL;
};
