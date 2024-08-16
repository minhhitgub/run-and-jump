#pragma once
#include "functions.hpp"

class Object{
public:

    Object();
    ~Object();
    SDL_Rect rect;
    int vx;
    int vy;

    static SDL_Texture* platformTexture;
    static SDL_Texture* dragonTexture[4];
    static SDL_Texture* fireTexture;
    static std::vector<Object> objects;
    static std::vector<Object> dragons;
    static std::vector<Object> fires;
    Object(SDL_Rect rect, int vx, int vy) : rect(rect), vx(vx), vy(vy) {};
    void initObject();
    void render();
    void update();
};
