#include "renderEngine.h" 
#include <math.h>
#include <SDL2/SDL.h>
#include "types.h"

#define PI 3.14159
#define FOV 80



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


LineEquation lineEquationPoint(Point p1, Point p2)
{
    LineEquation result;
    result.a = p2.y - p1.y;
    result.b = p2.x - p1.x;
    result.c = (p1.y - p2.y) * p1.x + (p2.x - p1.x) * p1.y;

    return result;
}

LineEquation lineEquationLine(Line line)
{
    Point p1, p2;
    p1.x = line.x1;
    p1.y = line.y1;
    p2.x = line.x2;
    p2.y = line.y2;

    return lineEquationPoint(p1, p2);
}

Line getPlayerLine(Player *player, int angle)
{
    int player_view_x = player->x + floor( 100.0 * cos(angle * PI / 180));
    int player_view_y = player->y + floor( 100.0 * sin(angle * PI / 180));

    Line result;
    result.x1 = player->x;
    result.y1 = player->y;
    result.x2 = player_view_x;
    result.y2 = player_view_y;

    return result;

}

LineEquation getPlayerLineEquation (Player *player, int angle)
{
    return lineEquationLine(getPlayerLine(player, angle));
}

void drawWall (SDL_Renderer *renderer, Line wall, Player *player)
{
    LineEquation wall_equation = lineEquationLine(wall);
    Point player_position;
    player_position.x = player->x;
    player_position.y = player->y;
    LineEquation current_ray;
    SDL_Rect current_rect;
    current_rect.x = 0;
    current_rect.y = 0;
    current_rect.w = 640/FOV;
    current_rect.h = 480;
    int maxi;
    for (int i = (player->angle - FOV/2); i < (player->angle + FOV/2); i++)
    {
        current_ray = getPlayerLineEquation(player, (i+360)%360);

        if (intersects(wall_equation, current_ray))
        {
            current_rect.h = 480 / distance(player_position, findIntersection(wall_equation, current_ray));
            current_rect.h *= 30;
            current_rect.y = (480 - current_rect.h)/2;

            SDL_RenderFillRect(renderer, &current_rect);
        
        }
        else
        {
            printf("No intersection\n");
        }
        
        current_rect.x += 640/FOV;
        maxi = i;

    }

    printf("%d\n", maxi);

}