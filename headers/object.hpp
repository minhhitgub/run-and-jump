#pragma once
#include "functions.hpp"

class Object{
public:

    Object();
    ~Object();
    SDL_Rect rect;
    int vx;
    int vy;
    int minX, maxX, minY, maxY;


    static SDL_Texture* platformTexture;
    static SDL_Texture* dragonTexture[4];
    static SDL_Texture* fireTexture;
    static std::vector<Object> platforms;
    static std::vector<Object> dragons;
    static std::vector<Object> fires;
    Object(SDL_Rect rect, int vx, int vy, int minX, int maxX, int minY, int maxY ) : rect(rect), vx(vx), vy(vy), minX(minX), maxX(maxX), minY(minY), maxY(maxY) {};
    void initObject();
    void render();
    void update();
};
