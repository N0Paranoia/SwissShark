#ifndef CAMERA_H
#define CAMERA_H

#include <SDL.h>
#include "Constants.h"

using namespace std;

class Camera
{
	public:
		SDL_Rect cameraRect;
		SDL_Rect centerRect;
	public:
		Camera();
		virtual ~Camera();
		void InitCam();
		void Center(SDL_Rect* playerRect);
		void Follow();
		void Update(SDL_Rect* playerRect);
		void Render(SDL_Renderer* Renderer);
	protected:
	private:
};

#endif // CAMERA_H
