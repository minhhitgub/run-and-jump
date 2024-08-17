
#include "functions.hpp"




bool checkCollision(const SDL_Rect& obj1, const SDL_Rect& obj2) {
    return SDL_HasIntersection(&obj1, &obj2);
}

void pause(){
checkPause = !checkPause;
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
