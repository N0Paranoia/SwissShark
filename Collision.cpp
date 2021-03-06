#include "Collision.h"

Collision::Collision()
{
    //ctor
}

Collision::~Collision()
{
    //dtor
}

bool Collision::CheckCollision(SDL_Rect a, SDL_Rect b)
{
	leftA = a.x;
	rightA = a.x + a.w;
	topA = a.y;
	bottomA = a.y + a.h;

	leftB = b.x;
	rightB = b.x + b.w;
	topB = b.y;
	bottomB = b.y + b.h;

	if(bottomA <= topB)
	{
		return false;
	}
	if(topA >= bottomB)
	{
		return false;
	}
	if(rightA <= leftB)
	{
		return false;
	}
	if(leftA >= rightB)
	{
		return false;
	}
	return true;
}

bool Collision::VarCollision(SDL_Rect cBoxA, SDL_Rect cBoxB)
{
	if(this->CheckCollision(cBoxA, cBoxB))
	{
		return true;
	}
	return false;
}

bool Collision::CustomCollision(SDL_Rect cBoxA, int x, int y, int w, int h)
{
	customRect = {x ,y, w, h};
	if(this->CheckCollision(cBoxA, customRect))
	{
		return true;
	}
	return false;
}

bool Collision::WallCollision(SDL_Rect cBox, Tile* tiles[])
{
	for(int i = 0; i < TOTAL_TILES; i++)
	{
		if(tiles[i]->getType() > TILE_CLEAR)
		{
			if(this->CheckCollision(cBox, tiles[i]->getTileBox()))
			{
				return true;
			}
		}
	}
	return false;
}
