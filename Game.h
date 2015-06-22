#ifndef EQ_H
#define EQ_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

std::stringstream timeText;
std::stringstream gameOverText1;
std::stringstream gameOverText2;
std::stringstream winText;

class Game
{
private:
		
		enum Gamestates
		{
			intro,
			running,
			pause,
			gameover,
			win
		};
		
		int _gamestate;

		bool Running;
		SDL_Window* Window ;
		SDL_Renderer* Renderer;
		SDL_Texture* Texture;
		TTF_Font* Font;
		SDL_Color textColor;
		int countedFrames;

		float avgFPS;
		int frameTicks;

	public:
		Game();
		int Execute();

	public:
		void Event(SDL_Event* Event);
		void Fps();
		void FpsCap();
		bool Init();
		bool LoadMedia();
		//Loads individual image as texture
		SDL_Texture* loadTexture(std::string path);
		void Input();
		void Loop();
		void Render();
		void Cleanup();
};

#endif // EQ_H
