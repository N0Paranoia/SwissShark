#ifndef TILE_H
#define TILE_H

#include <SDL.h>
#include "Textures.h"

class Tile
{
	public:
		Tile(int x, int y, int Type);
		virtual ~Tile();
		int getType();
		SDL_Rect getTileBox();
		void Render(Textures* textures, SDL_Rect* clips, SDL_Renderer* Renderer, SDL_Rect* camera);
	protected:
	private:
	public:
		int TileType;
		SDL_Rect TileBox;
};

#endif // TILE_H
