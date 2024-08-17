
#include "functions.hpp"




bool checkCollision(const SDL_Rect& obj1, const SDL_Rect& obj2) {
    return SDL_HasIntersection(&obj1, &obj2);
}

void pause(){
checkPause = !checkPause;
}



void processInput(SDL_Event& e)
{
    if (e.type == SDL_KEYDOWN) {
        switch (e.key.keysym.sym) {
            case SDLK_RETURN:
                 lava.vy = 2;
             current_gStatus = PLAY;

             break;
             case SDLK_TAB:
             pause();
             break;
             case SDLK_ESCAPE:
             running = false;
             break;

        }
    }
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



SDL_Texture* loadTextTexture(const std::string& text, const SDL_Color& color)
{
    TTF_Font* font = TTF_OpenFont("Xerox Sans Serif Wide Bold.ttf", 24);


    SDL_Surface* textSurface = TTF_RenderText_Solid(font, text.c_str(), color);


    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

    SDL_FreeSurface(textSurface);
    TTF_CloseFont(font);

    return textTexture;
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
