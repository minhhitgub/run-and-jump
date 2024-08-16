#include "object.hpp"

std::vector<Object> Object::objects;
std::vector<Object> Object::dragons;
std::vector<Object> Object::fires;
SDL_Texture* Object::platformTexture = nullptr;
SDL_Texture* Object::dragonTexture[4] = {nullptr};
SDL_Texture* Object::fireTexture = nullptr;

Object::Object(){

    objects.push_back(Object {SDL_Rect{1000, LAVA_DEPTH - 2300, 50, 50}, 0, 0});
    objects.push_back(Object {SDL_Rect{800, LAVA_DEPTH - 2100, 50, 50}, 0, 0});
    objects.push_back(Object {SDL_Rect{600, LAVA_DEPTH - 1900, 50, 50}, 0, 0});


     objects.push_back(Object {SDL_Rect{400, LAVA_DEPTH - 1900, 100, 150}, 0, 0});
    objects.push_back(Object {SDL_Rect{200, LAVA_DEPTH - 1700, 50, 50}, 0, 0});



    objects.push_back(Object {SDL_Rect{200, LAVA_DEPTH - 1500, 600, 50}, 0, 0});
    objects.push_back(Object {SDL_Rect{1000, LAVA_DEPTH - 1500, 500, 50}, 0, 0});



    objects.push_back(Object {SDL_Rect{900, LAVA_DEPTH - 1300, 100, 100}, 0, 0});
    objects.push_back(Object {SDL_Rect{700, LAVA_DEPTH - 1100, 100, 150}, 0, 0});
    objects.push_back(Object {SDL_Rect{900, LAVA_DEPTH - 900, 100, 50}, 0, 0});
    objects.push_back(Object {SDL_Rect{1100, LAVA_DEPTH - 700, 100, 100}, 0, 0});
    objects.push_back(Object {SDL_Rect{900, LAVA_DEPTH - 600, 130, 50}, 0, 0});
    objects.push_back(Object {SDL_Rect{600, LAVA_DEPTH - 400, 200, 100}, 0, 0});
    objects.push_back(Object {SDL_Rect{300, LAVA_DEPTH - 300, 200, 50}, 0, 0});





    dragons.push_back(Object {SDL_Rect{0, LAVA_DEPTH -1650, 200, 200}, 0, 0});







    fires.push_back(Object {SDL_Rect{200, LAVA_DEPTH -1650, 1300, 200}, 0, 0});


    platformTexture = loadTexture("image/platform.png", renderer);
    dragonTexture[0] = loadTexture("image/dragon1.png", renderer);
    dragonTexture[1] = loadTexture("image/dragon2.png", renderer);
    dragonTexture[2] = loadTexture("image/dragon3.png", renderer);
    dragonTexture[3] = loadTexture("image/dragon4.png", renderer);
    fireTexture = loadTexture("image/dragonFire.png", renderer);
}

Object::~Object(){
;
}



void Object::render() {

for (const auto& it : objects) {
        SDL_Rect platformRect = { it.rect.x, it.rect.y - camera.y , it.rect.w, it.rect.h };
        SDL_RenderCopy(renderer, platformTexture, NULL, &platformRect);
    }


for (const auto& it : dragons) {
        SDL_Rect dragonRect = { it.rect.x, it.rect.y - camera.y , it.rect.w, it.rect.h };
        SDL_RenderCopy(renderer, dragonTexture[frame/20%4], NULL, &dragonRect);
    }

if (frame >= 0 && frame <= 29  ){
for (const auto& it : fires) {
        SDL_Rect fireRect = { it.rect.x, it.rect.y - camera.y , it.rect.w, it.rect.h };
        SDL_RenderCopy(renderer, fireTexture, NULL, &fireRect);
    }
}
}



void Object::update(){
for (auto& it : objects) {
        it.rect.x += it.vx;
        it.rect.y += it.vy;
}
for (auto& it : dragons) {
        it.rect.x += it.vx;
        it.rect.y += it.vy;
}


for (auto it = objects.begin(); it != objects.end();) {
        if (checkCollision(it->rect, lava.rect)) {
            it = objects.erase(it);
        } else {
            it++;
        }
    }
    for (auto it = dragons.begin(); it != dragons.end();) {
        if (checkCollision(it->rect, lava.rect)) {
            it = dragons.erase(it);
        } else {
            it++;
        }
    }
}

