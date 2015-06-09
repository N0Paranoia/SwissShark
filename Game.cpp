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
Textures TextTexture;

Game::Game()
{
    Running = true;
    Window = nullptr;
    Renderer = nullptr;
    Texture = nullptr;

    textColor = {255,0,0};
    countedFrames  = 0;
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
    //Load Tile Sheet
    if((world.LoadMedia(Renderer, tileSet)) == NULL)
    {
        return false;
    }
    //Load PNG background texture
    if((wallpaperTexture.LoadFromFile(Renderer, "../assets/background.png")) == NULL)
	{
		cout << "Unable to Load texture image! SDL_Error: " << SDL_GetError() << endl;
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

void Game::Input()
{
     player.Input(tileSet);
}

void Game::Loop()
{
	camera.Center(&player.playerRect);
}

void Game::Render()
{
	//Set Default colors
	SDL_SetRenderDrawColor(Renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	//Clear screen
	SDL_RenderClear(Renderer);
	//Render Texture to screen
	wallpaperTexture.Render(Renderer, 0, 0);
	//Render Tiles
	world.Render(Renderer, &camera.cameraRect, tileSet);
	//Render Player data
	player.Render(Renderer, &camera.cameraRect);
	//Render Objects
	objects.Render(Renderer, &camera.cameraRect);
	//Render Camara outline
	camera.Render(Renderer);
	//Render FPS text
	TextTexture.Render(Renderer, WINDOW_WIDTH - TILE_SIZE, 0);

	//Update screen
	SDL_RenderPresent(Renderer);

	// frame counter for FPS
	++countedFrames;

	this->FpsCap();
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
