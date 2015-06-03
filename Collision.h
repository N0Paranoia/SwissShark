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
		bool CheckCircleCollision(Circle& a, SDL_Rect b);
		bool VarCollision(SDL_Rect cBox, Tile* tiles[], int type);
		bool WallCollision(SDL_Rect cBox, Tile* tiles[]);
		bool CircleCollision(Circle& cCircle, Tile* tiles[]);

	protected:
	private:
		int leftA, leftB;
		int rightA, rightB;
		int topA, topB;
		int bottomA, bottomB;
};

#endif // COLLISION_H
