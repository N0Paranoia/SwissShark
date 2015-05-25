#include "Camera.h"
#include "Constants.h"
#include <iostream>

Camera::Camera()
{
    centerRect.x = 0;
    centerRect.y = 0;
    centerRect.w = 2*TILE_SIZE;
    centerRect.h = 4*TILE_SIZE;

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
    if(centerRect.x > playerRect->x)
    {
        centerRect.x = playerRect->x;
    }
    if((centerRect.x + centerRect.w) < (playerRect->x + playerRect->w))
    {
        centerRect.x = (playerRect->x + playerRect->w) - centerRect.w;
    }
    if(centerRect.y > playerRect->y)
    {
        centerRect.y = playerRect->y;
    }
    if((centerRect.y + centerRect.h) < (playerRect->y + playerRect->h))
    {
        centerRect.y = (playerRect->h + playerRect->y) - centerRect.h;
    }
    this->Follow();
}

void Camera::Follow()
{
    cameraRect.x = (centerRect.x + centerRect.w/2) - WINDOW_WIDTH/2;
    cameraRect.y = (centerRect.y + centerRect.h/2) - WINDOW_HEIGHT/2;

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
    SDL_SetRenderDrawColor(Renderer, 0x00, 0x00, 0x00, 0xff);
    test = {centerRect.x - cameraRect.x, centerRect.y - cameraRect.y, centerRect.w, centerRect.h};
    SDL_RenderDrawRect(Renderer, &test);
}
