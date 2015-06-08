#ifndef OBJECTS_H
#define OBJECTS_H
#include <SDL.h>
#include <iostream>


class Objects
{
public:
	Objects();
	~Objects();
	void Chest(int playerX, int playerY);
	bool Door(int playerX, int playerY);
	void Render(SDL_Renderer* Renderer, SDL_Rect* camera);
	
	SDL_Rect chest;
	SDL_Rect door;
	
};

#endif // OBJECTS_H
