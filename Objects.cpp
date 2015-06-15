#include "Objects.h"
#include "Constants.h"
#include "Textures.h"

using namespace std;
Textures ItemSheetTexture;


Objects::Objects()
{
	fisherman.x = 16*TILE_SIZE;
	fisherman.y = 0*TILE_SIZE;
	fisherman.w = TILE_SIZE/8;
	fisherman.h = 5*TILE_SIZE;
	
	door.x = 21*TILE_SIZE + TILE_SIZE/2; 
	door.y = 9*TILE_SIZE;
	door.w = TILE_SIZE/2;
	door.h = 2*TILE_SIZE;
	
	diver.x = 35*TILE_SIZE;
	diver.y = 0*TILE_SIZE;
	diver.w = TILE_SIZE/4;
	diver.h = 11*TILE_SIZE;
	
	item_saw.x = 13*TILE_SIZE;
	item_saw.y = 10*TILE_SIZE;
	item_saw.w = TILE_SIZE;
	item_saw.h = TILE_SIZE;
	
	item_sword.x = 23*TILE_SIZE;
	item_sword.y = 2*TILE_SIZE;
	item_sword.w = TILE_SIZE;
	item_sword.h = TILE_SIZE;
}

Objects::~Objects()
{
}

int Objects::LoadMedia(SDL_Renderer* Renderer)
{
	//Load Item sheet
	if((ItemSheetTexture.LoadFromFile(Renderer, "../assets/itemSheet.png")) == NULL)
	{
		cout << "Unable to load Item Texture! SDL_Error: " << SDL_GetError() << endl;
		return false;
	}
	else
	{
		ObjectClips[0].x = 0;
		ObjectClips[0].y = 0;
		ObjectClips[0].w = TILE_SIZE;
		ObjectClips[0].h = TILE_SIZE;
		
		ObjectClips[1].x = 0;
		ObjectClips[1].y = TILE_SIZE;
		ObjectClips[1].w = TILE_SIZE;
		ObjectClips[1].h = TILE_SIZE;
	}	
	return true;
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
	SDL_SetRenderDrawColor(Renderer, 0xff, 0xff, 0x00, 0x00);
	if(!doorStatus)
	{
		SDL_RenderFillRect(Renderer, &doorSprite);
	}
	if(!sawStatus)
	{
		ItemSheetTexture.Render(Renderer, this->item_saw.x - camera->x, this->item_saw.y - camera->y, &ObjectClips[0]);
	}
	if(!swordStatus)
	{
		ItemSheetTexture.Render(Renderer, this->item_sword.x - camera->x, this->item_sword.y - camera->y, &ObjectClips[1]);
	}
	SDL_SetRenderDrawColor(Renderer, 0xff, 0x00, 0xff, 0x00);
	if(!diverStatus)
	{
		SDL_RenderFillRect(Renderer, &diverSprite);
	}
	SDL_SetRenderDrawColor(Renderer, 0xff, 0x00, 0x00, 0x00);
	SDL_RenderFillRect(Renderer, &fishermanSprite);
}

void Objects::Cleanup()
{
	ItemSheetTexture.Free();
}