#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include "mapViewer.h"
#include "types.h"
#include "eventHandler.h"

int main()
{

    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("Oh noes SDL could not be initialised, exiting!\n");
        printf("Error is : %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }



    SDL_Window *map_window = SDL_CreateWindow("MAP", 100,100,640,480, SDL_WINDOW_SHOWN);

    if (map_window == NULL)
    {
        printf("SDL Error : %s\n", SDL_GetError);
        SDL_Quit();
        return 1;
    }

    SDL_Window *game_window = SDL_CreateWindow("GAME", 100,100,640,480, SDL_WINDOW_SHOWN);

    if (game_window == NULL)
    {
        printf("SDL Error : %s\n", SDL_GetError);
        SDL_Quit();
        return 1;
    }


    SDL_Renderer *map_renderer = SDL_CreateRenderer(map_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (map_renderer == NULL)
    {
        printf("SDL Error : %s\n", SDL_GetError);
        SDL_Quit();
        return 1;
    }
    
    SDL_Renderer *game_renderer = SDL_CreateRenderer(game_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (game_renderer == NULL)
    {
        printf("SDL Error : %s\n", SDL_GetError);
        SDL_Quit();
        return 1;
    }


    SDL_Surface *canvas = SDL_CreateRGBSurface(0, 640, 480, 4, 0, 0, 0, 0);

    int playing = 1;

    Line *lines = NULL;
    int lineCount = 0;
    lineCount = loadMap("map.fmap", &lines);


    printLines(lines, lineCount);
    
    Player player;
    player.x = 0;
    player.y = 0;
    player.angle = 0;
    while (playing)
    {
        
        SDL_SetRenderDrawColor(map_renderer, 0,0,0, 255);
        SDL_RenderClear(map_renderer);
        SDL_SetRenderDrawColor(map_renderer, 255,255,255, 255);

        drawLines(map_renderer, lines, lineCount);
        drawPlayer(map_renderer, &player);
        SDL_RenderPresent(map_renderer);

        SDL_RenderPresent(game_renderer);

        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                playing = 0;
            }
            else
            {
                movePlayer(&player, event);
            }
            
        }
        
        SDL_Delay(10);

    }
    free(lines);
    SDL_DestroyRenderer(map_renderer);
    SDL_DestroyRenderer(game_renderer);
    SDL_DestroyWindow(map_window);
    SDL_DestroyWindow(game_window);
    SDL_Quit();

    return 0;
}
