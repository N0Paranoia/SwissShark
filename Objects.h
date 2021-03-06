#ifndef OBJECTS_H
#define OBJECTS_H
#include <SDL.h>
#include <iostream>


class Objects
{
public:
	Objects();
	~Objects();
	void InitObjects();
	int LoadMedia(SDL_Renderer* Renderer);
	void Update(int action);
	void Move();
	void RenderForeground(SDL_Renderer* Renderer, SDL_Rect* camera, bool doorStatus, bool diverStatus, bool sawStatus, bool swordStatus);
	void RenderBackground(SDL_Renderer* Renderer, SDL_Rect* camera, bool doorStatus, bool diverStatus, bool sawStatus, bool swordStatus);
	SDL_Rect Door();
	SDL_Rect Diver();
	SDL_Rect DiverHose();
	SDL_Rect Fisherman();
	SDL_Rect Item_Saw();
	SDL_Rect Item_Sword();
	
	void Cleanup();
	
	SDL_Rect ObjectClips[14];
	
	SDL_Rect chest;
	SDL_Rect door;
	SDL_Rect doorSprite;
	SDL_Rect fisherman;
	SDL_Rect fishermanSprite;
	SDL_Rect diver;
	SDL_Rect diverSprite;
	SDL_Rect diverHose;
	SDL_Rect diverHoseSprite;
	SDL_Rect plantSprite1;
	SDL_Rect plantSprite2;
	SDL_Rect item_saw;
	SDL_Rect item_sawSprite;
	SDL_Rect item_sword;
	SDL_Rect item_swordSprite;
	SDL_Rect boat;
	
	int framePlant;
	int frameBoat;
	int frameHose;
	int frameCounterHose;
	int startFrameHose;
	int endFrameHose;
	
	int frameDiver;
	int frameCounterDiver;
	int startFrameDiver;
	int endFrameDiver;
	
	int frameCounter;
	int frameSpeed;
	int frameSwitch;
	
	bool killedDiver;
	bool goingUp;
	bool goingDown;

	int OBJ_SAW;
	int OBJ_SWORD;
	int OBJ_DIVER;
	int OBJ_HOSE;
	int OBJ_PLANT;
	int OBJ_DOOR;
	int OBJ_DOOR_OPEN;
	int OBJ_FISHINGROD;
};

#endif // OBJECTS_H
