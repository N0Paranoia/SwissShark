#include "Textures.h"

Textures::Textures()
{
    texture = nullptr;
    mWidth = 0;
    mHeight = 0;
}

Textures::~Textures()
{
    this->Free();
}

bool Textures::LoadFromFile(SDL_Renderer* Renderer, std::string path)
{
    //Free textures
    this->Free();

	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if(loadedSurface == NULL)
	{
	    cout << "Unable to load image! SDL_Error: " << path.c_str() << IMG_GetError() << endl;
	}
	else
	{
		//Color key image
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xF));

		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(Renderer, loadedSurface);
		if(newTexture == NULL)
		{
			cout << "Unable to create texture! SDL_Error: " << path.c_str() << SDL_GetError() << endl;
		}
		else
		{
			//Get image dimensions
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	//Return success
	texture = newTexture;
	return texture != NULL;
}

bool Textures::LoadFromRenderedText(SDL_Renderer* Renderer, TTF_Font* Font, std::string textureText, SDL_Color textColor)
{
	this->Free();

	SDL_Surface* textSurface = TTF_RenderText_Solid(Font, textureText.c_str(), textColor);
	if(textSurface == NULL)
	{
		cout << "Unable to render text surface! SDL_ttf Error: " << TTF_GetError() << endl;
	}
	else
    {
        texture = SDL_CreateTextureFromSurface(Renderer, textSurface);
        if(texture == NULL)
        {
            cout << "Unable to create texture from rendered text! SDL Error: " << SDL_GetError() << endl;
        }
        else
        {
            mWidth = textSurface->w;
            mHeight = textSurface->h;
        }
        SDL_FreeSurface(textSurface);
    }
    return texture != NULL;
}

void Textures::Render(SDL_Renderer* Renderer,int x ,int y, SDL_Rect* clip)
{
    //Set rendering spade en render to screen
    SDL_Rect renderQuad = {x, y, mWidth, mHeight};
    //Set dimensions
    if(clip !=NULL)
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }
    //Render to screen
    SDL_RenderCopy(Renderer, texture, clip, &renderQuad);
}

int Textures::getWidth()
{
    return mWidth;
}

int Textures::getHeight()
{
    return mHeight;
}

void Textures::Free()
{
    //Free texture is exist
    if(texture !=NULL)
    {
        SDL_DestroyTexture(texture);
        texture = nullptr;
        mWidth = 0;
        mHeight = 0;
    }
}
