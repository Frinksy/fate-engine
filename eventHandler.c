#include <stdlib.h>
#include <stdio.h>

#include "eventHandler.h"


void movePlayer(Player *player, SDL_Event event)
{
    if (event.type == SDL_KEYDOWN)
    {   
        switch (event.key.keysym.sym)
        {
        case SDLK_z:
            player->y -= 1;
            break;
        
        case SDLK_s:
            player->y += 1;
            break;

        case SDLK_q:
            player->x -= 1;
            break;

        case SDLK_d:
            player->x += 1;
            break;

        case SDLK_a:
            player->angle = (player->angle - 1 + 360 ) % 360;
            break;

        case SDLK_e:
            player->angle = (player->angle + 1 ) % 360;

        default:
            break;
        }
    }
}