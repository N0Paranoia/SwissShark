#include "Doors.h"

Doors::Doors()
{
	doorA[0].x = 10*TILE_SIZE;
	doorA[1].x = 19*TILE_SIZE;
	doorA[0].y = 3*TILE_SIZE;
	doorA[1].y = 3*TILE_SIZE;

	doorB[0].x = 2*TILE_SIZE;
	doorB[1].x = 27*TILE_SIZE;
	doorB[0].y = 26*TILE_SIZE;
	doorB[1].y = 26*TILE_SIZE;
}

Doors::~Doors()
{
    //dtor
}

void Doors::Connection(SDL_Rect* player, int z)
{
    for(int i = 0; i < TOTAL_DOORS; i++)
    {
        if(player->x >= doorA[i].x - TILE_SIZE/2 && player->x <= doorA[i].x + TILE_SIZE/2 && player->y >= doorA[i].y - TILE_SIZE/2 && player->y <= doorA[i].y)
        {
            player->x = doorB[i].x;
            player->y = doorB[i].y;
        }
        else if(player->x >= doorB[i].x - TILE_SIZE/2 && player->x <= doorB[i].x + TILE_SIZE/2 && player->y >= doorB[i].y - TILE_SIZE/2 && player->y <= doorB[i].y)
        {
            player->x = doorA[i].x;
            player->y = doorA[i].y;
        }
    }
}
