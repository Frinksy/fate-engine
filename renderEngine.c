#include "renderEngine.h" 
#include <math.h>
#include <SDL2/SDL.h>
#include "types.h"

Point findIntersection (LineEquation l1, LineEquation l2)
{
    Point intersection;

    intersection.y = round((l2.a*l1.c - l1.a*l2.c) / (l1.a*l2.b - l2.a*l1.b));
    intersection.x = round(-(l1.b*intersection.y + l1.c)/l1.a);

    return intersection;
}


int intersects(LineEquation l1, LineEquation l2)
{
    return (l2.b*l1.a - l1.b*l2.a != 0);
}

int distance(Point p1, Point p2)
{
    return sqrt( (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y) );
}


LineEquation lineEquation(Point p1, Point p2)
{
    LineEquation result;
    result.a = p2.y - p1.y;
    result.b = p2.x - p1.x;
    result.c = (p1.y - p2.y) * p1.x + (p2.x - p1.x) * p1.y;
}



void drawWall (SDL_Renderer *renderer, Line line, Player *player)
{

}