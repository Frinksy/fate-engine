#ifndef DEF_MAPVIEWER
#define DEF_MAPVIEWER
#include "types.h"
#include "SDL2/SDL.h"
int loadMap(char *filename, Line **mapLines);

void printLines(Line *lines, int length);

void drawLines(SDL_Renderer *renderer, Line *lines, int lineCount);

void drawPlayer(SDL_Renderer *renderer, Player *player);

#endif