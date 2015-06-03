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

bool CheckCircleCollision(Circle& a, SDL_Rect b)
{
	//Closest point on collision box
	int cX, cY;

	//Find closest x offset
	if( a.x < b.x )
	{
		cX = b.x;
	}
	else if( a.x > b.x + b.w )
	{
		cX = b.x + b.w;
	}
	else
	{
		cX = a.x;
	}

	//Find closest y offset
	if( a.y < b.y )
	{
		cY = b.y;
	}
	else if( a.y > b.y + b.h )
	{
		cY = b.y + b.h;
	}
	else
	{
		cY = a.y;
	}

	//If the closest point is inside the circle
//	if( distanceSquared( a.x, a.y, cX, cY) < a.r * a.r )
//	{
//		return true;
//	}
	return false;
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
