#include "Game.h"
#include "Timer.h"
#include "Player.h"
#include "Textures.h"
#include "Camera.h"
#include "Objects.h"
#include "World.h"
#include "Constants.h"


Timer FPStimer;
Timer CAPtimer;
Player player;
World world;
Camera camera;
Objects objects;
Tile* tileSet[TOTAL_TILES];

Textures wallpaperTexture;
Textures foregroundTexture;
Textures TextTexture;
Textures TextGameOver1;
Textures TextGameOver2;
Textures TextWin;

Game::Game()
{
	Running = true;
	Window = nullptr;
	Renderer = nullptr;
	Texture = nullptr;

	textColor = {255,0,0};
	countedFrames  = 0;

	_gamestate = running;
}

bool Game::Init()
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
		return false;
	}

	if((Window = SDL_CreateWindow("Swiss Shark",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN)) == NULL)
	{
		cout << "Unable to create SDL_Window! SDL_Error: " << SDL_GetError() << endl;
		return false;
	}

	if((Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED /*| SDL_RENDERER_PRESENTVSYNC*/)) == NULL)
	{
		cout << "Unable to create Renderer! SDL_Error: " << SDL_GetError() << endl;
		return false;
	}
	// initialize image loading for PNG
	if(!(IMG_Init(IMG_INIT_PNG)& IMG_INIT_PNG))
	{
		cout << "Unable to initialize SDL_Image! SDL_Error: " << SDL_GetError() << endl;
		return false;
	}
	if(TTF_Init() == -1)
	{
		cout << "Unable to initialize SDL_TTF! SDL_Error: " << TTF_GetError() << endl;
	}
	return true;
}

bool Game::LoadMedia()
{
	//Load Player texture
	if((player.LoadMedia(Renderer)) == NULL)
	{
		return false;
	}
	//Load Item Sheet
	if((objects.LoadMedia(Renderer)) == NULL)
	{
		return false;
	}
	//Load Tile Sheet
	if((world.LoadMedia(Renderer, tileSet)) == NULL)
	{
		return false;
	}
	//Load PNG background texture
	if((wallpaperTexture.LoadFromFile(Renderer, "../assets/background.png")) == NULL)
	{
		cout << "Unable to Load texture image! (background) SDL_Error: " << SDL_GetError() << endl;
		return false;
	}
	if((foregroundTexture.LoadFromFile(Renderer, "../assets/foreground.png")) == NULL)
	{
		cout << "Unable to Load texture image! (foreground) SDL_Error: " << SDL_GetError() << endl;
		return false;
	}
	Font = TTF_OpenFont("../assets/FreePixel.ttf", 14);
	if(Font == NULL)
	{
		cout << "Unable to Load font! SDL_Error: " << TTF_GetError() << endl;
		return false;
	}
	return true;
}

void Game::Event(SDL_Event* event)
{
	if(event->type == SDL_QUIT)
	{
		Running = false;
	}
	else if(event->type == SDL_KEYDOWN)
	{
		switch(event->key.keysym.sym)
		{
		case SDLK_q:
			Running = false;
			cout << "Quit by keyboard(q)" << endl;
			break;
		}
	}
}

void Game::Fps()
{
	avgFPS = countedFrames / (FPStimer.getTicks() / 1000.f);

	if(avgFPS > 2000000)
	{
		avgFPS = 0;
	}

	timeText.str("");
	timeText << avgFPS;
	if(!TextTexture.LoadFromRenderedText(Renderer, Font, timeText.str().c_str(), textColor))
	{
		cout << "Failed to render text texture!" << endl;
	}
}

void Game::FpsCap()
{
	frameTicks = CAPtimer.getTicks();
	if(frameTicks < TICK_PER_FRAME)
	{
		SDL_Delay( TICK_PER_FRAME - frameTicks);
	}
}
void Game::GameOver()
{
	gameOverText1.str("Game Over");
	gameOverText2.str("press q to Quit");
	if(!TextGameOver1.LoadFromRenderedText(Renderer, Font, gameOverText1.str().c_str(), textColor))
	{
		cout << "Failed to render text texture!" << endl;
	}
	if(!TextGameOver2.LoadFromRenderedText(Renderer, Font, gameOverText2.str().c_str(), textColor))
	{
		cout << "Failed to render text texture!" << endl;
	}
}

void Game::Win()
{
	winText.str("You Win!!!");
	if(!TextWin.LoadFromRenderedText(Renderer, Font, winText.str().c_str(), textColor))
	{
		cout << "Failed to render text texture!" << endl;
	}
}

void Game::Input()
{
	player.Input(tileSet);
}

void Game::Loop()
{
	switch(_gamestate)
	{
		case running:
			camera.Center(&player.playerRect);
			if(player.Health(0) < 1)
			{
				_gamestate = gameover;
			}
			if(player.CheckWinStatus() == 1)
			{
				_gamestate = win;
			}
			break;
		
		case pause:
			break;
		
		case gameover:
			break;	
	}
}

void Game::Render()
{
	switch(_gamestate)
	{
		case running:
			//Set Default colors
			SDL_SetRenderDrawColor(Renderer, 0xFF, 0xFF, 0xFF, 0xFF);
			//Clear screen
			SDL_RenderClear(Renderer);
			//Render Texture to screen
			wallpaperTexture.Render(Renderer, 0 - camera.cameraRect.x, 0 - camera.cameraRect.y);
			//Render Tiles
			world.Render(Renderer, &camera.cameraRect, tileSet);
			//Render Player data
			player.Render(Renderer, &camera.cameraRect);
			//Render Objects
			objects.Render(Renderer, &camera.cameraRect, player.destroyedDoor, player.kiledDiver, player.pickedUpSaw, player.pickedUpSword);
			//Render Camara outline
			camera.Render(Renderer);
			//Render FPS text
			TextTexture.Render(Renderer, WINDOW_WIDTH - TILE_SIZE, 0);
			
			foregroundTexture.Render(Renderer, 0 - camera.cameraRect.x, 0 - camera.cameraRect.y);

			//Update screen
			SDL_RenderPresent(Renderer);

			// frame counter for FPS
			++countedFrames;

			this->FpsCap();
			break;
			
		case pause:

			break;
		
		case gameover:
			this->GameOver();
			//Render FPS text
			TextGameOver1.Render(Renderer, WINDOW_WIDTH/2, WINDOW_HEIGHT/2);
			TextGameOver2.Render(Renderer, WINDOW_WIDTH/2 - TILE_SIZE/3, WINDOW_HEIGHT/2 + TILE_SIZE);
			//Update screen
			SDL_RenderPresent(Renderer);

			break;
		case win:
			this->Win();
			//Render FPS text
			TextWin.Render(Renderer, WINDOW_WIDTH/2, WINDOW_HEIGHT/2);
			//Update screen
			SDL_RenderPresent(Renderer);

			
			break;
	}
}

void Game::Cleanup()
{
	if(Renderer)
	{
		SDL_DestroyRenderer(Renderer);
		Renderer = nullptr;
	}
	if(Texture)
	{
		SDL_DestroyTexture(Texture);
		Texture = nullptr;
	}
	if(Window)
	{
		SDL_DestroyWindow(Window);
		Window = nullptr;
	}
	player.Cleanup();
	objects.Cleanup();
	world.Cleanup();
	TextTexture.Free();
	TTF_CloseFont(Font);
	Font = nullptr;
	SDL_Quit();
}

int Game::Execute()
{
	if(this->Init() == false)
	{
		return -1;
	}
	if(this->LoadMedia() == false)
	{
		return -1;
	}
	SDL_Event event;
	//start FPS timer
	FPStimer.Start();

	while(Running)
	{

		CAPtimer.Start();
		while(SDL_PollEvent(&event))
		{
		   this->Event(&event);
		}
		this->Fps();
		this->Input();
		this->Loop();
		this->Render();
	}
	this->Cleanup();
	return 0;
}


int main(int argc, char* argv[])
{
	Game EpicQuest;
	return EpicQuest.Execute();
}
