#include "Hud.h"
#include "Constants.h"

Hud::Hud()
{

}

Hud::~Hud()
{
}

void Hud::Render(SDL_Renderer* Renderer, int health, int energy)
{
	healtRect = {10, 10, health, 10};
	energyRect = {10, 25, energy, 10};
	SDL_SetRenderDrawColor(Renderer, 0xff, 0x00, 0x00, 0xff);
	SDL_RenderFillRect(Renderer, &healtRect);
	SDL_SetRenderDrawColor(Renderer, 0x00, 0xff, 0x00, 0xFF);
	SDL_RenderFillRect(Renderer, &energyRect);
}
