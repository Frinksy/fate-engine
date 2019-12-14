#ifndef DEF_TYPES
#define DEF_TYPES
#include <SDL2/SDL_types.h>

typedef struct Point Point;
struct Point
{
    int x;
    int y;
};


typedef struct Line Line;
struct Line
{
    int x1;
    int y1;
    int x2;
    int y2;
};

typedef struct Player Player;
struct Player
{
    int x;
    int y;
    unsigned int angle;
};


typedef struct LineEquation LineEquation;
struct LineEquation
{
    float a;
    float b; 
    float c;
};


#endif