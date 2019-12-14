#include "mapViewer.h"
#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include "types.h"
#include <math.h>

#define PI 3.14159

int loadMap (char *filename, Line **mapLines)
{
    FILE *file = fopen(filename, "r");
    char char_buffer;
    int count = 0;


    printf("Opening map %s\n", filename);
    if (file == NULL)
    {
        printf("Map %s could not be opened\n", filename);
    }
    else
    {
        
        do
        {
            char_buffer = fgetc(file);

            if (char_buffer == '\n')
            {
                count++;
            }

        }while (char_buffer != EOF);
        
        printf("There are %d lines in this map\n", count);

        Line *lines = malloc(sizeof(Line)*count);

        rewind(file);

        int x1, x2, y1, y2;
        for (int i = 0; i < count; i++)
        {  

            fscanf(file, "%d,%d,%d,%d", &x1, &y1, &x2, &y2);
            lines[i].x1 = x1;
            lines[i].y1 = y1;
            lines[i].x2 = x2;
            lines[i].y2 = y2;
        }

        *mapLines = lines;

        fclose(file);

    }
    

    return count;


}


void printLines(Line *lines, int length)
{
    Line *currentLine = lines;
    for (int i = 0; i < length; i++)
    {
       printf("%d %d %d %d\n", lines[i].x1, lines[i].y1, lines[i].x2, lines[i].y2);
    }
}


void drawLines(SDL_Renderer *renderer, Line *lines, int lineCount)
{
    for (int i = 0; i < lineCount; i++)
    {
        SDL_RenderDrawLine(renderer, lines[i].x1, lines[i].y1, lines[i].x2, lines[i].y2);
    }
}

void drawPlayer(SDL_Renderer *renderer, Player *player)
{   
    /*
    SDL_Rect player_rect;
    player_rect.x = player->x - 10;
    player_rect.y = player->y - 10;
    player_rect.w = 20;
    player_rect.h = 20;
    SDL_RenderDrawRect(renderer, &player_rect);
    */

    int player_view_x = player->x + floor( 20.0 * cos(player->angle * PI / 180));
    int player_view_y = player->y + floor( 20.0 * sin(player->angle * PI / 180));

    SDL_RenderDrawLine(renderer, player->x, player->y, player_view_x, player_view_y);

}
