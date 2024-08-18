    #include "object.hpp"

    std::vector<Object> Object::platforms;
    std::vector<Object> Object::dragons;
    std::vector<Object> Object::fires;
    SDL_Texture* Object::platformTexture = nullptr;
    SDL_Texture* Object::platformUpTexture = nullptr;
    SDL_Texture* Object::platformDownTexture = nullptr;
    SDL_Texture* Object::dragonTexture[4] = {nullptr};
    SDL_Texture* Object::fireTexture = nullptr;

    Object::Object(){


         platforms.push_back(Object {SDL_Rect{700, LAVA_DEPTH - 15500, 200, 50}, 0, 0, 0, 0, 0, 0, false, false});
         platforms.push_back(Object {SDL_Rect{700, LAVA_DEPTH - 15300, 200, 50}, 0, 0, 0, 0, 0, 0, false, false});
         platforms.push_back(Object {SDL_Rect{700, LAVA_DEPTH - 15100, 200, 50}, 0, 0, 0, 0, 0, 0, false, false});
         platforms.push_back(Object {SDL_Rect{700, LAVA_DEPTH - 14900, 200, 50}, 0, 0, 0, 0, 0, 0, false, false});
         platforms.push_back(Object {SDL_Rect{700, LAVA_DEPTH - 14700, 200, 50}, 0, 0, 0, 0, 0, 0, false, false});
         platforms.push_back(Object {SDL_Rect{700, LAVA_DEPTH - 14500, 200, 50}, 0, 0, 0, 0, 0, 0, false, false});
         platforms.push_back(Object {SDL_Rect{700, LAVA_DEPTH - 14300, 200, 50}, 0, 0, 0, 0, 0, 0, false, false});
         platforms.push_back(Object {SDL_Rect{700, LAVA_DEPTH - 14100, 200, 50}, 0, 0, 0, 0, 0, 0, false, false});
         platforms.push_back(Object {SDL_Rect{700, LAVA_DEPTH - 13900, 200, 50}, 0, 0, 0, 0, 0, 0, false, false});



         platforms.push_back(Object {SDL_Rect{1000, LAVA_DEPTH - 13700, 200, 50}, 0, 0, 0, 0, 0, 0, false, false});
         platforms.push_back(Object {SDL_Rect{1200, LAVA_DEPTH - 13500, 200, 50}, 0, 0, 0, 0, 0, 0, false, false});
         platforms.push_back(Object {SDL_Rect{200, LAVA_DEPTH - 13300, 100, 50}, 0, 0, 0, 0, 0, 0, false, true});    platforms.push_back(Object {SDL_Rect{400, LAVA_DEPTH - 13300, 100, 50}, 0, 0, 0, 0, 0, 0, false, false});    platforms.push_back(Object {SDL_Rect{600, LAVA_DEPTH - 13300, 100, 50}, 5, 0, 600, 1200, 0, 0, false, false});


         platforms.push_back(Object {SDL_Rect{0, LAVA_DEPTH - 13150, 25, 50}, 0, 0, 0, 0, 0, 0, false, true});
         platforms.push_back(Object {SDL_Rect{0, LAVA_DEPTH - 12980, 25, 50}, 0, 0, 0, 0, 0, 0, false, true});

         platforms.push_back(Object {SDL_Rect{0, LAVA_DEPTH - 12810, 25, 50}, 0, 0, 0, 0, 0, 0, false, true});


         platforms.push_back(Object {SDL_Rect{0, LAVA_DEPTH - 12640, 25, 50}, 0, 0, 0, 0, 0, 0, false, false});

         platforms.push_back(Object {SDL_Rect{0, LAVA_DEPTH - 12470, 25, 50}, 0, 0, 0, 0, 0, 0, false, true});
         platforms.push_back(Object {SDL_Rect{250, LAVA_DEPTH - 12350, 25, 50}, 0, 0, 0, 0, 0, 0, false, true});


          platforms.push_back(Object {SDL_Rect{400, LAVA_DEPTH - 12600, 25, 50}, 0, 0, 0, 0, 0, 0, false, true});

         platforms.push_back(Object {SDL_Rect{600, LAVA_DEPTH - 12600, 50, 50}, 0, 0, 0, 0, 0, 0, false, true});      platforms.push_back(Object {SDL_Rect{800, LAVA_DEPTH - 12600, 150, 50}, 0, 0, 0, 0, 0, 0, false, true});
          platforms.push_back(Object {SDL_Rect{1100, LAVA_DEPTH - 12450, 159, 50}, 0, 0, 0, 0, 0, 0, false, true});
         platforms.push_back(Object {SDL_Rect{800, LAVA_DEPTH - 12300, 200, 50}, 0, 0, 0, 0, 0, 0, false, true});




        platforms.push_back(Object {SDL_Rect{1000, LAVA_DEPTH - 12100, 200, 50}, 0, 0, 0, 0, 0, 0, false, false});
        platforms.push_back(Object {SDL_Rect{1000, LAVA_DEPTH - 11900, 200, 100}, 0, 0, 0, 0, 0, 0, false, false});

        platforms.push_back(Object {SDL_Rect{900, LAVA_DEPTH - 10000, 50, 50}, 7, -7, 900, 1300, LAVA_DEPTH - 10400, LAVA_DEPTH - 10000, false, false});  platforms.push_back(Object {SDL_Rect{1400, LAVA_DEPTH - 10400, 100, 100}, 0, 0, 0, 0, LAVA_DEPTH - 12000, LAVA_DEPTH - 10400, true, false});



        platforms.push_back(Object {SDL_Rect{700, LAVA_DEPTH - 9500, 50, 50}, 0, 0, 0, 0, LAVA_DEPTH - 11000, LAVA_DEPTH - 9500, true, false});



        platforms.push_back(Object {SDL_Rect{2, LAVA_DEPTH - 8900, 50, 50}, 5, -5, 1, 600, LAVA_DEPTH - 9500, LAVA_DEPTH - 8901, false, false});

        platforms.push_back(Object {SDL_Rect{200, LAVA_DEPTH - 8800, 50, 50}, 0, 0, 0, 0, 0, 0, false, false});           platforms.push_back(Object {SDL_Rect{500, LAVA_DEPTH - 8800, 50, 50}, 0, 0, 0, 0, 0, 0, false, false});        platforms.push_back(Object {SDL_Rect{800, LAVA_DEPTH - 8800, 200, 200}, 0, 0, 0, 0, 0, 0, false, false});

        platforms.push_back(Object {SDL_Rect{1200, LAVA_DEPTH - 8600, 200, 50}, 6, 0, 1000, 1600, 0, 0, false, false});
        platforms.push_back(Object {SDL_Rect{1200, LAVA_DEPTH - 8400, 200, 50}, 6, 0, 1000, 1600, 0, 0, false, false});

        platforms.push_back(Object {SDL_Rect{900, LAVA_DEPTH - 8200, 200, 50}, 4, 0, 500, 1100, 0, 0, false, false});
        platforms.push_back(Object {SDL_Rect{900, LAVA_DEPTH - 8000, 200, 50}, 4, 0, 500, 1100, 0, 0, false, false});

       platforms.push_back(Object {SDL_Rect{100, LAVA_DEPTH - 7800, 200, 50}, 3, 0, 1, 500, 0, 0, false, false});

        platforms.push_back(Object {SDL_Rect{100, LAVA_DEPTH - 7600, 200, 50}, 3, 0, 1, 500, 0, 0, false, false});


       platforms.push_back(Object {SDL_Rect{0, LAVA_DEPTH - 7400, 260, 50}, 0, 0, 0, 0, 0, 0, false, false});
       platforms.push_back(Object {SDL_Rect{0, LAVA_DEPTH - 7200, 240, 50}, 0, 0, 0, 0, 0, 0, false, false});
       platforms.push_back(Object {SDL_Rect{0, LAVA_DEPTH - 7000, 220, 50}, 0, 0, 0, 0, 0, 0, false, false});
       platforms.push_back(Object {SDL_Rect{0, LAVA_DEPTH - 6800, 200, 50}, 0, 0, 0, 0, 0, 0, false, false});


        platforms.push_back(Object {SDL_Rect{300, LAVA_DEPTH - 6700, 1300, 80}, 0, 0, 0, 0, 0, 0, false, false});
        platforms.push_back(Object {SDL_Rect{200, LAVA_DEPTH - 6500, 500, 100}, 0, 0, 0, 0, 0, 0, false, false});

        platforms.push_back(Object {SDL_Rect{200, LAVA_DEPTH - 6400, 700, 50}, 0, 0, 0, 0, 0, 0, false, false});

        platforms.push_back(Object {SDL_Rect{700, LAVA_DEPTH - 6200, 900, 50}, 0, 0, 0, 0, 0, 0, false, false});
         platforms.push_back(Object {SDL_Rect{530, LAVA_DEPTH - 6050, 240, 50}, 0, 0, 0, 0, 0, 0, false, false});
         platforms.push_back(Object {SDL_Rect{560, LAVA_DEPTH - 5860, 180, 50}, 0, 0, 0, 0, 0, 0, false, false});
         platforms.push_back(Object {SDL_Rect{580, LAVA_DEPTH - 5670, 140, 50}, 0, 0, 0, 0, 0, 0, false, false});
        platforms.push_back(Object {SDL_Rect{600, LAVA_DEPTH - 5480, 100, 50}, 0, 0, 0, 0, 0, 0, false, false});
        platforms.push_back(Object {SDL_Rect{600, LAVA_DEPTH - 5290, 100, 50}, 0, 0, 0, 0, 0, 0, false, false});
        platforms.push_back(Object {SDL_Rect{600, LAVA_DEPTH - 5100, 100, 50}, 0, 0, 0, 0, 0, 0, false, false});
        platforms.push_back(Object {SDL_Rect{800, LAVA_DEPTH - 5000, 100, 50}, 0, 0, 0, 0, 0, 0, false, false});
        platforms.push_back(Object {SDL_Rect{1000, LAVA_DEPTH - 4900, 100, 50}, 0, 0, 0, 0, 0, 0, false, false});
        platforms.push_back(Object {SDL_Rect{1200, LAVA_DEPTH - 4800, 200, 50}, 0, 0, 0, 0, 0, 0, false, false});




        platforms.push_back(Object {SDL_Rect{800, LAVA_DEPTH - 4600, 100, 50}, -5, 0, 800, 1200, 0, 0, false, false});


       platforms.push_back(Object {SDL_Rect{700, LAVA_DEPTH - 4400, 100, 50}, -5, 0, 200, 750, 0, 0, false, false});     platforms.push_back(Object {SDL_Rect{1000, LAVA_DEPTH - 4400, 100, 50}, -5, 0, 800, 1200, 0, 0, false, false});

        platforms.push_back(Object {SDL_Rect{500, LAVA_DEPTH - 4200, 100, 50}, -3, 0, 500, 1000, 0, 0, false, false});     platforms.push_back(Object {SDL_Rect{1000, LAVA_DEPTH - 4200, 100, 50}, -6, 0, 1000, 1400, 0, 0, false, false});

        platforms.push_back(Object {SDL_Rect{400, LAVA_DEPTH - 4000, 100, 50}, 0, 0, 0, 0, 0, 0, false, false});
        platforms.push_back(Object {SDL_Rect{200, LAVA_DEPTH - 3800, 100, 50}, 0, 0, 0, 0, 0, 0, false, false});
        platforms.push_back(Object {SDL_Rect{400, LAVA_DEPTH - 3600, 100, 50}, 0, 0, 0, 0, 0, 0, false, false});
        platforms.push_back(Object {SDL_Rect{200, LAVA_DEPTH - 3400, 100, 50}, 0, 0, 0, 0, 0, 0, false, false});


        platforms.push_back(Object {SDL_Rect{400, LAVA_DEPTH - 3300, 50, 50}, -3, -3, 400, 740, LAVA_DEPTH - 3300, LAVA_DEPTH - 2960, false, false});
        platforms.push_back(Object {SDL_Rect{1100, LAVA_DEPTH - 2600, 50, 50}, -3, -3, 760, 1100, LAVA_DEPTH - 2940, LAVA_DEPTH - 2600, false, false});


         platforms.push_back(Object {SDL_Rect{1200, LAVA_DEPTH - 2500, 50, 50}, 0, 0, 0, 0, 0, 0, false, false});
        platforms.push_back(Object {SDL_Rect{1000, LAVA_DEPTH - 2300, 50, 50}, 0, 0, 0, 0, 0, 0, false, false});
        platforms.push_back(Object {SDL_Rect{800, LAVA_DEPTH - 2100, 50, 50}, 0, 0, 0, 0, 0, 0, false, false});
        platforms.push_back(Object {SDL_Rect{900, LAVA_DEPTH - 1900, 50, 50}, 0, 0, 0, 0, 0, 0, false, false});


         platforms.push_back(Object {SDL_Rect{1150, LAVA_DEPTH - 1900, 100, 150}, 0, 0, 0, 0, 0, 0, false, false});
        platforms.push_back(Object {SDL_Rect{1350, LAVA_DEPTH - 1700, 50, 50}, 0, 0, 0, 0, 0, 0, false, false});




        platforms.push_back(Object {SDL_Rect{1000, LAVA_DEPTH - 1500, 500, 50}, 0, 0, 0, 0, 0, 0, false, false});



        platforms.push_back(Object {SDL_Rect{600, LAVA_DEPTH - 1400, 200, 50}, 0, 0, 0, 0, 0 , 0, false, false});
        platforms.push_back(Object {SDL_Rect{600, LAVA_DEPTH - 1400, 200, 50}, 0, 0, 0, 0, 0 , 0, false, false});
        platforms.push_back(Object {SDL_Rect{400, LAVA_DEPTH - 1200, 200, 50}, 0, 0, 0, 0, 0 , 0, false, false});
        platforms.push_back(Object {SDL_Rect{600, LAVA_DEPTH - 1000, 200, 50}, 0, 0, 0, 0, 0, 0, false, false});
        platforms.push_back(Object {SDL_Rect{700, LAVA_DEPTH - 900, 200, 50}, 0, 0, 0, 0, 0, 0, false, false});
        platforms.push_back(Object {SDL_Rect{900, LAVA_DEPTH - 750, 200, 50}, 0, 0, 0, 0, 0, 0, false, false});
        platforms.push_back(Object {SDL_Rect{1100, LAVA_DEPTH - 600, 200, 50}, 0, 0, 0, 0, 0, 0, false, false});
        platforms.push_back(Object {SDL_Rect{900, LAVA_DEPTH - 500, 200, 50}, 0, 0, 0, 0, 0, 0, false, false});
        platforms.push_back(Object {SDL_Rect{600, LAVA_DEPTH - 400, 200, 50}, 0, 0, 0, 0, 0, 0, false, false});
        platforms.push_back(Object {SDL_Rect{300, LAVA_DEPTH - 300, 200, 50}, 0, 0, 0, 0, 0, 0, false, false});





        dragons.push_back(Object {SDL_Rect{0, LAVA_DEPTH -15500, 200, 200}, 0, 0, 0, 0, 0, 0, false, false});
        fires.push_back(Object {SDL_Rect{200, LAVA_DEPTH -15450, 600, 150}, 0, 0, 0, 0, 0, 0, false, false});

        dragons.push_back(Object {SDL_Rect{1400, LAVA_DEPTH -15300, 200, 200}, 0, 0, 0, 0, 0, 0, false, false});
        fires.push_back(Object {SDL_Rect{801, LAVA_DEPTH -15250, 600, 150}, 0, 0, 0, 0, 0, 0, false, false});

        dragons.push_back(Object {SDL_Rect{0, LAVA_DEPTH -15100, 200, 200}, 0, 0, 0, 0, 0, 0, false, false});
        fires.push_back(Object {SDL_Rect{200, LAVA_DEPTH -15050, 600, 150}, 0, 0, 0, 0, 0, 0, false, false});

        dragons.push_back(Object {SDL_Rect{1400, LAVA_DEPTH -14900, 200, 200}, 0, 0, 0, 0, 0, 0, false, false});
        fires.push_back(Object {SDL_Rect{801, LAVA_DEPTH -14850, 600, 150}, 0, 0, 0, 0, 0, 0, false, false});


        dragons.push_back(Object {SDL_Rect{0, LAVA_DEPTH -14700, 200, 200}, 0, 0, 0, 0, 0, 0, false, false});
        fires.push_back(Object {SDL_Rect{200, LAVA_DEPTH -14650, 600, 150}, 0, 0, 0, 0, 0, 0, false, false});

        dragons.push_back(Object {SDL_Rect{1400, LAVA_DEPTH -14500, 200, 200}, 0, 0, 0, 0, 0, 0, false, false});
        fires.push_back(Object {SDL_Rect{801, LAVA_DEPTH -14450, 600, 150}, 0, 0, 0, 0, 0, 0, false, false});

        dragons.push_back(Object {SDL_Rect{0, LAVA_DEPTH -14300, 200, 200}, 0, 0, 0, 0, 0, 0, false, false});
        fires.push_back(Object {SDL_Rect{200, LAVA_DEPTH -14250, 600, 150}, 0, 0, 0, 0, 0, 0, false, false});

        dragons.push_back(Object {SDL_Rect{1400, LAVA_DEPTH -14100, 200, 200}, 0, 0, 0, 0, 0, 0, false, false});
        fires.push_back(Object {SDL_Rect{801, LAVA_DEPTH -14050, 600, 150}, 0, 0, 0, 0, 0, 0, false, false});




        dragons.push_back(Object {SDL_Rect{0, LAVA_DEPTH - 10800, 400, 400}, 0, 0, 0, 0, 0, 0, false, false});
        fires.push_back(Object {SDL_Rect{400, LAVA_DEPTH - 10700, 500, 200}, 0, 0, 0, 0, 0, 0, false, false});


        dragons.push_back(Object {SDL_Rect{0, LAVA_DEPTH - 6700, 200, 200}, 0, 0, 0, 0, 0, 0, false, false});
        fires.push_back(Object {SDL_Rect{200, LAVA_DEPTH - 6680, 1200, 190}, 0, 0, 0, 0, 0, 0, false, false});


        dragons.push_back(Object {SDL_Rect{0, LAVA_DEPTH -1700, 200, 200}, 0, 0, 0, 0, 0, 0, false, false});
        fires.push_back(Object {SDL_Rect{200, LAVA_DEPTH -1700, 1000, 180}, 0, 0, 0, 0, 0, 0, false, false});


        dragons.push_back(Object {SDL_Rect{1400, LAVA_DEPTH -1300, 200, 200}, 0, 0, 0, 0, 0, 0, false, false});
        fires.push_back(Object {SDL_Rect{201, LAVA_DEPTH -1300, 1200, 200}, 0, 0, 0, 0, 0, 0, false, false});



        platformTexture = loadTexture("image/platform.png", renderer);
        platformUpTexture = loadTexture("image/platformUp.png", renderer);
        platformDownTexture = loadTexture("image/platformDown.png", renderer);
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

    for (const auto& it : platforms) {
            if(it.canTriggerUp)
            {
                 SDL_Rect platformRect = { it.rect.x, it.rect.y - camera.y , it.rect.w, it.rect.h };
            SDL_RenderCopy(renderer, platformUpTexture, NULL, &platformRect);
            }
            else if(it.canTriggerDown)
            {
                 SDL_Rect platformRect = { it.rect.x, it.rect.y - camera.y , it.rect.w, it.rect.h };
            SDL_RenderCopy(renderer, platformDownTexture, NULL, &platformRect);
            }
            else
            {
            SDL_Rect platformRect = { it.rect.x, it.rect.y - camera.y , it.rect.w, it.rect.h };
            SDL_RenderCopy(renderer, platformTexture, NULL, &platformRect);
            }
        }



    for (const auto& it : dragons) {
            if(it.rect.x <300){
            SDL_Rect dragonRect = { it.rect.x, it.rect.y - camera.y , it.rect.w, it.rect.h };
            SDL_RenderCopy(renderer, dragonTexture[frame/20%4], NULL, &dragonRect);
        }
            else
            {
                SDL_Rect dragonRect = { it.rect.x, it.rect.y - camera.y , it.rect.w, it.rect.h };
            SDL_RenderCopyEx(renderer, dragonTexture[frame/20%4], NULL, &dragonRect, 0, NULL, SDL_FLIP_HORIZONTAL);
            }
    }


    for (const auto& it : fires) {
            if (frame >= 0 && frame <= 14 || frame >= 150 && frame <= 164 ){
            if(it.rect.x%2==0){
            SDL_Rect fireRect = { it.rect.x, it.rect.y - camera.y , it.rect.w, it.rect.h };
            SDL_RenderCopy(renderer, fireTexture, NULL, &fireRect);
        }
            else
            {
                SDL_Rect fireRect = { it.rect.x, it.rect.y - camera.y , it.rect.w, it.rect.h };
            SDL_RenderCopyEx(renderer, fireTexture, NULL, &fireRect, 0, NULL, SDL_FLIP_HORIZONTAL);
            }
    }
    }
    if (current_gStatus == MENU) {


        SDL_Color white = { 255, 255, 255, 255 };
        SDL_Texture* menuText = loadTextTexture("Start Game", white);
        SDL_Rect textRect = { 800, 450, 500, 300 };
        SDL_RenderCopy(renderer, menuText, NULL, &textRect);
        SDL_DestroyTexture(menuText);
    }
    }



    void Object::update(){
    for (auto& it : platforms) {




            it.rect.x += it.vx;
            it.rect.y += it.vy;


    if(it.minX!=0){

    if (it.rect.x <= it.minX) {
            it.rect.x = it.minX;
            it.vx = abs(it.vx);
        }
        else if (it.rect.x + it.rect.w >= it.maxX) {
            it.rect.x = it.maxX - it.rect.w;
            it.vx = -abs(it.vx);
        }
    }

    if (it.minY!=0){
    if (it.rect.y <= it.minY) {
            it.rect.y = it.minY;
            it.vy = abs(it.vy);
        }
        else if (it.rect.y + it.rect.h >= it.maxY) {
            it.rect.y = it.maxY - it.rect.h;
            it.vy = -abs(it.vy);
        }


    }
    }


        for (auto& it : dragons) {
            it.rect.x += it.vx;
            it.rect.y += it.vy;
    }

    for (auto it = platforms.begin(); it != platforms.end();) {
           if (checkCollision(it->rect, lava.rect)) {
                it = platforms.erase(it);
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
        for (auto it = fires.begin(); it != fires.end();) {
            if (checkCollision(it->rect, lava.rect)) {
                it = fires.erase(it);
            } else {
                it++;
            }
        }
    }

