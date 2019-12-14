#ifndef DEF_RENDERENGINE
#define DEF_RENDERENGINE
#include <SDL2/SDL.h>
#include "types.h"

Point findIntersection (LineEquation l1, LineEquation l2);

int intersects(LineEquation l1, LineEquation l2);

int distance(Point p1, Point p2);

LineEquation lineEquationPoint(Point p1, Point p2);

LineEquation lineEquationLine(Line line);

Line getPlayerLine(Player *player, int angle);

LineEquation getPlayerLineEquation(Player *player, int angle);

void drawWall (SDL_Renderer *renderer, Line line, Player *player);

#endif