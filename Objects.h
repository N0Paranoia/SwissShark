#ifndef OBJECTS_H
#define OBJECTS_H
#include <SDL.h>
#include <iostream>


class Objects
{
public:
	Objects();
	~Objects();
	int LoadMedia(SDL_Renderer* Renderer);
	SDL_Rect Door();
	SDL_Rect Diver();
	SDL_Rect Fisherman();
	SDL_Rect Item_Saw();
	SDL_Rect Item_Sword();
	void Update(int action);
	void Render(SDL_Renderer* Renderer, SDL_Rect* camera, bool doorStatus, bool diverStatus, bool sawStatus, bool swordStatus);
	
	void Cleanup();
	
	SDL_Rect ObjectClips[2];
	
	SDL_Rect chest;
	SDL_Rect door;
	SDL_Rect doorSprite;
	SDL_Rect fisherman;
	SDL_Rect fishermanSprite;
	SDL_Rect diver;
	SDL_Rect diverSprite;
	SDL_Rect item_saw;
	SDL_Rect item_sawSprite;
	SDL_Rect item_sword;
	SDL_Rect item_swordSprite;
};

#endif // OBJECTS_H
