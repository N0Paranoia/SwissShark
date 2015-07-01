#include "Objects.h"
#include "Constants.h"
#include "Textures.h"

using namespace std;
Textures ItemSheetTexture;


Objects::Objects()
{
	this->InitObjects();
}

Objects::~Objects()
{
}

void Objects::InitObjects()
{
	frameHose = 2;
	frameCounterHose = 0;
	startFrameHose = 3;
	endFrameHose = 5;
	
	frameDiver = 6;
	frameCounterDiver = 0;
	startFrameDiver = 6;
	endFrameDiver = 9;
	
	frameCounter = 0;
	frameSpeed = 12;
	frameSwitch = 60;
	
	framePlant = 12;
	
	goingUp = false;
	goingDown = true;
	
	killedDiver = false;

	OBJ_SAW = 0;
	OBJ_SWORD = 1;
	OBJ_HOSE = 2;
	OBJ_DIVER = 6;
	OBJ_DOOR = 10;
	OBJ_DOOR_OPEN = 11;
	OBJ_PLANT = 12;
	OBJ_FISHINGROD = 13;
	
	fisherman.x = 16*TILE_SIZE + TILE_SIZE/2;
	fisherman.y =-10*TILE_SIZE;
	fisherman.w = TILE_SIZE/8;
	fisherman.h = 12*TILE_SIZE;
	
	door.x = 21*TILE_SIZE + TILE_SIZE/2; 
	door.y = 9*TILE_SIZE;
	door.w = TILE_SIZE/2;
	door.h = 2*TILE_SIZE;
	
	diver.x = 35*TILE_SIZE;
	diver.y = 9*TILE_SIZE;
	diver.w = TILE_SIZE;
	diver.h = 2*TILE_SIZE;
	
	diverHose.x = 35*TILE_SIZE;
	diverHose.y = 0*TILE_SIZE;
	diverHose.w = TILE_SIZE/4;
	diverHose.h = 9*TILE_SIZE;
	
	item_saw.x = 13*TILE_SIZE;
	item_saw.y = 10*TILE_SIZE;
	item_saw.w = TILE_SIZE;
	item_saw.h = TILE_SIZE;
	
	item_sword.x = 23*TILE_SIZE;
	item_sword.y = 2*TILE_SIZE;
	item_sword.w = TILE_SIZE;
	item_sword.h = TILE_SIZE;
	
	plantSprite1.x = 14*TILE_SIZE;
	plantSprite1.y = 9*TILE_SIZE;
	plantSprite1.w = 2*TILE_SIZE;
	plantSprite1.h = 2*TILE_SIZE;
	
	plantSprite2.x = 24*TILE_SIZE;
	plantSprite2.y = 1*TILE_SIZE;
	plantSprite2.w = 2*TILE_SIZE;
	plantSprite2.h = 2*TILE_SIZE;
}

int Objects::LoadMedia(SDL_Renderer* Renderer)
{
	//Load Item sheet
	if((ItemSheetTexture.LoadFromFile(Renderer, "assets/objectSheet.png")) == NULL)
	{
		cout << "Unable to load Item Texture! SDL_Error: " << SDL_GetError() << endl;
		return false;
	}
	else
	{
		ObjectClips[OBJ_SAW].x = 0;
		ObjectClips[OBJ_SAW].y = 0;
		ObjectClips[OBJ_SAW].w = TILE_SIZE;
		ObjectClips[OBJ_SAW].h = TILE_SIZE;
		
		ObjectClips[OBJ_SWORD].x = 0;
		ObjectClips[OBJ_SWORD].y = TILE_SIZE;
		ObjectClips[OBJ_SWORD].w = TILE_SIZE;
		ObjectClips[OBJ_SWORD].h = TILE_SIZE;
		
		ObjectClips[OBJ_HOSE].x = 7*TILE_SIZE;
		ObjectClips[OBJ_HOSE].y = 0;
		ObjectClips[OBJ_HOSE].w = TILE_SIZE;
		ObjectClips[OBJ_HOSE].h = 9*TILE_SIZE;
		
		ObjectClips[3].x = 8*TILE_SIZE;
		ObjectClips[3].y = 0;
		ObjectClips[3].w = TILE_SIZE;
		ObjectClips[3].h = 9*TILE_SIZE;
		
		ObjectClips[4].x = 9*TILE_SIZE;
		ObjectClips[4].y = 0;
		ObjectClips[4].w = TILE_SIZE;
		ObjectClips[4].h = 9*TILE_SIZE;
		
		ObjectClips[5].x = 10*TILE_SIZE;
		ObjectClips[5].y = 0;
		ObjectClips[5].w = TILE_SIZE;
		ObjectClips[5].h = 9*TILE_SIZE;
		
		ObjectClips[OBJ_DIVER].x = 3*TILE_SIZE;
		ObjectClips[OBJ_DIVER].y = 0;
		ObjectClips[OBJ_DIVER].w = TILE_SIZE;
		ObjectClips[OBJ_DIVER].h = 2*TILE_SIZE;
		
		ObjectClips[7].x = 4*TILE_SIZE;
		ObjectClips[7].y = 0;
		ObjectClips[7].w = TILE_SIZE;
		ObjectClips[7].h = 2*TILE_SIZE;
		
		ObjectClips[8].x = 5*TILE_SIZE;
		ObjectClips[8].y = 0;
		ObjectClips[8].w = TILE_SIZE;
		ObjectClips[8].h = 2*TILE_SIZE;
		
		ObjectClips[9].x = 6*TILE_SIZE;
		ObjectClips[9].y = 0;
		ObjectClips[9].w = TILE_SIZE;
		ObjectClips[9].h = 2*TILE_SIZE;
				
		ObjectClips[OBJ_DOOR].x = 0*TILE_SIZE;
		ObjectClips[OBJ_DOOR].y = 2*TILE_SIZE;
		ObjectClips[OBJ_DOOR].w = TILE_SIZE;
		ObjectClips[OBJ_DOOR].h = 2*TILE_SIZE;
		
		ObjectClips[11].x = 1*TILE_SIZE;
		ObjectClips[11].y = 2*TILE_SIZE;
		ObjectClips[11].w = TILE_SIZE;
		ObjectClips[11].h = 2*TILE_SIZE;
						
		ObjectClips[OBJ_PLANT].x = 3*TILE_SIZE;
		ObjectClips[OBJ_PLANT].y = 4*TILE_SIZE;
		ObjectClips[OBJ_PLANT].w = 2*TILE_SIZE;
		ObjectClips[OBJ_PLANT].h = 2*TILE_SIZE;
		
		ObjectClips[OBJ_FISHINGROD].x = 0*TILE_SIZE; 
		ObjectClips[OBJ_FISHINGROD].y = 4*TILE_SIZE;
		ObjectClips[OBJ_FISHINGROD].w = 1*TILE_SIZE;
		ObjectClips[OBJ_FISHINGROD].h = 12*TILE_SIZE;
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

SDL_Rect Objects::DiverHose()
{
	return diverHose;
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
		
		diverHose.x = 0; 
		diverHose.y = 0;
		diverHose.w = 0;
		diverHose.h = 0;
	}
}

void Objects::Move()
{
	if(goingDown)
	{
		fisherman.y ++;
		if((fisherman.y + fisherman.h) == 11*TILE_SIZE)
		{
			goingDown = false;
			goingUp = true;
		}
	}
	else if(goingUp)
	{
		fisherman.y --;
		if((fisherman.y + fisherman.h) == 2*TILE_SIZE)
		{
			goingUp = false;
			goingDown = true;
		}
	}
}

void Objects::Render(SDL_Renderer* Renderer, SDL_Rect* camera, bool doorStatus, bool diverStatus, bool sawStatus, bool swordStatus)
{
	if(!doorStatus)
	{
		ItemSheetTexture.Render(Renderer, this->door.x - camera->x, this->door.y - camera->y, &ObjectClips[OBJ_DOOR]);
	}
	else
	{
		ItemSheetTexture.Render(Renderer, this->door.x - camera->x, this->door.y - camera->y, &ObjectClips[OBJ_DOOR_OPEN]);
	}
	if(!sawStatus)
	{
		ItemSheetTexture.Render(Renderer, this->item_saw.x - camera->x, this->item_saw.y - camera->y, &ObjectClips[OBJ_SAW]);
	}
	if(!swordStatus)
	{
		ItemSheetTexture.Render(Renderer, this->item_sword.x - camera->x, this->item_sword.y - camera->y, &ObjectClips[OBJ_SWORD]);
	}
	SDL_SetRenderDrawColor(Renderer, 0xff, 0x00, 0xff, 0x00);
	if(diverStatus)
	{
		frameCounter += frameSpeed;
		if(frameCounter > frameSwitch)
		{
			if(!killedDiver)
			{
				frameHose ++;
				frameDiver ++;
				frameCounterHose = 0;
				frameCounterDiver = 0;
				if(frameHose == endFrameHose)
				{
					killedDiver = true;
				}
			}
		}
	}
	ItemSheetTexture.Render(Renderer, this->diverHose.x - camera->x, this->diverHose.y - camera->y, &ObjectClips[OBJ_HOSE]);
	ItemSheetTexture.Render(Renderer, this->diver.x - camera->x, this->diver.y - camera->y, &ObjectClips[OBJ_DIVER]);
	ItemSheetTexture.Render(Renderer, this->plantSprite1.x - camera->x, this->plantSprite1.y - camera->y, &ObjectClips[OBJ_PLANT]);
	ItemSheetTexture.Render(Renderer, this->plantSprite2.x - camera->x, this->plantSprite2.y - camera->y, &ObjectClips[OBJ_PLANT]);
	ItemSheetTexture.Render(Renderer, this->fisherman.x - camera->x, this->fisherman.y - camera->y, &ObjectClips[OBJ_FISHINGROD]);
}

void Objects::Cleanup()
{
	ItemSheetTexture.Free();
}
