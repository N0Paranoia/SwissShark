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

bool Collision::CheckCircleCollision(Circle a, SDL_Rect b)
{
	//Find closest x offset
	if(a.x < b.x)
	{
		circX = b.x;
	}
	else if(a.x > b.x + b.w)
	{
		circX = b.x + b.w;
	}
	else
	{
		circX = a.x;
	}

	//Find closest y offset
	if(a.y < b.y)
	{
		circY = b.y;
	}
	else if(a.y > b.y + b.h)
	{
		circY = b.y + b.h;
	}
	else
	{
		circY = a.y;
	}

	//If the closest point is inside the circle
	if(this->distanceSquared(a.x, a.y, circX, circY) < a.r*a.r)
	{
		return true;
	}
	return false;
}

double Collision::distanceSquared(int x1, int y1, int x2, int y2)
{
	int deltaX = x2 - x1;
	int deltaY = y2 - y1;
	
	return deltaX*deltaX + deltaY*deltaY;
}

bool Collision::VarCollision(SDL_Rect cBox, Tile* tiles[], int type)
	{
	for(int i = 0; i < TOTAL_TILES; i++)
	{
		if(tiles[i]->getType() == type)
		{
			if(this->CheckCollision(cBox, tiles[i]->getTileBox()))
			{
				return true;
			}
		}
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

bool Collision::CircleCollision(Circle cCircle, Tile* tiles[])
{    
	for(int i = 0; i < TOTAL_TILES; i++)
	{
		if(tiles[i]->getType() > TILE_CLEAR)
		{
			if(this->CheckCircleCollision(cCircle, tiles[i]->getTileBox()))
			{
				return true;
			}
		}
	}
	return false;
}