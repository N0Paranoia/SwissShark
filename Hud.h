#ifndef HUD_H
#define HUD_H

#include <SDL.h>

using namespace std;

class Hud
{
	private:
		SDL_Rect healtRect;
		SDL_Rect energyRect;
	public:
		Hud();
		~Hud();
		void Render(SDL_Renderer*, int health, int energy);
};

#endif // HUD_:w

