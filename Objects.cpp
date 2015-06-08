#include "Objects.h"
#include "Constants.h"

using namespace std;

Objects::Objects()
{

}

Objects::~Objects()
{
}

void Objects::Chest(int playerX, int playerY)
{
	chest = {4 * TILE_SIZE, TILE_SIZE, 2*TILE_SIZE, TILE_SIZE};
}

bool Objects::Door(int playerX, int playerY)
{
	door.x = 22*TILE_SIZE; 
	door.y = 10*TILE_SIZE;
	
	if(playerX == door.x && playerY == door.y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Objects::Render(SDL_Renderer* Renderer, SDL_Rect* camera)
{
	this->Chest(NULL, NULL);
	this->Door(NULL, NULL);
	door = {door.x - camera->x, door.y - camera->y, TILE_SIZE/4, TILE_SIZE};
	SDL_SetRenderDrawColor(Renderer, 0xff, 0xff, 0xff, 0xff);
	SDL_RenderFillRect(Renderer, &chest);
	SDL_RenderFillRect(Renderer, &door);	
}