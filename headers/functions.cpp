
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
                 lava.vy = 1;
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



void showHealth()
{
    static std::vector<SDL_Texture*> healthTextures;
    static std::vector<SDL_Rect> healthPositions;


    if (healthTextures.empty()) {
        for (int i = 0; i < 5; i++) {
            SDL_Texture* healthTexture = loadTexture("image/health.png", renderer);
            healthTextures.push_back(healthTexture);
            SDL_Rect pos = { i * 50, 20, 80, 80 };
            healthPositions.push_back(pos);
        }
    }


    for (int i = 0; i < healthTextures.size()-healthLoss; i++) {
        SDL_RenderCopy(renderer, healthTextures[i], NULL, &healthPositions[i]);
    }
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
