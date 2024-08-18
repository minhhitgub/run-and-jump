#include "load.hpp"




int Load()
{
if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf ("Unable to initialize SDL!\n");
        SDL_GetError();
        return -1;
    }


    window = SDL_CreateWindow("Run and Jump", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        printf ("Unable to create window!\n");
        destroy();
        return -1;
    }



     renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf ("Unable to create renderer!\n");
        destroy();
        return -1;
    }

   backgroundTexture[0] = loadTexture("image/bg1.png", renderer);

   backgroundTexture[1] = loadTexture("image/bg2.png", renderer);
   backgroundTexture[2] = loadTexture("image/bg3.png", renderer);
   backgroundTexture[3] = loadTexture("image/bg4.png", renderer);
   victoryTexture = loadTexture("image/victory.png", renderer);
   overTexture = loadTexture("image/gameOver.png", renderer);





    if (Mix_Init(MIX_INIT_MP3) == 0)
        {
            printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
        }


    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
       {
            printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
            return -1;
        }


    gMusic = Mix_LoadMUS("music/backgroundMusic.mp3");
    hitSound = Mix_LoadWAV("music/hitSound.wav");
    if (!gMusic)
        {
            printf("Failed to load music: %s\n", Mix_GetError());
        }

     if (Mix_PlayMusic(gMusic, -1) == -1)
        {
            printf("Failed to play music! SDL_mixer Error: %s\n", Mix_GetError());
        }


    if (TTF_Init() == -1) {
        printf("Unable to initialize SDL_ttf: %s\n", TTF_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }







}
