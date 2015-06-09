#include "Objects.h"
#include "Constants.h"

using namespace std;


Objects::Objects()
{
	door.x = 22*TILE_SIZE; 
	door.y = 10*TILE_SIZE;
	door.w = TILE_SIZE/2;
	door.h = TILE_SIZE;
	
	brokenDoor = false;
}

Objects::~Objects()
{
}

SDL_Rect Objects::Chest()
{
	chest = {4 * TILE_SIZE, TILE_SIZE, 2*TILE_SIZE, TILE_SIZE};
	return chest;
}

SDL_Rect Objects::Door()
{
	return door;
}

void Objects::Render(SDL_Renderer* Renderer, SDL_Rect* camera)
{
	this->Chest();
	this->Door();
	SDL_SetRenderDrawColor(Renderer, 0xff, 0xff, 0x00, 0x00);
	test = {door.x - camera->x, door.y - camera->y, door.w, door.h};
	
	SDL_RenderFillRect(Renderer, &chest);
	SDL_RenderFillRect(Renderer, &test);
}