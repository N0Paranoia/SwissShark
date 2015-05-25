#include "Tile.h"
#include "Constants.h"
#include "Textures.h"
#include "Collision.h"

Collision collision;

Tile::Tile(int x, int y, int Type)
{
    TileBox.x = x;
    TileBox.y = y;
    TileBox.w = TILE_SIZE;
    TileBox.h = TILE_SIZE;

    TileType = Type;
}

Tile::~Tile()
{
    //dtor
}

int Tile::getType()
{
    return TileType;
}

SDL_Rect Tile::getTileBox()
{
    return TileBox;
}

void Tile::Render(Textures* textures, SDL_Rect* clips, SDL_Renderer* Renderer, SDL_Rect* camera)
{
    if(collision.CheckCollision(TileBox, *camera))
    {
        textures->Render(Renderer, TileBox.x - camera->x, TileBox.y - camera->y, &clips[TileType]);
    }
}
