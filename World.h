#ifndef WORLD_H
#define WORLD_H

#include <SDL.h>
#include "Constants.h"
#include "Tile.h"

class World
{
    public:
        World();
        virtual ~World();
        int Init(int x, int y, int TileType);
        int LoadMedia(SDL_Renderer* Renderer, Tile* tiles[]);
        bool SetTiles(Tile* tiles[]);
        void Render(SDL_Renderer* Renderer, SDL_Rect* camera, Tile* tiles[]);
    protected:
    private:
    public:
        SDL_Rect TileClips[TOTAL_TILE_SPRITES];
        int Type;
};

#endif // WORLD_H
