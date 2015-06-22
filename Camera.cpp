#include "Camera.h"
#include "Constants.h"
#include <iostream>

Camera::Camera()
{
	centerRect.x = 0;
	centerRect.y = 0;
	centerRect.w = 2*TILE_SIZE;
	centerRect.h = 1*TILE_SIZE;

	cameraRect.x = 0;
	cameraRect.y = 0;
	cameraRect.w = WINDOW_WIDTH;
	cameraRect.h = WINDOW_HEIGHT;
}

Camera::~Camera()
{
    //dtor
}

void Camera::Center(SDL_Rect* playerRect)
{
	centerRect.x = playerRect->x;
	centerRect.y = playerRect->y;
	centerRect.w = playerRect->w;
	centerRect.h = playerRect->h;
	this->Follow();
}

void Camera::Follow()
{
	if((centerRect.x + centerRect.w) - TILE_SIZE > WINDOW_WIDTH)	
	{
		if(cameraRect.x < WINDOW_WIDTH)
		{
			cameraRect.x +=20;
		}
	}
	else if((centerRect.x + TILE_SIZE) < WINDOW_WIDTH)
	{
		if(cameraRect.x > 0)
		{
			cameraRect.x -=20;
		}
	}
	if(cameraRect.x < 0)
	{
		cameraRect.x = 0;
	}
	if((cameraRect.x + cameraRect.w) > LEVEL_WIDTH*TILE_SIZE)
	{
		cameraRect.x = LEVEL_WIDTH*TILE_SIZE - cameraRect.w;
	}
	if(cameraRect.y < 0)
	{
		cameraRect.y = 0;
	}
	if((cameraRect.y + cameraRect.h) > LEVEL_HEIGHT*TILE_SIZE)
	{
		cameraRect.y = LEVEL_HEIGHT*TILE_SIZE - cameraRect.h;
	}
}

void Camera::Render(SDL_Renderer* Renderer)
{

}
