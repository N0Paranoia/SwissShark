#ifndef OBJECTS_H
#define OBJECTS_H
#include <SDL.h>
#include <iostream>


class Objects
{
public:
	Objects();
	~Objects();
	SDL_Rect Chest();
	SDL_Rect Door();
	void Render(SDL_Renderer* Renderer, SDL_Rect* camera);
	
	SDL_Rect chest;
	SDL_Rect door;
	SDL_Rect test;
	bool brokenDoor;
};

#endif // OBJECTS_H
