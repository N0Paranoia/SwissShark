#ifndef COLLISION_H
#define COLLISION_H
#include "Constants.h"
#include "Tile.h"
#include <SDL.h>


class Collision
{
	public:
		Collision();
		virtual ~Collision();
		bool CheckCollision(SDL_Rect a, SDL_Rect b);
		bool VarCollision(SDL_Rect cBoxA, SDL_Rect cBoxB);
		bool WallCollision(SDL_Rect cBox, Tile* tiles[]);
		double distanceSquared( int x1, int y1, int x2, int y2 );

	protected:
	private:
		int leftA, leftB;
		int rightA, rightB;
		int topA, topB;
		int bottomA, bottomB;
};

#endif // COLLISION_H
