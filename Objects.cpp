#include "Objects.h"
#include "Constants.h"

using namespace std;


Objects::Objects()
{
	fisherman.x = 16*TILE_SIZE;
	fisherman.y = 0*TILE_SIZE;
	fisherman.w = TILE_SIZE/8;
	fisherman.h = 6*TILE_SIZE;
	
	door.x = 22*TILE_SIZE; 
	door.y = 10*TILE_SIZE;
	door.w = TILE_SIZE/2;
	door.h = TILE_SIZE;
	
	diver.x = 35*TILE_SIZE;
	diver.y = 0*TILE_SIZE;
	diver.w = TILE_SIZE/4;
	diver.h = 11*TILE_SIZE;
	
	item_saw.x = 20*TILE_SIZE;
	item_saw.y = 1*TILE_SIZE;
	item_saw.w = TILE_SIZE;
	item_saw.h = TILE_SIZE/4;
	
	item_sword.x = 23*TILE_SIZE;
	item_sword.y = 1*TILE_SIZE;
	item_sword.w = TILE_SIZE;
	item_sword.h = TILE_SIZE/4;
}

Objects::~Objects()
{
}

SDL_Rect Objects::Fisherman()
{
	return fisherman;
}

SDL_Rect Objects::Door()
{
	return door;
}

SDL_Rect Objects::Diver()
{
	return diver;
}

SDL_Rect Objects::Item_Saw()
{
	return item_saw;
}

SDL_Rect Objects::Item_Sword()
{
	return item_sword;
}

void Objects::Update(int action)
{
	int pickupSaw = 1;
	if(action == pickupSaw)
	{
		item_saw.x = 0;
		item_saw.y = 0;
		item_saw.w = 0;
		item_saw.h = 0;
	}
	int pickupSword = 2;
	if(action == pickupSword)
	{
		item_sword.x = 0;
		item_sword.y = 0;
		item_sword.w = 0;
		item_sword.h = 0;
	}
	int openDoor = 10;
	if(action == openDoor)
	{
		door.x = 0; 
		door.y = 0;
		door.w = 0;
		door.h = 0;
	}
	int killDiver = 11;
	if(action == killDiver)
	{
		diver.x = 0; 
		diver.y = 0;
		diver.w = 0;
		diver.h = 0;
	}
}

void Objects::Render(SDL_Renderer* Renderer, SDL_Rect* camera, bool doorStatus, bool diverStatus, bool sawStatus, bool swordStatus)
{
	fishermanSprite = {fisherman.x - camera->x, fisherman.y - camera->y, fisherman.w, fisherman.h};
	doorSprite = {door.x - camera->x, door.y - camera->y, door.w, door.h};
	diverSprite = {diver.x - camera->x, diver.y - camera->y, diver.w, diver.h};
	item_sawSprite = {item_saw.x - camera->x, item_saw.y - camera->y, item_saw.w, item_saw.h};
	item_swordSprite = {item_sword.x - camera->x, item_sword.y - camera->y, item_sword.w, item_sword.h};
	SDL_SetRenderDrawColor(Renderer, 0xff, 0xff, 0x00, 0x00);
	if(!doorStatus)
	{
		SDL_RenderFillRect(Renderer, &doorSprite);
	}
	if(!sawStatus)
	{
		SDL_RenderFillRect(Renderer, &item_sawSprite);
	}
	SDL_SetRenderDrawColor(Renderer, 0xff, 0x00, 0xff, 0x00);
	if(!diverStatus)
	{
		SDL_RenderFillRect(Renderer, &diverSprite);
	}
	if(!swordStatus)
	{
		SDL_RenderFillRect(Renderer, &item_swordSprite);
	}
	SDL_SetRenderDrawColor(Renderer, 0xff, 0x00, 0x00, 0x00);
	SDL_RenderFillRect(Renderer, &fishermanSprite);
	
}